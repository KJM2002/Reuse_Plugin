#pragma once

#include "Core/JMEnemyBase.h"
#include "JMSurfaceCrawlerEnemyBase.generated.h"

/** Locomotion-only shell: behavior, memory, perception, and actions remain AJMEnemyBase systems. */
UCLASS(Abstract, Blueprintable)
class JMMONSTERFRAMEWORKRUNTIME_API AJMSurfaceCrawlerEnemyBase : public AJMEnemyBase
{
    GENERATED_BODY()

public:
    explicit AJMSurfaceCrawlerEnemyBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
