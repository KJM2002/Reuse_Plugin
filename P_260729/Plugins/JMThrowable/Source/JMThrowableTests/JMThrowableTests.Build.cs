using UnrealBuildTool;

public class JMThrowableTests : ModuleRules
{
    public JMThrowableTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine", "Niagara", "JMThrowable"
        });
    }
}
