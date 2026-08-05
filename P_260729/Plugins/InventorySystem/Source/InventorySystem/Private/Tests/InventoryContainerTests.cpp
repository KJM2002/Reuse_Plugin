#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Components/InventoryContainerComponent.h"
#include "Items/InventoryItemDefinition.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryContainerTransferTest,
	"InventorySystem.Container.TransferSplitSwapAndWeight",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryContainerTransferTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Player = NewObject<UInventoryComponent>();
	UInventoryContainerComponent* Container = NewObject<UInventoryContainerComponent>();
	Player->MaxInventorySlots = 4;
	Container->MaxInventorySlots = 4;

	UInventoryItemDefinition* Ammo = NewObject<UInventoryItemDefinition>();
	Ammo->ItemId = TEXT("Test.Ammo");
	Ammo->bStackable = true;
	Ammo->MaxStackSize = 20;
	Ammo->Weight = 0.5f;
	UInventoryItemDefinition* Tool = NewObject<UInventoryItemDefinition>();
	Tool->ItemId = TEXT("Test.Tool");
	Tool->Weight = 2.0f;

	TestTrue(TEXT("Container starts with ammo"), Container->AddItem(Ammo, 10));
	TestEqual(TEXT("Double-click style auto transfer succeeds"), Container->MoveStack(Player, 0), EInventoryOperationResult::Success);
	TestEqual(TEXT("Player receives complete stack"), Player->GetItemQuantity(Ammo), 10);
	TestEqual(TEXT("Container source is empty"), Container->GetItemQuantity(Ammo), 0);

	TestTrue(TEXT("Second ammo stack can be seeded"), Container->AddItem(Ammo, 8));
	TestEqual(TEXT("Ctrl-drag style split succeeds"), Container->SplitStack(Player, 0, 3, 1), EInventoryOperationResult::Success);
	FInventorySlot Slot;
	TestTrue(TEXT("Split destination is occupied"), Player->GetSlot(1, Slot));
	TestEqual(TEXT("Split destination has requested quantity"), Slot.Quantity, 3);
	TestEqual(TEXT("Split leaves the remainder"), Container->GetItemQuantity(Ammo), 5);

	TestTrue(TEXT("Tool can be added to container"), Container->AddItem(Tool, 1));
	TestEqual(TEXT("Cross-inventory occupied slots swap"), Player->SwapItem(Container, 1, 1), EInventoryOperationResult::Success);
	TestTrue(TEXT("Player now owns tool"), Player->GetSlot(1, Slot));
	TestEqual(TEXT("Swapped player item is tool"), Slot.ItemDefinition.Get(), Tool);

	Player->MaxInventoryWeight = Player->GetCurrentWeight();
	TestFalse(TEXT("Weight limit rejects another item"), Player->CanAccept(Ammo, 1));
	return true;
}

#endif
