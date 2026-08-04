#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Types/JMRoomGridTypes.h"
#include "JMRoomPortComponent.generated.h"

UCLASS(ClassGroup=(JMRoomGrid), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class JMROOMGRIDRUNTIME_API UJMRoomPortComponent : public UArrowComponent
{
    GENERATED_BODY()

public:
    UJMRoomPortComponent();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Port")
    EJMRoomDirection LocalDirection = EJMRoomDirection::None;

    UFUNCTION(BlueprintPure, Category="Port")
    EJMRoomDirection GetWorldDirection() const;
};
