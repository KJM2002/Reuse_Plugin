using UnrealBuildTool;

public class JMRoomGridRuntime : ModuleRules
{
    public JMRoomGridRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "DeveloperSettings", "GameplayTags"
        });
    }
}
