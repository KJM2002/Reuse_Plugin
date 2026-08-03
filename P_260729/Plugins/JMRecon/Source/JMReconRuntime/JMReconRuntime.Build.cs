using UnrealBuildTool;

public class JMReconRuntime : ModuleRules
{
    public JMReconRuntime(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "DeveloperSettings", "AudioMixer"
        });
    }
}
