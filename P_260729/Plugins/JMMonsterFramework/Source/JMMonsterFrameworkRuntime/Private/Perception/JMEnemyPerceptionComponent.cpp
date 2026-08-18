#include "Perception/JMEnemyPerceptionComponent.h"

#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "HAL/PlatformTime.h"
#include "Perception/AISense.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "TimerManager.h"

UJMEnemyPerceptionComponent::UJMEnemyPerceptionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMEnemyPerceptionComponent::BeginPlay()
{
    Super::BeginPlay();
    RefreshGazeTimer();
}

void UJMEnemyPerceptionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(GazeTimer);
    }
    Super::EndPlay(EndPlayReason);
}

void UJMEnemyPerceptionComponent::ApplyConfig(const FJMEnemyPerceptionConfig& InConfig)
{
    ActiveConfig = InConfig;
    if (HasBegunPlay())
    {
        RefreshGazeTimer();
    }
}

void UJMEnemyPerceptionComponent::HandlePerceptionStimulus(AActor* SourceActor, const FAIStimulus& EngineStimulus)
{
    FJMStimulus Normalized;
    Normalized.SourceActor = SourceActor;
    Normalized.WorldLocation = EngineStimulus.StimulusLocation;
    Normalized.Strength = EngineStimulus.Strength;
    Normalized.Confidence = 1.0f;
    Normalized.Timestamp = GetCurrentTime();
    Normalized.bSuccessfullySensed = EngineStimulus.WasSuccessfullySensed();

    if (EngineStimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
    {
        if (!ActiveConfig.Vision.bEnabled)
        {
            return;
        }
        Normalized.Type = EJMStimulusType::Vision;
    }
    else if (EngineStimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
    {
        if (!ActiveConfig.Hearing.bEnabled || !EngineStimulus.WasSuccessfullySensed() ||
            EngineStimulus.Strength < ActiveConfig.Hearing.MinimumStrength)
        {
            return;
        }
        Normalized.Type = EJMStimulusType::Hearing;
    }
    else
    {
        return;
    }

    SubmitStimulus(Normalized);
}

bool UJMEnemyPerceptionComponent::SubmitStimulus(FJMStimulus Stimulus)
{
    if (!Stimulus.IsValid() || !IsSenseEnabled(Stimulus.Type))
    {
        return false;
    }

    LastStimuli.Add(Stimulus.Type, Stimulus);
    OnStimulusReceived.Broadcast(Stimulus);
    return true;
}

bool UJMEnemyPerceptionComponent::IsSenseEnabled(const EJMStimulusType Type) const
{
    switch (Type)
    {
    case EJMStimulusType::Vision: return ActiveConfig.Vision.bEnabled;
    case EJMStimulusType::Hearing: return ActiveConfig.Hearing.bEnabled;
    case EJMStimulusType::PlayerGaze: return ActiveConfig.PlayerGaze.bEnabled;
    case EJMStimulusType::Damage: return true;
    default: return false;
    }
}

bool UJMEnemyPerceptionComponent::GetLastStimulus(const EJMStimulusType Type, FJMStimulus& OutStimulus) const
{
    if (const FJMStimulus* Found = LastStimuli.Find(Type))
    {
        OutStimulus = *Found;
        return true;
    }
    return false;
}

void UJMEnemyPerceptionComponent::RefreshGazeTimer()
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return;
    }

    World->GetTimerManager().ClearTimer(GazeTimer);
    LastGazeEvaluationTime = GetCurrentTime();

    if (!ActiveConfig.PlayerGaze.bEnabled)
    {
        UpdateGazeState(false, 0.0f, nullptr, LastGazeEvaluationTime);
        return;
    }

    const float Interval = FMath::Max(ActiveConfig.PlayerGaze.UpdateInterval, 0.05f);
    World->GetTimerManager().SetTimer(GazeTimer, this, &ThisClass::EvaluatePlayerGaze, Interval, true);
}

