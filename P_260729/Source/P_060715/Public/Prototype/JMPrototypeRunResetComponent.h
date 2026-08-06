#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeRunResetComponent.generated.h"

class UInventoryItemDefinition;

/** Clears configured run-only items and returns its owner to the base. */
UCLASS(ClassGroup = (Prototype), BlueprintType, meta = (BlueprintSpawnableComponent))
class P_060715_API UJMPrototypeRunResetComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UJMPrototypeRunResetComponent();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Base Upgrade Prototype|Failure")
	TObjectPtr<AActor> BaseRespawnTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype|Failure")
	TArray<TObjectPtr<UInventoryItemDefinition>> RunOnlyItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Upgrade Prototype|Failure")
	FName FailureLevelName;

	UFUNCTION(BlueprintCallable, Category = "Base Upgrade Prototype|Failure")
	FJMPrototypeOperationResult FailCurrentRun();

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Upgrade Prototype|Failure")
	void OnRunResetCompleted(const FJMPrototypeOperationResult& Result);
};
