#include "Debug/JMEnemyDebugComponent.h"

#include "Action/JMEnemyAction.h"
#include "Action/JMEnemyActionComponent.h"
#include "Animation/JMEnemyAnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Core/JMEnemyAIController.h"
#include "Core/JMEnemyBase.h"
#include "DrawDebugHelpers.h"
#include "EngineUtils.h"
#include "HAL/IConsoleManager.h"
#include "Locomotion/JMEnemyLocomotionComponent.h"
#include "Locomotion/JMEnemyLocomotion_SurfaceCrawler.h"
#include "Memory/JMEnemyMemoryComponent.h"
#include "Perception/JMEnemyPerceptionComponent.h"
#include "State/JMEnemyStateComponent.h"
#include "StateTree/JMEnemyStateTreeComponent.h"

#if !UE_BUILD_SHIPPING
namespace
{
void SetWorldDebug(const TArray<FString>& Args, UWorld* World)
{
    if (!World) return;
    const bool bEnable = Args.IsEmpty() || FCString::Atoi(*Args[0]) != 0;
    for (TActorIterator<AJMEnemyBase> It(World); It; ++It)
    {
        if (UJMEnemyDebugComponent* Debug = It->FindComponentByClass<UJMEnemyDebugComponent>())
        {
            Debug->SetDebugEnabled(bEnable);
        }
    }
}

FAutoConsoleCommandWithWorldAndArgs GJMEnemyDebugCommand(
    TEXT("JM.AI.Debug"),
    TEXT("JM.AI.Debug 1 enables framework debug for enemies in the current world; 0 disables it."),
    FConsoleCommandWithWorldAndArgsDelegate::CreateStatic(&SetWorldDebug));
}
#endif

UJMEnemyDebugComponent::UJMEnemyDebugComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMEnemyDebugComponent::BeginPlay()
{
    Super::BeginPlay();
    PrimaryComponentTick.TickInterval = UpdateInterval;
    SetDebugEnabled(bEnableOnBeginPlay);
}

void UJMEnemyDebugComponent::SetDebugEnabled(const bool bEnabled)
{
#if UE_BUILD_SHIPPING
    bDebugEnabled = false;
    SetComponentTickEnabled(false);
#else
    bDebugEnabled = bEnabled;
    SetComponentTickEnabled(bDebugEnabled);
#endif
}

void UJMEnemyDebugComponent::TickComponent(
    const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
#if !UE_BUILD_SHIPPING
    if (!bDebugEnabled || !GetWorld() || !GetOwner()) return;
    DrawDebugString(GetWorld(), GetOwner()->GetActorLocation() + FVector(0, 0, 140),
        BuildStatusText(), nullptr, FColor::White, UpdateInterval * 1.5f, true, 1.0f);
    DrawWorldData();
#endif
}

FString UJMEnemyDebugComponent::BuildStatusText() const
{
    const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(GetOwner());
    if (!Enemy) return TEXT("JM Enemy Debug: invalid owner");
    const UJMEnemyStateComponent* State = Enemy->GetEnemyStateComponent();
    const UJMEnemyMemoryComponent* Memory = Enemy->GetEnemyMemoryComponent();
    const UJMEnemyPerceptionComponent* Perception = Enemy->GetEnemyPerceptionComponent();
    const UJMEnemyLocomotionComponent* Move = Enemy->GetEnemyLocomotionComponent();
    const UJMEnemyActionComponent* Actions = Enemy->GetEnemyActionComponent();
    const UJMEnemyAction* Action = Actions ? Actions->GetCurrentAction() : nullptr;
    const UAnimInstance* RawAnim = Enemy->GetMesh() ? Enemy->GetMesh()->GetAnimInstance() : nullptr;
    const UJMEnemyAnimInstance* Anim = Cast<UJMEnemyAnimInstance>(RawAnim);
    const AJMEnemyAIController* Controller = Cast<AJMEnemyAIController>(Enemy->GetController());
    const UJMEnemyStateTreeComponent* Tree = Controller ? Controller->GetEnemyStateTreeComponent() : nullptr;

    return FString::Printf(
        TEXT("%s\nState: %s | Target: %s | See: %s | Encounters: %d\n")
        TEXT("Memory Seen:%s Heard:%s Known:%s\nGaze: %s Strength %.2f Duration %.2f\n")
        TEXT("Move: %s Profile:%s Dest:%s Target:%s Request:%u\n")
        TEXT("Action: %s Phase:%s Cooldown:%.2f | StateTree:%s\n")
        TEXT("Anim:%s Speed:%.1f Direction:%.1f Action:%s Phase:%s"),
        *Enemy->GetName(), State ? *State->GetCurrentState().ToString() : TEXT("None"),
        Memory ? *GetNameSafe(Memory->GetCurrentTarget()) : TEXT("None"),
        Memory && Memory->CanCurrentlySeeTarget() ? TEXT("Yes") : TEXT("No"),
        Memory ? Memory->GetEncounterCount() : 0,
        Memory ? *Memory->GetLastSeenLocation().ToCompactString() : TEXT("None"),
        Memory ? *Memory->GetLastHeardLocation().ToCompactString() : TEXT("None"),
        Memory ? *Memory->GetLastKnownTargetLocation().ToCompactString() : TEXT("None"),
        Perception && Perception->IsPlayerLookingAtMe() ? TEXT("Yes") : TEXT("No"),
        Perception ? Perception->GetGazeStrength() : 0.0f,
        Perception ? Perception->GetGazeDuration() : 0.0f,
        Move ? *StaticEnum<EJMEnemyMoveStatus>()->GetNameStringByValue(static_cast<int64>(Move->GetMoveStatus())) : TEXT("None"),
        Move ? *Move->GetCurrentMovementProfile().ToString() : TEXT("None"),
        Move ? *Move->GetCurrentDestination().ToCompactString() : TEXT("None"),
        Move ? *GetNameSafe(Move->GetCurrentMoveTarget()) : TEXT("None"),
        Move ? Move->GetCurrentRequestID().GetID() : 0,
        Action ? *Action->GetActionId().ToString() : TEXT("None"),
        Action ? *StaticEnum<EJMEnemyActionPhase>()->GetNameStringByValue(static_cast<int64>(Action->GetPhase())) : TEXT("Idle"),
        Action ? Action->GetRemainingCooldown() : 0.0f,
        Tree && Tree->IsRunning() ? TEXT("Running") : TEXT("Stopped"),
        RawAnim ? *RawAnim->GetClass()->GetName() : TEXT("None"),
        Anim ? Anim->Speed : 0.0f,
        Anim ? Anim->Direction : 0.0f,
        Anim ? *Anim->CurrentAction.ToString() : TEXT("None"),
        Anim ? *StaticEnum<EJMEnemyActionPhase>()->GetNameStringByValue(
            static_cast<int64>(Anim->CurrentActionPhase)) : TEXT("Idle"));
}

