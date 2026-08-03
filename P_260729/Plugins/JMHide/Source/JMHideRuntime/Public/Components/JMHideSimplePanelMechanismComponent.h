#pragma once

#include "CoreMinimal.h"
#include "Components/JMHideMechanismComponent.h"
#include "JMHideSimplePanelMechanismComponent.generated.h"

class UCurveFloat;
class USceneComponent;

UENUM(BlueprintType)
enum class EJMHidePanelMotionType : uint8
{
    Transform,
    RotationOnly
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHidePanelPart
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(UseComponentPicker, AllowAnyActor))
    TObjectPtr<USceneComponent> Panel = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    FTransform ClosedRelativeTransform = FTransform::Identity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    FTransform OpenRelativeTransform = FTransform::Identity;

    /** RotationOnly never writes the panel's relative location or scale. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    EJMHidePanelMotionType MotionType = EJMHidePanelMotionType::Transform;
};

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDERUNTIME_API UJMHideSimplePanelMechanismComponent final : public UJMHideMechanismComponent
{
    GENERATED_BODY()

public:
    UJMHideSimplePanelMechanismComponent();

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual bool CanStartOperation(EJMHideOperation Operation, const FJMHideOperationContext& Context,
        EJMHideFailureCode& OutFailure) const override;
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation, const FJMHideOperationContext& Context) override;
    virtual void CancelOperation(const FGuid& SessionId) override;
    virtual void Restore(const FGuid& SessionId) override;
    virtual void GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Panel")
    TArray<FJMHidePanelPart> Panels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Panel", meta=(ClampMin="0.0", Units="s"))
    float Duration = 0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Panel", meta=(ClampMin="0.0", Units="s"))
    float Delay = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Panel")
    TObjectPtr<UCurveFloat> Curve = nullptr;

    UFUNCTION(BlueprintCallable, Category="JM Hide|Validation")
    bool ValidateConfiguration(TArray<FText>& OutErrors) const;

private:
    void ApplyAlpha(float Alpha);
    void FinishTransition();

    FGuid ActiveSessionId;
    EJMHideOperation ActiveOperation = EJMHideOperation::None;
    float Elapsed = 0.0f;
    bool bOpening = false;
};
