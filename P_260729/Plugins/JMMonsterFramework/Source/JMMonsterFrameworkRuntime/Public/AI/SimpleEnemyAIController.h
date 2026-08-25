#pragma once

#include "AIController.h"
#include "SimpleEnemyAIController.generated.h"

/**
 * Minimal controller used to verify that an enemy pawn can be possessed.
 * Behavior systems intentionally belong to later phases.
 */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API ASimpleEnemyAIController : public AAIController
{
    GENERATED_BODY()

public:
    ASimpleEnemyAIController();
};
