using UnrealBuildTool;

public class JMRoomGridTests : ModuleRules
{
    public JMRoomGridTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd", "JMRoomGridRuntime"
        });
    }
}
