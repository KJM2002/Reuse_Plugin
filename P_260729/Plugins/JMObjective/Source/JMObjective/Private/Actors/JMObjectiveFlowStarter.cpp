#include "Actors/JMObjectiveFlowStarter.h"

#include "Data/JMObjectiveFlowDefinition.h"
#include "Engine/GameInstance.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"

AJMObjectiveFlowStarter::AJMObjectiveFlowStarter()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AJMObjectiveFlowStarter::BeginPlay()
{
    Super::BeginPlay();
    if (bStartOnBeginPlay && IsValid(FlowDefinition))
    {
        if (UGameInstance* GameInstance = GetGameInstance())
        {
            if (UJMObjectiveFlowSubsystem* FlowSubsystem = GameInstance->GetSubsystem<UJMObjectiveFlowSubsystem>())
            {
                FlowSubsystem->StartObjectiveFlow(FlowDefinition);
            }
        }
    }
}

void AJMObjectiveFlowStarter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (bResetFlowOnEndPlay && IsValid(FlowDefinition))
    {
        if (UGameInstance* GameInstance = GetGameInstance())
        {
            if (UJMObjectiveFlowSubsystem* FlowSubsystem = GameInstance->GetSubsystem<UJMObjectiveFlowSubsystem>())
            {
                FlowSubsystem->ResetObjectiveFlow(FlowDefinition->FlowId);
            }
        }
    }
    Super::EndPlay(EndPlayReason);
}

