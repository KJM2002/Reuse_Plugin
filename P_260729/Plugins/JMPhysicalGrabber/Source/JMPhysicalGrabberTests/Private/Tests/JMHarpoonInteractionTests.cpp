#include "Components/JMHarpoonInteractableComponent.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

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
