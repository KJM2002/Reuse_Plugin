using UnrealBuildTool;

public class JMHideInteractionIntegration : ModuleRules
{
    public JMHideInteractionIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "GameplayTags", "JMHideRuntime", "JMInteraction"
        });
    }
}
