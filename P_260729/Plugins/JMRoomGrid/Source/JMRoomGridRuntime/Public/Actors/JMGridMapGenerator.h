#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/JMRoomGridTypes.h"
#include "JMGridMapGenerator.generated.h"

class AJMRoomModule;
class UArrowComponent;
class UJMRoomDefinition;
class USceneComponent;

USTRUCT(BlueprintType)
struct JMROOMGRIDRUNTIME_API FJMRoomCellRequirement
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Grid")
    FJMGridCoordinate Coordinate;

    UPROPERTY(BlueprintReadOnly, Category="Grid", meta=(Bitmask, BitmaskEnum="/Script/JMRoomGridRuntime.EJMRoomDirection"))
    EJMRoomDirection RequiredOpenDirections = EJMRoomDirection::None;

    UPROPERTY(BlueprintReadOnly, Category="Grid")
    EJMRoomJunctionType JunctionType = EJMRoomJunctionType::FourWay;

    UPROPERTY(BlueprintReadOnly, Category="Grid")
    bool bHasEntrance = false;

    UPROPERTY(BlueprintReadOnly, Category="Grid")
    bool bHasExit = false;
};

USTRUCT(BlueprintType)
struct JMROOMGRIDRUNTIME_API FJMGeneratedRoomRecord
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Generation")
    FJMGridCoordinate Coordinate;

    UPROPERTY(BlueprintReadOnly, Category="Generation")
    FName RoomId = NAME_None;

    UPROPERTY(BlueprintReadOnly, Category="Generation")
    EJMRoomJunctionType JunctionType = EJMRoomJunctionType::FourWay;

    UPROPERTY(BlueprintReadOnly, Category="Generation", meta=(Bitmask, BitmaskEnum="/Script/JMRoomGridRuntime.EJMRoomDirection"))
    EJMRoomDirection OpenDirections = EJMRoomDirection::None;

    UPROPERTY(BlueprintReadOnly, Category="Generation")
    int32 AppliedYaw = 0;

    UPROPERTY(Transient, BlueprintReadOnly, Category="Generation")
    TObjectPtr<AJMRoomModule> RoomActor = nullptr;
};

UCLASS(Blueprintable)
class JMROOMGRIDRUNTIME_API AJMGridMapGenerator : public AActor
{
    GENERATED_BODY()

public:
    AJMGridMapGenerator();

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Generation", meta=(DisplayName="Generate Preview (With Result)"))
    bool GeneratePreview();

    UFUNCTION(CallInEditor, Category="JM Room Grid|Generation", meta=(DisplayName="Generate Preview"))
    void GeneratePreviewInEditor();

    UFUNCTION(CallInEditor, BlueprintCallable, Category="JM Room Grid|Generation")
    void ClearPreview();

    /** Removes only actors tagged JMRoomGrid.Generated, including stale previews from deleted generator instances. */
    UFUNCTION(CallInEditor, BlueprintCallable, Category="JM Room Grid|Generation", meta=(DisplayName="Clear All Generated Rooms In Level"))
    void ClearAllGeneratedRoomsInLevel();

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Generation", meta=(DisplayName="Regenerate Same Seed (With Result)"))
    bool RegenerateSameSeed();

    UFUNCTION(CallInEditor, Category="JM Room Grid|Generation", meta=(DisplayName="Regenerate Same Seed"))
    void RegenerateSameSeedInEditor();

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Generation", meta=(DisplayName="Generate New Seed (With Result)"))
    bool GenerateNewSeed();

    UFUNCTION(CallInEditor, Category="JM Room Grid|Generation", meta=(DisplayName="Generate New Seed"))
    void GenerateNewSeedInEditor();

    UFUNCTION(BlueprintCallable, Category="JM Room Grid|Validation", meta=(DisplayName="Validate Generated Map (With Result)"))
    FJMRoomValidationResult ValidateGeneratedMap() const;

    UFUNCTION(CallInEditor, Category="JM Room Grid|Validation", meta=(DisplayName="Validate Generated Map"))
    void ValidateGeneratedMapInEditor();

    UFUNCTION(CallInEditor, BlueprintCallable, Category="JM Room Grid|Validation")
    void PrintGenerationReport() const;

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Grid")
    FVector GridToLocalLocation(FJMGridCoordinate Coordinate) const;

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Grid")
    static TArray<FJMRoomCellRequirement> BuildStandardTopology();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<USceneComponent> GeneratorRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UArrowComponent> EntranceMarker;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    TObjectPtr<UArrowComponent> ExitMarker;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid", meta=(ClampMin="1.0"))
    float RoomCellSize = 5200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid", meta=(ClampMin="1.0"))
    float RoomHeight = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Selection")
    TArray<TSoftObjectPtr<UJMRoomDefinition>> RoomDefinitions;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Random")
    int32 RandomSeed = 1337;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Random")
    bool bUseRandomSeed = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation")
    bool bGenerateOnBeginPlay = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation")
    bool bGenerateInEditor = true;

    /** Editor/test visibility only. Ceiling meshes remain intact in every room Blueprint. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generation|Preview")
    bool bHideCeilingsForPreview = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
    bool bShowDebug = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(EditCondition="bShowDebug"))
    bool bShowCoordinates = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(EditCondition="bShowDebug"))
    bool bShowRoomType = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(EditCondition="bShowDebug"))
    bool bShowPortDirections = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(EditCondition="bShowDebug"))
    bool bShowRoomBounds = true;

    UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category="Generation")
    TArray<FJMGeneratedRoomRecord> GeneratedRooms;

private:
    bool GenerateInternal(int32 EffectiveSeed);
    void DrawGenerationDebug() const;
};
