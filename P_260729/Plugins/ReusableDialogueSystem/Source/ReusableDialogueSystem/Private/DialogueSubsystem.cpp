#include "DialogueSubsystem.h"
#include "DialogueAssets.h"
#include "DialogueEventTags.h"
#include "DialogueSettings.h"
#include "DialogueTokenizer.h"
#include "DialogueWidgetBase.h"
#include "ReusableDialogueSystem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/AudioComponent.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Payloads/DialogueEventPayload.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "TimerManager.h"

namespace
{
    void PublishDialogueEvent(UDialogueSubsystem* DialogueSubsystem, FGameplayTag EventTag, UDialogueSequence* Sequence, EDialogueEndReason EndReason = EDialogueEndReason::Completed)
    {
        UGameInstance* GameInstance = DialogueSubsystem && DialogueSubsystem->GetWorld() ? DialogueSubsystem->GetWorld()->GetGameInstance() : nullptr;
        UJMGameplayEventSubsystem* EventSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
        if (!EventSubsystem || !Sequence) return;
        UDialogueEventPayload* Payload = NewObject<UDialogueEventPayload>(DialogueSubsystem);
        Payload->Sequence = Sequence;
        Payload->DialogueId = Sequence->SequenceId;
        Payload->ConversationId = Sequence->SequenceId;
        Payload->ObjectiveTargetIdentifier = Sequence->SequenceId;
        Payload->ObjectiveProgressAmount = 1;
        if (Sequence->SequenceTag.IsValid())
        {
            Payload->ObjectiveContextTags.AddTag(Sequence->SequenceTag);
        }
        Payload->EndReason = EndReason;
        FJMGameplayEventMessage Message;
        Message.EventTag = EventTag;
        Message.Source = DialogueSubsystem;
        Message.Target = Sequence;
        Message.Payload = Payload;
        EventSubsystem->PublishEvent(Message);
    }
}

void UDialogueSubsystem::Deinitialize()
{
    CleanupPlayback();
    CurrentSequence = nullptr;
    SetState(EDialogueState::Inactive);
    Super::Deinitialize();
}

FDialogueLine UDialogueSubsystem::GetCurrentLine() const
{
    return CurrentSequence && CurrentSequence->Lines.IsValidIndex(CurrentLineIndex) ? CurrentSequence->Lines[CurrentLineIndex] : FDialogueLine{};
}

bool UDialogueSubsystem::StartDialogue(UDialogueSequence* Sequence, EDialogueInteractionMode InteractionMode, APlayerController* PlayerController, EExistingDialoguePolicy ExistingPolicy)
{
    if (!Sequence || Sequence->Lines.IsEmpty()) { UE_LOG(LogReusableDialogue, Warning, TEXT("Dialogue start failed: null or empty sequence.")); return false; }
    if (IsDialogueActive())
    {
        if (ExistingPolicy == EExistingDialoguePolicy::Reject) { UE_LOG(LogReusableDialogue, Warning, TEXT("Dialogue start rejected: another dialogue is active.")); return false; }
        FinishDialogue(EDialogueEndReason::Replaced, true);
    }
    UWorld* World = GetWorld();
    if (!World) { UE_LOG(LogReusableDialogue, Warning, TEXT("Dialogue start failed: no world.")); return false; }
    const UDialogueSettings* Settings = GetDefault<UDialogueSettings>();
    TSubclassOf<UDialogueWidgetBase> WidgetClass = Settings->DefaultDialogueWidgetClass.LoadSynchronous();
    if (!WidgetClass) { UE_LOG(LogReusableDialogue, Error, TEXT("Dialogue start failed: Default Dialogue Widget Class is not configured.")); return false; }

    OwningPlayerController = PlayerController ? PlayerController : World->GetFirstPlayerController();
    DialogueWidget = CreateWidget<UDialogueWidgetBase>(OwningPlayerController, WidgetClass);
    if (!DialogueWidget) { UE_LOG(LogReusableDialogue, Error, TEXT("Dialogue start failed: widget creation failed.")); return false; }

    CurrentSequence = Sequence;
    CurrentLineIndex = 0;
    ActiveInteractionMode = InteractionMode;
    SetState(EDialogueState::Opening);
    DialogueWidget->AddToViewport();
    DialogueWidget->ResetDialogueWidget();
    DialogueWidget->OnDialogueOpened();
    ApplyInteractionMode();
    OnDialogueStarted.Broadcast(CurrentSequence);
    PublishDialogueEvent(this, JMDialogueEventTags::Started, CurrentSequence);
    UE_LOG(LogReusableDialogue, Log, TEXT("Started dialogue %s."), *Sequence->GetName());
    BeginCurrentLine();
    return true;
}

