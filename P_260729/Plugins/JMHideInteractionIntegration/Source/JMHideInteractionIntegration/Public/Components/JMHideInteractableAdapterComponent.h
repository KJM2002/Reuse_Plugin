#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/JMInteractableInterface.h"
#include "JMHideInteractableAdapterComponent.generated.h"

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDEINTERACTIONINTEGRATION_API UJMHideInteractableAdapterComponent final
    : public UActorComponent, public IJMInteractableInterface
{
    GENERATED_BODY()

public:
    UJMHideInteractableAdapterComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Interaction")
    FText EnterPrompt = NSLOCTEXT("JMHideInteraction", "EnterPrompt", "Hide");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Interaction")
    FText ExitPrompt = NSLOCTEXT("JMHideInteraction", "ExitPrompt", "Exit");

    /** Installs the built-in ACharacter driver on first use when the host has not added one. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Interaction")
    bool bAutoInstallDefaultCharacterDriver = true;

    virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
    virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
    virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
    virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
    virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

private:
    class UJMHideInteractorComponent* ResolveOrInstallInteractor(AActor* Participant) const;
};
