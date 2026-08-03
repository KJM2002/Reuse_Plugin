#include "Modules/ModuleManager.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "EdGraphSchema_Niagara.h"
#include "Misc/CommandLine.h"
#include "Misc/PackageName.h"
#include "Misc/Parse.h"
#include "Materials/MaterialInterface.h"
#include "NiagaraConstants.h"
#include "NiagaraDataInterfaceArrayFloat.h"
#include "NiagaraEmitter.h"
#include "NiagaraEmitterFactoryNew.h"
#include "NiagaraGraph.h"
#include "NiagaraNodeAssignment.h"
#include "NiagaraNodeFunctionCall.h"
#include "NiagaraNodeOutput.h"
#include "NiagaraRibbonRendererProperties.h"
#include "NiagaraScript.h"
#include "NiagaraScriptSource.h"
#include "NiagaraSystem.h"
#include "NiagaraSystemFactoryNew.h"
#include "UObject/SavePackage.h"
#include "ViewModels/Stack/NiagaraParameterHandle.h"
#include "ViewModels/Stack/NiagaraStackGraphUtilities.h"

namespace JMThrowableNiagaraAssetGenerator
{
    constexpr TCHAR EmitterPackageName[] =
        TEXT("/JMThrowable/Effects/NE_JMThrowablePathRibbon");
    constexpr TCHAR MovingDotPackageName[] =
        TEXT("/JMThrowable/Effects/NE_JMThrowableMovingDot");
    constexpr TCHAR ImpactDotPackageName[] =
        TEXT("/JMThrowable/Effects/NE_JMThrowableImpactDot");
    constexpr TCHAR RibbonMaterialPackageName[] =
        TEXT("/JMThrowable/Materials/M_JMThrowableRibbon_Niagara");
    constexpr TCHAR SystemPackageName[] =
        TEXT("/JMThrowable/Effects/NS_JMThrowableTrajectory");

    bool SaveAsset(UPackage* Package, UObject* Asset)
    {
        if (!Package || !Asset)
        {
            return false;
        }
        const FString Filename = FPackageName::LongPackageNameToFilename(
            Package->GetName(), FPackageName::GetAssetPackageExtension());
        FSavePackageArgs SaveArgs;
        SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
        SaveArgs.SaveFlags = SAVE_NoError;
        return UPackage::SavePackage(Package, Asset, *Filename, SaveArgs);
    }

    UNiagaraNodeOutput* FindOutput(
        FVersionedNiagaraEmitterData& EmitterData,
        ENiagaraScriptUsage Usage)
    {
        UNiagaraScript* Script = Usage == ENiagaraScriptUsage::ParticleSpawnScript
            ? EmitterData.SpawnScriptProps.Script
            : EmitterData.UpdateScriptProps.Script;
        UNiagaraScriptSource* Source =
            Script ? Cast<UNiagaraScriptSource>(Script->GetLatestSource()) : nullptr;
        if (!Source || !Source->NodeGraph)
        {
            return nullptr;
        }
        for (UEdGraphNode* Node : Source->NodeGraph->Nodes)
        {
            UNiagaraNodeOutput* Output = Cast<UNiagaraNodeOutput>(Node);
            if (Output && Output->GetUsage() == Usage
                && Output->GetUsageId() == Script->GetUsageId())
            {
                return Output;
            }
        }
        return nullptr;
    }

    void BindPositionArray(UNiagaraNodeFunctionCall& AssignmentNode)
    {
        UNiagaraScript* SelectPositionScript = LoadObject<UNiagaraScript>(
            nullptr,
            TEXT("/Niagara/DynamicInputs/Arrays/SelectPositionFromArray."
                 "SelectPositionFromArray"));
        if (!SelectPositionScript)
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: SelectPositionFromArray is missing."));
            return;
        }

