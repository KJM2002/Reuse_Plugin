#include "Core/JMEnemyAIController.h"

#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
#include "JMMonsterFrameworkRuntime.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "StateTree/JMEnemyStateTreeComponent.h"
#include "Types/JMEnemyTags.h"

AJMEnemyAIController::AJMEnemyAIController()
{
    EnemyPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
    EnemyStateTree = CreateDefaultSubobject<UJMEnemyStateTreeComponent>(TEXT("EnemyStateTree"));
    SetPerceptionComponent(*EnemyPerception);

    // Seed the component before registration. UAIPerceptionComponent::OnRegister only creates a
    // listener when at least one sense config already exists.
    EnemyPerception->ConfigureSense(*SightConfig);
    EnemyPerception->ConfigureSense(*HearingConfig);
}

void AJMEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
    EnemyPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(
        this, &ThisClass::HandleTargetPerceptionUpdated);
    if (GetPawn())
    {
        ConfigureFromPawn();
    }
}

void AJMEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    if (HasActorBegunPlay())
    {
        ConfigureFromPawn();
    }
}

void AJMEnemyAIController::OnUnPossess()
{
    GetWorldTimerManager().ClearTimer(PerceptionConfigurationTimer);
    GetWorldTimerManager().ClearTimer(StimulusEventTimer);
    bStimulusEventQueued = false;
    if (EnemyStateTree)
    {
        EnemyStateTree->StopFrameworkTree(TEXT("Enemy unpossessed"));
    }
    FrameworkPerception.Reset();
    PerceptionConfigurationAttempts = 0;
    bBehaviorStarted = false;
    Super::OnUnPossess();
}

void AJMEnemyAIController::ConfigureFromPawn()
{
    const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(GetPawn());
    FrameworkPerception = Enemy ? Enemy->GetEnemyPerceptionComponent() : nullptr;
    if (!FrameworkPerception.IsValid())
    {
        return;
    }

    // StateTree event conditions read the memory written by this same stimulus. Dynamic multicast
    // delegates execute in registration order, so make that order explicit even when Controller
    // BeginPlay happens before the possessed pawn's BeginPlay.
    if (UJMEnemyMemoryComponent* Memory = Enemy->GetEnemyMemoryComponent())
    {
        FrameworkPerception->OnStimulusReceived.RemoveDynamic(
            Memory, &UJMEnemyMemoryComponent::HandleStimulus);
        FrameworkPerception->OnStimulusReceived.AddUniqueDynamic(
            Memory, &UJMEnemyMemoryComponent::HandleStimulus);
    }
    StartBehaviorFromPawn(*Enemy);
    TryConfigurePerception();
}

void AJMEnemyAIController::StartBehaviorFromPawn(const AJMEnemyBase& Enemy)
{
    if (bBehaviorStarted || !EnemyStateTree)
    {
        return;
    }
    const UJMEnemyDefinition* Definition = Enemy.GetEnemyDefinition();
    bBehaviorStarted = EnemyStateTree->StartFrameworkTree(Definition ? Definition->StateTree.Get() : nullptr);
}

void AJMEnemyAIController::TryConfigurePerception()
{
    if (!FrameworkPerception.IsValid() || !EnemyPerception || !SightConfig || !HearingConfig ||
        GetPawn() == nullptr)
    {
        return;
    }

    if (!EnemyPerception->GetListenerId().IsValid())
    {
        SchedulePerceptionConfigurationRetry();
        return;
    }

    GetWorldTimerManager().ClearTimer(PerceptionConfigurationTimer);
    PerceptionConfigurationAttempts = 0;

    const FJMEnemyPerceptionConfig& Config = FrameworkPerception->GetConfig();
    SightConfig->SightRadius = Config.Vision.SightRadius;
    SightConfig->LoseSightRadius = Config.Vision.LoseSightRadius;
    SightConfig->PeripheralVisionAngleDegrees = Config.Vision.PeripheralVisionAngle;
    SightConfig->SetMaxAge(Config.Vision.StimulusMaxAge);
    SightConfig->DetectionByAffiliation.bDetectEnemies = Config.Vision.bDetectEnemies;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = Config.Vision.bDetectFriendlies;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = Config.Vision.bDetectNeutrals;

    HearingConfig->HearingRange = Config.Hearing.HearingRange;
    HearingConfig->SetMaxAge(Config.Hearing.StimulusMaxAge);
    HearingConfig->DetectionByAffiliation.bDetectEnemies = Config.Hearing.bDetectEnemies;
    HearingConfig->DetectionByAffiliation.bDetectFriendlies = Config.Hearing.bDetectFriendlies;
    HearingConfig->DetectionByAffiliation.bDetectNeutrals = Config.Hearing.bDetectNeutrals;

    EnemyPerception->ConfigureSense(*SightConfig);
    EnemyPerception->ConfigureSense(*HearingConfig);
    EnemyPerception->SetSenseEnabled(UAISenseConfig_Sight::StaticClass(), Config.Vision.bEnabled);
    EnemyPerception->SetSenseEnabled(UAISenseConfig_Hearing::StaticClass(), Config.Hearing.bEnabled);
    if (Config.Vision.bEnabled)
    {
        EnemyPerception->SetDominantSense(UAISenseConfig_Sight::StaticClass());
    }
    else if (Config.Hearing.bEnabled)
    {
        EnemyPerception->SetDominantSense(UAISenseConfig_Hearing::StaticClass());
    }
    EnemyPerception->RequestStimuliListenerUpdate();
}

void AJMEnemyAIController::SchedulePerceptionConfigurationRetry()
{
    static constexpr int32 MaxRegistrationAttempts = 20;
    if (++PerceptionConfigurationAttempts > MaxRegistrationAttempts)
    {
        UE_LOG(LogJMMonsterFramework, Warning,
            TEXT("Perception listener registration did not become valid: Controller=%s Pawn=%s Attempts=%d"),
            *GetName(), GetPawn() ? *GetPawn()->GetName() : TEXT("None"), PerceptionConfigurationAttempts - 1);
        return;
    }

    if (!GetWorldTimerManager().IsTimerActive(PerceptionConfigurationTimer))
    {
        GetWorldTimerManager().SetTimer(PerceptionConfigurationTimer, this,
            &ThisClass::TryConfigurePerception, 0.05f, false);
    }
}

void AJMEnemyAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    if (FrameworkPerception.IsValid())
    {
        FrameworkPerception->HandlePerceptionStimulus(Actor, Stimulus);
    }
}

void AJMEnemyAIController::NotifyFrameworkStimulus(const FJMStimulus& Stimulus)
{
    if (!bStimulusEventQueued && EnemyStateTree && EnemyStateTree->IsRunning())
    {
        // The StateTree context evaluator snapshots Memory once per AI tick. Queue the event for
        // the next frame so transition bindings observe the stimulus that Memory just recorded.
        // Multiple perception callbacks in one frame intentionally collapse into one reevaluation.
        bStimulusEventQueued = true;
        StimulusEventTimer = GetWorldTimerManager().SetTimerForNextTick(
            FTimerDelegate::CreateUObject(this, &ThisClass::FlushFrameworkStimulusEvent));
    }
}

void AJMEnemyAIController::FlushFrameworkStimulusEvent()
{
    bStimulusEventQueued = false;
    if (EnemyStateTree && EnemyStateTree->IsRunning())
    {
        EnemyStateTree->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    }
}
