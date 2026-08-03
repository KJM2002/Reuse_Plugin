using UnrealBuildTool;

public class JMReconGameplayIntegration : ModuleRules
{
    public JMReconGameplayIntegration(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings",
            "InputCore",
            "UMG",
            "Slate",
            "SlateCore",
            "JMInteraction",
            "JMReconRuntime"
        });
    }
}