void UJMEnemyDebugComponent::DrawWorldData() const
{
    const AJMEnemyBase* Enemy = Cast<AJMEnemyBase>(GetOwner());
    if (!Enemy || !GetWorld()) return;
    const FVector Origin = Enemy->GetActorLocation();
    const UJMEnemyPerceptionComponent* Perception = Enemy->GetEnemyPerceptionComponent();
    const UJMEnemyMemoryComponent* Memory = Enemy->GetEnemyMemoryComponent();
    const UJMEnemyLocomotionComponent* Move = Enemy->GetEnemyLocomotionComponent();
    const float Life = UpdateInterval * 1.5f;

    if (Perception)
    {
        const FJMEnemyPerceptionConfig& Config = Perception->GetConfig();
        if (Config.Vision.bEnabled)
        {
            DrawDebugCone(GetWorld(), Origin, Enemy->GetActorForwardVector(), Config.Vision.SightRadius,
                FMath::DegreesToRadians(Config.Vision.PeripheralVisionAngle),
                FMath::DegreesToRadians(Config.Vision.PeripheralVisionAngle), 20, FColor::Green, false, Life);
        }
        if (Config.Hearing.bEnabled)
        {
            DrawDebugSphere(GetWorld(), Origin, Config.Hearing.HearingRange, 24, FColor::Blue, false, Life);
        }
        if (AActor* Source = Perception->GetGazeSourceActor())
        {
            DrawDebugLine(GetWorld(), Source->GetActorLocation(), Origin, FColor::Purple, false, Life, 0, 2.0f);
        }
    }
    if (Memory)
    {
        DrawDebugSphere(GetWorld(), Memory->GetLastSeenLocation(), 20, 8, FColor::Green, false, Life);
        DrawDebugSphere(GetWorld(), Memory->GetLastHeardLocation(), 20, 8, FColor::Blue, false, Life);
        DrawDebugSphere(GetWorld(), Memory->GetLastKnownTargetLocation(), 24, 8, FColor::Yellow, false, Life);
    }
    if (Move && Move->GetMoveStatus() == EJMEnemyMoveStatus::Moving)
    {
        DrawDebugDirectionalArrow(GetWorld(), Origin, Move->GetCurrentDestination(), 30,
            FColor::Orange, false, Life, 0, 2.0f);
    }
    if (const UJMEnemyLocomotion_SurfaceCrawler* Surface =
        Cast<UJMEnemyLocomotion_SurfaceCrawler>(Move))
    {
        DrawDebugDirectionalArrow(GetWorld(), Surface->GetAttachmentPoint(),
            Surface->GetAttachmentPoint() + Surface->GetCurrentSurfaceNormal() * 100,
            25, FColor::Cyan, false, Life, 0, 2.0f);
        DrawDebugLine(GetWorld(), Origin, Surface->GetAttachmentPoint(), FColor::Cyan, false, Life);
        DrawDebugDirectionalArrow(GetWorld(), Origin,
            Origin + Surface->GetDesiredMoveDirection() * 120, 25, FColor::Yellow, false, Life);
    }
}
