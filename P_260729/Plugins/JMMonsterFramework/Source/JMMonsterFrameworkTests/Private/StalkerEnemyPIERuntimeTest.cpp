#include "AI/StalkerEnemyAIController.h"
#include "Characters/SimpleEnemyCharacter.h"

#include "Components/StateTreeAIComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Misc/AutomationTest.h"
#include "NavigationSystem.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Sight.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationEditorCommon.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace
{
    UWorld* GetStalkerPIEWorld()
    {
        if (!GEngine)
        {
            return nullptr;
        }
        for (const FWorldContext& WorldContext : GEngine->GetWorldContexts())
        {
            if (WorldContext.WorldType == EWorldType::PIE && IsValid(WorldContext.World()))
            {
                return WorldContext.World();
            }
        }
        return nullptr;
    }

    bool HasStalkerState(const AStalkerEnemyAIController* Controller, const FName StateName)
    {
        const UStateTreeAIComponent* Component = IsValid(Controller)
            ? Controller->FindComponentByClass<UStateTreeAIComponent>()
            : nullptr;
        return IsValid(Component) && Component->GetActiveStateNames().Contains(StateName);
    }

    class FJMStalkerPIERuntimeCommand final : public IAutomationLatentCommand
    {
    public:
        explicit FJMStalkerPIERuntimeCommand(FAutomationTestBase& InTest)
            : Test(InTest)
            , CommandStartTime(FPlatformTime::Seconds())
            , StageStartTime(CommandStartTime)
        {
        }

        virtual bool Update() override
        {
            UWorld* World = GetStalkerPIEWorld();
            if (!IsValid(World))
            {
                if (FPlatformTime::Seconds() - CommandStartTime > 10.0)
                {
                    Test.AddError(TEXT("Stalker PIE world did not start."));
                    return true;
                }
                return false;
            }

            if (!bSetupComplete && !Setup(*World))
            {
                return true;
            }

            const double Now = FPlatformTime::Seconds();
            if (Now - CommandStartTime > 35.0)
            {
                Test.AddError(TEXT("Stalker PIE runtime sequence timed out."));
                return true;
            }

            AStalkerEnemyAIController* Controller = StalkerController.Get();
            ASimpleEnemyCharacter* StalkerPawn = Stalker.Get();
            ACharacter* PlayerPawn = Player.Get();
            UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
            if (!IsValid(Controller) || !IsValid(StalkerPawn) || !IsValid(PlayerPawn) || !IsValid(NavSystem))
            {
                Test.AddError(TEXT("Stalker PIE actors or NavigationSystem became invalid."));
                return true;
            }

            switch (Stage)
            {
            case EStage::AwaitApproach:
                if (Controller->EnemyMemory.bCanSeeTarget
                    && Controller->CurrentDistanceBand == EJMStalkerDistanceBand::TooFar
                    && HasStalkerState(Controller, TEXT("Approach")))
                {
                    InitialDistance = Controller->CurrentTargetDistance;
                    MinimumApproachDistance = InitialDistance;
                    ApproachStartLocation = StalkerPawn->GetActorLocation();
                    MaximumApproachMovement = 0.0f;
                    StageStartTime = Now;
                    Stage = EStage::ObserveApproach;
                }
                else if (Now - StageStartTime > 6.0)
                {
                    Test.AddError(TEXT("Actual Sight did not reach Stalker Approach in PIE."));
                    return true;
                }
                break;

            case EStage::ObserveApproach:
                MinimumApproachDistance = FMath::Min(
                    MinimumApproachDistance,
                    Controller->CurrentTargetDistance);
                MaximumApproachMovement = FMath::Max(
                    MaximumApproachMovement,
                    FVector::Dist2D(ApproachStartLocation, StalkerPawn->GetActorLocation()));
                if (Controller->CurrentDistanceBand == EJMStalkerDistanceBand::Preferred
                    || Now - StageStartTime >= 2.0)
                {
                    Test.TestTrue(
                        TEXT("Far actual Player makes Stalker move on NavMesh"),
                        MaximumApproachMovement > 50.0f);
                    Test.TestTrue(
                        TEXT("Far actual Player makes Stalker reduce target distance"),
                        MinimumApproachDistance < InitialDistance - 50.0f);
                    if (!MovePlayerToDistance(*NavSystem, *StalkerPawn, *PlayerPawn, 600.0f))
                    {
                        Test.AddError(TEXT("Could not project preferred-distance Player position to NavMesh."));
                        return true;
                    }
                    StageStartTime = Now;
                    Stage = EStage::AwaitHold;
                }
                break;

            case EStage::AwaitHold:
                if (Controller->CurrentDistanceBand == EJMStalkerDistanceBand::Preferred
                    && HasStalkerState(Controller, TEXT("HoldDistance")))
                {
                    HoldStartLocation = StalkerPawn->GetActorLocation();
                    StageStartTime = Now;
                    Stage = EStage::ObserveHold;
                }
                else if (Now - StageStartTime > 4.0)
                {
                    Test.AddError(TEXT("Preferred actual Player distance did not reach HoldDistance."));
                    return true;
                }
                break;

            case EStage::ObserveHold:
                if (Now - StageStartTime >= 1.0)
                {
                    Test.TestTrue(
                        TEXT("Preferred distance stops Stalker movement"),
                        FVector::Dist2D(HoldStartLocation, StalkerPawn->GetActorLocation()) < 30.0f);
                    BoundaryMoveIndex = 0;
                    StageStartTime = Now;
                    Stage = EStage::BoundaryMoves;
                }
                break;

            case EStage::BoundaryMoves:
                if (Now - StageStartTime >= 0.12)
                {
                    const float BoundaryDistance = BoundaryMoveIndex % 2 == 0 ? 720.0f : 790.0f;
                    if (!MovePlayerToDistance(*NavSystem, *StalkerPawn, *PlayerPawn, BoundaryDistance))
                    {
                        Test.AddError(TEXT("Could not project boundary Player position to NavMesh."));
                        return true;
                    }
                    ++BoundaryMoveIndex;
                    StageStartTime = Now;
                    if (Controller->CurrentDistanceBand != EJMStalkerDistanceBand::Preferred)
                    {
                        ++BoundaryBandChanges;
                    }
                    if (BoundaryMoveIndex >= 12)
                    {
                        Test.TestEqual(
                            TEXT("Actual Player boundary movement causes no distance-band oscillation"),
                            BoundaryBandChanges,
                            0);
                        if (!MovePlayerToDistance(*NavSystem, *StalkerPawn, *PlayerPawn, 180.0f))
                        {
                            Test.AddError(TEXT("Could not project close Player position to NavMesh."));
                            return true;
                        }
                        StageStartTime = Now;
                        Stage = EStage::AwaitRetreat;
                    }
                }
                break;

            case EStage::AwaitRetreat:
                if (Controller->CurrentDistanceBand == EJMStalkerDistanceBand::TooClose
                    && HasStalkerState(Controller, TEXT("Retreat")))
                {
                    InitialDistance = Controller->CurrentTargetDistance;
                    StageStartTime = Now;
                    Stage = EStage::ObserveRetreat;
                }
                else if (Now - StageStartTime > 4.0)
                {
                    Test.AddError(TEXT("Close actual Player did not reach Retreat."));
                    return true;
                }
                break;

            case EStage::ObserveRetreat:
                if (Now - StageStartTime >= 1.5)
                {
                    Test.TestTrue(
                        TEXT("Close actual Player makes Stalker retreat"),
                        Controller->CurrentTargetDistance > InitialDistance + 100.0f);

                    FNavLocation ProjectedStalkerLocation;
                    const bool bStalkerOnNavMesh = NavSystem->ProjectPointToNavigation(
                        StalkerPawn->GetActorLocation(),
                        ProjectedStalkerLocation,
                        FVector(100.0, 100.0, 250.0));
                    Test.TestTrue(TEXT("Retreat Stalker remains on NavMesh"), bStalkerOnNavMesh);
                    if (bStalkerOnNavMesh)
                    {
                        Test.TestTrue(
                            TEXT("Retreat never selects an off-NavMesh actor position"),
                            FVector::Dist2D(ProjectedStalkerLocation.Location, StalkerPawn->GetActorLocation()) < 75.0f);
                    }

                    PlayerPawn->SetActorLocation(
                        StalkerPawn->GetActorLocation() + FVector(3000.0, 0.0, 100.0),
                        false,
                        nullptr,
                        ETeleportType::TeleportPhysics);
                    StageStartTime = Now;
                    Stage = EStage::AwaitSightLost;
                }
                break;

            case EStage::AwaitSightLost:
                if (!Controller->EnemyMemory.bCanSeeTarget)
                {
                    const bool bDistanceBandCleared =
                        Controller->CurrentDistanceBand == EJMStalkerDistanceBand::None;
                    const bool bEnteredLostSightFlow =
                        HasStalkerState(Controller, TEXT("RecentTracking"))
                        || HasStalkerState(Controller, TEXT("InvestigateLastLocation"))
                        || HasStalkerState(Controller, TEXT("Search"));

                    // Perception delegates can run after the controller and StateTree ticks
                    // for the current frame. Wait for the real runtime pipeline to converge
                    // instead of asserting against that valid one-frame intermediate state.
                    if (bDistanceBandCleared && bEnteredLostSightFlow)
                    {
                        return true;
                    }
                }
                if (Now - StageStartTime > 5.0)
                {
                    Test.AddError(TEXT(
                        "Stalker Sight Lost did not clear the distance band and enter Predictive tracking."));
                    return true;
                }
                break;
            }
            return false;
        }

    private:
        enum class EStage : uint8
        {
            AwaitApproach,
            ObserveApproach,
            AwaitHold,
            ObserveHold,
            BoundaryMoves,
            AwaitRetreat,
            ObserveRetreat,
            AwaitSightLost
        };

        bool Setup(UWorld& World)
        {
            UClass* StalkerClass = LoadObject<UClass>(
                nullptr,
                TEXT("/JMMonsterFramework/Blueprints/BP_StalkerEnemy.BP_StalkerEnemy_C"));
            UClass* PlayerClass = LoadObject<UClass>(
                nullptr,
                TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter.BP_FirstPersonCharacter_C"));
            UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(&World);
            if (!StalkerClass || !PlayerClass || !IsValid(NavSystem))
            {
                Test.AddError(TEXT("Stalker PIE test could not load actual Blueprints or NavigationSystem."));
                return false;
            }

            FBox NavBounds(ForceInit);
            for (TActorIterator<ANavMeshBoundsVolume> It(&World); It; ++It)
            {
                NavBounds += It->GetComponentsBoundingBox(true);
            }
            if (!NavBounds.IsValid)
            {
                Test.AddError(TEXT("Level_TestAI contains no NavMeshBoundsVolume."));
                return false;
            }

            FNavLocation BaseNavLocation;
            if (!NavSystem->ProjectPointToNavigation(
                NavBounds.GetCenter(),
                BaseNavLocation,
                FVector(500.0, 500.0, NavBounds.GetExtent().Z + 500.0)))
            {
                Test.AddError(TEXT("Could not find a valid NavMesh point inside Level_TestAI bounds."));
                return false;
            }

            FNavLocation StalkerNavLocation;
            if (!NavSystem->GetRandomReachablePointInRadius(BaseNavLocation.Location, 800.0f, StalkerNavLocation))
            {
                Test.AddError(TEXT("Could not find a reachable Stalker spawn point."));
                return false;
            }

            FNavLocation PlayerNavLocation;
            bool bFoundFarVisiblePoint = false;
            for (int32 Attempt = 0; Attempt < 64; ++Attempt)
            {
                FNavLocation Candidate;
                if (!NavSystem->GetRandomReachablePointInRadius(StalkerNavLocation.Location, 1400.0f, Candidate))
                {
                    continue;
                }
                const float CandidateDistance = FVector::Dist2D(Candidate.Location, StalkerNavLocation.Location);
                if (CandidateDistance < 1000.0f || CandidateDistance > 1400.0f)
                {
                    continue;
                }
                const FVector TraceStart = StalkerNavLocation.Location + FVector(0.0, 0.0, 80.0);
                const FVector TraceEnd = Candidate.Location + FVector(0.0, 0.0, 80.0);
                if (!World.LineTraceTestByChannel(TraceStart, TraceEnd, ECC_Visibility))
                {
                    PlayerNavLocation = Candidate;
                    bFoundFarVisiblePoint = true;
                    break;
                }
            }
            if (!bFoundFarVisiblePoint)
            {
                Test.AddError(TEXT("Could not find two visible NavMesh points for Stalker PIE test."));
                return false;
            }

            const FVector PlayerSpawnLocation = PlayerNavLocation.Location + FVector(0.0, 0.0, 100.0);
            const FVector StalkerSpawnLocation = StalkerNavLocation.Location + FVector(0.0, 0.0, 90.0);
            const FRotator StalkerSpawnRotation = (PlayerSpawnLocation - StalkerSpawnLocation).Rotation();
            APlayerController* PlayerController = World.GetFirstPlayerController();
            ACharacter* PlayerPawn = Cast<ACharacter>(World.SpawnActor(PlayerClass, &PlayerSpawnLocation, &StalkerSpawnRotation));
            if (!IsValid(PlayerController) || !IsValid(PlayerPawn))
            {
                Test.AddError(TEXT("Actual Player Blueprint or PlayerController did not spawn in PIE."));
                return false;
            }
            PlayerPawn->GetCharacterMovement()->GravityScale = 0.0f;
            PlayerController->Possess(PlayerPawn);
            UAIPerceptionSystem::RegisterPerceptionStimuliSource(
                &World,
                UAISense_Sight::StaticClass(),
                PlayerPawn);

            ASimpleEnemyCharacter* StalkerPawn = Cast<ASimpleEnemyCharacter>(
                World.SpawnActor(StalkerClass, &StalkerSpawnLocation, &StalkerSpawnRotation));
            if (StalkerPawn && !StalkerPawn->GetController())
            {
                StalkerPawn->SpawnDefaultController();
            }
            AStalkerEnemyAIController* Controller = StalkerPawn
                ? Cast<AStalkerEnemyAIController>(StalkerPawn->GetController())
                : nullptr;
            if (!IsValid(StalkerPawn) || !IsValid(Controller))
            {
                Test.AddError(TEXT("Actual Stalker Blueprint was not possessed by its Stalker controller."));
                return false;
            }

            Test.TestTrue(
                TEXT("Stalker PIE uses the actual Stalker controller Blueprint"),
                Controller->GetClass()->GetPathName().Contains(TEXT("BP_StalkerEnemyAIController")));
            Test.TestNotNull(
                TEXT("Stalker PIE runs its actual StateTree"),
                Controller->FindComponentByClass<UStateTreeAIComponent>());

            Stalker = StalkerPawn;
            StalkerController = Controller;
            Player = PlayerPawn;
            MoveDirection = (PlayerNavLocation.Location - StalkerNavLocation.Location).GetSafeNormal2D();
            bSetupComplete = true;
            StageStartTime = FPlatformTime::Seconds();
            return true;
        }

        bool MovePlayerToDistance(
            UNavigationSystemV1& NavSystem,
            const ASimpleEnemyCharacter& StalkerPawn,
            ACharacter& PlayerPawn,
            const float Distance) const
        {
            const FVector DesiredLocation = StalkerPawn.GetActorLocation() + MoveDirection * Distance;
            FNavLocation ProjectedLocation;
            if (!NavSystem.ProjectPointToNavigation(
                DesiredLocation,
                ProjectedLocation,
                FVector(150.0, 150.0, 300.0)))
            {
                return false;
            }
            PlayerPawn.SetActorLocation(
                ProjectedLocation.Location + FVector(0.0, 0.0, 100.0),
                false,
                nullptr,
                ETeleportType::TeleportPhysics);
            return true;
        }

        FAutomationTestBase& Test;
        TWeakObjectPtr<ASimpleEnemyCharacter> Stalker;
        TWeakObjectPtr<AStalkerEnemyAIController> StalkerController;
        TWeakObjectPtr<ACharacter> Player;
        FVector MoveDirection = FVector::ForwardVector;
        FVector ApproachStartLocation = FVector::ZeroVector;
        FVector HoldStartLocation = FVector::ZeroVector;
        float InitialDistance = 0.0f;
        float MinimumApproachDistance = 0.0f;
        float MaximumApproachMovement = 0.0f;
        int32 BoundaryMoveIndex = 0;
        int32 BoundaryBandChanges = 0;
        bool bSetupComplete = false;
        EStage Stage = EStage::AwaitApproach;
        double CommandStartTime = 0.0;
        double StageStartTime = 0.0;
    };
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMStalkerPIERuntimeTest,
    "JM.MonsterFramework.Stalker.PIERuntimeNavMeshPath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMStalkerPIERuntimeTest::RunTest(const FString& Parameters)
{
    AutomationOpenMap(TEXT("/Game/Level/Level_TestAI"), true);
    ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
    ADD_LATENT_AUTOMATION_COMMAND(FWaitLatentCommand(2.0f));
    ADD_LATENT_AUTOMATION_COMMAND(FJMStalkerPIERuntimeCommand(*this));
    ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
    return true;
}

#endif
