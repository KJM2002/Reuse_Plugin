using UnrealBuildTool;

public class JMDoorRuntime : ModuleRules
{
    public JMDoorRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "DeveloperSettings",
            "GameplayTags",
            "JMGameplayEvent"
        });

        PrivateDependencyModuleNames.Add("InputCore");
    }
}
