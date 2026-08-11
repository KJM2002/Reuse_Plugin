#pragma once

#include "Components/ActorComponent.h"
#include "Interfaces/JMHarpoonInteractable.h"
#include "JMHarpoonInteractableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FJMHarpoonReactionEvent,
    EJMHarpoonReaction, Reaction,
    const FJMHarpoonInteractionContext&, Context);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
    FJMHarpoonNoiseEvent,
    FVector, Location,
    float, Loudness,
    bool, bFromPull);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMHarpoonConditionEvent, float, Condition);

/** Drop-in, data-driven implementation used by cargo, obstacles, creature parts, noise props, and cores. */
UCLASS(ClassGroup=(JM), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class JMPHYSICALGRABBER_API UJMHarpoonInteractableComponent : public UActorComponent, public IJMHarpoonInteractable
{
    GENERATED_BODY()

public:
    UJMHarpoonInteractableComponent();

    virtual FJMHarpoonInteractionProfile GetHarpoonInteractionProfile_Implementation(
        const FJMHarpoonInteractionContext& Context) const override;
    virtual void OnHarpoonEmbedded_Implementation(const FJMHarpoonInteractionContext& Context) override;
    virtual void OnHarpoonPullStarted_Implementation(const FJMHarpoonInteractionContext& Context) override;
    virtual EJMHarpoonReactionDirective OnHarpoonPullUpdated_Implementation(
        const FJMHarpoonInteractionContext& Context,
        const FJMHarpoonPullUpdate& Update) override;
    virtual void OnHarpoonInteractionEnded_Implementation(
        const FJMHarpoonInteractionContext& Context,
        EJMHarpoonInteractionEndReason Reason) override;

    UFUNCTION(BlueprintCallable, Category="JM|Harpoon Interaction")
    void ResetHarpoonCondition();

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Interaction")
    float GetCondition() const { return Condition; }

    UFUNCTION(BlueprintPure, Category="JM|Harpoon Interaction")
    bool HasCompletedReaction() const { return bReactionCompleted; }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Interaction")
    FJMHarpoonInteractionProfile Profile;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Harpoon Interaction")
    bool bReleaseOnReactionComplete = true;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Interaction")
    FJMHarpoonReactionEvent OnReactionCompleted;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Interaction")
    FJMHarpoonNoiseEvent OnHarpoonNoise;

    UPROPERTY(BlueprintAssignable, Category="JM|Harpoon Interaction")
    FJMHarpoonConditionEvent OnConditionChanged;

private:
    float Condition = 1.0f;
    float SustainedReactionTime = 0.0f;
    float PullNoiseCooldown = 0.0f;
    bool bReactionCompleted = false;
};
