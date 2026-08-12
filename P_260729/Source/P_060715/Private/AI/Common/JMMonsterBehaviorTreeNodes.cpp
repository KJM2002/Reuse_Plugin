#include "AI/Common/JMMonsterBehaviorTreeNodes.h"

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

namespace
{
	AJMDungeonMonster* GetMonster(const UBehaviorTreeComponent& OwnerComp)
	{
		const AAIController* Controller = OwnerComp.GetAIOwner();
		return Controller ? Cast<AJMDungeonMonster>(Controller->GetPawn()) : nullptr;
	}

	FString StateDisplayName(EJMDungeonMonsterState State)
	{
		const UEnum* Enum = StaticEnum<EJMDungeonMonsterState>();
		return Enum ? Enum->GetDisplayNameTextByValue(static_cast<int64>(State)).ToString() : TEXT("Unknown");
	}
}

UBTDecorator_JMMonsterState::UBTDecorator_JMMonsterState()
{
	NodeName = TEXT("Monster State Is");
}

bool UBTDecorator_JMMonsterState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8*) const
{
	const AJMDungeonMonster* Monster = GetMonster(OwnerComp);
	return Monster && Monster->GetMonsterState() == ExpectedState;
}

FString UBTDecorator_JMMonsterState::GetStaticDescription() const
{
	return FString::Printf(TEXT("Monster State == %s"), *StateDisplayName(ExpectedState));
}

UBTTask_JMMonsterState::UBTTask_JMMonsterState()
{
	NodeName = TEXT("Run Monster State");
	bTickIntervals = true;
	INIT_TASK_NODE_NOTIFY_FLAGS();
}

void UBTTask_JMMonsterState::ConfigureTask(EJMDungeonMonsterState InState, const FString& InNodeName)
{
	StateToRun = InState;
	NodeName = InNodeName;
}

EBTNodeResult::Type UBTTask_JMMonsterState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AJMDungeonMonster* Monster = GetMonster(OwnerComp);
	if (!Monster || Monster->GetMonsterState() != StateToRun)
	{
		return EBTNodeResult::Failed;
	}
	if (UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent())
	{
		Monster->SyncBehaviorTreeBlackboard(*Blackboard);
	}
	SetNextTickTime(NodeMemory, FMath::Max(0.02f, DecisionInterval));
	return EBTNodeResult::InProgress;
}

void UBTTask_JMMonsterState::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float)
{
	AJMDungeonMonster* Monster = GetMonster(OwnerComp);
	if (!Monster)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return;
	}
	if (Monster->GetMonsterState() != StateToRun)
	{
		if (UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent())
		{
			Monster->SyncBehaviorTreeBlackboard(*Blackboard);
		}
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}

	Monster->TickBehaviorTreeDecision(StateToRun);
	if (UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent())
	{
		Monster->SyncBehaviorTreeBlackboard(*Blackboard);
	}
	if (Monster->GetMonsterState() != StateToRun)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return;
	}
	SetNextTickTime(NodeMemory, FMath::Max(0.02f, DecisionInterval));
}

FString UBTTask_JMMonsterState::GetStaticDescription() const
{
	return FString::Printf(TEXT("Runs %s state every %.2fs and mirrors it to the Blackboard."),
		*StateDisplayName(StateToRun), DecisionInterval);
}
