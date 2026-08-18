#include "Animation/JMEnemyAnimInstance.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyActionComponent.h"
#include "Core/JMEnemyBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "State/JMEnemyStateComponent.h"

void UJMEnemyAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    InitializeFromEnemy(Cast<AJMEnemyBase>(TryGetPawnOwner()));
}

void UJMEnemyAnimInstance::NativeUninitializeAnimation()
{
    UnbindActionEvents();
    EnemyOwner.Reset();
    StateComponent.Reset();
    LocomotionComponent.Reset();
    ActionComponent.Reset();
    bHasLocationSample = false;
    Super::NativeUninitializeAnimation();
}

void UJMEnemyAnimInstance::NativeUpdateAnimation(const float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    RefreshPresentationData(DeltaSeconds);
}

void UJMEnemyAnimInstance::InitializeFromEnemy(AJMEnemyBase* InEnemy)
{
    UnbindActionEvents();
    EnemyOwner = InEnemy;
    StateComponent = InEnemy ? InEnemy->GetEnemyStateComponent() : nullptr;
    LocomotionComponent = InEnemy ? InEnemy->GetEnemyLocomotionComponent() : nullptr;
    ActionComponent = InEnemy ? InEnemy->GetEnemyActionComponent() : nullptr;
    LastOwnerLocation = InEnemy ? InEnemy->GetActorLocation() : FVector::ZeroVector;
    bHasLocationSample = InEnemy != nullptr;

    if (ActionComponent.IsValid())
    {
        ActionStartedHandle = ActionComponent->OnActionStartedNative.AddUObject(
            this, &ThisClass::HandleActionStarted);
        ActionPhaseHandle = ActionComponent->OnActionPhaseChangedNative.AddUObject(
            this, &ThisClass::HandleActionPhaseChanged);
        ActionFinishedHandle = ActionComponent->OnActionFinishedNative.AddUObject(
            this, &ThisClass::HandleActionFinished);
        ActionCancelledHandle = ActionComponent->OnActionCancelledNative.AddUObject(
            this, &ThisClass::HandleActionCancelled);
    }
    RefreshPresentationData(0.0f);
}

void UJMEnemyAnimInstance::RefreshPresentationData(const float DeltaSeconds)
{
    AJMEnemyBase* Enemy = EnemyOwner.Get();
    if (!Enemy) return;

    FVector SampledVelocity = Enemy->GetVelocity();
    const FVector CurrentLocation = Enemy->GetActorLocation();
    if (SampledVelocity.IsNearlyZero() && bHasLocationSample && DeltaSeconds > UE_KINDA_SMALL_NUMBER)
    {
        SampledVelocity = (CurrentLocation - LastOwnerLocation) / DeltaSeconds;
    }
    LastOwnerLocation = CurrentLocation;
    bHasLocationSample = true;

    Velocity = SampledVelocity;
    Speed = Velocity.Size();
    bIsMoving = Speed > 1.0f;
    const FVector LocalVelocity = Enemy->GetActorTransform().InverseTransformVectorNoScale(Velocity);
    Direction = bIsMoving
        ? FMath::RadiansToDegrees(FMath::Atan2(LocalVelocity.Y, LocalVelocity.X)) : 0.0f;
    bIsFalling = Enemy->GetCharacterMovement() && Enemy->GetCharacterMovement()->IsFalling();
    CurrentState = StateComponent.IsValid()
        ? StateComponent->GetCurrentState() : FGameplayTag::EmptyTag;
    CurrentMovementProfile = LocomotionComponent.IsValid()
        ? LocomotionComponent->GetCurrentMovementProfile() : NAME_None;

    if (const UJMEnemyAction* Action = ActionComponent.IsValid()
        ? ActionComponent->GetCurrentAction() : nullptr)
    {
        CurrentAction = Action->GetActionId();
        CurrentActionPhase = Action->GetPhase();
    }
}

void UJMEnemyAnimInstance::UnbindActionEvents()
{
    if (ActionComponent.IsValid())
    {
        ActionComponent->OnActionStartedNative.Remove(ActionStartedHandle);
        ActionComponent->OnActionPhaseChangedNative.Remove(ActionPhaseHandle);
        ActionComponent->OnActionFinishedNative.Remove(ActionFinishedHandle);
        ActionComponent->OnActionCancelledNative.Remove(ActionCancelledHandle);
    }
    ActionStartedHandle.Reset();
    ActionPhaseHandle.Reset();
    ActionFinishedHandle.Reset();
    ActionCancelledHandle.Reset();
}

void UJMEnemyAnimInstance::HandleActionStarted(const FGameplayTag ActionId, UJMEnemyAction*)
{
    CurrentAction = ActionId;
    CurrentActionPhase = EJMEnemyActionPhase::Idle;
}

void UJMEnemyAnimInstance::HandleActionPhaseChanged(const FGameplayTag ActionId, UJMEnemyAction*,
    EJMEnemyActionPhase, const EJMEnemyActionPhase NewPhase)
{
    CurrentAction = ActionId;
    CurrentActionPhase = NewPhase;
}

void UJMEnemyAnimInstance::HandleActionFinished(const FGameplayTag ActionId, UJMEnemyAction*)
{
    if (CurrentAction == ActionId)
    {
        CurrentAction = FGameplayTag::EmptyTag;
        CurrentActionPhase = EJMEnemyActionPhase::Idle;
    }
}

void UJMEnemyAnimInstance::HandleActionCancelled(const FGameplayTag ActionId, UJMEnemyAction*)
{
    HandleActionFinished(ActionId, nullptr);
}
