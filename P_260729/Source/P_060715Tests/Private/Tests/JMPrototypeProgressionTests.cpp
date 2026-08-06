#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Engine/GameInstance.h"
#include "Items/InventoryItemDefinition.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypeFullEconomyLoopTest,
	"JM.Prototype.Progression.FullEconomyLoop",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeFullEconomyLoopTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	UJMPrototypeProgressionSubsystem* Progression = NewObject<UJMPrototypeProgressionSubsystem>(GameInstance);
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	UInventoryItemDefinition* QuestItem = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* Ingredient = NewObject<UInventoryItemDefinition>();
	QuestItem->ItemId = TEXT("Prototype.SlimeSample");
	QuestItem->bStackable = true;
	QuestItem->MaxStackSize = 10;
	Ingredient->ItemId = TEXT("Prototype.SlimeSac");

	const FJMPrototypeConfig Config;
	TestTrue(TEXT("Valid defaults configure the prototype"), Progression->ConfigurePrototype(Config).bSucceeded);
	TestTrue(TEXT("Base capacity is applied"), Progression->ApplyOwnedInventoryCapacity(Inventory).bSucceeded);
	TestEqual(TEXT("Initial inventory has four slots"), Inventory->GetMaxInventorySlots(), 4);
	TestTrue(TEXT("Quest can be accepted"), Progression->AcceptQuest().bSucceeded);
	TestTrue(TEXT("Dungeon can be entered"), Progression->EnterDungeon().bSucceeded);
	TestFalse(TEXT("Travel marker starts clear"), Progression->ConsumeLevelTravelPending());
	Progression->MarkLevelTravelPending();
	TestTrue(TEXT("Intentional travel marker is consumed once"), Progression->ConsumeLevelTravelPending());
	TestFalse(TEXT("Travel marker does not leak into a restart"), Progression->ConsumeLevelTravelPending());
	Progression->MarkLevelTravelPending();
	TestTrue(TEXT("Failed travel can restore the pre-travel state"), Progression->CancelPendingLevelTravel(EJMPrototypeRunState::QuestAccepted));
	TestEqual(TEXT("Failed travel restores quest accepted"), Progression->GetRunState(), EJMPrototypeRunState::QuestAccepted);
	TestFalse(TEXT("Failed travel clears its marker"), Progression->ConsumeLevelTravelPending());
	TestTrue(TEXT("Dungeon can be entered again after rollback"), Progression->EnterDungeon().bSucceeded);
	TestFalse(TEXT("Quest cannot be submitted while exploring"), Progression->SubmitQuest(Inventory, QuestItem, 3).bSucceeded);

	TestTrue(TEXT("Quest samples are collected"), Inventory->AddItem(QuestItem, 3));
	TestTrue(TEXT("Cooking ingredient is collected"), Inventory->AddItem(Ingredient));
	TestTrue(TEXT("Player can return to base"), Progression->ReturnToBase().bSucceeded);
	TestTrue(TEXT("Quest submission succeeds"), Progression->SubmitQuest(Inventory, QuestItem, 3).bSucceeded);
	TestEqual(TEXT("Quest reward grants sixty currency"), Progression->GetCurrency(), 60);
	TestEqual(TEXT("Quest items are consumed"), Inventory->GetItemQuantity(QuestItem), 0);
	TestFalse(TEXT("Quest cannot be submitted twice"), Progression->SubmitQuest(Inventory, QuestItem, 3).bSucceeded);

	TestTrue(TEXT("Ingredient can be cooked and sold"), Progression->CookAndSell(Inventory, Ingredient).bSucceeded);
	TestEqual(TEXT("Cooking raises currency to eighty"), Progression->GetCurrency(), 80);
	TestTrue(TEXT("Inventory upgrade can be purchased"), Progression->PurchaseInventoryUpgrade(Inventory).bSucceeded);
	TestTrue(TEXT("Upgrade ownership is recorded"), Progression->HasInventoryUpgrade());
	TestEqual(TEXT("Upgrade expands inventory to six slots"), Inventory->GetMaxInventorySlots(), 6);
	TestEqual(TEXT("Upgrade spends all prototype currency"), Progression->GetCurrency(), 0);
	TestFalse(TEXT("Upgrade cannot be purchased twice"), Progression->PurchaseInventoryUpgrade(Inventory).bSucceeded);
	TestTrue(TEXT("Next quest can be accepted"), Progression->AcceptQuest().bSucceeded);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypeFailureSafetyTest,
	"JM.Prototype.Progression.FailureSafety",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeFailureSafetyTest::RunTest(const FString& Parameters)
{
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	UJMPrototypeProgressionSubsystem* Progression = NewObject<UJMPrototypeProgressionSubsystem>(GameInstance);
	FJMPrototypeConfig InvalidConfig;
	InvalidConfig.UpgradedInventorySlots = InvalidConfig.BaseInventorySlots;
	TestFalse(TEXT("Invalid configuration is rejected"), Progression->ConfigurePrototype(InvalidConfig).bSucceeded);
	TestFalse(TEXT("Unconfigured quest cannot start"), Progression->AcceptQuest().bSucceeded);

	const FJMPrototypeConfig ValidConfig;
	TestTrue(TEXT("Valid configuration succeeds"), Progression->ConfigurePrototype(ValidConfig).bSucceeded);
	TestFalse(TEXT("Dungeon cannot be entered before quest acceptance"), Progression->EnterDungeon().bSucceeded);
	TestFalse(TEXT("Missing inventory cannot be upgraded"), Progression->PurchaseInventoryUpgrade(nullptr).bSucceeded);
	TestEqual(TEXT("Failed operations do not change currency"), Progression->GetCurrency(), 0);
	TestEqual(TEXT("Failed operations keep initial state"), Progression->GetRunState(), EJMPrototypeRunState::AwaitingQuest);
	return true;
}

#endif
