using UnrealBuildTool;

public class JMHideRuntime : ModuleRules
{
    public JMHideRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "DeveloperSettings", "GameplayTags"
        });
    }
}
