#pragma once

#include "CoreMinimal.h"
#include "JMReconTypes.generated.h"

class AActor;
class UJMReconInteractorComponent;
class UJMReconTargetComponent;

UENUM(BlueprintType)
enum class EJMReconState : uint8
{
    Idle,
    Entering,
    Listening,
    Peeking,
    Exiting
};

UENUM(BlueprintType)
enum class EJMReconInitialObservationMode : uint8
{
    Listen,
    Peek
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EJMReconMode : uint8
{
    None       = 0,
    Listen     = 1 << 0,
    Peek       = 1 << 1,
    Illuminate = 1 << 2
};
ENUM_CLASS_FLAGS(EJMReconMode);

UENUM(BlueprintType)
enum class EJMReconFailureReason : uint8
{
    None,
    AlreadyActive,
    AlreadyInUse,
    InvalidInteractor,
    InvalidTarget,
    TargetDestroyed,
    Disabled,
    OutOfRange,
    DoorOpen,
    DoorMoving,
    Blocked,
    NotSupported,
    InvalidState,
    DefinitionInvalid
};

UENUM(BlueprintType)
enum class EJMReconEndReason : uint8
{
    Completed,
    Cancelled,
    TargetDestroyed,
    InteractorDestroyed,
    TargetInvalidated,
    EndPlay
};

USTRUCT(BlueprintType)
struct JMRECONRUNTIME_API FJMReconRequestResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    bool bSucceeded = false;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    EJMReconFailureReason FailureReason = EJMReconFailureReason::None;

    static FJMReconRequestResult Success()
    {
        FJMReconRequestResult Result;
        Result.bSucceeded = true;
        return Result;
    }

    static FJMReconRequestResult Failure(EJMReconFailureReason Reason)
    {
        FJMReconRequestResult Result;
        Result.FailureReason = Reason;
        return Result;
    }
};

USTRUCT(BlueprintType)
struct JMRECONRUNTIME_API FJMReconSession
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    FGuid SessionId;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    EJMReconState CurrentState = EJMReconState::Idle;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    bool bIsIlluminating = false;

    TWeakObjectPtr<UJMReconInteractorComponent> Interactor;
    TWeakObjectPtr<UJMReconTargetComponent> Target;
    /** Actor or ActorComponent that accepted the target contract for this session. */
    TWeakObjectPtr<UObject> TargetContract;

    bool IsActive() const
    {
        return SessionId.IsValid() && CurrentState != EJMReconState::Idle;
    }
};

USTRUCT(BlueprintType)
struct JMRECONRUNTIME_API FJMReconNoiseEvent
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    FVector Location = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly, Category="Recon", meta=(ClampMin="0.0"))
    float Loudness = 0.0f;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    FName NoiseType = NAME_None;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    TObjectPtr<AActor> Instigator = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="Recon")
    TObjectPtr<AActor> Target = nullptr;
};
