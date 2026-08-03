using UnrealBuildTool;

public class JMDoorGameplayIntegration : ModuleRules
{
    public JMDoorGameplayIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "JMDoorRuntime",
            "JMInteraction",
            "InventorySystem"
        });
    }
}
