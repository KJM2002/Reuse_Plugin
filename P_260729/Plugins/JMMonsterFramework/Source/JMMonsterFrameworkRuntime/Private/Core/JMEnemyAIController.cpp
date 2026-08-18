#include "Core/JMEnemyAIController.h"

#include "Core/JMEnemyBase.h"
#include "Core/JMEnemyDefinition.h"
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
    if (FrameworkPerception.IsValid())
    {
        FrameworkPerception->OnStimulusReceived.RemoveDynamic(
            this, &ThisClass::HandleFrameworkStimulus);
    }
    if (EnemyStateTree)
    {
        EnemyStateTree->StopFrameworkTree(TEXT("Enemy unpossessed"));
    }
    FrameworkPerception.Reset();
    Super::OnUnPossess();
}

void AJMEnemyAIController::ConfigureFromPawn()
{
    const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(GetPawn());
    if (FrameworkPerception.IsValid())
    {
        FrameworkPerception->OnStimulusReceived.RemoveDynamic(
            this, &ThisClass::HandleFrameworkStimulus);
    }
    FrameworkPerception = Enemy ? Enemy->GetEnemyPerceptionComponent() : nullptr;
    if (!FrameworkPerception.IsValid())
    {
        return;
    }
    FrameworkPerception->OnStimulusReceived.AddUniqueDynamic(
        this, &ThisClass::HandleFrameworkStimulus);

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

    const UJMEnemyDefinition* Definition = Enemy->GetEnemyDefinition();
    if (EnemyStateTree)
    {
        EnemyStateTree->StartFrameworkTree(Definition ? Definition->StateTree.Get() : nullptr);
    }
}

void AJMEnemyAIController::HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
    if (FrameworkPerception.IsValid())
    {
        FrameworkPerception->HandlePerceptionStimulus(Actor, Stimulus);
    }
}

void AJMEnemyAIController::HandleFrameworkStimulus(FJMStimulus Stimulus)
{
    if (EnemyStateTree && EnemyStateTree->IsRunning())
    {
        EnemyStateTree->SendStateTreeEvent(JMEnemyTags::Event_Stimulus);
    }
}
