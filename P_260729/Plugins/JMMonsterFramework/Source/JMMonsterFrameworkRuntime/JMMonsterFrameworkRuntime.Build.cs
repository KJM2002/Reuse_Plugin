using UnrealBuildTool;

public class JMMonsterFrameworkRuntime : ModuleRules
{
    public JMMonsterFrameworkRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "AIModule",
            "StateTreeModule",
            "GameplayStateTreeModule"
        });

        // Navigation remains an implementation detail; StateTree types are public node/runtime surfaces.
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "NavigationSystem"
        });
    }
}
