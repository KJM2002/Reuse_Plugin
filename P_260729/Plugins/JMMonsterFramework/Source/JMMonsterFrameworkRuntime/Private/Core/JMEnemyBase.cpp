#include "Core/JMEnemyBase.h"

#include "Action/JMEnemyActionComponent.h"
#include "Audio/JMEnemyAudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Core/JMEnemyDefinition.h"
#include "Core/JMEnemyAIController.h"
#include "JMMonsterFrameworkRuntime.h"
#include "Debug/JMEnemyDebugComponent.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Patrol/JMEnemyPatrolComponent.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "Engine/World.h"
#include "HAL/PlatformTime.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

AJMEnemyBase::AJMEnemyBase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = false;

    StateComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyStateComponent>(this, TEXT("EnemyState"));
    PerceptionComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyPerceptionComponent>(this, TEXT("EnemyPerception"));
    MemoryComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyMemoryComponent>(this, TEXT("EnemyMemory"));
    LocomotionComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyLocomotionComponent>(this, TEXT("EnemyLocomotion"));
    PatrolComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyPatrolComponent>(this, TEXT("EnemyPatrol"));
    ActionComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyActionComponent>(this, TEXT("EnemyActions"));
    AudioComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyAudioComponent>(this, TEXT("EnemyAudio"));
    DebugComponent = ObjectInitializer.CreateDefaultSubobject<UJMEnemyDebugComponent>(this, TEXT("EnemyDebug"));

    AIControllerClass = AJMEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    // A moving enemy is a navigation agent, not moving level geometry.
    // APawn itself defaults to not affecting navigation, but primitive components can still be nav-relevant.
    SetCanAffectNavigationGeneration(false, false);
}

void AJMEnemyBase::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    // Blueprint/SCS primitive components exist by this point, so the policy also covers
    // extra collision and mesh components added by a concrete enemy Blueprint.
    ApplyNavigationInfluencePolicy();
    InitializeEnemy();
}

void AJMEnemyBase::BeginPlay()
{
    Super::BeginPlay();

    if (!bFrameworkInitialized)
    {
        InitializeEnemy();
    }

    if (!EnemyDefinition)
    {
        UE_LOG(LogJMMonsterFramework, Warning,
            TEXT("Enemy '%s' has no Enemy Definition. Core defaults remain active."), *GetNameSafe(this));
    }
}

void AJMEnemyBase::ApplyNavigationInfluencePolicy()
{
    SetCanAffectNavigationGeneration(bPrimitiveComponentsAffectNavigation, false);

    if (bPrimitiveComponentsAffectNavigation)
    {
        return;
    }

    TInlineComponentArray<UPrimitiveComponent*> PrimitiveComponents;
    GetComponents(PrimitiveComponents);

    for (UPrimitiveComponent* Primitive : PrimitiveComponents)
    {
        if (IsValid(Primitive) && Primitive->CanEverAffectNavigation())
        {
            Primitive->SetCanEverAffectNavigation(false);
        }
    }
}

void AJMEnemyBase::InitializeEnemy()
{
    if (bFrameworkInitialized)
    {
        return;
    }

    bFrameworkInitialized = true;

    if (EnemyDefinition)
    {
        ApplyDefinition(*EnemyDefinition);
    }

    if (AudioComponent)
    {
        AudioComponent->InitializeAudio(EnemyDefinition ? EnemyDefinition->AudioSet.Get() : nullptr,
            StateComponent, ActionComponent);
    }

    if (PerceptionComponent && MemoryComponent)
    {
        PerceptionComponent->OnStimulusReceived.AddUniqueDynamic(
            MemoryComponent, &UJMEnemyMemoryComponent::HandleStimulus);
    }
}

float AJMEnemyBase::TakeDamage(const float DamageAmount, const FDamageEvent& DamageEvent,
    AController* EventInstigator, AActor* DamageCauser)
{
    const float AppliedDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    if (AppliedDamage > 0.0f && PerceptionComponent)
    {
        AActor* Source = DamageCauser;
        if (!Source && EventInstigator)
        {
            Source = EventInstigator->GetPawn() ? static_cast<AActor*>(EventInstigator->GetPawn()) : EventInstigator;
        }

        FJMStimulus Stimulus;
        Stimulus.Type = EJMStimulusType::Damage;
        Stimulus.SourceActor = Source;
        Stimulus.WorldLocation = Source ? Source->GetActorLocation() : GetActorLocation();
        Stimulus.Strength = AppliedDamage;
        Stimulus.Confidence = 1.0f;
        Stimulus.Timestamp = GetWorld() ? static_cast<double>(GetWorld()->GetTimeSeconds()) : FPlatformTime::Seconds();
        Stimulus.bSuccessfullySensed = true;
        PerceptionComponent->SubmitStimulus(Stimulus);
    }

    return AppliedDamage;
}

void AJMEnemyBase::ApplyDefinition(const UJMEnemyDefinition& Definition)
{
    if (StateComponent && !StateComponent->SetState(Definition.InitialState) &&
        StateComponent->GetCurrentState() != Definition.InitialState)
    {
        UE_LOG(LogJMMonsterFramework, Warning,
            TEXT("Enemy '%s' could not apply initial state '%s' from definition '%s'."),
            *GetNameSafe(this), *Definition.InitialState.ToString(), *GetNameSafe(&Definition));
    }

    if (PerceptionComponent)
    {
        PerceptionComponent->ApplyConfig(Definition.Perception);
    }

    if (PatrolComponent)
    {
        PatrolComponent->MinWaitTime = Definition.BehaviorTuning.PatrolMinWaitTime;
        PatrolComponent->MaxWaitTime = Definition.BehaviorTuning.PatrolMaxWaitTime;
    }

    if (LocomotionComponent && Definition.MovementSet &&
        !LocomotionComponent->ApplyMovementProfile(Definition.MovementSet, Definition.DefaultMovementProfile))
    {
        UE_LOG(LogJMMonsterFramework, Warning,
            TEXT("Enemy '%s' could not apply movement profile '%s' from definition '%s'."),
            *GetNameSafe(this), *Definition.DefaultMovementProfile.ToString(), *GetNameSafe(&Definition));
    }

    if (ActionComponent)
    {
        ActionComponent->InitializeActions(Definition.Actions);
    }
}

#if WITH_EDITOR
EDataValidationResult AJMEnemyBase::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);

    if (!EnemyDefinition)
    {
        Context.AddError(NSLOCTEXT("JMMonsterFramework", "MissingEnemyDefinition",
            "Enemy Definition is required for a configured JM Enemy."));
        return EDataValidationResult::Invalid;
    }

    return Result == EDataValidationResult::NotValidated ? EDataValidationResult::Valid : Result;
}
#endif
