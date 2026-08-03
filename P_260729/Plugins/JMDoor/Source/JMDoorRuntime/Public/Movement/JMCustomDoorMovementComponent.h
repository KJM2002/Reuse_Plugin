#pragma once

#include "CoreMinimal.h"
#include "Movement/JMDoorMovementComponent.h"
#include "JMCustomDoorMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(JMGameplay), meta=(BlueprintSpawnableComponent), DisplayName="JM Custom Door Movement")
class JMDOORRUNTIME_API UJMCustomDoorMovementComponent : public UJMDoorMovementComponent
{
    GENERATED_BODY()

public:
    virtual FTransform CalculateRelativeTransform_Implementation(float OpenFraction, int32 DirectionSign) const override;
};
