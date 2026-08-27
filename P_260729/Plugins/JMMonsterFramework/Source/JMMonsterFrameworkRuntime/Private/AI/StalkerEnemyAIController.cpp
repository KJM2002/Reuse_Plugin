#include "AI/StalkerEnemyAIController.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "StateTree.h"

AStalkerEnemyAIController::AStalkerEnemyAIController()
{
    StateTreeAsset = TSoftObjectPtr<UStateTree>(FSoftObjectPath(
        TEXT("/JMMonsterFramework/AI/ST_StalkerEnemy.ST_StalkerEnemy")));
}

void AStalkerEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (ACharacter* StalkerCharacter = Cast<ACharacter>(InPawn))
    {
        StalkerCharacter->bUseControllerRotationYaw = true;
        StalkerCharacter->GetCharacterMovement()->bOrientRotationToMovement = false;
    }

    if (UAIPerceptionComponent* Perception = GetPerceptionComponent())
    {
        Perception->SetSenseEnabled(UAISense_Hearing::StaticClass(), false);
        Perception->RequestStimuliListenerUpdate();
    }

    UpdateDistanceBand();
}

void AStalkerEnemyAIController::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    UpdateDistanceBand();
}

void AStalkerEnemyAIController::UpdateDistanceBand()
{
    if (!EnemyMemory.bCanSeeTarget || !IsValid(EnemyMemory.TargetActor) || !IsValid(GetPawn()))
    {
        CurrentTargetDistance = 0.0f;
        CurrentDistanceBand = EJMStalkerDistanceBand::None;
        return;
    }

    CurrentTargetDistance = FVector::Dist2D(
        GetPawn()->GetActorLocation(),
        EnemyMemory.TargetActor->GetActorLocation());

    const float MinimumDistance = FMath::Max(MinimumFollowDistance, 0.0f);
    const float MaximumDistance = FMath::Max(MaximumFollowDistance, MinimumDistance);
    const float Hysteresis = FMath::Clamp(
        DistanceHysteresis,
        0.0f,
        FMath::Max((MaximumDistance - MinimumDistance) * 0.5f, 0.0f));

    switch (CurrentDistanceBand)
    {
    case EJMStalkerDistanceBand::TooClose:
        if (CurrentTargetDistance >= MaximumDistance + Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooFar;
        }
        else if (CurrentTargetDistance >= MinimumDistance + Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::Preferred;
        }
        break;

    case EJMStalkerDistanceBand::Preferred:
        if (CurrentTargetDistance <= MinimumDistance - Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooClose;
        }
        else if (CurrentTargetDistance >= MaximumDistance + Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooFar;
        }
        break;

    case EJMStalkerDistanceBand::TooFar:
        if (CurrentTargetDistance <= MinimumDistance - Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooClose;
        }
        else if (CurrentTargetDistance <= MaximumDistance - Hysteresis)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::Preferred;
        }
        break;

    default:
        if (CurrentTargetDistance < MinimumDistance)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooClose;
        }
        else if (CurrentTargetDistance > MaximumDistance)
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::TooFar;
        }
        else
        {
            CurrentDistanceBand = EJMStalkerDistanceBand::Preferred;
        }
        break;
    }
}
