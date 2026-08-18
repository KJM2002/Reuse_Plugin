#include "Misc/AutomationTest.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Core/JMEnemyDefinition.h"
#include "Misc/DataValidation.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "UObject/StrongObjectPtr.h"

namespace JMEnemyActionTests
{
    void BindListener(UJMEnemyActionComponent& Component, UJMEnemyActionTestListener& Listener)
    {
        Component.OnActionStarted.AddDynamic(&Listener, &UJMEnemyActionTestListener::HandleStarted);
        Component.OnActionPhaseChanged.AddDynamic(&Listener, &UJMEnemyActionTestListener::HandlePhaseChanged);
        Component.OnActionFinished.AddDynamic(&Listener, &UJMEnemyActionTestListener::HandleFinished);
        Component.OnActionCancelled.AddDynamic(&Listener, &UJMEnemyActionTestListener::HandleCancelled);
    }

    TArray<TObjectPtr<UJMEnemyActionDefinition>> MakeDefinitions(
        UJMEnemyActionDefinition* First, UJMEnemyActionDefinition* Second = nullptr)
    {
        TArray<TObjectPtr<UJMEnemyActionDefinition>> Result;
        Result.Add(First);
        if (Second)
        {
            Result.Add(Second);
        }
        return Result;
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyActionDefinitionTest,
    "JM.MonsterFramework.Action.DefinitionAndInstances",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyActionDefinitionTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyActionDefinition_Melee> Melee(NewObject<UJMEnemyActionDefinition_Melee>());
    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> Scream(NewObject<UJMEnemyActionDefinition_Scream>());
    TestEqual(TEXT("Melee has its native identity"), Melee->ActionId, JMEnemyTags::Action_Melee.GetTag());
    TestEqual(TEXT("Scream has its native identity"), Scream->ActionId, JMEnemyTags::Action_Scream.GetTag());
    TestTrue(TEXT("Melee defaults are valid"), Melee->IsRuntimeConfigValid());
    TestTrue(TEXT("Scream defaults are valid"), Scream->IsRuntimeConfigValid());

    TStrongObjectPtr<UJMEnemyDefinition> EnemyDefinition(NewObject<UJMEnemyDefinition>());
    EnemyDefinition->Actions.Add(Melee.Get());
    EnemyDefinition->Actions.Add(Melee.Get());
    FDataValidationContext DuplicateContext;
    TestEqual(TEXT("Duplicate Action IDs are rejected"),
        EnemyDefinition->IsDataValid(DuplicateContext), EDataValidationResult::Invalid);

    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    UJMEnemyActionComponent* Component = Enemy->GetEnemyActionComponent();
    TestEqual(TEXT("Definitions create per-enemy runtime instances"),
        Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Melee.Get(), Scream.Get())), 2);
    TestNotNull(TEXT("Melee lookup succeeds"), Component->GetAction(JMEnemyTags::Action_Melee));
    TestNotNull(TEXT("Scream lookup succeeds"), Component->GetAction(JMEnemyTags::Action_Scream));
    TestEqual(TEXT("Runtime action is owned by the component"),
        Component->GetAction(JMEnemyTags::Action_Melee)->GetOuter(), static_cast<UObject*>(Component));
    TestNull(TEXT("Unknown Action lookup is safe"), Component->GetAction(FGameplayTag::EmptyTag));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyActionLifecycleTest,
    "JM.MonsterFramework.Action.LifecycleAndCancellation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyActionLifecycleTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> Scream(NewObject<UJMEnemyActionDefinition_Scream>());
    TStrongObjectPtr<UJMEnemyActionTestListener> Listener(NewObject<UJMEnemyActionTestListener>());
    Scream->WindupDuration = 10.0f;
    Scream->ActiveDuration = 0.0f;
    Scream->RecoveryDuration = 0.0f;
    Scream->ActionClass = UJMEnemyActionTickingScream::StaticClass();

    UJMEnemyActionComponent* Component = Enemy->GetEnemyActionComponent();
    Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Scream.Get()));
    JMEnemyActionTests::BindListener(*Component, *Listener);

    TestEqual(TEXT("Scream starts through the generic API"),
        Component->ExecuteAction(JMEnemyTags::Action_Scream, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::Started);
    TestTrue(TEXT("Current action is running"), Component->IsActionRunning());
    TestTrue(TEXT("An opt-in Action enables component Update only while running"),
        Component->IsComponentTickEnabled());
    TestEqual(TEXT("Runtime phase is Windup"),
        Component->GetCurrentAction()->GetPhase(), EJMEnemyActionPhase::Windup);
    TestEqual(TEXT("Another primary action request is rejected while running"),
        Component->ExecuteAction(JMEnemyTags::Action_Scream, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::AlreadyRunning);
    TestEqual(TEXT("Unknown Action is reported distinctly"),
        Component->ExecuteAction(FGameplayTag::EmptyTag, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::NotFound);
    TestTrue(TEXT("Explicit cancel succeeds"), Component->CancelCurrentAction());
    TestFalse(TEXT("Cancel clears current action"), Component->IsActionRunning());
    TestNull(TEXT("Current action pointer is cleared"), Component->GetCurrentAction());
    TestEqual(TEXT("Started event fires once"), Listener->StartedCount, 1);
    TestEqual(TEXT("Cancelled event is distinct from finish"), Listener->CancelledCount, 1);
    TestEqual(TEXT("Cancelled action does not finish"), Listener->FinishedCount, 0);
    TestFalse(TEXT("Cancellation does not start cooldown"),
        Component->IsActionOnCooldown(JMEnemyTags::Action_Scream));
    TestFalse(TEXT("Cancel disables the opt-in Action Update"),
        Component->IsComponentTickEnabled());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyMeleeActionTest,
    "JM.MonsterFramework.Action.Melee",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyMeleeActionTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<AJMEnemyActionDamageTarget> Target(NewObject<AJMEnemyActionDamageTarget>());
    TStrongObjectPtr<UJMEnemyActionDefinition_Melee> Melee(NewObject<UJMEnemyActionDefinition_Melee>());
    Melee->Damage = 30.0f;
    Melee->AttackRange = 150.0f;
    Melee->WindupDuration = 0.0f;
    Melee->ActiveDuration = 0.0f;
    Melee->RecoveryDuration = 0.0f;
    Melee->Cooldown = 10.0f;

    UJMEnemyActionComponent* Component = Enemy->GetEnemyActionComponent();
    Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Melee.Get()));
    FJMEnemyActionContext Context;

    TestEqual(TEXT("Melee requires a target"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::CannotExecute);

    Context.TargetActor = Target.Get();
    Target->SetActorLocation(FVector(500.0, 0.0, 0.0));
    TestEqual(TEXT("Melee rejects a target outside start range"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::CannotExecute);

    Target->SetActorLocation(FVector(50.0, 0.0, 0.0));
    TestEqual(TEXT("In-range Melee starts"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Damage is applied once at Active entry"), Target->DamageCallCount, 1);
    TestEqual(TEXT("Standard damage amount is forwarded"), Target->DamageTaken, 30.0f);
    TestTrue(TEXT("Finished Melee enters timestamp cooldown"),
        Component->IsActionOnCooldown(JMEnemyTags::Action_Melee));
    TestEqual(TEXT("Immediate cooldown re-execution is rejected"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::CannotExecute);

    TStrongObjectPtr<UJMEnemyActionDefinition_Melee> Recheck(NewObject<UJMEnemyActionDefinition_Melee>());
    Recheck->ActionClass = UJMEnemyActionMoveTargetOnStart::StaticClass();
    Recheck->Damage = 30.0f;
    Recheck->AttackRange = 150.0f;
    Recheck->WindupDuration = 0.0f;
    Recheck->ActiveDuration = 0.0f;
    Recheck->RecoveryDuration = 0.0f;
    Recheck->Cooldown = 0.0f;
    Target->DamageCallCount = 0;
    Target->DamageTaken = 0.0f;
    Target->SetActorLocation(FVector(50.0, 0.0, 0.0));
    Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Recheck.Get()));
    TestEqual(TEXT("Melee can start while initially in range"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Active entry rechecks range after Windup"), Target->DamageCallCount, 0);

    Melee->WindupDuration = 10.0f;
    Melee->Cooldown = 0.0f;
    Target->SetActorLocation(FVector(50.0, 0.0, 0.0));
    Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Melee.Get()));
    TestEqual(TEXT("Cancelable Melee starts in Windup"),
        Component->ExecuteAction(JMEnemyTags::Action_Melee, Context),
        EJMEnemyActionExecuteResult::Started);
    TestTrue(TEXT("Windup Melee cancels"), Component->CancelCurrentAction());
    TestEqual(TEXT("Cancelled Windup applies no damage"), Target->DamageCallCount, 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyScreamActionTest,
    "JM.MonsterFramework.Action.Scream",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyScreamActionTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> Scream(NewObject<UJMEnemyActionDefinition_Scream>());
    TStrongObjectPtr<UJMEnemyActionTestListener> Listener(NewObject<UJMEnemyActionTestListener>());
    Scream->WindupDuration = 0.0f;
    Scream->ActiveDuration = 0.0f;
    Scream->RecoveryDuration = 0.0f;
    Scream->Cooldown = 5.0f;

    UJMEnemyActionComponent* Component = Enemy->GetEnemyActionComponent();
    Component->InitializeActions(JMEnemyActionTests::MakeDefinitions(Scream.Get()));
    JMEnemyActionTests::BindListener(*Component, *Listener);
    TestEqual(TEXT("Scream uses the generic execution API"),
        Component->ExecuteAction(JMEnemyTags::Action_Scream, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Scream enters Active once"), Listener->ActiveCount, 1);
    TestEqual(TEXT("Scream finishes once"), Listener->FinishedCount, 1);
    TestFalse(TEXT("Synchronous finish clears current action"), Component->IsActionRunning());
    TestTrue(TEXT("Scream cooldown is queryable"),
        Component->IsActionOnCooldown(JMEnemyTags::Action_Scream));
    return true;
}
