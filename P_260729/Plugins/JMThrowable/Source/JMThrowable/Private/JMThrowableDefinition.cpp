#include "JMThrowableDefinition.h"
#include "NiagaraSystem.h"

UJMThrowableDefinition::UJMThrowableDefinition()
{
    TrajectoryNiagaraSystem = TSoftObjectPtr<UNiagaraSystem>(
        FSoftObjectPath(TEXT(
            "/JMThrowable/Effects/NS_JMThrowableTrajectory.NS_JMThrowableTrajectory")));
    TrajectoryMaterial = TSoftObjectPtr<UMaterialInterface>(
        FSoftObjectPath(TEXT("/JMThrowable/Materials/M_ThrowableTrajectory.M_ThrowableTrajectory")));
}
