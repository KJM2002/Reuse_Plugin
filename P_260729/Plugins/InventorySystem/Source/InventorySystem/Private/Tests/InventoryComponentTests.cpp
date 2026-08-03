#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Items/InventoryItemDefinition.h"
#include "UI/InventoryWidgetBase.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryStackingTest,
	"InventorySystem.Component.StackingAndCapacity",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryStackingTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	Inventory->MaxInventorySlots = 2;
	Definition->ItemId = TEXT("Automation.Stackable");
	Definition->bStackable = true;
	Definition->MaxStackSize = 3;

	const FInventoryAddOutcome Outcome = Inventory->AddItemDetailed(Definition, 7);
	TestEqual(TEXT("Two slots accept six items"), Outcome.AddedQuantity, 6);
	TestEqual(TEXT("One item remains"), Outcome.RemainingQuantity, 1);
	TestEqual(TEXT("Result is partial success"), Outcome.Result, EInventoryAddResult::PartialSuccess);
	TestEqual(TEXT("Both slots are occupied"), Inventory->GetOccupiedSlotCount(), 2);
	TestEqual(TEXT("Quantity query sums stacks"), Inventory->GetItemQuantity(Definition), 6);
	TestTrue(TEXT("Atomic definition removal succeeds when enough items exist"), Inventory->RemoveItem(Definition, 4));
	TestEqual(TEXT("Removal updates quantity"), Inventory->GetItemQuantity(Definition), 2);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventorySelectionRecoveryTest,
	"InventorySystem.UI.SelectionRecovery",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventorySelectionRecoveryTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	UInventoryItemDefinition* First = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* Second = NewObject<UInventoryItemDefinition>();
	Inventory->MaxInventorySlots = 3;
	First->ItemId = TEXT("Automation.First");
	Second->ItemId = TEXT("Automation.Second");
	TestTrue(TEXT("First item added"), Inventory->AddItem(First));
	TestTrue(TEXT("Second item added"), Inventory->AddItem(Second));

	UInventoryWidgetBase* Widget = NewObject<UInventoryWidgetBase>();
	Widget->InitializeInventory(Inventory, nullptr);
	TestEqual(TEXT("Opening chooses the first valid item"), Widget->GetSelectedSlotIndex(), 0);

	TestEqual(
		TEXT("Removing selected item succeeds"),
		Inventory->RemoveItemAtSlot(0),
		EInventoryOperationResult::Success);
	TestEqual(TEXT("Selection safely advances to the remaining item"), Widget->GetSelectedSlotIndex(), 1);

	TestEqual(
		TEXT("Removing last item succeeds"),
		Inventory->RemoveItemAtSlot(1),
		EInventoryOperationResult::Success);
	TestEqual(TEXT("Empty inventory clears selection"), Widget->GetSelectedSlotIndex(), INDEX_NONE);
	return true;
}

#endif
