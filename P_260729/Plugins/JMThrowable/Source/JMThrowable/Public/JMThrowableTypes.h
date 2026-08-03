#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "JMThrowableTypes.generated.h"

class AJMThrowableProjectile;
class UJMThrowableDefinition;

UENUM(BlueprintType)
enum class EJMThrowableUseState : uint8
{
    Idle, Ready, Aiming, CommittingThrow
};

UENUM(BlueprintType)
enum class EJMThrowablePreviewRendererMode : uint8
{
    NiagaraPreferred,
    ProceduralOnly
};

UENUM(BlueprintType)
enum class EJMThrowableProjectileState : uint8
{
    Inactive, Flying, Resting, Fuse, Activated, Finished
};

UENUM(BlueprintType)
enum class EJMThrowableSurfaceType : uint8
{
    Floor, Wall, Slope, Ceiling
};

UENUM(BlueprintType)
enum class EJMThrowResultCode : uint8
{
    Success,
    InvalidState,
    NoActiveItem,
    ItemNoLongerExists,
    InvalidDefinition,
    NoLocalView,
    InvalidThrowOrigin,
    BlockedSpawn,
    ProjectileSpawnFailed,
    InventoryConsumeFailed,
    DuplicateCommit
};

USTRUCT(BlueprintType)
struct JMTHROWABLE_API FJMThrowParameters
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector StartPosition = FVector::ZeroVector;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector InitialVelocity = FVector::ZeroVector;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Gravity = FVector(0, 0, -980);
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.1")) float ProjectileRadius = 4.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.001")) float SimulationStep = 1.f / 60.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.01")) float MaximumSimulationTime = 5.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FName CollisionProfile = TEXT("BlockAll");
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="-1.0", ClampMax="1.0")) float FloorNormalThreshold = 0.7f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0")) int32 MaxWallBounces = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float BounceRestitution = 0.08f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float TangentialDamping = 0.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0")) int32 MaxFloorBounces = 3;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float FloorRestitution = .2f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float FloorTangentialDamping = .6f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float FloorBounceDecay = .6f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0")) float FloorBounceStopSpeed = 80.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0")) float SurfaceOffset = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0", ClampMax="1.0")) float FloorFriction = .18f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0")) float FloorStopSpeed = 50.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="0.0")) float DynamicImpactImpulse = 80.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FRotator VisualSpinDegreesPerSecond = FRotator(110.f, 180.f, 75.f);
    UPROPERTY(BlueprintReadWrite) TArray<TObjectPtr<AActor>> IgnoredActors;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bDebugDraw = false;
};

USTRUCT(BlueprintType)
struct JMTHROWABLE_API FJMThrowSimulationState
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly) FVector Position = FVector::ZeroVector;
    UPROPERTY(BlueprintReadOnly) FVector Velocity = FVector::ZeroVector;
    UPROPERTY(BlueprintReadOnly) float ElapsedTime = 0.f;
    UPROPERTY(BlueprintReadOnly) int32 WallBounceCount = 0;
    UPROPERTY(BlueprintReadOnly) int32 FloorBounceCount = 0;
    UPROPERTY(BlueprintReadOnly) bool bResting = false;
};

USTRUCT(BlueprintType)
struct JMTHROWABLE_API FJMThrowSimulationResult
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly) TArray<FVector> Points;
    UPROPERTY(BlueprintReadOnly) TArray<FVector> ImpactPoints;
    UPROPERTY(BlueprintReadOnly) TArray<FVector> ImpactNormals;
    UPROPERTY(BlueprintReadOnly) FVector FinalRestPoint = FVector::ZeroVector;
    UPROPERTY(BlueprintReadOnly) bool bReachedRest = false;
    UPROPERTY(BlueprintReadOnly) int32 WallBounceCount = 0;
    UPROPERTY(BlueprintReadOnly) int32 FloorBounceCount = 0;
};

USTRUCT(BlueprintType)
struct JMTHROWABLE_API FJMThrowableUseContext
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TObjectPtr<AActor> User = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TObjectPtr<UJMThrowableDefinition> Definition = nullptr;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TObjectPtr<USceneComponent> ExplicitThrowOrigin = nullptr;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) FGuid SessionId;
};

USTRUCT(BlueprintType)
struct JMTHROWABLE_API FJMThrowResult
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadOnly) bool bSucceeded = false;
    UPROPERTY(BlueprintReadOnly) EJMThrowResultCode ResultCode = EJMThrowResultCode::InvalidState;
    UPROPERTY(BlueprintReadOnly) FText FailureReason;
    UPROPERTY(BlueprintReadOnly) TObjectPtr<AJMThrowableProjectile> Projectile = nullptr;
    UPROPERTY(BlueprintReadOnly) FGuid SessionId;
    UPROPERTY(BlueprintReadOnly) int32 ConsumedQuantity = 0;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMThrowableStateChanged, EJMThrowableUseState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMThrowableThrowCompleted, const FJMThrowResult&, Result);