        const FNiagaraParameterHandle PositionHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(TEXT("Position"));
        const FNiagaraParameterHandle AliasedPositionHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                PositionHandle, &AssignmentNode);
        UEdGraphPin& PositionPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                AssignmentNode,
                AliasedPositionHandle,
                FNiagaraTypeDefinition::GetPositionDef(),
                FGuid(),
                FGuid());

        UNiagaraNodeFunctionCall* DynamicInputNode = nullptr;
        FNiagaraStackGraphUtilities::SetDynamicInputForFunctionInput(
            PositionPin, SelectPositionScript, DynamicInputNode);
        if (!DynamicInputNode)
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: failed to create array dynamic input."));
            return;
        }

        const FNiagaraVariable PathArray(
            FNiagaraTypeDefinition(UNiagaraDataInterfaceArrayPosition::StaticClass()),
            TEXT("User.PathPoints"));
        const FNiagaraVariable ExecutionIndex = SYS_PARAM_ENGINE_EXEC_INDEX;
        const TSet<FNiagaraVariableBase> KnownParameters = {
            FNiagaraVariableBase(PathArray),
            FNiagaraVariableBase(ExecutionIndex)};

        const FNiagaraParameterHandle ArrayHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(TEXT("Array"));
        const FNiagaraParameterHandle AliasedArrayHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                ArrayHandle, DynamicInputNode);
        UEdGraphPin& ArrayPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                *DynamicInputNode,
                AliasedArrayHandle,
                PathArray.GetType(),
                FGuid(),
                FGuid());
        FNiagaraStackGraphUtilities::SetLinkedParameterValueForFunctionInput(
            ArrayPin, PathArray, KnownParameters);

        const FNiagaraParameterHandle IndexHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(TEXT("Index"));
        const FNiagaraParameterHandle AliasedIndexHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                IndexHandle, DynamicInputNode);
        UEdGraphPin& IndexPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                *DynamicInputNode,
                AliasedIndexHandle,
                FNiagaraTypeDefinition::GetIntDef(),
                FGuid(),
                FGuid());
        FNiagaraStackGraphUtilities::SetLinkedParameterValueForFunctionInput(
            IndexPin, ExecutionIndex, KnownParameters);
    }

    void BindLinkedFloat(
        UNiagaraNodeFunctionCall& AssignmentNode,
        FName InputName,
        const FNiagaraVariable& LinkedParameter)
    {
        const FNiagaraParameterHandle InputHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(InputName);
        const FNiagaraParameterHandle AliasedInputHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                InputHandle, &AssignmentNode);
        UEdGraphPin& InputPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                AssignmentNode,
                AliasedInputHandle,
                FNiagaraTypeDefinition::GetFloatDef(),
                FGuid(),
                FGuid());
        const TSet<FNiagaraVariableBase> KnownParameters = {
            FNiagaraVariableBase(LinkedParameter)};
        FNiagaraStackGraphUtilities::SetLinkedParameterValueForFunctionInput(
            InputPin, LinkedParameter, KnownParameters);
    }

    void BindLinkedPosition(
        UNiagaraNodeFunctionCall& AssignmentNode,
        const FNiagaraVariable& LinkedParameter)
    {
        const FNiagaraParameterHandle InputHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(TEXT("Position"));
        const FNiagaraParameterHandle AliasedInputHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                InputHandle, &AssignmentNode);
        UEdGraphPin& InputPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                AssignmentNode,
                AliasedInputHandle,
                FNiagaraTypeDefinition::GetPositionDef(),
                FGuid(),
                FGuid());
        const TSet<FNiagaraVariableBase> KnownParameters = {
            FNiagaraVariableBase(LinkedParameter)};
        FNiagaraStackGraphUtilities::SetLinkedParameterValueForFunctionInput(
            InputPin, LinkedParameter, KnownParameters);
    }

    void BindLinkedColor(
        UNiagaraNodeFunctionCall& AssignmentNode,
        const FNiagaraVariable& LinkedParameter)
    {
        const FNiagaraParameterHandle InputHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(TEXT("Color"));
        const FNiagaraParameterHandle AliasedInputHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                InputHandle, &AssignmentNode);
        UEdGraphPin& InputPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                AssignmentNode,
                AliasedInputHandle,
                FNiagaraTypeDefinition::GetColorDef(),
                FGuid(),
                FGuid());
        const TSet<FNiagaraVariableBase> KnownParameters = {
            FNiagaraVariableBase(LinkedParameter)};
        FNiagaraStackGraphUtilities::SetLinkedParameterValueForFunctionInput(
            InputPin, LinkedParameter, KnownParameters);
    }

    void SetIntegerInput(
        UNiagaraNodeFunctionCall& FunctionNode,
        FName InputName,
        int32 Value)
    {
        const FNiagaraParameterHandle InputHandle =
            FNiagaraParameterHandle::CreateModuleParameterHandle(InputName);
        const FNiagaraParameterHandle AliasedInputHandle =
            FNiagaraParameterHandle::CreateAliasedModuleParameterHandle(
                InputHandle, &FunctionNode);
        UEdGraphPin& InputPin =
            FNiagaraStackGraphUtilities::GetOrCreateStackFunctionInputOverridePin(
                FunctionNode,
                AliasedInputHandle,
                FNiagaraTypeDefinition::GetIntDef(),
                FGuid(),
                FGuid());
        if (const UEdGraphSchema_Niagara* Schema =
            Cast<UEdGraphSchema_Niagara>(FunctionNode.GetSchema()))
        {
            Schema->TrySetDefaultValue(InputPin, FString::FromInt(Value));
        }
    }

    UMaterialInterface* CreateRibbonMaterial()
    {
        UMaterialInterface* TemplateMaterial = LoadObject<UMaterialInterface>(
            nullptr,
            TEXT("/Niagara/DefaultAssets/DefaultRIbbonMaterial."
                 "DefaultRIbbonMaterial"));
        if (!TemplateMaterial)
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: default Niagara ribbon material is missing."));
            return nullptr;
        }

        UPackage* Package = CreatePackage(RibbonMaterialPackageName);
        Package->FullyLoad();
        UMaterialInterface* Material = Cast<UMaterialInterface>(StaticDuplicateObject(
            TemplateMaterial,
            Package,
            TEXT("M_JMThrowableRibbon_Niagara"),
            RF_Public | RF_Standalone | RF_Transactional));
        if (!Material)
        {
            return nullptr;
        }
        Material->MarkPackageDirty();
        FAssetRegistryModule::AssetCreated(Material);
        return SaveAsset(Package, Material) ? Material : nullptr;
    }

    UNiagaraEmitter* CreatePathEmitter(UMaterialInterface& RibbonMaterial)
    {
        UNiagaraEmitter* TemplateEmitter = LoadObject<UNiagaraEmitter>(
            nullptr,
            TEXT("/Niagara/DefaultAssets/Templates/BehaviorExamples/"
                 "RibbonLinkOrder.RibbonLinkOrder"));
        if (!TemplateEmitter)
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: RibbonLinkOrder template is missing."));
            return nullptr;
        }

        UPackage* Package = CreatePackage(EmitterPackageName);
        Package->FullyLoad();
        UNiagaraEmitter* Emitter = Cast<UNiagaraEmitter>(StaticDuplicateObject(
            TemplateEmitter,
            Package,
            TEXT("NE_JMThrowablePathRibbon"),
            RF_Public | RF_Standalone | RF_Transactional));
        if (!Emitter)
        {
            return nullptr;
        }

        const FGuid VersionGuid = Emitter->GetExposedVersion().VersionGuid;
        FVersionedNiagaraEmitterData* EmitterData = Emitter->GetEmitterData(VersionGuid);
        if (!EmitterData)
        {
            return nullptr;
        }
        EmitterData->bLocalSpace = false;

        const FNiagaraVariable BaseWidth(
            FNiagaraTypeDefinition::GetFloatDef(), TEXT("User.BaseWidth"));
        const FNiagaraVariable BaseColor(
            FNiagaraTypeDefinition::GetColorDef(), TEXT("User.BaseColor"));
        const TArray<FNiagaraVariable> AssignmentVariables = {
            SYS_PARAM_PARTICLES_POSITION,
            SYS_PARAM_PARTICLES_RIBBONWIDTH,
            SYS_PARAM_PARTICLES_COLOR};
        const TArray<FString> AssignmentDefaults = {
            TEXT("(X=0.0,Y=0.0,Z=0.0)"),
            TEXT("10.0"),
            TEXT("(R=1.0,G=1.0,B=1.0,A=0.2)")};
        for (const ENiagaraScriptUsage Usage : {
            ENiagaraScriptUsage::ParticleSpawnScript,
            ENiagaraScriptUsage::ParticleUpdateScript})
        {
            if (UNiagaraNodeOutput* OutputNode = FindOutput(*EmitterData, Usage))
            {
                if (UNiagaraNodeAssignment* Assignment =
                    FNiagaraStackGraphUtilities::AddParameterModuleToStack(
                        AssignmentVariables, *OutputNode, INDEX_NONE, AssignmentDefaults))
                {
                    BindPositionArray(*Assignment);
                    BindLinkedFloat(*Assignment, TEXT("RibbonWidth"), BaseWidth);
                    BindLinkedColor(*Assignment, BaseColor);
                }
            }
        }

        if (UNiagaraScript* EmitterUpdateScript =
            EmitterData->EmitterUpdateScriptProps.Script)
        {
            if (UNiagaraScriptSource* Source =
                Cast<UNiagaraScriptSource>(EmitterUpdateScript->GetLatestSource()))
            {
                TArray<UNiagaraNodeFunctionCall*> SpawnBurstNodes;
                for (UEdGraphNode* Node : Source->NodeGraph->Nodes)
                {
                    UNiagaraNodeFunctionCall* FunctionNode =
                        Cast<UNiagaraNodeFunctionCall>(Node);
                    if (FunctionNode
                        && FunctionNode->GetFunctionName().Contains(
                            TEXT("SpawnBurst"), ESearchCase::IgnoreCase))
                    {
                        SpawnBurstNodes.Add(FunctionNode);
                    }
                }
                for (UNiagaraNodeFunctionCall* SpawnBurstNode : SpawnBurstNodes)
                {
                    SetIntegerInput(*SpawnBurstNode, TEXT("SpawnCount"), 64);
                }
            }
        }

        for (UNiagaraRendererProperties* Renderer : EmitterData->GetRenderers())
        {
            if (UNiagaraRibbonRendererProperties* RibbonRenderer =
                Cast<UNiagaraRibbonRendererProperties>(Renderer))
            {
                RibbonRenderer->bUseGPUInit = false;
                RibbonRenderer->Material = &RibbonMaterial;
            }
        }

        Emitter->MarkPackageDirty();
        FAssetRegistryModule::AssetCreated(Emitter);
        if (!SaveAsset(Package, Emitter))
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: failed to save path emitter."));
            return nullptr;
        }
        return Emitter;
    }

    UNiagaraEmitter* CreatePointEmitter(
        const TCHAR* PackageName,
        const TCHAR* AssetName,
        const TCHAR* PositionParameterName,
        float SpriteSize)
    {
        UNiagaraEmitter* TemplateEmitter = LoadObject<UNiagaraEmitter>(
            nullptr,
            TEXT("/Niagara/DefaultAssets/Templates/Emitters/"
                 "SingleLoopingParticle.SingleLoopingParticle"));
        if (!TemplateEmitter)
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable: looping sprite template is missing."));
            return nullptr;
        }

        UPackage* Package = CreatePackage(PackageName);
        Package->FullyLoad();
        UNiagaraEmitter* Emitter = Cast<UNiagaraEmitter>(StaticDuplicateObject(
            TemplateEmitter,
            Package,
            AssetName,
            RF_Public | RF_Standalone | RF_Transactional));
        if (!Emitter)
        {
            return nullptr;
        }

        FVersionedNiagaraEmitterData* EmitterData =
            Emitter->GetEmitterData(Emitter->GetExposedVersion().VersionGuid);
        if (!EmitterData)
        {
            return nullptr;
        }
        EmitterData->bLocalSpace = false;
        const FNiagaraVariable PositionParameter(
            FNiagaraTypeDefinition::GetPositionDef(),
            PositionParameterName);
        const TArray<FNiagaraVariable> AssignmentVariables = {
            SYS_PARAM_PARTICLES_POSITION,
            SYS_PARAM_PARTICLES_SPRITE_SIZE};
        const TArray<FString> AssignmentDefaults = {
            TEXT("(X=0.0,Y=0.0,Z=0.0)"),
            FString::Printf(TEXT("(X=%g,Y=%g)"), SpriteSize, SpriteSize)};
        for (const ENiagaraScriptUsage Usage : {
            ENiagaraScriptUsage::ParticleSpawnScript,
            ENiagaraScriptUsage::ParticleUpdateScript})
        {
            if (UNiagaraNodeOutput* OutputNode = FindOutput(*EmitterData, Usage))
            {
                if (UNiagaraNodeAssignment* Assignment =
                    FNiagaraStackGraphUtilities::AddParameterModuleToStack(
                        AssignmentVariables, *OutputNode, INDEX_NONE, AssignmentDefaults))
                {
                    BindLinkedPosition(*Assignment, PositionParameter);
                }
            }
        }

        Emitter->MarkPackageDirty();
        FAssetRegistryModule::AssetCreated(Emitter);
        return SaveAsset(Package, Emitter) ? Emitter : nullptr;
    }

    bool CreateTrajectorySystem(
        UNiagaraEmitter& PathEmitter,
        UNiagaraEmitter& MovingDotEmitter,
        UNiagaraEmitter& ImpactDotEmitter)
    {
        UPackage* Package = CreatePackage(SystemPackageName);
        Package->FullyLoad();
        UNiagaraSystem* System = NewObject<UNiagaraSystem>(
            Package,
            TEXT("NS_JMThrowableTrajectory"),
            RF_Public | RF_Standalone | RF_Transactional);
        UNiagaraSystemFactoryNew::InitializeSystem(System, true);

        const FNiagaraVariable PathArray(
            FNiagaraTypeDefinition(UNiagaraDataInterfaceArrayPosition::StaticClass()),
            TEXT("User.PathPoints"));
        System->GetExposedParameters().AddParameter(PathArray);
        System->GetExposedParameters().AddParameter(
            FNiagaraVariable(
                FNiagaraTypeDefinition::GetColorDef(),
                TEXT("User.BaseColor")));
        for (const FName Name : {
            FName(TEXT("User.BaseWidth")),
            FName(TEXT("User.BaseOpacity")),
            FName(TEXT("User.FlowPhase")),
            FName(TEXT("User.FlowWidth")),
            FName(TEXT("User.FlowOpacity")),
            FName(TEXT("User.DotSize")),
            FName(TEXT("User.ImpactDotSize"))})
        {
            System->GetExposedParameters().AddParameter(
                FNiagaraVariable(FNiagaraTypeDefinition::GetFloatDef(), Name));
        }
        System->GetExposedParameters().AddParameter(
            FNiagaraVariable(
                FNiagaraTypeDefinition::GetPositionDef(),
                TEXT("User.FlowWorldPosition")));
        System->GetExposedParameters().AddParameter(
            FNiagaraVariable(
                FNiagaraTypeDefinition::GetPositionDef(),
                TEXT("User.ImpactWorldPosition")));
        System->GetExposedParameters().AddParameter(
            FNiagaraVariable(
                FNiagaraTypeDefinition::GetBoolDef(),
                TEXT("User.HasImpact")));
        System->AddEmitterHandle(
            PathEmitter,
            TEXT("E_PathRibbon"),
            PathEmitter.GetExposedVersion().VersionGuid);
        System->AddEmitterHandle(
            MovingDotEmitter,
            TEXT("E_MovingDot"),
            MovingDotEmitter.GetExposedVersion().VersionGuid);
        System->AddEmitterHandle(
            ImpactDotEmitter,
            TEXT("E_ImpactDot"),
            ImpactDotEmitter.GetExposedVersion().VersionGuid);
        System->RequestCompile(true);
        System->WaitForCompilationComplete(false, false);
        System->MarkPackageDirty();
        FAssetRegistryModule::AssetCreated(System);
        return SaveAsset(Package, System);
    }

    bool Generate()
    {
        UMaterialInterface* RibbonMaterial = CreateRibbonMaterial();
        UNiagaraEmitter* PathEmitter =
            RibbonMaterial ? CreatePathEmitter(*RibbonMaterial) : nullptr;
        UNiagaraEmitter* MovingDotEmitter = CreatePointEmitter(
            MovingDotPackageName,
            TEXT("NE_JMThrowableMovingDot"),
            TEXT("User.FlowWorldPosition"),
            3.f);
        UNiagaraEmitter* ImpactDotEmitter = CreatePointEmitter(
            ImpactDotPackageName,
            TEXT("NE_JMThrowableImpactDot"),
            TEXT("User.ImpactWorldPosition"),
            5.f);
        const bool bSucceeded =
            PathEmitter && MovingDotEmitter && ImpactDotEmitter
            && CreateTrajectorySystem(
                *PathEmitter, *MovingDotEmitter, *ImpactDotEmitter);
        if (bSucceeded)
        {
            UE_LOG(LogTemp, Display, TEXT("JMThrowable Niagara asset generation succeeded."));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("JMThrowable Niagara asset generation failed."));
        }
        return bSucceeded;
    }
}

class FJMThrowableEditorModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        if (FParse::Param(FCommandLine::Get(), TEXT("JMGenerateThrowableNiagara")))
        {
            JMThrowableNiagaraAssetGenerator::Generate();
        }
    }
};

IMPLEMENT_MODULE(FJMThrowableEditorModule, JMThrowableEditor)
