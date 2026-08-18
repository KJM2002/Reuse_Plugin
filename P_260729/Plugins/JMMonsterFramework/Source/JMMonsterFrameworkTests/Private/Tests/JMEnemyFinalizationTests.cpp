#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Audio/JMEnemyAudioComponent.h"
#include "Audio/JMEnemyAudioSet.h"
#include "Core/JMEnemyBase.h"
#include "Misc/DataValidation.h"
#include "State/JMEnemyStateComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAudioEventContractTest,
    "JM.MonsterFramework.Audio.EventContract",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAudioEventContractTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyAudioSet> Set(NewObject<UJMEnemyAudioSet>());
    FJMEnemyAudioEventEntry Enrage;
    Enrage.Event = EJMEnemyAudioEvent::Enrage;
    Set->Events.Add(Enrage);
    FJMEnemyAudioEventEntry Scream;
    Scream.Event = EJMEnemyAudioEvent::Scream;
    Set->Events.Add(Scream);

    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> ScreamDefinition(
        NewObject<UJMEnemyActionDefinition_Scream>());
    ScreamDefinition->WindupDuration = 0.0f;
    ScreamDefinition->ActiveDuration = 0.0f;
    ScreamDefinition->RecoveryDuration = 0.0f;
    TArray<TObjectPtr<UJMEnemyActionDefinition>> Definitions;
    Definitions.Add(ScreamDefinition.Get());
    Enemy->GetEnemyActionComponent()->InitializeActions(Definitions);
    UJMEnemyAudioComponent* Audio = Enemy->GetEnemyAudioComponent();
    Audio->InitializeAudio(Set.Get(), Enemy->GetEnemyStateComponent(), Enemy->GetEnemyActionComponent());
    Enemy->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Enraged);
    TestEqual(TEXT("Enraged state maps to the Enrage presentation event"),
        Audio->GetLastRequestedEvent(), EJMEnemyAudioEvent::Enrage);
    FJMEnemyActionContext Context;
    TestEqual(TEXT("Reusable Scream action executes"),
        Enemy->GetEnemyActionComponent()->ExecuteAction(JMEnemyTags::Action_Scream, Context),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Scream active phase maps to the Scream presentation event"),
        Audio->GetLastRequestedEvent(), EJMEnemyAudioEvent::Scream);
    TestFalse(TEXT("Audio component never ticks"), Audio->PrimaryComponentTick.bCanEverTick);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAudioValidationTest,
    "JM.MonsterFramework.Audio.Validation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAudioValidationTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyAudioSet> Set(NewObject<UJMEnemyAudioSet>());
    FJMEnemyAudioEventEntry First;
    First.Event = EJMEnemyAudioEvent::Attack;
    Set->Events.Add(First);
    FDataValidationContext ValidContext;
    TestEqual(TEXT("Empty placeholder event is a valid presentation contract"),
        Set->IsDataValid(ValidContext), EDataValidationResult::Valid);

    Set->Events.Add(First);
    FDataValidationContext DuplicateContext;
    TestEqual(TEXT("Duplicate audio events are rejected"),
        Set->IsDataValid(DuplicateContext), EDataValidationResult::Invalid);
    TestTrue(TEXT("Duplicate event emits an actionable error"), DuplicateContext.GetNumErrors() > 0);
    return true;
}
