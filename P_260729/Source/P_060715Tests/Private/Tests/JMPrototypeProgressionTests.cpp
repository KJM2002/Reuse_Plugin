#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Engine/GameInstance.h"
#include "Items/InventoryItemDefinition.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype/JMPrototypeInventorySaveGame.h"
#include "Prototype/JMPrototypeProgressionSubsystem.h"
#include "Prototype/JMPrototypeStations.h"
#include "Sound/SoundBase.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypeStationFeedbackContractTest,
	"JM.Prototype.Interaction.StationFeedbackContract",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeStationFeedbackContractTest::RunTest(const FString& Parameters)
{
	const AJMPrototypeInteractionActorBase* Stations[] =
	{
		GetDefault<AJMPrototypeQuestSubmitStation>(),
		GetDefault<AJMPrototypeCookingStation>(),
		GetDefault<AJMPrototypeUpgradeStation>()
	};
	for (const AJMPrototypeInteractionActorBase* Station : Stations)
	{
		TestNotNull(TEXT("Station default exists"), Station);
		if (!Station)
		{
			continue;
		}
		TestTrue(TEXT("Station opens confirmation UI"), Station->bUseConfirmationUI);
		TestFalse(TEXT("Station title is visible"), Station->InteractionTitle.IsEmpty());
		TestFalse(TEXT("Station confirm label is visible"), Station->ConfirmButtonText.IsEmpty());
		TestTrue(TEXT("Open feedback sound is configured"), !Station->OpenSound.IsNull());
		TestTrue(TEXT("Success feedback sound is configured"), !Station->SuccessSound.IsNull());
		TestTrue(TEXT("Failure feedback sound is configured"), !Station->FailureSound.IsNull());
	}
	const AJMPrototypeQuestSubmitStation* QuestStation = GetDefault<AJMPrototypeQuestSubmitStation>();
	TestNotNull(TEXT("Second quest item is configured"), QuestStation->SecondQuestItem.Get());
	TestEqual(TEXT("Second quest requires two items"), QuestStation->SecondRequiredQuantity, 2);
	TestNotNull(TEXT("Runtime-safe Engine feedback sound loads"),
		LoadObject<USoundBase>(nullptr, TEXT("/Engine/EngineSounds/1kSineTonePing.1kSineTonePing")));
	return true;
}

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

	FJMPrototypeConfig Config;
	Config.InitialCurrency = 0;
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
	TestFalse(TEXT("Quest cannot be submitted without its items"), Progression->SubmitQuest(Inventory, QuestItem, 3).bSucceeded);

	TestTrue(TEXT("Quest samples are collected"), Inventory->AddItem(QuestItem, 3));
	TestTrue(TEXT("Cooking ingredient is collected"), Inventory->AddItem(Ingredient));
	Progression->CaptureEntireTravelInventory(Inventory);
	UInventoryComponent* InventoryAfterTravel = NewObject<UInventoryComponent>();
	TestTrue(TEXT("Destination inventory receives base capacity"), Progression->ApplyOwnedInventoryCapacity(InventoryAfterTravel).bSucceeded);
	TestTrue(TEXT("Entire inventory restores after travel"), Progression->RestoreTravelInventory(InventoryAfterTravel));
	TestEqual(TEXT("Quest items survive map travel"), InventoryAfterTravel->GetItemQuantity(QuestItem), 3);
	TestEqual(TEXT("Ingredient survives map travel"), InventoryAfterTravel->GetItemQuantity(Ingredient), 1);
	UInventoryComponent* EmptyInventory = NewObject<UInventoryComponent>();
	Progression->CaptureEntireTravelInventory(EmptyInventory);
	UInventoryComponent* DestinationWithDefaults = NewObject<UInventoryComponent>();
	TestTrue(TEXT("Destination starts with a removable default"), DestinationWithDefaults->AddItem(QuestItem, 2));
	TestTrue(TEXT("An empty travel snapshot is still restored"), Progression->RestoreTravelInventory(DestinationWithDefaults));
	TestEqual(TEXT("Empty snapshot clears destination defaults"), DestinationWithDefaults->GetItemQuantity(QuestItem), 0);
	Inventory = InventoryAfterTravel;
	TestTrue(TEXT("Player can return to base"), Progression->ReturnToBase().bSucceeded);
	const FJMPrototypeOperationResult SubmitResult = Progression->SubmitQuest(Inventory, QuestItem, 3);
	TestTrue(TEXT("Quest submission succeeds"), SubmitResult.bSucceeded);
	TestFalse(TEXT("Quest submission provides visible feedback"), SubmitResult.Message.IsEmpty());
	TestEqual(TEXT("Quest reward grants sixty currency"), Progression->GetCurrency(), 60);
	TestEqual(TEXT("Quest items are consumed"), Inventory->GetItemQuantity(QuestItem), 0);
	TestFalse(TEXT("Completed quest clears the active slot"), Progression->HasActiveQuest());
	TestEqual(TEXT("Completed quest returns to empty quest state"), Progression->GetRunState(), EJMPrototypeRunState::AwaitingQuest);
	TestFalse(TEXT("Quest cannot be submitted twice"), Progression->SubmitQuest(Inventory, QuestItem, 3).bSucceeded);

	const FJMPrototypeOperationResult CookingResult = Progression->CookAndSell(Inventory, Ingredient);
	TestTrue(TEXT("Ingredient can be cooked and sold"), CookingResult.bSucceeded);
	TestFalse(TEXT("Cooking provides visible feedback"), CookingResult.Message.IsEmpty());
	TestEqual(TEXT("Cooking raises currency to eighty"), Progression->GetCurrency(), 80);
	const FJMPrototypeOperationResult UpgradeResult = Progression->PurchaseInventoryUpgrade(Inventory);
	TestTrue(TEXT("Inventory upgrade can be purchased"), UpgradeResult.bSucceeded);
	TestFalse(TEXT("Upgrade provides visible feedback"), UpgradeResult.Message.IsEmpty());
	TestTrue(TEXT("Upgrade ownership is recorded"), Progression->HasInventoryUpgrade());
	TestEqual(TEXT("Upgrade expands inventory to six slots"), Inventory->GetMaxInventorySlots(), 6);
	TestEqual(TEXT("Upgrade spends all prototype currency"), Progression->GetCurrency(), 0);
	TestFalse(TEXT("Upgrade cannot be purchased twice"), Progression->PurchaseInventoryUpgrade(Inventory).bSucceeded);
	TestTrue(TEXT("Second quest can be accepted"), Progression->AcceptQuest().bSucceeded);
	TestEqual(TEXT("Second quest becomes active"), Progression->GetActiveQuestIndex(), 1);
	TestTrue(TEXT("Second quest items can already be owned at the base"), Inventory->AddItem(Ingredient, 2));
	const FJMPrototypeOperationResult SecondSubmit = Progression->SubmitQuest(Inventory, Ingredient, 2, 90, 1);
	TestTrue(TEXT("Second quest succeeds without a dungeon return requirement"), SecondSubmit.bSucceeded);
	TestEqual(TEXT("Second quest grants its reward"), Progression->GetCurrency(), 90);
	TestFalse(TEXT("Second completion clears the active quest"), Progression->HasActiveQuest());
	TestFalse(TEXT("No third prototype quest is offered"), Progression->AcceptQuest().bSucceeded);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypeCheckpointBoundaryTest,
	"JM.Prototype.Progression.InventoryCheckpointBoundary",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeCheckpointBoundaryTest::RunTest(const FString& Parameters)
{
	TestEqual(TEXT("Prototype defaults include test currency"), FJMPrototypeConfig().InitialCurrency, 80);
	TestTrue(TEXT("Dungeon to base is a checkpoint transition"),
		UJMPrototypeProgressionSubsystem::IsBaseReturnCheckpointTransition(
			TEXT("/Game/Level/Level_Mapgenerate"), TEXT("/Game/Prototype/Maps/Level_Prototype")));
	TestTrue(TEXT("PIE-prefixed dungeon to base is recognized"),
		UJMPrototypeProgressionSubsystem::IsBaseReturnCheckpointTransition(
			TEXT("/Game/Level/UEDPIE_12_Level_Mapgenerate"), TEXT("/Game/Prototype/Maps/UEDPIE_12_Level_Prototype?game=Test")));
	TestFalse(TEXT("Base to dungeon never checkpoints"),
		UJMPrototypeProgressionSubsystem::IsBaseReturnCheckpointTransition(
			TEXT("Level_Prototype"), TEXT("Level_Mapgenerate")));
	TestFalse(TEXT("Similar test map names never checkpoint"),
		UJMPrototypeProgressionSubsystem::IsBaseReturnCheckpointTransition(
			TEXT("Level_Mapgenerate_CycleTest"), TEXT("Level_Prototype")));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FJMPrototypeInventoryCheckpointSerializationTest,
	"JM.Prototype.Progression.InventoryCheckpointSerialization",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FJMPrototypeInventoryCheckpointSerializationTest::RunTest(const FString& Parameters)
{
	const FString TestSlot = TEXT("JMPrototype_Automation_InventoryCheckpoint");
	UGameplayStatics::DeleteGameInSlot(TestSlot, 0);

	UJMPrototypeInventorySaveGame* SaveObject = Cast<UJMPrototypeInventorySaveGame>(
		UGameplayStatics::CreateSaveGameObject(UJMPrototypeInventorySaveGame::StaticClass()));
	TestNotNull(TEXT("Checkpoint save object is created"), SaveObject);
	if (!SaveObject)
	{
		return false;
	}
	SaveObject->InventoryCapacity = 6;
	SaveObject->SaveVersion = 2;
	SaveObject->Currency = 80;
	SaveObject->bInventoryUpgradePurchased = true;
	SaveObject->RunState = EJMPrototypeRunState::QuestCompleted;
	SaveObject->ActiveQuestIndex = 1;
	SaveObject->CompletedQuestCount = 1;
	FJMPrototypeSavedInventoryEntry& Entry = SaveObject->Items.AddDefaulted_GetRef();
	Entry.ItemDefinition = TSoftObjectPtr<UInventoryItemDefinition>(
		FSoftObjectPath(TEXT("/Game/Prototype/Data/Items/DA_Item_SlimeSample.DA_Item_SlimeSample")));
	Entry.Quantity = 3;

	TestTrue(TEXT("Checkpoint is written to disk"), UGameplayStatics::SaveGameToSlot(SaveObject, TestSlot, 0));
	UJMPrototypeInventorySaveGame* Loaded = Cast<UJMPrototypeInventorySaveGame>(
		UGameplayStatics::LoadGameFromSlot(TestSlot, 0));
	TestNotNull(TEXT("Checkpoint is loaded from disk"), Loaded);
	if (Loaded)
	{
		TestEqual(TEXT("Saved inventory capacity survives serialization"), Loaded->InventoryCapacity, 6);
		TestEqual(TEXT("Saved currency survives serialization"), Loaded->Currency, 80);
		TestTrue(TEXT("Saved upgrade ownership survives serialization"), Loaded->bInventoryUpgradePurchased);
		TestEqual(TEXT("Saved run state survives serialization"), Loaded->RunState, EJMPrototypeRunState::QuestCompleted);
		TestEqual(TEXT("Saved active quest survives serialization"), Loaded->ActiveQuestIndex, 1);
		TestEqual(TEXT("Saved completed quest count survives serialization"), Loaded->CompletedQuestCount, 1);
		TestEqual(TEXT("Saved entry count survives serialization"), Loaded->Items.Num(), 1);
		if (Loaded->Items.Num() == 1)
		{
			TestEqual(TEXT("Saved item quantity survives serialization"), Loaded->Items[0].Quantity, 3);
			TestEqual(TEXT("Saved item asset path survives serialization"),
				Loaded->Items[0].ItemDefinition.ToSoftObjectPath().ToString(),
				FString(TEXT("/Game/Prototype/Data/Items/DA_Item_SlimeSample.DA_Item_SlimeSample")));
		}
	}
	TestTrue(TEXT("Automation checkpoint is cleaned up"), UGameplayStatics::DeleteGameInSlot(TestSlot, 0));
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

	FJMPrototypeConfig ValidConfig;
	ValidConfig.InitialCurrency = 0;
	TestTrue(TEXT("Valid configuration succeeds"), Progression->ConfigurePrototype(ValidConfig).bSucceeded);
	TestFalse(TEXT("Dungeon cannot be entered before quest acceptance"), Progression->EnterDungeon().bSucceeded);
	TestFalse(TEXT("Missing inventory cannot be upgraded"), Progression->PurchaseInventoryUpgrade(nullptr).bSucceeded);
	TestEqual(TEXT("Failed operations do not change currency"), Progression->GetCurrency(), 0);
	TestEqual(TEXT("Failed operations keep initial state"), Progression->GetRunState(), EJMPrototypeRunState::AwaitingQuest);
	return true;
}

#endif
