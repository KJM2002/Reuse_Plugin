#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareEventPayload.generated.h"

class AJMJumpScareAnchor;
class UJMJumpScareDefinition;
class APawn;
class APlayerController;

UCLASS(BlueprintType, Transient)
class JMJUMPSCARE_API UJMJumpScareEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    FGameplayTag JumpScareId;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<UJMJumpScareDefinition> Definition = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    EJMJumpScareState CurrentState = EJMJumpScareState::Idle;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    EJMJumpScarePhase CurrentPhase = EJMJumpScarePhase::Idle;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<AActor> SpawnedActor = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<AJMJumpScareAnchor> Anchor = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    EJMJumpScarePlayResult Result = EJMJumpScarePlayResult::Started;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<UObject> Trigger = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<APawn> TargetPawn = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM JumpScare")
    TObjectPtr<APlayerController> PlayerController = nullptr;
};
