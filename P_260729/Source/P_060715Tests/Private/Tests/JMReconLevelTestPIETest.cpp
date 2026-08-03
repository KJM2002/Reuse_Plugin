#include "Misc/AutomationTest.h"

#include "Components/JMDoorReconTargetAdapterComponent.h"
#include "Components/JMInteractionComponent.h"
#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconPlayerBridgeComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Door/JMDoorComponent.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Movement/JMDoorMovementComponent.h"
#include "Tests/AutomationEditorCommon.h"

namespace
{
    UWorld* FindPIEWorld()
    {
        if (!GEngine)
        {
            return nullptr;
        }
        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            if (Context.WorldType == EWorldType::PIE)
            {
                return Context.World();
            }
        }
        return nullptr;
    }
}

class FJMReconVerifyLevelTestPIECommand final : public IAutomationLatentCommand
{
public:
    explicit FJMReconVerifyLevelTestPIECommand(FAutomationTestBase* InTest)
        : Test(InTest)
        , StartedAt(FPlatformTime::Seconds())
    {
    }

    virtual bool Update() override
    {
        UWorld* World = FindPIEWorld();
        if (!World)
        {
            return FPlatformTime::Seconds() - StartedAt > 10.0;
        }

        if (!Target.IsValid() || !Player.IsValid())
        {
            for (TActorIterator<AActor> It(World); It; ++It)
            {
                AActor* Actor = *It;
                if (!Target.IsValid() &&
                    (Actor->GetName().Contains(TEXT("BP_JMRotatingDoorExample2")) ||
                     Actor->GetActorLabel() == TEXT("BP_JMRotatingDoorExample2")))
                {
                    Target = Actor->FindComponentByClass<UJMReconTargetComponent>();
                    Adapter = Actor->FindComponentByClass<UJMDoorReconTargetAdapterComponent>();
                    Door = Actor->FindComponentByClass<UJMDoorComponent>();
                }
                if (APawn* Pawn = Cast<APawn>(Actor);
                    Pawn &&
                    Pawn->FindComponentByClass<UJMInteractionComponent>() &&
                    Pawn->FindComponentByClass<UJMReconInteractorComponent>())
                {
                    Player = Pawn;
                    Bridge = Pawn->FindComponentByClass<UJMReconPlayerBridgeComponent>();
                    Interactor = Pawn->FindComponentByClass<UJMReconInteractorComponent>();
                    Interaction = Pawn->FindComponentByClass<UJMInteractionComponent>();
                }
            }
        }

        if (!Target.IsValid() || !Player.IsValid() || !Bridge.IsValid() ||
            !Interactor.IsValid() || !Interaction.IsValid() ||
            !Adapter.IsValid() || !Door.IsValid())
        {
            if (FPlatformTime::Seconds() - StartedAt <= 10.0)
            {
                return false;
            }
            Test->AddError(FString::Printf(
                TEXT("Level_test PIE setup incomplete: target=%d player=%d bridge=%d interactor=%d interaction=%d adapter=%d door=%d"),
                Target.IsValid(),
                Player.IsValid(),
                Bridge.IsValid(),
                Interactor.IsValid(),
                Interaction.IsValid(),
                Adapter.IsValid(),
                Door.IsValid()));
            return true;
        }

        if (!bStartRequested)
        {
            OriginalDoorPose = Door->MovementComponent->GetMovingComponent()->GetRelativeTransform();
            OriginalPlayerPose = Target->GetPlayerWorldTransform();
            OriginalPlayerPose.AddToTranslation(
                OriginalPlayerPose.GetRotation().RotateVector(FVector(-50.0f, 0.0f, 0.0f)));
            Player->SetActorTransform(OriginalPlayerPose);
            const FJMReconRequestResult Result = Bridge->TryStartReconWithTarget(Target.Get());
            Test->TestTrue(TEXT("Level_test door starts Recon through the runtime Bridge"), Result.bSucceeded);
            if (!Result.bSucceeded)
            {
                return true;
            }
            bStartRequested = true;
            return false;
        }

        if (!bFinishRequested && Interactor->GetCurrentState() == EJMReconState::Peeking)
        {
            APlayerController* PlayerController =
                Cast<APlayerController>(Player->GetController());
            if (!bLookApplied)
            {
                Test->TestNotNull(TEXT("Level_test player has a PlayerController"), PlayerController);
                if (!PlayerController)
                {
                    return true;
                }
                OriginalControlRotation = PlayerController->GetControlRotation();
                FRotator ReconLookRotation = OriginalControlRotation;
                ReconLookRotation.Yaw += 25.0f;
                PlayerController->SetControlRotation(ReconLookRotation);
                bLookApplied = true;
                return false;
            }

            Test->TestTrue(TEXT("Level_test enters direct Peeking"), Adapter->IsTemporaryPoseActive());
            Test->TestFalse(
                TEXT("Level_test moves the player from the pre-Recon interaction position"),
                Player->GetActorTransform().Equals(OriginalPlayerPose, 1.0f));
            Test->TestFalse(
                TEXT("Level_test applies the session-only door crack pose"),
                Door->MovementComponent->GetMovingComponent()->GetRelativeTransform().Equals(OriginalDoorPose));
            Test->TestTrue(TEXT("Level_test normal R/Esc-style exit succeeds"), Interactor->FinishRecon().bSucceeded);
            Test->TestTrue(
                TEXT("Exit blend starts with the original ControlRotation already restored"),
                PlayerController &&
                PlayerController->GetControlRotation().Equals(OriginalControlRotation, 0.01f));
            bFinishRequested = true;
            return false;
        }

        if (bFinishRequested && Interactor->GetCurrentState() == EJMReconState::Idle &&
            !Adapter->IsTemporaryPoseActive())
        {
            Test->TestTrue(
                TEXT("Level_test restores the exact original door pose"),
                Door->MovementComponent->GetMovingComponent()->GetRelativeTransform().Equals(OriginalDoorPose));
            Test->TestTrue(
                TEXT("Level_test restores the player's exact pre-Recon transform"),
                Player->GetActorTransform().Equals(OriginalPlayerPose));
            Player->AddActorWorldOffset(FVector(10000.0f, 0.0f, 0.0f));
            Interaction->RefreshCurrentInteractable();
            Test->TestFalse(
                TEXT("Leaving Recon does not leave the normal interaction prompt suppressed"),
                Interaction->IsPromptSuppressed());
            return true;
        }

        if (FPlatformTime::Seconds() - StartedAt > 15.0)
        {
            Test->AddError(FString::Printf(
                TEXT("Level_test Recon PIE flow timed out: state=%d start=%d finish=%d pose=%d"),
                static_cast<int32>(Interactor->GetCurrentState()),
                bStartRequested,
                bFinishRequested,
                Adapter->IsTemporaryPoseActive()));
            return true;
        }
        return false;
    }

private:
    FAutomationTestBase* Test = nullptr;
    double StartedAt = 0.0;
    bool bStartRequested = false;
    bool bFinishRequested = false;
    bool bLookApplied = false;
    FTransform OriginalDoorPose = FTransform::Identity;
    FTransform OriginalPlayerPose = FTransform::Identity;
    FRotator OriginalControlRotation = FRotator::ZeroRotator;
    TWeakObjectPtr<APawn> Player;
    TWeakObjectPtr<UJMReconTargetComponent> Target;
    TWeakObjectPtr<UJMReconPlayerBridgeComponent> Bridge;
    TWeakObjectPtr<UJMReconInteractorComponent> Interactor;
    TWeakObjectPtr<UJMInteractionComponent> Interaction;
    TWeakObjectPtr<UJMDoorReconTargetAdapterComponent> Adapter;
    TWeakObjectPtr<UJMDoorComponent> Door;
};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconLevelTestPIETest,
    "JM.Recon.Project.LevelTestPIE",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconLevelTestPIETest::RunTest(const FString& Parameters)
{
    FAutomationEditorCommonUtils::LoadMap(TEXT("/Game/Level/Level_test"));
    ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
    ADD_LATENT_AUTOMATION_COMMAND(FJMReconVerifyLevelTestPIECommand(this));
    ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
    return true;
}
