#include "Misc/AutomationTest.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideInteractorComponent.h"
#include "Components/JMHideInteractableAdapterComponent.h"
#include "Components/JMHideSimplePanelMechanismComponent.h"
#include "Components/JMHideSpotComponent.h"
#include "Components/JMInteractionComponent.h"
#include "Components/SpotLightComponent.h"
#include "Engine/GameViewportClient.h"
#include "EngineUtils.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "GenericPlatform/GenericPlatformInputDeviceMapper.h"
#include "InputCoreTypes.h"
#include "InputKeyEventArgs.h"
#include "JMHideReadyActors.h"
#include "Interfaces/JMInteractableInterface.h"
#include "Tests/AutomationEditorCommon.h"

namespace
{
    bool SendViewportKey(UWorld* World, APlayerController* Controller, const FKey Key)
    {
        if (!FApp::CanEverRender() || !World || !Controller)
        {
            return false;
        }
        UGameViewportClient* ViewportClient = World->GetGameViewport();
        if (!ViewportClient || !ViewportClient->Viewport)
        {
            return false;
        }
        const FInputDeviceId DeviceId =
            IPlatformInputDeviceMapper::Get().GetPrimaryInputDeviceForUser(
                Controller->GetPlatformUserId());
        ViewportClient->InputKey(FInputKeyEventArgs(
            ViewportClient->Viewport, DeviceId, Key, IE_Pressed,
            FPlatformTime::Cycles64()));
        ViewportClient->InputKey(FInputKeyEventArgs(
            ViewportClient->Viewport, DeviceId, Key, IE_Released,
            FPlatformTime::Cycles64()));
        return true;
    }

    UWorld* FindHidePIEWorld()
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

    bool InvokeExitInput(UWorld* World, APlayerController* Controller,
        UJMInteractionComponent* Interaction, bool& bOutUsedRenderedViewport)
    {
        bOutUsedRenderedViewport = false;
        if (!Interaction)
        {
            return false;
        }
        if (FApp::CanEverRender() && World && Controller)
        {
            if (SendViewportKey(World, Controller, EKeys::E))
            {
                bOutUsedRenderedViewport = true;
                // InputKey's return value reports viewport consumption, not whether a
                // legacy Blueprint key event ran. The latent state assertions below
                // verify that the hide session actually exited.
                return true;
            }
        }
        return Interaction->TryBeginInteraction().bSucceeded;
    }

    bool EnterThroughAdapter(ACharacter* Player, AActor* HideActor)
    {
        UJMHideInteractableAdapterComponent* Adapter =
            HideActor ? HideActor->FindComponentByClass<UJMHideInteractableAdapterComponent>() : nullptr;
        if (!Adapter)
        {
            return false;
        }
        FJMInteractionContext Context;
        Context.InstigatorActor = Player;
        Context.InstigatorController = Player ? Player->GetController() : nullptr;
        Context.TargetActor = HideActor;
        return IJMInteractableInterface::Execute_CompleteInteract(Adapter, Context).bSucceeded;
    }

    void ClearInteractionTrace(UJMInteractionComponent* Interaction)
    {
        Interaction->RefreshCurrentInteractableFromTrace(
            FVector(500000.0, 500000.0, 500000.0), FVector::UpVector);
    }

    void AimAt(ACharacter* Character, APlayerController* Controller, const FVector& Target)
    {
        Character->SetActorLocation(Target + FVector(0.0, 300.0, 30.0), false, nullptr,
            ETeleportType::TeleportPhysics);
        FVector ViewLocation;
        FRotator ViewRotation;
        Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
        const FRotator Aim = (Target - ViewLocation).Rotation();
        Character->SetActorRotation(FRotator(0.0, Aim.Yaw, 0.0));
        Controller->SetControlRotation(Aim);
    }

    void AimHiddenViewAway(APlayerController* Controller)
    {
        if (AActor* ViewTarget = Controller ? Controller->GetViewTarget() : nullptr)
        {
            ViewTarget->SetActorRotation(FRotator(-90.0, 0.0, 0.0));
        }
        if (Controller)
        {
            Controller->SetControlRotation(FRotator(-90.0, 0.0, 0.0));
        }
    }
}

