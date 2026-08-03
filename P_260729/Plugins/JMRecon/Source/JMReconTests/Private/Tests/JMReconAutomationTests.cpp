#include "Misc/AutomationTest.h"

#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Data/JMReconDefinition.h"
#include "Misc/DataValidation.h"
#include "UObject/StrongObjectPtr.h"

namespace
{
    struct FReconFixture
    {
        TStrongObjectPtr<AActor> Player;
        TStrongObjectPtr<AActor> TargetActor;
        TStrongObjectPtr<UJMReconInteractorComponent> Interactor;
        TStrongObjectPtr<UJMReconTargetComponent> Target;
        TStrongObjectPtr<UJMReconDefinition> Definition;

        FReconFixture()
            : Player(NewObject<AActor>())
            , TargetActor(NewObject<AActor>())
            , Interactor(NewObject<UJMReconInteractorComponent>(Player.Get()))
            , Target(NewObject<UJMReconTargetComponent>(TargetActor.Get()))
            , Definition(NewObject<UJMReconDefinition>())
        {
            Player->AddInstanceComponent(Interactor.Get());
            TargetActor->AddInstanceComponent(Target.Get());
            Target->MaximumStartDistance = 0.0f;
            Target->ReconDefinition = Definition.Get();
            Definition->EnteringDuration = 0.0f;
            Definition->ExitingDuration = 0.0f;
        }
    };
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconHappyPathTest,
    "JM.Recon.Runtime.HappyPathAndCleanup",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconHappyPathTest::RunTest(const FString& Parameters)
{
    FReconFixture Fixture;

    const FJMReconRequestResult Start = Fixture.Interactor->TryStartRecon(Fixture.Target.Get());
    TestTrue(TEXT("Recon starts"), Start.bSucceeded);
    TestEqual(TEXT("Default entry becomes Listening"), Fixture.Interactor->GetCurrentState(), EJMReconState::Listening);
    TestTrue(TEXT("Target is reserved"), Fixture.Target->IsReserved());

    const FJMReconRequestResult Peek = Fixture.Interactor->StartPeek();
    TestTrue(TEXT("Peek starts"), Peek.bSucceeded);
    TestEqual(TEXT("State is Peeking"), Fixture.Interactor->GetCurrentState(), EJMReconState::Peeking);
    TestTrue(TEXT("Illuminate can start while peeking"), Fixture.Interactor->SetIlluminate(true).bSucceeded);
    TestTrue(TEXT("Illuminate is active"), Fixture.Interactor->IsIlluminating());

    TestTrue(TEXT("Cancel succeeds"), Fixture.Interactor->CancelRecon().bSucceeded);
    TestEqual(TEXT("Cancel returns to Idle"), Fixture.Interactor->GetCurrentState(), EJMReconState::Idle);
    TestFalse(TEXT("Target reservation is released"), Fixture.Target->IsReserved());
    TestTrue(TEXT("Repeated cancel is idempotent"), Fixture.Interactor->CancelRecon().bSucceeded);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconDuplicateAndReservationTest,
    "JM.Recon.Runtime.DuplicateAndReservation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconDuplicateAndReservationTest::RunTest(const FString& Parameters)
{
    FReconFixture Fixture;
    TStrongObjectPtr<AActor> SecondPlayer(NewObject<AActor>());
    TStrongObjectPtr<UJMReconInteractorComponent> SecondInteractor(
        NewObject<UJMReconInteractorComponent>(SecondPlayer.Get()));
    SecondPlayer->AddInstanceComponent(SecondInteractor.Get());

    TestTrue(TEXT("First interactor starts"), Fixture.Interactor->TryStartRecon(Fixture.Target.Get()).bSucceeded);

    const FJMReconRequestResult Duplicate = Fixture.Interactor->TryStartRecon(Fixture.Target.Get());
    TestFalse(TEXT("Duplicate start is rejected"), Duplicate.bSucceeded);
    TestEqual(TEXT("Duplicate start reason"), Duplicate.FailureReason, EJMReconFailureReason::AlreadyActive);

    const FJMReconRequestResult Contended = SecondInteractor->TryStartRecon(Fixture.Target.Get());
    TestFalse(TEXT("Second interactor cannot reserve target"), Contended.bSucceeded);
    TestEqual(TEXT("Reservation failure reason"), Contended.FailureReason, EJMReconFailureReason::AlreadyInUse);

    Fixture.Interactor->CancelRecon();
    TestTrue(TEXT("Second interactor can start after release"), SecondInteractor->TryStartRecon(Fixture.Target.Get()).bSucceeded);
    SecondInteractor->CancelRecon();
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconInvalidStateTest,
    "JM.Recon.Runtime.InvalidStateSafety",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconInvalidStateTest::RunTest(const FString& Parameters)
{
    FReconFixture Fixture;
    TestFalse(TEXT("Peek cannot start without session"), Fixture.Interactor->StartPeek().bSucceeded);
    TestFalse(TEXT("Illuminate cannot start without Peek"), Fixture.Interactor->SetIlluminate(true).bSucceeded);

    Fixture.Definition->bAllowPeek = false;
    Fixture.Interactor->TryStartRecon(Fixture.Target.Get());
    TestFalse(TEXT("Peek disabled by definition"), Fixture.Interactor->StartPeek().bSucceeded);
    TestEqual(TEXT("Disabled Peek reason"), Fixture.Interactor->GetLastFailureReason(), EJMReconFailureReason::NotSupported);
    Fixture.Interactor->CancelRecon();
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconDefinitionValidationTest,
    "JM.Recon.Data.Validation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconDefinitionValidationTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMReconDefinition> Definition(NewObject<UJMReconDefinition>());
    Definition->bAllowListen = false;
    Definition->bAllowPeek = false;
    Definition->PeekOpenFraction = 2.0f;

    FDataValidationContext Context;
    TestEqual(TEXT("Invalid definition is rejected"), Definition->IsDataValid(Context), EDataValidationResult::Invalid);
    TestTrue(TEXT("Validation reports errors"), Context.GetNumErrors() >= 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconModeMaskCompatibilityTest,
    "JM.Recon.Runtime.ModeMaskCompatibility",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconModeMaskCompatibilityTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMReconTargetComponent> Target(NewObject<UJMReconTargetComponent>());
    TestEqual(TEXT("New targets store all modes as 1|2|4"), Target->AllowedReconModes, 7);
    TestTrue(TEXT("Default target supports Listen"), Target->SupportsMode(EJMReconMode::Listen));
    TestTrue(TEXT("Default target supports Peek"), Target->SupportsMode(EJMReconMode::Peek));
    TestTrue(TEXT("Default target supports Illuminate"), Target->SupportsMode(EJMReconMode::Illuminate));

    Target->AllowedReconModes = 22;
    TestTrue(TEXT("Legacy value 22 retains Listen"), Target->SupportsMode(EJMReconMode::Listen));
    TestTrue(TEXT("Legacy value 22 retains Peek"), Target->SupportsMode(EJMReconMode::Peek));
    TestTrue(TEXT("Legacy value 22 retains Illuminate"), Target->SupportsMode(EJMReconMode::Illuminate));
    return true;
}
