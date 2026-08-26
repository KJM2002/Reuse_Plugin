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

    Controller->ApplySightState(nullptr, true, FVector(1.0, 2.0, 3.0), FVector(4.0, 5.0, 6.0));
    TestNull(TEXT("Null detection is ignored"), Controller->TargetActor.Get());
    TestFalse(TEXT("Null detection does not enable sight"), Controller->bCanSeeTarget);

    for (int32 Iteration = 0; Iteration < 20; ++Iteration)
    {
        const FVector DetectedLocation(Iteration * 100.0, 25.0, 0.0);
        const FVector LastObservedLocation(Iteration * 100.0 + 50.0, 75.0, 0.0);
        const FVector DetectedVelocity(200.0 + Iteration, 100.0, 0.0);
        const FVector LastObservedVelocity(300.0 + Iteration, 0.0, 0.0);

        Controller->ApplySightState(PlayerTarget.Get(), true, DetectedLocation, DetectedVelocity);
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
        TestEqual(
            FString::Printf(TEXT("Detection stores visible velocity on iteration %d"), Iteration + 1),
            Controller->LastSeenVelocity,
            DetectedVelocity);

        Controller->ApplySightState(PlayerTarget.Get(), true, LastObservedLocation, LastObservedVelocity);
        TestEqual(
            FString::Printf(TEXT("Duplicate detection does not change target on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get(),
            PlayerTarget.Get());
        TestEqual(
            FString::Printf(TEXT("Visible update refreshes last seen location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);
        TestEqual(
            FString::Printf(TEXT("Visible update refreshes last seen velocity on iteration %d"), Iteration + 1),
            Controller->LastSeenVelocity,
            LastObservedVelocity);

        Controller->ApplySightState(
            UnrelatedTarget.Get(),
            false,
            FVector(9999.0, 9999.0, 9999.0),
            FVector(-9999.0, -9999.0, -9999.0));
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

        Controller->ApplySightState(
            PlayerTarget.Get(),
            false,
            LastObservedLocation,
            FVector(-9999.0, -9999.0, -9999.0));
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
        TestEqual(
            FString::Printf(TEXT("Lost preserves the last visible velocity on iteration %d"), Iteration + 1),
            Controller->LastSeenVelocity,
            LastObservedVelocity);
        TestTrue(
            FString::Printf(TEXT("Lost enables recent tracking on iteration %d"), Iteration + 1),
            Controller->bHasRecentTrackingMemory);

        const FVector PredictionOffset = Controller->EstimatedTrackingLocation - LastObservedLocation;
        TestTrue(
            FString::Printf(TEXT("Prediction follows the last visible direction on iteration %d"), Iteration + 1),
            FVector::DotProduct(PredictionOffset, LastObservedVelocity) > 0.0);
        TestTrue(
            FString::Printf(TEXT("Prediction distance is capped on iteration %d"), Iteration + 1),
            PredictionOffset.Size() <= Controller->MaximumPredictionDistance + UE_KINDA_SMALL_NUMBER);

        const FVector EstimatedBeforeDuplicateLoss = Controller->EstimatedTrackingLocation;
        Controller->ApplySightState(
            PlayerTarget.Get(),
            false,
            FVector(8888.0, 8888.0, 8888.0),
            FVector(-8888.0, -8888.0, -8888.0));
        TestNull(
            FString::Printf(TEXT("Duplicate loss remains stable on iteration %d"), Iteration + 1),
            Controller->TargetActor.Get());
        TestEqual(
            FString::Printf(TEXT("Duplicate loss cannot move remembered location on iteration %d"), Iteration + 1),
            Controller->LastSeenLocation,
            LastObservedLocation);
        TestEqual(
            FString::Printf(TEXT("Duplicate loss cannot change the cached prediction on iteration %d"), Iteration + 1),
            Controller->EstimatedTrackingLocation,
            EstimatedBeforeDuplicateLoss);
    }

    return true;
}

#endif
