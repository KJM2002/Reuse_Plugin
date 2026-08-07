#pragma once

#include "Blueprint/UserWidget.h"
#include "JMPrototypeStationInteractionWidget.generated.h"

class AJMPrototypeInteractionActorBase;
class APlayerController;
class UBorder;
class UButton;
class UTextBlock;

/** Common modal used by quest submission, cooking, and upgrade stations. */
UCLASS(BlueprintType, Blueprintable)
class P_060715_API UJMPrototypeStationInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitializeForStation(AJMPrototypeInteractionActorBase* InStation);
	void ActivateModal();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Text")
	FText CloseButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Text")
	FText RetryButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Appearance")
	FLinearColor PanelColor = FLinearColor(0.015f, 0.028f, 0.04f, 0.97f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Appearance")
	FLinearColor AccentColor = FLinearColor(0.22f, 0.72f, 0.82f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Appearance")
	FLinearColor SuccessColor = FLinearColor(0.35f, 1.0f, 0.48f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Station UI|Appearance")
	FLinearColor FailureColor = FLinearColor(1.0f, 0.28f, 0.22f, 1.0f);

protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual FReply NativeOnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UTextBlock> Text_Result;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UButton> Button_Confirm;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UTextBlock> Text_ConfirmButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UButton> Button_Close;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "Station UI")
	TObjectPtr<UTextBlock> Text_CloseButton;

private:
	void BuildFallbackLayout();
	void RefreshStationText();
	void CloseModal();

	UFUNCTION()
	void HandleConfirmClicked();

	UFUNCTION()
	void HandleCloseClicked();

	TWeakObjectPtr<AJMPrototypeInteractionActorBase> Station;
	TWeakObjectPtr<APlayerController> ModalPlayerController;
	bool bOperationSucceeded = false;
};
