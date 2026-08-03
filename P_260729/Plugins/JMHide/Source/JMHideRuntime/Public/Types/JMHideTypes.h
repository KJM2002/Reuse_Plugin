#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "JMHideTypes.generated.h"

class AActor;
class UJMHideInteractorComponent;
class UJMHideMechanismComponent;
class UJMHideParticipantDriverComponent;
class UJMHideSpotComponent;

UENUM(BlueprintType)
enum class EJMHidePhase : uint8
{
    None,
    Reserving,
    PreparingEnter,
    Opening,
    Entering,
    ClosingAfterEnter,
    Hidden,
    PreparingExit,
    OpeningForExit,
    Exiting,
    ClosingAfterExit,
    CleaningUp,
    Completed,
    Cancelled,
    Failed
};

UENUM(BlueprintType)
enum class EJMHideSpotState : uint8
{
    Disabled,
    Available,
    Reserved,
    Occupied
};

UENUM(BlueprintType)
enum class EJMHideSpotArchetype : uint8
{
    OpenSpace,
    Enclosed,
    Custom
};

UENUM(BlueprintType)
enum class EJMHideAnchorRole : uint8
{
    Entry,
    Occupant,
    Camera,
    PrimaryExit,
    AlternativeExit,
    Investigation
};

UENUM(BlueprintType)
enum class EJMHideOperation : uint8
{
    None,
    PrepareEnter,
    Enter,
    CompleteEnter,
    PrepareExit,
    Exit,
    CompleteExit,
    Restore
};

UENUM(BlueprintType)
enum class EJMHideFailureCode : uint8
{
    None,
    AlreadyActive,
    InvalidState,
    InvalidParticipant,
    UnsupportedParticipant,
    InvalidSpot,
    SpotDisabled,
    SpotUnavailable,
    MissingAnchor,
    MissingMechanism,
    InvalidMechanism,
    OperationRejected,
    OperationFailed,
    ExitBlocked,
    Cancelled,
    TargetDestroyed
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bSucceeded = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    EJMHideFailureCode Code = EJMHideFailureCode::InvalidState;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FText Message;

    static FJMHideResult Success(const FText& Message = FText::GetEmpty());
    static FJMHideResult Failure(EJMHideFailureCode Code, const FText& Message = FText::GetEmpty());
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideConfigValues
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(ClampMin="0.0", Units="s"))
    float EnterDuration = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(ClampMin="0.0", Units="s"))
    float ExitDuration = 0.25f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(ClampMin="0.0", Units="s"))
    float CameraBlendDuration = 0.2f;

    /** Use a short fade instead of spatially blending the camera through solid geometry. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Camera")
    bool bUseCameraFadeTransition = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bUseEntryAnchor = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bHideParticipant = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bDisableCollision = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bForceExitIgnoresCollision = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Look")
    bool bAllowLimitedLook = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Look",
        meta=(EditCondition="bAllowLimitedLook", ClampMin="0.0", ClampMax="180.0", Units="deg"))
    float LookYawLimit = 55.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide|Look",
        meta=(EditCondition="bAllowLimitedLook", ClampMin="0.0", ClampMax="89.0", Units="deg"))
    float LookPitchLimit = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    FText ExitPrompt = NSLOCTEXT("JMHide", "DefaultExitPrompt", "Exit");
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideConfigOverride
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bOverride = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(EditCondition="bOverride"))
    FJMHideConfigValues Values;
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMResolvedHideConfig : public FJMHideConfigValues
{
    GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    FJMHideConfigOverride ConfigOverride;
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideOperationContext
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    TObjectPtr<AActor> Participant = nullptr;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FTransform EntryTransform = FTransform::Identity;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FTransform OccupantTransform = FTransform::Identity;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FTransform CameraTransform = FTransform::Identity;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FTransform ExitTransform = FTransform::Identity;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FJMResolvedHideConfig Config;
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideOperationCompletion
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FGuid SessionId;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    EJMHideOperation Operation = EJMHideOperation::None;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bSucceeded = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    EJMHideFailureCode FailureCode = EJMHideFailureCode::OperationFailed;
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideParticipantSnapshot
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bCaptured = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedMovement = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedTransform = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedCollision = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedVisibility = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedViewTarget = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bChangedLookConstraint = false;
};

USTRUCT(BlueprintType)
struct JMHIDERUNTIME_API FJMHideSession
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FGuid SessionId;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    EJMHidePhase CurrentPhase = EJMHidePhase::None;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FJMResolvedHideConfig ResolvedConfig;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FTransform SelectedExit = FTransform::Identity;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    FJMHideParticipantSnapshot OriginalStateSnapshot;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bCleanupStarted = false;

    UPROPERTY(BlueprintReadOnly, Category="JM Hide")
    bool bCleanupCompleted = false;

    TWeakObjectPtr<UJMHideInteractorComponent> Interactor;
    TWeakObjectPtr<UJMHideSpotComponent> HideSpot;
    TWeakObjectPtr<UJMHideParticipantDriverComponent> ParticipantDriver;
    TWeakObjectPtr<UJMHideMechanismComponent> MechanismProvider;

    bool IsActive() const
    {
        return SessionId.IsValid() && !bCleanupCompleted &&
            CurrentPhase != EJMHidePhase::None &&
            CurrentPhase != EJMHidePhase::Completed &&
            CurrentPhase != EJMHidePhase::Cancelled &&
            CurrentPhase != EJMHidePhase::Failed;
    }
};
