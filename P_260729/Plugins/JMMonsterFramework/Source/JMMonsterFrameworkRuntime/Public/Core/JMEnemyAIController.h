#pragma once

#include "AIController.h"
#include "Perception/JMEnemyPerceptionTypes.h"
#include "TimerManager.h"
#include "JMEnemyAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
class AJMEnemyBase;
class UJMEnemyPerceptionComponent;
class UJMEnemyStateTreeComponent;
struct FAIStimulus;

/** UE perception adapter only. Target selection and behavior belong to later layers. */
UCLASS()
class JMMONSTERFRAMEWORKRUNTIME_API AJMEnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    AJMEnemyAIController();

    UFUNCTION(BlueprintPure, Category="JM Enemy|StateTree")
    UJMEnemyStateTreeComponent* GetEnemyStateTreeComponent() const { return EnemyStateTree; }

    /** Called by the pawn perception facade after its memory listeners processed a stimulus. */
    void NotifyFrameworkStimulus(const FJMStimulus& Stimulus);

protected:
    virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;
    virtual void OnUnPossess() override;

private:
    void ConfigureFromPawn();
    void StartBehaviorFromPawn(const AJMEnemyBase& Enemy);
    void TryConfigurePerception();
    void SchedulePerceptionConfigurationRetry();
    void FlushFrameworkStimulusEvent();

    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    UPROPERTY(VisibleAnywhere, Category="JM Enemy|Perception")
    TObjectPtr<UAIPerceptionComponent> EnemyPerception;

    UPROPERTY(VisibleAnywhere, Category="JM Enemy|StateTree")
    TObjectPtr<UJMEnemyStateTreeComponent> EnemyStateTree;

    UPROPERTY()
    TObjectPtr<UAISenseConfig_Sight> SightConfig;

    UPROPERTY()
    TObjectPtr<UAISenseConfig_Hearing> HearingConfig;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyPerceptionComponent> FrameworkPerception;

    FTimerHandle PerceptionConfigurationTimer;
    FTimerHandle StimulusEventTimer;
    int32 PerceptionConfigurationAttempts = 0;
    bool bBehaviorStarted = false;
    bool bStimulusEventQueued = false;
};
