#pragma once

#include "CoreMinimal.h"
#include "Movement/JMDoorMovementComponent.h"
#include "JMRotatingDoorMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(JMGameplay), meta=(BlueprintSpawnableComponent))
class JMDOORRUNTIME_API UJMRotatingDoorMovementComponent : public UJMDoorMovementComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Rotation", meta=(ClampMin="0.0", ClampMax="360.0", Units="deg"))
    float OpenAngle = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Rotation")
    FVector LocalRotationAxis = FVector::UpVector;

    virtual FTransform CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const override;
};
