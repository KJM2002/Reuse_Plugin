#include "Data/JMObjectiveDefinition.h"

FPrimaryAssetId UJMObjectiveDefinition::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(TEXT("JMObjective"), ObjectiveId.IsValid() ? ObjectiveId.GetTagName() : GetFName());
}
