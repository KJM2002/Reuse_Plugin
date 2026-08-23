#pragma once

#include "AITypes.h"
#include "Components/ActorComponent.h"
#include "Locomotion/JMEnemyMovementTypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "JMEnemyLocomotionComponent.generated.h"

class AAIController;
class UJMEnemyMovementSet;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(
    FJMEnemyMoveStartedSignature, FAIRequestID, RequestID, AActor*, TargetActor, FVector, Destination);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(
    FJMEnemyMoveFinishedSignature, FAIRequestID, RequestID, EJMEnemyMoveStatus, Result,
    AActor*, TargetActor, FVector, Destination);
DECLARE_MULTICAST_DELEGATE_FourParams(
    FJMEnemyMoveFinishedNativeSignature, FAIRequestID, EJMEnemyMoveStatus, AActor*, FVector);

/** Ground-navigation facade. It executes destinations selected by an external behavior layer. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyLocomotionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyLocomotionComponent();

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual EJMEnemyMoveRequestResult MoveToActor(AActor* TargetActor, FJMEnemyMoveOptions Options);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual EJMEnemyMoveRequestResult MoveToLocation(FVector Destination, FJMEnemyMoveOptions Options);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual EJMEnemyMoveRequestResult MoveAwayFromActor(
        AActor* ThreatActor, float EscapeDistance, FJMEnemyMoveOptions Options);

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    virtual bool FindEscapeLocation(AActor* ThreatActor, float EscapeDistance, FVector& OutLocation) const;

    /** Backend-specific reachable-point query used by generic roam/search behavior. */
    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    virtual bool FindRandomReachableLocation(FVector Center, float Radius, FVector& OutLocation) const;

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual void StopMovement();

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual bool FaceActor(AActor* TargetActor, EJMEnemyFacingMode Mode = EJMEnemyFacingMode::ControllerFocus);

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual void ClearFacingFocus();

    UFUNCTION(BlueprintCallable, Category="JM Enemy|Locomotion")
    virtual bool ApplyMovementProfile(const UJMEnemyMovementSet* MovementSet, FName ProfileName);

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    FName GetCurrentMovementProfile() const { return CurrentMovementProfile; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    EJMEnemyMoveStatus GetMoveStatus() const { return MoveStatus; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    EJMEnemyMoveStatus GetLastMoveResult() const { return LastMoveResult; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    FVector GetCurrentDestination() const { return CurrentDestination; }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    AActor* GetCurrentMoveTarget() const { return CurrentMoveTarget.Get(); }

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    FAIRequestID GetCurrentRequestID() const { return ActiveRequestID; }

    /** True when an existing active request already represents this actor-follow intent. */
    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    bool IsMovingToActor(AActor* TargetActor) const;

    /** True when an existing location request is already close enough to the supplied destination. */
    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    bool IsMovingToLocation(FVector Destination, float Tolerance = 10.0f) const;

    /** Stable spawn anchor used by autonomous movement so repeated patrol legs cannot drift forever. */
    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    FVector GetHomeLocation() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    bool IsControllerReady() const;

    UFUNCTION(BlueprintPure, Category="JM Enemy|Locomotion")
    bool IsNavigationReady() const;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Locomotion")
    FJMEnemyMoveStartedSignature OnMoveStarted;

    UPROPERTY(BlueprintAssignable, Category="JM Enemy|Locomotion")
    FJMEnemyMoveFinishedSignature OnMoveFinished;

    /** Native completion bridge used by event-driven C++ StateTree tasks. */
    FJMEnemyMoveFinishedNativeSignature OnMoveFinishedNative;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    /** Ground backend seam. A future surface component can override execution while keeping the public intent API. */
    virtual EJMEnemyMoveRequestResult SubmitMoveRequest(AActor* TargetActor, const FVector& Destination,
        const FJMEnemyMoveOptions& Options);

    AAIController* ResolveController();
    void BindController(AAIController* Controller);
    void FinishActiveMove(EJMEnemyMoveStatus Result);
    float ResolveAcceptanceRadius(const FJMEnemyMoveOptions& Options) const;

    /**
     * Returns true when a new call expresses the same active movement intent.
     * Ground MoveToActor is intentionally idempotent so a behavior reevaluation cannot restart pathfinding every frame.
     */
    bool IsEquivalentActiveMove(AActor* TargetActor, const FVector& Destination,
        const FJMEnemyMoveOptions& Options) const;

    void RememberActiveMoveOptions(const FJMEnemyMoveOptions& Options);

    FAIRequestID BeginBackendMove(AActor* TargetActor, const FVector& Destination);
    void UpdateBackendDestination(const FVector& Destination) { CurrentDestination = Destination; }

private:
    UFUNCTION()
    void HandleMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);

    UPROPERTY(Transient)
    TWeakObjectPtr<AAIController> BoundController;

    UPROPERTY(Transient)
    TWeakObjectPtr<AActor> CurrentMoveTarget;

    UPROPERTY(Transient)
    FAIRequestID ActiveRequestID;

    FVector CurrentDestination = FVector::ZeroVector;
    FName CurrentMovementProfile;
    float ProfileAcceptanceRadius = 75.0f;

    FJMEnemyMoveOptions ActiveMoveOptions;
    float ActiveResolvedAcceptanceRadius = -1.0f;
    bool bHasActiveMoveOptions = false;

    EJMEnemyMoveStatus MoveStatus = EJMEnemyMoveStatus::Idle;
    EJMEnemyMoveStatus LastMoveResult = EJMEnemyMoveStatus::Idle;

    FVector HomeLocation = FVector::ZeroVector;
    bool bHasHomeLocation = false;
};
