#include "Tests/JMDoorFunctionalTest.h"

#include "Actors/JMDoorActor.h"
#include "Components/StaticMeshComponent.h"
#include "Door/JMDoorComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "UObject/UObjectGlobals.h"

void AJMDoorFunctionalTest::StartTest()
{
    Super::StartTest();

    UWorld* World = GetWorld();
    if (!World)
    {
        FinishTest(EFunctionalTestResult::Failed, TEXT("No world was available."));
        return;
    }

    UClass* ExampleDoorClass = LoadClass<AJMRotatingDoorActor>(nullptr, TEXT("/JMDoor/Demo/Blueprints/BP_JMRotatingDoorExample.BP_JMRotatingDoorExample_C"));
    const AJMRotatingDoorActor* ExampleCDO = ExampleDoorClass ? Cast<AJMRotatingDoorActor>(ExampleDoorClass->GetDefaultObject()) : nullptr;
    const FTransform ExpectedClosedTransform = ExampleCDO && ExampleCDO->DoorLeafMesh
        ? ExampleCDO->DoorLeafMesh->GetRelativeTransform()
        : FTransform::Identity;

    SpawnedDoor = ExampleDoorClass
        ? World->SpawnActor<AJMRotatingDoorActor>(ExampleDoorClass, GetActorLocation() + FVector(200.0f, 0.0f, 0.0f), FRotator::ZeroRotator)
        : nullptr;
    if (!SpawnedDoor || !SpawnedDoor->DoorComponent)
    {
        FinishTest(EFunctionalTestResult::Failed, TEXT("Could not load and spawn the example door Blueprint."));
        return;
    }

    if (!SpawnedDoor->DoorLeafMesh->GetRelativeTransform().Equals(ExpectedClosedTransform, KINDA_SMALL_NUMBER))
    {
        FinishTest(EFunctionalTestResult::Failed, TEXT("The example door did not preserve its authored location, rotation and scale at BeginPlay."));
        return;
    }

    SpawnedDoor->DoorLeafMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    FJMDoorUseContext Context;
    Context.InteractionLocation = GetActorLocation();
    const FJMDoorResult DoorResult = SpawnedDoor->DoorComponent->OpenDoor(Context);
    if (!DoorResult.bSucceeded)
    {
        FinishTest(EFunctionalTestResult::Failed, FString::Printf(TEXT("Open failed: %s"), *DoorResult.Message.ToString()));
        return;
    }

    World->GetTimerManager().SetTimer(VerificationTimer, this, &AJMDoorFunctionalTest::VerifyDoorOpened, 1.25f, false);
}

void AJMDoorFunctionalTest::VerifyDoorOpened()
{
    if (SpawnedDoor && SpawnedDoor->DoorComponent && SpawnedDoor->DoorComponent->GetState() == EJMDoorState::Open && SpawnedDoor->DoorComponent->GetOpenFraction() > 0.99f)
    {
        FinishTest(EFunctionalTestResult::Succeeded, TEXT("The rotating door opened through its runtime state machine."));
    }
    else
    {
        FinishTest(EFunctionalTestResult::Failed, TEXT("The rotating door did not reach Open state."));
    }
}
