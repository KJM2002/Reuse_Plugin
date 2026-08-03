#include "Subsystems/JMReconGameplayIntegrationWorldSubsystem.h"

#include "Components/JMInteractionComponent.h"
#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconPlayerBridgeComponent.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Settings/JMReconGameplayIntegrationSettings.h"

bool UJMReconGameplayIntegrationWorldSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    const UWorld* World = Cast<UWorld>(Outer);
    return World &&
        (World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE);
}

void UJMReconGameplayIntegrationWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    if (UWorld* World = GetWorld())
    {
        ActorSpawnedHandle = World->AddOnActorSpawnedHandler(
            FOnActorSpawned::FDelegate::CreateUObject(
                this,
                &UJMReconGameplayIntegrationWorldSubsystem::HandleActorSpawned));
    }
}

void UJMReconGameplayIntegrationWorldSubsystem::Deinitialize()
{
    if (UWorld* World = GetWorld(); World && ActorSpawnedHandle.IsValid())
    {
        World->RemoveOnActorSpawnedHandler(ActorSpawnedHandle);
    }
    ActorSpawnedHandle.Reset();
    Super::Deinitialize();
}

void UJMReconGameplayIntegrationWorldSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
    Super::OnWorldBeginPlay(InWorld);
    if (!GetDefault<UJMReconGameplayIntegrationSettings>()->bAutoAddPlayerBridge)
    {
        return;
    }
    for (TActorIterator<APawn> It(&InWorld); It; ++It)
    {
        EnsurePlayerBridge(*It);
    }
}

void UJMReconGameplayIntegrationWorldSubsystem::HandleActorSpawned(AActor* Actor)
{
    if (GetDefault<UJMReconGameplayIntegrationSettings>()->bAutoAddPlayerBridge)
    {
        EnsurePlayerBridge(Actor);
    }
}

void UJMReconGameplayIntegrationWorldSubsystem::EnsurePlayerBridge(AActor* Actor)
{
    APawn* Pawn = Cast<APawn>(Actor);
    if (!Pawn ||
        !Pawn->FindComponentByClass<UJMInteractionComponent>() ||
        !Pawn->FindComponentByClass<UJMReconInteractorComponent>() ||
        Pawn->FindComponentByClass<UJMReconPlayerBridgeComponent>())
    {
        return;
    }

    UJMReconPlayerBridgeComponent* Bridge =
        NewObject<UJMReconPlayerBridgeComponent>(Pawn, TEXT("JMReconPlayerBridge"));
    Pawn->AddInstanceComponent(Bridge);
    Bridge->RegisterComponent();
}