void UJMEnemyPerceptionComponent::EvaluatePlayerGaze()
{
    UWorld* World = GetWorld();
    AActor* Owner = GetOwner();
    if (!World || !Owner || !ActiveConfig.PlayerGaze.bEnabled)
    {
        return;
    }

    FVector TargetLocation;
    FRotator UnusedRotation;
    Owner->GetActorEyesViewPoint(TargetLocation, UnusedRotation);

    float BestStrength = -1.0f;
    AActor* BestSource = nullptr;
    for (FConstPlayerControllerIterator It = World->GetPlayerControllerIterator(); It; ++It)
    {
        APlayerController* Controller = It->Get();
        float CandidateStrength = 0.0f;
        if (IsValid(Controller) && EvaluateControllerGaze(*Controller, TargetLocation, CandidateStrength) &&
            CandidateStrength > BestStrength)
        {
            BestStrength = CandidateStrength;
            BestSource = Controller->GetPawn() ? static_cast<AActor*>(Controller->GetPawn()) : Controller;
        }
    }

    UpdateGazeState(BestSource != nullptr, FMath::Max(BestStrength, 0.0f), BestSource, GetCurrentTime());
}

bool UJMEnemyPerceptionComponent::EvaluateControllerGaze(
    APlayerController& Controller, const FVector TargetLocation, float& OutStrength) const
{
    FVector ViewLocation;
    FRotator ViewRotation;
    Controller.GetPlayerViewPoint(ViewLocation, ViewRotation);

    const FVector ToEnemy = TargetLocation - ViewLocation;
    const float Distance = ToEnemy.Size();
    if (Distance <= UE_SMALL_NUMBER || Distance > ActiveConfig.PlayerGaze.MaximumDistance)
    {
        return false;
    }

    const float Dot = FVector::DotProduct(ViewRotation.Vector(), ToEnemy / Distance);
    if (Dot < ActiveConfig.PlayerGaze.DotThreshold)
    {
        return false;
    }

    if (ActiveConfig.PlayerGaze.bRequireLineOfSight)
    {
        const UWorld* World = GetWorld();
        if (!World)
        {
            return false;
        }

        FCollisionQueryParams Params(SCENE_QUERY_STAT(JMEnemyPlayerGaze), false);
        if (APawn* Pawn = Controller.GetPawn())
        {
            Params.AddIgnoredActor(Pawn);
        }

        FHitResult Hit;
        const bool bBlocked = World->LineTraceSingleByChannel(
            Hit, ViewLocation, TargetLocation, ActiveConfig.PlayerGaze.TraceChannel, Params);
        if (bBlocked && Hit.GetActor() != GetOwner())
        {
            return false;
        }
    }

    OutStrength = FMath::Clamp(Dot, 0.0f, 1.0f);
    return true;
}

void UJMEnemyPerceptionComponent::UpdateGazeState(
    const bool bNewLooking, const float NewStrength, AActor* NewSource, const double CurrentTime)
{
    const bool bSourceChanged = GazeSourceActor.Get() != NewSource;
    const bool bStateChanged = bIsPlayerLookingAtMe != bNewLooking;

    if (bNewLooking)
    {
        if (bIsPlayerLookingAtMe && !bSourceChanged && LastGazeEvaluationTime >= 0.0)
        {
            GazeDuration += static_cast<float>(FMath::Max(0.0, CurrentTime - LastGazeEvaluationTime));
        }
        else
        {
            GazeDuration = 0.0f;
        }
        GazeStrength = NewStrength;
    }
    else
    {
        GazeDuration = 0.0f;
        GazeStrength = 0.0f;
    }

    AActor* PreviousSource = GazeSourceActor.Get();
    bIsPlayerLookingAtMe = bNewLooking;
    GazeSourceActor = NewSource;
    LastGazeEvaluationTime = CurrentTime;

    // Persistent gaze is queried directly; events only describe entering, leaving, or source hand-off.
    if (bStateChanged || bSourceChanged)
    {
        FJMStimulus GazeStimulus;
        GazeStimulus.Type = EJMStimulusType::PlayerGaze;
        GazeStimulus.SourceActor = bNewLooking ? NewSource : PreviousSource;
        GazeStimulus.WorldLocation = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
        GazeStimulus.Strength = GazeStrength;
        GazeStimulus.Confidence = 1.0f;
        GazeStimulus.Timestamp = CurrentTime;
        GazeStimulus.bSuccessfullySensed = bNewLooking;
        SubmitStimulus(GazeStimulus);
    }
}

double UJMEnemyPerceptionComponent::GetCurrentTime() const
{
    return GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : FPlatformTime::Seconds();
}
