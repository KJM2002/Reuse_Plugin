#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Core/JMEnemyAIController.h"
#include "Core/JMEnemyDefinition.h"
#include "HAL/PlatformTime.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "StateTree/JMEnemyStateTreeComponent.h"
#include "StateTree/JMEnemyStateTreeConditions.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyStateTreeRuntimeOwnershipTest,
    "JM.MonsterFramework.StateTree.RuntimeOwnership",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyStateTreeRuntimeOwnershipTest::RunTest(const FString& Parameters)
{
    const AJMEnemyAIController* Controller = GetDefault<AJMEnemyAIController>();
    TStrongObjectPtr<UJMEnemyDefinition> Definition(NewObject<UJMEnemyDefinition>());
    TestNotNull(TEXT("AIController owns the StateTree runner"), Controller->GetEnemyStateTreeComponent());
    TestFalse(TEXT("StateTree does not auto-start before possession"),
        Controller->GetEnemyStateTreeComponent()->IsRunning());
    TestNull(TEXT("StateTree remains optional on reusable definitions"), Definition->StateTree.Get());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyStateTreeEventBridgeTest,
    "JM.MonsterFramework.StateTree.EventBridges",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyStateTreeEventBridgeTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    UJMEnemyLocomotionComponent* Locomotion = Enemy->GetEnemyLocomotionComponent();
    int32 MoveCallbacks = 0;
    EJMEnemyMoveStatus MoveResult = EJMEnemyMoveStatus::Idle;
    const FDelegateHandle MoveHandle = Locomotion->OnMoveFinishedNative.AddLambda(
        [&MoveCallbacks, &MoveResult](FAIRequestID, EJMEnemyMoveStatus Result, AActor*, FVector)
        {
            ++MoveCallbacks;
            MoveResult = Result;
        });
    TestEqual(TEXT("Invalid actor move fails"), Locomotion->MoveToActor(nullptr, FJMEnemyMoveOptions()),
        EJMEnemyMoveRequestResult::RequestFailed);
    TestEqual(TEXT("Native movement bridge reports synchronous failure"), MoveCallbacks, 1);
    TestEqual(TEXT("Movement bridge normalizes failure"), MoveResult, EJMEnemyMoveStatus::Failed);
    Locomotion->OnMoveFinishedNative.Remove(MoveHandle);

    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> Scream(NewObject<UJMEnemyActionDefinition_Scream>());
    Scream->WindupDuration = 0.0f;
    Scream->ActiveDuration = 0.0f;
    Scream->RecoveryDuration = 0.0f;
    Scream->Cooldown = 0.0f;
    TArray<TObjectPtr<UJMEnemyActionDefinition>> Definitions{Scream.Get()};
    UJMEnemyActionComponent* Actions = Enemy->GetEnemyActionComponent();
    Actions->InitializeActions(Definitions);
    int32 FinishedCallbacks = 0;
    UJMEnemyAction* FinishedAction = nullptr;
    const FDelegateHandle ActionHandle = Actions->OnActionFinishedNative.AddLambda(
        [&FinishedCallbacks, &FinishedAction](FGameplayTag, UJMEnemyAction* Action)
        {
            ++FinishedCallbacks;
            FinishedAction = Action;
        });
    TestEqual(TEXT("Zero-duration action still reports Started"),
        Actions->ExecuteAction(JMEnemyTags::Action_Scream, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Pre-bound native bridge catches synchronous finish"), FinishedCallbacks, 1);
    TestNotNull(TEXT("Synchronous completion preserves runtime action identity"), FinishedAction);
    Actions->OnActionFinishedNative.Remove(ActionHandle);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyStateTreeConditionDataTest,
    "JM.MonsterFramework.StateTree.ConditionData",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyStateTreeConditionDataTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<AActor> Target(NewObject<AActor>());
    UJMEnemyMemoryComponent* Memory = Enemy->GetEnemyMemoryComponent();
    UJMEnemyPerceptionComponent* Perception = Enemy->GetEnemyPerceptionComponent();

    TestFalse(TEXT("Empty memory has no target"), JMEnemyStateTreeConditions::HasTarget(*Memory));
    Memory->SetCurrentTarget(Target.Get());
    TestTrue(TEXT("Valid generic actor is a target"), JMEnemyStateTreeConditions::HasTarget(*Memory));

    FJMStimulus Hearing;
    Hearing.Type = EJMStimulusType::Hearing;
    Hearing.SourceActor = Target.Get();
    Hearing.Timestamp = FPlatformTime::Seconds();
    Hearing.bSuccessfullySensed = true;
    Memory->HandleStimulus(Hearing);
    TestTrue(TEXT("Recent hearing uses memory timestamps"),
        JMEnemyStateTreeConditions::HasRecentHearing(*Memory, 1.0f));
    TestFalse(TEXT("Default gaze state does not pass"),
        JMEnemyStateTreeConditions::HasGaze(*Perception, 0.0f, 0.0f));

    Memory->IncrementEncounterCount();
    TestTrue(TEXT("Encounter comparison supports greater-or-equal"),
        JMEnemyStateTreeConditions::Compare(Memory->GetEncounterCount(), 1,
            EJMStateTreeCompare::GreaterOrEqual));
    TestTrue(TEXT("Distance comparison supports strict thresholds"),
        JMEnemyStateTreeConditions::Compare(100.0f, 200.0f, EJMStateTreeCompare::Less));
    return true;
}
