#pragma once

#include "Components/ActorComponent.h"
#include "Perception/JMEnemyPerceptionTypes.h"
#include "JMEnemyPerceptionComponent.generated.h"

class APlayerController;
struct FAIStimulus;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMStimulusReceivedSignature, FJMStimulus, Stimulus);

/** Normalizes engine sensing and owns inexpensive runtime gaze queries. It never selects behavior. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyPerceptionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyPerceptionComponent();

    void ApplyConfig(const FJMEnemyPerceptionConfig& InConfig);
    const FJMEnemyPerceptionConfig& GetConfig() const { return ActiveConfig; }

    /** Adapter entry used by AJMEnemyAIController. */
    void HandlePerceptionStimulus(AActor* SourceActor, const FAIStimulus& EngineStimulus);

    /** Shared injection boundary for damage and future external senses. */
    UFUNCTION(BlueprintCallable, Category="JM Enemy|Perception")
    bool SubmitStimulus(FJMStimulus Stimulus);

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception")
    bool IsSenseEnabled(EJMStimulusType Type) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception")
    bool GetLastStimulus(EJMStimulusType Type, FJMStimulus& OutStimulus) const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception|Gaze")
    bool IsPlayerLookingAtMe() const { return bIsPlayerLookingAtMe; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception|Gaze")
    float GetGazeStrength() const { return GazeStrength; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception|Gaze")
    float GetGazeDuration() const { return GazeDuration; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Perception|Gaze")
    AActor* GetGazeSourceActor() const { return GazeSourceActor.Get(); }

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Perception")
    FJMStimulusReceivedSignature OnStimulusReceived;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    void RefreshGazeTimer();
    void EvaluatePlayerGaze();
    bool EvaluateControllerGaze(APlayerController& Controller, FVector TargetLocation, float& OutStrength) const;
    void UpdateGazeState(bool bNewLooking, float NewStrength, AActor* NewSource, double CurrentTime);
    double GetCurrentTime() const;

    UPROPERTY(Transient)
    FJMEnemyPerceptionConfig ActiveConfig;

    UPROPERTY(Transient)
    TMap<EJMStimulusType, FJMStimulus> LastStimuli;

    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> GazeSourceActor;

    bool bIsPlayerLookingAtMe = false;
    float GazeStrength = 0.0f;
    float GazeDuration = 0.0f;
    double LastGazeEvaluationTime = -1.0;
    FTimerHandle GazeTimer;
};
