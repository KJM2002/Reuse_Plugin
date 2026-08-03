#pragma once

#include "CoreMinimal.h"
#include "Door/JMDoorTypes.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "JMDoorStateChangedEventPayload.generated.h"

UCLASS(BlueprintType)
class JMDOORRUNTIME_API UJMDoorStateChangedEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "JM Door|Events")
    EJMDoorState OldState = EJMDoorState::Closed;

    UPROPERTY(BlueprintReadOnly, Category = "JM Door|Events")
    EJMDoorState NewState = EJMDoorState::Closed;

    UPROPERTY(BlueprintReadOnly, Category = "JM Door|Events")
    float OpenFraction = 0.0f;
};
