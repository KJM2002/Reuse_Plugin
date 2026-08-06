#include "UI/InventoryQuantityDialogWidgetBase.h"

#include "Blueprint/WidgetTree.h"
#include "Brushes/SlateRoundedBoxBrush.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "InputCoreTypes.h"

UInventoryQuantityDialogWidgetBase::UInventoryQuantityDialogWidgetBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsFocusable(true);
	TitleText = NSLOCTEXT("InventorySystem", "DropQuantityTitle", "버릴 수량");
	QuantityTextFormat = NSLOCTEXT("InventorySystem", "QuantityFormat", "{0} / {1}");
	AllButtonText = NSLOCTEXT("InventorySystem", "QuantityAll", "전부");
	ConfirmButtonText = NSLOCTEXT("InventorySystem", "QuantityConfirm", "확인");
	CancelButtonText = NSLOCTEXT("InventorySystem", "QuantityCancel", "취소");
}

void UInventoryQuantityDialogWidgetBase::BuildDefaultWidgetTreeIfNeeded()
{
	if (!WidgetTree || WidgetTree->RootWidget)
	{
		return;
	}

	Border_Dialog = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Border_Dialog"));
	Border_Dialog->SetBrush(FSlateRoundedBoxBrush(
		FLinearColor(0.025f, 0.075f, 0.125f, 0.98f),
		12.0f,
		FLinearColor(0.12f, 0.78f, 0.74f, 0.95f),
		1.5f));
	Border_Dialog->SetPadding(FMargin(18.0f));
	WidgetTree->RootWidget = Border_Dialog;

	UVerticalBox* Layout = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("VerticalBox_QuantityDialog"));
	Border_Dialog->SetContent(Layout);

	UTextBlock* Title = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Title"));
	Title->SetText(TitleText);
	FSlateFontInfo TitleFont = Title->GetFont();
	TitleFont.Size = 18;
	Title->SetFont(TitleFont);
	Title->SetJustification(ETextJustify::Center);
	if (UVerticalBoxSlot* TitleSlot = Layout->AddChildToVerticalBox(Title))
	{
		TitleSlot->SetPadding(FMargin(0.0f, 0.0f, 0.0f, 12.0f));
	}

	UHorizontalBox* QuantityRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HorizontalBox_Quantity"));
	Layout->AddChildToVerticalBox(QuantityRow);

	auto MakeButton = [this](const FName Name, const FText& Label, UButton*& OutButton)
	{
		OutButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), Name);
		UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), *(Name.ToString() + TEXT("_Label")));
		Text->SetText(Label);
		Text->SetJustification(ETextJustify::Center);
		OutButton->AddChild(Text);
	};

	UButton* Decrease = nullptr;
	MakeButton(TEXT("Button_Decrease"), FText::FromString(TEXT("-")), Decrease);
	Button_Decrease = Decrease;
	QuantityRow->AddChildToHorizontalBox(Button_Decrease);

	Text_Quantity = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Text_Quantity"));
	Text_Quantity->SetJustification(ETextJustify::Center);
	if (UHorizontalBoxSlot* QuantitySlot = QuantityRow->AddChildToHorizontalBox(Text_Quantity))
	{
		QuantitySlot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
		QuantitySlot->SetVerticalAlignment(VAlign_Center);
		QuantitySlot->SetPadding(FMargin(18.0f, 6.0f));
	}

	UButton* Increase = nullptr;
	MakeButton(TEXT("Button_Increase"), FText::FromString(TEXT("+")), Increase);
	Button_Increase = Increase;
	QuantityRow->AddChildToHorizontalBox(Button_Increase);

	UHorizontalBox* ActionRow = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HorizontalBox_Actions"));
	if (UVerticalBoxSlot* ActionSlot = Layout->AddChildToVerticalBox(ActionRow))
	{
		ActionSlot->SetPadding(FMargin(0.0f, 12.0f, 0.0f, 0.0f));
	}

	UButton* All = nullptr;
	MakeButton(TEXT("Button_All"), AllButtonText, All);
	Button_All = All;
	ActionRow->AddChildToHorizontalBox(Button_All);
	UButton* Confirm = nullptr;
	MakeButton(TEXT("Button_Confirm"), ConfirmButtonText, Confirm);
	Button_Confirm = Confirm;
	ActionRow->AddChildToHorizontalBox(Button_Confirm);
	UButton* Cancel = nullptr;
	MakeButton(TEXT("Button_Cancel"), CancelButtonText, Cancel);
	Button_Cancel = Cancel;
	ActionRow->AddChildToHorizontalBox(Button_Cancel);

	for (int32 Index = 0; Index < ActionRow->GetChildrenCount(); ++Index)
	{
		if (UHorizontalBoxSlot* ActionButtonSlot = Cast<UHorizontalBoxSlot>(ActionRow->GetChildAt(Index)->Slot))
		{
			ActionButtonSlot->SetPadding(FMargin(Index == 0 ? 0.0f : 6.0f, 0.0f));
		}
	}
}

