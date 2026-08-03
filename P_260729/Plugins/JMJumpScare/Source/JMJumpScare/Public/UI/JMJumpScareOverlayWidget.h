#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JMJumpScareOverlayWidget.generated.h"

class UImage;
class UTexture2D;

/** Internal full-screen image used by the JumpScare subsystem. */
UCLASS(NotBlueprintable)
class JMJUMPSCARE_API UJMJumpScareOverlayWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void Configure(UTexture2D* Texture, const FLinearColor& Tint, const FVector2D& ImageResolution, float RiseDuration);

protected:
    virtual void NativeOnInitialized() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    UPROPERTY(Transient)
    TObjectPtr<UImage> ImageWidget = nullptr;

    FVector2D ConfiguredResolution = FVector2D(1920.0f, 1080.0f);
    float ConfiguredRiseDuration = 0.0f;
    float RiseElapsed = 0.0f;
    float StartTranslationY = 0.0f;
    bool bRising = false;
};
