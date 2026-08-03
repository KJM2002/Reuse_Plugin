#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/JMInteractionTypes.h"
#include "JMReconPromptWidgetBase.generated.h"

class UBorder;
class UTextBlock;

UCLASS(Blueprintable)
class JMRECONGAMEPLAYINTEGRATION_API UJMReconPromptWidgetBase : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="JM Recon|UI")
    void SetReconPrompt(const FText& Prompt, bool bVisible);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="JM Recon|UI")
    void ApplyReconPromptStyle(const FJMInteractionPromptStyle& Style);

    UFUNCTION(BlueprintPure, Category="JM Recon|UI")
    FText GetDisplayedPrompt() const { return DisplayedPrompt; }

protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;
    virtual void SetReconPrompt_Implementation(const FText& Prompt, bool bVisible);
    virtual void ApplyReconPromptStyle_Implementation(const FJMInteractionPromptStyle& Style);

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UTextBlock> PromptText;

    UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
    TObjectPtr<UBorder> PromptContainer;

private:
    TSharedPtr<class SBox> NativeOffsetBox;
    TSharedPtr<class SBorder> NativeContainer;
    TSharedPtr<class STextBlock> NativeText;
    FSlateFontInfo NativeFont;
    FJMInteractionPromptStyle AppliedStyle;
    FText DisplayedPrompt;
};
