#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Types/JMGameplayEventTypes.h"
#include "JMObjectiveTestReceiver.generated.h"

UCLASS()
class UJMObjectiveTestPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()
};

UCLASS()
class UJMObjectiveTestReceiver : public UObject
{
    GENERATED_BODY()

public:
    int32 ReceivedCount = 0;
    void Receive(const FJMGameplayEventMessage& Message) { ++ReceivedCount; }
};
