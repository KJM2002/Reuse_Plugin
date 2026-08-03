#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "JMDoorReconIntegrationWorldSubsystem.generated.h"

UCLASS()
class JMDOORRECONINTEGRATION_API UJMDoorReconIntegrationWorldSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual void OnWorldBeginPlay(UWorld& InWorld) override;

private:
    void HandleActorSpawned(AActor* Actor);
    void EnsureAdapter(AActor* Actor);
    FDelegateHandle ActorSpawnedHandle;
};
