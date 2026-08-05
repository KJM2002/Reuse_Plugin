#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

#include "Components/InventoryComponent.h"
#include "Items/InventoryItemDefinition.h"
#include "UI/InventoryContextMenuWidgetBase.h"
#include "UI/InventoryDuckovWidgetBase.h"
#include "UI/InventoryTooltipWidgetBase.h"
#include "UI/InventoryUIPresentationTypes.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryUIPresentationFormattingTest,
	"InventorySystem.UI.Presentation.Formatting",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryUIPresentationFormattingTest::RunTest(const FString& Parameters)
{
	TestFalse(TEXT("Quantity one is hidden"), FInventoryUIPresentationUtils::ShouldShowQuantity(1));
	TestTrue(TEXT("Quantity two is shown"), FInventoryUIPresentationUtils::ShouldShowQuantity(2));
	TestTrue(TEXT("Quantity one text is empty"), FInventoryUIPresentationUtils::FormatQuantityText(1).IsEmpty());
	TestEqual(TEXT("Quantity text uses x prefix"), FInventoryUIPresentationUtils::FormatQuantityText(12).ToString(), FString(TEXT("x12")));
	TestEqual(TEXT("Capacity text is stable"), FInventoryUIPresentationUtils::FormatCapacityText(9, 20).ToString(), FString(TEXT("9 / 20")));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryUIContextActionsTest,
	"InventorySystem.UI.Presentation.ContextActions",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryUIContextActionsTest::RunTest(const FString& Parameters)
{
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	Definition->ItemId = TEXT("Automation.ContextItem");
	Definition->DisplayName = FText::FromString(TEXT("Context Item"));
	Definition->bCanUse = true;
	Definition->bCanDrop = true;
	Definition->bCanInspect = true;

	FInventorySlot Slot;
	Slot.ItemDefinition = Definition;
	Slot.Quantity = 3;
	Slot.InstanceId = FGuid::NewGuid();
	const FInventorySlotViewData Data = FInventoryUIPresentationUtils::MakeSlotViewData(Slot, 4);
	TestTrue(TEXT("Valid slot produces valid view data"), Data.IsValid());
	TestEqual(TEXT("View data preserves slot index"), Data.SlotIndex, 4);
	TestEqual(TEXT("View data preserves name"), Data.DisplayName.ToString(), FString(TEXT("Context Item")));

	TArray<FInventoryContextAction> Actions = FInventoryUIPresentationUtils::BuildContextActions(Data);
	TestEqual(TEXT("Use and Drop are available without inspection assets"), Actions.Num(), 2);
	TestEqual(TEXT("First action is Use"), Actions[0].ActionId, EInventoryContextActionId::Use);
	TestEqual(TEXT("Second action is Drop"), Actions[1].ActionId, EInventoryContextActionId::Drop);
	Definition->bCanUse = false;
	Definition->CannotUseReason = FText::FromString(TEXT("Cannot use here"));
	const FInventorySlotViewData DisabledData = FInventoryUIPresentationUtils::MakeSlotViewData(Slot, 4);
	TestEqual(
		TEXT("Unavailable reason is copied only for non-usable items"),
		DisabledData.CannotUseReason.ToString(),
		FString(TEXT("Cannot use here")));
	Definition->bCanUse = true;

	Definition->InspectMesh = TSoftObjectPtr<UStaticMesh>(FSoftObjectPath(TEXT("/InventorySystem/Tests/SM_Test.SM_Test")));
	Definition->InspectorData = TSoftObjectPtr<UPrimaryDataAsset>(FSoftObjectPath(TEXT("/InventorySystem/Tests/DA_Test.DA_Test")));
	Actions = FInventoryUIPresentationUtils::BuildContextActions(Data);
	TestEqual(TEXT("Inspect appears only when both inspection references exist"), Actions.Num(), 3);
	TestEqual(TEXT("Third action is Inspect"), Actions[2].ActionId, EInventoryContextActionId::Inspect);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryUIPresentationIdentityAndClampTest,
	"InventorySystem.UI.Presentation.IdentityAndClamp",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryUIPresentationIdentityAndClampTest::RunTest(const FString& Parameters)
{
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	Definition->ItemId = TEXT("Automation.IdentityItem");
	const FGuid FirstId = FGuid::NewGuid();
	const FGuid SecondId = FGuid::NewGuid();

	TArray<FInventorySlot> Slots;
	Slots.SetNum(3);
	Slots[0].ItemDefinition = Definition;
	Slots[0].Quantity = 1;
	Slots[0].InstanceId = FirstId;
	Slots[2].ItemDefinition = Definition;
	Slots[2].Quantity = 1;
	Slots[2].InstanceId = SecondId;

	TestEqual(TEXT("Instance lookup finds moved stack"), FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(Slots, SecondId), 2);
	TestEqual(TEXT("Invalid instance is rejected"), FInventoryUIPresentationUtils::FindSlotIndexByInstanceId(Slots, FGuid()), INDEX_NONE);

	const FVector2D Clamped = FInventoryUIPresentationUtils::ClampPopupPosition(
		FVector2D(950.0f, 760.0f),
		FVector2D(200.0f, 180.0f),
		FVector2D(1000.0f, 800.0f),
		8.0f);
	TestEqual(TEXT("Popup clamps on right edge"), Clamped.X, 792.0);
	TestEqual(TEXT("Popup clamps on bottom edge"), Clamped.Y, 612.0);
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInventoryUIDuckovNullSafeLifecycleTest,
	"InventorySystem.UI.Duckov.NullSafeLifecycle",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FInventoryUIDuckovNullSafeLifecycleTest::RunTest(const FString& Parameters)
{
	UInventoryComponent* Inventory = NewObject<UInventoryComponent>();
	UInventoryItemDefinition* Definition = NewObject<UInventoryItemDefinition>();
	Definition->ItemId = TEXT("Automation.NullSafeItem");
	Definition->DisplayName = FText::FromString(TEXT("Null Safe Item"));
	Definition->bCanDrop = true;
	Inventory->MaxInventorySlots = 2;
	TestTrue(TEXT("Test item is added"), Inventory->AddItem(Definition));

	UInventoryDuckovWidgetBase* DuckovWidget = NewObject<UInventoryDuckovWidgetBase>();
	// Simulate an older WBP asset whose serialized value predates the Duckov 5-column layout.
	DuckovWidget->GridColumnCount = 4;
	DuckovWidget->bShowEmptySlots = false;
	DuckovWidget->InitializeInventory(Inventory, nullptr);
	TestEqual(TEXT("Duckov layout is fixed before the initial refresh"), DuckovWidget->GridColumnCount, 5);
	TestTrue(TEXT("Duckov layout always includes capacity slots"), DuckovWidget->bShowEmptySlots);
	TestEqual(TEXT("Duckov widget preserves base selection recovery"), DuckovWidget->GetSelectedSlotIndex(), 0);
	DuckovWidget->RefreshInventory();
	TestEqual(TEXT("Duckov layout remains fixed after refresh"), DuckovWidget->GridColumnCount, 5);
	DuckovWidget->BeginInspectTransition();
	DuckovWidget->BeginCloseTransition();
	DuckovWidget->CloseTransientWidgets();

	FInventorySlot Slot;
	TestTrue(TEXT("Inventory slot remains owned by InventoryComponent"), Inventory->GetSlot(0, Slot));
	const FInventorySlotViewData ViewData = FInventoryUIPresentationUtils::MakeSlotViewData(Slot, 0);

	UInventoryTooltipWidgetBase* Tooltip = NewObject<UInventoryTooltipWidgetBase>();
	Tooltip->SetTooltipData(ViewData);
	Tooltip->ClearTooltipData();
	TestFalse(TEXT("Tooltip clears copied data without a Widget Tree"), Tooltip->GetTooltipData().IsValid());

	UInventoryContextMenuWidgetBase* ContextMenu = NewObject<UInventoryContextMenuWidgetBase>();
	TestFalse(
		TEXT("Context menu safely rejects a missing action container"),
		ContextMenu->SetMenuData(ViewData, FInventoryUIPresentationUtils::BuildContextActions(ViewData)));
	ContextMenu->ClearMenu();
	return true;
}

#endif
