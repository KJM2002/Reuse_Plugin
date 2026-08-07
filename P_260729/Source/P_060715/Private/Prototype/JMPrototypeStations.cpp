#include "Prototype/JMPrototypeStations.h"

#include "Components/InventoryComponent.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Pawn.h"
#include "Items/InventoryItemDefinition.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype/JMPrototypeInventoryResolver.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "UObject/ConstructorHelpers.h"

#define LOCTEXT_NAMESPACE "JMPrototypeStations"

namespace
{
	UJMPrototypeProgressionSubsystem* ResolveProgression(const AActor* Actor)
	{
		UGameInstance* GameInstance = Actor ? Actor->GetGameInstance() : nullptr;
		return GameInstance ? GameInstance->GetSubsystem<UJMPrototypeProgressionSubsystem>() : nullptr;
	}
}

AJMPrototypeQuestSubmitStation::AJMPrototypeQuestSubmitStation()
{
	InteractionPrompt = LOCTEXT("SubmitQuest", "의뢰 제출 확인");
	bUseConfirmationUI = true;
	InteractionTitle = LOCTEXT("SubmitTitle", "의뢰 제출");
	InteractionDescription = LOCTEXT("SubmitDescription", "점액 샘플을 제출하고 의뢰 보상을 받습니다.");
	ConfirmButtonText = LOCTEXT("SubmitConfirm", "제출하기");
	QuestItemName = LOCTEXT("SlimeSampleName", "점액 샘플");
	SecondQuestItemName = LOCTEXT("SlimeSacName", "점액 부산물");
	static ConstructorHelpers::FObjectFinder<UInventoryItemDefinition> DefaultQuestItem(
		TEXT("/Game/Prototype/Data/Items/DA_Item_SlimeSample.DA_Item_SlimeSample"));
	static ConstructorHelpers::FObjectFinder<UInventoryItemDefinition> DefaultSecondQuestItem(
		TEXT("/Game/Prototype/Data/Items/DA_Item_SlimeSac.DA_Item_SlimeSac"));
	if (DefaultQuestItem.Succeeded())
	{
		QuestItem = DefaultQuestItem.Object;
	}
	if (DefaultSecondQuestItem.Succeeded())
	{
		SecondQuestItem = DefaultSecondQuestItem.Object;
	}
}

FText AJMPrototypeQuestSubmitStation::BuildInteractionDescription(const FJMInteractionContext&) const
{
	const UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	if (!Progression || !Progression->HasActiveQuest())
	{
		return LOCTEXT("NoActiveQuest", "[아직 의뢰가 없습니다]\n의뢰인에게서 새 의뢰를 받아 주세요.");
	}
	const bool bSecondQuest = Progression->GetActiveQuestIndex() == 1;
	UInventoryItemDefinition* RequiredItem = bSecondQuest ? SecondQuestItem : QuestItem;
	const int32 Needed = bSecondQuest ? SecondRequiredQuantity : RequiredQuantity;
	const FText ItemName = bSecondQuest ? SecondQuestItemName : QuestItemName;
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
	UInventoryComponent* Inventory = JMPrototypeInventory::Resolve(Pawn);
	const int32 Owned = Inventory && RequiredItem ? Inventory->GetItemQuantity(RequiredItem) : 0;
	const FJMPrototypeConfig Config = Progression->GetPrototypeConfig();
	const int32 Reward = bSecondQuest ? Config.SecondQuestReward : Config.QuestReward;
	return FText::Format(LOCTEXT("SubmitSummary", "의뢰 {0}: {1}\n필요: {2}개 / 보유: {3}개\n보상: +{4} 덕코인"),
		FText::AsNumber(Progression->GetActiveQuestIndex() + 1), ItemName,
		FText::AsNumber(Needed), FText::AsNumber(Owned), FText::AsNumber(Reward));
}

