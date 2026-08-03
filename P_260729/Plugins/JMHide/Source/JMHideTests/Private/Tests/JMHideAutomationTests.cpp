#include "Misc/AutomationTest.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideCharacterParticipantComponent.h"
#include "Components/JMHideInteractorComponent.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "GameFramework/Character.h"
#include "GameplayTagsManager.h"
#include "Tests/JMHideTestDoubles.h"
#include "UObject/StrongObjectPtr.h"

namespace
{
    struct FHideFixture
    {
        TStrongObjectPtr<ACharacter> Participant{NewObject<ACharacter>()};
        TStrongObjectPtr<AActor> SpotActor{NewObject<AActor>()};
        TStrongObjectPtr<UJMHideInteractorComponent> Interactor{
            NewObject<UJMHideInteractorComponent>(Participant.Get())};
        TStrongObjectPtr<UJMHideCharacterParticipantComponent> Driver{
            NewObject<UJMHideCharacterParticipantComponent>(Participant.Get())};
        TStrongObjectPtr<UJMHideSpotComponent> Spot{NewObject<UJMHideSpotComponent>(SpotActor.Get())};

        FHideFixture()
        {
            Participant->AddInstanceComponent(Interactor.Get());
            Participant->AddInstanceComponent(Driver.Get());
            SpotActor->AddInstanceComponent(Spot.Get());
            Spot->Archetype = EJMHideSpotArchetype::OpenSpace;
            Spot->InstanceConfigOverride.bOverride = true;
            Spot->InstanceConfigOverride.Values.EnterDuration = 0.0f;
            Spot->InstanceConfigOverride.Values.ExitDuration = 0.0f;
            Spot->InstanceConfigOverride.Values.CameraBlendDuration = 0.0f;

            AddAnchor(EJMHideAnchorRole::Entry, FVector(10, 0, 0));
            AddAnchor(EJMHideAnchorRole::Occupant, FVector(20, 0, 0));
            AddAnchor(EJMHideAnchorRole::Camera, FVector(20, 0, 60));
            AddAnchor(EJMHideAnchorRole::PrimaryExit, FVector(100, 0, 0));
        }

        void AddAnchor(EJMHideAnchorRole Role, const FVector& Location)
        {
            UJMHideAnchorComponent* Anchor = NewObject<UJMHideAnchorComponent>(SpotActor.Get());
            Anchor->Role = Role;
            Anchor->SetRelativeLocation(Location);
            SpotActor->AddInstanceComponent(Anchor);
        }
    };

    struct FAsyncHideFixture
    {
        TStrongObjectPtr<AActor> Participant{NewObject<AActor>()};
        TStrongObjectPtr<AActor> SpotActor{NewObject<AActor>()};
        TStrongObjectPtr<UJMHideInteractorComponent> Interactor{
            NewObject<UJMHideInteractorComponent>(Participant.Get())};
        TStrongObjectPtr<UJMHideTestDriverComponent> Driver{
            NewObject<UJMHideTestDriverComponent>(Participant.Get())};
        TStrongObjectPtr<UJMHideSpotComponent> Spot{NewObject<UJMHideSpotComponent>(SpotActor.Get())};
        TStrongObjectPtr<UJMHideTestMechanismComponent> Mechanism{
            NewObject<UJMHideTestMechanismComponent>(SpotActor.Get())};

        FAsyncHideFixture()
        {
            Participant->AddInstanceComponent(Interactor.Get());
            Participant->AddInstanceComponent(Driver.Get());
            SpotActor->AddInstanceComponent(Spot.Get());
            SpotActor->AddInstanceComponent(Mechanism.Get());
            Spot->Archetype = EJMHideSpotArchetype::Enclosed;
            AddAnchor(EJMHideAnchorRole::Entry, FVector(10, 0, 0));
            AddAnchor(EJMHideAnchorRole::Occupant, FVector(20, 0, 0));
            AddAnchor(EJMHideAnchorRole::Camera, FVector(20, 0, 60));
            AddAnchor(EJMHideAnchorRole::PrimaryExit, FVector(100, 0, 0));
        }

