using UnrealBuildTool;

public class JMDoorTests : ModuleRules
{
    public JMDoorTests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "JMDoorRuntime",
            "FunctionalTesting",
            "UnrealEd",
            "Kismet",
            "AssetRegistry",
            "PropertyEditor",
            "Slate",
            "SlateCore"
        });
    }
}
