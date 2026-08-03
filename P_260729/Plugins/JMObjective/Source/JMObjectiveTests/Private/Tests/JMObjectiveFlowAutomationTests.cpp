#include "Misc/AutomationTest.h"

#include "Data/JMObjectiveDefinition.h"
#include "Data/JMObjectiveFlowDefinition.h"
#include "Engine/GameInstance.h"
#include "Runtime/JMObjectiveEventTags.h"
#include "Runtime/JMObjectiveFlowEventTags.h"
#include "Settings/JMObjectiveSettings.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Subsystems/JMObjectiveFlowSubsystem.h"
#include "Subsystems/JMObjectiveSubsystem.h"
#include "Tests/JMObjectiveTestReceiver.h"
#include "UI/JMObjectiveDefaultWidget.h"

namespace
{
    struct FFlowFixture
    {
        TStrongObjectPtr<UGameInstance> GameInstance{NewObject<UGameInstance>()};
        TStrongObjectPtr<UJMGameplayEventSubsystem> Events{NewObject<UJMGameplayEventSubsystem>(GameInstance.Get())};
        TStrongObjectPtr<UJMObjectiveSubsystem> Objectives{NewObject<UJMObjectiveSubsystem>(GameInstance.Get())};
        TStrongObjectPtr<UJMObjectiveFlowSubsystem> Flows{NewObject<UJMObjectiveFlowSubsystem>(GameInstance.Get())};

        FFlowFixture()
        {
            Objectives->SetGameplayEventSubsystemForTesting(Events.Get());
            Flows->SetSubsystemsForTesting(Objectives.Get(), Events.Get());
        }

        UJMObjectiveDefinition* MakeObjective(FGameplayTag Id, FGameplayTag Event, FName Target, int32 Count = 1)
        {
            UJMObjectiveDefinition* Definition = NewObject<UJMObjectiveDefinition>(GameInstance.Get());
            Definition->ObjectiveId = Id;
            Definition->ListeningEventTag = Event;
            Definition->RequiredTargetIdentifier = Target;
            Definition->RequiredCount = Count;
            return Definition;
        }

        UJMObjectiveFlowDefinition* MakeFlow(const TArray<UJMObjectiveDefinition*>& Definitions)
        {
            UJMObjectiveFlowDefinition* Flow = NewObject<UJMObjectiveFlowDefinition>(GameInstance.Get());
            Flow->FlowId = JMObjectiveFlowEventTags::ObjectiveFlow;
            for (UJMObjectiveDefinition* Definition : Definitions)
            {
                Flow->ObjectiveDefinitions.Add(Definition);
            }
            return Flow;
        }

        void Publish(FGameplayTag EventTag, FName Target, int32 Amount = 1)
        {
            UJMObjectiveTestPayload* Payload = NewObject<UJMObjectiveTestPayload>(GameInstance.Get());
            Payload->ObjectiveTargetIdentifier = Target;
            Payload->ObjectiveProgressAmount = Amount;
            FJMGameplayEventMessage Message;
            Message.EventTag = EventTag;
            Message.Payload = Payload;
            Events->PublishEvent(Message);
        }

        FJMObjectiveRuntimeState ObjectiveState(FGameplayTag Id) const
        {
            FJMObjectiveRuntimeState State;
            Objectives->GetObjectiveState(Id, State);
            return State;
        }

        FJMObjectiveFlowRuntimeState FlowState() const
        {
            FJMObjectiveFlowRuntimeState State;
            Flows->GetObjectiveFlowState(JMObjectiveFlowEventTags::ObjectiveFlow, State);
            return State;
        }
    };

