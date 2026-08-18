#include "Misc/AutomationTest.h"

#include "Core/JMEnemyDefinition.h"
#include "Misc/DataValidation.h"
#include "State/JMEnemyStateComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyStateComponentTest,
    "JM.MonsterFramework.Core.StateTransitions",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyStateComponentTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyStateComponent> StateComponent(NewObject<UJMEnemyStateComponent>());
    TStrongObjectPtr<UJMEnemyStateTestListener> Listener(NewObject<UJMEnemyStateTestListener>());
    StateComponent->OnStateChanged.AddDynamic(Listener.Get(), &UJMEnemyStateTestListener::HandleStateChanged);

    TestEqual(TEXT("Default state is Idle"), StateComponent->GetCurrentState(), JMEnemyTags::State_Idle.GetTag());
    TestTrue(TEXT("Parent state query matches the current leaf"), StateComponent->IsInState(JMEnemyTags::State));
    TestTrue(TEXT("A different concrete state is applied"), StateComponent->SetState(JMEnemyTags::State_Chase));
    TestEqual(TEXT("Current state changes"), StateComponent->GetCurrentState(), JMEnemyTags::State_Chase.GetTag());
    TestEqual(TEXT("Transition broadcasts once"), Listener->CallCount, 1);
    TestEqual(TEXT("Delegate includes previous state"), Listener->LastPreviousState, JMEnemyTags::State_Idle.GetTag());
    TestEqual(TEXT("Delegate includes new state"), Listener->LastNewState, JMEnemyTags::State_Chase.GetTag());
    TestFalse(TEXT("Setting the same state is an idempotent no-op"), StateComponent->SetState(JMEnemyTags::State_Chase));
    TestEqual(TEXT("Duplicate state does not broadcast"), Listener->CallCount, 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyCoreDefaultsTest,
    "JM.MonsterFramework.Core.Defaults",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyCoreDefaultsTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyDefinition> Definition(NewObject<UJMEnemyDefinition>());
    const AJMEnemyCoreTestEnemy* EnemyDefaults = GetDefault<AJMEnemyCoreTestEnemy>();

    TestNotNull(TEXT("Definition can be created independently"), Definition.Get());
    TestEqual(TEXT("Definition starts in Idle"), Definition->InitialState, JMEnemyTags::State_Idle.GetTag());
    TestTrue(TEXT("Definition has usable health"), Definition->MaxHealth > 0.0f);
    TestNotNull(TEXT("Enemy base owns the state component"), EnemyDefaults->GetEnemyStateComponent());
    TestFalse(TEXT("Enemy base does not tick"), EnemyDefaults->PrimaryActorTick.bCanEverTick);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyDefinitionValidationTest,
    "JM.MonsterFramework.Core.DefinitionValidation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyDefinitionValidationTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyDefinition> Definition(NewObject<UJMEnemyDefinition>());
    FDataValidationContext DefaultContext;

    TestEqual(TEXT("Usable defaults remain valid"),
        Definition->IsDataValid(DefaultContext), EDataValidationResult::Valid);
    TestTrue(TEXT("Missing authoring identity is reported as warnings"), DefaultContext.GetNumWarnings() >= 2);

    Definition->MaxHealth = 0.0f;
    Definition->InitialState = FGameplayTag::EmptyTag;
    FDataValidationContext InvalidContext;
    TestEqual(TEXT("Invalid required values are rejected"),
        Definition->IsDataValid(InvalidContext), EDataValidationResult::Invalid);
    TestTrue(TEXT("Invalid required values produce actionable errors"), InvalidContext.GetNumErrors() >= 2);
    return true;
}
