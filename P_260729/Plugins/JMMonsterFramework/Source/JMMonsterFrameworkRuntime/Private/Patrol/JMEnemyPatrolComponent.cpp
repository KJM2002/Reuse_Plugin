#include "Patrol/JMEnemyPatrolComponent.h"

#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Patrol/JMEnemyPatrolPoint.h"

UJMEnemyPatrolComponent::UJMEnemyPatrolComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

bool UJMEnemyPatrolComponent::SelectNextDestination(
    UJMEnemyLocomotionComponent* Locomotion, FJMEnemyPatrolDestination& OutDestination)
{
    OutDestination = FJMEnemyPatrolDestination();
    if (PatrolMode == EJMEnemyPatrolMode::Disabled)
    {
        return false;
    }

    if (PatrolMode == EJMEnemyPatrolMode::Random)
    {
        if (!Locomotion || !Locomotion->FindRandomReachableLocation(
            Locomotion->GetHomeLocation(), RandomRadius, OutDestination.Location))
        {
            return false;
        }
        OutDestination.WaitTime = FMath::FRandRange(FMath::Min(MinWaitTime, MaxWaitTime), FMath::Max(MinWaitTime, MaxWaitTime));
        return true;
    }

    PatrolPoints.RemoveAll([](const AJMEnemyPatrolPoint* Point) { return !IsValid(Point); });
    if (PatrolPoints.IsEmpty())
    {
        return false;
    }

    NextPatrolPointIndex = NextPatrolPointIndex % PatrolPoints.Num();
    AJMEnemyPatrolPoint* Point = PatrolPoints[NextPatrolPointIndex];
    NextPatrolPointIndex = (NextPatrolPointIndex + 1) % PatrolPoints.Num();
    OutDestination.Location = Point->GetActorLocation();
    OutDestination.AcceptanceRadius = Point->AcceptanceRadius;
    OutDestination.WaitTime = Point->WaitTime;
    return true;
}
