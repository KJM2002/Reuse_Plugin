#include "DialogueWidgetBase.h"
#include "DialogueSettings.h"
#include "DialogueSubsystem.h"
#include "Components/Image.h"
#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Engine/GameInstance.h"
#include "Input/Reply.h"
#include "InputCoreTypes.h"

void UDialogueWidgetBase::SetSpeakerName(const FText& Name)
{
    if (SpeakerNameText) SpeakerNameText->SetText(Name);
    if (SpeakerNamePanel) SpeakerNamePanel->SetVisibility(Name.IsEmpty() ? ESlateVisibility::Collapsed : ESlateVisibility::SelfHitTestInvisible);
}

void UDialogueWidgetBase::SetSpeakerNameColor(FLinearColor Color) { if (SpeakerNameText) SpeakerNameText->SetColorAndOpacity(Color); }
void UDialogueWidgetBase::SetDialogueText(const FText& Text)
{
    bRevealBlendActive = false;
    if (DialogueText)
    {
        DialogueText->SetText(Text);
        DialogueText->SetRenderOpacity(1.f);
    }
}

void UDialogueWidgetBase::SetDialogueTextSmoothed(const FText& Text, float BlendDuration, float StartOpacity)
{
    if (!DialogueText)
    {
        return;
    }

    DialogueText->SetText(Text);
    RevealBlendElapsed = 0.f;
    RevealBlendDuration = FMath::Max(BlendDuration, UE_SMALL_NUMBER);
    RevealStartOpacity = FMath::Clamp(StartOpacity, 0.f, 1.f);
    bRevealBlendActive = RevealStartOpacity < 1.f;
    DialogueText->SetRenderOpacity(bRevealBlendActive ? RevealStartOpacity : 1.f);
}

void UDialogueWidgetBase::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (!bRevealBlendActive || !DialogueText)
    {
        return;
    }

    RevealBlendElapsed += InDeltaTime;
    const float Alpha = FMath::Clamp(RevealBlendElapsed / RevealBlendDuration, 0.f, 1.f);
    DialogueText->SetRenderOpacity(FMath::InterpEaseOut(RevealStartOpacity, 1.f, Alpha, 2.f));
    if (Alpha >= 1.f)
    {
        bRevealBlendActive = false;
    }
}
void UDialogueWidgetBase::SetPortrait(UTexture2D* Portrait) { if (SpeakerPortrait) { SpeakerPortrait->SetBrushFromTexture(Portrait); SpeakerPortrait->SetVisibility(Portrait ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed); } }
void UDialogueWidgetBase::SetAdvanceIndicatorVisible(bool bVisible) { if (AdvanceIndicator) AdvanceIndicator->SetVisibility(bVisible ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed); }
void UDialogueWidgetBase::ResetDialogueWidget() { SetSpeakerName(FText::GetEmpty()); SetDialogueText(FText::GetEmpty()); SetPortrait(nullptr); SetAdvanceIndicatorVisible(false); }

FReply UDialogueWidgetBase::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    const UDialogueSettings* Settings = GetDefault<UDialogueSettings>();
    const FKey Key = InKeyEvent.GetKey();
    const bool bKeyboard = Settings->bAllowKeyboardAdvance && (Key == EKeys::SpaceBar || Key == EKeys::Enter);
    const bool bGamepad = Settings->bAllowGamepadAdvance && Key == EKeys::Gamepad_FaceButton_Bottom;
    if ((bKeyboard || bGamepad) && GetGameInstance()) { GetGameInstance()->GetSubsystem<UDialogueSubsystem>()->AdvanceDialogue(); return FReply::Handled(); }
    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

FReply UDialogueWidgetBase::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (GetDefault<UDialogueSettings>()->bAllowMouseAdvance && InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton && GetGameInstance())
    { GetGameInstance()->GetSubsystem<UDialogueSubsystem>()->AdvanceDialogue(); return FReply::Handled(); }
    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}
