#include "Misc/AutomationTest.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideCharacterParticipantComponent.h"
#include "Components/JMHideInputRouterComponent.h"
#include "Components/JMHideInteractorComponent.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "Components/JMInteractionComponent.h"
#include "Editor.h"
#include "GameFramework/Character.h"
#include "JMHideReadyActors.h"
#include "Tests/AutomationEditorCommon.h"

namespace
{
    template <typename THideActor>
    bool RunEnterExitTraceFlow(FAutomationTestBase& Test, const FVector& PlayerStart,
        const FVector& InitialTraceDirection)
    {
        UWorld* World = GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
        if (!World)
        {
            Test.AddError(TEXT("Editor world is unavailable."));
            return false;
        }

        THideActor* HideActor = World->SpawnActor<THideActor>(FVector::ZeroVector, FRotator::ZeroRotator);
        ACharacter* Character = World->SpawnActor<ACharacter>(PlayerStart, FRotator::ZeroRotator);
        UJMInteractionComponent* Interaction = NewObject<UJMInteractionComponent>(
            Character, TEXT("JMInteraction_Test"));
        Character->AddInstanceComponent(Interaction);
        Interaction->RegisterComponent();
        Interaction->bCreatePromptWidget = false;
        Interaction->TraceMode = EJMInteractionTraceMode::Manual;

        HideActor->HideSpot->InstanceConfigOverride.bOverride = true;
        HideActor->HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.0f;
        HideActor->HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.0f;
        HideActor->HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.0f;
        if (UJMHideSimplePanelMechanismComponent* Panel =
            HideActor->FindComponentByClass<UJMHideSimplePanelMechanismComponent>())
        {
            Panel->Duration = 0.0f;
            Panel->Delay = 0.0f;
        }

        const bool bFoundEnter = Interaction->RefreshCurrentInteractableFromTrace(
            PlayerStart, InitialTraceDirection.GetSafeNormal());
        Test.TestTrue(TEXT("Existing JMInteraction trace finds the hide actor"), bFoundEnter);
        const FJMInteractionResult Enter = Interaction->TryBeginInteraction();
        Test.TestTrue(TEXT("Actual BP input entry point preserves normal interaction"), Enter.bSucceeded);
        Test.TestEqual(TEXT("Spot becomes occupied"), HideActor->HideSpot->GetSpotState(),
            EJMHideSpotState::Occupied);
        Test.TestNotNull(TEXT("Runtime interactor exists on the real participant"),
            Character->FindComponentByClass<UJMHideInteractorComponent>());
        Test.TestNotNull(TEXT("Runtime participant driver exists on the real participant"),
            Character->FindComponentByClass<UJMHideCharacterParticipantComponent>());
        Test.TestNotNull(TEXT("Runtime input router exists on the real participant"),
            Character->FindComponentByClass<UJMHideInputRouterComponent>());

        const bool bFoundExit = Interaction->RefreshCurrentInteractableFromTrace(
            FVector(10000, 10000, 10000), FVector::UpVector);
        Test.TestFalse(TEXT("Test deliberately removes the traced target"), bFoundExit);
        const FJMInteractionResult Exit = Interaction->TryBeginInteraction();
        Test.TestTrue(TEXT("Actual BP input entry point exits without a trace target"), Exit.bSucceeded);
        Test.TestEqual(TEXT("Spot returns available"), HideActor->HideSpot->GetSpotState(),
            EJMHideSpotState::Available);

        HideActor->Destroy();
        Character->Destroy();
        return !Test.HasAnyErrors();
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideLockerReadyInteractionTest,
    "JM.Hide.ProjectReady.LockerExistingInteractionEnterExit",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideLockerReadyInteractionTest::RunTest(const FString&)
{
    FAutomationEditorCommonUtils::CreateNewMap();
    const bool bFlowSucceeded = RunEnterExitTraceFlow<AJMHideLockerActor>(
        *this, FVector(0, 300, 95), FVector(0, -1, 0));

    const AJMHideLockerActor* Defaults = GetDefault<AJMHideLockerActor>();
    const FJMHidePanelPart& DoorPart = Defaults->PanelMechanism->Panels[0];
    TestTrue(TEXT("Door mechanism owns the explicit hinge, not the mesh"),
        DoorPart.Panel == Defaults->DoorPivot);
    TestEqual(TEXT("Locker uses RotationOnly motion"),
        DoorPart.MotionType, EJMHidePanelMotionType::RotationOnly);
    TestTrue(TEXT("Door mesh is attached under the explicit hinge"),
        Defaults->LockerDoor->GetAttachParent() == Defaults->DoorPivot);
    return bFlowSucceeded && !HasAnyErrors();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideLockerDoorPivotInvariantTest,
    "JM.Hide.Locker.DoorPivot.LocationInvariant",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideLockerDoorPivotInvariantTest::RunTest(const FString&)
{
    FAutomationEditorCommonUtils::CreateNewMap();
    UWorld* World = GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
    AJMHideLockerActor* Locker = World
        ? World->SpawnActor<AJMHideLockerActor>(FVector::ZeroVector, FRotator::ZeroRotator)
        : nullptr;
    TestNotNull(TEXT("Locker spawned"), Locker);
    if (!Locker)
    {
        return false;
    }

    Locker->PanelMechanism->Duration = 0.0f;
    const FVector PivotLocation = Locker->DoorPivot->GetRelativeLocation();
    const FVector PivotScale = Locker->DoorPivot->GetRelativeScale3D();
    const FTransform DoorTransform = Locker->LockerDoor->GetRelativeTransform();
    FJMHideOperationContext Context;
    const FGuid Session = FGuid::NewGuid();
    TestTrue(TEXT("Open operation starts"),
        Locker->PanelMechanism->StartOperation(
            Session, EJMHideOperation::PrepareEnter, Context));
    TestTrue(TEXT("DoorPivot location is invariant while open"),
        Locker->DoorPivot->GetRelativeLocation().Equals(PivotLocation));
    TestTrue(TEXT("DoorPivot scale is invariant while open"),
        Locker->DoorPivot->GetRelativeScale3D().Equals(PivotScale));
    TestTrue(TEXT("DoorMesh authored relative transform is invariant while open"),
        Locker->LockerDoor->GetRelativeTransform().Equals(DoorTransform));
    TestFalse(TEXT("Only DoorPivot rotation changes"),
        Locker->DoorPivot->GetRelativeRotation().IsNearlyZero());

    const FGuid CloseSession = FGuid::NewGuid();
    TestTrue(TEXT("Close operation starts"),
        Locker->PanelMechanism->StartOperation(
            CloseSession, EJMHideOperation::CompleteEnter, Context));
    TestTrue(TEXT("DoorPivot location remains invariant after close"),
        Locker->DoorPivot->GetRelativeLocation().Equals(PivotLocation));
    TestTrue(TEXT("DoorMesh remains invariant after close"),
        Locker->LockerDoor->GetRelativeTransform().Equals(DoorTransform));
    TestTrue(TEXT("DoorPivot returns to its exact closed rotation"),
        Locker->DoorPivot->GetRelativeRotation().IsNearlyZero());
    Locker->Destroy();
    return !HasAnyErrors();
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideBedReadyInteractionTest,
    "JM.Hide.ProjectReady.BedExistingInteractionEnterExit",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideBedReadyInteractionTest::RunTest(const FString&)
{
    FAutomationEditorCommonUtils::CreateNewMap();
    return RunEnterExitTraceFlow<AJMHideBedActor>(*this, FVector(300, 0, 95), FVector(-1, 0, 0));
}
