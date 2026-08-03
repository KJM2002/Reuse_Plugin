#include "JMHideReadyActors.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideInteractableAdapterComponent.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "GameplayTagsManager.h"
#include "UObject/ConstructorHelpers.h"

namespace
{
    UJMHideAnchorComponent* CreateAnchor(AActor* Owner, USceneComponent* Parent, const TCHAR* Name,
        EJMHideAnchorRole Role, const FVector& Location, const FRotator& Rotation)
    {
        UJMHideAnchorComponent* Anchor = Owner->CreateDefaultSubobject<UJMHideAnchorComponent>(Name);
        Anchor->SetupAttachment(Parent);
        Anchor->Role = Role;
        Anchor->SetRelativeLocationAndRotation(Location, Rotation);
        return Anchor;
    }

    void ConfigureInteractionMesh(UStaticMeshComponent* Mesh)
    {
        Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    }

}

AJMHideLockerActor::AJMHideLockerActor()
{
    PrimaryActorTick.bCanEverTick = false;
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    LockerBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockerBody"));
    LockerBody->SetupAttachment(SceneRoot);
    DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
    DoorPivot->SetupAttachment(SceneRoot);
    LockerDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockerDoor"));
    LockerDoor->SetupAttachment(DoorPivot);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMesh(
        TEXT("/Game/Hide/SM_HideIn.SM_HideIn"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorMesh(
        TEXT("/Game/Hide/SM_HideDoor.SM_HideDoor"));
    if (BodyMesh.Succeeded()) LockerBody->SetStaticMesh(BodyMesh.Object);
    if (DoorMesh.Succeeded()) LockerDoor->SetStaticMesh(DoorMesh.Object);
    ConfigureInteractionMesh(LockerBody);
    ConfigureInteractionMesh(LockerDoor);

    // Align the imported door's hinge-space origin with the front-left edge of
    // the imported locker. The door mesh stays authored relative to DoorPivot.
    if (BodyMesh.Succeeded() && DoorMesh.Succeeded())
    {
        const FBox BodyBounds = BodyMesh.Object->GetBoundingBox();
        const FBox DoorBounds = DoorMesh.Object->GetBoundingBox();
        DoorPivot->SetRelativeLocation(FVector(
            BodyBounds.GetCenter().X - DoorBounds.GetCenter().X,
            BodyBounds.Max.Y - DoorBounds.Min.Y,
            BodyBounds.Min.Z - DoorBounds.Min.Z));
    }

    HideSpot = CreateDefaultSubobject<UJMHideSpotComponent>(TEXT("JMHideSpot"));
    HideSpot->Archetype = EJMHideSpotArchetype::Enclosed;
    HideSpot->HideType = UGameplayTagsManager::Get().RequestGameplayTag(
        FName(TEXT("Hide.Type.Locker")), false);
    HideSpot->InstanceConfigOverride.bOverride = true;
    HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.25f;
    HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.25f;
    HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.2f;
    HideSpot->InstanceConfigOverride.Values.bUseCameraFadeTransition = false;
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;

    PanelMechanism = CreateDefaultSubobject<UJMHideSimplePanelMechanismComponent>(
        TEXT("JMHideSimplePanelMechanism"));
    PanelMechanism->Duration = 0.45f;
    FJMHidePanelPart DoorPart;
    DoorPart.Panel = DoorPivot;
    DoorPart.MotionType = EJMHidePanelMotionType::RotationOnly;
    DoorPart.ClosedRelativeTransform = FTransform(FRotator::ZeroRotator);
    DoorPart.OpenRelativeTransform = FTransform(OpenDoorRotation);
    PanelMechanism->Panels.Add(DoorPart);

    InteractionAdapter = CreateDefaultSubobject<UJMHideInteractableAdapterComponent>(
        TEXT("JMHideInteractable"));
    InteractionAdapter->EnterPrompt = NSLOCTEXT("JMHideReady", "LockerEnter", "Hide in locker");
    InteractionAdapter->ExitPrompt = NSLOCTEXT("JMHideReady", "LockerExit", "Exit locker");

    EntryAnchor = CreateAnchor(this, SceneRoot, TEXT("EntryAnchor"), EJMHideAnchorRole::Entry,
        FVector(0, 105, 95), FRotator(0, -90, 0));
    OccupantAnchor = CreateAnchor(this, SceneRoot, TEXT("OccupantAnchor"), EJMHideAnchorRole::Occupant,
        FVector(0, -5, 95), FRotator(0, 90, 0));
    CameraAnchor = CreateAnchor(this, SceneRoot, TEXT("CameraAnchor"), EJMHideAnchorRole::Camera,
        FVector(0, 5, 165), FRotator(0, 90, 0));
    PrimaryExitAnchor = CreateAnchor(this, SceneRoot, TEXT("PrimaryExitAnchor"), EJMHideAnchorRole::PrimaryExit,
        FVector(0, 125, 95), FRotator(0, -90, 0));

    Tags.Add(TEXT("JM.Hide.Ready"));
    Tags.Add(TEXT("JM.Hide.Locker"));
}

void AJMHideLockerActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;
    EnsureDoorHierarchy();
    if (PanelMechanism && PanelMechanism->Panels.Num() > 0)
    {
        FJMHidePanelPart& DoorPart = PanelMechanism->Panels[0];
        DoorPart.Panel = DoorPivot;
        DoorPart.MotionType = EJMHidePanelMotionType::RotationOnly;
        DoorPart.ClosedRelativeTransform.SetRotation(FQuat::Identity);
        DoorPart.OpenRelativeTransform.SetRotation(OpenDoorRotation.Quaternion());
    }
}

void AJMHideLockerActor::PostRegisterAllComponents()
{
    Super::PostRegisterAllComponents();
    EnsureDoorHierarchy();
}

void AJMHideLockerActor::BeginPlay()
{
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;
    EnsureDoorHierarchy();
    Super::BeginPlay();
}

void AJMHideLockerActor::EnsureDoorHierarchy()
{
    if (LockerDoor && DoorPivot && LockerDoor->GetAttachParent() != DoorPivot)
    {
        // Existing level instances may retain the pre-DoorPivot serialized parent.
        // Keep the authored relative offset; only repair ownership of the rotation.
        LockerDoor->AttachToComponent(
            DoorPivot, FAttachmentTransformRules::KeepRelativeTransform);
    }
}

AJMHideBedActor::AJMHideBedActor()
{
    PrimaryActorTick.bCanEverTick = false;
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    BedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BedMesh"));
    BedMesh->SetupAttachment(SceneRoot);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> BedAsset(
        TEXT("/Game/Hide/SM_Bed.SM_Bed"));
    if (BedAsset.Succeeded()) BedMesh->SetStaticMesh(BedAsset.Object);
    ConfigureInteractionMesh(BedMesh);

    HideSpot = CreateDefaultSubobject<UJMHideSpotComponent>(TEXT("JMHideSpot"));
    HideSpot->Archetype = EJMHideSpotArchetype::OpenSpace;
    HideSpot->HideType = UGameplayTagsManager::Get().RequestGameplayTag(
        FName(TEXT("Hide.Type.UnderBed")), false);
    HideSpot->InstanceConfigOverride.bOverride = true;
    HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.35f;
    HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.35f;
    HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.25f;
    HideSpot->InstanceConfigOverride.Values.bUseCameraFadeTransition = true;
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;

    InteractionAdapter = CreateDefaultSubobject<UJMHideInteractableAdapterComponent>(
        TEXT("JMHideInteractable"));
    InteractionAdapter->EnterPrompt = NSLOCTEXT("JMHideReady", "BedEnter", "Hide under bed");
    InteractionAdapter->ExitPrompt = NSLOCTEXT("JMHideReady", "BedExit", "Crawl out");

    EntryAnchor = CreateAnchor(this, SceneRoot, TEXT("EntryAnchor"), EJMHideAnchorRole::Entry,
        FVector(155, 0, 50), FRotator(0, 180, 0));
    OccupantAnchor = CreateAnchor(this, SceneRoot, TEXT("OccupantAnchor"), EJMHideAnchorRole::Occupant,
        FVector(0, 0, 48), FRotator::ZeroRotator);
    CameraAnchor = CreateAnchor(this, SceneRoot, TEXT("CameraAnchor"), EJMHideAnchorRole::Camera,
        FVector(55, 0, 38), FRotator::ZeroRotator);
    PrimaryExitAnchor = CreateAnchor(this, SceneRoot, TEXT("PrimaryExitAnchor"), EJMHideAnchorRole::PrimaryExit,
        FVector(175, 0, 95), FRotator(0, 180, 0));
    AlternativeExitAnchor = CreateAnchor(this, SceneRoot, TEXT("AlternativeExitAnchor"),
        EJMHideAnchorRole::AlternativeExit, FVector(-175, 0, 95), FRotator::ZeroRotator);

    Tags.Add(TEXT("JM.Hide.Ready"));
    Tags.Add(TEXT("JM.Hide.UnderBed"));
}

void AJMHideBedActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;
}

void AJMHideBedActor::BeginPlay()
{
    HideSpot->InstanceConfigOverride.Values.bHideParticipant = bHideParticipantDuringHide;
    Super::BeginPlay();
}
