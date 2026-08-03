#include "UI/JMJumpScareOverlayWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

void UJMJumpScareOverlayWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!WidgetTree->RootWidget)
    {
        UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("JumpScareCanvas"));
        ImageWidget = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("JumpScareImage"));
        WidgetTree->RootWidget = Canvas;

        UCanvasPanelSlot* ImageSlot = Canvas->AddChildToCanvas(ImageWidget);
        ImageSlot->SetAnchors(FAnchors(0.5f, 0.5f));
        ImageSlot->SetAlignment(FVector2D(0.5f, 0.5f));
        ImageSlot->SetPosition(FVector2D::ZeroVector);
    }
    else
    {
        ImageWidget = Cast<UImage>(WidgetTree->FindWidget(TEXT("JumpScareImage")));
    }

    SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UJMJumpScareOverlayWidget::Configure(
    UTexture2D* Texture,
    const FLinearColor& Tint,
    const FVector2D& ImageResolution,
    float RiseDuration)
{
    if (ImageWidget)
    {
        ConfiguredResolution = FVector2D(FMath::Max(1.0f, ImageResolution.X), FMath::Max(1.0f, ImageResolution.Y));
        ConfiguredRiseDuration = FMath::Max(0.0f, RiseDuration);
        RiseElapsed = 0.0f;

        ImageWidget->SetBrushFromTexture(Texture, false);
        ImageWidget->SetColorAndOpacity(Tint);
        if (UCanvasPanelSlot* ImageSlot = Cast<UCanvasPanelSlot>(ImageWidget->Slot))
        {
            ImageSlot->SetSize(ConfiguredResolution);
        }

        const float ViewportHeight = UWidgetLayoutLibrary::GetViewportSize(this).Y;
        StartTranslationY = FMath::Max(ViewportHeight, ConfiguredResolution.Y);
        bRising = ConfiguredRiseDuration > 0.0f;
        ImageWidget->SetRenderTranslation(bRising ? FVector2D(0.0f, StartTranslationY) : FVector2D::ZeroVector);
    }
}

void UJMJumpScareOverlayWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (!bRising || !ImageWidget)
    {
        return;
    }

    RiseElapsed += InDeltaTime;
    const float Alpha = FMath::Clamp(RiseElapsed / ConfiguredRiseDuration, 0.0f, 1.0f);
    const float EasedAlpha = FMath::InterpEaseOut(0.0f, 1.0f, Alpha, 3.0f);
    ImageWidget->SetRenderTranslation(FVector2D(0.0f, FMath::Lerp(StartTranslationY, 0.0f, EasedAlpha)));

    if (Alpha >= 1.0f)
    {
        bRising = false;
        ImageWidget->SetRenderTranslation(FVector2D::ZeroVector);
    }
}
