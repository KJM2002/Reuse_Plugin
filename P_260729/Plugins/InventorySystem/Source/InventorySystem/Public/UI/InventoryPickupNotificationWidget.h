#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryPickupNotificationWidget.generated.h"

class STextBlock;
class UImage;
class USizeBox;
class UTextBlock;
class UTexture2D;

/** Widget Blueprint 없이도 사용할 수 있는 기본 아이템 획득 알림이다. */
UCLASS(BlueprintType, Blueprintable)
class INVENTORYSYSTEM_API UInventoryPickupNotificationWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory|Notification")
	void ShowNotification(const FText& InMessage, float InDuration = 2.0f);

	/** 아이템 아이콘과 문구를 함께 표시한다. */
	UFUNCTION(BlueprintCallable, Category = "Inventory|Notification")
	void ShowItemNotification(const FText& InMessage, UTexture2D* InIcon, float InDuration = 2.0f);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	/**
	 * Widget Blueprint에서 알림 문구를 표시할 TextBlock.
	 * WBP 자식 위젯에서는 TextBlock 이름을 정확히 Text_Message로 만들고
	 * Is Variable을 체크한다. 위젯이 없으면 C++ 기본 Slate 알림을 사용한다.
	 */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|Notification")
	TObjectPtr<UTextBlock> Text_Message = nullptr;

	/** WBP의 아이템 아이콘. 위젯 이름을 정확히 Image_ItemIcon으로 만든다. */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|Notification")
	TObjectPtr<UImage> Image_ItemIcon = nullptr;

	/** 아이콘이 없는 아이템일 때 빈 공간까지 숨기기 위한 선택 위젯. */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Inventory|Notification")
	TObjectPtr<USizeBox> SizeBox_Icon = nullptr;

	/** Widget Blueprint에서 등장 애니메이션 등을 실행할 때 사용한다. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory|Notification", meta = (DisplayName = "On Notification Shown"))
	void BP_OnNotificationShown(const FText& InMessage, float InDuration);

private:
	void HandleExpired();

	FText Message;
	TSharedPtr<STextBlock> MessageTextBlock;
	FTimerHandle ExpireTimerHandle;
};
