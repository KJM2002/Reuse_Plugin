using UnrealBuildTool;

public class JMObjectiveTests : ModuleRules
{
    public JMObjectiveTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "GameplayTags", "JMGameplayEvent", "JMObjective"
        });
    }
}
