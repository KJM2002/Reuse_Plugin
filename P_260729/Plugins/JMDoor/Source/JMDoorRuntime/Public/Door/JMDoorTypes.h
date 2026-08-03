#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JMDoorTypes.generated.h"

class AController;
class AActor;

UENUM(BlueprintType)
enum class EJMDoorState : uint8
{
    Closed,
    Opening,
    Open,
    Closing,
    Locked,
    Blocked,
    Jammed,
    Broken
};

UENUM(BlueprintType)
enum class EJMDoorCommand : uint8
{
    Open,
    Close,
    Toggle,
    Unlock,
    Lock,
    ForceOpen
};

UENUM(BlueprintType)
enum class EJMDoorResultCode : uint8
{
    Succeeded,
    InvalidRequest,
    Disabled,
    AccessDenied,
    Locked,
    AlreadyAtTarget,
    Moving,
    Blocked,
    Jammed,
    Broken,
    MissingMovementComponent
};

UENUM(BlueprintType)
enum class EJMDoorOpenDirectionMode : uint8
{
    Positive,
    Negative,
    AwayFromInteractor,
    TowardInteractor
};

/** Explicit panel selection for a two-panel sliding door. */
UENUM(BlueprintType)
enum class EJMSlideDoorPanel : uint8
{
    DoorA,
    DoorB,
    Both
};

/** Panel(s) opened by the general OpenDoor command. */
UENUM(BlueprintType)
enum class EJMSlideDoorOpenMode : uint8
{
    OpenDoorA,
    OpenDoorB,
    OpenBoth
};

/** How the general OpenDoor command chooses a panel. Movement direction is never changed. */
UENUM(BlueprintType)
enum class EJMSlideDoorPanelSelectionMode : uint8
{
    ConfiguredPanel,
    NearestPanel
};

UENUM(BlueprintType)
enum class EJMDoorBlockBehavior : uint8
{
    Stop,
    Reverse,
    Retry,
    Ignore
};

UENUM(BlueprintType)
enum class EJMDoorAccessMatchMode : uint8
{
    AllRequired,
    AnyRequired
};

USTRUCT(BlueprintType)
struct JMDOORRUNTIME_API FJMDoorAccessRequirement
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Access")
    FGameplayTagContainer RequiredTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Access")
    FGameplayTagContainer MasterAccessTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Access")
    EJMDoorAccessMatchMode MatchMode = EJMDoorAccessMatchMode::AllRequired;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Access")
    bool bConsumeAccess = false;

    bool IsEmpty() const { return RequiredTags.IsEmpty(); }
    bool IsSatisfiedBy(const FGameplayTagContainer& AvailableTags) const;
};

USTRUCT(BlueprintType)
struct JMDOORRUNTIME_API FJMDoorUseContext
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    TObjectPtr<AActor> InstigatorActor = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    TObjectPtr<AController> InstigatorController = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    FVector InteractionLocation = FVector::ZeroVector;

    /** Direction in which the interactor is looking/using. Used to swing away from the interaction. */
    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    FVector InteractionDirection = FVector::ZeroVector;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    FGameplayTagContainer AccessTags;

    /** Optional directly linked key/card/item object. No Gameplay Tags are required. */
    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    TObjectPtr<UObject> AccessObject = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    bool bIsAI = false;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    bool bQuiet = false;

    UPROPERTY(BlueprintReadWrite, Category="JM Door")
    bool bFast = false;

    UPROPERTY(BlueprintReadWrite, Category="JM Door", meta=(ClampMin="0.0", ClampMax="1.0"))
    float RequestedOpenFraction = 1.0f;
};

USTRUCT(BlueprintType)
struct JMDOORRUNTIME_API FJMDoorResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Door")
    bool bSucceeded = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Door")
    EJMDoorResultCode Code = EJMDoorResultCode::InvalidRequest;

    UPROPERTY(BlueprintReadOnly, Category="JM Door")
    FText Message;

    static FJMDoorResult Success(const FText& Message = FText::GetEmpty());
    static FJMDoorResult Failure(EJMDoorResultCode Code, const FText& Message);
};

USTRUCT(BlueprintType)
struct JMDOORRUNTIME_API FJMDoorNoiseEvent
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    FVector Location = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    float Loudness = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    float MaxRange = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    FGameplayTag NoiseTag;

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    TObjectPtr<AActor> SourceActor = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM Door|Noise")
    TObjectPtr<AActor> InstigatorActor = nullptr;
};

USTRUCT(BlueprintType)
struct JMDOORRUNTIME_API FJMDoorSaveData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    int32 Version = 2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    FGuid PersistentId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    EJMDoorState State = EJMDoorState::Closed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    bool bLocked = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    bool bLockBroken = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    float OpenFraction = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    float DoorDurability = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    float LockDurability = 0.0f;

    /** Independent sliding panel progress. Version 1 data migrates OpenFraction to panel A. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    float SlideDoorAOpenFraction = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    float SlideDoorBOpenFraction = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    EJMDoorState SlideDoorAState = EJMDoorState::Closed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Door|Save")
    EJMDoorState SlideDoorBState = EJMDoorState::Closed;
};
