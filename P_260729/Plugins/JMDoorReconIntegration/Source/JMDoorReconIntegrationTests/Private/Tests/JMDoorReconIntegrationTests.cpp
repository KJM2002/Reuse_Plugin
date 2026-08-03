#include "Misc/AutomationTest.h"

#include "Actors/JMDoorActor.h"
#include "Components/JMDoorReconTargetAdapterComponent.h"
#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Data/JMReconDefinition.h"
#include "Door/JMDoorComponent.h"
#include "Movement/JMDoorMovementComponent.h"
#include "Settings/JMDoorReconIntegrationSettings.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMDoorReconIntegrationDefaultsTest,
    "JM.DoorRecon.Settings.Defaults",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDoorReconIntegrationDefaultsTest::RunTest(const FString& Parameters)
{
    const UJMDoorReconIntegrationSettings* Settings =
        GetDefault<UJMDoorReconIntegrationSettings>();
    TestTrue(TEXT("Door adapter auto-add is enabled"), Settings->bAutoAddDoorAdapter);
    TestTrue(TEXT("Door opens over time"), Settings->OpenBlendDuration > 0.0f);
    TestTrue(TEXT("Door restores over time"), Settings->RestoreBlendDuration > 0.0f);
    return true;
}

namespace
{
    template<typename TDoorActor>
    void RunTemporaryPoseTest(FAutomationTestBase& Test)
    {
        UJMDoorReconIntegrationSettings* Settings =
            GetMutableDefault<UJMDoorReconIntegrationSettings>();
        const float SavedOpenDuration = Settings->OpenBlendDuration;
        const float SavedRestoreDuration = Settings->RestoreBlendDuration;
        Settings->OpenBlendDuration = 0.0f;
        Settings->RestoreBlendDuration = 0.0f;

        TStrongObjectPtr<TDoorActor> Door(NewObject<TDoorActor>());
        TStrongObjectPtr<UJMReconTargetComponent> Target(
            NewObject<UJMReconTargetComponent>(Door.Get()));
        TStrongObjectPtr<UJMDoorReconTargetAdapterComponent> Adapter(
            NewObject<UJMDoorReconTargetAdapterComponent>(Door.Get()));
        TStrongObjectPtr<UJMReconDefinition> Definition(NewObject<UJMReconDefinition>());
        Door->AddInstanceComponent(Target.Get());
        Door->AddInstanceComponent(Adapter.Get());
        Target->ReconDefinition = Definition.Get();
        Target->MaximumStartDistance = 0.0f;
        Definition->InitialObservationMode = EJMReconInitialObservationMode::Peek;
        Definition->EnteringDuration = 0.0f;
        Definition->ExitingDuration = 0.0f;
        Definition->PeekOpenFraction = 0.1f;

        TStrongObjectPtr<AActor> Player(NewObject<AActor>());
        TStrongObjectPtr<UJMReconInteractorComponent> Interactor(
            NewObject<UJMReconInteractorComponent>(Player.Get()));
        Player->AddInstanceComponent(Interactor.Get());

        USceneComponent* MovingComponent =
            Door->DoorComponent->MovementComponent->GetMovingComponent();
        MovingComponent->AddLocalOffset(FVector(0.0f, 2.0f, 0.0f));
        const FTransform Original = MovingComponent->GetRelativeTransform();
        const FJMReconRequestResult Started = Interactor->TryStartRecon(Target.Get());
        Test.TestTrue(TEXT("Component adapter accepts direct Peek session"), Started.bSucceeded);
        Test.TestEqual(TEXT("R-style entry reaches Peeking directly"),
            Interactor->GetCurrentState(), EJMReconState::Peeking);
        Test.TestFalse(TEXT("Door receives a temporary visual pose"),
            MovingComponent->GetRelativeTransform().Equals(Original));

        Test.TestTrue(TEXT("Session cancellation succeeds"), Interactor->CancelRecon().bSucceeded);
        Test.TestTrue(TEXT("Door pose is restored exactly"),
            MovingComponent->GetRelativeTransform().Equals(Original));

        Settings->OpenBlendDuration = SavedOpenDuration;
        Settings->RestoreBlendDuration = SavedRestoreDuration;
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMDoorReconRotatingPoseTest,
    "JM.DoorRecon.Runtime.RotatingDoorTemporaryPose",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDoorReconRotatingPoseTest::RunTest(const FString& Parameters)
{
    RunTemporaryPoseTest<AJMRotatingDoorActor>(*this);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMDoorReconSlidingPoseTest,
    "JM.DoorRecon.Runtime.SlidingDoorTemporaryPose",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDoorReconSlidingPoseTest::RunTest(const FString& Parameters)
{
    RunTemporaryPoseTest<AJMSlidingDoorActor>(*this);
    return true;
}
