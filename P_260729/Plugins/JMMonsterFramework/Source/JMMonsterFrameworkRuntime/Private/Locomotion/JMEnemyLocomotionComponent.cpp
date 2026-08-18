#include "Locomotion/JMEnemyLocomotionComponent.h"

#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Locomotion/JMEnemyMovementSet.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"

UJMEnemyLocomotionComponent::UJMEnemyLocomotionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMEnemyLocomotionComponent::BeginPlay()
{
    Super::BeginPlay();
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
            FVector::DistSquared2D(Projected.Location, Owner->GetActorLocation()) / FMath::Max(EscapeDistance, 1.0f);
        if (!bFound || Score > BestScore)
        {
            BestScore = Score;
            OutLocation = Projected.Location;
            bFound = true;
        }
    }
    return bFound;
}

void UJMEnemyLocomotionComponent::StopMovement()
{
    AAIController* Controller = BoundController.Get();
    if (!Controller)
    {
        Controller = ResolveController();
    }

    if (MoveStatus == EJMEnemyMoveStatus::Moving)
    {
        FinishActiveMove(EJMEnemyMoveStatus::Aborted);
    }
    if (Controller)
    {
        Controller->StopMovement();
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

    FRotator Facing = UKismetMathLibrary::FindLookAtRotation(Pawn->GetActorLocation(), TargetActor->GetActorLocation());
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

EJMEnemyMoveRequestResult UJMEnemyLocomotionComponent::SubmitMoveRequest(
    AActor* TargetActor, const FVector& Destination, const FJMEnemyMoveOptions& Options)
{
    AAIController* Controller = ResolveController();
    APawn* Pawn = Cast<APawn>(GetOwner());
    if (!Controller || !Pawn || Controller->GetPawn() != Pawn || !Pawn->GetMovementComponent())
    {
        CurrentMoveTarget = TargetActor;
        CurrentDestination = Destination;
        FinishActiveMove(EJMEnemyMoveStatus::Failed);
        return EJMEnemyMoveRequestResult::RequestFailed;
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
        Request.SetProjectGoalLocation(true);
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
        OnMoveStarted.Broadcast(ActiveRequestID, TargetActor, Destination);
        return EJMEnemyMoveRequestResult::RequestStarted;
    }

    ActiveRequestID = Result.MoveId;
    const bool bAlreadyAtGoal = Result.Code == EPathFollowingRequestResult::AlreadyAtGoal;
    FinishActiveMove(bAlreadyAtGoal ? EJMEnemyMoveStatus::Succeeded : EJMEnemyMoveStatus::Failed);
    return bAlreadyAtGoal ? EJMEnemyMoveRequestResult::AlreadyAtGoal : EJMEnemyMoveRequestResult::RequestFailed;
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
        Previous->ReceiveMoveCompleted.RemoveDynamic(this, &ThisClass::HandleMoveCompleted);
        if (MoveStatus == EJMEnemyMoveStatus::Moving)
        {
            FinishActiveMove(EJMEnemyMoveStatus::Aborted);
            Previous->StopMovement();
        }
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
    OnMoveFinished.Broadcast(FinishedID, Result, FinishedTarget, FinishedDestination);
    OnMoveFinishedNative.Broadcast(FinishedID, Result, FinishedTarget, FinishedDestination);
    CurrentMoveTarget.Reset();
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
