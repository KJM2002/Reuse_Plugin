#include "Components/JMHarpoonInteractableComponent.h"
#include "Components/JMHarpoonWireRouteComponent.h"
#include "Misc/AutomationTest.h"
#include "Types/JMHarpoonCableLengthModel.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonWireSurfaceOffsetTest,
    "JM.PhysicalGrabber.Wire.SurfaceOffset",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonWireSurfaceOffsetTest::RunTest(const FString& Parameters)
{
    const FVector Contact = UJMHarpoonWireRouteComponent::MakeSurfaceContactPoint(
        FVector::ZeroVector,
        FVector::UpVector,
        2.5f,
        0.75f);
    TestEqual(TEXT("Contact is displaced outside the surface"), Contact, FVector(0.0f, 0.0f, 3.25f));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonWireSagTest,
    "JM.PhysicalGrabber.Wire.SagCurve",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonWireSagTest::RunTest(const FString& Parameters)
{
    const FVector Start(0.0f, 0.0f, 0.0f);
    const FVector End(100.0f, 0.0f, 0.0f);
    TestEqual(
        TEXT("Sag preserves the start endpoint"),
        UJMHarpoonWireRouteComponent::EvaluateSagPoint(Start, End, 0.0f, 10.0f),
        Start);
    TestEqual(
        TEXT("Sag reaches its requested depth at the midpoint"),
        UJMHarpoonWireRouteComponent::EvaluateSagPoint(Start, End, 0.5f, 10.0f),
        FVector(50.0f, 0.0f, -10.0f));
    TestEqual(
        TEXT("Sag preserves the end endpoint"),
        UJMHarpoonWireRouteComponent::EvaluateSagPoint(Start, End, 1.0f, 10.0f),
        End);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonCableLengthModelTest,
    "JM.PhysicalGrabber.Cable.WinchLengthModel",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonCableLengthModelTest::RunTest(const FString& Parameters)
{
    FJMHarpoonCableLengthModel Model;
    Model.Reset(10.0f);
    const float MuzzleLength = Model.Update(0.0f, 1.0f / 60.0f, false, 10.0f, 1.01f, 0.5f, 8.0f, 1.0f, 24.0f);
    TestEqual(TEXT("Muzzle cable starts without a one-meter loose loop"), MuzzleLength, 10.0f);

    const float FiredLength = Model.Update(1000.0f, 1.0f / 60.0f, false, 10.0f, 1.01f, 2.5f, 8.0f, 1.0f, 24.0f);
    TestEqual(TEXT("Long-range slack is capped"), FiredLength, 1008.0f);

    const float EmbeddedCloserLength = Model.Update(700.0f, 1.0f / 60.0f, false, 10.0f, 1.01f, 2.5f, 8.0f, 1.0f, 24.0f);
    TestEqual(TEXT("Flying/embedded cable does not reel inward"), EmbeddedCloserLength, FiredLength);

    const float RetractingLength = Model.Update(700.0f, 1.0f / 60.0f, true, 10.0f, 1.01f, 2.5f, 8.0f, 1.0f, 24.0f);
    TestTrue(TEXT("Recall reels inward"), RetractingLength < FiredLength);
    TestTrue(TEXT("Recall never undercuts endpoint span"), RetractingLength >= 707.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonExtractThresholdTest,
    "JM.PhysicalGrabber.Interaction.ExtractThreshold",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonExtractThresholdTest::RunTest(const FString& Parameters)
{
    UJMHarpoonInteractableComponent* Target = NewObject<UJMHarpoonInteractableComponent>();
    Target->Profile.Reaction = EJMHarpoonReaction::Extract;
    Target->Profile.bCanExtract = true;
    Target->Profile.ReactionForce = 100.0f;
    Target->Profile.ReactionHoldTime = 0.3f;

    FJMHarpoonInteractionContext Context;
    Target->OnHarpoonEmbedded_Implementation(Context);
    Target->OnHarpoonPullStarted_Implementation(Context);

    FJMHarpoonPullUpdate Update;
    Update.DeltaTime = 0.1f;
    Update.AppliedForce = 150.0f;
    TestEqual(
        TEXT("First tension sample keeps pulling"),
        Target->OnHarpoonPullUpdated_Implementation(Context, Update),
        EJMHarpoonReactionDirective::Continue);
    TestEqual(
        TEXT("Second tension sample keeps pulling"),
        Target->OnHarpoonPullUpdated_Implementation(Context, Update),
        EJMHarpoonReactionDirective::Continue);
    TestEqual(
        TEXT("Sustained threshold completes and releases"),
        Target->OnHarpoonPullUpdated_Implementation(Context, Update),
        EJMHarpoonReactionDirective::ReleaseHarpoon);
    TestTrue(TEXT("Extraction is marked complete"), Target->HasCompletedReaction());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonFragileCargoTest,
    "JM.PhysicalGrabber.Interaction.FragileCargoBreaks",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonFragileCargoTest::RunTest(const FString& Parameters)
{
    UJMHarpoonInteractableComponent* Cargo = NewObject<UJMHarpoonInteractableComponent>();
    Cargo->Profile.FragileSafeForce = 100.0f;
    Cargo->Profile.FragileDamagePerSecond = 1.0f;

    FJMHarpoonInteractionContext Context;
    Cargo->OnHarpoonEmbedded_Implementation(Context);
    FJMHarpoonPullUpdate Update;
    Update.DeltaTime = 1.0f;
    Update.AppliedForce = 200.0f;

    TestEqual(
        TEXT("Broken cargo releases the harpoon"),
        Cargo->OnHarpoonPullUpdated_Implementation(Context, Update),
        EJMHarpoonReactionDirective::ReleaseHarpoon);
    TestEqual(TEXT("Condition reaches zero"), Cargo->GetCondition(), 0.0f);
    TestTrue(TEXT("Break is marked complete"), Cargo->HasCompletedReaction());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMHarpoonInteractionSessionResetTest,
    "JM.PhysicalGrabber.Interaction.SessionReset",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHarpoonInteractionSessionResetTest::RunTest(const FString& Parameters)
{
    UJMHarpoonInteractableComponent* Target = NewObject<UJMHarpoonInteractableComponent>();
    Target->Profile.Reaction = EJMHarpoonReaction::Break;
    Target->Profile.bCanBreak = true;
    Target->Profile.ReactionForce = 100.0f;
    Target->Profile.ReactionHoldTime = 0.3f;

    FJMHarpoonInteractionContext Context;
    FJMHarpoonPullUpdate Update;
    Update.DeltaTime = 0.2f;
    Update.AppliedForce = 120.0f;
    Target->OnHarpoonPullStarted_Implementation(Context);
    Target->OnHarpoonPullUpdated_Implementation(Context, Update);
    Target->OnHarpoonInteractionEnded_Implementation(Context, EJMHarpoonInteractionEndReason::Released);
    Target->OnHarpoonPullStarted_Implementation(Context);

    TestEqual(
        TEXT("A new pull does not inherit old sustained tension"),
        Target->OnHarpoonPullUpdated_Implementation(Context, Update),
        EJMHarpoonReactionDirective::Continue);
    TestFalse(TEXT("Reaction remains incomplete"), Target->HasCompletedReaction());
    return true;
}

#endif
