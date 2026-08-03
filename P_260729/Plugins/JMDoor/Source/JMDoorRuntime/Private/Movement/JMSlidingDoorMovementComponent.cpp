#include "Movement/JMSlidingDoorMovementComponent.h"

#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Serialization/CustomVersion.h"

namespace JMSlideDoorCustomVersion
{
    const FGuid GUID(0xE88D6591, 0x5EEA4D6E, 0xB144F64B, 0xB4DA61C2);

    enum Type : int32
    {
        BeforeCustomVersion = 0,
        DualPanelLayout = 1,
        LatestVersion = DualPanelLayout
    };

    const FCustomVersionRegistration Registration(GUID, LatestVersion, TEXT("JMSlideDoorCustomVersion"));
}

void UJMSlidingDoorMovementComponent::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar);
    Ar.UsingCustomVersion(JMSlideDoorCustomVersion::GUID);
    if (Ar.IsLoading() && !HasAnyFlags(RF_ClassDefaultObject))
    {
        bLoadedFromLegacyVersion = Ar.CustomVer(JMSlideDoorCustomVersion::GUID) < JMSlideDoorCustomVersion::DualPanelLayout;
    }
}

void UJMSlidingDoorMovementComponent::PostLoad()
{
    Super::PostLoad();
    bLegacySinglePanelAsset = bLoadedFromLegacyVersion;
}

void UJMSlidingDoorMovementComponent::BeginPlay()
{
    Super::BeginPlay();
    if (MovingComponent)
    {
        DoorAClosedRelativeTransform = MovingComponent->GetRelativeTransform();
        ClosedRelativeTransform = DoorAClosedRelativeTransform;
    }
    if (MovingComponentB)
    {
        DoorBClosedRelativeTransform = MovingComponentB->GetRelativeTransform();
    }
}

void UJMSlidingDoorMovementComponent::InitializeMovingComponent(USceneComponent* InMovingComponent)
{
    Super::InitializeMovingComponent(InMovingComponent);
    if (MovingComponent)
    {
        DoorAClosedRelativeTransform = MovingComponent->GetRelativeTransform();
    }
}

void UJMSlidingDoorMovementComponent::InitializeDoorBComponent(USceneComponent* InMovingComponent, UPrimitiveComponent* InCollisionComponent)
{
    MovingComponentB = InMovingComponent;
    CollisionComponentB = InCollisionComponent;
    if (MovingComponentB)
    {
        DoorBClosedRelativeTransform = MovingComponentB->GetRelativeTransform();
    }
}

void UJMSlidingDoorMovementComponent::SetPanelOpenFraction(EJMSlideDoorPanel Panel, float OpenFraction)
{
    if (Panel == EJMSlideDoorPanel::Both)
    {
        SetPanelOpenFraction(EJMSlideDoorPanel::DoorA, OpenFraction);
        SetPanelOpenFraction(EJMSlideDoorPanel::DoorB, OpenFraction);
        return;
    }

    USceneComponent* PanelComponent = Panel == EJMSlideDoorPanel::DoorB ? MovingComponentB.Get() : MovingComponent.Get();
    if (PanelComponent)
    {
        PanelComponent->SetRelativeTransform(GetPanelRelativeTransformAtFraction(Panel, OpenFraction));
    }
}

FTransform UJMSlidingDoorMovementComponent::GetPanelRelativeTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const
{
    const float Fraction = FMath::Clamp(OpenFraction, 0.0f, 1.0f);
    const bool bPanelB = Panel == EJMSlideDoorPanel::DoorB;
    FTransform Result = bPanelB ? DoorBClosedRelativeTransform : DoorAClosedRelativeTransform;
    const FVector Offset = bPanelB
        ? DoorBOpenOffset
        : (bLegacySinglePanelAsset ? LocalOpenOffset : DoorAOpenOffset);
    Result.SetLocation(Result.GetLocation() + Offset * Fraction);
    return Result;
}

FTransform UJMSlidingDoorMovementComponent::GetPanelWorldTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const
{
    USceneComponent* PanelComponent = Panel == EJMSlideDoorPanel::DoorB ? MovingComponentB.Get() : MovingComponent.Get();
    const FTransform Relative = GetPanelRelativeTransformAtFraction(Panel, OpenFraction);
    if (PanelComponent && PanelComponent->GetAttachParent())
    {
        return Relative * PanelComponent->GetAttachParent()->GetComponentTransform();
    }
    return Relative;
}

FTransform UJMSlidingDoorMovementComponent::GetPanelCollisionWorldTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const
{
    USceneComponent* PanelComponent = Panel == EJMSlideDoorPanel::DoorB ? MovingComponentB.Get() : MovingComponent.Get();
    UPrimitiveComponent* PanelCollision = GetPanelCollisionComponent(Panel);
    const FTransform ProposedPanelWorld = GetPanelWorldTransformAtFraction(Panel, OpenFraction);
    if (!PanelComponent || !PanelCollision || PanelCollision == PanelComponent)
    {
        return ProposedPanelWorld;
    }

    const FTransform CollisionRelativeToPanel = PanelCollision->GetComponentTransform().GetRelativeTransform(PanelComponent->GetComponentTransform());
    return CollisionRelativeToPanel * ProposedPanelWorld;
}

UPrimitiveComponent* UJMSlidingDoorMovementComponent::GetPanelCollisionComponent(EJMSlideDoorPanel Panel) const
{
    return Panel == EJMSlideDoorPanel::DoorB ? CollisionComponentB.Get() : CollisionComponent.Get();
}

bool UJMSlidingDoorMovementComponent::HasPanel(EJMSlideDoorPanel Panel) const
{
    if (Panel == EJMSlideDoorPanel::Both)
    {
        return HasPanel(EJMSlideDoorPanel::DoorA) && HasPanel(EJMSlideDoorPanel::DoorB);
    }
    const USceneComponent* PanelComponent = Panel == EJMSlideDoorPanel::DoorB ? MovingComponentB.Get() : MovingComponent.Get();
    if (!IsValid(PanelComponent))
    {
        return false;
    }

    // The native sliding actor always owns both component slots. An empty static-mesh
    // slot is intentionally treated as unconfigured so one-panel assets keep working.
    if (const UStaticMeshComponent* StaticMeshPanel = Cast<UStaticMeshComponent>(PanelComponent))
    {
        return StaticMeshPanel->GetStaticMesh() != nullptr;
    }
    return true;
}

FTransform UJMSlidingDoorMovementComponent::CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const
{
    if (!bLegacySinglePanelAsset)
    {
        return GetPanelRelativeTransformAtFraction(EJMSlideDoorPanel::DoorA, OpenFraction);
    }

    FTransform Result = ClosedRelativeTransform;
    const float Direction = bReverseOffsetWithDirection ? static_cast<float>(DirectionSign) : 1.0f;
    Result.SetLocation(ClosedRelativeTransform.GetLocation() + LocalOpenOffset * OpenFraction * Direction);
    return Result;
}