void UDialogueSubsystem::SetState(EDialogueState NewState)
{
    if (State == NewState) return;
    const EDialogueState Previous = State;
    State = NewState;
    OnDialogueStateChanged.Broadcast(Previous, State);
}

void UDialogueSubsystem::BeginCurrentLine()
{
    if (!CurrentSequence || !CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) { FinishDialogue(EDialogueEndReason::InvalidData, true); return; }
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    bCurrentLineRecorded = false;
    VisibleText.Reset(); RevealTokens.Reset(); RevealTokenIndex = 0; RevealCharacterCount = 0; LastSoundIndex = INDEX_NONE;
    const FText SpeakerName = !Line.SpeakerNameOverride.IsEmpty() ? Line.SpeakerNameOverride : (Line.Speaker ? Line.Speaker->DisplayName : FText::GetEmpty());
    DialogueWidget->SetSpeakerName(SpeakerName);
    DialogueWidget->SetSpeakerNameColor(Line.Speaker ? Line.Speaker->NameColor : FLinearColor::White);
    DialogueWidget->SetPortrait(Line.Speaker ? Line.Speaker->Portrait : nullptr);
    DialogueWidget->SetDialogueText(FText::GetEmpty());
    DialogueWidget->SetAdvanceIndicatorVisible(false);
    DialogueWidget->OnSpeakerChanged();
    DialogueWidget->OnLineStarted(Line.LineId, CurrentLineIndex);
    OnLineStarted.Broadcast(CurrentSequence, Line.LineId, CurrentLineIndex);
    USoundBase* VoiceSound = Line.VoiceSound ? Line.VoiceSound.Get() : (Line.Speaker ? Line.Speaker->DefaultVoiceSound.Get() : nullptr);
    if (VoiceSound) VoiceAudioComponent = UGameplayStatics::SpawnSound2D(this, VoiceSound);
    SetState(EDialogueState::Revealing);
    if (Line.StartDelay > 0.f)
    {
        if (UWorld* World = GetWorld()) World->GetTimerManager().SetTimer(RevealTimerHandle, this, &UDialogueSubsystem::BeginReveal, Line.StartDelay, false);
    }
    else BeginReveal();
}

void UDialogueSubsystem::BeginReveal()
{
    if (!CurrentSequence || !CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) return;
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    const UDialogueSettings* Settings = GetDefault<UDialogueSettings>();
    ActiveRevealMode = Line.RevealMode;
    if (Settings->bForceCharacterReveal && ActiveRevealMode != EDialogueRevealMode::Instant)
    {
        ActiveRevealMode = EDialogueRevealMode::Character;
    }
    if (ActiveRevealMode == EDialogueRevealMode::Instant) { CompleteCurrentLine(); return; }
    const FString Source = Line.DialogueText.ToString();
    RevealTokens = ActiveRevealMode == EDialogueRevealMode::Word ? FDialogueTokenizer::TokenizeWords(Source) : FDialogueTokenizer::TokenizeCharacters(Source);
    RevealNextToken();
}

