using UnrealBuildTool;

public class JMMonsterFrameworkTests : ModuleRules
{
    public JMMonsterFrameworkTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "AIModule",
            "JMMonsterFrameworkRuntime"
        });
    }
}
