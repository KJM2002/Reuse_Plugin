#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMPrototypeGeneratedDungeonDirector.generated.h"

class AJMGridMapGenerator;
class UInventoryItemDefinition;
class UStaticMesh;

/** Populates the rooms produced by JMRoomGrid with prototype pickups and one roaming monster. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeGeneratedDungeonDirector : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeGeneratedDungeonDirector();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Prototype|Generated Dungeon")
	TObjectPtr<AJMGridMapGenerator> MapGenerator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Items")
	TObjectPtr<UInventoryItemDefinition> SlimeSample;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Items")
	TObjectPtr<UInventoryItemDefinition> SlimeSac;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Items")
	TObjectPtr<UInventoryItemDefinition> Scrap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Items")
	TObjectPtr<UInventoryItemDefinition> EmergencyBattery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Visuals")
	TObjectPtr<UStaticMesh> SampleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Visuals")
	TObjectPtr<UStaticMesh> SacMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Visuals")
	TObjectPtr<UStaticMesh> ScrapMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Visuals")
	TObjectPtr<UStaticMesh> BatteryMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype|Generated Dungeon|Visuals")
	TObjectPtr<UStaticMesh> MonsterMesh;

	UFUNCTION(BlueprintCallable, Category = "Prototype|Generated Dungeon")
	bool PopulateGeneratedDungeon();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void TryPopulate();

	FTimerHandle PopulateTimer;
	bool bPopulated = false;
};
