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
    TestEqual(TEXT("Last seen location starts at zero"), Controller->LastSeenLocation, FVector::ZeroVector);

    Controller->ApplySightState(nullptr, true, FVector(1.0, 2.0, 3.0));
    TestNull(TEXT("Null detection is ignored"), Controller->TargetActor.Get());
    TestFalse(TEXT("Null detection does not enable sight"), Controller->bCanSeeTarget);

    for (int32 Iteration = 0; Iteration < 20; ++Iteration)
    {
        const FVector DetectedLocation(Iteration * 100.0, 25.0, 0.0);
        const FVector LastObservedLocation(Iteration * 100.0 + 50.0, 75.0, 0.0);

        Controller->ApplySightState(PlayerTarget.Get(), true, DetectedLocation);
        TestEqual(
            FString::Printf(TEXT("Detected target is stable on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestTrue(
            FString::Printf(TEXT("Detected flag is true on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);
        TestEqual(
            FString::Printf(TEXT("Detection stores observed location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            DetectedLocation);

        Controller->ApplySightState(PlayerTarget.Get(), true, LastObservedLocation);
        TestEqual(
            FString::Printf(TEXT("Duplicate detection does not change target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestEqual(
            FString::Printf(TEXT("Visible update refreshes last seen location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);

        Controller->ApplySightState(UnrelatedTarget.Get(), false, FVector(9999.0, 9999.0, 9999.0));
        TestEqual(
            FString::Printf(TEXT("Unrelated loss does not clear target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestTrue(
            FString::Printf(TEXT("Unrelated loss preserves sight on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);
        TestEqual(
            FString::Printf(TEXT("Unrelated loss preserves memory on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);

        Controller->ApplySightState(PlayerTarget.Get(), false, LastObservedLocation);
        TestNull(
            FString::Printf(TEXT("Lost clears target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get());
        TestFalse(
            FString::Printf(TEXT("Lost clears flag on iteration %d"), Iteration + 1),
            Controller->bCanSeeTarget);
        TestEqual(
            FString::Printf(TEXT("Lost preserves the actual observed location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);

        Controller->ApplySightState(PlayerTarget.Get(), false, FVector(8888.0, 8888.0, 8888.0));
        TestNull(
            FString::Printf(TEXT("Duplicate loss remains stable on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get());
        TestEqual(
            FString::Printf(TEXT("Duplicate loss cannot move remembered location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);
    }

    return true;
}

#endif
