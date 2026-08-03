#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidgetBase.generated.h"

class UImage;
class UPanelWidget;
class UTextBlock;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class REUSABLEDIALOGUESYSTEM_API UDialogueWidgetBase : public UUserWidget
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetSpeakerName(const FText& Name);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetSpeakerNameColor(FLinearColor Color);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetDialogueText(const FText& Text);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetDialogueTextSmoothed(const FText& Text, float BlendDuration, float StartOpacity);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetPortrait(UTexture2D* Portrait);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void SetAdvanceIndicatorVisible(bool bVisible);
    UFUNCTION(BlueprintCallable, Category="Dialogue|UI") void ResetDialogueWidget();

    UFUNCTION(BlueprintImplementableEvent, Category="Dialogue|UI") void OnDialogueOpened();
    UFUNCTION(BlueprintImplementableEvent, Category="Dialogue|UI") void OnDialogueClosed();
    UFUNCTION(BlueprintImplementableEvent, Category="Dialogue|UI") void OnLineStarted(FName LineId, int32 LineIndex);
    UFUNCTION(BlueprintImplementableEvent, Category="Dialogue|UI") void OnLineCompleted(FName LineId, int32 LineIndex);
    UFUNCTION(BlueprintImplementableEvent, Category="Dialogue|UI") void OnSpeakerChanged();

protected:
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidget), Category="Dialogue|UI") TObjectPtr<UTextBlock> SpeakerNameText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidget), Category="Dialogue|UI") TObjectPtr<UTextBlock> DialogueText;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional), Category="Dialogue|UI") TObjectPtr<UPanelWidget> SpeakerNamePanel;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional), Category="Dialogue|UI") TObjectPtr<UImage> SpeakerPortrait;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional), Category="Dialogue|UI") TObjectPtr<UWidget> AdvanceIndicator;
    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional), Category="Dialogue|UI") TObjectPtr<UWidget> DialogueContainer;

private:
    float RevealBlendElapsed = 0.f;
    float RevealBlendDuration = 0.f;
    float RevealStartOpacity = 1.f;
    bool bRevealBlendActive = false;
};
