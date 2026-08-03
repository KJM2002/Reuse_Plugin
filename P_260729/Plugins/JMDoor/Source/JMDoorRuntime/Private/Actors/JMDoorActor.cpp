#include "Actors/JMDoorActor.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Door/JMDoorComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Movement/JMDoorMovementComponent.h"
#include "Movement/JMRotatingDoorMovementComponent.h"
#include "Movement/JMSlidingDoorMovementComponent.h"

AJMDoorActor::AJMDoorActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    FrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrameMesh"));
    FrameMesh->SetupAttachment(SceneRoot);

    MovementRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MovementRoot"));
    MovementRoot->SetupAttachment(SceneRoot);

    DoorLeafMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeafMesh"));
    DoorLeafMesh->SetupAttachment(MovementRoot);
    DoorLeafMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);

    LockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockMesh"));
    LockMesh->SetupAttachment(DoorLeafMesh);
    LockMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    DoorComponent = CreateDefaultSubobject<UJMDoorComponent>(TEXT("DoorComponent"));
}

void AJMDoorActor::PostActorCreated()
{
    Super::PostActorCreated();
    EnsurePersistentId();
}

void AJMDoorActor::PostLoad()
{
    Super::PostLoad();
    EnsurePersistentId();
}

FJMDoorResult AJMDoorActor::ExecuteDoorCommand_Implementation(EJMDoorCommand Command, const FJMDoorUseContext& Context)
{
    return DoorComponent
        ? DoorComponent->ExecuteCommand(Command, Context)
        : FJMDoorResult::Failure(EJMDoorResultCode::Disabled, NSLOCTEXT("JMDoor", "MissingDoorComponent", "The actor has no door component."));
}

bool AJMDoorActor::CanExecuteDoorCommand_Implementation(EJMDoorCommand Command, const FJMDoorUseContext& Context) const
{
    return DoorComponent && DoorComponent->CanExecuteCommand(Command, Context);
}

EJMDoorState AJMDoorActor::GetDoorState_Implementation() const
{
    return DoorComponent ? DoorComponent->GetState() : EJMDoorState::Broken;
}

FGuid AJMDoorActor::GetDoorPersistentId_Implementation() const
{
    return DoorComponent ? DoorComponent->PersistentId : FGuid();
}

FJMDoorSaveData AJMDoorActor::CaptureDoorSaveData_Implementation() const
{
    return DoorComponent ? DoorComponent->CaptureSaveData() : FJMDoorSaveData();
}

bool AJMDoorActor::RestoreDoorSaveData_Implementation(const FJMDoorSaveData& SaveData)
{
    return DoorComponent && DoorComponent->RestoreSaveData(SaveData);
}

void AJMDoorActor::ConfigureMovement(UJMDoorMovementComponent* InMovementComponent)
{
    if (InMovementComponent)
    {
        // A rotating door must move the hinge root so the leaf orbits the hinge.
        // Sliding doors translate the leaf directly.
        USceneComponent* MovingTarget = InMovementComponent->IsA<UJMRotatingDoorMovementComponent>()
            ? MovementRoot.Get()
            : DoorLeafMesh.Get();
        InMovementComponent->InitializeMovingComponent(MovingTarget);
        InMovementComponent->SetCollisionComponent(DoorLeafMesh);
        InMovementComponent->SetDirectionProbeComponent(DoorLeafMesh);
    }
    if (DoorComponent)
    {
        DoorComponent->MovementComponent = InMovementComponent;
    }
}

void AJMDoorActor::EnsurePersistentId()
{
    if (DoorComponent && !HasAnyFlags(RF_ClassDefaultObject | RF_ArchetypeObject) && !DoorComponent->PersistentId.IsValid())
    {
        DoorComponent->PersistentId = FGuid::NewGuid();
    }
}

AJMRotatingDoorActor::AJMRotatingDoorActor()
{
    RotatingMovement = CreateDefaultSubobject<UJMRotatingDoorMovementComponent>(TEXT("RotatingMovement"));
    ConfigureMovement(RotatingMovement);
}

AJMSlidingDoorActor::AJMSlidingDoorActor()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = false;
    SlidingMovement = CreateDefaultSubobject<UJMSlidingDoorMovementComponent>(TEXT("SlidingMovement"));
    ConfigureMovement(SlidingMovement);

    DoorLeafMeshB = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SlideDoorMeshB"));
    DoorLeafMeshB->SetupAttachment(MovementRoot);
    DoorLeafMeshB->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    SlidingMovement->InitializeDoorBComponent(DoorLeafMeshB, DoorLeafMeshB);
}

void AJMSlidingDoorActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
#if WITH_EDITOR
    SetActorTickEnabled(bPreviewOpenPositions);
#endif
}

void AJMSlidingDoorActor::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
#if WITH_EDITOR
    UWorld* World = GetWorld();
    if (!bPreviewOpenPositions || !World || World->WorldType != EWorldType::Editor || !SlidingMovement)
    {
        return;
    }

    auto DrawPanelPreview = [this, World](EJMSlideDoorPanel Panel, UPrimitiveComponent* Primitive, const FColor& Color)
    {
        if (!Primitive)
        {
            return;
        }
        const FTransform Closed = SlidingMovement->GetPanelCollisionWorldTransformAtFraction(Panel, 0.0f);
        const FTransform Open = SlidingMovement->GetPanelCollisionWorldTransformAtFraction(Panel, 1.0f);
        const FVector Extent = Primitive->Bounds.BoxExtent.ComponentMax(FVector(2.0f));
        DrawDebugDirectionalArrow(World, Closed.GetLocation(), Open.GetLocation(), 12.0f, Color, false, 0.05f, 0, 2.0f);
        DrawDebugBox(World, Open.GetLocation(), Extent, Open.GetRotation(), Color, false, 0.05f, 0, 1.5f);
    };

    DrawPanelPreview(EJMSlideDoorPanel::DoorA, DoorLeafMesh, FColor::Cyan);
    DrawPanelPreview(EJMSlideDoorPanel::DoorB, DoorLeafMeshB, FColor::Magenta);
#endif
}

FJMDoorResult AJMSlidingDoorActor::OpenSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context)
{
    return DoorComponent
        ? DoorComponent->OpenSlideDoor(Panel, Context)
        : FJMDoorResult::Failure(EJMDoorResultCode::Disabled, NSLOCTEXT("JMDoor", "MissingSlideDoorComponent", "The actor has no door component."));
}

FJMDoorResult AJMSlidingDoorActor::CloseSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context)
{
    return DoorComponent
        ? DoorComponent->CloseSlideDoor(Panel, Context)
        : FJMDoorResult::Failure(EJMDoorResultCode::Disabled, NSLOCTEXT("JMDoor", "MissingSlideDoorComponent", "The actor has no door component."));
}

EJMDoorState AJMSlidingDoorActor::GetSlideDoorPanelState(EJMSlideDoorPanel Panel) const
{
    return DoorComponent ? DoorComponent->GetSlideDoorPanelState(Panel) : EJMDoorState::Closed;
}
