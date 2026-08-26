#include "AI/SimpleEnemyAIController.h"

#include "JMMonsterFrameworkRuntime.h"
#include "AITypes.h"
#include "Components/StateTreeAIComponent.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Pawn.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"
#include "StateTree.h"

ASimpleEnemyAIController::ASimpleEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = true;

    StateTreeComponent = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeComponent"));
    StateTreeComponent->SetStartLogicAutomatically(false);
    StateTreeAsset = TSoftObjectPtr<UStateTree>(FSoftObjectPath(
        TEXT("/JMMonsterFramework/AI/ST_SimpleEnemy.ST_SimpleEnemy")));

    UAIPerceptionComponent* SightPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("SightPerception"));
    SetPerceptionComponent(*SightPerception);

    UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    SightConfig->SightRadius = 1500.0f;
    SightConfig->LoseSightRadius = 1800.0f;
    SightConfig->PeripheralVisionAngleDegrees = 60.0f;
    SightConfig->SetMaxAge(0.0f);
    SightConfig->AutoSuccessRangeFromLastSeenLocation = -1.0f;
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    SightPerception->ConfigureSense(*SightConfig);

    HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
    HearingConfig->HearingRange = 1500.0f;
    HearingConfig->SetMaxAge(3.0f);
    HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
    HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
    HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
    SightPerception->ConfigureSense(*HearingConfig);

    SightPerception->SetDominantSense(SightConfig->GetSenseImplementation());
    SightPerception->OnTargetPerceptionUpdated.AddDynamic(
        this,
        &ASimpleEnemyAIController::HandleTargetPerceptionUpdated);
}

void ASimpleEnemyAIController::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Sampling the actor is deliberately restricted to the confirmed-visible state.
    // After sight loss, RecentTracking uses only the snapshot created in ApplySightState.
    if (bCanSeeTarget && IsValid(TargetActor))
    {
        UpdateVisibleObservation(*TargetActor, TargetActor->GetActorLocation());
    }
}

void ASimpleEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    // Existing Blueprint controller assets may carry a serialized Sight-only SensesConfig
    // from before Phase 7. Reassert the native Hearing config on the runtime listener.
    if (UAIPerceptionComponent* Perception = GetPerceptionComponent();
        IsValid(Perception) && IsValid(HearingConfig))
    {
        Perception->ConfigureSense(*HearingConfig);
        Perception->SetSenseEnabled(UAISense_Hearing::StaticClass(), true);
        Perception->RequestStimuliListenerUpdate();
        UE_LOG(
            LogJMMonsterFramework,
            Log,
            TEXT("[JM HEARING CONFIG] Enemy=%s Enabled=%d Range=%.1f MaxAge=%.1f DetectEnemies=%d DetectFriendlies=%d DetectNeutrals=%d"),
            *GetNameSafe(InPawn),
            Perception->IsSenseEnabled(UAISense_Hearing::StaticClass()),
            HearingConfig->HearingRange,
            HearingConfig->GetMaxAge(),
            HearingConfig->DetectionByAffiliation.bDetectEnemies,
            HearingConfig->DetectionByAffiliation.bDetectFriendlies,
            HearingConfig->DetectionByAffiliation.bDetectNeutrals);
    }

    if (!IsValid(StateTreeComponent))
    {
        return;
    }

    UStateTree* LoadedStateTree = StateTreeAsset.LoadSynchronous();
    if (!IsValid(LoadedStateTree))
    {
        UE_LOG(LogJMMonsterFramework, Error, TEXT("SimpleEnemy StateTree asset could not be loaded."));
        return;
    }

    StateTreeComponent->SetStateTree(LoadedStateTree);
    StateTreeComponent->StartLogic();
}

void ASimpleEnemyAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    const TCHAR* SenseName = TEXT("Unknown");
    if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
    {
        SenseName = TEXT("Sight");
    }
    else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
    {
        SenseName = TEXT("Hearing");
    }
    else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Damage>())
    {
        SenseName = TEXT("Damage");
    }

    UE_LOG(
        LogJMMonsterFramework,
        Log,
        TEXT("[RAW PERCEPTION] Enemy=%s Actor=%s Sense=%s Success=%d Strength=%.2f Location=%s"),
        *GetNameSafe(GetPawn()),
        *GetNameSafe(Actor),
        SenseName,
        Stimulus.WasSuccessfullySensed(),
        Stimulus.Strength,
        *Stimulus.StimulusLocation.ToCompactString());

    if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
    {
        ApplyHearingState(
            Actor,
            Stimulus.WasSuccessfullySensed(),
            Stimulus.StimulusLocation,
            Stimulus.Strength);
        return;
    }

    if (Stimulus.Type != UAISense::GetSenseID<UAISense_Sight>())
    {
        return;
    }

    const APawn* SensedPawn = Cast<APawn>(Actor);
    if (!IsValid(SensedPawn) || !SensedPawn->IsPlayerControlled())
    {
        return;
    }

    const bool bIsVisible = Stimulus.WasSuccessfullySensed();
    const FVector ObservedVelocity = bIsVisible ? Actor->GetVelocity() : FVector::ZeroVector;
    ApplySightState(Actor, bIsVisible, Stimulus.StimulusLocation, ObservedVelocity);
}

void ASimpleEnemyAIController::ApplySightState(
    AActor* Actor,
    const bool bIsVisible,
    const FVector& ObservedLocation,
    const FVector& ObservedVelocity)
{
    if (bIsVisible)
    {
        if (!IsValid(Actor))
        {
            return;
        }

        const bool bStateChanged = TargetActor != Actor || !bCanSeeTarget;
        TargetActor = Actor;
        bCanSeeTarget = true;
        bHasRecentTrackingMemory = false;
        EndLiveGraceTracking();
        ClearHeardSound();
        if (FAISystem::IsValidLocation(ObservedLocation))
        {
            LastSeenLocation = ObservedLocation;
        }
        LastSeenVelocity = ObservedVelocity;
        LastSeenTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;

        if (bStateChanged)
        {
            UE_LOG(LogJMMonsterFramework, Log, TEXT("Detected: %s"), *GetNameSafe(Actor));
        }
        return;
    }

    if (TargetActor != Actor)
    {
        return;
    }

    const bool bWasVisible = bCanSeeTarget;
    if (FAISystem::IsValidLocation(ObservedLocation))
    {
        // Sight reports its stored successful stimulus location on loss. Do not
        // sample Actor here: it may already be moving unseen behind an obstacle.
        LastSeenLocation = ObservedLocation;
    }

    const FVector PredictionOffset = (LastSeenVelocity * TrackingMemoryDuration)
        .GetClampedToMaxSize(MaximumPredictionDistance);
    EstimatedTrackingLocation = LastSeenLocation + PredictionOffset;
    bHasRecentTrackingMemory = TrackingMemoryDuration > 0.0f;
    LiveGraceTargetActor = Actor;
    bHasLiveGraceTracking = LiveGraceDuration > 0.0f && IsValid(Actor);
    TargetActor = nullptr;
    bCanSeeTarget = false;

    if (bWasVisible)
    {
        UE_LOG(LogJMMonsterFramework, Log, TEXT("Lost: %s"), *GetNameSafe(Actor));
    }
}

