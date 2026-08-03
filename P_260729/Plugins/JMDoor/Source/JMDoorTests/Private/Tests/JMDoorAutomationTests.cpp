#include "Misc/AutomationTest.h"

#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Data/JMDoorConfigData.h"
#include "Door/JMDoorTypes.h"
#include "Door/JMDoorTags.h"
#include "Movement/JMRotatingDoorMovementComponent.h"
#include "Movement/JMSlidingDoorMovementComponent.h"
#include "Door/JMDoorComponent.h"
#include "Movement/JMDoorMovementComponent.h"
#include "UObject/UnrealType.h"
#include "Actors/JMDoorActor.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"
#include "Tests/AutomationEditorCommon.h"
#include "Tests/JMDoorTestEventReceiver.h"

#if WITH_DEV_AUTOMATION_TESTS

namespace
{
    struct FJMDoorPushScenarioResult
    {
        FVector TotalMovement = FVector::ZeroVector;
        int32 MovingFrameCount = 0;
        int32 GapsAfterContact = 0;
        float LargestFrameMove = 0.0f;
        EJMDoorState FinalDoorState = EJMDoorState::Closed;
        float ExtraMovementAfterStop = 0.0f;
    };

    template <typename TComponent>
    TComponent* JMAddRuntimeComponent(AActor* Owner)
    {
        TComponent* Component = NewObject<TComponent>(Owner);
        Owner->AddInstanceComponent(Component);
        Component->RegisterComponent();
        return Component;
    }

    FJMDoorPushScenarioResult JMRunPushScenario(UWorld* World, bool bRotating, float DeltaTime, bool bAddWall)
    {
        FJMDoorPushScenarioResult Result;
        if (!World)
        {
            return Result;
        }

        AActor* DoorOwner = World->SpawnActor<AActor>();
        USceneComponent* Root = JMAddRuntimeComponent<USceneComponent>(DoorOwner);
        DoorOwner->SetRootComponent(Root);
        Root->SetWorldLocation(FVector(0.0f, 0.0f, 100.0f));

        USceneComponent* Hinge = JMAddRuntimeComponent<USceneComponent>(DoorOwner);
        Hinge->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);

        UBoxComponent* Leaf = JMAddRuntimeComponent<UBoxComponent>(DoorOwner);
        Leaf->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
        Leaf->SetGenerateOverlapEvents(true);

        UJMDoorMovementComponent* Movement = nullptr;
        if (bRotating)
        {
            UJMRotatingDoorMovementComponent* Rotating = JMAddRuntimeComponent<UJMRotatingDoorMovementComponent>(DoorOwner);
            Rotating->OpenAngle = 90.0f;
            Leaf->SetBoxExtent(FVector(50.0f, 5.0f, 100.0f));
            Leaf->AttachToComponent(Hinge, FAttachmentTransformRules::KeepRelativeTransform);
            Leaf->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
            Rotating->InitializeMovingComponent(Hinge);
            Rotating->SetCollisionComponent(Leaf);
            Movement = Rotating;
        }
        else
        {
            UJMSlidingDoorMovementComponent* Sliding = JMAddRuntimeComponent<UJMSlidingDoorMovementComponent>(DoorOwner);
            Sliding->LocalOpenOffset = FVector(100.0f, 0.0f, 0.0f);
            Sliding->DoorAOpenOffset = FVector(100.0f, 0.0f, 0.0f);
            Sliding->bReverseOffsetWithDirection = false;
            Leaf->SetBoxExtent(FVector(5.0f, 100.0f, 100.0f));
            Leaf->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
            Leaf->SetRelativeLocation(FVector::ZeroVector);
            Sliding->InitializeMovingComponent(Leaf);
            Sliding->SetCollisionComponent(Leaf);
            Movement = Sliding;
        }
        Leaf->UpdateOverlaps();

        UJMDoorConfigData* Config = NewObject<UJMDoorConfigData>(DoorOwner);
        Config->OpenDuration = 1.0f;
        Config->CloseDuration = 1.0f;
        Config->bDetectObstructions = true;
        Config->BlockBehavior = EJMDoorBlockBehavior::Stop;
        Config->bPushCharacters = true;
        Config->CharacterPushMaxSubstepDistance = 4.0f;
        Config->CharacterPushMaxSubstepAngle = 1.5f;

        UJMDoorComponent* Door = JMAddRuntimeComponent<UJMDoorComponent>(DoorOwner);
        Door->Config = Config;
        Door->SetMovementComponent(Movement);

        FJMDoorSaveData OpenState;
        OpenState.State = EJMDoorState::Open;
        OpenState.OpenFraction = 1.0f;
        Door->RestoreSaveData(OpenState);

