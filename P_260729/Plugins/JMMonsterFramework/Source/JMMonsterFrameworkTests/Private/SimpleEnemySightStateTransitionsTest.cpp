#include "AI/SimpleEnemyAIController.h"

#include "GameFramework/Actor.h"
#include "Misc/AutomationTest.h"
#include "UObject/StrongObjectPtr.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemySightStateTransitionsTest,
    "JM.MonsterFramework.Phase1.SightStateTransitions",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemySightStateTransitionsTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<ASimpleEnemyAIController> Controller(NewObject<ASimpleEnemyAIController>());
    TStrongObjectPtr<AActor> PlayerTarget(NewObject<AActor>());
    TStrongObjectPtr<AActor> UnrelatedTarget(NewObject<AActor>());

    TestNull(TEXT("Target starts empty"), Controller->TargetActor.Get());
    TestFalse(TEXT("Sight starts false"), Controller->bCanSeeTarget);

    Controller->ApplySightState(nullptr, true);
    TestNull(TEXT("Null detection is ignored"), Controller->TargetActor.Get());
    TestFalse(TEXT("Null detection does not enable sight"), Controller->bCanSeeTarget);

    for (int32 Iteration = 0; Iteration < 20; ++Iteration)
    {
        Controller->ApplySightState(PlayerTarget.Get(), true);
        TestEqual(
            FString::Printf(TEXT("Detected target is stable on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestTrue(
            FString::Printf(TEXT("Detected flag is true on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);

        Controller->ApplySightState(PlayerTarget.Get(), true);
        TestEqual(
            FString::Printf(TEXT("Duplicate detection does not change target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());

        Controller->ApplySightState(UnrelatedTarget.Get(), false);
        TestEqual(
            FString::Printf(TEXT("Unrelated loss does not clear target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestTrue(
            FString::Printf(TEXT("Unrelated loss preserves sight on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);

        Controller->ApplySightState(PlayerTarget.Get(), false);
        TestNull(
            FString::Printf(TEXT("Lost clears target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get());
        TestFalse(
            FString::Printf(TEXT("Lost clears flag on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);

        Controller->ApplySightState(PlayerTarget.Get(), false);
        TestNull(
            FString::Printf(TEXT("Duplicate loss remains stable on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get());
    }

    return true;
}

#endif
