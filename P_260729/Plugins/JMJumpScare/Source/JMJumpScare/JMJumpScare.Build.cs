using UnrealBuildTool;

public class JMJumpScare : ModuleRules
{
    public JMJumpScare(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "GameplayTags", "DeveloperSettings", "JMGameplayEvent",
            "UMG", "Slate", "SlateCore"
        });
    }
}
