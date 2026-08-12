using UnrealBuildTool;

public class P_060715Tests : ModuleRules
{
    public P_060715Tests(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "ApplicationCore",
			"AIModule",
			"AIGraph",
			"AssetRegistry",
			"BehaviorTreeEditor",
			"BlueprintGraph",
            "Engine",
            "InputCore",
            "UnrealEd",
            "JMInteraction",
            "JMReconRuntime",
            "JMReconGameplayIntegration",
            "JMDoorRuntime",
            "JMDoorReconIntegration",
			"P_060715",
			"JMRoomGridRuntime",
            "JMHideRuntime",
			"JMHideInteractionIntegration",
			"InventorySystem",
			"KismetCompiler",
			"Niagara"
        });
    }
}