void UDialogueSubsystem::RevealNextToken()
{
    if (State != EDialogueState::Revealing || !CurrentSequence || !CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) return;
    if (!DialogueWidget || !DialogueWidget->IsInViewport()) { FinishDialogue(EDialogueEndReason::WidgetCreationFailed, true); return; }
    if (!RevealTokens.IsValidIndex(RevealTokenIndex)) { CompleteCurrentLine(); return; }
    const FDialogueRevealToken& Token = RevealTokens[RevealTokenIndex++];
    VisibleText += Token.Text;
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    const UDialogueSettings* Settings = GetDefault<UDialogueSettings>();
    const bool bSmoothToken = ActiveRevealMode == EDialogueRevealMode::Character
        && Settings->bSmoothCharacterReveal
        && Token.Type != EDialogueTokenType::Whitespace;
    if (bSmoothToken)
    {
        DialogueWidget->SetDialogueTextSmoothed(FText::FromString(VisibleText), Settings->CharacterRevealBlendDuration, Settings->CharacterRevealStartOpacity);
    }
    else
    {
        DialogueWidget->SetDialogueText(FText::FromString(VisibleText));
    }
    PlayTextSound(Token);
    const float BaseDelay = ActiveRevealMode == EDialogueRevealMode::Word ? (Line.WordIntervalOverride >= 0.f ? Line.WordIntervalOverride : Settings->DefaultWordInterval) : (Line.CharacterIntervalOverride >= 0.f ? Line.CharacterIntervalOverride : Settings->DefaultCharacterInterval);
    const float Extra = FDialogueTokenizer::CalculatePunctuationDelay(Token.Text, Settings->CommaDelay, Settings->SentenceEndDelay, Settings->EllipsisDelay, Settings->NewLineDelay);
    ScheduleNextReveal(BaseDelay + Extra);
}

void UDialogueSubsystem::ScheduleNextReveal(float Delay)
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().SetTimer(RevealTimerHandle, this, &UDialogueSubsystem::RevealNextToken, FMath::Max(Delay, .001f), false);
}

void UDialogueSubsystem::CompleteCurrentLine()
{
    if (State != EDialogueState::Revealing || !CurrentSequence || !CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) return;
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(RevealTimerHandle);
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    if (DialogueWidget) { DialogueWidget->SetDialogueText(Line.DialogueText); DialogueWidget->SetAdvanceIndicatorVisible(Line.bWaitForPlayerInput && !Line.bAutoAdvance); DialogueWidget->OnLineCompleted(Line.LineId, CurrentLineIndex); }
    RecordCurrentLine();
    SetState(EDialogueState::WaitingForAdvance);
    OnLineRevealCompleted.Broadcast(CurrentSequence, Line.LineId, CurrentLineIndex);
    if (Line.bAutoAdvance || !Line.bWaitForPlayerInput)
    {
        const float Delay = Line.bAutoAdvance ? Line.AutoAdvanceDelay : Line.EndDelay;
        if (UWorld* World = GetWorld()) World->GetTimerManager().SetTimer(RevealTimerHandle, this, &UDialogueSubsystem::MoveToNextLine, FMath::Max(Delay, .001f), false);
    }
}

void UDialogueSubsystem::AdvanceDialogue()
{
    UWorld* World = GetWorld();
    if (!World || State == EDialogueState::Paused) return;
    const double Now = World->GetRealTimeSeconds();
    if (LastAdvanceTime >= 0.0 && Now - LastAdvanceTime < GetDefault<UDialogueSettings>()->InputDebounceTime) return;
    LastAdvanceTime = Now;
    if (State == EDialogueState::Revealing)
    {
        if (CurrentSequence && CurrentSequence->Lines.IsValidIndex(CurrentLineIndex) && CurrentSequence->Lines[CurrentLineIndex].bCanSkipReveal) CompleteCurrentLine();
        return;
    }
    if (State == EDialogueState::WaitingForAdvance) MoveToNextLine();
}

