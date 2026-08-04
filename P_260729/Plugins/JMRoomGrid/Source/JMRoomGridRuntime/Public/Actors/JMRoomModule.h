#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/JMRoomGridTypes.h"
#include "JMRoomModule.generated.h"

class UJMRoomPortComponent;
class UInstancedStaticMeshComponent;
class USceneComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class JMROOMGRIDRUNTIME_API AJMRoomModule : public AActor
{
    GENERATED_BODY()

public:
    AJMRoomModule();

    virtual void OnConstruction(const FTransform& Transform) override;

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Room")
    void ApplyStructureVisibility();

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Room")
    EJMRoomDirection GetWorldOpenDirections() const;

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Validation")
    FJMRoomValidationResult ValidateRoomContract(float Tolerance = 1.0f) const;

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Assets")
    void SetPrototypeMeshes(UStaticMesh* InFloor, UStaticMesh* InWall, UStaticMesh* InCeiling);

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Room")
    void SetCeilingsVisible(bool bVisible);

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Room")
    bool IsTileWalkable(int32 X, int32 Y) const;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> RoomAnchor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> StructureRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> Floor;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> Ceiling;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> WallNorth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> WallEast;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> WallSouth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UStaticMeshComponent> WallWest;

    /** 25 native floor and ceiling components, indexed Y * 5 + X. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|5x5")
    TArray<TObjectPtr<UStaticMeshComponent>> FloorTiles;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|5x5")
    TArray<TObjectPtr<UStaticMeshComponent>> CeilingTiles;

    /** 30 horizontal edges (EdgeY * 5 + X) and 30 vertical edges (Y * 6 + EdgeX). */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|5x5")
    TArray<TObjectPtr<UStaticMeshComponent>> HorizontalWalls;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|5x5")
    TArray<TObjectPtr<UStaticMeshComponent>> VerticalWalls;

    /** Performant editable 13x13 structure. Layout is rebuilt from room defaults in Construction Script. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|13x13")
    TObjectPtr<UInstancedStaticMeshComponent> FloorInstances13;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|13x13")
    TObjectPtr<UInstancedStaticMeshComponent> CeilingInstances13;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|13x13")
    TObjectPtr<UInstancedStaticMeshComponent> HorizontalWallInstances13;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components|13x13")
    TObjectPtr<UInstancedStaticMeshComponent> VerticalWallInstances13;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UJMRoomPortComponent> PortNorth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UJMRoomPortComponent> PortEast;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UJMRoomPortComponent> PortSouth;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UJMRoomPortComponent> PortWest;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> ContentRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> ItemSpawnRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> AISpawnRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> DebugRoot;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room")
    FName RoomId = NAME_None;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room")
    EJMRoomJunctionType JunctionType = EJMRoomJunctionType::FourWay;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room", meta=(Bitmask, BitmaskEnum="/Script/JMRoomGridRuntime.EJMRoomDirection"))
    int32 CanonicalOpenDirections = static_cast<int32>(EJMRoomDirection::All);

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|5x5")
    bool bUseFiveByFiveLayout = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|5x5", meta=(EditCondition="bUseFiveByFiveLayout"))
    EJMRoomLayoutVariant LayoutVariant = EJMRoomLayoutVariant::A;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|13x13")
    bool bUseThirteenByThirteenLayout = false;

    /** Enable this in a child Blueprint to replace its A-D pattern with your own tile coordinate list (0..12). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|13x13", meta=(EditCondition="bUseThirteenByThirteenLayout"))
    bool bUseCustomWalkableTiles = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|13x13", meta=(EditCondition="bUseThirteenByThirteenLayout && bUseCustomWalkableTiles", ClampMin="0", ClampMax="12"))
    TArray<FIntPoint> CustomWalkableTiles;

    /** Hides ceilings only in Blueprint/level editor views. PIE and packaged games still show them. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|13x13", meta=(EditCondition="bUseThirteenByThirteenLayout"))
    bool bHideCeilingInEditor = true;

    /** Uses fast generated instances. Disable for room Blueprints made from individually editable mesh components. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Room|13x13", meta=(EditCondition="bUseThirteenByThirteenLayout"))
    bool bUseAutomatic13x13Structure = true;

    /** Internal generated-component schema version. User-authored components are never included. */
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Room|13x13")
    int32 GeneratedEditableStructureVersion = 0;

private:
    void ConfigurePort(UJMRoomPortComponent* Port, EJMRoomDirection Direction, const FVector& Location, float Yaw);
};
