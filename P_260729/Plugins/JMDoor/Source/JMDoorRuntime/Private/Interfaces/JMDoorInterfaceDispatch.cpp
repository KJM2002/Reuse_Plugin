#include "Interfaces/JMDoorInterfaceDispatch.h"

#include "Interfaces/JMDoorAccessProviderInterface.h"
#include "Interfaces/JMDoorUsableInterface.h"
#include "GameFramework/Actor.h"
#include "UObject/Class.h"

namespace
{
    bool UsesBlueprintImplementation(const UObject* Object, const FName FunctionName)
    {
        return IsValid(Object) && Object->GetClass()->IsFunctionImplementedInScript(FunctionName);
    }
}

FGameplayTagContainer JMDoorInterfaceDispatch::GetAccessTags(AActor* Provider)
{
    if (!IsValid(Provider))
    {
        return FGameplayTagContainer();
    }
    if (IJMDoorAccessProviderInterface* Native = Cast<IJMDoorAccessProviderInterface>(Provider);
        Native && !UsesBlueprintImplementation(Provider, GET_FUNCTION_NAME_CHECKED(IJMDoorAccessProviderInterface, GetDoorAccessTags)))
    {
        return Native->GetDoorAccessTags_Implementation();
    }
    return IJMDoorAccessProviderInterface::Execute_GetDoorAccessTags(Provider);
}

bool JMDoorInterfaceDispatch::CanProvideAccess(AActor* Provider, const FJMDoorAccessRequirement& Requirement)
{
    if (!IsValid(Provider))
    {
        return false;
    }
    if (IJMDoorAccessProviderInterface* Native = Cast<IJMDoorAccessProviderInterface>(Provider);
        Native && !UsesBlueprintImplementation(Provider, GET_FUNCTION_NAME_CHECKED(IJMDoorAccessProviderInterface, CanProvideDoorAccess)))
    {
        return Native->CanProvideDoorAccess_Implementation(Requirement);
    }
    return IJMDoorAccessProviderInterface::Execute_CanProvideDoorAccess(Provider, Requirement);
}

bool JMDoorInterfaceDispatch::ConsumeAccess(AActor* Provider, const FJMDoorAccessRequirement& Requirement)
{
    if (!IsValid(Provider))
    {
        return false;
    }
    if (IJMDoorAccessProviderInterface* Native = Cast<IJMDoorAccessProviderInterface>(Provider);
        Native && !UsesBlueprintImplementation(Provider, GET_FUNCTION_NAME_CHECKED(IJMDoorAccessProviderInterface, ConsumeDoorAccess)))
    {
        return Native->ConsumeDoorAccess_Implementation(Requirement);
    }
    return IJMDoorAccessProviderInterface::Execute_ConsumeDoorAccess(Provider, Requirement);
}

FJMDoorResult JMDoorInterfaceDispatch::ExecuteDoorCommand(UObject* DoorObject, EJMDoorCommand Command, const FJMDoorUseContext& Context)
{
    if (!IsValid(DoorObject))
    {
        return FJMDoorResult::Failure(EJMDoorResultCode::InvalidRequest, NSLOCTEXT("JMDoor", "InvalidDoorObject", "The door object is invalid."));
    }
    if (IJMDoorUsableInterface* Native = Cast<IJMDoorUsableInterface>(DoorObject);
        Native && !UsesBlueprintImplementation(DoorObject, GET_FUNCTION_NAME_CHECKED(IJMDoorUsableInterface, ExecuteDoorCommand)))
    {
        return Native->ExecuteDoorCommand_Implementation(Command, Context);
    }
    return IJMDoorUsableInterface::Execute_ExecuteDoorCommand(DoorObject, Command, Context);
}
