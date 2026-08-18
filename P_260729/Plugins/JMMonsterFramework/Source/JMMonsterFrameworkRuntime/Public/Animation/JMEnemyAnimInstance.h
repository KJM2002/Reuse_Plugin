#pragma once

#include "Action/JMEnemyActionTypes.h"
#include "Animation/AnimInstance.h"
#include "GameplayTagContainer.h"
#include "JMEnemyAnimInstance.generated.h"

class AJMEnemyBase;
class UJMEnemyAction;
class UJMEnemyActionComponent;
class UJMEnemyLocomotionComponent;
class UJMEnemyStateComponent;

/**
 * Skeleton-independent, read-only bridge from framework runtime state to an Anim Blueprint.
 * It never changes AI state or action timing and performs no sensing, tracing, or navigation work.
 */
UCLASS(Blueprintable, Transient)
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUninitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

    /** Explicit initialization seam used by tests and non-standard mesh ownership. */
    void InitializeFromEnemy(AJMEnemyBase* InEnemy);

    /** Lightweight value refresh; NativeUpdateAnimation calls this automatically. */
    void RefreshPresentationData(float DeltaSeconds);

    UFUNCTION(BlueprintPure, Category="JM Monster|Animation")
    AJMEnemyBase* GetEnemyOwner() const { return EnemyOwner.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Monster|Animation")
    bool IsInState(FGameplayTag State) const { return CurrentState.MatchesTag(State); }

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    FVector Velocity = FVector::ZeroVector;

    /** Actor-local planar travel direction in degrees, suitable for a directional BlendSpace. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    float Direction = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    float Speed = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    bool bIsMoving = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    bool bIsFalling = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|State")
    FGameplayTag CurrentState;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Locomotion")
    FName CurrentMovementProfile;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Action")
    FGameplayTag CurrentAction;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="JM Monster|Animation|Action")
    EJMEnemyActionPhase CurrentActionPhase = EJMEnemyActionPhase::Idle;

private:
    void UnbindActionEvents();
    void HandleActionStarted(FGameplayTag ActionId, UJMEnemyAction* Action);
    void HandleActionPhaseChanged(FGameplayTag ActionId, UJMEnemyAction* Action,
        EJMEnemyActionPhase PreviousPhase, EJMEnemyActionPhase NewPhase);
    void HandleActionFinished(FGameplayTag ActionId, UJMEnemyAction* Action);
    void HandleActionCancelled(FGameplayTag ActionId, UJMEnemyAction* Action);

    UPROPERTY(Transient)
    TWeakObjectPtr<AJMEnemyBase> EnemyOwner;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyStateComponent> StateComponent;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyLocomotionComponent> LocomotionComponent;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyActionComponent> ActionComponent;

    FDelegateHandle ActionStartedHandle;
    FDelegateHandle ActionPhaseHandle;
    FDelegateHandle ActionFinishedHandle;
    FDelegateHandle ActionCancelledHandle;
    FVector LastOwnerLocation = FVector::ZeroVector;
    bool bHasLocationSample = false;
};
