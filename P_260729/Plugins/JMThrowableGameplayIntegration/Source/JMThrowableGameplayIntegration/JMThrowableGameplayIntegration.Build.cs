using UnrealBuildTool;

public class JMThrowableGameplayIntegration : ModuleRules
{
    public JMThrowableGameplayIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine", "GameplayTags", "EnhancedInput", "UMG", "Slate", "SlateCore",
            "JMThrowable", "InventorySystem"
        });
    }
}
