#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMPrototypeGeneratedDungeonDirector.generated.h"

class AJMDungeonMonster;
class AJMCustomGridMapGenerator;
class AJMGridMapGenerator;
class AJMRoomModule;
class UJMDungeonAIEntryPointComponent;

/** One editable monster request. Entry and route transforms remain authored by each room Blueprint. */
USTRUCT(BlueprintType)
struct P_060715_API FJMDungeonMonsterSpawnRequest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI")
	TSubclassOf<AJMDungeonMonster> MonsterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI", meta=(ClampMin="0"))
	int32 Count = 1;

	/** None accepts any entry group. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI")
	FName RequiredEntryGroup = NAME_None;

	/** AI stays invisible and non-colliding until this delay and navmesh projection both succeed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI", meta=(ClampMin="0.0"))
	float ActivationDelay = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI")
	bool bPreferUnusedRoom = true;
};

/** Resolves room-authored item and AI billboards only after the generated map validates. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeGeneratedDungeonDirector : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeGeneratedDungeonDirector();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Dungeon Content")
	TObjectPtr<AJMGridMapGenerator> MapGenerator;

	/** Optional custom-grid source. Used when MapGenerator is empty. */
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Dungeon Content")
	TObjectPtr<AJMCustomGridMapGenerator> CustomMapGenerator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|AI", meta=(TitleProperty="MonsterClass"))
	TArray<FJMDungeonMonsterSpawnRequest> MonsterRoster;

	/** If navmesh is still unavailable after this time, the monster remains safely dormant and a warning is logged. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|AI", meta=(ClampMin="1.0"))
	float NavigationReadyTimeout = 15.0f;

	UFUNCTION(BlueprintCallable, Category="Dungeon Content")
	bool PopulateGeneratedDungeon();

	UFUNCTION(BlueprintPure, Category="Dungeon Content")
	bool IsDungeonPopulated() const { return bPopulated; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	struct FPendingMonsterActivation
	{
		TWeakObjectPtr<AJMDungeonMonster> Monster;
		double EarliestTime = 0.0;
		double Deadline = 0.0;
	};

	void TryPopulate();
	void UpdatePendingMonsterActivations();
	bool CollectValidatedRooms(TArray<AJMRoomModule*>& OutRooms, int32& OutSeed) const;
	int32 PopulateItems(FRandomStream& Stream, const TArray<AJMRoomModule*>& Rooms);
	int32 PopulateMonsters(FRandomStream& Stream, const TArray<AJMRoomModule*>& Rooms);

	FTimerHandle PopulateTimer;
	FTimerHandle ActivationTimer;
	TArray<FPendingMonsterActivation> PendingMonsterActivations;
	bool bPopulated = false;
};
