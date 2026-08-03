using UnrealBuildTool;

public class JMDoorReconIntegrationTests : ModuleRules
{
    public JMDoorReconIntegrationTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd",
            "JMDoorRuntime", "JMReconRuntime", "JMDoorReconIntegration"
        });
    }
}
