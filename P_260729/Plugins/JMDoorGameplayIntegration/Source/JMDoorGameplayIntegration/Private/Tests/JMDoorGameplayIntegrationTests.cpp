#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Actors/JMDoorActor.h"
#include "Components/InventoryComponent.h"
#include "Components/JMDoorInteractableAdapterComponent.h"
#include "Components/JMDoorInventoryAgentComponent.h"
#include "Data/JMDoorConfigData.h"
#include "Door/JMDoorComponent.h"
#include "Door/JMDoorTags.h"
#include "Engine/World.h"
#include "InventoryTypes.h"
#include "Items/InventoryItemDefinition.h"
#include "Items/InventoryUseOnActorComponentsEffect.h"
#include "Settings/JMDoorGameplayIntegrationSettings.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMDoorCustomInteractionPromptTest,
    "JM.Door.Integration.CustomInteractionPrompt",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDoorCustomInteractionPromptTest::RunTest(const FString& Parameters)
{
    const UJMDoorGameplayIntegrationSettings* Settings =
        GetDefault<UJMDoorGameplayIntegrationSettings>();
    TestFalse(TEXT("Default open prompt is authorable and populated"), Settings->OpenDoorPrompt.IsEmpty());
    TestFalse(TEXT("Default close prompt is authorable and populated"), Settings->CloseDoorPrompt.IsEmpty());
    TestFalse(TEXT("Default locked prompt is authorable and populated"), Settings->LockedDoorPrompt.IsEmpty());

    AJMRotatingDoorActor* Door = NewObject<AJMRotatingDoorActor>();
    UJMDoorInteractableAdapterComponent* Adapter =
        NewObject<UJMDoorInteractableAdapterComponent>(Door);
    Adapter->bOverridePromptTexts = true;
    Adapter->OpenDoorPrompt = FText::FromString(TEXT("Custom open"));

    FJMInteractionContext Context;
    const FJMInteractionPrompt Prompt =
        Adapter->GetInteractionPrompt_Implementation(Context);
    TestTrue(
        TEXT("Per-door override replaces the project default"),
        Prompt.DisplayText.EqualTo(Adapter->OpenDoorPrompt));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMDoorInventoryOldKeyFlowTest,
    "JM.Door.Integration.InventoryOldKeyFlow",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMDoorInventoryOldKeyFlowTest::RunTest(const FString& Parameters)
{
    UInventoryItemDefinition* ConfiguredOldKey = LoadObject<UInventoryItemDefinition>(
        nullptr,
        TEXT("/InventorySystem/Example/DA_Inventory_OldKey.DA_Inventory_OldKey"));
    TestNotNull(TEXT("Existing Old Key Item Definition loaded"), ConfiguredOldKey);
    if (ConfiguredOldKey)
    {
        TestTrue(TEXT("Existing Old Key can be used"), ConfiguredOldKey->bCanUse);
        TestTrue(TEXT("Existing Old Key provides the demo door access tag"), ConfiguredOldKey->ItemTags.HasTagExact(TAG_JMDoor_Demo_Key));
        TestNull(TEXT("Existing Old Key needs no per-item Use Effect"), ConfiguredOldKey->UseEffect.Get());
    }

    UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
    TestNotNull(TEXT("Test world created"), World);
    if (!World)
    {
        return false;
    }

    AJMRotatingDoorActor* Door = World->SpawnActor<AJMRotatingDoorActor>();
    AActor* User = World->SpawnActor<AActor>();
    Door->DoorLeafMesh->SetRelativeLocation(FVector(0.0f, 50.0f, 0.0f));
    Door->MovementRoot->UpdateComponentToWorld();
    Door->DoorLeafMesh->UpdateComponentToWorld();
    UInventoryComponent* Inventory = NewObject<UInventoryComponent>(User, TEXT("Inventory"));
    User->AddInstanceComponent(Inventory);
    Inventory->RegisterComponent();
    UJMDoorInventoryAgentComponent* Agent = NewObject<UJMDoorInventoryAgentComponent>(User, TEXT("DoorInventoryAgent"));
    User->AddInstanceComponent(Agent);
    Agent->RegisterComponent();

    UJMDoorConfigData* Config = NewObject<UJMDoorConfigData>();
    Config->AcceptedAccessObjects.Add(TSoftObjectPtr<UObject>(ConfiguredOldKey));
    Config->bDetectObstructions = false;
    Door->DoorComponent->Config = Config;
    TestTrue(TEXT("Door locked"), Door->DoorComponent->LockDoor().bSucceeded);

    FJMInteractionContext InteractionContext;
    InteractionContext.InstigatorActor = User;
    InteractionContext.InteractionLocation = FVector(-200.0f, 0.0f, 0.0f);
    InteractionContext.InteractionDirection = FVector::ForwardVector;
    TestTrue(TEXT("Locked door stored as pending item target"), Agent->SetPendingDoorForItemUse(Door, InteractionContext));

    TestTrue(TEXT("Existing Old Key added to the real Inventory Component"), Inventory->AddItem(ConfiguredOldKey, 1));
    int32 OldKeySlotIndex = INDEX_NONE;
    const TArray<FInventorySlot> Slots = Inventory->GetInventorySlots();
    for (int32 SlotIndex = 0; SlotIndex < Slots.Num(); ++SlotIndex)
    {
        if (Slots[SlotIndex].ItemDefinition == ConfiguredOldKey)
        {
            OldKeySlotIndex = SlotIndex;
            break;
        }
    }
    TestTrue(TEXT("Existing Old Key slot found"), OldKeySlotIndex != INDEX_NONE);
    TestEqual(TEXT("UseItemAtSlot completes the full UI-equivalent path"), Inventory->UseItemAtSlot(OldKeySlotIndex, User), EInventoryOperationResult::Success);
    TestFalse(TEXT("Door is unlocked after successful use"), Door->DoorComponent->IsLocked());
    TestNull(TEXT("Pending target is cleared"), Agent->GetPendingDoor());

    const FVector ClosedLeafLocation = Door->DoorLeafMesh->GetComponentLocation();
    Door->DoorComponent->TickComponent(0.5f, LEVELTICK_All, nullptr);
    const FVector LeafTravel = Door->DoorLeafMesh->GetComponentLocation() - ClosedLeafLocation;
    AddInfo(FString::Printf(TEXT("Player=%s ClosedLeaf=%s LeafTravel=%s"), *InteractionContext.InteractionLocation.ToCompactString(), *ClosedLeafLocation.ToCompactString(), *LeafTravel.ToCompactString()));
    TestTrue(TEXT("Door leaf moves along the player's interaction ray, away from the player"), FVector::DotProduct(LeafTravel, InteractionContext.InteractionDirection) > 0.0f);

    AJMRotatingDoorActor* OppositeDoor = World->SpawnActor<AJMRotatingDoorActor>();
    OppositeDoor->DoorLeafMesh->SetRelativeLocation(FVector(0.0f, 50.0f, 0.0f));
    OppositeDoor->MovementRoot->UpdateComponentToWorld();
    OppositeDoor->DoorLeafMesh->UpdateComponentToWorld();
    UJMDoorConfigData* OppositeConfig = NewObject<UJMDoorConfigData>();
    OppositeConfig->bDetectObstructions = false;
    OppositeDoor->DoorComponent->Config = OppositeConfig;
    FJMDoorUseContext OppositeContext;
    OppositeContext.InteractionLocation = FVector(200.0f, 0.0f, 0.0f);
    const FVector OppositeClosedLeafLocation = OppositeDoor->DoorLeafMesh->GetComponentLocation();
    TestTrue(TEXT("Door opens from the opposite player side"), OppositeDoor->DoorComponent->OpenDoor(OppositeContext).bSucceeded);
    OppositeDoor->DoorComponent->TickComponent(0.5f, LEVELTICK_All, nullptr);
    const FVector OppositeLeafTravel = OppositeDoor->DoorLeafMesh->GetComponentLocation() - OppositeClosedLeafLocation;
    TestTrue(TEXT("Opposite-side player reverses the swing direction"), OppositeLeafTravel.X < 0.0f);

    World->DestroyWorld(false);
    return true;
}

#endif
