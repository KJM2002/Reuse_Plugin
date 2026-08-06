#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeLevelPortal.generated.h"

class UNiagaraComponent;
class USphereComponent;
class UInventoryItemDefinition;
class UWorld;

/** Niagara-backed overlap portal. It deliberately does not participate in the interaction UI. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeLevelPortal : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeLevelPortal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<USphereComponent> OverlapArea;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<UNiagaraComponent> PortalEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	FName DestinationLevel;

	/** Asset-backed destination used for validated travel. DestinationLevel remains as a legacy fallback. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UWorld> DestinationWorld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	EJMPrototypePortalDirection Direction = EJMPrototypePortalDirection::EnterDungeon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TArray<TObjectPtr<UInventoryItemDefinition>> TravelItems;

	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	void HandleTravelWatchdog();
	bool ResolveDestinationPackage(FName& OutPackageName) const;

	bool bTravelStarted = false;
	EJMPrototypeRunState StateBeforeTravel = EJMPrototypeRunState::AwaitingQuest;
	FTimerHandle TravelWatchdogHandle;
};
