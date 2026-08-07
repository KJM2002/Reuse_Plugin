#pragma once

#include "CoreMinimal.h"
#include "JMPrototypeTypes.generated.h"

UENUM(BlueprintType)
enum class EJMPrototypeRunState : uint8
{
	AwaitingQuest,
	QuestAccepted,
	Exploring,
	Returned,
	QuestCompleted
};

UENUM(BlueprintType)
enum class EJMPrototypeOperationCode : uint8
{
	Success,
	InvalidState,
	InvalidConfiguration,
	MissingInventory,
	MissingItemDefinition,
	InsufficientItems,
	InsufficientCurrency,
	AlreadyPurchased,
	InventoryCapacityRejected,
	MissingDestination,
	TravelFailed
};

USTRUCT(BlueprintType)
struct P_060715_API FJMPrototypeOperationResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Base Upgrade Prototype")
	bool bSucceeded = false;

	UPROPERTY(BlueprintReadOnly, Category = "Base Upgrade Prototype")
	EJMPrototypeOperationCode Code = EJMPrototypeOperationCode::InvalidState;

	UPROPERTY(BlueprintReadOnly, Category = "Base Upgrade Prototype")
	FText Message;

	static FJMPrototypeOperationResult Success(const FText& InMessage = FText::GetEmpty());
	static FJMPrototypeOperationResult Failure(EJMPrototypeOperationCode InCode, const FText& InMessage);
};

USTRUCT(BlueprintType)
struct P_060715_API FJMPrototypeConfig
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (ClampMin = "0"))
	int32 InitialCurrency = 80;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (ClampMin = "0"))
	int32 QuestReward = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (ClampMin = "0"))
	int32 SecondQuestReward = 90;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (ClampMin = "0"))
	int32 CookingReward = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade", meta = (ClampMin = "0"))
	int32 InventoryUpgradeCost = 80;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade", meta = (ClampMin = "1"))
	int32 BaseInventorySlots = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade", meta = (ClampMin = "1"))
	int32 UpgradedInventorySlots = 6;

	bool IsValid() const
	{
		return InitialCurrency >= 0 && QuestReward >= 0 && SecondQuestReward >= 0 && CookingReward >= 0
			&& InventoryUpgradeCost >= 0 && BaseInventorySlots > 0
			&& UpgradedInventorySlots > BaseInventorySlots;
	}
};

UENUM(BlueprintType)
enum class EJMPrototypePortalDirection : uint8
{
	EnterDungeon,
	ReturnToBase
};
