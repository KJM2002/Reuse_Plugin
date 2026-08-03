#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "JMDoorInteractionWorldSubsystem.generated.h"

/** Automatically equips every JMDoor actor with the JM interaction adapter. */
UCLASS()
class JMDOORGAMEPLAYINTEGRATION_API UJMDoorInteractionWorldSubsystem final : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual void OnWorldBeginPlay(UWorld& InWorld) override;

private:
    void HandleActorSpawned(AActor* Actor);
    void EnsureDoorAdapter(AActor* Actor);
    FDelegateHandle ActorSpawnedHandle;
};
