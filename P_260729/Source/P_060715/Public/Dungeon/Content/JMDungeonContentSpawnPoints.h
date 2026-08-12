#pragma once

#include "Components/BillboardComponent.h"
#include "CoreMinimal.h"
#include "JMDungeonContentSpawnPoints.generated.h"

class AJMDungeonMonster;
class UInventoryItemDefinition;
class UStaticMesh;

/** Determines how an authored item marker participates in dungeon population. */
UENUM(BlueprintType)
enum class EJMDungeonItemSelectionPolicy : uint8
{
	Guaranteed UMETA(DisplayName="Always Spawn"),
	Optional UMETA(DisplayName="Spawn By Chance"),
	UniqueGroup UMETA(DisplayName="Pick One Marker From Group")
};

UENUM(BlueprintType)
enum class EJMDungeonAIRoutePointRole : uint8
{
	Home,
	Patrol,
	Ambush,
	Exit
};

/** One weighted item choice stored directly on a room-local billboard marker. */
USTRUCT(BlueprintType)
struct P_060715_API FJMDungeonItemSpawnOption
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content")
	TObjectPtr<UInventoryItemDefinition> ItemDefinition = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content")
	TObjectPtr<UStaticMesh> PickupMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content", meta=(ClampMin="1"))
	int32 Weight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content", meta=(ClampMin="1"))
	int32 MinQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content", meta=(ClampMin="1"))
	int32 MaxQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content")
	FVector PickupMeshScale = FVector(0.35f);

	/** Empty text uses "Pick up {DisplayName}". */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content")
	FText PickupPromptOverride;
};

/** Visible-in-editor, hidden-in-game item location authored inside a room Blueprint. */
UCLASS(ClassGroup=(Dungeon), meta=(BlueprintSpawnableComponent, DisplayName="Dungeon Item Spawn Point"))
class P_060715_API UJMDungeonItemSpawnPointComponent : public UBillboardComponent
{
	GENERATED_BODY()

public:
	UJMDungeonItemSpawnPointComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Identity")
	FName SlotId = TEXT("ItemSlot");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Selection")
	EJMDungeonItemSelectionPolicy SelectionPolicy = EJMDungeonItemSelectionPolicy::Optional;

	/** Markers with the same non-empty group compete globally when policy is UniqueGroup. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Selection",
		meta=(EditCondition="SelectionPolicy == EJMDungeonItemSelectionPolicy::UniqueGroup"))
	FName SelectionGroup = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Selection", meta=(ClampMin="0.0", ClampMax="1.0"))
	float SpawnChance = 0.65f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Selection", meta=(ClampMin="1"))
	int32 MarkerWeight = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon Content|Selection", meta=(TitleProperty="ItemDefinition"))
	TArray<FJMDungeonItemSpawnOption> ItemOptions;
};

/** AI actor appears at this room-local marker after generation and navmesh readiness. */
UCLASS(ClassGroup=(Dungeon), meta=(BlueprintSpawnableComponent, DisplayName="Dungeon AI Entry Point"))
class P_060715_API UJMDungeonAIEntryPointComponent : public UBillboardComponent
{
	GENERATED_BODY()

public:
	UJMDungeonAIEntryPointComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Identity")
	FName EntryId = TEXT("AIEntry");

	/** Empty request group accepts any entry. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Selection")
	FName EntryGroup = TEXT("Default");

	/** Home and patrol points in the same room with this group are assigned to the spawned AI. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Route")
	FName RouteGroup = TEXT("Primary");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Selection", meta=(ClampMin="1"))
	int32 EntryWeight = 1;

	/** Empty allows every dungeon monster class. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Selection")
	TArray<TSubclassOf<AJMDungeonMonster>> AllowedMonsterClasses;

	bool AllowsMonsterClass(TSubclassOf<AJMDungeonMonster> MonsterClass) const;
};

/** A room-local AI route marker. It remains a component, so rotating the generated room rotates the route. */
UCLASS(ClassGroup=(Dungeon), meta=(BlueprintSpawnableComponent, DisplayName="Dungeon AI Route Point"))
class P_060715_API UJMDungeonAIRoutePointComponent : public UBillboardComponent
{
	GENERATED_BODY()

public:
	UJMDungeonAIRoutePointComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Route")
	FName RouteGroup = TEXT("Primary");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Route")
	EJMDungeonAIRoutePointRole Role = EJMDungeonAIRoutePointRole::Patrol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dungeon AI|Route")
	int32 Order = 0;
};
