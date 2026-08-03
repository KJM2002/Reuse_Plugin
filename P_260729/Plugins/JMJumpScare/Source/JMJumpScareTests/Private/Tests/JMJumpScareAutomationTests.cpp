#include "Misc/AutomationTest.h"

#include "Data/JMJumpScareDefinition.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialInterface.h"
#include "Subsystems/JMJumpScareSubsystem.h"
#include "Types/JMJumpScareEventTags.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMJumpScareDefinitionValidationTest,
    "JM.JumpScare.Definition.Validation",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMJumpScareDefinitionValidationTest::RunTest(const FString& Parameters)
{
    UJMJumpScareDefinition* Definition = NewObject<UJMJumpScareDefinition>();
    TestFalse(TEXT("A 2D image is required"), Definition->IsDefinitionValid());

    Definition->Image = NewObject<UTexture2D>(Definition);
    TestTrue(TEXT("Image with non-negative timing is valid"), Definition->IsDefinitionValid());

    UMaterialInterface* GlitchMaterial = Definition->GlitchMaterial.LoadSynchronous();
    TestNotNull(TEXT("Default /Game/Jumpscare/M_Glitch material loads"), GlitchMaterial);
    if (GlitchMaterial && GlitchMaterial->GetMaterial())
    {
        TestEqual(TEXT("M_Glitch uses the Post Process material domain"), GlitchMaterial->GetMaterial()->MaterialDomain, MD_PostProcess);
    }

    Definition->ImageResolution = FVector2D::ZeroVector;
    TestFalse(TEXT("Zero display resolution is rejected"), Definition->IsDefinitionValid());
    Definition->ImageResolution = FVector2D(1920.0f, 1080.0f);

    Definition->Duration = -1.0f;
    TestFalse(TEXT("Negative duration is rejected"), Definition->IsDefinitionValid());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMJumpScareCompatibilityTransformTest,
    "JM.JumpScare.Compatibility.TransformHelpers",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMJumpScareCompatibilityTransformTest::RunTest(const FString& Parameters)
{
    const FTransform Camera(FRotator(0.0f, 90.0f, 0.0f), FVector(10.0f, 20.0f, 30.0f));
    const FTransform Result = UJMJumpScareSubsystem::CalculateCameraRelativeTransform(
        Camera, 100.0f, 20.0f, -5.0f, FRotator::ZeroRotator, FTransform::Identity);
    TestTrue(TEXT("Legacy native transform helper remains stable"), Result.GetLocation().Equals(FVector(-10.0f, 120.0f, 25.0f), 0.01f));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FJMJumpScareEventTagsTest,
    "JM.JumpScare.Events.NativeTags",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMJumpScareEventTagsTest::RunTest(const FString& Parameters)
{
    TestTrue(TEXT("Started event tag registered"), JMJumpScareEventTags::Started.GetTag().IsValid());
    TestTrue(TEXT("Impact event tag registered"), JMJumpScareEventTags::Impact.GetTag().IsValid());
    TestTrue(TEXT("Exiting event tag registered"), JMJumpScareEventTags::Exiting.GetTag().IsValid());
    TestTrue(TEXT("Finished event tag registered"), JMJumpScareEventTags::Finished.GetTag().IsValid());
    TestTrue(TEXT("Cancelled event tag registered"), JMJumpScareEventTags::Cancelled.GetTag().IsValid());
    TestTrue(TEXT("Failed event tag registered"), JMJumpScareEventTags::Failed.GetTag().IsValid());
    return true;
}

#endif