void UDialogueSubsystem::MoveToNextLine()
{
    if (State != EDialogueState::WaitingForAdvance || !CurrentSequence) return;
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(RevealTimerHandle);
    const FDialogueLine PreviousLine = GetCurrentLine();
    OnLineAdvanced.Broadcast(CurrentSequence, PreviousLine.LineId, CurrentLineIndex);
    SetState(EDialogueState::Transitioning);
    ++CurrentLineIndex;
    if (!CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) { FinishDialogue(EDialogueEndReason::Completed, false); return; }
    if (VoiceAudioComponent) { VoiceAudioComponent->Stop(); VoiceAudioComponent = nullptr; }
    BeginCurrentLine();
}

void UDialogueSubsystem::RecordCurrentLine()
{
    if (bCurrentLineRecorded || !CurrentSequence || !CurrentSequence->Lines.IsValidIndex(CurrentLineIndex)) return;
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    FDialogueHistoryEntry& Entry = DialogueHistory.AddDefaulted_GetRef();
    Entry.SequenceId = CurrentSequence->GetPrimaryAssetId(); Entry.LineId = Line.LineId; Entry.LineIndex = CurrentLineIndex;
    Entry.SpeakerName = !Line.SpeakerNameOverride.IsEmpty() ? Line.SpeakerNameOverride : (Line.Speaker ? Line.Speaker->DisplayName : FText::GetEmpty());
    Entry.DialogueText = Line.DialogueText; Entry.Timestamp = FDateTime::UtcNow(); Entry.VoiceSound = Line.VoiceSound;
    bCurrentLineRecorded = true;
}

UDialogueTextSoundSet* UDialogueSubsystem::ResolveTextSoundSet(const FDialogueLine& Line) const
{
    if (Line.TextSoundSetOverride) return Line.TextSoundSetOverride;
    if (Line.Speaker)
    {
        if (!Line.Speaker->bEnableTextSound) return nullptr;
        if (Line.Speaker->TextSoundSet) return Line.Speaker->TextSoundSet;
    }
    return GetDefault<UDialogueSettings>()->DefaultTextSoundSet.LoadSynchronous();
}

void UDialogueSubsystem::PlayTextSound(const FDialogueRevealToken& Token)
{
    const FDialogueLine& Line = CurrentSequence->Lines[CurrentLineIndex];
    if (Line.bDisableTextSound || Line.TextSoundTriggerMode == EDialogueTextSoundTriggerMode::None || !Token.bCanTriggerSound) return;
    UDialogueTextSoundSet* Set = ResolveTextSoundSet(Line);
    if (!Set || Set->Sounds.IsEmpty() || (Set->bDisableWhileVoiceIsPlaying && VoiceAudioComponent && VoiceAudioComponent->IsPlaying())) return;
    RevealCharacterCount += Token.Text.Len();
    const int32 EveryN = Line.SoundEveryNCharactersOverride > 0 ? Line.SoundEveryNCharactersOverride : Set->SoundEveryNCharacters;
    if (Line.TextSoundTriggerMode == EDialogueTextSoundTriggerMode::EveryNCharacters && RevealCharacterCount % FMath::Max(EveryN, 1) != 0) return;
    UWorld* World = GetWorld(); if (!World) return;
    const double Now = World->GetRealTimeSeconds();
    const float MinInterval = Line.MinimumTextSoundIntervalOverride >= 0.f ? Line.MinimumTextSoundIntervalOverride : Set->MinimumPlaybackInterval;
    if (LastTextSoundTime >= 0.0 && Now - LastTextSoundTime < MinInterval) return;
    TArray<int32> ValidIndices; for (int32 Index = 0; Index < Set->Sounds.Num(); ++Index) if (Set->Sounds[Index]) ValidIndices.Add(Index);
    if (ValidIndices.IsEmpty()) return;
    int32 Pick = ValidIndices[FMath::RandRange(0, ValidIndices.Num() - 1)];
    if (ValidIndices.Num() > 1 && Pick == LastSoundIndex) Pick = ValidIndices[(ValidIndices.IndexOfByKey(Pick) + 1) % ValidIndices.Num()];
    if (Set->bStopPreviousSound && TextAudioComponent) TextAudioComponent->Stop();
    TextAudioComponent = UGameplayStatics::SpawnSound2D(this, Set->Sounds[Pick], FMath::FRandRange(Set->VolumeMin, Set->VolumeMax), FMath::FRandRange(Set->PitchMin, Set->PitchMax), 0.f, Set->SoundConcurrency, false, true);
    LastSoundIndex = Pick; LastTextSoundTime = Now;
}

