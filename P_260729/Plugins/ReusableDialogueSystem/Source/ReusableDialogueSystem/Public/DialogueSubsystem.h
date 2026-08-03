#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ReusableDialogueTypes.h"
#include "DialogueSubsystem.generated.h"

class APlayerController;
class UAudioComponent;
class UDialogueSequence;
class UDialogueTextSoundSet;
class UDialogueWidgetBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueStartedSignature, UDialogueSequence*, Sequence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueStateChangedSignature, EDialogueState, PreviousState, EDialogueState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDialogueLineSignature, UDialogueSequence*, Sequence, FName, LineId, int32, LineIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueEndedSignature, UDialogueSequence*, Sequence, EDialogueEndReason, Reason);

UCLASS()
class REUSABLEDIALOGUESYSTEM_API UDialogueSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category="Dialogue") bool StartDialogue(UDialogueSequence* Sequence, EDialogueInteractionMode InteractionMode, APlayerController* PlayerController, EExistingDialoguePolicy ExistingPolicy = EExistingDialoguePolicy::Reject);
    UFUNCTION(BlueprintCallable, Category="Dialogue") void AdvanceDialogue();
    UFUNCTION(BlueprintCallable, Category="Dialogue") void CompleteCurrentLine();
    UFUNCTION(BlueprintCallable, Category="Dialogue") void StopDialogue();
    UFUNCTION(BlueprintCallable, Category="Dialogue") void PauseDialogue();
    UFUNCTION(BlueprintCallable, Category="Dialogue") void ResumeDialogue();

    UFUNCTION(BlueprintPure, Category="Dialogue") bool IsDialogueActive() const { return State != EDialogueState::Inactive; }
    UFUNCTION(BlueprintPure, Category="Dialogue") bool IsLineRevealing() const { return State == EDialogueState::Revealing; }
    UFUNCTION(BlueprintPure, Category="Dialogue") EDialogueState GetDialogueState() const { return State; }
    UFUNCTION(BlueprintPure, Category="Dialogue") UDialogueSequence* GetCurrentSequence() const { return CurrentSequence; }
    UFUNCTION(BlueprintPure, Category="Dialogue") int32 GetCurrentLineIndex() const { return CurrentLineIndex; }
    UFUNCTION(BlueprintPure, Category="Dialogue") FDialogueLine GetCurrentLine() const;
    UFUNCTION(BlueprintPure, Category="Dialogue") const TArray<FDialogueHistoryEntry>& GetDialogueHistory() const { return DialogueHistory; }
    UFUNCTION(BlueprintCallable, Category="Dialogue") void ClearDialogueHistory() { DialogueHistory.Reset(); }

    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueStartedSignature OnDialogueStarted;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueStateChangedSignature OnDialogueStateChanged;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueLineSignature OnLineStarted;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueLineSignature OnLineRevealCompleted;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueLineSignature OnLineAdvanced;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueEndedSignature OnDialogueFinished;
    UPROPERTY(BlueprintAssignable, Category="Dialogue|Events") FDialogueEndedSignature OnDialogueCancelled;

private:
    void SetState(EDialogueState NewState);
    void BeginCurrentLine();
    void BeginReveal();
    void RevealNextToken();
    void ScheduleNextReveal(float Delay);
    void MoveToNextLine();
    void FinishDialogue(EDialogueEndReason Reason, bool bCancelled);
    void CleanupPlayback();
    void ApplyInteractionMode();
    void RestoreInteractionMode();
    void RecordCurrentLine();
    void PlayTextSound(const FDialogueRevealToken& Token);
    UDialogueTextSoundSet* ResolveTextSoundSet(const FDialogueLine& Line) const;

    UPROPERTY(Transient) TObjectPtr<UDialogueSequence> CurrentSequence = nullptr;
    UPROPERTY(Transient) TObjectPtr<UDialogueWidgetBase> DialogueWidget = nullptr;
    UPROPERTY(Transient) TObjectPtr<APlayerController> OwningPlayerController = nullptr;
    UPROPERTY(Transient) TObjectPtr<UAudioComponent> TextAudioComponent = nullptr;
    UPROPERTY(Transient) TObjectPtr<UAudioComponent> VoiceAudioComponent = nullptr;
    UPROPERTY(Transient) TArray<FDialogueHistoryEntry> DialogueHistory;
    UPROPERTY(Transient) EDialogueState State = EDialogueState::Inactive;

    EDialogueState StateBeforePause = EDialogueState::Inactive;
    EDialogueInteractionMode ActiveInteractionMode = EDialogueInteractionMode::Overlay;
    EDialogueRevealMode ActiveRevealMode = EDialogueRevealMode::Character;
    TArray<FDialogueRevealToken> RevealTokens;
    FString VisibleText;
    int32 CurrentLineIndex = INDEX_NONE;
    int32 RevealTokenIndex = 0;
    int32 RevealCharacterCount = 0;
    int32 LastSoundIndex = INDEX_NONE;
    bool bCurrentLineRecorded = false;
    bool bSavedMouseCursor = false;
    double LastAdvanceTime = -1.0;
    double LastTextSoundTime = -1.0;
    FTimerHandle RevealTimerHandle;
};
