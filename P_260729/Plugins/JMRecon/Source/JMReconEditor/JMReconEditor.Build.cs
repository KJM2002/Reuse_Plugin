using UnrealBuildTool;

public class JMReconEditor : ModuleRules
{
    public JMReconEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd", "JMReconRuntime", "ComponentVisualizers"
        });
    }
}
