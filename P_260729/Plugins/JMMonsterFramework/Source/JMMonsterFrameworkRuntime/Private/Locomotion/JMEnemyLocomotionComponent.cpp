#include "Locomotion/JMEnemyLocomotionComponent.h"

#include "AIController.h"
#include "JMMonsterFrameworkRuntime.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "ProfilingDebugging/CpuProfilerTrace.h"

namespace JMEnemyLocomotion
{
    static constexpr float DuplicateDestinationTolerance = 10.0f;
    static constexpr float AcceptanceRadiusTolerance = 1.0f;
}

UJMEnemyLocomotionComponent::UJMEnemyLocomotionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMEnemyLocomotionComponent::BeginPlay()
{
    Super::BeginPlay();

    if (const AActor* Owner = GetOwner())
    {
        HomeLocation = Owner->GetActorLocation();
        bHasHomeLocation = true;
    }

    ResolveController();
}

void UJMEnemyLocomotionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (AAIController* Controller = BoundController.Get())
    {
        Controller->ReceiveMoveCompleted.RemoveDynamic(this, &ThisClass::HandleMoveCompleted);
    }

    BoundController.Reset();
    ActiveRequestID = FAIRequestID::InvalidRequest;
    CurrentMoveTarget.Reset();
    bHasActiveMoveOptions = false;
    ActiveResolvedAcceptanceRadius = -1.0f;

    Super::EndPlay(EndPlayReason);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotionComponent::MoveToActor(
    AActor* TargetActor, const FJMEnemyMoveOptions Options)
{
    if (!IsValid(TargetActor))
    {
        LastMoveResult = EJMEnemyMoveStatus::Failed;

        if (MoveStatus != EJMEnemyMoveStatus::Moving)
        {
            MoveStatus = EJMEnemyMoveStatus::Failed;
        }

        OnMoveFinished.Broadcast(FAIRequestID::InvalidRequest, EJMEnemyMoveStatus::Failed,
            nullptr, FVector::ZeroVector);
        OnMoveFinishedNative.Broadcast(FAIRequestID::InvalidRequest, EJMEnemyMoveStatus::Failed,
            nullptr, FVector::ZeroVector);
        return EJMEnemyMoveRequestResult::RequestFailed;
    }

    return SubmitMoveRequest(TargetActor, TargetActor->GetActorLocation(), Options);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotionComponent::MoveToLocation(
    const FVector Destination, const FJMEnemyMoveOptions Options)
{
    return SubmitMoveRequest(nullptr, Destination, Options);
}

EJMEnemyMoveRequestResult UJMEnemyLocomotionComponent::MoveAwayFromActor(
    AActor* ThreatActor, const float EscapeDistance, const FJMEnemyMoveOptions Options)
{
    FVector EscapeLocation;
    if (!FindEscapeLocation(ThreatActor, EscapeDistance, EscapeLocation))
    {
        LastMoveResult = EJMEnemyMoveStatus::Failed;

        if (MoveStatus != EJMEnemyMoveStatus::Moving)
        {
            MoveStatus = EJMEnemyMoveStatus::Failed;
        }

        OnMoveFinished.Broadcast(FAIRequestID::InvalidRequest, EJMEnemyMoveStatus::Failed,
            nullptr, FVector::ZeroVector);
        OnMoveFinishedNative.Broadcast(FAIRequestID::InvalidRequest, EJMEnemyMoveStatus::Failed,
            nullptr, FVector::ZeroVector);
        return EJMEnemyMoveRequestResult::RequestFailed;
    }

    return MoveToLocation(EscapeLocation, Options);
}

bool UJMEnemyLocomotionComponent::FindEscapeLocation(
    AActor* ThreatActor, const float EscapeDistance, FVector& OutLocation) const
{
    TRACE_CPUPROFILER_EVENT_SCOPE(JMEnemy_FindEscapeLocation);

    const AActor* Owner = GetOwner();
    UWorld* World = GetWorld();
    if (!Owner || !IsValid(ThreatActor) || !World || EscapeDistance <= 0.0f)
    {
        return false;
    }

    UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
    if (!Navigation)
    {
        return false;
    }

    FVector Away = Owner->GetActorLocation() - ThreatActor->GetActorLocation();
    Away.Z = 0.0f;
    if (!Away.Normalize())
    {
        Away = -Owner->GetActorForwardVector().GetSafeNormal2D();
    }

    static constexpr float CandidateAngles[] = {0.0f, 30.0f, -30.0f, 60.0f, -60.0f, 90.0f, -90.0f};
    const FVector ProjectionExtent(250.0, 250.0, 500.0);
    float BestScore = -TNumericLimits<float>::Max();
    bool bFound = false;

    for (const float Angle : CandidateAngles)
    {
        const FVector Direction = Away.RotateAngleAxis(Angle, FVector::UpVector);
        const FVector Candidate = Owner->GetActorLocation() + Direction * EscapeDistance;
        FNavLocation Projected;

        if (!Navigation->ProjectPointToNavigation(Candidate, Projected, ProjectionExtent))
        {
            continue;
        }

        UNavigationPath* Path = UNavigationSystemV1::FindPathToLocationSynchronously(
            World, Owner->GetActorLocation(), Projected.Location, const_cast<AActor*>(Owner));
        if (!Path || !Path->IsValid() || Path->IsPartial())
        {
            continue;
        }

        const FVector ActualDirection = (Projected.Location - Owner->GetActorLocation()).GetSafeNormal2D();
        const float Score = FVector::DotProduct(ActualDirection, Away) * 10000.0f +
            FVector::DistSquared2D(Projected.Location, Owner->GetActorLocation()) /
            FMath::Max(EscapeDistance, 1.0f);

        if (!bFound || Score > BestScore)
        {
            BestScore = Score;
            OutLocation = Projected.Location;
            bFound = true;
        }
    }

    return bFound;
}

bool UJMEnemyLocomotionComponent::FindRandomReachableLocation(
    const FVector Center, const float Radius, FVector& OutLocation) const
{
    TRACE_CPUPROFILER_EVENT_SCOPE(JMEnemy_FindRandomReachableLocation);

    const UWorld* World = GetWorld();
    UNavigationSystemV1* Navigation = World
        ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(const_cast<UWorld*>(World)) : nullptr;

    FNavLocation ProjectedCenter;
    const FVector ProjectionExtent(250.0f, 250.0f, 500.0f);
    if (!Navigation || Radius <= 0.0f ||
        !Navigation->ProjectPointToNavigation(Center, ProjectedCenter, ProjectionExtent))
    {
        return false;
    }

    const AActor* Owner = GetOwner();
    const INavAgentInterface* NavAgent = Cast<INavAgentInterface>(Owner);
    const FVector PathStart = NavAgent ? NavAgent->GetNavAgentLocation() :
        (Owner ? Owner->GetActorLocation() : ProjectedCenter.Location);

    FNavLocation ProjectedPathStart;
    const FVector QueryPathStart = Navigation->ProjectPointToNavigation(
        PathStart, ProjectedPathStart, ProjectionExtent) ? ProjectedPathStart.Location : PathStart;

    static constexpr int32 MaxCandidateAttempts = 8;
    FVector LastRandomLocation = ProjectedCenter.Location;
    bool bHasRandomLocation = false;

    for (int32 Attempt = 0; Attempt < MaxCandidateAttempts; ++Attempt)
    {
        FNavLocation RandomLocation;
        if (!Navigation->GetRandomReachablePointInRadius(ProjectedCenter.Location, Radius, RandomLocation))
        {
            continue;
        }

        LastRandomLocation = RandomLocation.Location;
        bHasRandomLocation = true;

        UNavigationPath* Path = Owner ? UNavigationSystemV1::FindPathToLocationSynchronously(
            const_cast<UWorld*>(World), QueryPathStart, RandomLocation.Location,
            const_cast<AActor*>(Owner)) : nullptr;

        if (Path && Path->IsValid() && !Path->IsPartial())
        {
            OutLocation = RandomLocation.Location;
            return true;
        }
    }

    if (Owner && FVector::Dist2D(PathStart, ProjectedCenter.Location) <= 250.0f)
    {
        OutLocation = bHasRandomLocation ? LastRandomLocation : ProjectedCenter.Location;
        return true;
    }

    return false;
}

FVector UJMEnemyLocomotionComponent::GetHomeLocation() const
{
    const AActor* Owner = GetOwner();
    return bHasHomeLocation ? HomeLocation : (Owner ? Owner->GetActorLocation() : FVector::ZeroVector);
}

bool UJMEnemyLocomotionComponent::IsControllerReady() const
{
    const APawn* Pawn = Cast<APawn>(GetOwner());
    const AAIController* Controller = Pawn ? Cast<AAIController>(Pawn->GetController()) : nullptr;
    return Controller && Controller->GetPawn() == Pawn && Pawn->GetMovementComponent();
}

bool UJMEnemyLocomotionComponent::IsNavigationReady() const
{
    const UWorld* World = GetWorld();
    return World && FNavigationSystem::GetCurrent<UNavigationSystemV1>(const_cast<UWorld*>(World));
}

bool UJMEnemyLocomotionComponent::IsMovingToActor(AActor* TargetActor) const
{
    return MoveStatus == EJMEnemyMoveStatus::Moving &&
        ActiveRequestID.IsValid() &&
        IsValid(TargetActor) &&
        CurrentMoveTarget.Get() == TargetActor;
}

bool UJMEnemyLocomotionComponent::IsMovingToLocation(
    const FVector Destination, const float Tolerance) const
{
    if (MoveStatus != EJMEnemyMoveStatus::Moving ||
        !ActiveRequestID.IsValid() ||
        CurrentMoveTarget.IsValid())
    {
        return false;
    }

    const float SafeTolerance = FMath::Max(Tolerance, 0.0f);
    return FVector::DistSquared(CurrentDestination, Destination) <= FMath::Square(SafeTolerance);
}

void UJMEnemyLocomotionComponent::StopMovement()
{
    AAIController* Controller = BoundController.Get();
    if (!Controller)
    {
        Controller = ResolveController();
    }

    if (MoveStatus != EJMEnemyMoveStatus::Moving)
    {
        if (Controller)
        {
            Controller->StopMovement();
        }
        return;
    }

    // Abort the backend first. ReceiveMoveCompleted can synchronously normalize the request.
    // If the backend does not produce a completion callback, finish the framework request ourselves.
    const FAIRequestID RequestToAbort = ActiveRequestID;

    if (Controller)
    {
        Controller->StopMovement();
    }

    if (MoveStatus == EJMEnemyMoveStatus::Moving &&
        (!RequestToAbort.IsValid() || ActiveRequestID.IsEquivalent(RequestToAbort)))
    {
        FinishActiveMove(EJMEnemyMoveStatus::Aborted);
    }
}

bool UJMEnemyLocomotionComponent::FaceActor(AActor* TargetActor, const EJMEnemyFacingMode Mode)
{
    AAIController* Controller = ResolveController();
    APawn* Pawn = Cast<APawn>(GetOwner());
    if (!Controller || !Pawn || !IsValid(TargetActor))
    {
        return false;
    }

    if (Mode == EJMEnemyFacingMode::ControllerFocus)
    {
        Controller->SetFocus(TargetActor);
        return true;
    }

    FRotator Facing = UKismetMathLibrary::FindLookAtRotation(
        Pawn->GetActorLocation(), TargetActor->GetActorLocation());
    Facing.Pitch = 0.0f;
    Facing.Roll = 0.0f;
    Controller->SetControlRotation(Facing);
    Pawn->FaceRotation(Facing, 0.0f);
    return true;
}

void UJMEnemyLocomotionComponent::ClearFacingFocus()
{
    if (AAIController* Controller = ResolveController())
    {
        Controller->ClearFocus(EAIFocusPriority::Gameplay);
    }
}

bool UJMEnemyLocomotionComponent::ApplyMovementProfile(
    const UJMEnemyMovementSet* MovementSet, const FName ProfileName)
{
    const FJMEnemyMovementProfile* Profile = MovementSet ? MovementSet->FindProfile(ProfileName) : nullptr;
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    UCharacterMovementComponent* Movement = Character ? Character->GetCharacterMovement() : nullptr;

    if (!Profile || !Profile->IsValid() || !Movement)
    {
        return false;
    }

    Movement->MaxWalkSpeed = Profile->MaxSpeed;
    Movement->MaxAcceleration = Profile->MaxAcceleration;
    Movement->RotationRate = Profile->RotationRate;
    ProfileAcceptanceRadius = Profile->AcceptanceRadius;
    CurrentMovementProfile = Profile->ProfileName;
    return true;
}

bool UJMEnemyLocomotionComponent::IsEquivalentActiveMove(
    AActor* TargetActor, const FVector& Destination, const FJMEnemyMoveOptions& Options) const
{
    if (MoveStatus != EJMEnemyMoveStatus::Moving ||
        !ActiveRequestID.IsValid() ||
        !bHasActiveMoveOptions)
    {
        return false;
    }

    const float RequestedAcceptanceRadius = ResolveAcceptanceRadius(Options);
    if (!FMath::IsNearlyEqual(ActiveResolvedAcceptanceRadius, RequestedAcceptanceRadius,
        JMEnemyLocomotion::AcceptanceRadiusTolerance))
    {
        return false;
    }

    if (ActiveMoveOptions.bStopOnOverlap != Options.bStopOnOverlap ||
        ActiveMoveOptions.bUsePathfinding != Options.bUsePathfinding ||
        ActiveMoveOptions.bAllowPartialPath != Options.bAllowPartialPath)
    {
        return false;
    }

    if (TargetActor)
    {
        // GoalActor movement already observes the actor's changing location inside UE PathFollowing.
        // Reissuing MoveToActor for the same actor only aborts/repaths work that already exists.
        return CurrentMoveTarget.Get() == TargetActor;
    }

    if (CurrentMoveTarget.IsValid() ||
        ActiveMoveOptions.bProjectGoalLocation != Options.bProjectGoalLocation)
    {
        return false;
    }

    return FVector::DistSquared(CurrentDestination, Destination) <=
        FMath::Square(JMEnemyLocomotion::DuplicateDestinationTolerance);
}

void UJMEnemyLocomotionComponent::RememberActiveMoveOptions(const FJMEnemyMoveOptions& Options)
{
    ActiveMoveOptions = Options;
    ActiveResolvedAcceptanceRadius = ResolveAcceptanceRadius(Options);
    bHasActiveMoveOptions = true;
}

EJMEnemyMoveRequestResult UJMEnemyLocomotionComponent::SubmitMoveRequest(
    AActor* TargetActor, const FVector& Destination, const FJMEnemyMoveOptions& Options)
{
    TRACE_CPUPROFILER_EVENT_SCOPE(JMEnemy_SubmitMoveRequest);

    AAIController* Controller = ResolveController();
    APawn* Pawn = Cast<APawn>(GetOwner());

    if (!Controller || !Pawn || Controller->GetPawn() != Pawn || !Pawn->GetMovementComponent())
    {
        // Preserve the old request's completion semantics before reporting the new failed intent.
        if (MoveStatus == EJMEnemyMoveStatus::Moving)
        {
            FinishActiveMove(EJMEnemyMoveStatus::Aborted);
        }

        CurrentMoveTarget = TargetActor;
        CurrentDestination = Destination;
        ActiveRequestID = FAIRequestID::InvalidRequest;
        FinishActiveMove(EJMEnemyMoveStatus::Failed);
        return EJMEnemyMoveRequestResult::RequestFailed;
    }

    // Most important contract change:
    // expressing the same movement intent again is idempotent.
    if (IsEquivalentActiveMove(TargetActor, Destination, Options))
    {
        return EJMEnemyMoveRequestResult::RequestStarted;
    }

    if (MoveStatus == EJMEnemyMoveStatus::Moving)
    {
        StopMovement();
    }

    CurrentMoveTarget = TargetActor;
    CurrentDestination = Destination;

    FAIMoveRequest Request;
    if (TargetActor)
    {
        Request.SetGoalActor(TargetActor);
    }
    else
    {
        Request.SetGoalLocation(Destination);
        Request.SetProjectGoalLocation(Options.bProjectGoalLocation);
        Request.SetRequireNavigableEndLocation(true);
    }

    Request.SetAcceptanceRadius(ResolveAcceptanceRadius(Options));
    Request.SetReachTestIncludesAgentRadius(Options.bStopOnOverlap);
    Request.SetReachTestIncludesGoalRadius(Options.bStopOnOverlap && TargetActor != nullptr);
    Request.SetUsePathfinding(Options.bUsePathfinding);
    Request.SetAllowPartialPath(Options.bAllowPartialPath);

    const FPathFollowingRequestResult Result = Controller->MoveTo(Request);
    if (Result.Code == EPathFollowingRequestResult::RequestSuccessful)
    {
        ActiveRequestID = Result.MoveId;
        MoveStatus = EJMEnemyMoveStatus::Moving;
        RememberActiveMoveOptions(Options);
        OnMoveStarted.Broadcast(ActiveRequestID, TargetActor, Destination);
        return EJMEnemyMoveRequestResult::RequestStarted;
    }

    // A placed pawn can be slightly outside the first nav polygon even though a nearby Home
    // projection is valid. Recover only to that nearby polygon; never direct-move to the random goal.
    if (Result.Code == EPathFollowingRequestResult::Failed && !TargetActor && Options.bUsePathfinding)
    {
        UNavigationSystemV1* Navigation = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
        FNavLocation RecoveryLocation;
        const FVector RecoveryExtent(250.0f, 250.0f, 500.0f);
        const FVector NavAgentLocation = Pawn->GetNavAgentLocation();

        if (Navigation && Navigation->ProjectPointToNavigation(
                Pawn->GetActorLocation(), RecoveryLocation, RecoveryExtent) &&
            FVector::Dist2D(NavAgentLocation, RecoveryLocation.Location) <= 250.0f)
        {
            FVector RecoveryGoal = RecoveryLocation.Location;
            const FVector RecoveryDirection = (Destination - RecoveryGoal).GetSafeNormal2D();
            FNavLocation DeeperRecoveryLocation;

            if (!RecoveryDirection.IsNearlyZero() && Navigation->ProjectPointToNavigation(
                    RecoveryGoal + RecoveryDirection * 100.0f, DeeperRecoveryLocation,
                    FVector(75.0f, 75.0f, 100.0f)))
            {
                RecoveryGoal = DeeperRecoveryLocation.Location;
            }

            FAIMoveRequest RecoveryRequest;
            RecoveryRequest.SetGoalLocation(RecoveryGoal);
            RecoveryRequest.SetUsePathfinding(false);
            RecoveryRequest.SetProjectGoalLocation(false);
            RecoveryRequest.SetRequireNavigableEndLocation(false);
            RecoveryRequest.SetAcceptanceRadius(5.0f);
            RecoveryRequest.SetReachTestIncludesAgentRadius(false);

            const FPathFollowingRequestResult RecoveryResult = Controller->MoveTo(RecoveryRequest);
            if (RecoveryResult.Code == EPathFollowingRequestResult::RequestSuccessful)
            {
                CurrentMoveTarget.Reset();
                CurrentDestination = RecoveryGoal;
                ActiveRequestID = RecoveryResult.MoveId;
                MoveStatus = EJMEnemyMoveStatus::Moving;
                RememberActiveMoveOptions(Options);

                UE_LOG(LogJMMonsterFramework, Verbose,
                    TEXT("Locomotion starting nearby Nav recovery: Enemy=%s From=%s To=%s"),
                    *Pawn->GetName(), *NavAgentLocation.ToCompactString(),
                    *RecoveryLocation.Location.ToCompactString());

                OnMoveStarted.Broadcast(ActiveRequestID, nullptr, CurrentDestination);
                return EJMEnemyMoveRequestResult::RequestStarted;
            }
        }
    }

    ActiveRequestID = Result.MoveId;
    const bool bAlreadyAtGoal = Result.Code == EPathFollowingRequestResult::AlreadyAtGoal;
    FinishActiveMove(bAlreadyAtGoal ? EJMEnemyMoveStatus::Succeeded : EJMEnemyMoveStatus::Failed);
    return bAlreadyAtGoal
        ? EJMEnemyMoveRequestResult::AlreadyAtGoal
        : EJMEnemyMoveRequestResult::RequestFailed;
}

AAIController* UJMEnemyLocomotionComponent::ResolveController()
{
    APawn* Pawn = Cast<APawn>(GetOwner());
    AAIController* Controller = Pawn ? Cast<AAIController>(Pawn->GetController()) : nullptr;

    if (Controller != BoundController.Get())
    {
        BindController(Controller);
    }

    return Controller;
}

void UJMEnemyLocomotionComponent::BindController(AAIController* Controller)
{
    if (AAIController* Previous = BoundController.Get())
    {
        // Keep the completion delegate alive while the old backend is being stopped so a real
        // aborted result can close the request. Fall back to framework completion if it does not.
        if (MoveStatus == EJMEnemyMoveStatus::Moving)
        {
            const FAIRequestID RequestToAbort = ActiveRequestID;
            Previous->StopMovement();

            if (MoveStatus == EJMEnemyMoveStatus::Moving &&
                (!RequestToAbort.IsValid() || ActiveRequestID.IsEquivalent(RequestToAbort)))
            {
                FinishActiveMove(EJMEnemyMoveStatus::Aborted);
            }
        }

        Previous->ReceiveMoveCompleted.RemoveDynamic(this, &ThisClass::HandleMoveCompleted);
    }

    BoundController = Controller;

    if (Controller)
    {
        Controller->ReceiveMoveCompleted.AddUniqueDynamic(this, &ThisClass::HandleMoveCompleted);
    }
}

void UJMEnemyLocomotionComponent::FinishActiveMove(const EJMEnemyMoveStatus Result)
{
    const FAIRequestID FinishedID = ActiveRequestID;
    AActor* FinishedTarget = CurrentMoveTarget.Get();
    const FVector FinishedDestination = CurrentDestination;

    ActiveRequestID = FAIRequestID::InvalidRequest;
    MoveStatus = Result;
    LastMoveResult = Result;

    bHasActiveMoveOptions = false;
    ActiveResolvedAcceptanceRadius = -1.0f;

    OnMoveFinished.Broadcast(FinishedID, Result, FinishedTarget, FinishedDestination);
    OnMoveFinishedNative.Broadcast(FinishedID, Result, FinishedTarget, FinishedDestination);

    CurrentMoveTarget.Reset();
}

FAIRequestID UJMEnemyLocomotionComponent::BeginBackendMove(
    AActor* TargetActor, const FVector& Destination)
{
    if (MoveStatus == EJMEnemyMoveStatus::Moving)
    {
        StopMovement();
    }

    static uint32 NextBackendRequest = 0x80000000u;
    ++NextBackendRequest;
    if (NextBackendRequest == MAX_uint32)
    {
        NextBackendRequest = 0x80000001u;
    }

    ActiveRequestID = FAIRequestID(NextBackendRequest);
    CurrentMoveTarget = TargetActor;
    CurrentDestination = Destination;
    MoveStatus = EJMEnemyMoveStatus::Moving;

    // Custom backends do not currently pass options through this helper.
    // They still get the same request lifetime semantics; option-based dedupe remains ground-backend specific.
    bHasActiveMoveOptions = false;
    ActiveResolvedAcceptanceRadius = -1.0f;

    OnMoveStarted.Broadcast(ActiveRequestID, TargetActor, Destination);
    return ActiveRequestID;
}

float UJMEnemyLocomotionComponent::ResolveAcceptanceRadius(const FJMEnemyMoveOptions& Options) const
{
    return Options.AcceptanceRadius >= 0.0f ? Options.AcceptanceRadius : ProfileAcceptanceRadius;
}

void UJMEnemyLocomotionComponent::HandleMoveCompleted(
    const FAIRequestID RequestID, const EPathFollowingResult::Type Result)
{
    if (MoveStatus != EJMEnemyMoveStatus::Moving || !ActiveRequestID.IsEquivalent(RequestID))
    {
        return;
    }

    EJMEnemyMoveStatus Normalized = EJMEnemyMoveStatus::Failed;
    if (Result == EPathFollowingResult::Success)
    {
        Normalized = EJMEnemyMoveStatus::Succeeded;
    }
    else if (Result == EPathFollowingResult::Aborted)
    {
        Normalized = EJMEnemyMoveStatus::Aborted;
    }

    FinishActiveMove(Normalized);
}
