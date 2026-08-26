#include "AI/SimpleEnemyAIController.h"

#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "Misc/AutomationTest.h"
#include "UObject/StrongObjectPtr.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMSimpleEnemyLiveGraceStateTest,
    "JM.MonsterFramework.Phase4_6.LiveGraceState",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMSimpleEnemyLiveGraceStateTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<ASimpleEnemyAIController> Controller(NewObject<ASimpleEnemyAIController>());
    TStrongObjectPtr<AActor> PlayerTarget(NewObject<AActor>());
    USceneComponent* PlayerRoot = NewObject<USceneComponent>(PlayerTarget.Get());
    PlayerTarget->SetRootComponent(PlayerRoot);

    const FVector VisibleLocation(100.0, 0.0, 0.0);
    const FVector SightLossLocation(200.0, 0.0, 0.0);
    const FVector GraceLocation(200.0, 300.0, 0.0);
    const FVector PostExpiryLocation(-500.0, 800.0, 0.0);

    Controller->ApplySightState(PlayerTarget.Get(), true, VisibleLocation, FVector(300.0, 0.0, 0.0));
    Controller->ApplySightState(PlayerTarget.Get(), false, SightLossLocation, FVector::ZeroVector);

    TestNull(TEXT("Predictive TargetActor still clears on sight loss"), Controller->EnemyMemory.TargetActor.Get());
    TestFalse(TEXT("Sight flag clears on loss"), Controller->EnemyMemory.bCanSeeTarget);
    TestTrue(TEXT("Live Grace starts on loss"), Controller->EnemyMemory.bHasLiveGraceTracking);
    TestEqual(TEXT("Live Grace retains only its weak target"), Controller->EnemyMemory.LiveGraceTargetActor.Get(), PlayerTarget.Get());

    PlayerRoot->SetWorldLocation(GraceLocation);
    TestTrue(TEXT("Live Grace may sample the hidden target while valid"), Controller->UpdateLiveGraceLastKnownLocation());
    TestEqual(TEXT("Grace sampling refreshes the investigate location"), Controller->EnemyMemory.LastSeenLocation, GraceLocation);

    Controller->EndLiveGraceTracking();
    PlayerRoot->SetWorldLocation(PostExpiryLocation);
    TestFalse(TEXT("Expired Live Grace cannot sample the target"), Controller->UpdateLiveGraceLastKnownLocation());
    TestEqual(TEXT("Post-expiry movement cannot change memory"), Controller->EnemyMemory.LastSeenLocation, GraceLocation);
    TestFalse(TEXT("Expiry consumes the Grace flag"), Controller->EnemyMemory.bHasLiveGraceTracking);
    TestFalse(TEXT("Expiry releases the weak target"), Controller->EnemyMemory.LiveGraceTargetActor.IsValid());

    Controller->ApplySightState(PlayerTarget.Get(), true, PostExpiryLocation, FVector(0.0, 300.0, 0.0));
    TestFalse(TEXT("Reacquisition leaves old Grace inactive"), Controller->EnemyMemory.bHasLiveGraceTracking);
    Controller->ApplySightState(PlayerTarget.Get(), false, PostExpiryLocation, FVector::ZeroVector);
    TestTrue(TEXT("A second loss starts a fresh Grace event"), Controller->EnemyMemory.bHasLiveGraceTracking);
    TestEqual(TEXT("A second loss retains the target again"), Controller->EnemyMemory.LiveGraceTargetActor.Get(), PlayerTarget.Get());

    return true;
}

#endif
