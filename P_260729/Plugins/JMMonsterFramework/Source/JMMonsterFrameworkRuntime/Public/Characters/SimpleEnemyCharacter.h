#pragma once

#include "GameFramework/Character.h"
#include "SimpleEnemyCharacter.generated.h"

/**
 * Minimal enemy body for Phase 0 possession and movement validation.
 * Uses only ACharacter's inherited capsule, skeletal mesh, and movement component.
 */
UCLASS(BlueprintType, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API ASimpleEnemyCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASimpleEnemyCharacter();
};
