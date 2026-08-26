#include "AI/ListenerEnemyAIController.h"

#include "JMMonsterFrameworkRuntime.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "StateTree.h"

AListenerEnemyAIController::AListenerEnemyAIController()
{
    StateTreeAsset = TSoftObjectPtr<UStateTree>(FSoftObjectPath(
        TEXT("/JMMonsterFramework/AI/ST_ListenerEnemy.ST_ListenerEnemy")));

    if (HearingConfig)
    {
        HearingConfig->HearingRange = 2500.0f;
    }
}

void AListenerEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    SetSightConfirmationEnabled(false);
}

void AListenerEnemyAIController::SetSightConfirmationEnabled(const bool bEnabled)
{
    UAIPerceptionComponent* Perception = GetPerceptionComponent();
    if (!IsValid(Perception))
    {
        return;
    }

    Perception->SetSenseEnabled(UAISense_Sight::StaticClass(), bEnabled);
    Perception->RequestStimuliListenerUpdate();

    if (!bEnabled)
    {
        EnemyMemory.TargetActor = nullptr;
        EnemyMemory.bCanSeeTarget = false;
        EnemyMemory.bHasRecentTrackingMemory = false;
        EndLiveGraceTracking();
    }

    UE_LOG(
        LogJMMonsterFramework,
        Log,
        TEXT("[JM LISTENER SIGHT] Enemy=%s Enabled=%d"),
        *GetNameSafe(GetPawn()),
        Perception->IsSenseEnabled(UAISense_Sight::StaticClass()));
}
