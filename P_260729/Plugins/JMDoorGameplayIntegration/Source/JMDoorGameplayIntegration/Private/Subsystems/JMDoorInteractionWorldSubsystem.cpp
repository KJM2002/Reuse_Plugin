#include "Subsystems/JMDoorInteractionWorldSubsystem.h"

#include "Actors/JMDoorActor.h"
#include "Components/JMDoorInteractableAdapterComponent.h"
#include "EngineUtils.h"
#include "Engine/World.h"

bool UJMDoorInteractionWorldSubsystem::DoesSupportWorldType(EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE || WorldType == EWorldType::GamePreview;
}

void UJMDoorInteractionWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    if (UWorld* World = GetWorld())
    {
        ActorSpawnedHandle = World->AddOnActorSpawnedHandler(FOnActorSpawned::FDelegate::CreateUObject(this, &UJMDoorInteractionWorldSubsystem::HandleActorSpawned));
    }
}

void UJMDoorInteractionWorldSubsystem::Deinitialize()
{
    if (UWorld* World = GetWorld(); World && ActorSpawnedHandle.IsValid())
    {
        World->RemoveOnActorSpawnedHandler(ActorSpawnedHandle);
    }
    ActorSpawnedHandle.Reset();
    Super::Deinitialize();
}

void UJMDoorInteractionWorldSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
    Super::OnWorldBeginPlay(InWorld);
    for (TActorIterator<AJMDoorActor> It(&InWorld); It; ++It)
    {
        EnsureDoorAdapter(*It);
    }
}

void UJMDoorInteractionWorldSubsystem::HandleActorSpawned(AActor* Actor)
{
    EnsureDoorAdapter(Actor);
}

void UJMDoorInteractionWorldSubsystem::EnsureDoorAdapter(AActor* Actor)
{
    AJMDoorActor* Door = Cast<AJMDoorActor>(Actor);
    if (!Door || Door->FindComponentByClass<UJMDoorInteractableAdapterComponent>())
    {
        return;
    }

    UJMDoorInteractableAdapterComponent* Adapter = NewObject<UJMDoorInteractableAdapterComponent>(Door, TEXT("JMDoorInteractableAdapter"));
    Door->AddInstanceComponent(Adapter);
    Adapter->RegisterComponent();
}
