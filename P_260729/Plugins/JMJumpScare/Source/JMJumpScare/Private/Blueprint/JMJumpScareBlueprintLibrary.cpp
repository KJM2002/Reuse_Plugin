#include "Blueprint/JMJumpScareBlueprintLibrary.h"

#include "Engine/Engine.h"
#include "Subsystems/JMJumpScareSubsystem.h"

namespace
{
    UJMJumpScareSubsystem* JMGetJumpScareSubsystem(UObject* WorldContextObject)
    {
        UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
        return World ? World->GetSubsystem<UJMJumpScareSubsystem>() : nullptr;
    }
}

EJMJumpScarePlayResult UJMJumpScareBlueprintLibrary::PlayJumpScare(
    UObject* WorldContextObject,
    UJMJumpScareDefinition* Definition,
    APlayerController* TargetPlayer)
{
    UJMJumpScareSubsystem* Subsystem = JMGetJumpScareSubsystem(WorldContextObject);
    if (!Subsystem)
    {
        return EJMJumpScarePlayResult::InvalidWorld;
    }
    FJMJumpScarePlayContext Context;
    Context.WorldContextObject = WorldContextObject;
    Context.TargetPlayer = TargetPlayer;
    Context.Source = WorldContextObject;
    return Subsystem->PlayJumpScare(Definition, Context);
}

bool UJMJumpScareBlueprintLibrary::CancelJumpScare(UObject* WorldContextObject)
{
    if (UJMJumpScareSubsystem* Subsystem = JMGetJumpScareSubsystem(WorldContextObject))
    {
        return Subsystem->CancelJumpScare();
    }
    return false;
}

bool UJMJumpScareBlueprintLibrary::IsJumpScarePlaying(UObject* WorldContextObject)
{
    const UJMJumpScareSubsystem* Subsystem = JMGetJumpScareSubsystem(WorldContextObject);
    return Subsystem && Subsystem->IsJumpScarePlaying();
}
