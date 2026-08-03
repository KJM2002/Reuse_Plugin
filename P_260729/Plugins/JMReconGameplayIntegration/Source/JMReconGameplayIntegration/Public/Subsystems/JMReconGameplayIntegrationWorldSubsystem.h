#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "JMReconGameplayIntegrationWorldSubsystem.generated.h"

UCLASS()
class JMRECONGAMEPLAYINTEGRATION_API UJMReconGameplayIntegrationWorldSubsystem
    : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual void OnWorldBeginPlay(UWorld& InWorld) override;

private:
    void HandleActorSpawned(AActor* Actor);
    void EnsurePlayerBridge(AActor* Actor);

    FDelegateHandle ActorSpawnedHandle;
};