FJMPrototypeOperationResult AJMPrototypeQuestSubmitStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	if (!Progression)
	{
		return FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration,
			LOCTEXT("MissingProgression", "의뢰 진행 시스템을 찾을 수 없습니다."));
	}
	const int32 ActiveQuestIndex = Progression->GetActiveQuestIndex();
	const bool bSecondQuest = ActiveQuestIndex == 1;
	UInventoryItemDefinition* RequiredItem = bSecondQuest ? SecondQuestItem : QuestItem;
	const int32 Needed = bSecondQuest ? SecondRequiredQuantity : RequiredQuantity;
	const FJMPrototypeConfig Config = Progression->GetPrototypeConfig();
	const int32 Reward = bSecondQuest ? Config.SecondQuestReward : Config.QuestReward;
	FJMPrototypeOperationResult Result = Progression->SubmitQuest(
		JMPrototypeInventory::Resolve(Context.InstigatorActor), RequiredItem, Needed, Reward, ActiveQuestIndex);
	if (Result.bSucceeded && SubmissionObjectiveId.IsValid())
	{
		if (UGameInstance* GameInstance = GetGameInstance())
		{
			if (UJMObjectiveSubsystem* Objectives = GameInstance->GetSubsystem<UJMObjectiveSubsystem>())
			{
				Objectives->CompleteObjective(SubmissionObjectiveId);
			}
		}
	}
	return Result;
}

AJMPrototypeCookingStation::AJMPrototypeCookingStation()
{
	InteractionPrompt = LOCTEXT("Cook", "요리 및 판매 확인");
	bUseConfirmationUI = true;
	InteractionTitle = LOCTEXT("CookTitle", "요리 및 판매");
	InteractionDescription = LOCTEXT("CookDescription", "점액 부산물로 요리한 뒤 즉시 판매합니다.");
	ConfirmButtonText = LOCTEXT("CookConfirm", "요리하고 판매하기");
}

FText AJMPrototypeCookingStation::BuildInteractionDescription(const FJMInteractionContext&) const
{
	const UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);
	UInventoryComponent* Inventory = JMPrototypeInventory::Resolve(Pawn);
	const int32 Owned = Inventory && Ingredient ? Inventory->GetItemQuantity(Ingredient) : 0;
	const int32 Reward = Progression ? Progression->GetPrototypeConfig().CookingReward : 0;
	return FText::Format(LOCTEXT("CookSummary", "필요: 점액 부산물 {0}개\n보유: {1}개\n판매 보상: +{2} 덕코인"),
		FText::AsNumber(RequiredQuantity), FText::AsNumber(Owned), FText::AsNumber(Reward));
}

FJMPrototypeOperationResult AJMPrototypeCookingStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	return Progression
		? Progression->CookAndSell(JMPrototypeInventory::Resolve(Context.InstigatorActor), Ingredient, RequiredQuantity)
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration,
			LOCTEXT("MissingCookingProgression", "요리 진행 시스템을 찾을 수 없습니다."));
}

AJMPrototypeUpgradeStation::AJMPrototypeUpgradeStation()
{
	InteractionPrompt = LOCTEXT("Upgrade", "인벤토리 업그레이드 확인");
	bUseConfirmationUI = true;
	InteractionTitle = LOCTEXT("UpgradeTitle", "인벤토리 업그레이드");
	InteractionDescription = LOCTEXT("UpgradeDescription", "덕코인을 사용해 가방 슬롯을 확장합니다.");
	ConfirmButtonText = LOCTEXT("UpgradeConfirm", "업그레이드 구매");
}

FText AJMPrototypeUpgradeStation::BuildInteractionDescription(const FJMInteractionContext&) const
{
	const UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	if (!Progression)
	{
		return InteractionDescription;
	}
	const FJMPrototypeConfig Config = Progression->GetPrototypeConfig();
	return FText::Format(LOCTEXT("UpgradeSummary", "비용: {0} 덕코인\n보유: {1} 덕코인\n가방: {2}칸 → {3}칸"),
		FText::AsNumber(Config.InventoryUpgradeCost), FText::AsNumber(Progression->GetCurrency()),
		FText::AsNumber(Config.BaseInventorySlots), FText::AsNumber(Config.UpgradedInventorySlots));
}

FJMPrototypeOperationResult AJMPrototypeUpgradeStation::PerformPrototypeInteraction(const FJMInteractionContext& Context)
{
	UJMPrototypeProgressionSubsystem* Progression = ResolveProgression(this);
	return Progression
		? Progression->PurchaseInventoryUpgrade(JMPrototypeInventory::Resolve(Context.InstigatorActor))
		: FJMPrototypeOperationResult::Failure(EJMPrototypeOperationCode::InvalidConfiguration,
			LOCTEXT("MissingUpgradeProgression", "업그레이드 진행 시스템을 찾을 수 없습니다."));
}

#undef LOCTEXT_NAMESPACE
