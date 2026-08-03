#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interaction/JMInteractableInterface.h"
#include "ReusableDialogueTypes.h"
#include "ReuseDialogueInteractableComponent.generated.h"

class UDialogueSequence;
class UDialogueSubsystem;

/**
 * JMInteraction 요청을 ReusableDialogueSystem 재생 요청으로 변환하는 어댑터 컴포넌트다.
 */
UCLASS(ClassGroup = (Interaction), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class REUSABLEDIALOGUESYSTEM_API UReuseDialogueInteractableComponent : public UActorComponent, public IJMInteractableInterface
{
	GENERATED_BODY()

public:
	UReuseDialogueInteractableComponent();

	/** 상호작용 시 재생할 Dialogue Sequence Data Asset. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction")
	TSoftObjectPtr<UDialogueSequence> DialogueSequence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction")
	FText InteractionPrompt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction", meta = (ClampMin = "0.0"))
	float InteractionDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction")
	int32 InteractionPriority = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Playback")
	EDialogueInteractionMode InteractionMode = EDialogueInteractionMode::Modal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Playback")
	EExistingDialoguePolicy ExistingDialoguePolicy = EExistingDialoguePolicy::Reject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction")
	bool bInteractionEnabled = true;

	/** 끄면 Dialogue가 한 번 성공적으로 시작된 뒤 더 이상 상호작용할 수 없다. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue|Interaction")
	bool bAllowRepeat = true;

	UFUNCTION(BlueprintCallable, Category = "Dialogue|Interaction")
	void ResetInteraction();

	UFUNCTION(BlueprintPure, Category = "Dialogue|Interaction")
	bool HasStartedDialogue() const { return bHasStartedDialogue; }

	virtual bool CanInteract_Implementation(const FJMInteractionContext& Context) const override;
	virtual FJMInteractionResult BeginInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionResult CompleteInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual void CancelInteract_Implementation(const FJMInteractionContext& Context) override;
	virtual FJMInteractionPrompt GetInteractionPrompt_Implementation(const FJMInteractionContext& Context) const override;
	virtual float GetInteractionDuration_Implementation(const FJMInteractionContext& Context) const override;
	virtual int32 GetInteractionPriority_Implementation(const FJMInteractionContext& Context) const override;

private:
	UDialogueSubsystem* ResolveDialogueSubsystem() const;
	APlayerController* ResolvePlayerController(const FJMInteractionContext& Context) const;

	UPROPERTY(Transient)
	bool bHasStartedDialogue = false;
};
