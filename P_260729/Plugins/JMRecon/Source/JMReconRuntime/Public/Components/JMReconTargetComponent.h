#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Types/JMReconTypes.h"
#include "JMReconTargetComponent.generated.h"

class UJMReconDefinition;

UCLASS(ClassGroup=(JM), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMRECONRUNTIME_API UJMReconTargetComponent : public USceneComponent
{
    GENERATED_BODY()

public:
    UJMReconTargetComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recon|Advanced", meta=(AdvancedDisplay))
    TObjectPtr<UJMReconDefinition> ReconDefinition = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(Bitmask, BitmaskEnum="/Script/JMReconRuntime.EJMReconMode", AdvancedDisplay))
    int32 AllowedReconModes = static_cast<int32>(EJMReconMode::Listen) |
                              static_cast<int32>(EJMReconMode::Peek) |
                              static_cast<int32>(EJMReconMode::Illuminate);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(AdvancedDisplay))
    FTransform PlayerRelativeTransform = FTransform(FRotator::ZeroRotator, FVector(-100.0, 0.0, 0.0));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(AdvancedDisplay))
    FTransform ListenCameraRelativeTransform = FTransform(FRotator::ZeroRotator, FVector(-20.0, 0.0, 60.0));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(AdvancedDisplay))
    FTransform PeekCameraRelativeTransform = FTransform(FRotator::ZeroRotator, FVector(10.0, 0.0, 60.0));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(UseComponentPicker, AllowAnyActor, AdvancedDisplay))
    TObjectPtr<USceneComponent> PlayerAnchorOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(UseComponentPicker, AllowAnyActor, AdvancedDisplay))
    TObjectPtr<USceneComponent> ListenCameraAnchorOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(UseComponentPicker, AllowAnyActor, AdvancedDisplay))
    TObjectPtr<USceneComponent> PeekCameraAnchorOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Recon|Advanced", meta=(ClampMin="0.0", Units="cm", AdvancedDisplay))
    float MaximumStartDistance = 200.0f;

    UFUNCTION(BlueprintPure, Category="JM Recon")
    UJMReconDefinition* GetEffectiveDefinition() const;

    UFUNCTION(BlueprintPure, Category="JM Recon")
    FTransform GetPlayerWorldTransform() const;

    UFUNCTION(BlueprintPure, Category="JM Recon")
    FTransform GetListenCameraWorldTransform() const;

    UFUNCTION(BlueprintPure, Category="JM Recon")
    FTransform GetPeekCameraWorldTransform() const;

    UFUNCTION(BlueprintPure, Category="JM Recon")
    bool SupportsMode(EJMReconMode Mode) const;

    FJMReconRequestResult TryReserve(const FGuid& SessionId);
    void ReleaseReservation(const FGuid& SessionId);
    bool IsReservedBy(const FGuid& SessionId) const;
    bool IsReserved() const { return ReservedSessionId.IsValid(); }

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif

private:
    FTransform ResolveTransform(const USceneComponent* Override, const FTransform& Relative) const;

    FGuid ReservedSessionId;
};
