#include "UI/InventoryPickupNotificationWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Engine/World.h"
#include "Styling/CoreStyle.h"
#include "TimerManager.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

TSharedRef<SWidget> UInventoryPickupNotificationWidget::RebuildWidget()
{
	// Widget Blueprint 자식 클래스가 디자이너에서 만든 위젯 트리를 가지고 있으면
	// 그 구조를 사용한다. 순수 C++ 클래스로 생성된 경우에만 기본 Slate UI를 만든다.
	if (WidgetTree && WidgetTree->RootWidget)
	{
		return Super::RebuildWidget();
	}

	return SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.0f, 48.0f, 0.0f, 0.0f))
		[
			SNew(SBox)
			.WidthOverride(420.0f)
			.HeightOverride(54.0f)
			[
				SNew(SBorder)
				.Padding(FMargin(18.0f, 10.0f))
				.BorderBackgroundColor(FLinearColor(0.025f, 0.03f, 0.04f, 0.92f))
				[
					SAssignNew(MessageTextBlock, STextBlock)
					.Text(Message)
					.Justification(ETextJustify::Center)
					.Font(FCoreStyle::GetDefaultFontStyle(TEXT("Bold"), 18))
					.ColorAndOpacity(FLinearColor(0.92f, 0.92f, 0.92f, 1.0f))
				]
			]
		];
}

void UInventoryPickupNotificationWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MessageTextBlock.Reset();
}

void UInventoryPickupNotificationWidget::ShowNotification(const FText& InMessage, float InDuration)
{
	ShowItemNotification(InMessage, nullptr, InDuration);
}

void UInventoryPickupNotificationWidget::ShowItemNotification(const FText& InMessage, UTexture2D* InIcon, float InDuration)
{
	Message = InMessage;
	if (MessageTextBlock)
	{
		MessageTextBlock->SetText(Message);
	}
	if (Text_Message)
	{
		Text_Message->SetText(Message);
	}

	const bool bHasIcon = IsValid(InIcon);
	if (Image_ItemIcon)
	{
		if (bHasIcon)
		{
			Image_ItemIcon->SetBrushFromTexture(InIcon, true);
		}
		Image_ItemIcon->SetVisibility(bHasIcon ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
	}
	if (SizeBox_Icon)
	{
		SizeBox_Icon->SetVisibility(bHasIcon ? ESlateVisibility::HitTestInvisible : ESlateVisibility::Collapsed);
	}
	SetVisibility(ESlateVisibility::HitTestInvisible);
	BP_OnNotificationShown(Message, InDuration);

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(ExpireTimerHandle);
		World->GetTimerManager().SetTimer(ExpireTimerHandle, this, &UInventoryPickupNotificationWidget::HandleExpired, FMath::Max(0.1f, InDuration), false);
	}
}

void UInventoryPickupNotificationWidget::HandleExpired()
{
	RemoveFromParent();
}
