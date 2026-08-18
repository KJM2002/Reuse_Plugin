#pragma once

#include "AITypes.h"
#include "Action/JMEnemyAction_Melee.h"
#include "Action/JMEnemyAction_Scream.h"
#include "Action/JMEnemyActionTypes.h"
#include "Core/JMEnemyBase.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "Locomotion/JMEnemyMovementTypes.h"
#include "JMEnemyCoreTestTypes.generated.h"

UCLASS()
class AJMEnemyCoreTestEnemy : public AJMEnemyBase
{
    GENERATED_BODY()
};

UCLASS()
class UJMEnemyStateTestListener : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleStateChanged(FGameplayTag PreviousState, FGameplayTag NewState)
    {
        ++CallCount;
        LastPreviousState = PreviousState;
        LastNewState = NewState;
    }

    int32 CallCount = 0;
    FGameplayTag LastPreviousState;
    FGameplayTag LastNewState;
};

UCLASS()
class UJMEnemyMemoryTestListener : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleTargetChanged(AActor* PreviousTarget, AActor* NewTarget)
    {
        ++CallCount;
        LastPreviousTarget = PreviousTarget;
        LastNewTarget = NewTarget;
    }

    int32 CallCount = 0;
    TWeakObjectPtr<AActor> LastPreviousTarget;
    TWeakObjectPtr<AActor> LastNewTarget;
};

UCLASS()
class UJMEnemyLocomotionTestListener : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleMoveFinished(FAIRequestID RequestID, EJMEnemyMoveStatus Result,
        AActor* TargetActor, FVector Destination)
    {
        ++CallCount;
        LastRequestID = RequestID;
        LastResult = Result;
        LastTarget = TargetActor;
        LastDestination = Destination;
    }

    int32 CallCount = 0;
    FAIRequestID LastRequestID;
    EJMEnemyMoveStatus LastResult = EJMEnemyMoveStatus::Idle;
    TWeakObjectPtr<AActor> LastTarget;
    FVector LastDestination = FVector::ZeroVector;
};

UCLASS()
class AJMEnemyActionDamageTarget : public AActor
{
    GENERATED_BODY()

public:
    AJMEnemyActionDamageTarget()
    {
        RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
        SetCanBeDamaged(true);
    }

    virtual float TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override
    {
        DamageTaken += DamageAmount;
        ++DamageCallCount;
        return DamageAmount;
    }

    float DamageTaken = 0.0f;
    int32 DamageCallCount = 0;
};

UCLASS()
class AJMEnemyPlayerDamageTarget : public ACharacter
{
    GENERATED_BODY()

public:
    virtual float TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent,
        AController* EventInstigator, AActor* DamageCauser) override
    {
        DamageTaken += DamageAmount;
        ++DamageCallCount;
        return DamageAmount;
    }

    float DamageTaken = 0.0f;
    int32 DamageCallCount = 0;
};

UCLASS()
class UJMEnemyActionMoveTargetOnStart : public UJMEnemyAction_Melee
{
    GENERATED_BODY()

protected:
    virtual void ActionStarted() override
    {
        if (AActor* Target = GetExecutionContext().TargetActor.Get())
        {
            Target->SetActorLocation(FVector(10000.0, 0.0, 0.0));
        }
    }
};

UCLASS()
class UJMEnemyActionTickingScream : public UJMEnemyAction_Scream
{
    GENERATED_BODY()

protected:
    virtual bool WantsUpdate() const override { return true; }
};

UCLASS()
class UJMEnemyActionTestListener : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void HandleStarted(FGameplayTag ActionId, UJMEnemyAction* Action)
    {
        ++StartedCount;
        LastActionId = ActionId;
    }

    UFUNCTION()
    void HandlePhaseChanged(FGameplayTag ActionId, UJMEnemyAction* Action,
        EJMEnemyActionPhase PreviousPhase, EJMEnemyActionPhase NewPhase)
    {
        ++PhaseCount;
        if (NewPhase == EJMEnemyActionPhase::Active)
        {
            ++ActiveCount;
        }
    }

    UFUNCTION()
    void HandleFinished(FGameplayTag ActionId, UJMEnemyAction* Action)
    {
        ++FinishedCount;
        LastActionId = ActionId;
    }

    UFUNCTION()
    void HandleCancelled(FGameplayTag ActionId, UJMEnemyAction* Action)
    {
        ++CancelledCount;
        LastActionId = ActionId;
    }

    int32 StartedCount = 0;
    int32 PhaseCount = 0;
    int32 ActiveCount = 0;
    int32 FinishedCount = 0;
    int32 CancelledCount = 0;
    FGameplayTag LastActionId;
};
