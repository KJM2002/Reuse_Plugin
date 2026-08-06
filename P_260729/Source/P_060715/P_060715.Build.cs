// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class P_060715 : ModuleRules
{
	public P_060715(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			"GameplayTags", "JMHideRuntime", "JMHideInteractionIntegration",
			"JMInteraction", "InventorySystem", "JMObjective", "AIModule",
			"ReusableDialogueSystem", "Niagara", "UMG", "JMRoomGridRuntime"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"JMGameplayEvent",
			"NavigationSystem",
			"Slate", "SlateCore"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
