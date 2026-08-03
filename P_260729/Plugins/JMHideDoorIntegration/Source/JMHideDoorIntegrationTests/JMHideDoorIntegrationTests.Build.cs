using UnrealBuildTool;

public class JMHideDoorIntegrationTests : ModuleRules
{
    public JMHideDoorIntegrationTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd",
            "JMHideRuntime", "JMDoorRuntime", "JMHideDoorIntegration"
        });
    }
}
