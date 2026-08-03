using UnrealBuildTool;

public class JMObjective : ModuleRules
{
    public JMObjective(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "GameplayTags", "JMGameplayEvent", "UMG", "DeveloperSettings"
        });
    }
}
