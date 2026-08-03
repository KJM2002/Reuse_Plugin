using UnrealBuildTool;

public class JMReconGameplayIntegrationTests : ModuleRules
{
    public JMReconGameplayIntegrationTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "UMG",
            "UnrealEd",
            "JMInteraction",
            "JMReconRuntime",
            "JMReconGameplayIntegration"
        });
    }
}
