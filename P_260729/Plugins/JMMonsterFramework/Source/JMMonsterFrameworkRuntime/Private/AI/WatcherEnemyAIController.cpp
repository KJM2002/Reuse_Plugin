#include "AI/WatcherEnemyAIController.h"

#include "JMMonsterFrameworkRuntime.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"
#include "StateTree.h"

AWatcherEnemyAIController::AWatcherEnemyAIController()
{
    StateTreeAsset = TSoftObjectPtr<UStateTree>(FSoftObjectPath(
        TEXT("/JMMonsterFramework/AI/ST_WatcherEnemy.ST_WatcherEnemy")));
}

void AWatcherEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (UAIPerceptionComponent* Perception = GetPerceptionComponent())
    {
        Perception->SetSenseEnabled(UAISense_Sight::StaticClass(), false);
        Perception->SetSenseEnabled(UAISense_Hearing::StaticClass(), false);
        Perception->RequestStimuliListenerUpdate();
    }

    UpdatePlayerGaze(0.0f);
}

void AWatcherEnemyAIController::Tick(const float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    UpdatePlayerGaze(DeltaSeconds);
}

APawn* AWatcherEnemyAIController::GetGazePlayerPawn() const
{
    const UWorld* World = GetWorld();
    const APlayerController* PlayerController = World ? World->GetFirstPlayerController() : nullptr;
    return IsValid(PlayerController) ? PlayerController->GetPawn() : nullptr;
}

void AWatcherEnemyAIController::UpdatePlayerGaze(const float DeltaSeconds)
{
    UWorld* World = GetWorld();
    APawn* WatcherPawn = GetPawn();
    APlayerController* PlayerController = World ? World->GetFirstPlayerController() : nullptr;
    APawn* PlayerPawn = IsValid(PlayerController) ? PlayerController->GetPawn() : nullptr;

    bool bScreenPassed = false;
    bool bVisibilityPassed = false;
    FString BlockingActorName(TEXT("None"));
    if (IsValid(World) && IsValid(WatcherPawn) && IsValid(PlayerController) && IsValid(PlayerPawn))
    {
        FVector CameraLocation;
        FRotator CameraRotation;
        PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

        float HorizontalFOVDegrees = 90.0f;
        if (IsValid(PlayerController->PlayerCameraManager))
        {
            HorizontalFOVDegrees = PlayerController->PlayerCameraManager->GetFOVAngle();
        }

        int32 ViewportWidth = 0;
        int32 ViewportHeight = 0;
        PlayerController->GetViewportSize(ViewportWidth, ViewportHeight);
        const float AspectRatio = ViewportWidth > 0 && ViewportHeight > 0
            ? static_cast<float>(ViewportWidth) / static_cast<float>(ViewportHeight)
            : 16.0f / 9.0f;
        const float HorizontalHalfFOV = FMath::DegreesToRadians(
            FMath::Clamp(HorizontalFOVDegrees, 5.0f, 170.0f) * 0.5f);
        const float VerticalHalfFOV = FMath::Atan(FMath::Tan(HorizontalHalfFOV) / AspectRatio);
        const float ScreenFraction = FMath::Clamp(GazeScreenEdgeFraction, 0.1f, 1.0f);

        FVector WatcherEyeLocation;
        FRotator WatcherEyeRotation;
        WatcherPawn->GetActorEyesViewPoint(WatcherEyeLocation, WatcherEyeRotation);
        FVector BoundsOrigin;
        FVector BoundsExtent;
        WatcherPawn->GetActorBounds(false, BoundsOrigin, BoundsExtent, true);

        const FVector GazeSampleLocations[] =
        {
            WatcherEyeLocation,
            BoundsOrigin + FVector(0.0, 0.0, BoundsExtent.Z * 0.55),
            BoundsOrigin,
            BoundsOrigin - FVector(0.0, 0.0, BoundsExtent.Z * 0.45)
        };

        FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(JMWatcherGaze), false);
        TraceParams.AddIgnoredActor(PlayerPawn);
        TArray<AActor*> PlayerAttachedActors;
        PlayerPawn->GetAttachedActors(PlayerAttachedActors, true, true);
        TraceParams.AddIgnoredActors(PlayerAttachedActors);

        for (const FVector& SampleLocation : GazeSampleLocations)
        {
            const FVector LocalDirection = CameraRotation.UnrotateVector(SampleLocation - CameraLocation);
            if (LocalDirection.X <= UE_KINDA_SMALL_NUMBER)
            {
                continue;
            }

            const float HorizontalAngle = FMath::Abs(FMath::Atan2(LocalDirection.Y, LocalDirection.X));
            const float VerticalAngle = FMath::Abs(FMath::Atan2(
                LocalDirection.Z,
                FMath::Sqrt(FMath::Square(LocalDirection.X) + FMath::Square(LocalDirection.Y))));
            if (HorizontalAngle > HorizontalHalfFOV * ScreenFraction
                || VerticalAngle > VerticalHalfFOV * ScreenFraction)
            {
                continue;
            }

            bScreenPassed = true;
            FHitResult Hit;
            const bool bBlocked = World->LineTraceSingleByChannel(
                Hit,
                CameraLocation,
                SampleLocation,
                ECC_Visibility,
                TraceParams);
            AActor* HitActor = Hit.GetActor();
            BlockingActorName = GetNameSafe(HitActor);
            bVisibilityPassed = !bBlocked
                || HitActor == WatcherPawn
                || (IsValid(HitActor) && HitActor->IsAttachedTo(WatcherPawn));
            if (bVisibilityPassed)
            {
                break;
            }
        }
    }

    const bool bWasWatched = bPlayerIsWatchingWatcher;
    const bool bRawWatched = bScreenPassed && bVisibilityPassed;
    if (bRawWatched)
    {
        GazeLostElapsedTime = 0.0f;
        bPlayerIsWatchingWatcher = true;
    }
    else if (bPlayerIsWatchingWatcher
        && GazeLostElapsedTime + FMath::Max(DeltaSeconds, 0.0f) < GazeLostGraceDuration)
    {
        GazeLostElapsedTime += FMath::Max(DeltaSeconds, 0.0f);
    }
    else
    {
        GazeLostElapsedTime = 0.0f;
        bPlayerIsWatchingWatcher = false;
    }

    if (bWasWatched != bPlayerIsWatchingWatcher)
    {
        UE_LOG(
            LogJMMonsterFramework,
            Log,
            TEXT("[JM WATCHER GAZE] Enemy=%s Watched=%d Screen=%d Visible=%d Blocker=%s"),
            *GetNameSafe(WatcherPawn),
            bPlayerIsWatchingWatcher,
            bScreenPassed,
            bVisibilityPassed,
            *BlockingActorName);
    }
}
