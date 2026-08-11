#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Types/JMHarpoonInteractionTypes.h"
#include "JMHarpoonInteractable.generated.h"

UINTERFACE(BlueprintType)
class JMPHYSICALGRABBER_API UJMHarpoonInteractable : public UInterface
{
    GENERATED_BODY()
};

/** Target-owned contract. The harpoon never needs to know whether it hit slime, a door, or a portal core. */
class JMPHYSICALGRABBER_API IJMHarpoonInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM|Harpoon Interaction")
    FJMHarpoonInteractionProfile GetHarpoonInteractionProfile(const FJMHarpoonInteractionContext& Context) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM|Harpoon Interaction")
    void OnHarpoonEmbedded(const FJMHarpoonInteractionContext& Context);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM|Harpoon Interaction")
    void OnHarpoonPullStarted(const FJMHarpoonInteractionContext& Context);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM|Harpoon Interaction")
    EJMHarpoonReactionDirective OnHarpoonPullUpdated(
        const FJMHarpoonInteractionContext& Context,
        const FJMHarpoonPullUpdate& Update);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM|Harpoon Interaction")
    void OnHarpoonInteractionEnded(
        const FJMHarpoonInteractionContext& Context,
        EJMHarpoonInteractionEndReason Reason);
};
