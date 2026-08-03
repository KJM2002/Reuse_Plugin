#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interaction/JMInteractableInterface.h"
#include "JMDoorInteractableAdapterComponent.generated.h"

/**
 * JMInteractionComponent-facing adapter automatically added to JMDoor actors.
 * Add it explicitly to a door Blueprint and enable per-door overrides when a
 * particular door needs text different from the project defaults.
 */
UCLASS(ClassGroup = (JMInteraction), BlueprintType, meta = (BlueprintSpawnableComponent))
class JMDOORGAMEPLAYINTEGRATION_API UJMDoorInteractableAdapterComponent final
    : public UActorComponent
    , public IJMInteractableInterface
{
    GENERATED_BODY()

public:
    UJMDoorInteractableAdapterComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JM Door|Interaction Prompt")
    bool bOverridePromptTexts = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JM Door|Interaction Prompt",
        meta = (EditCondition = "bOverridePromptTexts"))
    FText OpenDoorPrompt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JM Door|Interaction Prompt",
        meta = (EditCondition = "bOverridePromptTexts"))
    FText CloseDoorPrompt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JM Door|Interaction Prompt",
        meta = (EditCondition = "bOverridePromptTexts"))
    FText LockedDoorPrompt;

    virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
    virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
    virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
    virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;
};
