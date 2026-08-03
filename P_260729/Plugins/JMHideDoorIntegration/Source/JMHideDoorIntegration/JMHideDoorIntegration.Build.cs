using UnrealBuildTool;

public class JMHideDoorIntegration : ModuleRules
{
    public JMHideDoorIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "JMHideRuntime", "JMDoorRuntime"
        });
    }
}