void UInventoryQuantityDialogWidgetBase::NativePreConstruct()
{
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativePreConstruct();
	RefreshQuantityText();
}

void UInventoryQuantityDialogWidgetBase::NativeOnInitialized()
{
	BuildDefaultWidgetTreeIfNeeded();
	Super::NativeOnInitialized();
	if (Button_Decrease) Button_Decrease->OnClicked.AddUniqueDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleDecreaseClicked);
	if (Button_Increase) Button_Increase->OnClicked.AddUniqueDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleIncreaseClicked);
	if (Button_All) Button_All->OnClicked.AddUniqueDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleAllClicked);
	if (Button_Confirm) Button_Confirm->OnClicked.AddUniqueDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleConfirmClicked);
	if (Button_Cancel) Button_Cancel->OnClicked.AddUniqueDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleCancelClicked);
}

void UInventoryQuantityDialogWidgetBase::NativeDestruct()
{
	if (Button_Decrease) Button_Decrease->OnClicked.RemoveDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleDecreaseClicked);
	if (Button_Increase) Button_Increase->OnClicked.RemoveDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleIncreaseClicked);
	if (Button_All) Button_All->OnClicked.RemoveDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleAllClicked);
	if (Button_Confirm) Button_Confirm->OnClicked.RemoveDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleConfirmClicked);
	if (Button_Cancel) Button_Cancel->OnClicked.RemoveDynamic(this, &UInventoryQuantityDialogWidgetBase::HandleCancelClicked);
	Super::NativeDestruct();
}

void UInventoryQuantityDialogWidgetBase::ShowQuantityPicker(int32 InMaximumQuantity, int32 InInitialQuantity)
{
	MaximumQuantity = FMath::Max(1, InMaximumQuantity);
	CurrentQuantity = FMath::Clamp(InInitialQuantity, 1, MaximumQuantity);
	RefreshQuantityText();
	SetVisibility(ESlateVisibility::Visible);
	SetKeyboardFocus();
}

void UInventoryQuantityDialogWidgetBase::SetQuantity(int32 InQuantity)
{
	CurrentQuantity = FMath::Clamp(InQuantity, 1, FMath::Max(1, MaximumQuantity));
	RefreshQuantityText();
}

void UInventoryQuantityDialogWidgetBase::RefreshQuantityText()
{
	if (Text_Quantity)
	{
		Text_Quantity->SetText(FText::Format(
			QuantityTextFormat,
			FText::AsNumber(CurrentQuantity),
			FText::AsNumber(MaximumQuantity)));
	}
}

void UInventoryQuantityDialogWidgetBase::HandleDecreaseClicked() { SetQuantity(CurrentQuantity - 1); }
void UInventoryQuantityDialogWidgetBase::HandleIncreaseClicked() { SetQuantity(CurrentQuantity + 1); }
void UInventoryQuantityDialogWidgetBase::HandleAllClicked() { SetQuantity(MaximumQuantity); }
void UInventoryQuantityDialogWidgetBase::HandleConfirmClicked() { OnConfirmed.Broadcast(CurrentQuantity); }
void UInventoryQuantityDialogWidgetBase::HandleCancelClicked() { OnCancelled.Broadcast(); }

FReply UInventoryQuantityDialogWidgetBase::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::Left) { HandleDecreaseClicked(); return FReply::Handled(); }
	if (InKeyEvent.GetKey() == EKeys::Right) { HandleIncreaseClicked(); return FReply::Handled(); }
	if (InKeyEvent.GetKey() == EKeys::Enter) { HandleConfirmClicked(); return FReply::Handled(); }
	if (InKeyEvent.GetKey() == EKeys::Escape) { HandleCancelClicked(); return FReply::Handled(); }
	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}
