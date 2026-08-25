#include "AI/SimpleEnemyAIController.h"

#include "JMMonsterFrameworkRuntime.h"
#include "AITypes.h"
#include "Components/StateTreeAIComponent.h"
#include "GameFramework/Pawn.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "StateTree.h"

ASimpleEnemyAIController::ASimpleEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = false;

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
    SightPerception->SetDominantSense(SightConfig->GetSenseImplementation());
    SightPerception->OnTargetPerceptionUpdated.AddDynamic(
        this,
        &ASimpleEnemyAIController::HandleTargetPerceptionUpdated);
}

void ASimpleEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

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
    const APawn* SensedPawn = Cast<APawn>(Actor);
    if (!IsValid(SensedPawn) || !SensedPawn->IsPlayerControlled())
    {
        return;
    }

    ApplySightState(Actor, Stimulus.WasSuccessfullySensed(), Stimulus.StimulusLocation);
}

void ASimpleEnemyAIController::ApplySightState(
    AActor* Actor,
    const bool bIsVisible,
    const FVector& ObservedLocation)
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
        if (FAISystem::IsValidLocation(ObservedLocation))
        {
            LastSeenLocation = ObservedLocation;
        }

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
    TargetActor = nullptr;
    bCanSeeTarget = false;

    if (bWasVisible)
    {
        UE_LOG(LogJMMonsterFramework, Log, TEXT("Lost: %s"), *GetNameSafe(Actor));
    }
}
