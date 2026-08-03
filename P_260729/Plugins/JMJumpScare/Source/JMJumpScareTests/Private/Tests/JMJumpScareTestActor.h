#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/JMJumpScareActorInterface.h"
#include "JMJumpScareTestActor.generated.h"

UCLASS()
class AJMJumpScareTestActor : public AActor, public IJMJumpScareActorInterface
{
    GENERATED_BODY()

public:
    AJMJumpScareTestActor();
    virtual void OnJumpScareStarted_Implementation(UJMJumpScareDefinition* Definition) override;
    virtual void OnJumpScareImpact_Implementation(UJMJumpScareDefinition* Definition) override;
    virtual void OnJumpScareExiting_Implementation(UJMJumpScareDefinition* Definition) override;
    virtual void OnJumpScareFinished_Implementation(UJMJumpScareDefinition* Definition) override;
    virtual void OnJumpScareCancelled_Implementation(UJMJumpScareDefinition* Definition) override;

    UPROPERTY(Transient)
    int32 StartedCount = 0;

    UPROPERTY(Transient)
    int32 ImpactCount = 0;

    UPROPERTY(Transient)
    int32 ExitingCount = 0;

    UPROPERTY(Transient)
    int32 FinishedCount = 0;

    UPROPERTY(Transient)
    int32 CancelledCount = 0;
};
