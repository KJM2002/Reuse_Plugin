#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/SoftObjectPtr.h"
#include "JMPrototypeLevelPortal.generated.h"

class UNiagaraComponent;
class UPrimitiveComponent;
class USphereComponent;
class UWorld;
struct FHitResult;

/** Minimal player-overlap portal. It owns no quest, inventory, or progression logic. */
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
	TSoftObjectPtr<UWorld> DestinationWorld;

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
	void RecheckPlayerInsidePortal();

	bool bTravelStarted = false;
	FTimerHandle RecheckTimerHandle;
};
