using UnrealBuildTool;

public class JMPhysicalGrabberTests : ModuleRules
{
    public JMPhysicalGrabberTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "JMPhysicalGrabber"
        });
    }
}
