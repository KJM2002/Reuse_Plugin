#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Types/JMReconTypes.h"
#include "JMReconDefinition.generated.h"

class USoundMix;

UCLASS(BlueprintType)
class JMRECONRUNTIME_API UJMReconDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    /** Listen preserves legacy behavior. Projects can select Peek for one-action observation. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
    EJMReconInitialObservationMode InitialObservationMode = EJMReconInitialObservationMode::Listen;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", meta=(ClampMin="0.0"))
    float EnteringDuration = 0.3f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", meta=(ClampMin="0.0"))
    float ExitingDuration = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
    bool bAllowListen = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
    bool bAllowPeek = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
    bool bAllowIlluminate = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Listen", meta=(ClampMin="0.0"))
    float MinimumListenTime = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Listen")
    TSoftObjectPtr<USoundMix> ListenAudioMix;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Listen", meta=(ClampMin="0.0"))
    float ListenFadeDuration = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Peek", meta=(ClampMin="0.0", ClampMax="1.0"))
    float PeekOpenFraction = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Peek", meta=(ClampMin="0.0", ClampMax="180.0"))
    float CameraYawLimit = 45.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Peek", meta=(ClampMin="0.0", ClampMax="89.9"))
    float CameraPitchLimit = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Peek", meta=(ClampMin="0.0"))
    float PeekBlendTime = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Risk", meta=(ClampMin="0.0"))
    float ListenNoise = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Risk", meta=(ClampMin="0.0"))
    float PeekNoise = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Risk")
    FName IlluminateEvent = TEXT("Illuminate");

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
