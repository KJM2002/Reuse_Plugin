using UnrealBuildTool;

public class JMReconTests : ModuleRules
{
    public JMReconTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd", "JMReconRuntime"
        });
    }
}
