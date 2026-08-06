#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/JMInteractableInterface.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeInteractionActorBase.generated.h"

class UBoxComponent;
class USceneComponent;
class UStaticMeshComponent;

/** Shared trace target and prompt behavior for prototype-only stations. */
UCLASS(Abstract, Blueprintable)
class P_060715_API AJMPrototypeInteractionActorBase : public AActor, public IJMInteractableInterface
{
	GENERATED_BODY()

public:
	AJMPrototypeInteractionActorBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> InteractionBounds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	FText InteractionPrompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction", meta = (ClampMin = "0.0"))
	float InteractionDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	int32 InteractionPriority = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bInteractionEnabled = true;

	virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
	virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
	virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
	virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Upgrade Prototype")
	void OnPrototypeInteractionResolved(bool bSucceeded, EJMPrototypeOperationCode Code, const FText& Message);

protected:
	virtual bool IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const;
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context);
};
