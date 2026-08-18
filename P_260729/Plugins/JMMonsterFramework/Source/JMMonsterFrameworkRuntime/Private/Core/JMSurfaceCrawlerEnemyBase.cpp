#include "Core/JMSurfaceCrawlerEnemyBase.h"

#include "Locomotion/JMEnemyLocomotion_SurfaceCrawler.h"

AJMSurfaceCrawlerEnemyBase::AJMSurfaceCrawlerEnemyBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UJMEnemyLocomotion_SurfaceCrawler>(TEXT("EnemyLocomotion")))
{
}
