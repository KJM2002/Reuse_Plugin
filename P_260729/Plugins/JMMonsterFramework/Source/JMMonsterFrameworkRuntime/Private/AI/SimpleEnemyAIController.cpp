#include "AI/SimpleEnemyAIController.h"

#include "JMMonsterFrameworkRuntime.h"
#include "GameFramework/Pawn.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ASimpleEnemyAIController::ASimpleEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = false;

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

void ASimpleEnemyAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    const APawn* SensedPawn = Cast<APawn>(Actor);
    if (!IsValid(SensedPawn) || !SensedPawn->IsPlayerControlled())
    {
        return;
    }

    ApplySightState(Actor, Stimulus.WasSuccessfullySensed());
}

void ASimpleEnemyAIController::ApplySightState(AActor* Actor, const bool bIsVisible)
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
    TargetActor = nullptr;
    bCanSeeTarget = false;

    if (bWasVisible)
    {
        UE_LOG(LogJMMonsterFramework, Log, TEXT("Lost: %s"), *GetNameSafe(Actor));
    }
}
