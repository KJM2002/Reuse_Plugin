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
            "AIModule",
            "StateTreeModule",
            "GameplayStateTreeModule"
        });
    }
}
