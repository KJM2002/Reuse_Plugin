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
            "NavigationSystem",
            "JMMonsterFrameworkRuntime",
            "StateTreeModule",
            "GameplayStateTreeModule",
            "StateTreeEditorModule",
            "PropertyBindingUtils",
            "AssetRegistry",
            "UnrealEd"
        });

        if (Target.bBuildDeveloperTools)
        {
            PrivateDependencyModuleNames.Add("AutomationController");
        }
    }
}
