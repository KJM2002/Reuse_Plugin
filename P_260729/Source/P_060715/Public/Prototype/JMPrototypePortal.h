#pragma once

#include "CoreMinimal.h"
#include "Prototype/JMPrototypeInteractionActorBase.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypePortal.generated.h"

class UNiagaraComponent;

/** Forgiving gameplay shell for NS_Portal that teleports between base and generated dungeon areas. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypePortal : public AJMPrototypeInteractionActorBase
{
	GENERATED_BODY()

public:
	AJMPrototypePortal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<UNiagaraComponent> PortalEffect;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Portal")
	TObjectPtr<AActor> DestinationActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	EJMPrototypePortalDirection Direction = EJMPrototypePortalDirection::EnterDungeon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	FVector ArrivalOffset = FVector::ZeroVector;

protected:
	virtual bool IsPrototypeInteractionAvailable(const FJMInteractionContext& Context) const override;
	virtual FJMPrototypeOperationResult PerformPrototypeInteraction(const FJMInteractionContext& Context) override;
};
