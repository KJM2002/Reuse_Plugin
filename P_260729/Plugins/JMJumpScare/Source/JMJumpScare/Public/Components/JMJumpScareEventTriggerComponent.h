#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMGameplayEventTypes.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareEventTriggerComponent.generated.h"

class AJMJumpScareAnchor;
class UJMJumpScareDefinition;

/** Optional event-bus adapter. The core subsystem does not depend on Door, Interaction, or Objective systems. */
UCLASS(ClassGroup=(JM), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent, DisplayName="JM JumpScare Event Trigger"))
class JMJUMPSCARE_API UJMJumpScareEventTriggerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMJumpScareEventTriggerComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    FGameplayTag TriggerEventTag;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    EJMGameplayEventMatchType EventMatchType = EJMGameplayEventMatchType::Exact;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    TObjectPtr<UJMJumpScareDefinition> JumpScareDefinition = nullptr;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    TObjectPtr<AJMJumpScareAnchor> JumpScareAnchor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    EJMJumpScareTriggerPolicy TriggerPolicy = EJMJumpScareTriggerPolicy::Once;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    FJMGameplayEventSubscriptionHandle SubscriptionHandle;
    bool bHasTriggered = false;
    void HandleGameplayEvent(const FJMGameplayEventMessage& Message);
};
