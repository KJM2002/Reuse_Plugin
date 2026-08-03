using UnrealBuildTool;

public class JMThrowable : ModuleRules
{
    public JMThrowable(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine", "DeveloperSettings", "EnhancedInput", "InputCore",
            "ProceduralMeshComponent", "Niagara", "AIModule", "GameplayTags", "JMGameplayEvent"
        });
    }
}
