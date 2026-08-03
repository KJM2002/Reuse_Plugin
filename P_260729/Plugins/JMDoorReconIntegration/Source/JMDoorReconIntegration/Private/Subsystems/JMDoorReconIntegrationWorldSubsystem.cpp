#include "Subsystems/JMDoorReconIntegrationWorldSubsystem.h"

#include "Components/JMDoorReconTargetAdapterComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Door/JMDoorComponent.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Settings/JMDoorReconIntegrationSettings.h"

bool UJMDoorReconIntegrationWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    const UWorld* World = Cast<UWorld>(Outer);
    return World && (World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE);
}

void UJMDoorReconIntegrationWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    if (UWorld* World = GetWorld())
    {
        ActorSpawnedHandle = World->AddOnActorSpawnedHandler(
            FOnActorSpawned::FDelegate::CreateUObject(
                this, &UJMDoorReconIntegrationWorldSubsystem::HandleActorSpawned));
    }
}

void UJMDoorReconIntegrationWorldSubsystem::Deinitialize()
{
    if (UWorld* World = GetWorld(); World && ActorSpawnedHandle.IsValid())
    {
        World->RemoveOnActorSpawnedHandler(ActorSpawnedHandle);
    }
    ActorSpawnedHandle.Reset();
    Super::Deinitialize();
}

void UJMDoorReconIntegrationWorldSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
    Super::OnWorldBeginPlay(InWorld);
    if (!GetDefault<UJMDoorReconIntegrationSettings>()->bAutoAddDoorAdapter)
    {
        return;
    }
    for (TActorIterator<AActor> It(&InWorld); It; ++It)
    {
        EnsureAdapter(*It);
    }
}

void UJMDoorReconIntegrationWorldSubsystem::HandleActorSpawned(AActor* Actor)
{
    if (GetDefault<UJMDoorReconIntegrationSettings>()->bAutoAddDoorAdapter)
    {
        EnsureAdapter(Actor);
    }
}

void UJMDoorReconIntegrationWorldSubsystem::EnsureAdapter(AActor* Actor)
{
    if (!Actor ||
        !Actor->FindComponentByClass<UJMDoorComponent>() ||
        !Actor->FindComponentByClass<UJMReconTargetComponent>() ||
        Actor->FindComponentByClass<UJMDoorReconTargetAdapterComponent>())
    {
        return;
    }

    UJMDoorReconTargetAdapterComponent* Adapter =
        NewObject<UJMDoorReconTargetAdapterComponent>(Actor, TEXT("JMDoorReconTargetAdapter"));
    Actor->AddInstanceComponent(Adapter);
    Adapter->RegisterComponent();
}
