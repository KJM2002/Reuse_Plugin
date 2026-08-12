#pragma once

#include "AI/Common/JMDungeonMonster.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BTTaskNode.h"
#include "JMMonsterBehaviorTreeNodes.generated.h"

/** Keeps a visible BT branch tied to the monster's authoritative gameplay state. */
UCLASS()
class P_060715_API UBTDecorator_JMMonsterState : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_JMMonsterState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Monster State")
	EJMDungeonMonsterState ExpectedState = EJMDungeonMonsterState::Patrol;

	virtual FString GetStaticDescription() const override;

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

/** Runs one existing monster state while exposing the active task in the Behavior Tree debugger. */
UCLASS(Blueprintable)
class P_060715_API UBTTask_JMMonsterState : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_JMMonsterState();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Monster State")
	EJMDungeonMonsterState StateToRun = EJMDungeonMonsterState::Patrol;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Monster State", meta=(ClampMin="0.02"))
	float DecisionInterval = 0.15f;

	void ConfigureTask(EJMDungeonMonsterState InState, const FString& InNodeName);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

protected:
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
