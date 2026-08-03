#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Door/JMDoorTypes.h"
#include "JMDoorComponent.generated.h"

class UJMDoorConfigData;
class UJMDoorMovementComponent;
class USoundBase;
class ACharacter;
class UPrimitiveComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMDoorStateChangedSignature, EJMDoorState, OldState, EJMDoorState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMDoorAccessDeniedSignature, FJMDoorUseContext, Context, FJMDoorResult, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMDoorNoiseSignature, FJMDoorNoiseEvent, NoiseEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMDoorObstructedSignature, AActor*, BlockingActor, EJMDoorBlockBehavior, Behavior);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FJMDoorDurabilityChangedSignature, float, DoorDurability, float, LockDurability, bool, bLockBroken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FJMSlideDoorPanelStateChangedSignature, EJMSlideDoorPanel, Panel, EJMDoorState, OldState, EJMDoorState, NewState);

UCLASS(Blueprintable, ClassGroup=(JMGameplay), meta=(BlueprintSpawnableComponent))
class JMDOORRUNTIME_API UJMDoorComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMDoorComponent();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Door|Config")
    TObjectPtr<UJMDoorConfigData> Config = nullptr;

    // Runtime wiring only. Exposing an ActorComponent pointer as EditAnywhere makes
    // the Details panel recursively expand sibling instanced components.
    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Movement")
    TObjectPtr<UJMDoorMovementComponent> MovementComponent = nullptr;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="JM Door|Save")
    FGuid PersistentId;

    /** Stable, designer-authored semantic identifier for event filtering (for example Door.Office.Main). */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Door|Events", meta=(DisplayName="Objective Target Identifier"))
    FName ObjectiveTargetIdentifier;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Events")
    FJMDoorStateChangedSignature OnDoorStateChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Events")
    FJMDoorAccessDeniedSignature OnAccessDenied;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Events")
    FJMDoorNoiseSignature OnNoiseEmitted;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Events")
    FJMDoorObstructedSignature OnDoorObstructed;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Events")
    FJMDoorDurabilityChangedSignature OnDurabilityChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Door|Slide Door|Events")
    FJMSlideDoorPanelStateChangedSignature OnSlideDoorPanelStateChanged;

    UFUNCTION(BlueprintCallable, Category="JM Door")
    FJMDoorResult ExecuteCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintPure, Category="JM Door")
    bool CanExecuteCommand(EJMDoorCommand Command, const FJMDoorUseContext& Context) const;

    UFUNCTION(BlueprintCallable, Category="JM Door")
    FJMDoorResult OpenDoor(const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door")
    FJMDoorResult CloseDoor(const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door")
    FJMDoorResult ToggleDoor(const FJMDoorUseContext& Context);

    /** Explicit panel control. Panel direction is fixed by the sliding movement component. */
    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    FJMDoorResult OpenSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door|Slide Door")
    FJMDoorResult CloseSlideDoor(EJMSlideDoorPanel Panel, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    EJMDoorState GetSlideDoorPanelState(EJMSlideDoorPanel Panel) const;

    UFUNCTION(BlueprintPure, Category="JM Door|Slide Door")
    float GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel Panel) const;

    UFUNCTION(BlueprintCallable, Category="JM Door|Access")
    FJMDoorResult LockDoor();

    UFUNCTION(BlueprintCallable, Category="JM Door|Access")
    FJMDoorResult UnlockDoor(const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door|Durability")
    FJMDoorResult ForceOpenDoor(float ForceDamage, const FJMDoorUseContext& Context);

    UFUNCTION(BlueprintCallable, Category="JM Door|Durability")
    void ApplyDoorDamage(float Damage, AActor* DamageInstigator = nullptr);

    UFUNCTION(BlueprintCallable, Category="JM Door|Durability")
    void ApplyLockDamage(float Damage, AActor* DamageInstigator = nullptr);

    UFUNCTION(BlueprintCallable, Category="JM Door|Blocking")
    FJMDoorResult RetryBlockedMovement();

    UFUNCTION(BlueprintCallable, Category="JM Door|Movement")
    void SetMovementComponent(UJMDoorMovementComponent* InMovementComponent);

    UFUNCTION(BlueprintCallable, Category="JM Door|Save")
    FJMDoorSaveData CaptureSaveData() const;

    UFUNCTION(BlueprintCallable, Category="JM Door|Save")
    bool RestoreSaveData(const FJMDoorSaveData& SaveData);

    UFUNCTION(BlueprintPure, Category="JM Door")
    EJMDoorState GetState() const { return CurrentState; }

    UFUNCTION(BlueprintPure, Category="JM Door")
    bool IsLocked() const { return bLocked; }

    UFUNCTION(BlueprintPure, Category="JM Door")
    float GetOpenFraction() const { return CurrentOpenFraction; }

    UFUNCTION(BlueprintPure, Category="JM Door|Durability")
    float GetDoorDurability() const { return DoorDurability; }

    UFUNCTION(BlueprintPure, Category="JM Door|Durability")
    float GetLockDurability() const { return LockDurability; }

    UFUNCTION(BlueprintCallable, Category="JM Door|Validation")
    bool ValidateConfiguration(TArray<FText>& OutErrors) const;

protected:
    FJMDoorResult BeginMovement(float TargetFraction, const FJMDoorUseContext& Context);
    bool ResolveAccess(const FJMDoorUseContext& Context, bool bConsume, FJMDoorResult& OutResult) const;
    int32 ResolveOpenDirection(const FJMDoorUseContext& Context) const;
    void PushCharactersAlongSweptPath(float CurrentEasedFraction, float ProposedEasedFraction);
    void PushCharactersAlongSweptGeometry(UPrimitiveComponent* Primitive, const FTransform& FrameStart, const FTransform& FrameEnd);
    bool IsObstructed(float ProposedFraction, AActor*& OutBlockingActor) const;
    bool IsGeometryObstructed(UPrimitiveComponent* Primitive, const FTransform& ProposedTransform, AActor*& OutBlockingActor) const;
    void HandleObstruction(AActor* BlockingActor);
    void HandleRetryTimer();
    void HandleAutoCloseTimer();
    void TickSlideDoorPanels(float DeltaTime);
    FJMDoorResult BeginSlidePanelMovement(EJMSlideDoorPanel Panel, float TargetFraction, const FJMDoorUseContext& Context);
    FJMDoorResult BeginSingleSlidePanelMovement(EJMSlideDoorPanel Panel, float TargetFraction, const FJMDoorUseContext& Context);
    void FinishSlidePanelMovement(EJMSlideDoorPanel Panel);
    void HandleSlidePanelObstruction(EJMSlideDoorPanel Panel, AActor* BlockingActor);
    void UpdateSlideDoorAggregateState();
    void SetSlidePanelState(EJMSlideDoorPanel Panel, EJMDoorState NewState);
    EJMSlideDoorPanel ResolveSlideDoorPanel(const FJMDoorUseContext& Context) const;
    bool IsDualPanelSlidingDoor() const;
    void HandleSlideDoorAAutoCloseTimer();
    void HandleSlideDoorBAutoCloseTimer();
    void HandleSlideDoorARetryTimer();
    void HandleSlideDoorBRetryTimer();
    void FinishMovement();
    void BreakDoor(AActor* DamageInstigator);
    void SetState(EJMDoorState NewState, AActor* EventInstigator = nullptr);
    void EmitNoise(float Loudness, float MaxRange, FGameplayTag NoiseTag, const FJMDoorUseContext& Context) const;
    void PlayConfiguredSound(const TSoftObjectPtr<USoundBase>& Sound) const;
    const UJMDoorConfigData* GetEffectiveConfig() const;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    EJMDoorState CurrentState = EJMDoorState::Closed;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    float CurrentOpenFraction = 0.0f;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    float TargetOpenFraction = 0.0f;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    bool bLocked = false;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    bool bLockBroken = false;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    float DoorDurability = 100.0f;

    UPROPERTY(Transient, BlueprintReadOnly, Category="JM Door|Runtime")
    float LockDurability = 50.0f;

    int32 OpenDirectionSign = 1;
    int32 RetryCount = 0;
    float ActiveMoveDuration = 1.0f;
    bool bActiveQuiet = false;
    bool bReversingFromObstruction = false;
    FJMDoorUseContext ActiveContext;
    FTimerHandle RetryTimerHandle;
    FTimerHandle AutoCloseTimerHandle;
    TSet<TWeakObjectPtr<ACharacter>> CharactersClearedForProposedPose;

    struct FSlidePanelRuntimeState
    {
        EJMDoorState State = EJMDoorState::Closed;
        float OpenFraction = 0.0f;
        float TargetFraction = 0.0f;
        float MoveDuration = 1.0f;
        int32 RetryCount = 0;
        bool bReversingFromObstruction = false;
        FJMDoorUseContext Context;
    };

    FSlidePanelRuntimeState SlideDoorA;
    FSlidePanelRuntimeState SlideDoorB;
    FTimerHandle SlideDoorAAutoCloseTimerHandle;
    FTimerHandle SlideDoorBAutoCloseTimerHandle;
    FTimerHandle SlideDoorARetryTimerHandle;
    FTimerHandle SlideDoorBRetryTimerHandle;
};
