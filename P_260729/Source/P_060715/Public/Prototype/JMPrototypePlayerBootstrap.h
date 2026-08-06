#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/JMInteractionTypes.h"
#include "UObject/SoftObjectPtr.h"
#include "JMPrototypePlayerBootstrap.generated.h"

class UInputAction;
class UInputMappingContext;
class UInventoryItemDefinition;
class UInventoryWidgetBase;
class UJMPrototypeHUDWidget;

/** Adds the reusable prototype components and input bindings to the existing project pawn at runtime. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypePlayerBootstrap : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypePlayerBootstrap();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Input")
	TSoftObjectPtr<UInputAction> InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Input")
	TSoftObjectPtr<UInputAction> InventoryAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Input")
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|UI")
	TSoftClassPtr<UInventoryWidgetBase> InventoryWidgetClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Prototype|Reset")
	TObjectPtr<AActor> BaseRespawnTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Reset")
	TArray<TObjectPtr<UInventoryItemDefinition>> RunOnlyItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Reset")
	FName FailureLevelName;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void SetupPlayer();
	void HandleInteract();

	UFUNCTION()
	void HandleInteractionFinished(UObject* Interactable, FJMInteractionResult Result);

	FTimerHandle SetupTimer;
	TWeakObjectPtr<APawn> PlayerPawn;
	TWeakObjectPtr<UJMPrototypeHUDWidget> PrototypeHUD;
	bool bInputBound = false;
};
