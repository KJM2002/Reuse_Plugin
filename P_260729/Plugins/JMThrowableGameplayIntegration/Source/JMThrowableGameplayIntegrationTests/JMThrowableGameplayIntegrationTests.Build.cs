using UnrealBuildTool;

public class JMThrowableGameplayIntegrationTests : ModuleRules
{
    public JMThrowableGameplayIntegrationTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine", "JMThrowable", "InventorySystem", "JMThrowableGameplayIntegration"
        });
    }
}
