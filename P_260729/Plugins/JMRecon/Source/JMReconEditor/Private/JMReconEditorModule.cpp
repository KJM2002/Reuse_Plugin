#include "Components/JMReconTargetComponent.h"
#include "ComponentVisualizer.h"
#include "Data/JMReconDefinition.h"
#include "Editor/UnrealEdEngine.h"
#include "Modules/ModuleManager.h"
#include "SceneManagement.h"
#include "UnrealEdGlobals.h"

namespace
{
    class FJMReconTargetComponentVisualizer final : public FComponentVisualizer
    {
    public:
        virtual void DrawVisualization(
            const UActorComponent* Component,
            const FSceneView* View,
            FPrimitiveDrawInterface* PDI) override
        {
            const UJMReconTargetComponent* Target = Cast<const UJMReconTargetComponent>(Component);
            if (!Target)
            {
                return;
            }

            DrawAnchor(PDI, Target->GetPlayerWorldTransform(), FColor::Green, 20.0f);
            DrawAnchor(PDI, Target->GetListenCameraWorldTransform(), FColor::Cyan, 16.0f);
            DrawAnchor(PDI, Target->GetPeekCameraWorldTransform(), FColor::Yellow, 16.0f);

            const FVector Origin = Target->GetComponentLocation();
            PDI->DrawLine(Origin, Target->GetPlayerWorldTransform().GetLocation(), FColor::Green, SDPG_World, 1.0f);
            PDI->DrawLine(Origin, Target->GetListenCameraWorldTransform().GetLocation(), FColor::Cyan, SDPG_World, 1.0f);
            PDI->DrawLine(Origin, Target->GetPeekCameraWorldTransform().GetLocation(), FColor::Yellow, SDPG_World, 1.0f);

            if (const UJMReconDefinition* Definition = Target->GetEffectiveDefinition())
            {
                const FTransform Peek = Target->GetPeekCameraWorldTransform();
                const FVector Forward = Peek.GetRotation().GetForwardVector();
                const FVector Right = Peek.GetRotation().GetRightVector();
                const FVector Up = Peek.GetRotation().GetUpVector();
                const float RayLength = 80.0f;
                const float YawOffset = FMath::Tan(FMath::DegreesToRadians(Definition->CameraYawLimit)) * RayLength;
                const float PitchOffset = FMath::Tan(FMath::DegreesToRadians(Definition->CameraPitchLimit)) * RayLength;
                const FVector Start = Peek.GetLocation();
                PDI->DrawLine(Start, Start + Forward * RayLength + Right * YawOffset, FColor::Orange, SDPG_World);
                PDI->DrawLine(Start, Start + Forward * RayLength - Right * YawOffset, FColor::Orange, SDPG_World);
                PDI->DrawLine(Start, Start + Forward * RayLength + Up * PitchOffset, FColor::Silver, SDPG_World);
                PDI->DrawLine(Start, Start + Forward * RayLength - Up * PitchOffset, FColor::Silver, SDPG_World);
            }
        }

    private:
        static void DrawAnchor(FPrimitiveDrawInterface* PDI, const FTransform& Transform, FColor Color, float Size)
        {
            const FVector Location = Transform.GetLocation();
            DrawWireSphere(PDI, Location, Color, Size, 16, SDPG_World, 1.5f);
            PDI->DrawLine(
                Location,
                Location + Transform.GetRotation().GetForwardVector() * 50.0f,
                Color,
                SDPG_World,
                2.0f);
        }
    };
}

class FJMReconEditorModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        if (GUnrealEd)
        {
            Visualizer = MakeShared<FJMReconTargetComponentVisualizer>();
            GUnrealEd->RegisterComponentVisualizer(UJMReconTargetComponent::StaticClass()->GetFName(), Visualizer);
            Visualizer->OnRegister();
        }
    }

    virtual void ShutdownModule() override
    {
        if (GUnrealEd)
        {
            GUnrealEd->UnregisterComponentVisualizer(UJMReconTargetComponent::StaticClass()->GetFName());
        }
        Visualizer.Reset();
    }

private:
    TSharedPtr<FComponentVisualizer> Visualizer;
};

IMPLEMENT_MODULE(FJMReconEditorModule, JMReconEditor)
