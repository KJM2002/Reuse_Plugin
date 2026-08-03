using UnrealBuildTool;

public class JMFootstepTests : ModuleRules
{
    public JMFootstepTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "JMFootstepRuntime"
        });
    }
}