        ACharacter* Character = World->SpawnActor<ACharacter>();
        Character->GetCharacterMovement()->SetMovementMode(MOVE_Flying);
        Character->GetCharacterMovement()->GravityScale = 0.0f;
        Character->SetActorLocation(bRotating ? FVector(53.0f, 53.0f, 100.0f) : FVector(50.0f, 0.0f, 100.0f), false);
        Character->GetCapsuleComponent()->UpdateOverlaps();

        AActor* WallOwner = nullptr;
        if (bAddWall)
        {
            WallOwner = World->SpawnActor<AActor>();
            UBoxComponent* Wall = JMAddRuntimeComponent<UBoxComponent>(WallOwner);
            WallOwner->SetRootComponent(Wall);
            Wall->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
            Wall->SetBoxExtent(FVector(5.0f, 150.0f, 150.0f));
            Wall->SetWorldLocation(FVector(-20.0f, 0.0f, 100.0f));
            Wall->UpdateOverlaps();
        }

        const FVector CharacterStart = Character->GetActorLocation();
        FJMDoorUseContext Context;
        Door->CloseDoor(Context);
        bool bContactStarted = false;
        const int32 MaxFrames = FMath::CeilToInt(2.0f / DeltaTime);
        for (int32 FrameIndex = 0; FrameIndex < MaxFrames && Door->GetState() == EJMDoorState::Closing; ++FrameIndex)
        {
            const FVector Before = Character->GetActorLocation();
            Door->TickComponent(DeltaTime, LEVELTICK_All, nullptr);
            const float FrameMove = FVector::Distance(Before, Character->GetActorLocation());
            Result.LargestFrameMove = FMath::Max(Result.LargestFrameMove, FrameMove);
            if (FrameMove > 0.05f)
            {
                bContactStarted = true;
                ++Result.MovingFrameCount;
            }
            else if (bContactStarted && Door->GetState() == EJMDoorState::Closing)
            {
                ++Result.GapsAfterContact;
            }
        }

        Result.TotalMovement = Character->GetActorLocation() - CharacterStart;
        Result.FinalDoorState = Door->GetState();
        const FVector StopLocation = Character->GetActorLocation();
        for (int32 Index = 0; Index < 5; ++Index)
        {
            Door->TickComponent(DeltaTime, LEVELTICK_All, nullptr);
        }
        Result.ExtraMovementAfterStop = FVector::Distance(StopLocation, Character->GetActorLocation());

        World->DestroyActor(Character);
        if (WallOwner)
        {
            World->DestroyActor(WallOwner);
        }
        World->DestroyActor(DoorOwner);
        return Result;
    }
}

DEFINE_LATENT_AUTOMATION_COMMAND_ONE_PARAMETER(FJMDoorVerifyKinematicPushPIECommand, FAutomationTestBase*, Test);
bool FJMDoorVerifyKinematicPushPIECommand::Update()
{
    UWorld* PIEWorld = nullptr;
    if (GEngine)
    {
        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            if (Context.WorldType == EWorldType::PIE)
            {
                PIEWorld = Context.World();
                break;
            }
        }
    }
    if (!PIEWorld)
    {
        return false;
    }

    const FJMDoorPushScenarioResult Sliding = JMRunPushScenario(PIEWorld, false, 1.0f / 60.0f, false);
    const FJMDoorPushScenarioResult Rotating = JMRunPushScenario(PIEWorld, true, 1.0f / 60.0f, false);
    const FJMDoorPushScenarioResult WallBlocked = JMRunPushScenario(PIEWorld, false, 1.0f / 60.0f, true);
    Test->TestTrue(TEXT("PIE sliding door push is continuous"), Sliding.MovingFrameCount > 30 && Sliding.GapsAfterContact == 0);
    Test->TestTrue(TEXT("PIE rotating door push is continuous and tangential"), Rotating.MovingFrameCount > 30 && Rotating.GapsAfterContact == 0 && FMath::Abs(Rotating.TotalMovement.Y) > 5.0f);
    Test->TestTrue(TEXT("PIE wall blocks without repeated correction"), WallBlocked.FinalDoorState == EJMDoorState::Blocked && WallBlocked.ExtraMovementAfterStop < 0.01f);
    return true;
}

class FJMDoorVerifyDualPanelAutoClosePIECommand final : public IAutomationLatentCommand
{
public:
    explicit FJMDoorVerifyDualPanelAutoClosePIECommand(FAutomationTestBase* InTest)
        : Test(InTest)
    {
    }

