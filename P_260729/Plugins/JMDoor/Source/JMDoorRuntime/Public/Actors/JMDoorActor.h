#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/JMDoorSaveInterface.h"
#include "Interfaces/JMDoorUsableInterface.h"
#include "JMDoorActor.generated.h"

class UAudioComponent;
class UJMDoorComponent;
class UJMDoorMovementComponent;
class UStaticMeshComponent;
class USceneComponent;

UCLASS(Abstract, Blueprintable)
class JMDOORRUNTIME_API AJMDoorActor : public AActor, public IJMDoorUsableInterface, public IJMDoorSaveInterface
{
    GENERATED_BODY()

public:
    AJMDoorActor();
    virtual void PostActorCreated() override;
    virtual void PostLoad() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<UStaticMeshComponent> FrameMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<USceneComponent> MovementRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<UStaticMeshComponent> DoorLeafMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<UStaticMeshComponent> LockMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<UJMDoorComponent> DoorComponent;

    virtual FJMDoorResult ExecuteDoorCommand_Implementation(EJMDoorCommand Command, const FJMDoorUseContext& Context) override;
    virtual bool CanExecuteDoorCommand_Implementation(EJMDoorCommand Command, const FJMDoorUseContext& Context) const override;
    virtual EJMDoorState GetDoorState_Implementation() const override;
    virtual FGuid GetDoorPersistentId_Implementation() const override;
    virtual FJMDoorSaveData CaptureDoorSaveData_Implementation() const override;
    virtual bool RestoreDoorSaveData_Implementation(const FJMDoorSaveData& SaveData) override;

protected:
    void ConfigureMovement(UJMDoorMovementComponent* InMovementComponent);
    void EnsurePersistentId();
};

UCLASS(Blueprintable)
class JMDOORRUNTIME_API AJMRotatingDoorActor : public AJMDoorActor
{
    GENERATED_BODY()

public:
    AJMRotatingDoorActor();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<class UJMRotatingDoorMovementComponent> RotatingMovement;
};

UCLASS(Blueprintable)
class JMDOORRUNTIME_API AJMSlidingDoorActor : public AJMDoorActor
{
    GENERATED_BODY()

public:
    AJMSlidingDoorActor();
    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void Tick(float DeltaSeconds) override;
#if WITH_EDITOR
    virtual bool ShouldTickIfViewportsOnly() const override { return true; }
#endif

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Components")
    TObjectPtr<class UJMSlidingDoorMovementComponent> SlidingMovement;

    /** Right-hand panel. The inherited DoorLeafMesh is panel A for compatibility. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM Door|Slide Door|Door B", meta=(DisplayName="Slide Door Mesh B"))
    TObjectPtr<UStaticMeshComponent> DoorLeafMeshB;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Door|Slide Door|Opening Behavior")
    bool bPreviewOpenPositions = false;

    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    FJMDoorResult OpenSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    FJMDoorResult CloseSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    EJMDoorState GetSlideDoorPanelState(EJMSlideDoorPanel Panel) const;
};
