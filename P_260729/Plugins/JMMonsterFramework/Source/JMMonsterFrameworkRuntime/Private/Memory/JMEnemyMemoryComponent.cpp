#include "Memory/JMEnemyMemoryComponent.h"

#include "Engine/World.h"
#include "HAL/PlatformTime.h"

UJMEnemyMemoryComponent::UJMEnemyMemoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMEnemyMemoryComponent::SetCurrentTarget(AActor* NewTarget)
{
    if (CurrentTarget.Get() == NewTarget)
    {
        return false;
    }

    AActor* PreviousTarget = CurrentTarget.Get();
    CurrentTarget = NewTarget;
    RefreshTargetDerivedState();
    OnTargetChanged.Broadcast(PreviousTarget, NewTarget);
    return true;
}

bool UJMEnemyMemoryComponent::ClearCurrentTarget()
{
    return SetCurrentTarget(nullptr);
}

void UJMEnemyMemoryComponent::HandleStimulus(FJMStimulus Stimulus)
{
    if (!Stimulus.IsValid())
    {
        return;
    }

    LastStimulus = Stimulus;
    bHasLastStimulus = true;
    AActor* Source = Stimulus.SourceActor.Get();

    if (Stimulus.Type == EJMStimulusType::Vision)
    {
        // Once a target is selected, unrelated vision stimuli must not replace its recency data.
        // Otherwise one nearby pawn makes HasSeenTargetRecently() fail immediately and aborts
        // Chase/Stalk even though the actual target is still visible.
        const bool bMayUpdateSeenSource = !CurrentTarget.IsValid() || Source == CurrentTarget.Get();
        if (Stimulus.bSuccessfullySensed && bMayUpdateSeenSource && Stimulus.Timestamp >= LastSeenTime)
        {
            LastSeenSource = Source;
            LastSeenLocation = Stimulus.WorldLocation;
            LastSeenTime = Stimulus.Timestamp;
            bLastVisionActive = true;
        }
        else if (LastSeenSource.Get() == Source && Stimulus.Timestamp >= LastSeenTime)
        {
            bLastVisionActive = false;
        }
    }
    else if (Stimulus.Type == EJMStimulusType::Hearing && Stimulus.bSuccessfullySensed &&
        Stimulus.Timestamp >= LastHeardTime)
    {
        LastHeardSource = Source;
        LastHeardLocation = Stimulus.WorldLocation;
        LastHeardTime = Stimulus.Timestamp;
        LastHeardStrength = Stimulus.Strength;
    }

    if (Source && Source == CurrentTarget.Get() && Stimulus.bSuccessfullySensed &&
        (Stimulus.Type == EJMStimulusType::Vision || Stimulus.Type == EJMStimulusType::Hearing) &&
        Stimulus.Timestamp >= LastKnownTargetTime)
    {
        LastKnownTargetLocation = Stimulus.WorldLocation;
        LastKnownTargetTime = Stimulus.Timestamp;
    }

    if (Stimulus.Type == EJMStimulusType::Vision && Source == CurrentTarget.Get() &&
        Stimulus.Timestamp >= LastSeenTime)
    {
        bCanCurrentlySeeTarget = Stimulus.bSuccessfullySensed;
    }
}

bool UJMEnemyMemoryComponent::HasSeenTargetRecently(const float MaximumAge) const
{
    const double Age = GetTimeSinceLastSeen();
    return MaximumAge >= 0.0f && CurrentTarget.IsValid() && LastSeenSource == CurrentTarget &&
        Age >= 0.0 && Age <= MaximumAge;
}

bool UJMEnemyMemoryComponent::HasHeardStimulusRecently(const float MaximumAge) const
{
    const double Age = GetTimeSinceLastHeard();
    return MaximumAge >= 0.0f && Age >= 0.0 && Age <= MaximumAge;
}

double UJMEnemyMemoryComponent::GetTimeSinceLastSeen() const
{
    return LastSeenTime >= 0.0 ? FMath::Max(0.0, GetCurrentTime() - LastSeenTime) : -1.0;
}

double UJMEnemyMemoryComponent::GetTimeSinceLastHeard() const
{
    return LastHeardTime >= 0.0 ? FMath::Max(0.0, GetCurrentTime() - LastHeardTime) : -1.0;
}

bool UJMEnemyMemoryComponent::GetLastStimulus(FJMStimulus& OutStimulus) const
{
    if (!bHasLastStimulus)
    {
        return false;
    }
    OutStimulus = LastStimulus;
    return true;
}

int32 UJMEnemyMemoryComponent::IncrementEncounterCount()
{
    return ++EncounterCount;
}

double UJMEnemyMemoryComponent::GetCurrentTime() const
{
    return GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : FPlatformTime::Seconds();
}

void UJMEnemyMemoryComponent::RefreshTargetDerivedState()
{
    AActor* Target = CurrentTarget.Get();
    bCanCurrentlySeeTarget = Target && LastSeenSource.Get() == Target && bLastVisionActive;

    if (!Target)
    {
        return;
    }

    if (LastSeenSource.Get() == Target && LastSeenTime >= LastHeardTime)
    {
        LastKnownTargetLocation = LastSeenLocation;
        LastKnownTargetTime = LastSeenTime;
    }
    else if (LastHeardSource.Get() == Target)
    {
        LastKnownTargetLocation = LastHeardLocation;
        LastKnownTargetTime = LastHeardTime;
    }
    else
    {
        LastKnownTargetLocation = FVector::ZeroVector;
        LastKnownTargetTime = -1.0;
    }
}
