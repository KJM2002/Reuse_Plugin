#include "Misc/AutomationTest.h"

#include "Data/JMObjectiveDefinition.h"
#include "Engine/GameInstance.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "Runtime/JMObjectiveEventTags.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Tests/JMObjectiveTestReceiver.h"

#define TAG_Objective_Key JMObjectiveEventTags::Registered
#define TAG_Objective_Door JMObjectiveEventTags::Activated
#define TAG_Objective_Dialogue JMObjectiveEventTags::Progressed
#define TAG_Event_Item FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door"))
#define TAG_Event_Door FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door.Opened"))
#define TAG_Event_Dialogue FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door.Closed"))
#define TAG_Context_Required JMObjectiveEventTags::Completed
#define TAG_Context_Blocked JMObjectiveEventTags::Failed

namespace
{
    struct FObjectiveFixture
    {
        TStrongObjectPtr<UGameInstance> GameInstance{NewObject<UGameInstance>()};
        TStrongObjectPtr<UJMGameplayEventSubsystem> Events{NewObject<UJMGameplayEventSubsystem>(GameInstance.Get())};
        TStrongObjectPtr<UJMObjectiveSubsystem> Objectives{NewObject<UJMObjectiveSubsystem>(GameInstance.Get())};

        FObjectiveFixture()
        {
            Objectives->SetGameplayEventSubsystemForTesting(Events.Get());
        }

        UJMObjectiveDefinition* MakeDefinition(FGameplayTag ObjectiveId, FGameplayTag EventTag, FName TargetId, int32 RequiredCount = 1)
        {
            UJMObjectiveDefinition* Definition = NewObject<UJMObjectiveDefinition>(GameInstance.Get());
            Definition->ObjectiveId = ObjectiveId;
            Definition->ListeningEventTag = EventTag;
            Definition->RequiredTargetIdentifier = TargetId;
            Definition->RequiredCount = RequiredCount;
            return Definition;
        }

        int32 Publish(FGameplayTag EventTag, FName TargetId, int32 Amount = 1, const FGameplayTagContainer& ContextTags = {})
        {
            UJMObjectiveTestPayload* Payload = NewObject<UJMObjectiveTestPayload>(GameInstance.Get());
            Payload->ObjectiveTargetIdentifier = TargetId;
            Payload->ObjectiveProgressAmount = Amount;
            FJMGameplayEventMessage Message;
            Message.EventTag = EventTag;
            Message.ContextTags = ContextTags;
            Message.Payload = Payload;
            return Events->PublishEvent(Message);
        }

