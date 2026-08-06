#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMPrototypeQuestGiver.generated.h"

class UJMPrototypeDialogueQuestBridgeComponent;
class UReuseDialogueInteractableComponent;
class USceneComponent;
class UStaticMeshComponent;

/** Visible prototype NPC that reuses the dialogue interaction and quest bridge systems. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeQuestGiver : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeQuestGiver();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> VisualMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UReuseDialogueInteractableComponent> DialogueInteraction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UJMPrototypeDialogueQuestBridgeComponent> QuestBridge;
};
