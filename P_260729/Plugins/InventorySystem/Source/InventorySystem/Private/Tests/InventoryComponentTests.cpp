#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Components/InventoryUIComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Items/InventoryItemDefinition.h"
#include "Tests/InventorySafetyTestTypes.h"
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
	FInventoryRuntimeCapacityTest,
	"InventorySystem.Component.RuntimeCapacityPreservesContents",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryRuntimeCapacityTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	UInventoryItemDefinition* First = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* Second = NewObject<UInventoryItemDefinition>();
	Inventory->MaxInventorySlots = 2;
	First->ItemId = TEXT("Automation.Capacity.First");
	Second->ItemId = TEXT("Automation.Capacity.Second");

	TestTrue(TEXT("First item added"), Inventory->AddItem(First));
	TestTrue(TEXT("Second item added"), Inventory->AddItem(Second));
	TestEqual(
		TEXT("Expansion succeeds"),
		Inventory->ExpandInventorySlots(2),
		EInventoryCapacityChangeResult::Success);
	TestEqual(TEXT("Capacity expands to four"), Inventory->GetMaxInventorySlots(), 4);
	TestTrue(TEXT("First item survives expansion"), Inventory->HasItem(First));
	TestTrue(TEXT("Second item survives expansion"), Inventory->HasItem(Second));

	TestEqual(
		TEXT("Unsafe shrink is rejected"),
		Inventory->SetMaxInventorySlots(1),
		EInventoryCapacityChangeResult::OccupiedSlotsExceedCapacity);
	TestEqual(TEXT("Rejected shrink preserves capacity"), Inventory->GetMaxInventorySlots(), 4);
	TestEqual(
		TEXT("Invalid expansion is rejected"),
		Inventory->ExpandInventorySlots(0),
		EInventoryCapacityChangeResult::InvalidCapacity);

	TestTrue(TEXT("One item can be removed"), Inventory->RemoveItem(Second));
	TestEqual(
		TEXT("Safe shrink succeeds"),
		Inventory->SetMaxInventorySlots(1),
		EInventoryCapacityChangeResult::Success);
	TestEqual(TEXT("Capacity shrinks to one"), Inventory->GetMaxInventorySlots(), 1);
	TestTrue(TEXT("Remaining item survives shrink"), Inventory->HasItem(First));
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

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventorySortConsolidationTest,
	"InventorySystem.Component.SortConsolidatesMatchingItemIds",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventorySortConsolidationTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	Inventory->MaxInventorySlots = 4;
	UInventoryItemDefinition* FirstDefinition = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* SecondDefinition = NewObject<UInventoryItemDefinition>();
	FirstDefinition->ItemId = TEXT("Automation.SharedId");
	SecondDefinition->ItemId = TEXT("Automation.SharedId");
	FirstDefinition->bStackable = SecondDefinition->bStackable = true;
	FirstDefinition->MaxStackSize = SecondDefinition->MaxStackSize = 10;

	TestTrue(TEXT("First logical stack added"), Inventory->AddItem(FirstDefinition, 4));
	TestTrue(TEXT("Second logical stack added"), Inventory->AddItem(SecondDefinition, 3));
	TestEqual(TEXT("Definitions initially occupy separate slots"), Inventory->GetOccupiedSlotCount(), 2);

	Inventory->SortItemsByQuantityDescending();
	FInventorySlot Slot;
	TestTrue(TEXT("Consolidated slot remains valid"), Inventory->GetSlot(0, Slot));
	TestEqual(TEXT("Matching ItemId quantities merge"), Slot.Quantity, 7);
	TestEqual(TEXT("Only one slot remains occupied"), Inventory->GetOccupiedSlotCount(), 1);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryLayoutOperationsTest,
	"InventorySystem.Component.LayoutOperations",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryLayoutOperationsTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	Inventory->MaxInventorySlots = 4;
	UInventoryItemDefinition* Two = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* Five = NewObject<UInventoryItemDefinition>();
	UInventoryItemDefinition* Three = NewObject<UInventoryItemDefinition>();
	Two->ItemId = TEXT("Automation.QuantityTwo");
	Five->ItemId = TEXT("Automation.QuantityFive");
	Three->ItemId = TEXT("Automation.QuantityThree");
	Two->MaxStackSize = Five->MaxStackSize = Three->MaxStackSize = 99;
	Two->bStackable = Five->bStackable = Three->bStackable = true;
	TestTrue(TEXT("Quantity-two stack added"), Inventory->AddItem(Two, 2));
	TestTrue(TEXT("Quantity-five stack added"), Inventory->AddItem(Five, 5));
	TestTrue(TEXT("Quantity-three stack added"), Inventory->AddItem(Three, 3));

	Inventory->SortItemsByQuantityDescending();
	FInventorySlot Slot;
	TestTrue(TEXT("Sorted first slot is occupied"), Inventory->GetSlot(0, Slot));
	TestEqual(TEXT("Largest stack sorts first"), Slot.Quantity, 5);
	TestTrue(TEXT("Sorted second slot is occupied"), Inventory->GetSlot(1, Slot));
	TestEqual(TEXT("Middle stack sorts second"), Slot.Quantity, 3);
	TestTrue(TEXT("Sorted third slot is occupied"), Inventory->GetSlot(2, Slot));
	TestEqual(TEXT("Smallest stack sorts third"), Slot.Quantity, 2);

	const FGuid MovedInstanceId = Inventory->GetSlotsNative()[0].InstanceId;
	TestEqual(
		TEXT("Stack moves into an empty grid cell"),
		Inventory->MoveItemToEmptySlot(0, 3),
		EInventoryOperationResult::Success);
	TestFalse(TEXT("Source slot becomes empty"), Inventory->GetSlot(0, Slot));
	TestTrue(TEXT("Destination slot becomes occupied"), Inventory->GetSlot(3, Slot));
	TestEqual(TEXT("Move preserves stack identity"), Slot.InstanceId, MovedInstanceId);
	TestEqual(TEXT("Move preserves quantity"), Slot.Quantity, 5);

	const FInventorySlot DestinationBeforeFailure = Inventory->GetSlotsNative()[2];
	TestEqual(
		TEXT("Occupied destination rejects a move"),
		Inventory->MoveItemToEmptySlot(3, 2),
		EInventoryOperationResult::NotAllowed);
	TestEqual(
		TEXT("Rejected move preserves destination identity"),
		Inventory->GetSlotsNative()[2].InstanceId,
		DestinationBeforeFailure.InstanceId);
	TestEqual(
		TEXT("Rejected move preserves source identity"),
		Inventory->GetSlotsNative()[3].InstanceId,
		MovedInstanceId);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryUseReentrancyIdentityTest,
	"InventorySystem.Component.UseReentrancyPreservesInstanceIdentity",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryUseReentrancyIdentityTest::RunTest(const FString& Parameters)
{
	for (int32 Action = 1; Action <= 4; ++Action)
	{
		UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
		Inventory->MaxInventorySlots = 4;
		UInventoryItemDefinition* Consumable = NewObject<UInventoryItemDefinition>();
		Consumable->ItemId = TEXT("Automation.Consumable");
		Consumable->bCanUse = true;
		Consumable->bConsumeOnUse = true;
		Consumable->ConsumeQuantity = 1;
		Consumable->bStackable = true;
		Consumable->MaxStackSize = 10;
		Consumable->UseEffect = NewObject<UInventoryAlwaysSucceedsUseEffect>(Consumable);
		UInventoryItemDefinition* Other = NewObject<UInventoryItemDefinition>();
		Other->ItemId = TEXT("Automation.Other");
		Other->bStackable = true;
		Other->MaxStackSize = 10;

		TestTrue(TEXT("Consumable stack is added"), Inventory->AddItem(Consumable, 2));
		TestTrue(TEXT("Other stack is added"), Inventory->AddItem(Other, 5));
		const FGuid OriginalInstanceId = Inventory->GetSlotsNative()[0].InstanceId;
		const FGuid OtherInstanceId = Inventory->GetSlotsNative()[1].InstanceId;

		UInventoryUseReentrancyReceiver* Receiver = NewObject<UInventoryUseReentrancyReceiver>();
		Receiver->Inventory = Inventory;
		Receiver->Action = Action;
		Inventory->OnItemUsed.AddDynamic(Receiver, &UInventoryUseReentrancyReceiver::HandleItemUsed);
		TestEqual(TEXT("Use succeeds across listener mutation"), Inventory->UseItemAtSlot(0), EInventoryOperationResult::Success);

		int32 OriginalQuantity = 0;
		int32 OtherQuantity = 0;
		for (const FInventorySlot& Slot : Inventory->GetSlotsNative())
		{
			if (Slot.InstanceId == OriginalInstanceId)
			{
				OriginalQuantity = Slot.Quantity;
			}
			if (Slot.InstanceId == OtherInstanceId)
			{
				OtherQuantity = Slot.Quantity;
			}
		}
		if (Action <= 2)
		{
			TestEqual(TEXT("Only the original moved/sorted instance is consumed"), OriginalQuantity, 1);
		}
		else
		{
			TestEqual(TEXT("A listener-removed original instance is not consumed again"), OriginalQuantity, 0);
		}
		TestEqual(TEXT("The other item is never consumed"), OtherQuantity, 5);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryAddTransactionBoundaryTest,
	"InventorySystem.Component.AddTransactionCommitsBeforeNotifications",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryAddTransactionBoundaryTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	Inventory->MaxInventorySlots = 3;
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	Definition->ItemId = TEXT("Automation.Transaction");
	Definition->bStackable = true;
	Definition->MaxStackSize = 2;
	UInventoryUseReentrancyReceiver* Receiver = NewObject<UInventoryUseReentrancyReceiver>();
	Receiver->Inventory = Inventory;
	Inventory->OnItemAdded.AddDynamic(Receiver, &UInventoryUseReentrancyReceiver::HandleItemAdded);

	const FInventoryAddOutcome Outcome = Inventory->AddItemDetailed(Definition, 5);
	TestEqual(TEXT("All requested items are committed"), Outcome.AddedQuantity, 5);
	TestEqual(TEXT("Per-stack notifications are retained"), Receiver->AddedCallbackCount, 3);
	TestEqual(TEXT("Every listener observes the fully committed transaction"), Receiver->MinimumObservedTotal, 5);
	TestEqual(TEXT("Listener layout mutation does not corrupt the outcome"), Inventory->GetItemQuantity(Definition), 5);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryEnhancedInputRebindTest,
	"InventorySystem.UI.EnhancedInputRebindOwnsOnlyCurrentBinding",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryEnhancedInputRebindTest::RunTest(const FString& Parameters)
{
	UInventoryUIComponent* UI = NewObject<UInventoryUIComponent>();
	UInputAction* Action = NewObject<UInputAction>();
	UEnhancedInputComponent* First = NewObject<UEnhancedInputComponent>();
	UEnhancedInputComponent* Second = NewObject<UEnhancedInputComponent>();
	UI->ToggleInventoryAction = Action;

	TestTrue(TEXT("First Enhanced Input component binds"), UI->BindEnhancedInput(First));
	TestEqual(TEXT("First component owns one binding"), First->GetActionEventBindings().Num(), 1);
	TestTrue(TEXT("Second Enhanced Input component rebinds"), UI->BindEnhancedInput(Second));
	TestEqual(TEXT("Old component binding is removed"), First->GetActionEventBindings().Num(), 0);
	TestEqual(TEXT("New component owns one binding"), Second->GetActionEventBindings().Num(), 1);
	return true;
}

#endif