    virtual bool Update() override
    {
        UWorld* PIEWorld = nullptr;
        if (GEngine)
        {
            for (const FWorldContext& Context : GEngine->GetWorldContexts())
            {
                if (Context.WorldType == EWorldType::PIE)
                {
                    PIEWorld = Context.World();
                    break;
                }
            }
        }
        if (!PIEWorld)
        {
            return false;
        }

        if (!Door.IsValid())
        {
            AJMSlidingDoorActor* SpawnedDoor = PIEWorld->SpawnActor<AJMSlidingDoorActor>();
            if (!SpawnedDoor)
            {
                Test->AddError(TEXT("Could not spawn a dual sliding door in PIE."));
                return true;
            }

            SpawnedDoor->DoorLeafMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            SpawnedDoor->DoorLeafMeshB->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
            SpawnedDoor->DoorLeafMesh->SetStaticMesh(CubeMesh);
            SpawnedDoor->DoorLeafMeshB->SetStaticMesh(CubeMesh);
            UJMDoorConfigData* Config = NewObject<UJMDoorConfigData>(SpawnedDoor);
            Config->OpenDuration = 0.05f;
            Config->CloseDuration = 0.05f;
            Config->bAutoClose = true;
            Config->AutoCloseDelay = 0.1f;
            Config->bDetectObstructions = false;
            SpawnedDoor->DoorComponent->Config = Config;

            FJMDoorUseContext Context;
            const FJMDoorResult Result = SpawnedDoor->OpenSlideDoor(EJMSlideDoorPanel::DoorA, Context);
            Test->TestTrue(TEXT("PIE panel A open starts for auto-close verification"), Result.bSucceeded);
            Door = SpawnedDoor;
            StartTime = PIEWorld->GetTimeSeconds();
            return !Result.bSucceeded;
        }

        AJMSlidingDoorActor* SlidingDoor = Door.Get();
        const EJMDoorState AState = SlidingDoor->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA);
        const EJMDoorState BState = SlidingDoor->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB);
        bObservedOpen |= AState == EJMDoorState::Open;
        if (bObservedOpen && AState == EJMDoorState::Closed)
        {
            Test->TestEqual(TEXT("PIE auto-close leaves unopened panel B closed"), BState, EJMDoorState::Closed);
            PIEWorld->DestroyActor(SlidingDoor);
            return true;
        }

        if (PIEWorld->GetTimeSeconds() - StartTime > 3.0f)
        {
            Test->AddError(FString::Printf(TEXT("PIE dual-panel auto-close timed out (A=%d, B=%d, observedOpen=%d)."),
                static_cast<int32>(AState), static_cast<int32>(BState), bObservedOpen ? 1 : 0));
            PIEWorld->DestroyActor(SlidingDoor);
            return true;
        }
        return false;
    }

