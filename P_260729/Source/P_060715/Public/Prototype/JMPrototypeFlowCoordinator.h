#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeFlowCoordinator.generated.h"

/** Place once in the active prototype map; owns editable prototype tuning and startup. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeFlowCoordinator : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeFlowCoordinator();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype")
	FJMPrototypeConfig PrototypeConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype")
	bool bResetPermanentProgressOnBeginPlay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype")
	bool bApplyCapacityToPlayerInventory = true;

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Upgrade Prototype")
	void OnPrototypeConfigured(const FJMPrototypeOperationResult& Result);

protected:
	virtual void BeginPlay() override;
};
