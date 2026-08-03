#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMHideReadyActors.generated.h"

class UJMHideAnchorComponent;
class UJMHideInteractableAdapterComponent;
class UJMHideSimplePanelMechanismComponent;
class UJMHideSpotComponent;
class USceneComponent;
class UStaticMeshComponent;

/** Project-ready locker assembled from /Game/Hide meshes and JMInteraction. */
UCLASS(Blueprintable)
class P_060715_API AJMHideLockerActor : public AActor
{
    GENERATED_BODY()

public:
    AJMHideLockerActor();
    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void PostRegisterAllComponents() override;

protected:
    virtual void BeginPlay() override;

private:
    void EnsureDoorHierarchy();

public:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UStaticMeshComponent> LockerBody;

    /** Explicit hinge. Runtime door animation rotates this component only. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Door")
    TObjectPtr<USceneComponent> DoorPivot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UStaticMeshComponent> LockerDoor;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hide|Door")
    FRotator OpenDoorRotation = FRotator(0.0, 105.0, 0.0);

    /** Keep first-person owned components, including the flashlight, active while hidden. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hide")
    bool bHideParticipantDuringHide = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UJMHideSpotComponent> HideSpot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UJMHideSimplePanelMechanismComponent> PanelMechanism;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UJMHideInteractableAdapterComponent> InteractionAdapter;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> EntryAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> OccupantAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> CameraAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> PrimaryExitAnchor;
};

/** Project-ready under-bed hide spot assembled from /Game/Hide/SM_Bed. */
UCLASS(Blueprintable)
class P_060715_API AJMHideBedActor : public AActor
{
    GENERATED_BODY()

public:
    AJMHideBedActor();
    virtual void OnConstruction(const FTransform& Transform) override;

protected:
    virtual void BeginPlay() override;

public:
    /** Keep first-person owned components, including the flashlight, active while hidden. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hide")
    bool bHideParticipantDuringHide = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UStaticMeshComponent> BedMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UJMHideSpotComponent> HideSpot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide")
    TObjectPtr<UJMHideInteractableAdapterComponent> InteractionAdapter;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> EntryAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> OccupantAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> CameraAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> PrimaryExitAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Hide|Anchors")
    TObjectPtr<UJMHideAnchorComponent> AlternativeExitAnchor;
};
