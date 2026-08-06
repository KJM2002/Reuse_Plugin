#include "Prototype/JMPrototypeQuestGiver.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Interaction/ReuseDialogueInteractableComponent.h"
#include "Prototype/JMPrototypeDialogueQuestBridgeComponent.h"

AJMPrototypeQuestGiver::AJMPrototypeQuestGiver()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(SceneRoot);
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	VisualMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	VisualMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	DialogueInteraction = CreateDefaultSubobject<UReuseDialogueInteractableComponent>(TEXT("DialogueInteraction"));
	QuestBridge = CreateDefaultSubobject<UJMPrototypeDialogueQuestBridgeComponent>(TEXT("QuestBridge"));
}
