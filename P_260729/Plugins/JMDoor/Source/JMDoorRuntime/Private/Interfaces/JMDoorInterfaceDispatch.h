#pragma once

#include "Door/JMDoorTypes.h"

class UObject;
class AActor;

namespace JMDoorInterfaceDispatch
{
    FGameplayTagContainer GetAccessTags(AActor* Provider);
    bool CanProvideAccess(AActor* Provider, const FJMDoorAccessRequirement& Requirement);
    bool ConsumeAccess(AActor* Provider, const FJMDoorAccessRequirement& Requirement);

    FJMDoorResult ExecuteDoorCommand(UObject* DoorObject, EJMDoorCommand Command, const FJMDoorUseContext& Context);
}
