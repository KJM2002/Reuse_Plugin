using UnrealBuildTool;

public class JMDoorReconIntegration : ModuleRules
{
    public JMDoorReconIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "DeveloperSettings",
            "JMDoorRuntime", "JMReconRuntime"
        });
    }
}
