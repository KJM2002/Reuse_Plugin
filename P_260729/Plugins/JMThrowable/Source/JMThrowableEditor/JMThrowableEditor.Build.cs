using UnrealBuildTool;

public class JMThrowableEditor : ModuleRules
{
    public JMThrowableEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine", "UnrealEd", "AssetRegistry",
            "Niagara", "NiagaraEditor", "JMThrowable"
        });
    }
}