void ASimpleEnemyAIController::ApplyHearingState(
    AActor* Actor,
    const bool bWasSuccessfullySensed,
    const FVector& HeardLocation,
    const float Strength)
{
    const UAIPerceptionComponent* Perception = GetPerceptionComponent();
    const bool bHearingEnabled = IsValid(Perception)
        && Perception->IsSenseEnabled(UAISense_Hearing::StaticClass());
    const TCHAR* RejectionReason = nullptr;
    if (!bWasSuccessfullySensed)
    {
        RejectionReason = TEXT("StimulusFailed");
    }
    else if (bCanSeeTarget)
    {
        RejectionReason = TEXT("SightActive");
    }
    else if (Actor == GetPawn())
    {
        RejectionReason = TEXT("SelfNoise");
    }
    else if (!FAISystem::IsValidLocation(HeardLocation))
    {
        RejectionReason = TEXT("InvalidLocation");
    }

    if (RejectionReason)
    {
        UE_LOG(
            LogJMMonsterFramework,
            Log,
            TEXT("[JM HEARING REJECTED] Enemy=%s Actor=%s Success=%d Strength=%.2f MinimumStrength=0.00 Enabled=%d Reason=%s"),
            *GetNameSafe(GetPawn()),
            *GetNameSafe(Actor),
            bWasSuccessfullySensed,
            Strength,
            bHearingEnabled,
            RejectionReason);
        return;
    }

    LastHeardLocation = HeardLocation;
    bHasHeardSound = true;
    UE_LOG(
        LogJMMonsterFramework,
        Log,
        TEXT("[JM HEARING ACCEPTED] Enemy=%s Actor=%s Success=1 Strength=%.2f MinimumStrength=0.00 Enabled=%d Location=%s"),
        *GetNameSafe(GetPawn()),
        *GetNameSafe(Actor),
        Strength,
        bHearingEnabled,
        *HeardLocation.ToCompactString());
}

void ASimpleEnemyAIController::ClearHeardSound()
{
    bHasHeardSound = false;
}

bool ASimpleEnemyAIController::UpdateLiveGraceLastKnownLocation()
{
    AActor* GraceTarget = LiveGraceTargetActor.Get();
    if (bCanSeeTarget || !bHasLiveGraceTracking || !IsValid(GraceTarget))
    {
        return false;
    }

    LastSeenLocation = GraceTarget->GetActorLocation();
    LastSeenTime = GetWorld() ? GetWorld()->GetTimeSeconds() : LastSeenTime;
    return true;
}

void ASimpleEnemyAIController::EndLiveGraceTracking()
{
    bHasLiveGraceTracking = false;
    LiveGraceTargetActor.Reset();
}

bool ASimpleEnemyAIController::IsTargetInAttackRange() const
{
    const APawn* ControlledPawn = GetPawn();
    return bCanSeeTarget
        && IsValid(TargetActor)
        && IsValid(ControlledPawn)
        && FVector::DistSquared(ControlledPawn->GetActorLocation(), TargetActor->GetActorLocation())
            <= FMath::Square(AttackRange);
}

bool ASimpleEnemyAIController::PerformBasicAttack()
{
    if (!IsTargetInAttackRange())
    {
        return false;
    }

    const UWorld* World = GetWorld();
    const float CurrentTime = IsValid(World) ? World->GetTimeSeconds() : 0.0f;
    const float EffectiveCooldown = FMath::Max(AttackCooldown, UE_KINDA_SMALL_NUMBER);
    if (LastBasicAttackTime >= 0.0f && CurrentTime - LastBasicAttackTime < EffectiveCooldown)
    {
        return false;
    }

    FDamageEvent DamageEvent;
    TargetActor->TakeDamage(Damage, DamageEvent, this, GetPawn());
    LastBasicAttackTime = CurrentTime;
    UE_LOG(
        LogJMMonsterFramework,
        Log,
        TEXT("BasicAttack: %s damaged %s for %.1f"),
        *GetNameSafe(GetPawn()),
        *GetNameSafe(TargetActor),
        Damage);
    return true;
}

void ASimpleEnemyAIController::UpdateVisibleObservation(
    AActor& VisibleActor,
    const FVector& ObservedLocation)
{
    if (!bCanSeeTarget || TargetActor != &VisibleActor)
    {
        return;
    }

    if (FAISystem::IsValidLocation(ObservedLocation))
    {
        LastSeenLocation = ObservedLocation;
    }
    LastSeenVelocity = VisibleActor.GetVelocity();
    LastSeenTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
}
