#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/JMInteractableInterface.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeInteractionActorBase.generated.h"

class UBoxComponent;
class USceneComponent;
class UStaticMeshComponent;
class UJMPrototypeStationInteractionWidget;
class USoundBase;

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

	/** When enabled, E opens a modal and the operation runs only after confirmation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|UI")
	bool bUseConfirmationUI = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|UI")
	TSubclassOf<UJMPrototypeStationInteractionWidget> InteractionWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|UI")
	FText InteractionTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|UI", meta = (MultiLine = "true"))
	FText InteractionDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|UI")
	FText ConfirmButtonText;

	/** Runtime-safe Engine sound. Replace per Station or Blueprint when final audio is ready. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Audio")
	TSoftObjectPtr<USoundBase> OpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Audio")
	TSoftObjectPtr<USoundBase> SuccessSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Audio")
	TSoftObjectPtr<USoundBase> FailureSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Audio")
	TSoftObjectPtr<USoundBase> CloseSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction|Audio", meta = (ClampMin = "0.0"))
	float InteractionSoundVolume = 0.65f;

	virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
	virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
	virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
	virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Interaction")
	FJMPrototypeOperationResult ConfirmPendingInteraction();

	void HandleInteractionWidgetClosed(UJMPrototypeStationInteractionWidget* Widget);
	void PlayInteractionSound(const TSoftObjectPtr<USoundBase>& Sound, float PitchMultiplier) const;
	virtual FText BuildInteractionDescription(const FJMInteractionContext& Context) const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Upgrade Prototype")
	void OnPrototypeInteractionResolved(bool bSucceeded, EJMPrototypeOperationCode Code, const FText& Message);

protected:
	virtual bool IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const;
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context);
	FJMInteractionResult OpenConfirmationUI(const FJMInteractionContext& Context);

private:
	FJMInteractionContext PendingInteractionContext;
	TWeakObjectPtr<UJMPrototypeStationInteractionWidget> ActiveInteractionWidget;
};
