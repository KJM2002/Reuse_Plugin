#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMDoorMovementComponent.generated.h"

class USceneComponent;
class UPrimitiveComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=(JMGameplay), meta=(BlueprintSpawnableComponent))
class JMDOORRUNTIME_API UJMDoorMovementComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMDoorMovementComponent();

    virtual void BeginPlay() override;

    // Runtime wiring only. Keep cross-component references out of inline Details
    // customization to prevent recursive component expansion in the editor.
    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Movement")
    TObjectPtr<USceneComponent> MovingComponent = nullptr;

    /** The primitive used for obstruction checks. It may be a child of MovingComponent. */
    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Movement")
    TObjectPtr<UPrimitiveComponent> CollisionComponent = nullptr;

    /** A child component whose future position represents the moving door leaf. */
    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Movement")
    TObjectPtr<USceneComponent> DirectionProbeComponent = nullptr;

    UFUNCTION(BlueprintCallable, Category="JM Door|Movement")
    virtual void InitializeMovingComponent(USceneComponent* InMovingComponent);

    UFUNCTION(BlueprintCallable, Category="JM Door|Movement")
    void SetCollisionComponent(UPrimitiveComponent* InCollisionComponent);

    UFUNCTION(BlueprintCallable, Category="JM Door|Movement")
    void SetDirectionProbeComponent(USceneComponent* InDirectionProbeComponent);

    UFUNCTION(BlueprintCallable, Category="JM Door|Movement")
    void SetOpenFraction(float OpenFraction, int32 DirectionSign);

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    FTransform GetRelativeTransformAtFraction(float OpenFraction, int32 DirectionSign) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    FTransform GetWorldTransformAtFraction(float OpenFraction, int32 DirectionSign) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    FTransform GetCollisionWorldTransformAtFraction(float OpenFraction, int32 DirectionSign) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    FVector GetDirectionProbeWorldLocationAtFraction(float OpenFraction, int32 DirectionSign) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    USceneComponent* GetMovingComponent() const { return MovingComponent; }

    UFUNCTION(BlueprintPure, Category="JM Door|Movement")
    UPrimitiveComponent* GetCollisionComponent() const { return CollisionComponent; }

    UFUNCTION(BlueprintNativeEvent, Category="JM Door|Movement")
    FTransform CalculateRelativeTransform(float OpenFraction, int32 DirectionSign) const;

    virtual FTransform CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const;

protected:
    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="JM Door|Movement")
    FTransform ClosedRelativeTransform = FTransform::Identity;
};
