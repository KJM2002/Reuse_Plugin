using UnrealBuildTool;

public class JMRoomGridEditor : ModuleRules
{
    public JMRoomGridEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UnrealEd", "AssetTools", "AssetRegistry",
            "BlueprintGraph", "Kismet", "KismetCompiler", "ToolMenus", "Slate", "SlateCore",
            "PropertyEditor", "JMRoomGridRuntime"
        });
    }
}
