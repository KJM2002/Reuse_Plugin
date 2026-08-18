#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "HAL/PlatformTime.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense_Sight.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyStimulusDefaultsTest,
    "JM.MonsterFramework.Perception.StimulusDefaults",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyStimulusDefaultsTest::RunTest(const FString& Parameters)
{
    const FJMStimulus Stimulus;
    TestEqual(TEXT("Default type is Vision"), Stimulus.Type, EJMStimulusType::Vision);
    TestNull(TEXT("Default source is empty"), Stimulus.SourceActor.Get());
    TestEqual(TEXT("Default location is zero"), Stimulus.WorldLocation, FVector::ZeroVector);
    TestEqual(TEXT("Default strength is zero"), Stimulus.Strength, 0.0f);
    TestEqual(TEXT("Default confidence is zero"), Stimulus.Confidence, 0.0f);
    TestFalse(TEXT("Default stimulus is inactive"), Stimulus.bSuccessfullySensed);
    TestFalse(TEXT("Unset timestamp keeps the default stimulus invalid"), Stimulus.IsValid());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyPerceptionNormalizationTest,
    "JM.MonsterFramework.Perception.Normalization",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyPerceptionNormalizationTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyPerceptionComponent> Perception(NewObject<UJMEnemyPerceptionComponent>());
    TStrongObjectPtr<AActor> Source(NewObject<AActor>());
    FJMEnemyPerceptionConfig Config;
    Config.Vision.bEnabled = true;
    Config.Hearing.bEnabled = false;
    Perception->ApplyConfig(Config);

    const FVector SeenAt(100.0, 200.0, 300.0);
    const FAIStimulus SightStimulus(
        *GetDefault<UAISense_Sight>(), 0.75f, SeenAt, FVector::ZeroVector,
        FAIStimulus::SensingSucceeded, TEXT("Automation sight"));
    Perception->HandlePerceptionStimulus(Source.Get(), SightStimulus);

    FJMStimulus Normalized;
    TestTrue(TEXT("Sight is normalized and retained"),
        Perception->GetLastStimulus(EJMStimulusType::Vision, Normalized));
    TestEqual(TEXT("Normalized type is Vision"), Normalized.Type, EJMStimulusType::Vision);
    TestEqual(TEXT("Source is preserved weakly"), Normalized.SourceActor.Get(), Source.Get());
    TestEqual(TEXT("World location is preserved"), Normalized.WorldLocation, SeenAt);
    TestEqual(TEXT("Strength is preserved"), Normalized.Strength, 0.75f);
    TestTrue(TEXT("Successful sense remains active"), Normalized.bSuccessfullySensed);
    TestFalse(TEXT("Disabled hearing rejects direct evidence"), Perception->IsSenseEnabled(EJMStimulusType::Hearing));
    TestTrue(TEXT("Damage channel remains available independently"), Perception->IsSenseEnabled(EJMStimulusType::Damage));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyMemoryPolicyTest,
    "JM.MonsterFramework.Memory.EventDrivenPolicy",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyMemoryPolicyTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMEnemyMemoryComponent> Memory(NewObject<UJMEnemyMemoryComponent>());
    TStrongObjectPtr<UJMEnemyMemoryTestListener> Listener(NewObject<UJMEnemyMemoryTestListener>());
    TStrongObjectPtr<AActor> Target(NewObject<AActor>());
    Memory->OnTargetChanged.AddDynamic(Listener.Get(), &UJMEnemyMemoryTestListener::HandleTargetChanged);

    TestTrue(TEXT("Target is selected explicitly"), Memory->SetCurrentTarget(Target.Get()));
    TestEqual(TEXT("Target change broadcasts once"), Listener->CallCount, 1);

    const double Now = FPlatformTime::Seconds();
    FJMStimulus Vision;
    Vision.Type = EJMStimulusType::Vision;
    Vision.SourceActor = Target.Get();
    Vision.WorldLocation = FVector(10.0, 20.0, 30.0);
    Vision.Strength = 1.0f;
    Vision.Confidence = 1.0f;
    Vision.Timestamp = Now;
    Vision.bSuccessfullySensed = true;
    Memory->HandleStimulus(Vision);

    TestTrue(TEXT("Active target vision is represented"), Memory->CanCurrentlySeeTarget());
    TestEqual(TEXT("Seen position becomes last-known target position"),
        Memory->GetLastKnownTargetLocation(), Vision.WorldLocation);
    TestTrue(TEXT("Recent target vision is computed without Tick"), Memory->HasSeenTargetRecently(1.0f));

    FJMStimulus LostVision = Vision;
    LostVision.WorldLocation = FVector(999.0, 999.0, 999.0);
    LostVision.Timestamp = Now + 0.01;
    LostVision.bSuccessfullySensed = false;
    Memory->HandleStimulus(LostVision);
    TestFalse(TEXT("Losing sight clears only current visibility"), Memory->CanCurrentlySeeTarget());
    TestEqual(TEXT("Losing sight preserves the last confirmed seen position"),
        Memory->GetLastSeenLocation(), Vision.WorldLocation);

    FJMStimulus Hearing;
    Hearing.Type = EJMStimulusType::Hearing;
    Hearing.SourceActor = Target.Get();
    Hearing.WorldLocation = FVector(40.0, 50.0, 60.0);
    Hearing.Strength = 0.6f;
    Hearing.Confidence = 0.8f;
    Hearing.Timestamp = Now + 0.02;
    Hearing.bSuccessfullySensed = true;
    Memory->HandleStimulus(Hearing);
    TestEqual(TEXT("Newer hearing updates last-known target position"),
        Memory->GetLastKnownTargetLocation(), Hearing.WorldLocation);
    TestEqual(TEXT("Hearing strength is retained"), Memory->GetLastHeardStrength(), 0.6f);
    TestEqual(TEXT("Hearing source is retained weakly"), Memory->GetLastHeardSource(), Target.Get());
    TestTrue(TEXT("Recent hearing is computed without Tick"), Memory->HasHeardStimulusRecently(1.0f));
    TestTrue(TEXT("Seen age query is available"), Memory->GetTimeSinceLastSeen() >= 0.0);
    TestTrue(TEXT("Heard age query is available"), Memory->GetTimeSinceLastHeard() >= 0.0);

    TestEqual(TEXT("Encounter count starts empty"), Memory->GetEncounterCount(), 0);
    TestEqual(TEXT("Encounter increment returns the new value"), Memory->IncrementEncounterCount(), 1);
    Memory->ResetEncounterCount();
    TestEqual(TEXT("Encounter count resets"), Memory->GetEncounterCount(), 0);
    TestTrue(TEXT("Target can be explicitly cleared"), Memory->ClearCurrentTarget());
    TestEqual(TEXT("Clearing target broadcasts"), Listener->CallCount, 2);
    TestEqual(TEXT("Historical hearing survives target clearing"), Memory->GetLastHeardLocation(), Hearing.WorldLocation);
    TestFalse(TEXT("Memory never ticks"), Memory->PrimaryComponentTick.bCanEverTick);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMEnemyPerceptionMemoryCompositionTest,
    "JM.MonsterFramework.Core.PerceptionMemoryComposition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyPerceptionMemoryCompositionTest::RunTest(const FString& Parameters)
{
    const AJMEnemyCoreTestEnemy* EnemyDefaults = GetDefault<AJMEnemyCoreTestEnemy>();
    TestNotNull(TEXT("Enemy base owns the perception facade"), EnemyDefaults->GetEnemyPerceptionComponent());
    TestNotNull(TEXT("Enemy base owns memory"), EnemyDefaults->GetEnemyMemoryComponent());
    TestNotNull(TEXT("Enemy base owns locomotion"), EnemyDefaults->GetEnemyLocomotionComponent());
    TestNotNull(TEXT("Enemy base owns actions"), EnemyDefaults->GetEnemyActionComponent());
    TestFalse(TEXT("Perception facade does not tick"),
        EnemyDefaults->GetEnemyPerceptionComponent()->PrimaryComponentTick.bCanEverTick);
    TestFalse(TEXT("Memory does not tick"),
        EnemyDefaults->GetEnemyMemoryComponent()->PrimaryComponentTick.bCanEverTick);
    TestFalse(TEXT("Locomotion does not tick"),
        EnemyDefaults->GetEnemyLocomotionComponent()->PrimaryComponentTick.bCanEverTick);
    TestFalse(TEXT("Action component starts with Tick disabled"),
        EnemyDefaults->GetEnemyActionComponent()->PrimaryComponentTick.bStartWithTickEnabled);
    return true;
}
