#pragma once

#include "AIController.h"
#include "Perception/JMEnemyPerceptionTypes.h"
#include "JMEnemyAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
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

protected:
    virtual void BeginPlay() override;
    virtual void OnPossess(APawn* InPawn) override;
    virtual void OnUnPossess() override;

private:
    void ConfigureFromPawn();

    UFUNCTION()
    void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    UFUNCTION()
    void HandleFrameworkStimulus(FJMStimulus Stimulus);

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
};
