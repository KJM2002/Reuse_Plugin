using UnrealBuildTool;

public class JMFootstepRuntime : ModuleRules
{
    public JMFootstepRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings",
            "PhysicsCore"
        });
    }
}
