using UnrealBuildTool;

public class JMPhysicalGrabber : ModuleRules
{
    public JMPhysicalGrabber(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "CableComponent"
        });
    }
}