        FJMObjectiveRuntimeState State(FGameplayTag ObjectiveId) const
        {
            FJMObjectiveRuntimeState Result;
            Objectives->GetObjectiveState(ObjectiveId, Result);
            return Result;
        }
    };
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveLifecycleTest, "JM.Objective.Lifecycle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveLifecycleTest::RunTest(const FString& Parameters)
{
    FObjectiveFixture Fixture;
    TStrongObjectPtr<UJMObjectiveTestReceiver> CompletionReceiver{NewObject<UJMObjectiveTestReceiver>()};
    FJMGameplayEventNativeDelegate CompletionCallback = FJMGameplayEventNativeDelegate::CreateUObject(CompletionReceiver.Get(), &UJMObjectiveTestReceiver::Receive);
    Fixture.Events->SubscribeEvent(JMObjectiveEventTags::Completed, CompletionReceiver.Get(), EJMGameplayEventMatchType::Exact, MoveTemp(CompletionCallback));
    UJMObjectiveDefinition* Definition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office"));

    TestTrue(TEXT("Definition registers"), Fixture.Objectives->RegisterObjective(Definition));
    TestEqual(TEXT("Initial state is inactive"), Fixture.State(TAG_Objective_Key).State, EJMObjectiveState::Inactive);
    TestEqual(TEXT("Initial count is zero"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    TestTrue(TEXT("Inactive objective activates"), Fixture.Objectives->ActivateObjective(TAG_Objective_Key));
    TestFalse(TEXT("Duplicate activation is rejected"), Fixture.Objectives->ActivateObjective(TAG_Objective_Key));
    TestEqual(TEXT("Objective subscription is added beside observer"), Fixture.Events->GetSubscriptionCount(), 2);

    Fixture.Publish(TAG_Event_Door, TEXT("Item.Key.Office"));
    TestEqual(TEXT("Wrong event tag does not progress"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Health.Small"));
    TestEqual(TEXT("Wrong target does not progress"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"));
    TestEqual(TEXT("Matching event completes"), Fixture.State(TAG_Objective_Key).State, EJMObjectiveState::Completed);
    TestEqual(TEXT("Completion removes only objective subscription"), Fixture.Events->GetSubscriptionCount(), 1);
    TestEqual(TEXT("Completed event is published once"), CompletionReceiver->ReceivedCount, 1);

    const FDateTime FirstCompletion = Fixture.State(TAG_Objective_Key).CompletionTime;
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"));
    TestEqual(TEXT("Completed objective count is stable"), Fixture.State(TAG_Objective_Key).CurrentCount, 1);
    TestEqual(TEXT("Completion time is stable"), Fixture.State(TAG_Objective_Key).CompletionTime, FirstCompletion);
    TestEqual(TEXT("Completed event is not republished"), CompletionReceiver->ReceivedCount, 1);

    TestTrue(TEXT("Completed objective resets"), Fixture.Objectives->ResetObjective(TAG_Objective_Key));
    TestEqual(TEXT("Reset returns inactive"), Fixture.State(TAG_Objective_Key).State, EJMObjectiveState::Inactive);
    TestEqual(TEXT("Reset clears count"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFiltersAndQuantityTest, "JM.Objective.FiltersAndQuantity", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFiltersAndQuantityTest::RunTest(const FString& Parameters)
{
    FObjectiveFixture Fixture;
    UJMObjectiveDefinition* Definition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office"), 5);
    Definition->ProgressIncrementMode = EJMObjectiveProgressIncrementMode::PayloadAmount;
    Definition->RequiredContextTags.AddTag(TAG_Context_Required);
    Definition->BlockedContextTags.AddTag(TAG_Context_Blocked);
    TestTrue(TEXT("Quantity objective registers"), Fixture.Objectives->RegisterObjective(Definition));
    TestTrue(TEXT("Quantity objective activates"), Fixture.Objectives->ActivateObjective(TAG_Objective_Key));

    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"), 2);
    TestEqual(TEXT("Missing required context is ignored"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    FGameplayTagContainer BlockedContext(TAG_Context_Required);
    BlockedContext.AddTag(TAG_Context_Blocked);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"), 2, BlockedContext);
    TestEqual(TEXT("Blocked context is ignored"), Fixture.State(TAG_Objective_Key).CurrentCount, 0);
    FGameplayTagContainer RequiredContext(TAG_Context_Required);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"), 2, RequiredContext);
    TestEqual(TEXT("First payload amount"), Fixture.State(TAG_Objective_Key).CurrentCount, 2);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"), 2, RequiredContext);
    TestEqual(TEXT("Second payload amount"), Fixture.State(TAG_Objective_Key).CurrentCount, 4);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"), 2, RequiredContext);
    TestEqual(TEXT("Progress clamps to required count"), Fixture.State(TAG_Objective_Key).CurrentCount, 5);
    TestEqual(TEXT("Quantity objective completes"), Fixture.State(TAG_Objective_Key).State, EJMObjectiveState::Completed);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFailureRemovalSaveTest, "JM.Objective.FailureRemovalAndSave", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFailureRemovalSaveTest::RunTest(const FString& Parameters)
{
    FObjectiveFixture Fixture;
    UJMObjectiveDefinition* Definition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office"), 3);
    Definition->bCanFail = true;
    Fixture.Objectives->RegisterObjective(Definition);
    Fixture.Objectives->ActivateObjective(TAG_Objective_Key);
    Fixture.Objectives->AddObjectiveProgress(TAG_Objective_Key, 1);
    const TArray<FJMObjectiveSaveData> Saved = Fixture.Objectives->CaptureObjectiveStates();
    TestEqual(TEXT("One save record captured"), Saved.Num(), 1);
    TestTrue(TEXT("Active objective can fail"), Fixture.Objectives->FailObjective(TAG_Objective_Key));
    TestEqual(TEXT("Failed objective unsubscribes"), Fixture.Events->GetSubscriptionCount(), 0);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"));
    TestEqual(TEXT("Failed objective ignores events"), Fixture.State(TAG_Objective_Key).CurrentCount, 1);
    TestTrue(TEXT("Restore rebuilds active subscription"), Fixture.Objectives->RestoreObjectiveStates(Saved));
    TestEqual(TEXT("Restored objective is active"), Fixture.State(TAG_Objective_Key).State, EJMObjectiveState::Active);
    TestEqual(TEXT("Restored active objective subscribed"), Fixture.Events->GetSubscriptionCount(), 1);
    TestTrue(TEXT("Active objective unregisters"), Fixture.Objectives->UnregisterObjective(TAG_Objective_Key));
    TestEqual(TEXT("Unregister removes subscription"), Fixture.Events->GetSubscriptionCount(), 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveSequentialIntegrationTest, "JM.Objective.Integration.KeyDoorDialogue", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveSequentialIntegrationTest::RunTest(const FString& Parameters)
{
    FObjectiveFixture Fixture;
    Fixture.Objectives->RegisterObjective(Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office")));
    Fixture.Objectives->RegisterObjective(Fixture.MakeDefinition(TAG_Objective_Door, TAG_Event_Door, TEXT("Door.Office.Main")));
    Fixture.Objectives->RegisterObjective(Fixture.MakeDefinition(TAG_Objective_Dialogue, TAG_Event_Dialogue, TEXT("Dialogue.Teacher.Intro")));

    Fixture.Objectives->ActivateObjective(TAG_Objective_Key);
    Fixture.Publish(TAG_Event_Item, TEXT("Item.Key.Office"));
    TestTrue(TEXT("Key objective completed"), Fixture.Objectives->IsObjectiveCompleted(TAG_Objective_Key));
    TestEqual(TEXT("Door remains inactive until controller advances"), Fixture.State(TAG_Objective_Door).State, EJMObjectiveState::Inactive);

    Fixture.Objectives->ActivateObjective(TAG_Objective_Door);
    Fixture.Publish(TAG_Event_Door, TEXT("Door.Office.Main"));
    TestTrue(TEXT("Door objective completed"), Fixture.Objectives->IsObjectiveCompleted(TAG_Objective_Door));

    Fixture.Objectives->ActivateObjective(TAG_Objective_Dialogue);
    Fixture.Publish(TAG_Event_Dialogue, TEXT("Dialogue.Teacher.Intro"));
    TestTrue(TEXT("Dialogue objective completed"), Fixture.Objectives->IsObjectiveCompleted(TAG_Objective_Dialogue));
    TestEqual(TEXT("All objective subscriptions released"), Fixture.Events->GetSubscriptionCount(), 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveActivationReentrancyTest, "JM.Objective.Reentrancy.ActivationUnregister", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveActivationReentrancyTest::RunTest(const FString& Parameters)
{
    FObjectiveFixture Fixture;
    UJMObjectiveDefinition* Definition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office"));
    TestTrue(TEXT("Objective registers"), Fixture.Objectives->RegisterObjectiveInactive(Definition));
    TStrongObjectPtr<UJMObjectiveReentrancyReceiver> Receiver{NewObject<UJMObjectiveReentrancyReceiver>()};
    Receiver->Objectives = Fixture.Objectives.Get();
    Fixture.Objectives->OnObjectiveActivated.AddDynamic(Receiver.Get(), &UJMObjectiveReentrancyReceiver::UnregisterOnState);

    TestTrue(TEXT("Activation mutation itself succeeds"), Fixture.Objectives->ActivateObjective(TAG_Objective_Key));
    FJMObjectiveRuntimeState State;
    TestFalse(TEXT("Reentrant unregister removes the Objective"), Fixture.Objectives->GetObjectiveState(TAG_Objective_Key, State));
    TestEqual(TEXT("Activation callback runs once"), Receiver->CallbackCount, 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveProgressReentrancyTest, "JM.Objective.Reentrancy.ProgressMutations", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveProgressReentrancyTest::RunTest(const FString& Parameters)
{
    for (int32 Action = 1; Action <= 3; ++Action)
    {
        FObjectiveFixture Fixture;
        UJMObjectiveDefinition* Definition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Office"), 1);
        TestTrue(TEXT("Objective registers"), Fixture.Objectives->RegisterObjectiveInactive(Definition));
        TestTrue(TEXT("Objective activates"), Fixture.Objectives->ActivateObjective(TAG_Objective_Key));

        TStrongObjectPtr<UJMObjectiveReentrancyReceiver> Receiver{NewObject<UJMObjectiveReentrancyReceiver>()};
        Receiver->Objectives = Fixture.Objectives.Get();
        Receiver->ProgressAction = Action;
        if (Action == 2)
        {
            Receiver->ReplacementDefinition = Fixture.MakeDefinition(TAG_Objective_Key, TAG_Event_Item, TEXT("Item.Key.Replacement"), 2);
        }
        Fixture.Objectives->OnObjectiveProgressed.AddDynamic(Receiver.Get(), &UJMObjectiveReentrancyReceiver::MutateOnProgress);

        TestTrue(TEXT("Progress mutation succeeds"), Fixture.Objectives->AddObjectiveProgress(TAG_Objective_Key, 1));
        FJMObjectiveRuntimeState State;
        if (Action == 1)
        {
            TestFalse(TEXT("Unregistered Objective stays removed"), Fixture.Objectives->GetObjectiveState(TAG_Objective_Key, State));
        }
        else if (Action == 2)
        {
            TestTrue(TEXT("Replacement Objective remains registered"), Fixture.Objectives->GetObjectiveState(TAG_Objective_Key, State));
            TestEqual(TEXT("Replacement Objective is not completed by stale progress"), State.State, EJMObjectiveState::Inactive);
            TestEqual(TEXT("Replacement Objective keeps its own target count"), State.RequiredCount, 2);
        }
        else
        {
            TestTrue(TEXT("Reentrant completion keeps Objective available"), Fixture.Objectives->GetObjectiveState(TAG_Objective_Key, State));
            TestEqual(TEXT("Objective completes exactly once"), State.State, EJMObjectiveState::Completed);
        }
        TestEqual(TEXT("Progress callback runs once"), Receiver->CallbackCount, 1);
    }
    return true;
}
