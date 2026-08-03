using UnrealBuildTool;

public class JMJumpScareTests : ModuleRules
{
    public JMJumpScareTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "GameplayTags", "JMGameplayEvent", "JMJumpScare", "UnrealEd"
        });
    }
}
