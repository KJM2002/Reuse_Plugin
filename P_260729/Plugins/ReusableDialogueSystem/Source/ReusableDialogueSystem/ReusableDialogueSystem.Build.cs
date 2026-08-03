using UnrealBuildTool;

public class ReusableDialogueSystem : ModuleRules
{
    public ReusableDialogueSystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "UMG", "Slate", "SlateCore",
            "InputCore", "GameplayTags", "DeveloperSettings", "JMInteraction", "JMGameplayEvent"
        });
    }
}