class FJMHideGameplayPIECommand final : public IAutomationLatentCommand
{
public:
    explicit FJMHideGameplayPIECommand(FAutomationTestBase* InTest)
        : Test(InTest), StartedAt(FPlatformTime::Seconds())
    {
    }

    virtual bool Update() override
    {
        UWorld* World = FindHidePIEWorld();
        if (!World)
        {
            return TimedOut(TEXT("PIE world did not start."));
        }

        if (!Player.IsValid())
        {
            for (TActorIterator<ACharacter> It(World); It; ++It)
            {
                if (UJMInteractionComponent* Found =
                    It->FindComponentByClass<UJMInteractionComponent>())
                {
                    Player = *It;
                    Interaction = Found;
                    Controller = Cast<APlayerController>(It->GetController());
                    break;
                }
            }
            if (!Player.IsValid() || !Interaction.IsValid() || !Controller.IsValid())
            {
                return TimedOut(TEXT("Actual PIE player or JMInteraction component was not found."));
            }
        }

        switch (Step)
        {
        case 0:
        {
            if (!Player->InputComponent || World->GetTimeSeconds() < 1.0f)
            {
                return TimedOut(TEXT("PIE player input stack did not initialize."));
            }
            Bed = World->SpawnActor<AJMHideBedActor>(FVector(10000.0, 0.0, 10000.0),
                FRotator::ZeroRotator);
            Configure(Bed.Get());
            Bed->HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.35f;
            Bed->HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.35f;
            Bed->HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.25f;
            const FVector BedTarget = Bed->BedMesh->Bounds.Origin;
            AimAt(Player.Get(), Controller.Get(), BedTarget);
            Test->TestTrue(TEXT("Bed adapter enters with the actual PIE character"),
                EnterThroughAdapter(Player.Get(), Bed.Get()));
            Test->TestTrue(TEXT("Bed fade keeps the player at EntryAnchor before blackout midpoint"),
                Player->GetActorTransform().Equals(
                    Bed->EntryAnchor->GetComponentTransform(), 1.0f));
            Test->TestFalse(TEXT("Bed does not immediately teleport through the mesh"),
                Player->GetActorTransform().Equals(
                    Bed->OccupantAnchor->GetComponentTransform(), 1.0f));
            ++Step;
            return false;
        }

        case 1:
        {
            if (!IsHiddenAt(Bed->HideSpot))
            {
                return TimedOut(TEXT("Bed did not reach Hidden from the actual BP input entry point."));
            }
            AimHiddenViewAway(Controller.Get());
            ClearInteractionTrace(Interaction.Get());
            Test->TestNull(TEXT("Bed exit test has no traced target"),
                Interaction->GetCurrentInteractableObject());
            bool bUsedRenderedViewport = false;
            Test->TestTrue(TEXT("Bed hidden exit input is handled"),
                InvokeExitInput(World, Controller.Get(), Interaction.Get(),
                    bUsedRenderedViewport));
            bRenderedViewportInputUsed |= bUsedRenderedViewport;
            ++Step;
            return false;
        }

        case 2:
        {
            if (HasActiveSession())
            {
                return TimedOut(TEXT("Bed did not return to Idle from the actual BP input entry point."));
            }
            Test->TestEqual(TEXT("Bed returns Available"),
                Bed->HideSpot->GetSpotState(), EJMHideSpotState::Available);
            Bed->Destroy();
            for (TActorIterator<AJMHideLockerActor> It(World); It; ++It)
            {
                if (It->ActorHasTag(TEXT("JM.Hide.Locker")))
                {
                    Locker = *It;
                    break;
                }
            }
            if (!Locker.IsValid())
            {
                Locker = World->SpawnActor<AJMHideLockerActor>(
                    FVector(20000.0, 0.0, 10000.0), FRotator::ZeroRotator);
            }
            Test->TestNotNull(TEXT("Level_test provides the placed locker"), Locker.Get());
            Configure(Locker.Get());
            Locker->HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.25f;
            Locker->HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.25f;
            Locker->HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.2f;
            PivotLocation = Locker->DoorPivot->GetRelativeLocation();
            PivotScale = Locker->DoorPivot->GetRelativeScale3D();
            DoorTransform = Locker->LockerDoor->GetRelativeTransform();
            RepeatIndex = 0;
            BeginLockerEnter();
            ++Step;
            return false;
        }

        case 3:
        {
            if (!IsHiddenAt(Locker->HideSpot))
            {
                return TimedOut(TEXT("Locker did not reach Hidden from the actual BP input entry point."));
            }
            VerifyDoorInvariants(TEXT("hidden"));
            Test->TestFalse(
                TEXT("Locker keeps the first-person actor visible for owned input visuals"),
                Player->IsHidden());
            if (!FApp::CanEverRender())
            {
                bFlashlightInputSent = true;
                bFlashlightChecked = true;
            }
            if (!bFlashlightInputSent)
            {
                Flashlight = Player->FindComponentByClass<USpotLightComponent>();
                Test->TestNotNull(TEXT("Actual player has the Blueprint flashlight"),
                    Flashlight.Get());
                if (!Flashlight.IsValid())
                {
                    return true;
                }
                bFlashlightWasVisible = Flashlight->IsVisible();
                Test->TestTrue(TEXT("Rendered PIE sends the actual F flashlight input"),
                    SendViewportKey(World, Controller.Get(), EKeys::F));
                bFlashlightInputSent = true;
                return false;
            }
            if (!bFlashlightChecked)
            {
                Test->TestNotEqual(TEXT("Flashlight remains operable while hidden"),
                    Flashlight->IsVisible(), bFlashlightWasVisible);
                bFlashlightChecked = true;
            }
            if (!bLockerLookApplied)
            {
                LockerLookBase = Locker->CameraAnchor->GetComponentRotation();
                FRotator BeyondLimit = LockerLookBase;
                BeyondLimit.Yaw += 120.0f;
                BeyondLimit.Pitch += 80.0f;
                Controller->SetControlRotation(BeyondLimit);
                bLockerLookApplied = true;
                return false;
            }
            const FRotator LimitedView = Controller->GetViewTarget()->GetActorRotation();
            Test->TestEqual(TEXT("Locker look clamps yaw to configured limit"),
                FMath::Abs(FMath::FindDeltaAngleDegrees(
                    LockerLookBase.Yaw, LimitedView.Yaw)), 55.0, 0.25);
            Test->TestEqual(TEXT("Locker look clamps pitch to configured limit"),
                FMath::Abs(FMath::FindDeltaAngleDegrees(
                    LockerLookBase.Pitch, LimitedView.Pitch)), 30.0, 0.25);
            AimHiddenViewAway(Controller.Get());
            ClearInteractionTrace(Interaction.Get());
            Test->TestNull(TEXT("Locker exit test has no traced target"),
                Interaction->GetCurrentInteractableObject());
            bool bUsedRenderedViewport = false;
            Test->TestTrue(TEXT("Locker hidden exit input is handled"),
                InvokeExitInput(World, Controller.Get(), Interaction.Get(),
                    bUsedRenderedViewport));
            bRenderedViewportInputUsed |= bUsedRenderedViewport;
            ++Step;
            return false;
        }

        case 4:
        {
            if (HasActiveSession())
            {
                return TimedOut(TEXT("Locker did not return to Idle from the actual BP input entry point."));
            }
            VerifyDoorInvariants(TEXT("idle"));
            Test->TestEqual(TEXT("Locker returns Available"),
                Locker->HideSpot->GetSpotState(), EJMHideSpotState::Available);
            Test->TestTrue(TEXT("Locker exit restores pre-hide control rotation"),
                Controller->GetControlRotation().Equals(PreHideControlRotation, 0.25f));
            ++RepeatIndex;
            if (RepeatIndex < 3)
            {
                bLockerLookApplied = false;
                BeginLockerEnter();
                Step = 3;
                return false;
            }
            if (FApp::CanEverRender())
            {
                Test->TestTrue(TEXT("Rendered PIE used GameViewport E input"),
                    bRenderedViewportInputUsed);
            }
            Locker->Destroy();
            return true;
        }
        default:
            return true;
        }
    }

private:
    template <typename TActor>
    void Configure(TActor* Actor)
    {
        Actor->HideSpot->InstanceConfigOverride.bOverride = true;
        Actor->HideSpot->InstanceConfigOverride.Values.EnterDuration = 0.0f;
        Actor->HideSpot->InstanceConfigOverride.Values.ExitDuration = 0.0f;
        Actor->HideSpot->InstanceConfigOverride.Values.CameraBlendDuration = 0.0f;
        if (UJMHideSimplePanelMechanismComponent* Panel =
            Actor->FindComponentByClass<UJMHideSimplePanelMechanismComponent>())
        {
            Panel->Duration = 0.0f;
            Panel->Delay = 0.0f;
        }
    }

