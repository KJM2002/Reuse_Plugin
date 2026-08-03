#include "Misc/AutomationTest.h"

#include "Components/JMInteractionComponent.h"
#include "Components/JMReconInteractorComponent.h"
#include "Components/JMReconPlayerBridgeComponent.h"
#include "Components/JMReconTargetComponent.h"
#include "Data/JMReconDefinition.h"
#include "GameFramework/Pawn.h"
#include "Settings/JMReconGameplayIntegrationSettings.h"
#include "UI/JMReconPromptWidgetBase.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconGameplayIntegrationDirectStartTest,
    "JM.Recon.Integration.DirectTargetStart",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconGameplayIntegrationDirectStartTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<APawn> Player(NewObject<APawn>());
    TStrongObjectPtr<UJMInteractionComponent> Interaction(
        NewObject<UJMInteractionComponent>(Player.Get()));
    TStrongObjectPtr<UJMReconInteractorComponent> Interactor(
        NewObject<UJMReconInteractorComponent>(Player.Get()));
    TStrongObjectPtr<UJMReconPlayerBridgeComponent> Bridge(
        NewObject<UJMReconPlayerBridgeComponent>(Player.Get()));
    Player->AddInstanceComponent(Interaction.Get());
    Player->AddInstanceComponent(Interactor.Get());
    Player->AddInstanceComponent(Bridge.Get());

    TStrongObjectPtr<AActor> TargetActor(NewObject<AActor>());
    TStrongObjectPtr<UJMReconTargetComponent> Target(
        NewObject<UJMReconTargetComponent>(TargetActor.Get()));
    TStrongObjectPtr<UJMReconDefinition> Definition(NewObject<UJMReconDefinition>());
    TargetActor->AddInstanceComponent(Target.Get());
    Target->MaximumStartDistance = 0.0f;
    Target->ReconDefinition = Definition.Get();
    Definition->EnteringDuration = 0.0f;
    Definition->ExitingDuration = 0.0f;

    const FJMReconRequestResult Result = Bridge->TryStartReconWithTarget(Target.Get());
    TestTrue(TEXT("Bridge starts Recon with an explicit target"), Result.bSucceeded);
    TestEqual(
        TEXT("Default integration entry becomes Listening"),
        Interactor->GetCurrentState(),
        EJMReconState::Listening);
    TestTrue(TEXT("Integration cleanup succeeds"), Interactor->CancelRecon().bSucceeded);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconGameplayIntegrationSettingsTest,
    "JM.Recon.Integration.DefaultSettings",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconGameplayIntegrationSettingsTest::RunTest(const FString& Parameters)
{
    const UJMReconGameplayIntegrationSettings* Settings =
        GetDefault<UJMReconGameplayIntegrationSettings>();
    TestNotNull(TEXT("Integration settings exist"), Settings);
    TestTrue(TEXT("Player bridge is automatic"), Settings->bAutoAddPlayerBridge);
    TestTrue(TEXT("Input is automatic"), Settings->bAutoBindInput);
    TestTrue(TEXT("Camera is automatic"), Settings->bAutoManageCamera);
    TestTrue(TEXT("Illuminate light is automatic"), Settings->bAutoManageIlluminate);
    TestTrue(TEXT("Native prompt fallback is automatic"), Settings->bCreateReconPromptWidget);
    TestEqual(TEXT("Interaction display key defaults to E"), Settings->InteractionDisplayKey, EKeys::E);
    TestEqual(TEXT("Start key defaults to R"), Settings->StartOrFinishKey, EKeys::R);
    TestEqual(TEXT("Illuminate key defaults to F"), Settings->IlluminateKey, EKeys::F);
    TestEqual(TEXT("Exit key defaults to Escape"), Settings->ExitKey, EKeys::Escape);
    TestFalse(TEXT("Focused target prompt format is authorable and populated"), Settings->FocusedTargetPromptFormat.IsEmpty());
    TestFalse(TEXT("Entering prompt is authorable and populated"), Settings->EnteringPrompt.IsEmpty());
    TestFalse(TEXT("Observing prompt format is authorable and populated"), Settings->ObservingPromptFormat.IsEmpty());
    TestFalse(TEXT("Generic failure prompt is authorable and populated"), Settings->GenericFailurePrompt.IsEmpty());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconGameplayIntegrationTextPromptFallbackTest,
    "JM.Recon.Integration.TextPromptFallback",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconGameplayIntegrationTextPromptFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMReconPromptWidgetBase> Prompt(NewObject<UJMReconPromptWidgetBase>());
    const FText Expected = NSLOCTEXT(
        "JMReconGameplayIntegrationTests",
        "FallbackPrompt",
        "[마우스] 둘러보기    [F 길게] 손전등    [R] 뒤로");
    Prompt->SetReconPrompt(Expected, true);
    TestTrue(TEXT("Native fallback retains localized text"), Prompt->GetDisplayedPrompt().EqualTo(Expected));
    TestEqual(
        TEXT("Prompt becomes non-interactive visible"),
        Prompt->GetVisibility(),
        ESlateVisibility::HitTestInvisible);
    Prompt->SetReconPrompt(FText::GetEmpty(), false);
    TestEqual(TEXT("Prompt collapses safely"), Prompt->GetVisibility(), ESlateVisibility::Collapsed);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMReconGameplayIntegrationLookClampTest,
    "JM.Recon.Integration.LookClampWrapSafety",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMReconGameplayIntegrationLookClampTest::RunTest(const FString& Parameters)
{
    float Offset = UJMReconPlayerBridgeComponent::AccumulateClampedLookAngle(
        30.0f, 170.0f, -170.0f, 35.0f);
    TestEqual(TEXT("Positive 180-degree wrap stays at the right limit"), Offset, 35.0f);

    Offset = UJMReconPlayerBridgeComponent::AccumulateClampedLookAngle(
        Offset, -170.0f, -150.0f, 35.0f);
    TestEqual(TEXT("Continued right input does not flip to the left limit"), Offset, 35.0f);

    Offset = UJMReconPlayerBridgeComponent::AccumulateClampedLookAngle(
        Offset, -150.0f, -160.0f, 35.0f);
    TestEqual(TEXT("Reverse input immediately leaves the right limit"), Offset, 25.0f);

    const float NegativeOffset =
        UJMReconPlayerBridgeComponent::AccumulateClampedLookAngle(
            -30.0f, -170.0f, 170.0f, 35.0f);
    TestEqual(TEXT("Negative 180-degree wrap stays at the left limit"), NegativeOffset, -35.0f);
    return true;
}