    const FGameplayTag ObjectiveA = JMObjectiveEventTags::Registered;
    const FGameplayTag ObjectiveB = JMObjectiveEventTags::Activated;
    const FGameplayTag ObjectiveC = JMObjectiveEventTags::Progressed;
    const FGameplayTag ExtraObjective = JMObjectiveEventTags::Removed;
    const FGameplayTag EventA = FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door"));
    const FGameplayTag EventB = FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door.Opened"));
    const FGameplayTag EventC = FGameplayTag::RequestGameplayTag(TEXT("JMGameplayEventTest.Door.Closed"));
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFlowValidationTest, "JM.Objective.Flow.Validation", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFlowValidationTest::RunTest(const FString& Parameters)
{
    FFlowFixture Fixture;
    UJMObjectiveDefinition* A = Fixture.MakeObjective(ObjectiveA, EventA, TEXT("Item.Key.Office"));
    UJMObjectiveFlowDefinition* Flow = Fixture.MakeFlow({A});
    FText Error;
    TestTrue(TEXT("Valid Flow is accepted"), Flow->IsFlowDefinitionValid(Error));

    Flow->ObjectiveDefinitions.Reset();
    TestFalse(TEXT("Empty Flow is rejected"), Flow->IsFlowDefinitionValid(Error));
    Flow->ObjectiveDefinitions.Add(nullptr);
    TestFalse(TEXT("Null Objective is rejected"), Flow->IsFlowDefinitionValid(Error));
    Flow->ObjectiveDefinitions = {A, A};
    TestFalse(TEXT("Duplicate Objective ID is rejected"), Flow->IsFlowDefinitionValid(Error));
    A->RequiredCount = 0;
    Flow->ObjectiveDefinitions = {A};
    TestFalse(TEXT("Invalid Objective is rejected"), Flow->IsFlowDefinitionValid(Error));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFlowStartAndSequentialTest, "JM.Objective.Flow.Integration.KeyDoorDialogue", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFlowStartAndSequentialTest::RunTest(const FString& Parameters)
{
    FFlowFixture Fixture;
    UJMObjectiveDefinition* A = Fixture.MakeObjective(ObjectiveA, EventA, TEXT("Item.Key.Office"));
    UJMObjectiveDefinition* B = Fixture.MakeObjective(ObjectiveB, EventB, TEXT("Door.Office.Main"));
    UJMObjectiveDefinition* C = Fixture.MakeObjective(ObjectiveC, EventC, TEXT("Dialogue.Teacher.Intro"));
    B->bAutoActivate = true;
    UJMObjectiveFlowDefinition* Flow = Fixture.MakeFlow({A, B, C});

    TStrongObjectPtr<UJMObjectiveTestReceiver> StartedReceiver{NewObject<UJMObjectiveTestReceiver>()};
    FJMGameplayEventNativeDelegate Callback = FJMGameplayEventNativeDelegate::CreateUObject(StartedReceiver.Get(), &UJMObjectiveTestReceiver::Receive);
    Fixture.Events->SubscribeEvent(JMObjectiveFlowEventTags::Started, StartedReceiver.Get(), EJMGameplayEventMatchType::Exact, MoveTemp(Callback));

    TestTrue(TEXT("Flow starts"), Fixture.Flows->StartObjectiveFlow(Flow));
    TestEqual(TEXT("Started event published once"), StartedReceiver->ReceivedCount, 1);
    TestEqual(TEXT("First Objective is Active"), Fixture.ObjectiveState(ObjectiveA).State, EJMObjectiveState::Active);
    TestEqual(TEXT("Second Objective remains Inactive despite bAutoActivate"), Fixture.ObjectiveState(ObjectiveB).State, EJMObjectiveState::Inactive);
    TestEqual(TEXT("Third Objective is Inactive"), Fixture.ObjectiveState(ObjectiveC).State, EJMObjectiveState::Inactive);
    TestFalse(TEXT("Duplicate active start is rejected"), Fixture.Flows->StartObjectiveFlow(Flow));

    UJMObjectiveDefinition* Extra = Fixture.MakeObjective(ExtraObjective, EventC, TEXT("Unrelated"));
    Fixture.Objectives->RegisterObjective(Extra);
    Fixture.Objectives->ActivateObjective(ExtraObjective);
    Fixture.Objectives->CompleteObjective(ExtraObjective);
    TestEqual(TEXT("Unrelated completion does not advance Flow"), Fixture.FlowState().CurrentStepIndex, 0);

    Fixture.Publish(EventA, TEXT("Item.Key.Office"));
    TestEqual(TEXT("Second Objective becomes Active"), Fixture.ObjectiveState(ObjectiveB).State, EJMObjectiveState::Active);
    TestEqual(TEXT("Flow advances once"), Fixture.FlowState().CurrentStepIndex, 1);
    Fixture.Objectives->CompleteObjective(ObjectiveA);
    TestEqual(TEXT("Repeated completion cannot advance twice"), Fixture.FlowState().CurrentStepIndex, 1);

    Fixture.Publish(EventB, TEXT("Door.Office.Main"));
    TestEqual(TEXT("Third Objective becomes Active"), Fixture.ObjectiveState(ObjectiveC).State, EJMObjectiveState::Active);
    Fixture.Publish(EventC, TEXT("Dialogue.Teacher.Intro"));
    TestEqual(TEXT("Flow completes after last Objective"), Fixture.FlowState().State, EJMObjectiveFlowState::Completed);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFlowFailureTest, "JM.Objective.Flow.FailurePolicy", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFlowFailureTest::RunTest(const FString& Parameters)
{
    FFlowFixture Fixture;
    UJMObjectiveDefinition* A = Fixture.MakeObjective(ObjectiveA, EventA, TEXT("Item.Key.Office"));
    UJMObjectiveDefinition* B = Fixture.MakeObjective(ObjectiveB, EventB, TEXT("Door.Office.Main"));
    A->bCanFail = true;
    UJMObjectiveFlowDefinition* Flow = Fixture.MakeFlow({A, B});
    Flow->bStopOnObjectiveFailure = true;
    Fixture.Flows->StartObjectiveFlow(Flow);
    TestTrue(TEXT("Current Objective fails"), Fixture.Objectives->FailObjective(ObjectiveA));
    TestEqual(TEXT("Flow becomes Failed"), Fixture.FlowState().State, EJMObjectiveFlowState::Failed);
    TestEqual(TEXT("Next Objective stays Inactive"), Fixture.ObjectiveState(ObjectiveB).State, EJMObjectiveState::Inactive);

    FFlowFixture SkipFixture;
    UJMObjectiveDefinition* SkipA = SkipFixture.MakeObjective(ObjectiveA, EventA, TEXT("Item.Key.Office"));
    UJMObjectiveDefinition* SkipB = SkipFixture.MakeObjective(ObjectiveB, EventB, TEXT("Door.Office.Main"));
    SkipA->bCanFail = true;
    UJMObjectiveFlowDefinition* SkipFlow = SkipFixture.MakeFlow({SkipA, SkipB});
    SkipFlow->bStopOnObjectiveFailure = false;
    SkipFixture.Flows->StartObjectiveFlow(SkipFlow);
    SkipFixture.Objectives->FailObjective(ObjectiveA);
    TestEqual(TEXT("Non-stopping failure advances to next Step"), SkipFixture.FlowState().CurrentStepIndex, 1);
    TestEqual(TEXT("Next Objective is Active after skipped failure"), SkipFixture.ObjectiveState(ObjectiveB).State, EJMObjectiveState::Active);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveFlowRestartAndSaveTest, "JM.Objective.Flow.RestartAndSave", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveFlowRestartAndSaveTest::RunTest(const FString& Parameters)
{
    FFlowFixture Fixture;
    UJMObjectiveDefinition* A = Fixture.MakeObjective(ObjectiveA, EventA, TEXT("Item.Key.Office"), 2);
    A->ProgressIncrementMode = EJMObjectiveProgressIncrementMode::PayloadAmount;
    UJMObjectiveDefinition* B = Fixture.MakeObjective(ObjectiveB, EventB, TEXT("Door.Office.Main"));
    UJMObjectiveFlowDefinition* Flow = Fixture.MakeFlow({A, B});
    Flow->bAllowRestart = true;
    Fixture.Flows->StartObjectiveFlow(Flow);
    Fixture.Publish(EventA, TEXT("Item.Key.Office"), 1);
    const TArray<FJMObjectiveFlowSaveData> Saved = Fixture.Flows->CaptureObjectiveFlowStates();
    TestEqual(TEXT("One Flow save record captured"), Saved.Num(), 1);

    Fixture.Publish(EventA, TEXT("Item.Key.Office"), 1);
    Fixture.Publish(EventB, TEXT("Door.Office.Main"));
    TestTrue(TEXT("Flow completed before restore"), Fixture.Flows->IsObjectiveFlowCompleted(Flow->FlowId));
    TestTrue(TEXT("Saved active Flow restores"), Fixture.Flows->RestoreObjectiveFlowStates(Saved));
    TestEqual(TEXT("Restored Step is first"), Fixture.FlowState().CurrentStepIndex, 0);
    TestEqual(TEXT("Restored progress is retained"), Fixture.ObjectiveState(ObjectiveA).CurrentCount, 1);
    TestEqual(TEXT("Restored Objective is subscribed and Active"), Fixture.ObjectiveState(ObjectiveA).State, EJMObjectiveState::Active);

    Fixture.Publish(EventA, TEXT("Item.Key.Office"), 1);
    Fixture.Publish(EventB, TEXT("Door.Office.Main"));
    TestTrue(TEXT("Restored Flow resumes and completes"), Fixture.Flows->IsObjectiveFlowCompleted(Flow->FlowId));
    TestTrue(TEXT("Restart allowed Flow restarts"), Fixture.Flows->RestartObjectiveFlow(Flow->FlowId));
    TestEqual(TEXT("Restart returns to first Step"), Fixture.FlowState().CurrentStepIndex, 0);
    TestEqual(TEXT("Restart resets first Objective count"), Fixture.ObjectiveState(ObjectiveA).CurrentCount, 0);
    TestTrue(TEXT("Completed Flow resets"), Fixture.Flows->StopObjectiveFlow(Flow->FlowId));
    TestTrue(TEXT("Stopped Flow resets to Inactive"), Fixture.Flows->ResetObjectiveFlow(Flow->FlowId));
    TestEqual(TEXT("Reset Flow is Inactive"), Fixture.FlowState().State, EJMObjectiveFlowState::Inactive);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMObjectiveUIContractTest, "JM.Objective.UI.AutomaticPresenterContract", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMObjectiveUIContractTest::RunTest(const FString& Parameters)
{
    const UJMObjectiveSettings* Settings = GetDefault<UJMObjectiveSettings>();
    TestNotNull(TEXT("Objective settings are available"), Settings);
    TestTrue(TEXT("Automatic Objective UI is enabled by default"), Settings && Settings->bAutomaticallyCreateObjectiveUI);
    TestTrue(TEXT("Native fallback Widget is a valid Objective Widget class"), UJMObjectiveDefaultWidget::StaticClass()->IsChildOf(UJMObjectiveWidgetBase::StaticClass()));

    TStrongObjectPtr<UJMObjectiveDefaultWidget> Widget{NewObject<UJMObjectiveDefaultWidget>()};
    UJMObjectiveDefinition* Definition = NewObject<UJMObjectiveDefinition>(Widget.Get());
    Definition->ObjectiveId = ObjectiveA;
    Definition->DisplayName = FText::FromString(TEXT("Acquire Office Key"));
    FJMObjectiveRuntimeState State;
    State.ObjectiveId = ObjectiveA;
    State.Definition = Definition;
    State.State = EJMObjectiveState::Active;
    State.CurrentCount = 0;
    State.RequiredCount = 1;
    Widget->SetObjectiveState(State);
    TestEqual(TEXT("Widget receives Objective state without Blueprint logic"), Widget->GetObjectiveState().ObjectiveId, ObjectiveA);
    return true;
}
