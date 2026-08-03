using UnrealBuildTool;

public class JMHideTests : ModuleRules
{
    public JMHideTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd", "GameplayTags", "JMHideRuntime"
        });
    }
}
