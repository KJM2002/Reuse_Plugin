#include "Misc/AutomationTest.h"

#include "Components/JMHideDoorMechanismComponent.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"
#include "Components/SceneComponent.h"
#include "Door/JMDoorComponent.h"
#include "Editor.h"
#include "Movement/JMRotatingDoorMovementComponent.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideDoorNoDoubleOwnerTest,
    "JM.Hide.DoorIntegration.NoDoubleTransformOwner",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideDoorNoDoubleOwnerTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<USceneComponent> Root(NewObject<USceneComponent>(Owner.Get()));
    TStrongObjectPtr<USceneComponent> Moving(NewObject<USceneComponent>(Owner.Get()));
    Moving->SetupAttachment(Root.Get());
    TStrongObjectPtr<UJMDoorComponent> Door(NewObject<UJMDoorComponent>(Owner.Get()));
    TStrongObjectPtr<UJMRotatingDoorMovementComponent> Movement(
        NewObject<UJMRotatingDoorMovementComponent>(Owner.Get()));
    Movement->InitializeMovingComponent(Moving.Get());
    Door->SetMovementComponent(Movement.Get());
    TStrongObjectPtr<UJMHideDoorMechanismComponent> Adapter(
        NewObject<UJMHideDoorMechanismComponent>(Owner.Get()));
    TStrongObjectPtr<UJMHideSimplePanelMechanismComponent> Simple(
        NewObject<UJMHideSimplePanelMechanismComponent>(Owner.Get()));
    FJMHidePanelPart Part;
    Part.Panel = Moving.Get();
    Part.OpenRelativeTransform.SetRotation(FQuat(FRotator(0, 90, 0)));
    Simple->Panels.Add(Part);

    TArray<USceneComponent*> DoorOwned;
    TArray<USceneComponent*> SimpleOwned;
    Adapter->GetOwnedSceneComponents(DoorOwned);
    Simple->GetOwnedSceneComponents(SimpleOwned);
    TestTrue(TEXT("Integration exposes JMDoor's transform ownership"),
        DoorOwned.Contains(Moving.Get()));
    TestTrue(TEXT("Validation can detect the same SimplePanel target"),
        SimpleOwned.Contains(Moving.Get()) && DoorOwned.Contains(Moving.Get()));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideDoorOpenFailureTest,
    "JM.Hide.DoorIntegration.OpenFailure",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideDoorOpenFailureTest::RunTest(const FString&)
{
    TStrongObjectPtr<AActor> Owner(NewObject<AActor>());
    TStrongObjectPtr<UJMHideDoorMechanismComponent> Adapter(
        NewObject<UJMHideDoorMechanismComponent>(Owner.Get()));
    EJMHideFailureCode Failure = EJMHideFailureCode::None;
    TestFalse(TEXT("Missing JMDoor is rejected"),
        Adapter->CanStartOperation(EJMHideOperation::PrepareEnter, FJMHideOperationContext(), Failure));
    TestEqual(TEXT("Failure identifies invalid mechanism"), Failure, EJMHideFailureCode::InvalidMechanism);
    TestFalse(TEXT("Operation cannot start"), Adapter->StartOperation(
        FGuid::NewGuid(), EJMHideOperation::PrepareEnter, FJMHideOperationContext()));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideDoorDestroyedTest,
    "JM.Hide.DoorIntegration.DestroyedDuringTransition",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMHideDoorDestroyedTest::RunTest(const FString&)
{
    UWorld* World = GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
    TestNotNull(TEXT("Editor world is available"), World);
    if (!World)
    {
        return false;
    }
    AActor* Owner = World->SpawnActor<AActor>();
    USceneComponent* Root = NewObject<USceneComponent>(Owner);
    USceneComponent* Moving = NewObject<USceneComponent>(Owner);
    Owner->SetRootComponent(Root);
    Moving->SetupAttachment(Root);
    UJMDoorComponent* Door = NewObject<UJMDoorComponent>(Owner);
    UJMRotatingDoorMovementComponent* Movement = NewObject<UJMRotatingDoorMovementComponent>(Owner);
    UJMHideDoorMechanismComponent* Adapter = NewObject<UJMHideDoorMechanismComponent>(Owner);
    Owner->AddInstanceComponent(Root);
    Owner->AddInstanceComponent(Moving);
    Owner->AddInstanceComponent(Door);
    Owner->AddInstanceComponent(Movement);
    Owner->AddInstanceComponent(Adapter);
    Root->RegisterComponent();
    Moving->RegisterComponent();
    Door->RegisterComponent();
    Movement->RegisterComponent();
    Adapter->RegisterComponent();
    Movement->InitializeMovingComponent(Moving);
    Door->SetMovementComponent(Movement);
    Door->BeginPlay();
    Adapter->BeginPlay();

    int32 CompletionCount = 0;
    EJMHideFailureCode CompletionFailure = EJMHideFailureCode::None;
    Adapter->OnOperationCompleted.AddLambda(
        [&CompletionCount, &CompletionFailure](const FJMHideOperationCompletion& Completion)
        {
            ++CompletionCount;
            CompletionFailure = Completion.FailureCode;
        });
    const bool bStarted = Adapter->StartOperation(
        FGuid::NewGuid(), EJMHideOperation::PrepareEnter, FJMHideOperationContext());
    TestTrue(TEXT("Door transition starts"), bStarted);
    Adapter->EndPlay(EEndPlayReason::Destroyed);
    TestEqual(TEXT("Destruction completes pending operation once"), CompletionCount, 1);
    TestEqual(TEXT("Destruction reports target loss"), CompletionFailure, EJMHideFailureCode::TargetDestroyed);
    Owner->Destroy();
    return true;
}
