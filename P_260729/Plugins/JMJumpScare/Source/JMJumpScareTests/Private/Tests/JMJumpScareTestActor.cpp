#include "Tests/JMJumpScareTestActor.h"

#include "Components/SceneComponent.h"

AJMJumpScareTestActor::AJMJumpScareTestActor()
{
    SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
}

void AJMJumpScareTestActor::OnJumpScareStarted_Implementation(UJMJumpScareDefinition* Definition)
{
    ++StartedCount;
}

void AJMJumpScareTestActor::OnJumpScareImpact_Implementation(UJMJumpScareDefinition* Definition)
{
    ++ImpactCount;
}

void AJMJumpScareTestActor::OnJumpScareExiting_Implementation(UJMJumpScareDefinition* Definition)
{
    ++ExitingCount;
}

void AJMJumpScareTestActor::OnJumpScareFinished_Implementation(UJMJumpScareDefinition* Definition)
{
    ++FinishedCount;
}

void AJMJumpScareTestActor::OnJumpScareCancelled_Implementation(UJMJumpScareDefinition* Definition)
{
    ++CancelledCount;
}
