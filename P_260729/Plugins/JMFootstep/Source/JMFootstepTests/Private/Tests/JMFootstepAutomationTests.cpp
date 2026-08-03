#include "Misc/AutomationTest.h"

#include "Components/JMFootstepComponent.h"
#include "Data/JMFootstepSet.h"
#include "Data/JMFootstepSurfaceProfile.h"
#include "Types/JMFootstepRuntimeLogic.h"
#include "Sound/SoundWave.h"
#include "UObject/StrongObjectPtr.h"
#include "UObject/UnrealType.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepNoMovementNoStepTest,
    "JM.Footstep.Distance.NoMovementNoStep",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepNoMovementNoStepTest::RunTest(const FString& Parameters)
{
    FJMFootstepDistanceAccumulator Accumulator;
    TestEqual(TEXT("Zero movement does not step"), Accumulator.AddMovement(0.0f, true, 100.0f, 500.0f, 2), 0);
    TestEqual(TEXT("Accumulator remains zero"), Accumulator.GetAccumulatedDistance(), 0.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepAccumulatesMovementTest,
    "JM.Footstep.Distance.AccumulatesMovement",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepAccumulatesMovementTest::RunTest(const FString& Parameters)
{
    FJMFootstepDistanceAccumulator Accumulator;
    TestEqual(TEXT("Partial movement does not step"), Accumulator.AddMovement(40.0f, true, 100.0f, 500.0f, 2), 0);
    TestEqual(TEXT("Partial movement accumulates"), Accumulator.GetAccumulatedDistance(), 40.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepTriggersAtThresholdTest,
    "JM.Footstep.Distance.TriggersAtThreshold",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepTriggersAtThresholdTest::RunTest(const FString& Parameters)
{
    FJMFootstepDistanceAccumulator Accumulator;
    TestEqual(TEXT("Exact threshold emits one step"), Accumulator.AddMovement(100.0f, true, 100.0f, 500.0f, 2), 1);
    TestEqual(TEXT("Exact threshold leaves no remainder"), Accumulator.GetAccumulatedDistance(), 0.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepPreservesRemainderTest,
    "JM.Footstep.Distance.PreservesRemainder",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepPreservesRemainderTest::RunTest(const FString& Parameters)
{
    FJMFootstepDistanceAccumulator Accumulator;
    TestEqual(TEXT("Threshold crossing emits one step"), Accumulator.AddMovement(125.0f, true, 100.0f, 500.0f, 2), 1);
    TestEqual(TEXT("Excess distance is preserved"), Accumulator.GetAccumulatedDistance(), 25.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepTeleportDoesNotSpamTest,
    "JM.Footstep.Distance.TeleportDoesNotSpam",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepTeleportDoesNotSpamTest::RunTest(const FString& Parameters)
{
    FJMFootstepDistanceAccumulator Accumulator;
    TestEqual(TEXT("Teleport emits no steps"), Accumulator.AddMovement(1000.0f, true, 100.0f, 500.0f, 2), 0);
    TestEqual(TEXT("Teleport resets pending distance"), Accumulator.GetAccumulatedDistance(), 0.0f);
    TestEqual(TEXT("Large non-teleport delta respects cap"), Accumulator.AddMovement(400.0f, true, 100.0f, 500.0f, 2), 2);
    TestTrue(TEXT("Discarded overflow cannot spill into later frames"), Accumulator.GetAccumulatedDistance() < 100.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepWalkStateTest,
    "JM.Footstep.State.Walk",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepWalkStateTest::RunTest(const FString& Parameters)
{
    TestEqual(
        TEXT("Grounded speed below run threshold is Walk"),
        FJMFootstepRuntimeLogic::ResolveLocomotionState(180.0f, false, true, 10.0f, 325.0f),
        EJMFootstepLocomotionState::Walk);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepRunStateTest,
    "JM.Footstep.State.Run",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepRunStateTest::RunTest(const FString& Parameters)
{
    TestEqual(
        TEXT("Grounded speed at run threshold is Run"),
        FJMFootstepRuntimeLogic::ResolveLocomotionState(325.0f, false, true, 10.0f, 325.0f),
        EJMFootstepLocomotionState::Run);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepCrouchStateTest,
    "JM.Footstep.State.Crouch",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepCrouchStateTest::RunTest(const FString& Parameters)
{
    TestEqual(
        TEXT("Crouch takes precedence over run speed"),
        FJMFootstepRuntimeLogic::ResolveLocomotionState(400.0f, true, true, 10.0f, 325.0f),
        EJMFootstepLocomotionState::CrouchWalk);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepFallingBlocksTest,
    "JM.Footstep.State.FallingBlocksFootstep",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepFallingBlocksTest::RunTest(const FString& Parameters)
{
    TestEqual(
        TEXT("Airborne movement resolves to Idle"),
        FJMFootstepRuntimeLogic::ResolveLocomotionState(400.0f, false, false, 10.0f, 325.0f),
        EJMFootstepLocomotionState::Idle);

    FJMFootstepDistanceAccumulator Accumulator;
    Accumulator.AddMovement(75.0f, true, 100.0f, 500.0f, 2);
    TestEqual(TEXT("Airborne update emits no steps"), Accumulator.AddMovement(100.0f, false, 100.0f, 500.0f, 2), 0);
    TestEqual(TEXT("Airborne update clears pending distance"), Accumulator.GetAccumulatedDistance(), 0.0f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepMissingPhysicalMaterialTest,
    "JM.Footstep.Surface.MissingPhysicalMaterialSafe",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepMissingPhysicalMaterialTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSet> Set(NewObject<UJMFootstepSet>());
    TStrongObjectPtr<UJMFootstepSurfaceProfile> DefaultProfile(NewObject<UJMFootstepSurfaceProfile>());
    Set->DefaultProfile = DefaultProfile.Get();
    bool bUsedFallback = false;
    TestEqual(TEXT("Default surface safely resolves fallback"), Set->FindProfile(SurfaceType_Default, bUsedFallback), DefaultProfile.Get());
    TestTrue(TEXT("Fallback is reported"), bUsedFallback);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepMissingProfileFallbackTest,
    "JM.Footstep.Surface.MissingProfileUsesFallback",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepMissingProfileFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSet> Set(NewObject<UJMFootstepSet>());
    TStrongObjectPtr<UJMFootstepSurfaceProfile> DefaultProfile(NewObject<UJMFootstepSurfaceProfile>());
    Set->DefaultProfile = DefaultProfile.Get();
    bool bUsedFallback = false;
    TestEqual(TEXT("Unmapped surface resolves default profile"), Set->FindProfile(SurfaceType1, bUsedFallback), DefaultProfile.Get());
    TestTrue(TEXT("Unmapped surface reports fallback"), bUsedFallback);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepEmptySoundArrayTest,
    "JM.Footstep.Sound.EmptyArraySafe",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepEmptySoundArrayTest::RunTest(const FString& Parameters)
{
    TestEqual(TEXT("Empty array returns INDEX_NONE"), FJMFootstepRuntimeLogic::SelectSoundIndex(0, INDEX_NONE, 7), INDEX_NONE);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepAvoidRepeatTest,
    "JM.Footstep.Sound.AvoidImmediateRepeat",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepAvoidRepeatTest::RunTest(const FString& Parameters)
{
    TestNotEqual(TEXT("Two sounds avoid the previous index"), FJMFootstepRuntimeLogic::SelectSoundIndex(2, 1, 1), 1);
    TestNotEqual(TEXT("Three sounds avoid the previous index"), FJMFootstepRuntimeLogic::SelectSoundIndex(3, 1, 1), 1);
    TestEqual(TEXT("Single sound remains selectable"), FJMFootstepRuntimeLogic::SelectSoundIndex(1, 0, 99), 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepEndPlaySafeTest,
    "JM.Footstep.Cleanup.EndPlaySafe",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepEndPlaySafeTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepComponent> Component(NewObject<UJMFootstepComponent>());
    Component->ResetFootstepState();
    Component->Deactivate();
    Component->ResetFootstepState();
    TestEqual(TEXT("Cleanup leaves no accumulated distance"), Component->GetAccumulatedDistance(), 0.0f);
    TestEqual(TEXT("Cleanup returns state to Idle"), Component->GetCurrentLocomotionState(), EJMFootstepLocomotionState::Idle);
    return true;
}

namespace
{
    USoundWave* AddTestSound(FJMFootstepSoundVariant& Variant)
    {
        USoundWave* Sound = NewObject<USoundWave>();
        Variant.Sounds.Add(Sound);
        return Sound;
    }

    bool ResolveTestVariant(
        const UJMFootstepSurfaceProfile* Profile,
        const EJMFootstepLocomotionState RequestedState,
        FJMFootstepSoundVariant& OutVariant,
        EJMFootstepLocomotionState& OutSelectedState,
        bool& bOutFallback,
        bool& bOutLegacy)
    {
        return Profile->ResolveVariant(
            RequestedState,
            OutVariant,
            OutSelectedState,
            bOutFallback,
            bOutLegacy);
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepWalkVariantTest,
    "JM.Footstep.SoundVariant.WalkUsesWalkVariant",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepWalkVariantTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = AddTestSound(Profile->WalkVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = true;
    bool bLegacy = true;
    TestTrue(TEXT("Walk variant resolves"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Walk, Resolved, Selected, bFallback, bLegacy));
    TestTrue(TEXT("Walk sound selected"), Resolved.Sounds[0].Get() == Expected);
    TestEqual(TEXT("Selected state is Walk"), Selected, EJMFootstepLocomotionState::Walk);
    TestFalse(TEXT("Direct Walk is not fallback"), bFallback);
    TestFalse(TEXT("Direct Walk is not legacy"), bLegacy);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepRunVariantTest,
    "JM.Footstep.SoundVariant.RunUsesRunVariant",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepRunVariantTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = AddTestSound(Profile->RunVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = true;
    bool bLegacy = true;
    TestTrue(TEXT("Run variant resolves"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Run, Resolved, Selected, bFallback, bLegacy));
    TestTrue(TEXT("Run sound selected"), Resolved.Sounds[0].Get() == Expected);
    TestEqual(TEXT("Selected state is Run"), Selected, EJMFootstepLocomotionState::Run);
    TestFalse(TEXT("Direct Run is not fallback"), bFallback);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepCrouchVariantTest,
    "JM.Footstep.SoundVariant.CrouchUsesCrouchVariant",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepCrouchVariantTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = AddTestSound(Profile->CrouchWalkVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = true;
    bool bLegacy = true;
    TestTrue(TEXT("Crouch variant resolves"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::CrouchWalk, Resolved, Selected, bFallback, bLegacy));
    TestTrue(TEXT("Crouch sound selected"), Resolved.Sounds[0].Get() == Expected);
    TestEqual(TEXT("Selected state is CrouchWalk"), Selected, EJMFootstepLocomotionState::CrouchWalk);
    TestFalse(TEXT("Direct Crouch is not fallback"), bFallback);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepRunVariantFallbackTest,
    "JM.Footstep.SoundVariant.RunFallsBackToWalk",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepRunVariantFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = AddTestSound(Profile->WalkVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = false;
    bool bLegacy = true;
    TestTrue(TEXT("Run falls back to Walk"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Run, Resolved, Selected, bFallback, bLegacy));
    TestTrue(TEXT("Walk fallback sound selected"), Resolved.Sounds[0].Get() == Expected);
    TestEqual(TEXT("Selected variant state is Walk"), Selected, EJMFootstepLocomotionState::Walk);
    TestTrue(TEXT("Fallback is reported"), bFallback);
    TestFalse(TEXT("Walk fallback is not legacy"), bLegacy);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepCrouchVariantFallbackTest,
    "JM.Footstep.SoundVariant.CrouchFallsBackToWalk",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepCrouchVariantFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    AddTestSound(Profile->WalkVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = false;
    bool bLegacy = true;
    TestTrue(TEXT("Crouch falls back to Walk"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::CrouchWalk, Resolved, Selected, bFallback, bLegacy));
    TestEqual(TEXT("Selected variant state is Walk"), Selected, EJMFootstepLocomotionState::Walk);
    TestTrue(TEXT("Fallback is reported"), bFallback);
    TestFalse(TEXT("Walk fallback is not legacy"), bLegacy);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepLegacyVariantFallbackTest,
    "JM.Footstep.SoundVariant.WalkFallsBackToLegacy",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepLegacyVariantFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* LegacySound = NewObject<USoundWave>();
    Profile->Sounds.Add(LegacySound);
    Profile->VolumeMin = 0.42f;
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = false;
    bool bLegacy = false;
    TestTrue(TEXT("Walk falls back to legacy"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Walk, Resolved, Selected, bFallback, bLegacy));
    TestTrue(TEXT("Legacy sound copied"), Resolved.Sounds[0].Get() == LegacySound);
    TestEqual(TEXT("Legacy variation copied"), Resolved.VolumeMin, 0.42f);
    TestTrue(TEXT("Fallback is reported"), bFallback);
    TestTrue(TEXT("Legacy is reported"), bLegacy);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepEmptyVariantTest,
    "JM.Footstep.SoundVariant.EmptyVariantSafe",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepEmptyVariantTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Walk;
    bool bFallback = false;
    bool bLegacy = false;
    TestFalse(TEXT("Completely empty profile does not resolve"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Run, Resolved, Selected, bFallback, bLegacy));
    TestEqual(TEXT("Failed resolution returns empty sounds"), Resolved.Sounds.Num(), 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepNullVariantSoundTest,
    "JM.Footstep.SoundVariant.NullSoundsIgnored",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepNullVariantSoundTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    Profile->RunVariant.Sounds.Add(nullptr);
    AddTestSound(Profile->WalkVariant);
    FJMFootstepSoundVariant Resolved;
    EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
    bool bFallback = false;
    bool bLegacy = false;
    TestTrue(TEXT("Null-only Run falls back safely"), ResolveTestVariant(Profile.Get(), EJMFootstepLocomotionState::Run, Resolved, Selected, bFallback, bLegacy));
    TestEqual(TEXT("Walk is selected after null-only Run"), Selected, EJMFootstepLocomotionState::Walk);
    TestEqual(TEXT("Only valid sounds are counted"), Resolved.GetValidSoundCount(), 1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepWalkRepeatHistoryTest,
    "JM.Footstep.SoundVariant.WalkRepeatHistoryIndependent",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepWalkRepeatHistoryTest::RunTest(const FString& Parameters)
{
    FJMFootstepVariantSoundHistory History;
    History.SetLastIndex(EJMFootstepLocomotionState::Walk, false, 1);
    History.SetLastIndex(EJMFootstepLocomotionState::Run, false, 0);
    TestEqual(TEXT("Walk keeps its own previous sound"), History.GetLastIndex(EJMFootstepLocomotionState::Walk, false), 1);
    TestEqual(TEXT("Walk history does not overwrite Run"), History.GetLastIndex(EJMFootstepLocomotionState::Run, false), 0);
    TestNotEqual(
        TEXT("Walk repeat selection avoids its own previous sound"),
        FJMFootstepRuntimeLogic::SelectSoundIndex(2, History.GetLastIndex(EJMFootstepLocomotionState::Walk, false), 1),
        1);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepRunRepeatHistoryTest,
    "JM.Footstep.SoundVariant.RunRepeatHistoryIndependent",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepRunRepeatHistoryTest::RunTest(const FString& Parameters)
{
    FJMFootstepVariantSoundHistory History;
    History.SetLastIndex(EJMFootstepLocomotionState::Walk, false, 0);
    History.SetLastIndex(EJMFootstepLocomotionState::Run, false, 1);
    TestEqual(TEXT("Run keeps its own previous sound"), History.GetLastIndex(EJMFootstepLocomotionState::Run, false), 1);
    TestNotEqual(
        TEXT("Run repeat selection avoids its own previous sound"),
        FJMFootstepRuntimeLogic::SelectSoundIndex(2, History.GetLastIndex(EJMFootstepLocomotionState::Run, false), 1),
        1);

    History.SetLastIndex(EJMFootstepLocomotionState::Walk, true, 7);
    TestEqual(TEXT("Legacy history has a separate slot"), History.GetLastIndex(EJMFootstepLocomotionState::Walk, true), 7);
    TestEqual(TEXT("Legacy history does not overwrite Walk variant"), History.GetLastIndex(EJMFootstepLocomotionState::Walk, false), 0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepContextOverrideVariantTest,
    "JM.Footstep.SoundVariant.ContextOverrideUsesRequestedState",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepContextOverrideVariantTest::RunTest(const FString& Parameters)
{
    FJMFootstepContext Context;
    Context.bOverrideLocomotionState = true;
    Context.LocomotionState = EJMFootstepLocomotionState::CrouchWalk;
    TestEqual(
        TEXT("Context override wins over detected state"),
        FJMFootstepRuntimeLogic::ResolveRequestedLocomotionState(Context, EJMFootstepLocomotionState::Run),
        EJMFootstepLocomotionState::CrouchWalk);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepWalkOnlyProfileSupportsAllGaitsTest,
    "JM.Footstep.SoundVariant.WalkOnlyProfileSupportsAllGaits",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepWalkOnlyProfileSupportsAllGaitsTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = AddTestSound(Profile->WalkVariant);

    for (const EJMFootstepLocomotionState RequestedState :
        { EJMFootstepLocomotionState::Walk, EJMFootstepLocomotionState::Run, EJMFootstepLocomotionState::CrouchWalk })
    {
        FJMFootstepSoundVariant Resolved;
        EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
        bool bFallback = false;
        bool bLegacy = false;
        TestTrue(TEXT("Walk-only profile resolves every moving gait"), ResolveTestVariant(
            Profile.Get(), RequestedState, Resolved, Selected, bFallback, bLegacy));
        TestTrue(TEXT("Every moving gait selects the Walk sound"), Resolved.Sounds[0].Get() == Expected);
        TestEqual(TEXT("Every moving gait selects the Walk variant"), Selected, EJMFootstepLocomotionState::Walk);
        TestEqual(TEXT("Only non-Walk requests report variant fallback"), bFallback, RequestedState != EJMFootstepLocomotionState::Walk);
        TestFalse(TEXT("Walk-only profile does not use Legacy"), bLegacy);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepRunAndCrouchLegacyFallbackTest,
    "JM.Footstep.SoundVariant.RunAndCrouchFallBackToLegacy",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepRunAndCrouchLegacyFallbackTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    USoundWave* Expected = NewObject<USoundWave>();
    Profile->Sounds.Add(Expected);

    for (const EJMFootstepLocomotionState RequestedState :
        { EJMFootstepLocomotionState::Run, EJMFootstepLocomotionState::CrouchWalk })
    {
        FJMFootstepSoundVariant Resolved;
        EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
        bool bFallback = false;
        bool bLegacy = false;
        TestTrue(TEXT("Moving gait resolves Legacy when state and Walk variants are empty"), ResolveTestVariant(
            Profile.Get(), RequestedState, Resolved, Selected, bFallback, bLegacy));
        TestTrue(TEXT("Legacy sound is selected"), Resolved.Sounds[0].Get() == Expected);
        TestTrue(TEXT("Legacy resolution reports fallback"), bFallback);
        TestTrue(TEXT("Legacy resolution is identified"), bLegacy);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepFallbackKeepsRequestedGaitSettingsTest,
    "JM.Footstep.SoundVariant.FallbackKeepsRequestedGaitSettings",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepFallbackKeepsRequestedGaitSettingsTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<UJMFootstepSurfaceProfile> Profile(NewObject<UJMFootstepSurfaceProfile>());
    AddTestSound(Profile->WalkVariant);

    for (const EJMFootstepLocomotionState RequestedState :
        { EJMFootstepLocomotionState::Run, EJMFootstepLocomotionState::CrouchWalk })
    {
        FJMFootstepSoundVariant Resolved;
        EJMFootstepLocomotionState Selected = EJMFootstepLocomotionState::Idle;
        bool bFallback = false;
        bool bLegacy = false;
        TestTrue(TEXT("Requested gait falls back to Walk"), ResolveTestVariant(
            Profile.Get(), RequestedState, Resolved, Selected, bFallback, bLegacy));
        TestEqual(TEXT("Fallback sound source is Walk"), Selected, EJMFootstepLocomotionState::Walk);

        const float StepDistance = FJMFootstepRuntimeLogic::ResolveStepDistance(
            RequestedState, 110.0f, 140.0f, 80.0f);
        const float StateVolume = FJMFootstepRuntimeLogic::ResolveStateVolumeMultiplier(
            RequestedState, 0.75f, 1.0f, 0.35f);
        TestEqual(
            TEXT("Step distance follows requested gait, not selected Walk variant"),
            StepDistance,
            RequestedState == EJMFootstepLocomotionState::Run ? 140.0f : 80.0f);
        TestEqual(
            TEXT("Volume multiplier follows requested gait, not selected Walk variant"),
            StateVolume,
            RequestedState == EJMFootstepLocomotionState::Run ? 1.0f : 0.35f);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMFootstepSurfaceProfileDetailsMetadataTest,
    "JM.Footstep.Editor.SurfaceProfileDetailsMetadata",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMFootstepSurfaceProfileDetailsMetadataTest::RunTest(const FString& Parameters)
{
    const FProperty* WalkVariantProperty =
        FindFProperty<FProperty>(UJMFootstepSurfaceProfile::StaticClass(), GET_MEMBER_NAME_CHECKED(UJMFootstepSurfaceProfile, WalkVariant));
    const FProperty* SoundsProperty =
        FindFProperty<FProperty>(FJMFootstepSoundVariant::StaticStruct(), GET_MEMBER_NAME_CHECKED(FJMFootstepSoundVariant, Sounds));
    const FProperty* VolumeMinProperty =
        FindFProperty<FProperty>(FJMFootstepSoundVariant::StaticStruct(), GET_MEMBER_NAME_CHECKED(FJMFootstepSoundVariant, VolumeMin));

    TestNotNull(TEXT("Walk Variant property exists"), WalkVariantProperty);
    TestNotNull(TEXT("Variant Sounds property exists"), SoundsProperty);
    TestNotNull(TEXT("Variant Volume Min property exists"), VolumeMinProperty);
    if (WalkVariantProperty && SoundsProperty && VolumeMinProperty)
    {
        TestFalse(TEXT("Variant remains nested instead of flattening inner properties"), WalkVariantProperty->HasMetaData(TEXT("ShowOnlyInnerProperties")));
        TestEqual(TEXT("Sounds no longer creates an Audio category"), SoundsProperty->GetMetaData(TEXT("Category")), FString(TEXT("Footstep")));
        TestEqual(TEXT("Variation no longer creates a Variation category"), VolumeMinProperty->GetMetaData(TEXT("Category")), FString(TEXT("Footstep")));
    }
    return true;
}
