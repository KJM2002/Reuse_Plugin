#pragma once

#include "Components/ActorComponent.h"
#include "Perception/JMEnemyPerceptionTypes.h"
#include "JMEnemyMemoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMEnemyTargetChangedSignature, AActor*, PreviousTarget, AActor*, NewTarget);

/** Event-driven perception history and explicit target ownership. It does not choose targets. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyMemoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyMemoryComponent();

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Memory")
    bool SetCurrentTarget(AActor* NewTarget);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Memory")
    bool ClearCurrentTarget();

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    AActor* GetCurrentTarget() const { return CurrentTarget.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool CanCurrentlySeeTarget() const { return bCanCurrentlySeeTarget; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool CanCurrentlySeeActor(const AActor* Actor) const
    {
        return IsValid(Actor) && LastSeenSource.Get() == Actor && bLastVisionActive;
    }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool HasLastKnownTargetLocation() const { return LastKnownTargetTime >= 0.0; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    FVector GetLastKnownTargetLocation() const { return LastKnownTargetLocation; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    double GetLastKnownTargetTime() const { return LastKnownTargetTime; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    FVector GetLastSeenLocation() const { return LastSeenLocation; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    double GetLastSeenTime() const { return LastSeenTime; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    double GetTimeSinceLastSeen() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    AActor* GetLastSeenSource() const { return LastSeenSource.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    FVector GetLastHeardLocation() const { return LastHeardLocation; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    double GetLastHeardTime() const { return LastHeardTime; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    double GetTimeSinceLastHeard() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    AActor* GetLastHeardSource() const { return LastHeardSource.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    float GetLastHeardStrength() const { return LastHeardStrength; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool HasSeenTargetRecently(float MaximumAge) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool HasHeardStimulusRecently(float MaximumAge) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    bool GetLastStimulus(FJMStimulus& OutStimulus) const;

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Memory")
    int32 IncrementEncounterCount();

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Memory")
    void ResetEncounterCount() { EncounterCount = 0; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Memory")
    int32 GetEncounterCount() const { return EncounterCount; }

    /** Bound directly to UJMEnemyPerceptionComponent by AJMEnemyBase. */
    UFUNCTION()
    void HandleStimulus(FJMStimulus Stimulus);

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Memory")
    FJMEnemyTargetChangedSignature OnTargetChanged;

private:
    double GetCurrentTime() const;
    void RefreshTargetDerivedState();

    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> CurrentTarget;

    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> LastSeenSource;

    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> LastHeardSource;

    FVector LastKnownTargetLocation = FVector::ZeroVector;
    FVector LastSeenLocation = FVector::ZeroVector;
    FVector LastHeardLocation = FVector::ZeroVector;
    double LastKnownTargetTime = -1.0;
    double LastSeenTime = -1.0;
    double LastHeardTime = -1.0;
    float LastHeardStrength = 0.0f;
    bool bLastVisionActive = false;
    bool bCanCurrentlySeeTarget = false;
    bool bHasLastStimulus = false;
    int32 EncounterCount = 0;
    FJMStimulus LastStimulus;
};