    void BeginLockerEnter()
    {
        const FVector LockerTarget = Locker->LockerDoor->Bounds.Origin;
        AimAt(Player.Get(), Controller.Get(), LockerTarget);
        PreHideControlRotation = Controller->GetControlRotation();
        Test->TestTrue(TEXT("Locker adapter enters with the actual PIE character"),
            EnterThroughAdapter(Player.Get(), Locker.Get()));
        Test->TestTrue(TEXT("Locker blend does not snap control rotation on entry"),
            Controller->GetControlRotation().Equals(PreHideControlRotation, 0.25f));
    }

    bool IsHiddenAt(const UJMHideSpotComponent* Spot)
    {
        UJMHideInteractorComponent* Hide =
            Player->FindComponentByClass<UJMHideInteractorComponent>();
        return Hide && Hide->IsHidden() && Hide->GetCurrentHideSpot() == Spot;
    }

    bool HasActiveSession()
    {
        UJMHideInteractorComponent* Hide =
            Player->FindComponentByClass<UJMHideInteractorComponent>();
        return Hide && Hide->HasActiveSession();
    }

    void VerifyDoorInvariants(const TCHAR* State)
    {
        Test->TestTrue(FString::Printf(TEXT("DoorPivot location invariant at %s"), State),
            Locker->DoorPivot->GetRelativeLocation().Equals(PivotLocation));
        Test->TestTrue(FString::Printf(TEXT("DoorPivot scale invariant at %s"), State),
            Locker->DoorPivot->GetRelativeScale3D().Equals(PivotScale));
        Test->TestTrue(FString::Printf(TEXT("DoorMesh transform invariant at %s"), State),
            Locker->LockerDoor->GetRelativeTransform().Equals(DoorTransform));
    }

