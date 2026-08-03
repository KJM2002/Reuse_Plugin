#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "Movement/JMDoorMovementComponent.h"
#include "JMSlidingDoorMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(JMGameplay), meta=(BlueprintSpawnableComponent))
class JMDOORRUNTIME_API UJMSlidingDoorMovementComponent : public UJMDoorMovementComponent
{
    GENERATED_BODY()

public:
    virtual void Serialize(FArchive& Ar) override;
    virtual void PostLoad() override;
    virtual void BeginPlay() override;
    virtual void InitializeMovingComponent(USceneComponent* InMovingComponent) override;

    /** Legacy single-panel offset. Existing assets continue to use this as panel A. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Slide Door|Legacy", meta=(Units="cm", DeprecatedProperty, DeprecationMessage="Use Door A Open Offset."))
    FVector LocalOpenOffset = FVector(0.0f, 150.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Slide Door|Legacy", meta=(DeprecatedProperty, DeprecationMessage="Panel directions are fixed in the dual-panel layout."))
    bool bReverseOffsetWithDirection = true;

    /** Panel A always opens toward actor-local left by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Slide Door|Door A", meta=(Units="cm"))
    FVector DoorAOpenOffset = FVector(0.0f, -150.0f, 0.0f);

    /** Panel B always opens toward actor-local right by default. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Slide Door|Door B", meta=(Units="cm"))
    FVector DoorBOpenOffset = FVector(0.0f, 150.0f, 0.0f);

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="JM Door|Slide Door|Door A")
    FTransform DoorAClosedRelativeTransform = FTransform::Identity;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="JM Door|Slide Door|Door B")
    FTransform DoorBClosedRelativeTransform = FTransform::Identity;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Slide Door|Door B")
    TObjectPtr<USceneComponent> MovingComponentB = nullptr;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Slide Door|Door B")
    TObjectPtr<UPrimitiveComponent> CollisionComponentB = nullptr;

    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    void InitializeDoorBComponent(USceneComponent* InMovingComponent, UPrimitiveComponent* InCollisionComponent);

    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    void SetPanelOpenFraction(EJMSlideDoorPanel Panel, float OpenFraction);

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    FTransform GetPanelWorldTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    FTransform GetPanelCollisionWorldTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    UPrimitiveComponent* GetPanelCollisionComponent(EJMSlideDoorPanel Panel) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    bool HasPanel(EJMSlideDoorPanel Panel) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    bool IsLegacySinglePanelAsset() const { return bLegacySinglePanelAsset; }

    virtual FTransform CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const override;

private:
    FTransform GetPanelRelativeTransformAtFraction(EJMSlideDoorPanel Panel, float OpenFraction) const;

    UPROPERTY(Transient)
    bool bLegacySinglePanelAsset = false;

    bool bLoadedFromLegacyVersion = false;
};
