// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JMThrowableDefinition.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeJMThrowableDefinition() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USoundAttenuation_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_AJMThrowableProjectile_NoRegister();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition();
JMTHROWABLE_API UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister();
JMTHROWABLE_API UEnum* Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_JMThrowable();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UJMThrowableDefinition ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UJMThrowableDefinition;
UClass* UJMThrowableDefinition::GetPrivateStaticClass()
{
	using TClass = UJMThrowableDefinition;
	if (!Z_Registration_Info_UClass_UJMThrowableDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("JMThrowableDefinition"),
			Z_Registration_Info_UClass_UJMThrowableDefinition.InnerSingleton,
			StaticRegisterNativesUJMThrowableDefinition,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UJMThrowableDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UJMThrowableDefinition_NoRegister()
{
	return UJMThrowableDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UJMThrowableDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "JMThrowableDefinition.h" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowSpeed_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalThrowBoost_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space upward speed added to the camera-forward throw velocity." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GravityScale_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileRadius_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisualMesh_MetaData[] = {
		{ "Category", "Projectile|Visual" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisualMaterial_MetaData[] = {
		{ "Category", "Projectile|Visual" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileVisualSize_MetaData[] = {
		{ "Category", "Projectile|Visual" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Centimeter dimensions used by the native box fallback and to normalize an optional visual mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualSpinDegreesPerSecond_MetaData[] = {
		{ "Category", "Projectile|Visual" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Purely visual local rotation rate; collision remains the compatible sphere sweep." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximumSimulationTime_MetaData[] = {
		{ "Category", "Simulation" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimulationStep_MetaData[] = {
		{ "Category", "Simulation" },
		{ "ClampMin", "0.001" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimTraceDistance_MetaData[] = {
		{ "Category", "Aim" },
		{ "ClampMin", "100" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionProfile_MetaData[] = {
		{ "Category", "Collision" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorNormalThreshold_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMax", "1" },
		{ "ClampMin", "-1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxWallBounces_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BounceRestitution_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Normal restitution for non-floor impacts." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TangentialDamping_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tangential velocity retained after non-floor impacts." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxFloorBounces_MetaData[] = {
		{ "Category", "Collision|Floor Bounce" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorRestitution_MetaData[] = {
		{ "Category", "Collision|Floor Bounce" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorTangentialDamping_MetaData[] = {
		{ "Category", "Collision|Floor Bounce" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceDecay_MetaData[] = {
		{ "Category", "Collision|Floor Bounce" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Restitution multiplier applied once per completed floor bounce." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorBounceStopSpeed_MetaData[] = {
		{ "Category", "Collision|Floor Bounce" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum incoming normal speed required to perform another floor bounce." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceOffset_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorFriction_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorStopSpeed_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicImpactImpulse_MetaData[] = {
		{ "Category", "Collision" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnForwardOffset_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRightOffset_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnVerticalOffset_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewPointSpacing_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewStartDistance_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMax", "200" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera-forward distance to the centered visual preview origin. Runtime spawn offsets are not applied." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewLineWidth_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMax", "20" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewOpacity_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewEndMarkerSize_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMax", "40" },
		{ "ClampMin", "2" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowLength_MetaData[] = {
		{ "Category", "Preview|Flow" },
		{ "ClampMax", "1000" },
		{ "ClampMin", "10" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "World-space length of the bright highlight traveling along the trajectory." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowWidthMultiplier_MetaData[] = {
		{ "Category", "Preview|Flow" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0.1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width of the bright highlight relative to the base ribbon." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowOpacity_MetaData[] = {
		{ "Category", "Preview|Flow" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowLoopGap_MetaData[] = {
		{ "Category", "Preview|Flow" },
		{ "ClampMax", "500" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Invisible travel distance after the end before the flow loops to the start." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewFlowOrbSize_MetaData[] = {
		{ "Category", "Preview|Flow" },
		{ "ClampMax", "20" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Diameter of the visible orb traveling with the flow highlight." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewMarkerSurfaceOffset_MetaData[] = {
		{ "Category", "Preview|Impact" },
		{ "ClampMax", "10" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moves the first-impact marker away from the surface to prevent clipping." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PreviewRendererMode_MetaData[] = {
		{ "Category", "Preview|Niagara" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrajectoryNiagaraSystem_MetaData[] = {
		{ "AllowedClasses", "/Script/Niagara.NiagaraSystem" },
		{ "Category", "Preview|Niagara" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Plugin-owned trajectory system. A missing or invalid asset automatically uses the procedural fallback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NiagaraPathSampleCount_MetaData[] = {
		{ "Category", "Preview|Niagara" },
		{ "ClampMax", "256" },
		{ "ClampMin", "2" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TrajectoryMaterial_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlowMoveSpeed_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlowIntensity_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlowRadius_MetaData[] = {
		{ "Category", "Preview" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FuseDelay_MetaData[] = {
		{ "Category", "Activation" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurstCount_MetaData[] = {
		{ "Category", "Activation" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurstInterval_MetaData[] = {
		{ "Category", "Activation" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurstParticle_MetaData[] = {
		{ "Category", "Activation" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurstSound_MetaData[] = {
		{ "Category", "Activation" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundAttenuation_MetaData[] = {
		{ "Category", "Activation" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightIntensity_MetaData[] = {
		{ "Category", "Activation" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LightDuration_MetaData[] = {
		{ "Category", "Activation" },
		{ "ClampMin", "0.01" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseLoudness_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NoiseRadius_MetaData[] = {
		{ "Category", "AI" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/JMThrowableDefinition.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UJMThrowableDefinition constinit property declarations *******************
	static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrowSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalThrowBoost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GravityScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileRadius;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileVisualMesh;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ProjectileVisualMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectileVisualSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VisualSpinDegreesPerSecond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaximumSimulationTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SimulationStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimTraceDistance;
	static const UECodeGen_Private::FNamePropertyParams NewProp_CollisionProfile;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorNormalThreshold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxWallBounces;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BounceRestitution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TangentialDamping;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxFloorBounces;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorRestitution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorTangentialDamping;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorBounceDecay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorBounceStopSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorFriction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorStopSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DynamicImpactImpulse;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnForwardOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnRightOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnVerticalOffset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewPointSpacing;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewStartDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewLineWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewEndMarkerSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewFlowLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewFlowWidthMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewFlowOpacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewFlowLoopGap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewFlowOrbSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PreviewMarkerSurfaceOffset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PreviewRendererMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PreviewRendererMode;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_TrajectoryNiagaraSystem;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NiagaraPathSampleCount;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_TrajectoryMaterial;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlowMoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlowIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GlowRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FuseDelay;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BurstCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BurstInterval;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BurstParticle;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BurstSound;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SoundAttenuation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LightIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LightDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NoiseLoudness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NoiseRadius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UJMThrowableDefinition constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJMThrowableDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UJMThrowableDefinition_Statics

// ********** Begin Class UJMThrowableDefinition Property Definitions ******************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ProjectileClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AJMThrowableProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ThrowSpeed = { "ThrowSpeed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ThrowSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowSpeed_MetaData), NewProp_ThrowSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_VerticalThrowBoost = { "VerticalThrowBoost", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, VerticalThrowBoost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalThrowBoost_MetaData), NewProp_VerticalThrowBoost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GravityScale = { "GravityScale", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, GravityScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GravityScale_MetaData), NewProp_GravityScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileRadius = { "ProjectileRadius", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ProjectileRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileRadius_MetaData), NewProp_ProjectileRadius_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualMesh = { "ProjectileVisualMesh", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ProjectileVisualMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisualMesh_MetaData), NewProp_ProjectileVisualMesh_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualMaterial = { "ProjectileVisualMaterial", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ProjectileVisualMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisualMaterial_MetaData), NewProp_ProjectileVisualMaterial_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualSize = { "ProjectileVisualSize", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, ProjectileVisualSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileVisualSize_MetaData), NewProp_ProjectileVisualSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_VisualSpinDegreesPerSecond = { "VisualSpinDegreesPerSecond", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, VisualSpinDegreesPerSecond), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualSpinDegreesPerSecond_MetaData), NewProp_VisualSpinDegreesPerSecond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaximumSimulationTime = { "MaximumSimulationTime", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, MaximumSimulationTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximumSimulationTime_MetaData), NewProp_MaximumSimulationTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SimulationStep = { "SimulationStep", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SimulationStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimulationStep_MetaData), NewProp_SimulationStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_AimTraceDistance = { "AimTraceDistance", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, AimTraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimTraceDistance_MetaData), NewProp_AimTraceDistance_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_CollisionProfile = { "CollisionProfile", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, CollisionProfile), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionProfile_MetaData), NewProp_CollisionProfile_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorNormalThreshold = { "FloorNormalThreshold", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorNormalThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorNormalThreshold_MetaData), NewProp_FloorNormalThreshold_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaxWallBounces = { "MaxWallBounces", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, MaxWallBounces), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxWallBounces_MetaData), NewProp_MaxWallBounces_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BounceRestitution = { "BounceRestitution", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, BounceRestitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BounceRestitution_MetaData), NewProp_BounceRestitution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TangentialDamping = { "TangentialDamping", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, TangentialDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TangentialDamping_MetaData), NewProp_TangentialDamping_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaxFloorBounces = { "MaxFloorBounces", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, MaxFloorBounces), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxFloorBounces_MetaData), NewProp_MaxFloorBounces_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorRestitution = { "FloorRestitution", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorRestitution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorRestitution_MetaData), NewProp_FloorRestitution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorTangentialDamping = { "FloorTangentialDamping", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorTangentialDamping), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorTangentialDamping_MetaData), NewProp_FloorTangentialDamping_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorBounceDecay = { "FloorBounceDecay", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorBounceDecay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceDecay_MetaData), NewProp_FloorBounceDecay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorBounceStopSpeed = { "FloorBounceStopSpeed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorBounceStopSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorBounceStopSpeed_MetaData), NewProp_FloorBounceStopSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SurfaceOffset = { "SurfaceOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SurfaceOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceOffset_MetaData), NewProp_SurfaceOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorFriction = { "FloorFriction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorFriction), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorFriction_MetaData), NewProp_FloorFriction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorStopSpeed = { "FloorStopSpeed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FloorStopSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorStopSpeed_MetaData), NewProp_FloorStopSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_DynamicImpactImpulse = { "DynamicImpactImpulse", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, DynamicImpactImpulse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicImpactImpulse_MetaData), NewProp_DynamicImpactImpulse_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnForwardOffset = { "SpawnForwardOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SpawnForwardOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnForwardOffset_MetaData), NewProp_SpawnForwardOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnRightOffset = { "SpawnRightOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SpawnRightOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnRightOffset_MetaData), NewProp_SpawnRightOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnVerticalOffset = { "SpawnVerticalOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SpawnVerticalOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnVerticalOffset_MetaData), NewProp_SpawnVerticalOffset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewPointSpacing = { "PreviewPointSpacing", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewPointSpacing), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewPointSpacing_MetaData), NewProp_PreviewPointSpacing_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewStartDistance = { "PreviewStartDistance", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewStartDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewStartDistance_MetaData), NewProp_PreviewStartDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewLineWidth = { "PreviewLineWidth", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewLineWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewLineWidth_MetaData), NewProp_PreviewLineWidth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewOpacity = { "PreviewOpacity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewOpacity_MetaData), NewProp_PreviewOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewEndMarkerSize = { "PreviewEndMarkerSize", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewEndMarkerSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewEndMarkerSize_MetaData), NewProp_PreviewEndMarkerSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowLength = { "PreviewFlowLength", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewFlowLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowLength_MetaData), NewProp_PreviewFlowLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowWidthMultiplier = { "PreviewFlowWidthMultiplier", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewFlowWidthMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowWidthMultiplier_MetaData), NewProp_PreviewFlowWidthMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowOpacity = { "PreviewFlowOpacity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewFlowOpacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowOpacity_MetaData), NewProp_PreviewFlowOpacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowLoopGap = { "PreviewFlowLoopGap", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewFlowLoopGap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowLoopGap_MetaData), NewProp_PreviewFlowLoopGap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowOrbSize = { "PreviewFlowOrbSize", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewFlowOrbSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewFlowOrbSize_MetaData), NewProp_PreviewFlowOrbSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewMarkerSurfaceOffset = { "PreviewMarkerSurfaceOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewMarkerSurfaceOffset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewMarkerSurfaceOffset_MetaData), NewProp_PreviewMarkerSurfaceOffset_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewRendererMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewRendererMode = { "PreviewRendererMode", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, PreviewRendererMode), Z_Construct_UEnum_JMThrowable_EJMThrowablePreviewRendererMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PreviewRendererMode_MetaData), NewProp_PreviewRendererMode_MetaData) }; // 2601393171
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TrajectoryNiagaraSystem = { "TrajectoryNiagaraSystem", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, TrajectoryNiagaraSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrajectoryNiagaraSystem_MetaData), NewProp_TrajectoryNiagaraSystem_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NiagaraPathSampleCount = { "NiagaraPathSampleCount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, NiagaraPathSampleCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NiagaraPathSampleCount_MetaData), NewProp_NiagaraPathSampleCount_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TrajectoryMaterial = { "TrajectoryMaterial", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, TrajectoryMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TrajectoryMaterial_MetaData), NewProp_TrajectoryMaterial_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowMoveSpeed = { "GlowMoveSpeed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, GlowMoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlowMoveSpeed_MetaData), NewProp_GlowMoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowIntensity = { "GlowIntensity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, GlowIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlowIntensity_MetaData), NewProp_GlowIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowRadius = { "GlowRadius", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, GlowRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlowRadius_MetaData), NewProp_GlowRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FuseDelay = { "FuseDelay", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, FuseDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FuseDelay_MetaData), NewProp_FuseDelay_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstCount = { "BurstCount", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, BurstCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurstCount_MetaData), NewProp_BurstCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstInterval = { "BurstInterval", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, BurstInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurstInterval_MetaData), NewProp_BurstInterval_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstParticle = { "BurstParticle", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, BurstParticle), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurstParticle_MetaData), NewProp_BurstParticle_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstSound = { "BurstSound", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, BurstSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurstSound_MetaData), NewProp_BurstSound_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SoundAttenuation = { "SoundAttenuation", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, SoundAttenuation), Z_Construct_UClass_USoundAttenuation_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundAttenuation_MetaData), NewProp_SoundAttenuation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_LightIntensity = { "LightIntensity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, LightIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightIntensity_MetaData), NewProp_LightIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_LightDuration = { "LightDuration", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, LightDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LightDuration_MetaData), NewProp_LightDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NoiseLoudness = { "NoiseLoudness", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, NoiseLoudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseLoudness_MetaData), NewProp_NoiseLoudness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NoiseRadius = { "NoiseRadius", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UJMThrowableDefinition, NoiseRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NoiseRadius_MetaData), NewProp_NoiseRadius_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJMThrowableDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ThrowSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_VerticalThrowBoost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GravityScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_ProjectileVisualSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_VisualSpinDegreesPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaximumSimulationTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SimulationStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_AimTraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_CollisionProfile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorNormalThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaxWallBounces,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BounceRestitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TangentialDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_MaxFloorBounces,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorRestitution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorTangentialDamping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorBounceDecay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorBounceStopSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SurfaceOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorFriction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FloorStopSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_DynamicImpactImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnForwardOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnRightOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SpawnVerticalOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewPointSpacing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewStartDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewLineWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewEndMarkerSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowWidthMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowLoopGap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewFlowOrbSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewMarkerSurfaceOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewRendererMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_PreviewRendererMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TrajectoryNiagaraSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NiagaraPathSampleCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_TrajectoryMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowMoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_GlowRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_FuseDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstParticle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_BurstSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_SoundAttenuation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_LightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_LightDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NoiseLoudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJMThrowableDefinition_Statics::NewProp_NoiseRadius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableDefinition_Statics::PropPointers) < 2048);
// ********** End Class UJMThrowableDefinition Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UJMThrowableDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_JMThrowable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UJMThrowableDefinition_Statics::ClassParams = {
	&UJMThrowableDefinition::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UJMThrowableDefinition_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableDefinition_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UJMThrowableDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UJMThrowableDefinition_Statics::Class_MetaDataParams)
};
void UJMThrowableDefinition::StaticRegisterNativesUJMThrowableDefinition()
{
}
UClass* Z_Construct_UClass_UJMThrowableDefinition()
{
	if (!Z_Registration_Info_UClass_UJMThrowableDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UJMThrowableDefinition.OuterSingleton, Z_Construct_UClass_UJMThrowableDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UJMThrowableDefinition.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UJMThrowableDefinition);
UJMThrowableDefinition::~UJMThrowableDefinition() {}
// ********** End Class UJMThrowableDefinition *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableDefinition_h__Script_JMThrowable_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UJMThrowableDefinition, UJMThrowableDefinition::StaticClass, TEXT("UJMThrowableDefinition"), &Z_Registration_Info_UClass_UJMThrowableDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UJMThrowableDefinition), 2595033871U) },
	};
}; // Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableDefinition_h__Script_JMThrowable_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableDefinition_h__Script_JMThrowable_1814804082{
	TEXT("/Script/JMThrowable"),
	Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableDefinition_h__Script_JMThrowable_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_P_260729_Plugins_JMThrowable_Source_JMThrowable_Public_JMThrowableDefinition_h__Script_JMThrowable_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