        void AddAnchor(EJMHideAnchorRole Role, const FVector& Location)
        {
            UJMHideAnchorComponent* Anchor = NewObject<UJMHideAnchorComponent>(SpotActor.Get());
            Anchor->Role = Role;
            Anchor->SetRelativeLocation(Location);
            SpotActor->AddInstanceComponent(Anchor);
        }
    };
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideSessionAuthorityTest, "JM.Hide.Session.Authority",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideSessionAuthorityTest::RunTest(const FString&)
{
    FHideFixture F;
    TestTrue(TEXT("Enter command accepted"), F.Interactor->TryEnterHideSpot(F.Spot.Get()).bSucceeded);
    TestEqual(TEXT("Interactor session owns Hidden phase"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Hidden);
    TestEqual(TEXT("Spot only reports occupancy"), F.Spot->GetSpotState(), EJMHideSpotState::Occupied);
    const FJMHideResult ForceResult = F.Interactor->ForceExit(true);
    TestTrue(TEXT("Force exit succeeds without a world collision query"), ForceResult.bSucceeded);
    TestEqual(TEXT("Session completes"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Completed);
    TestEqual(TEXT("Spot returns available"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideUnsupportedDriverTest, "JM.Hide.Driver.Unsupported",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideUnsupportedDriverTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Actor(NewObject<AActor>());
    TStrongObjectPtr<UJMHideCharacterParticipantComponent> Driver(NewObject<UJMHideCharacterParticipantComponent>(Actor.Get()));
    TestFalse(TEXT("Default driver rejects non-character"), Driver->SupportsParticipant(Actor.Get()));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideMechanismNoneTest, "JM.Hide.Mechanism.None",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideMechanismNoneTest::RunTest(const FString&)
{
    FHideFixture F;
    TestTrue(TEXT("Open space enters without mechanism"), F.Interactor->TryEnterHideSpot(F.Spot.Get()).bSucceeded);
    TestTrue(TEXT("Open space reaches hidden"), F.Interactor->IsHidden());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideMultiPanelTest, "JM.Hide.Mechanism.MultiPanel",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideMultiPanelTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<USceneComponent> Root(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> A(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> B(NewObject<USceneComponent>(Owner.Get()));
    A->SetupAttachment(Root.Get());
    B->SetupAttachment(Root.Get());
    TStrongObjectPtr<UJMHideSimplePanelMechanismComponent> Mechanism(
        NewObject<UJMHideSimplePanelMechanismComponent>(Owner.Get()));
    FJMHidePanelPart PartA;
    PartA.Panel = A.Get();
    PartA.OpenRelativeTransform.SetLocation(FVector(0, 50, 0));
    FJMHidePanelPart PartB;
    PartB.Panel = B.Get();
    PartB.OpenRelativeTransform.SetLocation(FVector(0, -50, 0));
    Mechanism->Panels = {PartA, PartB};
    TArray<FText> Errors;
    TestTrue(TEXT("Panel count is data-driven"), Mechanism->ValidateConfiguration(Errors));
    TArray<USceneComponent*> Owned;
    Mechanism->GetOwnedSceneComponents(Owned);
    TestEqual(TEXT("Both panels are owned"), Owned.Num(), 2);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCleanupIdempotentTest, "JM.Hide.Cleanup.Idempotent",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCleanupIdempotentTest::RunTest(const FString&)
{
    FHideFixture F;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    F.Interactor->ForceExit(true);
    TestFalse(TEXT("No active session after cleanup"), F.Interactor->HasActiveSession());
    TestFalse(TEXT("Second cancel safely fails"), F.Interactor->CancelCurrentTransition().bSucceeded);
    TestEqual(TEXT("Spot remains available"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCancelHiddenTest, "JM.Hide.Cancel.HiddenStable",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCancelHiddenTest::RunTest(const FString&)
{
    FHideFixture F;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestFalse(TEXT("Stable Hidden is not treated as transition cancel"), F.Interactor->CancelCurrentTransition().bSucceeded);
    TestTrue(TEXT("Hidden remains stable"), F.Interactor->IsHidden());
    TestEqual(TEXT("Occupancy remains"), F.Spot->GetSpotState(), EJMHideSpotState::Occupied);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideExitBlockedTest, "JM.Hide.Exit.AllPointsBlocked",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideExitBlockedTest::RunTest(const FString&)
{
    FHideFixture F;
    F.Spot->InstanceConfigOverride.Values.bForceExitIgnoresCollision = false;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    const FJMHideResult Exit = F.Interactor->TryExitCurrentHideSpot();
    TestFalse(TEXT("No world means default driver cannot prove exit fit"), Exit.bSucceeded);
    TestEqual(TEXT("Failure is ExitBlocked"), Exit.Code, EJMHideFailureCode::ExitBlocked);
    TestTrue(TEXT("Player stays hidden"), F.Interactor->IsHidden());
    TestEqual(TEXT("Occupancy is retained"), F.Spot->GetSpotState(), EJMHideSpotState::Occupied);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideExitSafetyFallbackTest,
    "JM.Hide.Exit.ConfiguredSafetyFallback",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideExitSafetyFallbackTest::RunTest(const FString&)
{
    FHideFixture F;
    F.Spot->InstanceConfigOverride.Values.bForceExitIgnoresCollision = true;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    const FJMHideResult Exit = F.Interactor->TryExitCurrentHideSpot();
    TestTrue(TEXT("Configured fallback prevents a permanently trapped player"), Exit.bSucceeded);
    TestFalse(TEXT("Fallback completes the hide session"), F.Interactor->HasActiveSession());
    TestEqual(TEXT("Fallback releases occupancy"),
        F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideConfigSnapshotTest, "JM.Hide.Session.ConfigSnapshot",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideConfigSnapshotTest::RunTest(const FString&)
{
    FHideFixture F;
    F.Spot->InstanceConfigOverride.Values.ExitPrompt = FText::FromString(TEXT("First"));
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    F.Spot->InstanceConfigOverride.Values.ExitPrompt = FText::FromString(TEXT("Second"));
    TestEqual(TEXT("Active session keeps resolved prompt"),
        F.Interactor->GetActiveSession().ResolvedConfig.ExitPrompt.ToString(), FString(TEXT("First")));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideFailAfterReservationTest, "JM.Hide.Enter.FailAfterReservation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideFailAfterReservationTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Driver->bFailCapture = true;
    TestFalse(TEXT("Capture failure rejects enter"), F.Interactor->TryEnterHideSpot(F.Spot.Get()).bSucceeded);
    TestEqual(TEXT("Reservation rolls back"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    TestFalse(TEXT("Failed session is inactive"), F.Interactor->HasActiveSession());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideFailDuringMechanismTest, "JM.Hide.Enter.FailDuringMechanism",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideFailDuringMechanismTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Mechanism->FailOperation = EJMHideOperation::PrepareEnter;
    TestTrue(TEXT("Command is accepted before async failure"), F.Interactor->TryEnterHideSpot(F.Spot.Get()).bSucceeded);
    TestEqual(TEXT("Session fails"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Failed);
    TestEqual(TEXT("Spot is released"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    TestEqual(TEXT("Mechanism restore called"), F.Mechanism->RestoreCount, 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideFailDuringParticipantTest, "JM.Hide.Enter.FailDuringParticipantTransition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideFailDuringParticipantTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Driver->FailOperation = EJMHideOperation::Enter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestEqual(TEXT("Participant failure fails session"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Failed);
    TestEqual(TEXT("Participant restore called"), F.Driver->RestoreCount, 1);
    TestEqual(TEXT("Reservation released"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCancelOpeningTest, "JM.Hide.Cancel.WhileOpening",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCancelOpeningTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Mechanism->HoldOperation = EJMHideOperation::PrepareEnter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestEqual(TEXT("Opening is pending"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Opening);
    TestTrue(TEXT("Cancel succeeds"), F.Interactor->CancelCurrentTransition().bSucceeded);
    TestEqual(TEXT("Cancelled session"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Cancelled);
    TestEqual(TEXT("Spot released"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCancelEnteringTest, "JM.Hide.Cancel.WhileEntering",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCancelEnteringTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Driver->HoldOperation = EJMHideOperation::Enter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestEqual(TEXT("Entering is pending"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Entering);
    F.Interactor->CancelCurrentTransition();
    TestEqual(TEXT("Entry cancellation restores participant"), F.Driver->RestoreCount, 1);
    TestEqual(TEXT("Spot released"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCancelClosingTest, "JM.Hide.Cancel.WhileClosing",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCancelClosingTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Mechanism->HoldOperation = EJMHideOperation::CompleteEnter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestEqual(TEXT("Closing-after-enter is pending"), F.Interactor->GetCurrentPhase(), EJMHidePhase::ClosingAfterEnter);
    F.Interactor->CancelCurrentTransition();
    TestEqual(TEXT("Cancel returns before-hide state"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Cancelled);
    TestEqual(TEXT("Spot released"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideExitMechanismFailureTest, "JM.Hide.Exit.FailDuringMechanism",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideExitMechanismFailureTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestTrue(TEXT("Entered hidden"), F.Interactor->IsHidden());
    F.Mechanism->FailOperation = EJMHideOperation::PrepareExit;
    TestTrue(TEXT("Exit command accepted"), F.Interactor->TryExitCurrentHideSpot().bSucceeded);
    TestTrue(TEXT("Failure rolls back to Hidden"), F.Interactor->IsHidden());
    TestEqual(TEXT("Occupancy retained"), F.Spot->GetSpotState(), EJMHideSpotState::Occupied);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideOnePanelTest, "JM.Hide.Mechanism.OnePanel",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideOnePanelTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<USceneComponent> Root(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> Panel(NewObject<USceneComponent>(Owner.Get()));
    Panel->SetupAttachment(Root.Get());
    TStrongObjectPtr<UJMHideSimplePanelMechanismComponent> Mechanism(
        NewObject<UJMHideSimplePanelMechanismComponent>(Owner.Get()));
    FJMHidePanelPart Part;
    Part.Panel = Panel.Get();
    Part.OpenRelativeTransform.SetRotation(FQuat(FRotator(0, 90, 0)));
    Mechanism->Panels.Add(Part);
    TArray<FText> Errors;
    TestTrue(TEXT("One panel validates without enum branching"), Mechanism->ValidateConfiguration(Errors));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideRelativeTransformTest, "JM.Hide.Mechanism.RelativeTransform",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideRelativeTransformTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<USceneComponent> Root(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> Panel(NewObject<USceneComponent>(Owner.Get()));
    Panel->SetupAttachment(Root.Get());
    TStrongObjectPtr<UJMHideSimplePanelMechanismComponent> Mechanism(
        NewObject<UJMHideSimplePanelMechanismComponent>(Owner.Get()));
    FJMHidePanelPart Part;
    Part.Panel = Panel.Get();
    Part.ClosedRelativeTransform.SetLocation(FVector(1, 2, 3));
    Part.OpenRelativeTransform.SetLocation(FVector(10, 20, 30));
    Mechanism->Panels.Add(Part);
    Mechanism->Duration = 0.0f;
    Mechanism->StartOperation(FGuid::NewGuid(), EJMHideOperation::PrepareEnter, FJMHideOperationContext());
    TestTrue(TEXT("Authored final relative transform is applied exactly"),
        Panel->GetRelativeTransform().Equals(Part.OpenRelativeTransform));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideStaleMechanismTest, "JM.Hide.StaleMechanismCallback",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideStaleMechanismTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Mechanism->HoldOperation = EJMHideOperation::PrepareEnter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    const FGuid OldSession = F.Interactor->GetCurrentSessionId();
    F.Interactor->CancelCurrentTransition();
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    const FGuid NewSession = F.Interactor->GetCurrentSessionId();
    F.Mechanism->Emit(OldSession, EJMHideOperation::PrepareEnter, true);
    TestNotEqual(TEXT("New session has a different id"), OldSession, NewSession);
    TestEqual(TEXT("Stale mechanism callback cannot advance new session"),
        F.Interactor->GetCurrentPhase(), EJMHidePhase::Opening);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideStaleParticipantTest, "JM.Hide.StaleParticipantCallback",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideStaleParticipantTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Driver->HoldOperation = EJMHideOperation::Enter;
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    const FGuid OldSession = F.Interactor->GetCurrentSessionId();
    F.Interactor->CancelCurrentTransition();
    F.Interactor->TryEnterHideSpot(F.Spot.Get());
    F.Driver->Emit(OldSession, EJMHideOperation::Enter, true);
    TestEqual(TEXT("Stale participant callback cannot advance new session"),
        F.Interactor->GetCurrentPhase(), EJMHidePhase::Entering);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideActorMovedTest, "JM.Hide.ActorMovedAfterPlacement",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideActorMovedTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<USceneComponent> Root(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> Panel(NewObject<USceneComponent>(Owner.Get()));
    Panel->SetupAttachment(Root.Get());
    Root->SetWorldTransform(FTransform(FRotator(0, 45, 0), FVector(1000, 500, 0)));
    TStrongObjectPtr<UJMHideSimplePanelMechanismComponent> Mechanism(
        NewObject<UJMHideSimplePanelMechanismComponent>(Owner.Get()));
    FJMHidePanelPart Part;
    Part.Panel = Panel.Get();
    Part.OpenRelativeTransform.SetLocation(FVector(0, 40, 0));
    Mechanism->Panels.Add(Part);
    Mechanism->Duration = 0.0f;
    Mechanism->StartOperation(FGuid::NewGuid(), EJMHideOperation::PrepareEnter, FJMHideOperationContext());
    TestTrue(TEXT("Moving the actor does not change authored panel-relative pose"),
        Panel->GetRelativeTransform().Equals(Part.OpenRelativeTransform));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideCommandAcceptedTest,
    "JM.Hide.Interaction.CommandAcceptedVsHiddenCompleted",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideCommandAcceptedTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    F.Mechanism->HoldOperation = EJMHideOperation::PrepareEnter;
    const FJMHideResult Accepted = F.Interactor->TryEnterHideSpot(F.Spot.Get());
    TestTrue(TEXT("Command is accepted"), Accepted.bSucceeded);
    TestFalse(TEXT("Accepted does not mean Hidden completed"), F.Interactor->IsHidden());
    TestEqual(TEXT("Session remains in asynchronous Opening"), F.Interactor->GetCurrentPhase(), EJMHidePhase::Opening);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideRestoreOwnedStateTest, "JM.Hide.Driver.RestoreOnlyOwnedState",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideRestoreOwnedStateTest::RunTest(const FString&)
{
    TStrongObjectPtr<ACharacter> Character(NewObject<ACharacter>());
    TStrongObjectPtr<UJMHideCharacterParticipantComponent> Driver(
        NewObject<UJMHideCharacterParticipantComponent>(Character.Get()));
    FJMHideParticipantSnapshot Snapshot;
    Driver->CaptureState(Snapshot);
    FJMHideOperationContext Context;
    Context.Config.bUseEntryAnchor = false;
    Context.Config.bDisableCollision = false;
    Driver->PrepareForHide(FGuid::NewGuid(), Context, Snapshot);
    Character->GetCharacterMovement()->SetMovementMode(MOVE_Falling);
    Driver->RestoreState(FGuid::NewGuid(), Snapshot);
    TestEqual(TEXT("External movement change is not overwritten"),
        Character->GetCharacterMovement()->MovementMode, MOVE_Falling);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideStressTest, "JM.Hide.Stress.RepeatFlow",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideStressTest::RunTest(const FString&)
{
    FAsyncHideFixture F;
    for (int32 Index = 0; Index < 4; ++Index)
    {
        TestTrue(TEXT("Enter succeeds"), F.Interactor->TryEnterHideSpot(F.Spot.Get()).bSucceeded);
        TestTrue(TEXT("Force exit succeeds"), F.Interactor->ForceExit(true).bSucceeded);
        TestEqual(TEXT("Spot available after cycle"), F.Spot->GetSpotState(), EJMHideSpotState::Available);
        TestFalse(TEXT("No active session after cycle"), F.Interactor->HasActiveSession());
    }
    return true;
}
