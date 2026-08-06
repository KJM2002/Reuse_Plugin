#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeLevelPortal.generated.h"

class UNiagaraComponent;
class UPrimitiveComponent;
class USphereComponent;
class UInventoryItemDefinition;
class UWorld;
struct FHitResult;

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

private:
	UFUNCTION()
	void HandleOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	void TryTravel(AActor* OtherActor);
	void RecheckPlayerInsidePortal();
	void HandleTravelWatchdog();
	bool ResolveDestinationPackage(FName& OutPackageName) const;

	bool bTravelStarted = false;
	EJMPrototypeRunState StateBeforeTravel = EJMPrototypeRunState::AwaitingQuest;
	FTimerHandle OverlapRecheckHandle;
	FTimerHandle TravelWatchdogHandle;
};
