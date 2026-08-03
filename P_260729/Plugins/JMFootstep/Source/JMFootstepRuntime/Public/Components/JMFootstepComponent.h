#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Types/JMFootstepRuntimeLogic.h"
#include "Types/JMFootstepTypes.h"
#include "JMFootstepComponent.generated.h"

class ACharacter;
class UJMFootstepSet;
class UJMFootstepSettings;
class UJMFootstepSurfaceProfile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FJMFootstepPlayedSignature,
    const FJMFootstepResult&,
    Result);

USTRUCT()
struct JMFOOTSTEPRUNTIME_API FJMFootstepVariantSoundHistory
{
    GENERATED_BODY()

    int32 GetLastIndex(EJMFootstepLocomotionState VariantState, bool bLegacyVariant) const;
    void SetLastIndex(EJMFootstepLocomotionState VariantState, bool bLegacyVariant, int32 SoundIndex);

private:
    UPROPERTY(Transient)
    int32 WalkIndex = INDEX_NONE;

    UPROPERTY(Transient)
    int32 RunIndex = INDEX_NONE;

    UPROPERTY(Transient)
    int32 CrouchWalkIndex = INDEX_NONE;

    UPROPERTY(Transient)
    int32 LegacyIndex = INDEX_NONE;
};

UCLASS(ClassGroup = (JM), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class JMFOOTSTEPRUNTIME_API UJMFootstepComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMFootstepComponent();

    virtual void TickComponent(
        float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
    virtual void Activate(bool bReset = false) override;
    virtual void Deactivate() override;

    UPROPERTY(BlueprintAssignable, Category = "JM Footstep")
    FJMFootstepPlayedSignature OnFootstepPlayed;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Data")
    TObjectPtr<UJMFootstepSet> FootstepSetOverride = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Trigger")
    bool bOverrideTriggerMode = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Trigger", meta = (EditCondition = "bOverrideTriggerMode"))
    EJMFootstepTriggerMode TriggerModeOverride = EJMFootstepTriggerMode::DistanceBased;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides")
    bool bOverrideMovementSettings = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "0.0", Units = "cm/s"))
    float MinimumMovementSpeedOverride = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "0.0", Units = "cm/s"))
    float RunSpeedThresholdOverride = 325.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "1.0", Units = "cm"))
    float WalkStepDistanceOverride = 110.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "1.0", Units = "cm"))
    float RunStepDistanceOverride = 140.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "1.0", Units = "cm"))
    float CrouchStepDistanceOverride = 80.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "1.0", Units = "cm"))
    float TeleportDistanceThresholdOverride = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideMovementSettings", ClampMin = "1", ClampMax = "8"))
    int32 MaxStepsPerFrameOverride = 2;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides")
    bool bOverrideTraceSettings = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideTraceSettings", ClampMin = "1.0", Units = "cm"))
    float TraceDistanceOverride = 70.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideTraceSettings", ClampMin = "0.0", Units = "cm"))
    float TraceStartOffsetOverride = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideTraceSettings"))
    TEnumAsByte<ECollisionChannel> TraceChannelOverride = ECC_Visibility;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides")
    bool bOverrideAudioMultipliers = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideAudioMultipliers", ClampMin = "0.0"))
    float VolumeMultiplierOverride = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Overrides", meta = (EditCondition = "bOverrideAudioMultipliers", ClampMin = "0.01"))
    float PitchMultiplierOverride = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Debug")
    bool bOverrideDebug = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Footstep|Debug", meta = (EditCondition = "bOverrideDebug"))
    bool bEnableDebugOverride = false;

    UFUNCTION(BlueprintCallable, Category = "JM Footstep")
    FJMFootstepResult TriggerFootstep();

    UFUNCTION(BlueprintCallable, Category = "JM Footstep")
    FJMFootstepResult RequestFootstep(const FJMFootstepContext& Context);

    UFUNCTION(BlueprintCallable, Category = "JM Footstep")
    void SetLocomotionStateOverride(EJMFootstepLocomotionState NewState);

    UFUNCTION(BlueprintCallable, Category = "JM Footstep")
    void ClearLocomotionStateOverride();

    UFUNCTION(BlueprintPure, Category = "JM Footstep")
    bool HasLocomotionStateOverride() const { return bHasLocomotionOverride; }

    UFUNCTION(BlueprintPure, Category = "JM Footstep")
    EJMFootstepLocomotionState GetCurrentLocomotionState() const { return CurrentLocomotionState; }

    UFUNCTION(BlueprintPure, Category = "JM Footstep")
    float GetAccumulatedDistance() const { return DistanceAccumulator.GetAccumulatedDistance(); }

    UFUNCTION(BlueprintCallable, Category = "JM Footstep")
    void ResetFootstepState();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    bool IsOwnerGrounded(const ACharacter* Character) const;
    EJMFootstepLocomotionState DetectLocomotionState(float ActualSpeed2D, bool bGrounded) const;
    float GetStepDistance(EJMFootstepLocomotionState State) const;
    float GetStateVolumeMultiplier(EJMFootstepLocomotionState State) const;
    FVector GetDefaultTraceOrigin(const ACharacter* Character) const;
    UJMFootstepSet* ResolveFootstepSet(const UJMFootstepSettings* Settings) const;
    FJMFootstepResult MakeFailure(
        EJMFootstepFailureReason Reason,
        EJMFootstepLocomotionState State,
        EJMFootstepFoot Foot) const;
    bool IsDebugEnabled(const UJMFootstepSettings* Settings) const;

    FVector PreviousLocation = FVector::ZeroVector;
    bool bHasPreviousLocation = false;
    float LastActualSpeed2D = 0.0f;
    FJMFootstepDistanceAccumulator DistanceAccumulator;
    EJMFootstepLocomotionState CurrentLocomotionState = EJMFootstepLocomotionState::Idle;
    EJMFootstepLocomotionState LocomotionOverride = EJMFootstepLocomotionState::Walk;
    bool bHasLocomotionOverride = false;
    EJMFootstepFoot NextLogicalFoot = EJMFootstepFoot::Left;

    UPROPERTY(Transient)
    TMap<TObjectPtr<UJMFootstepSurfaceProfile>, FJMFootstepVariantSoundHistory> SoundHistoryByProfile;
};