private:
    FAutomationTestBase* Test = nullptr;
    TWeakObjectPtr<AJMSlidingDoorActor> Door;
    float StartTime = 0.0f;
    bool bObservedOpen = false;
};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorAccessRequirementTest, "JM.Door.Access.RequirementMatching", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorAccessRequirementTest::RunTest(const FString& Parameters)
{
    const FGameplayTag KeyTag = TAG_JMDoor_Test_Key;
    const FGameplayTag CardTag = TAG_JMDoor_Test_Card;
    const FGameplayTag MasterTag = TAG_JMDoor_Access_Master;
    if (!KeyTag.IsValid() || !CardTag.IsValid() || !MasterTag.IsValid())
    {
        AddError(TEXT("JMDoor test Gameplay Tags were not registered."));
        return false;
    }

    FJMDoorAccessRequirement Requirement;
    Requirement.RequiredTags.AddTag(KeyTag);
    Requirement.RequiredTags.AddTag(CardTag);
    Requirement.MasterAccessTags.AddTag(MasterTag);

    FGameplayTagContainer Available;
    Available.AddTag(KeyTag);
    TestFalse(TEXT("AllRequired rejects a partial set"), Requirement.IsSatisfiedBy(Available));
    Available.AddTag(CardTag);
    TestTrue(TEXT("AllRequired accepts the complete set"), Requirement.IsSatisfiedBy(Available));

    FGameplayTagContainer MasterAccess;
    MasterAccess.AddTag(MasterTag);
    TestTrue(TEXT("Master access bypasses required tags"), Requirement.IsSatisfiedBy(MasterAccess));

    Requirement.MatchMode = EJMDoorAccessMatchMode::AnyRequired;
    Available.Reset();
    Available.AddTag(KeyTag);
    TestTrue(TEXT("AnyRequired accepts one tag"), Requirement.IsSatisfiedBy(Available));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorMovementMathTest, "JM.Door.Movement.Transforms", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorMovementMathTest::RunTest(const FString& Parameters)
{
    USceneComponent* MovingScene = NewObject<USceneComponent>();
    MovingScene->SetRelativeLocation(FVector(10.0f, 20.0f, 30.0f));

    UJMRotatingDoorMovementComponent* Rotation = NewObject<UJMRotatingDoorMovementComponent>();
    Rotation->InitializeMovingComponent(MovingScene);
    Rotation->OpenAngle = 90.0f;
    const FTransform Rotated = Rotation->GetRelativeTransformAtFraction(1.0f, 1);
    TestTrue(TEXT("Rotation preserves hinge location"), Rotated.GetLocation().Equals(FVector(10.0f, 20.0f, 30.0f)));
    TestTrue(TEXT("Rotation reaches configured angle"), FMath::IsNearlyEqual(Rotated.Rotator().Yaw, 90.0f, 0.1f));

    UJMSlidingDoorMovementComponent* Sliding = NewObject<UJMSlidingDoorMovementComponent>();
    Sliding->InitializeMovingComponent(MovingScene);
    Sliding->DoorAOpenOffset = FVector(0.0f, -200.0f, 0.0f);
    const FTransform Slid = Sliding->GetRelativeTransformAtFraction(0.5f, -1);
    TestTrue(TEXT("Sliding panel A applies its configured fraction"), Slid.GetLocation().Equals(FVector(10.0f, -80.0f, 30.0f), 0.1f));

    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    AJMRotatingDoorActor* Door = World ? World->SpawnActor<AJMRotatingDoorActor>() : nullptr;
    TestNotNull(TEXT("Native rotating door spawned"), Door);
    if (Door)
    {
        TestEqual(TEXT("Rotating movement targets the hinge root"), Door->RotatingMovement->GetMovingComponent(), static_cast<USceneComponent*>(Door->MovementRoot));
        TestEqual(TEXT("Door leaf is the obstruction primitive"), Door->RotatingMovement->GetCollisionComponent(), static_cast<UPrimitiveComponent*>(Door->DoorLeafMesh));

        UJMDoorConfigData* Config = NewObject<UJMDoorConfigData>(Door);
        Config->OpenDuration = 1.0f;
        Config->CloseDuration = 1.0f;
        Config->bAutoClose = false;
        Door->DoorComponent->Config = Config;

        UJMDoorTestEventReceiver* Receiver = NewObject<UJMDoorTestEventReceiver>();
        Door->DoorComponent->OnNoiseEmitted.AddUniqueDynamic(Receiver, &UJMDoorTestEventReceiver::HandleNoise);

        FJMDoorUseContext Context;
        Context.InteractionLocation = FVector(-200.0f, 0.0f, 0.0f);
        const FJMDoorResult OpenResult = Door->DoorComponent->OpenDoor(Context);
        TestTrue(TEXT("Opening command succeeds"), OpenResult.bSucceeded);
        TestEqual(TEXT("Door enters Opening immediately"), Door->DoorComponent->GetState(), EJMDoorState::Opening);
        TestEqual(TEXT("Open noise is emitted on the movement-start frame"), Receiver->NoiseCount, 1);
        TestEqual(TEXT("Immediate noise uses the open tag"), Receiver->LastNoiseTag, TAG_JMDoor_Noise_Open.GetTag());

        Door->DoorComponent->TickComponent(2.0f, LEVELTICK_All, nullptr);
        TestEqual(TEXT("Finishing movement does not replay open noise"), Receiver->NoiseCount, 1);

        const FJMDoorResult CloseResult = Door->DoorComponent->CloseDoor(Context);
        TestTrue(TEXT("Closing command succeeds"), CloseResult.bSucceeded);
        TestEqual(TEXT("Door enters Closing immediately"), Door->DoorComponent->GetState(), EJMDoorState::Closing);
        TestEqual(TEXT("Close noise is emitted on the movement-start frame"), Receiver->NoiseCount, 2);
        TestEqual(TEXT("Immediate noise uses the close tag"), Receiver->LastNoiseTag, TAG_JMDoor_Noise_Close.GetTag());
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorDualSlidingPanelTest, "JM.Door.Movement.DualSlidingPanels", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorDualSlidingPanelTest::RunTest(const FString& Parameters)
{
    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    AJMSlidingDoorActor* Door = World ? World->SpawnActor<AJMSlidingDoorActor>() : nullptr;
    TestNotNull(TEXT("Native dual sliding door spawned"), Door);
    if (!Door)
    {
        return false;
    }

    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    TestNotNull(TEXT("Engine cube mesh loaded for dual panel configuration"), CubeMesh);
    Door->DoorLeafMesh->SetStaticMesh(CubeMesh);
    Door->DoorLeafMeshB->SetStaticMesh(CubeMesh);
    Door->DoorLeafMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Door->DoorLeafMeshB->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Door->DoorLeafMesh->SetRelativeLocation(FVector(0.0f, -50.0f, 0.0f));
    Door->DoorLeafMeshB->SetRelativeLocation(FVector(0.0f, 50.0f, 0.0f));
    Door->SlidingMovement->InitializeMovingComponent(Door->DoorLeafMesh);
    Door->SlidingMovement->InitializeDoorBComponent(Door->DoorLeafMeshB, Door->DoorLeafMeshB);
    Door->SlidingMovement->DoorAOpenOffset = FVector(0.0f, -100.0f, 0.0f);
    Door->SlidingMovement->DoorBOpenOffset = FVector(0.0f, 100.0f, 0.0f);

    UJMDoorConfigData* Config = NewObject<UJMDoorConfigData>(Door);
    Config->OpenDuration = 1.0f;
    Config->CloseDuration = 1.0f;
    Config->bDetectObstructions = false;
    Config->SlideDoorPanelSelectionMode = EJMSlideDoorPanelSelectionMode::ConfiguredPanel;
    Config->SlideDoorOpenMode = EJMSlideDoorOpenMode::OpenDoorA;
    Door->DoorComponent->Config = Config;

    FJMDoorUseContext Context;
    Context.InteractionLocation = FVector(0.0f, 10000.0f, 0.0f);
    TestTrue(TEXT("Explicit panel A open succeeds"), Door->OpenSlideDoor(EJMSlideDoorPanel::DoorA, Context).bSucceeded);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Panel A reaches Open"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Open);
    TestEqual(TEXT("Panel B remains Closed"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Closed);
    TestTrue(TEXT("Panel A always moves actor-local left"), Door->DoorLeafMesh->GetRelativeLocation().Equals(FVector(0.0f, -150.0f, 0.0f), 0.1f));
    TestTrue(TEXT("Panel B did not move while A opened"), Door->DoorLeafMeshB->GetRelativeLocation().Equals(FVector(0.0f, 50.0f, 0.0f), 0.1f));

    TestTrue(TEXT("Panel B can open while A is already open"), Door->OpenSlideDoor(EJMSlideDoorPanel::DoorB, Context).bSucceeded);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Panel B reaches Open independently"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);
    TestTrue(TEXT("Panel B always moves actor-local right"), Door->DoorLeafMeshB->GetRelativeLocation().Equals(FVector(0.0f, 150.0f, 0.0f), 0.1f));

    TestTrue(TEXT("Panel A can close without affecting B"), Door->CloseSlideDoor(EJMSlideDoorPanel::DoorA, Context).bSucceeded);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Panel A is Closed"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Closed);
    TestEqual(TEXT("Panel B stays Open"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);

    TestTrue(TEXT("Panel B close starts"), Door->CloseSlideDoor(EJMSlideDoorPanel::DoorB, Context).bSucceeded);
    Door->DoorComponent->TickComponent(0.25f, LEVELTICK_All, nullptr);
    const float PartialCloseY = Door->DoorLeafMeshB->GetRelativeLocation().Y;
    TestTrue(TEXT("Opposite command reverses from the current position"), Door->OpenSlideDoor(EJMSlideDoorPanel::DoorB, Context).bSucceeded);
    TestTrue(TEXT("Reverse command does not teleport panel B"), FMath::IsNearlyEqual(Door->DoorLeafMeshB->GetRelativeLocation().Y, PartialCloseY, 0.01f));
    Door->DoorComponent->TickComponent(0.1f, LEVELTICK_All, nullptr);
    TestTrue(TEXT("Panel B resumes toward open after reversal"), Door->DoorLeafMeshB->GetRelativeLocation().Y > PartialCloseY);

    Door->CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    Door->DoorComponent->OpenDoor(Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Configured mode ignores approach side and opens A"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Open);
    TestEqual(TEXT("Configured A mode leaves B closed"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Closed);

    Door->CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    Config->SlideDoorOpenMode = EJMSlideDoorOpenMode::OpenDoorB;
    Door->DoorComponent->OpenDoor(Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Configured B mode leaves A closed"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Closed);
    TestEqual(TEXT("Configured B mode opens B regardless of approach"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);

    Door->CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    Config->SlideDoorPanelSelectionMode = EJMSlideDoorPanelSelectionMode::NearestPanel;
    Context.InteractionLocation = Door->SlidingMovement->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel::DoorB, 0.0f).GetLocation();
    Door->DoorComponent->OpenDoor(Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Nearest mode selects panel B"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);
    TestTrue(TEXT("Nearest selection does not reverse B direction"), Door->DoorLeafMeshB->GetRelativeLocation().Equals(FVector(0.0f, 150.0f, 0.0f), 0.1f));

    Door->CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    Config->SlideDoorPanelSelectionMode = EJMSlideDoorPanelSelectionMode::ConfiguredPanel;
    Config->SlideDoorOpenMode = EJMSlideDoorOpenMode::OpenBoth;
    Door->DoorComponent->OpenDoor(Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    TestEqual(TEXT("Both mode opens A"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Open);
    TestEqual(TEXT("Both mode opens B"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);

    Door->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
    const FVector AClosedWorld = Door->SlidingMovement->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel::DoorA, 0.0f).GetLocation();
    const FVector AOpenWorld = Door->SlidingMovement->GetPanelWorldTransformAtFraction(EJMSlideDoorPanel::DoorA, 1.0f).GetLocation();
    TestTrue(TEXT("Rotated actor still applies panel A offset in local space"), (AOpenWorld - AClosedWorld).Equals(FVector(100.0f, 0.0f, 0.0f), 0.2f));

    const FJMDoorSaveData Saved = Door->DoorComponent->CaptureSaveData();
    TestTrue(TEXT("Save data retains panel A progress"), Saved.SlideDoorAOpenFraction > 0.99f);
    TestTrue(TEXT("Save data retains panel B progress"), Saved.SlideDoorBOpenFraction > 0.99f);

    Door->CloseSlideDoor(EJMSlideDoorPanel::Both, Context);
    Door->DoorComponent->TickComponent(1.1f, LEVELTICK_All, nullptr);
    Config->bDetectObstructions = true;
    Config->BlockBehavior = EJMDoorBlockBehavior::Stop;
    Door->SetActorRotation(FRotator::ZeroRotator);
    UBoxComponent* PanelACollision = NewObject<UBoxComponent>(Door);
    Door->AddInstanceComponent(PanelACollision);
    PanelACollision->SetupAttachment(Door->DoorLeafMesh);
    PanelACollision->SetBoxExtent(FVector(5.0f, 20.0f, 50.0f));
    PanelACollision->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    PanelACollision->RegisterComponent();
    PanelACollision->UpdateOverlaps();
    UBoxComponent* PanelBCollision = NewObject<UBoxComponent>(Door);
    Door->AddInstanceComponent(PanelBCollision);
    PanelBCollision->SetupAttachment(Door->DoorLeafMeshB);
    PanelBCollision->SetBoxExtent(FVector(5.0f, 20.0f, 50.0f));
    PanelBCollision->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    PanelBCollision->RegisterComponent();
    PanelBCollision->UpdateOverlaps();
    Door->SlidingMovement->SetCollisionComponent(PanelACollision);
    Door->SlidingMovement->InitializeDoorBComponent(Door->DoorLeafMeshB, PanelBCollision);

    AActor* BlockerOwner = World->SpawnActor<AActor>();
    UBoxComponent* Blocker = NewObject<UBoxComponent>(BlockerOwner);
    BlockerOwner->AddInstanceComponent(Blocker);
    BlockerOwner->SetRootComponent(Blocker);
    Blocker->SetBoxExtent(FVector(20.0f, 10.0f, 60.0f));
    Blocker->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
    BlockerOwner->SetActorLocation(Door->GetActorTransform().TransformPosition(FVector(0.0f, -150.0f, 0.0f)));
    Blocker->RegisterComponent();
    Blocker->UpdateOverlaps();
    Door->OpenSlideDoor(EJMSlideDoorPanel::Both, Context);
    for (int32 Index = 0; Index < 25; ++Index)
    {
        Door->DoorComponent->TickComponent(0.05f, LEVELTICK_All, nullptr);
    }
    AddInfo(FString::Printf(TEXT("Obstruction states: A=%d B=%d fractions A=%.3f B=%.3f"),
        static_cast<int32>(Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA)),
        static_cast<int32>(Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB)),
        Door->DoorComponent->GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel::DoorA),
        Door->DoorComponent->GetSlideDoorPanelOpenFraction(EJMSlideDoorPanel::DoorB)));
    TestEqual(TEXT("Blocked panel A keeps its independent blocked state"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorA), EJMDoorState::Blocked);
    TestEqual(TEXT("Panel B completes even while panel A is blocked"), Door->GetSlideDoorPanelState(EJMSlideDoorPanel::DoorB), EJMDoorState::Open);
    World->DestroyActor(BlockerOwner);

    UClass* LegacyClass = LoadClass<AJMSlidingDoorActor>(nullptr, TEXT("/JMDoor/Demo/Blueprints/BP_JMSlidingDoorExample.BP_JMSlidingDoorExample_C"));
    const AJMSlidingDoorActor* LegacyCDO = LegacyClass ? Cast<AJMSlidingDoorActor>(LegacyClass->GetDefaultObject()) : nullptr;
    TestNotNull(TEXT("Legacy single-panel sliding door asset still loads"), LegacyCDO);
    if (LegacyCDO && LegacyCDO->SlidingMovement)
    {
        TestTrue(TEXT("Pre-dual-panel asset is migrated through legacy panel A mode"), LegacyCDO->SlidingMovement->IsLegacySinglePanelAsset());
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorKinematicCharacterPushTest, "JM.Door.Movement.KinematicCharacterPush", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorKinematicCharacterPushTest::RunTest(const FString& Parameters)
{
    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    TestNotNull(TEXT("Kinematic push test world was created"), World);
    if (!World)
    {
        return false;
    }

    const FJMDoorPushScenarioResult SlidingHighFps = JMRunPushScenario(World, false, 1.0f / 120.0f, false);
    const FJMDoorPushScenarioResult SlidingLowFps = JMRunPushScenario(World, false, 1.0f / 20.0f, false);
    AddInfo(FString::Printf(TEXT("Sliding 120fps: total=%s moving=%d gaps=%d largest=%.3f state=%d; 20fps: total=%s moving=%d gaps=%d largest=%.3f state=%d"),
        *SlidingHighFps.TotalMovement.ToCompactString(), SlidingHighFps.MovingFrameCount, SlidingHighFps.GapsAfterContact, SlidingHighFps.LargestFrameMove, static_cast<int32>(SlidingHighFps.FinalDoorState),
        *SlidingLowFps.TotalMovement.ToCompactString(), SlidingLowFps.MovingFrameCount, SlidingLowFps.GapsAfterContact, SlidingLowFps.LargestFrameMove, static_cast<int32>(SlidingLowFps.FinalDoorState)));
    TestTrue(TEXT("Sliding door continuously moves a stationary character"), SlidingHighFps.MovingFrameCount > 20);
    TestEqual(TEXT("Sliding push has no stationary gaps after contact"), SlidingHighFps.GapsAfterContact, 0);
    TestTrue(TEXT("Sliding push is frame-rate independent"), FVector::Distance(SlidingHighFps.TotalMovement, SlidingLowFps.TotalMovement) < 3.0f);
    TestTrue(TEXT("Sliding push is not divided by the legacy 30cm clamp"), SlidingLowFps.LargestFrameMove < 10.0f);
    TestTrue(TEXT("Sliding door adds no movement after stopping"), SlidingHighFps.ExtraMovementAfterStop < 0.01f);

    const FJMDoorPushScenarioResult RotatingHighFps = JMRunPushScenario(World, true, 1.0f / 120.0f, false);
    const FJMDoorPushScenarioResult RotatingLowFps = JMRunPushScenario(World, true, 1.0f / 20.0f, false);
    AddInfo(FString::Printf(TEXT("Rotating 120fps: total=%s moving=%d gaps=%d largest=%.3f state=%d; 20fps: total=%s moving=%d gaps=%d largest=%.3f state=%d"),
        *RotatingHighFps.TotalMovement.ToCompactString(), RotatingHighFps.MovingFrameCount, RotatingHighFps.GapsAfterContact, RotatingHighFps.LargestFrameMove, static_cast<int32>(RotatingHighFps.FinalDoorState),
        *RotatingLowFps.TotalMovement.ToCompactString(), RotatingLowFps.MovingFrameCount, RotatingLowFps.GapsAfterContact, RotatingLowFps.LargestFrameMove, static_cast<int32>(RotatingLowFps.FinalDoorState)));
    TestTrue(TEXT("Rotating door continuously moves a stationary character"), RotatingHighFps.MovingFrameCount > 10);
    TestEqual(TEXT("Rotating push has no stationary gaps after contact"), RotatingHighFps.GapsAfterContact, 0);
    TestTrue(TEXT("Rotating contact follows a tangential path"), FMath::Abs(RotatingHighFps.TotalMovement.Y) > 5.0f);
    TestTrue(TEXT("Rotating push is frame-rate independent"), FVector::Distance(RotatingHighFps.TotalMovement, RotatingLowFps.TotalMovement) < 5.0f);
    TestTrue(TEXT("Rotating door adds no movement after stopping"), RotatingHighFps.ExtraMovementAfterStop < 0.01f);

    const FJMDoorPushScenarioResult WallBlocked = JMRunPushScenario(World, false, 1.0f / 60.0f, true);
    AddInfo(FString::Printf(TEXT("Wall: total=%s moving=%d gaps=%d largest=%.3f state=%d extra=%.3f"),
        *WallBlocked.TotalMovement.ToCompactString(), WallBlocked.MovingFrameCount, WallBlocked.GapsAfterContact, WallBlocked.LargestFrameMove, static_cast<int32>(WallBlocked.FinalDoorState), WallBlocked.ExtraMovementAfterStop));
    TestEqual(TEXT("A wall behind the character blocks the door without penetration"), WallBlocked.FinalDoorState, EJMDoorState::Blocked);
    TestTrue(TEXT("Blocked door does not keep correcting the character"), WallBlocked.ExtraMovementAfterStop < 0.01f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorKinematicCharacterPushPIETest, "JM.Door.Movement.KinematicCharacterPushPIE", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorKinematicCharacterPushPIETest::RunTest(const FString& Parameters)
{
    FAutomationEditorCommonUtils::CreateNewMap();
    ADD_LATENT_AUTOMATION_COMMAND(FStartPIECommand(false));
    ADD_LATENT_AUTOMATION_COMMAND(FJMDoorVerifyKinematicPushPIECommand(this));
    ADD_LATENT_AUTOMATION_COMMAND(FJMDoorVerifyDualPanelAutoClosePIECommand(this));
    ADD_LATENT_AUTOMATION_COMMAND(FEndPlayMapCommand());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorSaveDataTest, "JM.Door.Save.DataContract", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorSaveDataTest::RunTest(const FString& Parameters)
{
    FJMDoorSaveData Data;
    Data.PersistentId = FGuid::NewGuid();
    Data.State = EJMDoorState::Blocked;
    Data.bLocked = true;
    Data.OpenFraction = 0.35f;
    Data.DoorDurability = 75.0f;
    Data.LockDurability = 10.0f;

    TestTrue(TEXT("Persistent ID is valid"), Data.PersistentId.IsValid());
    TestEqual(TEXT("State is retained"), Data.State, EJMDoorState::Blocked);
    TestTrue(TEXT("Partial open fraction is valid"), Data.OpenFraction > 0.0f && Data.OpenFraction < 1.0f);
    TestEqual(TEXT("Current save schema version"), Data.Version, 2);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorEditorPropertySafetyTest, "JM.Door.Editor.ComponentReferenceSafety", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorEditorPropertySafetyTest::RunTest(const FString& Parameters)
{
    const FProperty* MovementProperty = FindFProperty<FProperty>(UJMDoorComponent::StaticClass(), GET_MEMBER_NAME_CHECKED(UJMDoorComponent, MovementComponent));
    const FProperty* MovingSceneProperty = FindFProperty<FProperty>(UJMDoorMovementComponent::StaticClass(), GET_MEMBER_NAME_CHECKED(UJMDoorMovementComponent, MovingComponent));

    TestNotNull(TEXT("Door movement property exists"), MovementProperty);
    TestNotNull(TEXT("Moving scene property exists"), MovingSceneProperty);
    if (MovementProperty)
    {
        TestFalse(TEXT("Sibling movement component is not exposed to recursive Details editing"), MovementProperty->HasAnyPropertyFlags(CPF_Edit));
        TestTrue(TEXT("Movement component reference is transient runtime wiring"), MovementProperty->HasAnyPropertyFlags(CPF_Transient));
    }
    if (MovingSceneProperty)
    {
        TestFalse(TEXT("Moving scene component is not exposed to recursive Details editing"), MovingSceneProperty->HasAnyPropertyFlags(CPF_Edit));
        TestTrue(TEXT("Moving scene reference is transient runtime wiring"), MovingSceneProperty->HasAnyPropertyFlags(CPF_Transient));
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMDoorDetailsPanelSmokeTest, "JM.Door.Editor.DetailsPanelSmoke", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMDoorDetailsPanelSmokeTest::RunTest(const FString& Parameters)
{
    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    TestNotNull(TEXT("Editor test world was created"), World);
    if (!World)
    {
        return false;
    }

    UClass* ExampleDoorClass = LoadClass<AJMRotatingDoorActor>(nullptr, TEXT("/JMDoor/Demo/Blueprints/BP_JMRotatingDoorExample.BP_JMRotatingDoorExample_C"));
    TestNotNull(TEXT("Example rotating Door Blueprint class loaded"), ExampleDoorClass);
    if (!ExampleDoorClass)
    {
        return false;
    }

    AJMRotatingDoorActor* Door = World->SpawnActor<AJMRotatingDoorActor>(ExampleDoorClass, FVector::ZeroVector, FRotator::ZeroRotator);
    TestNotNull(TEXT("Example rotating Door Blueprint was placed"), Door);
    if (!Door)
    {
        return false;
    }

    FDetailsViewArgs ViewArgs;
    ViewArgs.bAllowSearch = false;
    ViewArgs.bUpdatesFromSelection = false;
    ViewArgs.bLockable = false;
    FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
    const TSharedRef<IDetailsView> DetailsView = PropertyEditor.CreateDetailView(ViewArgs);
    DetailsView->SetObject(Door, true);

    TestTrue(TEXT("Details panel accepted the placed door without recursive component expansion"), IsValid(Door));
    TestNotNull(TEXT("Transient movement wiring was restored by the native constructor"), Door->DoorComponent->MovementComponent.Get());
    TestNotNull(TEXT("Transient moving-scene wiring was restored by the native constructor"), Door->RotatingMovement->GetMovingComponent());
    TestNotNull(TEXT("Example rotating door has an explicit Data Asset"), Door->DoorComponent->Config.Get());
    if (Door->DoorComponent->Config)
    {
        TestEqual(
            TEXT("Example rotating door opens away from the interactor"),
            Door->DoorComponent->Config->OpenDirectionMode,
            EJMDoorOpenDirectionMode::AwayFromInteractor);
        TestFalse(TEXT("Example rotating door is not initially locked"), Door->DoorComponent->Config->bInitiallyLocked);
    }
    return true;
}

#endif