    bool TimedOut(const TCHAR* Message)
    {
        if (FPlatformTime::Seconds() - StartedAt <= 15.0)
        {
            return false;
        }
        Test->AddError(Message);
        return true;
    }

    FAutomationTestBase* Test = nullptr;
    double StartedAt = 0.0;
    int32 Step = 0;
    int32 RepeatIndex = 0;
    bool bLockerLookApplied = false;
    bool bFlashlightInputSent = false;
    bool bFlashlightChecked = false;
    bool bFlashlightWasVisible = false;
    bool bRenderedViewportInputUsed = false;
    FRotator LockerLookBase = FRotator::ZeroRotator;
    FRotator PreHideControlRotation = FRotator::ZeroRotator;
    TWeakObjectPtr<ACharacter> Player;
    TWeakObjectPtr<APlayerController> Controller;
    TWeakObjectPtr<UJMInteractionComponent> Interaction;
    TWeakObjectPtr<USpotLightComponent> Flashlight;
    TWeakObjectPtr<AJMHideBedActor> Bed;
    TWeakObjectPtr<AJMHideLockerActor> Locker;
    FVector PivotLocation = FVector::ZeroVector;
    FVector PivotScale = FVector::OneVector;
    FTransform DoorTransform = FTransform::Identity;
};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMHideGameplayPIETest,
    "JM.Hide.Project.RuntimeLogicPIE.ActualCharacterInputEntryPoint",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMHideGameplayPIETest::RunTest(const FString&)
{
    FAutomationEditorCommonUtils::LoadMap(TEXT("/Game/Level/Level_test"));
    ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
    ADD_LATENT_AUTOMATION_COMMAND(FJMHideGameplayPIECommand(this));
    ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
    return true;
}
