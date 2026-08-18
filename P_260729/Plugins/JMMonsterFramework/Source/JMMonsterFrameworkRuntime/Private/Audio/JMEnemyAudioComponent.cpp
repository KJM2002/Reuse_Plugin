#include "Audio/JMEnemyAudioComponent.h"

#include "Action/JMEnemyActionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "State/JMEnemyStateComponent.h"
#include "Types/JMEnemyTags.h"

UJMEnemyAudioComponent::UJMEnemyAudioComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMEnemyAudioComponent::InitializeAudio(UJMEnemyAudioSet* InAudioSet,
    UJMEnemyStateComponent* State, UJMEnemyActionComponent* Actions)
{
    UnbindSources();
    AudioSet = InAudioSet;
    BoundState = State;
    BoundActions = Actions;
    if (!AudioSet) return;

    if (State)
    {
        State->OnStateChanged.AddUniqueDynamic(this, &ThisClass::HandleStateChanged);
    }
    if (Actions)
    {
        ActionStartedHandle = Actions->OnActionStartedNative.AddUObject(this, &ThisClass::HandleActionStarted);
        ActionPhaseChangedHandle = Actions->OnActionPhaseChangedNative.AddUObject(
            this, &ThisClass::HandleActionPhaseChanged);
    }
    if (State)
    {
        HandleStateChanged(FGameplayTag::EmptyTag, State->GetCurrentState());
    }
}

bool UJMEnemyAudioComponent::PlayAudioEvent(const EJMEnemyAudioEvent Event)
{
    LastRequestedEvent = Event;
    const FJMEnemyAudioEventEntry* Entry = AudioSet ? AudioSet->FindEvent(Event) : nullptr;
    if (!Entry || Entry->Variants.IsEmpty() || !GetOwner()) return false;

    const FJMEnemyAudioVariant& Variant = Entry->Variants[FMath::RandHelper(Entry->Variants.Num())];
    if (!Variant.IsValid()) return false;
    UGameplayStatics::PlaySoundAtLocation(this, Variant.Sound, GetOwner()->GetActorLocation(),
        FMath::FRandRange(Variant.VolumeRange.X, Variant.VolumeRange.Y),
        FMath::FRandRange(Variant.PitchRange.X, Variant.PitchRange.Y));
    return true;
}

void UJMEnemyAudioComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UnbindSources();
    Super::EndPlay(EndPlayReason);
}

void UJMEnemyAudioComponent::HandleStateChanged(FGameplayTag, const FGameplayTag NewState)
{
    if (NewState == JMEnemyTags::State_Idle) PlayAudioEvent(EJMEnemyAudioEvent::Idle);
    else if (NewState == JMEnemyTags::State_Investigate) PlayAudioEvent(EJMEnemyAudioEvent::Investigate);
    else if (NewState == JMEnemyTags::State_Chase) PlayAudioEvent(EJMEnemyAudioEvent::Chase);
    else if (NewState == JMEnemyTags::State_Flee) PlayAudioEvent(EJMEnemyAudioEvent::Flee);
    else if (NewState == JMEnemyTags::State_Watcher_Frozen) PlayAudioEvent(EJMEnemyAudioEvent::Frozen);
    else if (NewState == JMEnemyTags::State_Enraged) PlayAudioEvent(EJMEnemyAudioEvent::Enrage);
    else if (NewState == JMEnemyTags::State_Crawler_FrenzyChase) PlayAudioEvent(EJMEnemyAudioEvent::Frenzy);
    else if (NewState == JMEnemyTags::State_Dead) PlayAudioEvent(EJMEnemyAudioEvent::Death);
}

void UJMEnemyAudioComponent::HandleActionStarted(
    const FGameplayTag ActionId, UJMEnemyAction*)
{
    if (ActionId == JMEnemyTags::Action_Melee)
    {
        PlayAudioEvent(EJMEnemyAudioEvent::AttackWindup);
    }
}

void UJMEnemyAudioComponent::HandleActionPhaseChanged(const FGameplayTag ActionId, UJMEnemyAction*,
    EJMEnemyActionPhase, const EJMEnemyActionPhase NewPhase)
{
    if (NewPhase != EJMEnemyActionPhase::Active) return;
    if (ActionId == JMEnemyTags::Action_Melee) PlayAudioEvent(EJMEnemyAudioEvent::Attack);
    else if (ActionId == JMEnemyTags::Action_Scream) PlayAudioEvent(EJMEnemyAudioEvent::Scream);
}

void UJMEnemyAudioComponent::UnbindSources()
{
    if (BoundState.IsValid())
    {
        BoundState->OnStateChanged.RemoveDynamic(this, &ThisClass::HandleStateChanged);
    }
    if (BoundActions.IsValid())
    {
        BoundActions->OnActionStartedNative.Remove(ActionStartedHandle);
        BoundActions->OnActionPhaseChangedNative.Remove(ActionPhaseChangedHandle);
    }
    ActionStartedHandle.Reset();
    ActionPhaseChangedHandle.Reset();
    BoundState.Reset();
    BoundActions.Reset();
}