void UDialogueSubsystem::PauseDialogue()
{
    if (!IsDialogueActive() || State == EDialogueState::Paused) return;
    StateBeforePause = State; if (UWorld* World = GetWorld()) World->GetTimerManager().PauseTimer(RevealTimerHandle); SetState(EDialogueState::Paused);
}
void UDialogueSubsystem::ResumeDialogue()
{
    if (State != EDialogueState::Paused) return;
    if (UWorld* World = GetWorld()) World->GetTimerManager().UnPauseTimer(RevealTimerHandle); SetState(StateBeforePause);
}
void UDialogueSubsystem::StopDialogue() { if (IsDialogueActive()) FinishDialogue(EDialogueEndReason::Cancelled, true); }

void UDialogueSubsystem::FinishDialogue(EDialogueEndReason Reason, bool bCancelled)
{
    if (!IsDialogueActive()) return;
    UDialogueSequence* FinishedSequence = CurrentSequence;
    SetState(EDialogueState::Closing);
    CleanupPlayback();
    CurrentSequence = nullptr; CurrentLineIndex = INDEX_NONE;
    SetState(EDialogueState::Inactive);
    if (bCancelled) OnDialogueCancelled.Broadcast(FinishedSequence, Reason); else OnDialogueFinished.Broadcast(FinishedSequence, Reason);
    if (!bCancelled) PublishDialogueEvent(this, JMDialogueEventTags::Finished, FinishedSequence, Reason);
    UE_LOG(LogReusableDialogue, Log, TEXT("Dialogue ended with reason %d."), static_cast<int32>(Reason));
}

void UDialogueSubsystem::CleanupPlayback()
{
    if (UWorld* World = GetWorld()) World->GetTimerManager().ClearTimer(RevealTimerHandle);
    if (TextAudioComponent) TextAudioComponent->Stop(); if (VoiceAudioComponent) VoiceAudioComponent->Stop();
    TextAudioComponent = nullptr; VoiceAudioComponent = nullptr;
    RestoreInteractionMode();
    if (DialogueWidget) { DialogueWidget->OnDialogueClosed(); DialogueWidget->RemoveFromParent(); }
    DialogueWidget = nullptr; OwningPlayerController = nullptr; RevealTokens.Reset(); VisibleText.Reset();
}

void UDialogueSubsystem::ApplyInteractionMode()
{
    if (!OwningPlayerController || ActiveInteractionMode != EDialogueInteractionMode::Modal) return;
    bSavedMouseCursor = OwningPlayerController->bShowMouseCursor;
    OwningPlayerController->bShowMouseCursor = true;
    DialogueWidget->SetIsFocusable(true);
    FInputModeUIOnly Mode; Mode.SetWidgetToFocus(DialogueWidget->TakeWidget()); Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    OwningPlayerController->SetInputMode(Mode);
    DialogueWidget->SetKeyboardFocus();
}

void UDialogueSubsystem::RestoreInteractionMode()
{
    if (!OwningPlayerController || ActiveInteractionMode != EDialogueInteractionMode::Modal) return;
    OwningPlayerController->SetInputMode(FInputModeGameOnly());
    OwningPlayerController->bShowMouseCursor = bSavedMouseCursor;
}
