#pragma once

#include "AI/SimpleEnemyAIController.h"
#include "ListenerEnemyAIController.generated.h"

/** Hearing-focused enemy preset that reuses the verified base perception, memory, and actions. */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API AListenerEnemyAIController : public ASimpleEnemyAIController
{
    GENERATED_BODY()

public:
    AListenerEnemyAIController();

    virtual void OnPossess(APawn* InPawn) override;

    /** Enables Sight only while a Hearing-triggered investigation is active. */
    void SetSightConfirmationEnabled(bool bEnabled);
};
