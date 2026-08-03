#include "JMThrowableInteractorComponent.h"
#include "JMThrowSolver.h"
#include "JMThrowableDefinition.h"
#include "JMThrowableProjectile.h"
#include "JMThrowableSettings.h"
#include "Components/SplineComponent.h"
#include "Components/PointLightComponent.h"
#include "ProceduralMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "NiagaraComponent.h"
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

namespace JMThrowablePreview
{
    void ConfigureMesh(UProceduralMeshComponent* Mesh)
    {
        if (!Mesh)
        {
            return;
        }
        Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        Mesh->SetGenerateOverlapEvents(false);
        Mesh->SetCastShadow(false);
        Mesh->SetVisibility(false);
    }

    void BuildRibbon(
        UProceduralMeshComponent* Mesh,
        const TArray<FVector>& Points,
        const FVector& ViewLocation,
        float Width,
        float Opacity,
        bool bTaperWidth,
        bool bFadeEnds)
    {
        if (!Mesh)
        {
            return;
        }
        if (Points.Num() < 2)
        {
            Mesh->ClearAllMeshSections();
            Mesh->SetVisibility(false);
            return;
        }

        TArray<FVector> Vertices;
        TArray<FVector> Normals;
        TArray<int32> Triangles;
        TArray<FVector2D> UVs;
        TArray<FLinearColor> Colors;
        TArray<FProcMeshTangent> Tangents;
        const FTransform ToLocal = Mesh->GetComponentTransform().Inverse();
        float TotalDistance = 0.f;
        for (int32 Index = 1; Index < Points.Num(); ++Index)
        {
            TotalDistance += FVector::Distance(Points[Index - 1], Points[Index]);
        }
        float Distance = 0.f;

        constexpr int32 CrossSectionCount = 5;
        constexpr float CrossSectionOffsets[CrossSectionCount] = {-1.f, -.55f, 0.f, .55f, 1.f};
        constexpr float EdgeFade[CrossSectionCount] = {0.f, .7f, 1.f, .7f, 0.f};

        for (int32 Index = 0; Index < Points.Num(); ++Index)
        {
            const FVector Point = Points[Index];
            if (Index > 0)
            {
                Distance += FVector::Distance(Points[Index - 1], Point);
            }
            const FVector PathTangent = (Index + 1 < Points.Num()
                ? Points[Index + 1] - Point
                : Point - Points[Index - 1]).GetSafeNormal();
            const FVector ToCamera = (ViewLocation - Point).GetSafeNormal();
            FVector Side = FVector::CrossProduct(PathTangent, ToCamera).GetSafeNormal();
            if (Side.IsNearlyZero())
            {
                Side = FVector::CrossProduct(PathTangent, FVector::UpVector).GetSafeNormal();
            }
            if (Side.IsNearlyZero())
            {
                Side = FVector::RightVector;
            }

            const float Alpha = TotalDistance > KINDA_SMALL_NUMBER ? Distance / TotalDistance : 0.f;
            const float WidthScale = bTaperWidth ? FMath::Lerp(1.f, .55f, Alpha) : 1.f;
            const float HalfWidth = Width * WidthScale * .5f;
            const float LongitudinalFade = bFadeEnds
                ? FMath::Clamp(FMath::Sin(Alpha * UE_PI), 0.f, 1.f)
                : 1.f;
            for (int32 CrossIndex = 0; CrossIndex < CrossSectionCount; ++CrossIndex)
            {
                Vertices.Add(ToLocal.TransformPosition(
                    Point + Side * HalfWidth * CrossSectionOffsets[CrossIndex]));
                Normals.Add(ToLocal.TransformVectorNoScale(ToCamera));
                UVs.Add(FVector2D(
                    Alpha,
                    static_cast<float>(CrossIndex) / (CrossSectionCount - 1)));
                Colors.Add(FLinearColor(
                    1.f,
                    1.f,
                    1.f,
                    Opacity * LongitudinalFade * EdgeFade[CrossIndex]));
                Tangents.Add(FProcMeshTangent(
                    ToLocal.TransformVectorNoScale(PathTangent), false));
            }
            if (Index > 0)
            {
                const int32 Base = Index * CrossSectionCount;
                for (int32 CrossIndex = 0; CrossIndex + 1 < CrossSectionCount; ++CrossIndex)
                {
                    const int32 Previous = Base - CrossSectionCount + CrossIndex;
                    const int32 Current = Base + CrossIndex;
                    Triangles.Append({
                        Previous,
                        Current,
                        Previous + 1,
                        Previous + 1,
                        Current,
                        Current + 1});
                }
            }
        }

        Mesh->CreateMeshSection_LinearColor(
            0, Vertices, Triangles, Normals, UVs, Colors, Tangents, false);
        Mesh->SetVisibility(true);
    }

    void BuildUnitSphere(UProceduralMeshComponent* Mesh)
    {
        if (!Mesh)
        {
            return;
        }

        constexpr int32 LatitudeSegments = 6;
        constexpr int32 LongitudeSegments = 8;
        TArray<FVector> Vertices;
        TArray<FVector> Normals;
        TArray<int32> Triangles;
        TArray<FVector2D> UVs;
        TArray<FLinearColor> Colors;
        TArray<FProcMeshTangent> Tangents;

        for (int32 Latitude = 0; Latitude <= LatitudeSegments; ++Latitude)
        {
            const float V = static_cast<float>(Latitude) / LatitudeSegments;
            const float Phi = V * UE_PI;
            for (int32 Longitude = 0; Longitude <= LongitudeSegments; ++Longitude)
            {
                const float U = static_cast<float>(Longitude) / LongitudeSegments;
                const float Theta = U * 2.f * UE_PI;
                const FVector Normal(
                    FMath::Sin(Phi) * FMath::Cos(Theta),
                    FMath::Sin(Phi) * FMath::Sin(Theta),
                    FMath::Cos(Phi));
                Vertices.Add(Normal * .5f);
                Normals.Add(Normal);
                UVs.Add(FVector2D(U, V));
                Colors.Add(FLinearColor::White);
                Tangents.Add(FProcMeshTangent(
                    FVector(-FMath::Sin(Theta), FMath::Cos(Theta), 0.f), false));
            }
        }

        const int32 RowSize = LongitudeSegments + 1;
        for (int32 Latitude = 0; Latitude < LatitudeSegments; ++Latitude)
        {
            for (int32 Longitude = 0; Longitude < LongitudeSegments; ++Longitude)
            {
                const int32 A = Latitude * RowSize + Longitude;
                const int32 B = A + RowSize;
                Triangles.Append({A, B, A + 1, A + 1, B, B + 1});
            }
        }

        Mesh->CreateMeshSection_LinearColor(
            0, Vertices, Triangles, Normals, UVs, Colors, Tangents, false);
        Mesh->SetVisibility(false);
    }
}

UJMThrowableInteractorComponent::UJMThrowableInteractorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMThrowableInteractorComponent::BeginPlay()
{
    Super::BeginPlay();
    PreviewSpline = NewObject<USplineComponent>(GetOwner(), TEXT("JMThrowablePreviewSpline"));
    if (PreviewSpline)
    {
        PreviewSpline->RegisterComponent();
        PreviewSpline->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        PreviewSpline->SetVisibility(false);
    }
    PreviewRibbon = NewObject<UProceduralMeshComponent>(GetOwner(), TEXT("JMThrowablePreviewRibbon"));
    if (PreviewRibbon)
    {
        PreviewRibbon->RegisterComponent();
        PreviewRibbon->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        JMThrowablePreview::ConfigureMesh(PreviewRibbon);
    }
    PreviewFlowRibbon = NewObject<UProceduralMeshComponent>(GetOwner(), TEXT("JMThrowablePreviewFlowRibbon"));
    if (PreviewFlowRibbon)
    {
        PreviewFlowRibbon->RegisterComponent();
        PreviewFlowRibbon->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        JMThrowablePreview::ConfigureMesh(PreviewFlowRibbon);
    }
    PreviewFlowOrb = NewObject<UProceduralMeshComponent>(GetOwner(), TEXT("JMThrowablePreviewFlowOrb"));
    if (PreviewFlowOrb)
    {
        PreviewFlowOrb->RegisterComponent();
        PreviewFlowOrb->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        JMThrowablePreview::ConfigureMesh(PreviewFlowOrb);
        JMThrowablePreview::BuildUnitSphere(PreviewFlowOrb);
    }
    PreviewGlow = NewObject<UPointLightComponent>(GetOwner(), TEXT("JMThrowablePreviewGlow"));
    if (PreviewGlow)
    {
        PreviewGlow->RegisterComponent();
        PreviewGlow->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        PreviewGlow->SetCastShadows(false);
        PreviewGlow->SetVisibility(false);
    }
    PreviewImpactMarker = NewObject<UProceduralMeshComponent>(GetOwner(), TEXT("JMThrowablePreviewImpactMarker"));
    if (PreviewImpactMarker)
    {
        PreviewImpactMarker->RegisterComponent();
        PreviewImpactMarker->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
        JMThrowablePreview::ConfigureMesh(PreviewImpactMarker);
        JMThrowablePreview::BuildUnitSphere(PreviewImpactMarker);
    }
    PreviewNiagara = NewObject<UNiagaraComponent>(GetOwner(), TEXT("JMThrowablePreviewNiagara"));
    if (PreviewNiagara)
    {
        PreviewNiagara->bAutoActivate = false;
        PreviewNiagara->RegisterComponent();
        PreviewNiagara->AttachToComponent(
            GetOwner()->GetRootComponent(),
            FAttachmentTransformRules::KeepWorldTransform);
        PreviewNiagara->SetCastShadow(false);
        PreviewNiagara->SetVisibility(false);
    }
}

void UJMThrowableInteractorComponent::EndPlay(const EEndPlayReason::Type Reason)
{
    Cleanup(true);
    Super::EndPlay(Reason);
}

bool UJMThrowableInteractorComponent::BeginItemUse(const FJMThrowableUseContext& Context)
{
    if (!IsValid(Context.User) || !IsValid(Context.Definition) || !Context.Definition->ProjectileClass) return false;
    if (UseState != EJMThrowableUseState::Idle) Cleanup(true);
    ActiveContext = Context;
    ActiveContext.SessionId = FGuid::NewGuid();
    SetState(EJMThrowableUseState::Ready);
    return true;
}

bool UJMThrowableInteractorComponent::BeginAim()
{
    if (UseState != EJMThrowableUseState::Ready) return false;
    PreparePreviewMaterials();
    PrepareNiagaraPreview();
    FlowDistance = 0.f;
    SetState(EJMThrowableUseState::Aiming);
    UpdatePreview();
    SetComponentTickEnabled(true);
    return true;
}

bool UJMThrowableInteractorComponent::EndAim()
{
    if (UseState != EJMThrowableUseState::Aiming) return false;
    HidePreviewVisuals(true);
    PreviewResult = FJMThrowSimulationResult();
    PreviewPathPoints.Reset();
    FlowDistance = 0.f;
    SetComponentTickEnabled(false);
    SetState(EJMThrowableUseState::Ready);
    return true;
}

void UJMThrowableInteractorComponent::CancelItemUse()
{
    if (UseState == EJMThrowableUseState::Idle || UseState == EJMThrowableUseState::CommittingThrow) return;
    Cleanup(true);
}

void UJMThrowableInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* Tick)
{
    Super::TickComponent(DeltaTime, TickType, Tick);
    if (UseState != EJMThrowableUseState::Aiming) return;
    UpdatePreviewAnimation(DeltaTime);
    PreviewAccumulator += DeltaTime;
    const UJMThrowableSettings* Settings = GetDefault<UJMThrowableSettings>();
    const float Interval = 1.f / FMath::Max(1.f, Settings ? Settings->PreviewUpdateHz : 30.f);
    if (PreviewAccumulator >= Interval)
    {
        PreviewAccumulator = FMath::Fmod(PreviewAccumulator, Interval);
        UpdatePreview();
    }
}

bool UJMThrowableInteractorComponent::GetView(FVector& OutLocation, FVector& OutForward) const
{
    const APawn* Pawn = Cast<APawn>(ActiveContext.User.Get());
    const APlayerController* PC = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    if (!PC || !PC->IsLocalController()) return false;
    FRotator Rotation;
    PC->GetPlayerViewPoint(OutLocation, Rotation);
    OutForward = Rotation.Vector();
    return !OutLocation.ContainsNaN() && !OutForward.IsNearlyZero();
}

bool UJMThrowableInteractorComponent::BuildThrowParameters(FJMThrowParameters& Out, FVector* OutAimPoint) const
{
    FVector ViewLocation, ViewForward;
    if (!GetView(ViewLocation, ViewForward) || !IsValid(ActiveContext.Definition)) return false;
    const UJMThrowableDefinition* D = ActiveContext.Definition;
    const FVector TraceEnd = ViewLocation + ViewForward * D->AimTraceDistance;
    FCollisionQueryParams Query(SCENE_QUERY_STAT(JMThrowableAim), true, ActiveContext.User);
    FHitResult AimHit;
    const bool bAimHit = GetWorld()->LineTraceSingleByProfile(AimHit, ViewLocation, TraceEnd, D->CollisionProfile, Query);
    const FVector AimPoint = bAimHit ? AimHit.ImpactPoint : TraceEnd;
    const FVector Origin = IsValid(ActiveContext.ExplicitThrowOrigin)
        ? ActiveContext.ExplicitThrowOrigin->GetComponentLocation()
        : ViewLocation + ViewForward * D->SpawnForwardOffset
            + FVector::CrossProduct(FVector::UpVector, ViewForward).GetSafeNormal() * D->SpawnRightOffset
            + FVector::UpVector * D->SpawnVerticalOffset;
    if (Origin.ContainsNaN() || Origin.Equals(AimPoint)) return false;
    Out.StartPosition = Origin;
    Out.InitialVelocity = FJMThrowSolver::CalculateLaunchVelocity(
        ViewForward,
        D->ThrowSpeed,
        D->VerticalThrowBoost);
    Out.Gravity = FVector(0, 0, GetWorld()->GetGravityZ() * D->GravityScale);
    Out.ProjectileRadius = D->ProjectileRadius;
    Out.SimulationStep = D->SimulationStep;
    Out.MaximumSimulationTime = D->MaximumSimulationTime;
    Out.CollisionProfile = D->CollisionProfile;
    Out.FloorNormalThreshold = D->FloorNormalThreshold;
    Out.MaxWallBounces = D->MaxWallBounces;
    Out.BounceRestitution = D->BounceRestitution;
    Out.TangentialDamping = D->TangentialDamping;
    Out.MaxFloorBounces = D->MaxFloorBounces;
    Out.FloorRestitution = D->FloorRestitution;
    Out.FloorTangentialDamping = D->FloorTangentialDamping;
    Out.FloorBounceDecay = D->FloorBounceDecay;
    Out.FloorBounceStopSpeed = D->FloorBounceStopSpeed;
    Out.SurfaceOffset = D->SurfaceOffset;
    Out.FloorFriction = D->FloorFriction;
    Out.FloorStopSpeed = D->FloorStopSpeed;
    Out.DynamicImpactImpulse = D->DynamicImpactImpulse;
    Out.VisualSpinDegreesPerSecond = D->VisualSpinDegreesPerSecond;
    Out.IgnoredActors.Add(ActiveContext.User);
    if (const UJMThrowableSettings* Settings = GetDefault<UJMThrowableSettings>())
        Out.bDebugDraw = Settings->bDebugThrowableTrajectory;
    if (OutAimPoint) *OutAimPoint = AimPoint;
    return true;
}

bool UJMThrowableInteractorComponent::ValidateSpawn(const FJMThrowParameters& P) const
{
    FCollisionQueryParams Query(SCENE_QUERY_STAT(JMThrowableSpawn), false, ActiveContext.User);
    return !GetWorld()->OverlapBlockingTestByProfile(
        P.StartPosition, FQuat::Identity, P.CollisionProfile,
        FCollisionShape::MakeSphere(P.ProjectileRadius), Query);
}

void UJMThrowableInteractorComponent::PreparePreviewMaterials()
{
    if (bPreviewMaterialPrepared || !IsValid(ActiveContext.Definition))
    {
        return;
    }
    bPreviewMaterialPrepared = true;
    if (ActiveContext.Definition->TrajectoryMaterial.IsNull())
    {
        return;
    }

    CachedPreviewMaterial = ActiveContext.Definition->TrajectoryMaterial.LoadSynchronous();
    if (!CachedPreviewMaterial)
    {
        return;
    }

    PreviewTrajectoryMID = UMaterialInstanceDynamic::Create(CachedPreviewMaterial, this);
    PreviewFlowMID = UMaterialInstanceDynamic::Create(CachedPreviewMaterial, this);
    PreviewOrbMID = UMaterialInstanceDynamic::Create(CachedPreviewMaterial, this);
    PreviewMarkerMID = UMaterialInstanceDynamic::Create(CachedPreviewMaterial, this);
    if (PreviewTrajectoryMID)
    {
        PreviewTrajectoryMID->SetVectorParameterValue(TEXT("PreviewColor"), FLinearColor::White);
        PreviewTrajectoryMID->SetScalarParameterValue(TEXT("BaseOpacity"), 1.f);
        PreviewTrajectoryMID->SetScalarParameterValue(TEXT("Opacity"), 1.f);
        if (PreviewRibbon) PreviewRibbon->SetMaterial(0, PreviewTrajectoryMID);
    }
    if (PreviewFlowMID)
    {
        PreviewFlowMID->SetVectorParameterValue(TEXT("PreviewColor"), FLinearColor::White);
        PreviewFlowMID->SetScalarParameterValue(TEXT("BaseOpacity"), 1.f);
        PreviewFlowMID->SetScalarParameterValue(TEXT("Opacity"), 1.f);
        if (PreviewFlowRibbon) PreviewFlowRibbon->SetMaterial(0, PreviewFlowMID);
    }
    if (PreviewOrbMID)
    {
        PreviewOrbMID->SetVectorParameterValue(TEXT("PreviewColor"), FLinearColor::White);
        PreviewOrbMID->SetScalarParameterValue(TEXT("BaseOpacity"), 1.f);
        PreviewOrbMID->SetScalarParameterValue(TEXT("Opacity"), 1.f);
        if (PreviewFlowOrb) PreviewFlowOrb->SetMaterial(0, PreviewOrbMID);
    }
    if (PreviewMarkerMID)
    {
        PreviewMarkerMID->SetVectorParameterValue(TEXT("PreviewColor"), FLinearColor::White);
        PreviewMarkerMID->SetScalarParameterValue(TEXT("BaseOpacity"), 1.f);
        PreviewMarkerMID->SetScalarParameterValue(TEXT("Opacity"), 1.f);
        if (PreviewImpactMarker) PreviewImpactMarker->SetMaterial(0, PreviewMarkerMID);
    }
}

bool UJMThrowableInteractorComponent::PrepareNiagaraPreview()
{
    bNiagaraPreviewActive = false;
    if (!PreviewNiagara || !IsValid(ActiveContext.Definition)
        || ActiveContext.Definition->PreviewRendererMode
            == EJMThrowablePreviewRendererMode::ProceduralOnly
        || ActiveContext.Definition->TrajectoryNiagaraSystem.IsNull())
    {
        DeactivateNiagaraPreview(false);
        return false;
    }

    CachedTrajectoryNiagaraSystem =
        ActiveContext.Definition->TrajectoryNiagaraSystem.LoadSynchronous();
    if (!CachedTrajectoryNiagaraSystem)
    {
        DeactivateNiagaraPreview(false);
        return false;
    }

    PreviewNiagara->SetAsset(CachedTrajectoryNiagaraSystem);
    PreviewNiagara->SetVisibility(true);
    PreviewNiagara->Activate(true);
    bNiagaraPreviewActive = true;
    return true;
}

bool UJMThrowableInteractorComponent::UpdateNiagaraPreview()
{
    if (!bNiagaraPreviewActive || !PreviewNiagara
        || !CachedTrajectoryNiagaraSystem || !IsValid(ActiveContext.Definition)
        || NiagaraPathPoints.Num() < 2)
    {
        return false;
    }

    const UJMThrowableDefinition* Definition = ActiveContext.Definition;
    UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayPosition(
        PreviewNiagara, TEXT("User.PathPoints"), NiagaraPathPoints);

    const bool bHasImpact =
        !PreviewResult.ImpactPoints.IsEmpty() && !PreviewResult.ImpactNormals.IsEmpty();
    const FVector ImpactPosition = bHasImpact
        ? PreviewResult.ImpactPoints[0]
            + PreviewResult.ImpactNormals[0].GetSafeNormal()
                * Definition->PreviewMarkerSurfaceOffset
        : FVector(0.f, 0.f, -UE_BIG_NUMBER);
    PreviewNiagara->SetVariablePosition(TEXT("User.ImpactWorldPosition"), ImpactPosition);
    PreviewNiagara->SetVariableBool(TEXT("User.HasImpact"), bHasImpact);
    PreviewNiagara->SetVariableLinearColor(
        TEXT("User.BaseColor"),
        FLinearColor(1.f, 1.f, 1.f, Definition->PreviewOpacity));
    PreviewNiagara->SetVariableFloat(TEXT("User.BaseWidth"), Definition->PreviewLineWidth);
    PreviewNiagara->SetVariableFloat(TEXT("User.BaseOpacity"), Definition->PreviewOpacity);
    PreviewNiagara->SetVariableFloat(
        TEXT("User.FlowWidth"),
        FJMThrowSolver::CalculateFlowWidth(
            Definition->PreviewLineWidth,
            Definition->PreviewFlowWidthMultiplier));
    PreviewNiagara->SetVariableFloat(TEXT("User.FlowOpacity"), Definition->PreviewFlowOpacity);
    PreviewNiagara->SetVariableFloat(TEXT("User.DotSize"), Definition->PreviewFlowOrbSize);
    PreviewNiagara->SetVariableFloat(
        TEXT("User.ImpactDotSize"), Definition->PreviewEndMarkerSize);
    return true;
}

void UJMThrowableInteractorComponent::DeactivateNiagaraPreview(bool bClearPath)
{
    if (PreviewNiagara)
    {
        if (bClearPath)
        {
            const TArray<FVector> EmptyPath;
            UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayPosition(
                PreviewNiagara, TEXT("User.PathPoints"), EmptyPath);
        }
        PreviewNiagara->SetVariableBool(TEXT("User.HasImpact"), false);
        PreviewNiagara->DeactivateImmediate();
        PreviewNiagara->SetVisibility(false);
    }
    bNiagaraPreviewActive = false;
    if (bClearPath)
    {
        NiagaraPathPoints.Reset();
    }
}

void UJMThrowableInteractorComponent::UpdatePreview()
{
    FJMThrowParameters Parameters;
    if (!BuildThrowParameters(Parameters))
    {
        HidePreviewVisuals(true);
        PreviewResult = FJMThrowSimulationResult();
        PreviewPathPoints.Reset();
        return;
    }

    FVector ViewLocation;
    FVector ViewForward;
    if (!GetView(ViewLocation, ViewForward))
    {
        HidePreviewVisuals(true);
        PreviewResult = FJMThrowSimulationResult();
        PreviewPathPoints.Reset();
        return;
    }
    FJMThrowParameters PreviewParameters = Parameters;
    PreviewParameters.StartPosition = FJMThrowSolver::CalculatePreviewVisualOrigin(
        ViewLocation,
        ViewForward,
        ActiveContext.Definition->PreviewStartDistance);
    PreviewResult = FJMThrowSolver::SimulatePreview(GetWorld(), PreviewParameters);
    BuildPreviewPath();
    if (UpdateNiagaraPreview())
    {
        // Keep a faint, solver-driven base path under Niagara. The Niagara system
        // remains responsible for flow/impact animation, while this underlay
        // guarantees that the complete first-hit parabola is always readable.
        RebuildBaseRibbon();
        if (PreviewFlowRibbon) PreviewFlowRibbon->SetVisibility(false);
        if (PreviewFlowOrb) PreviewFlowOrb->SetVisibility(false);
        if (PreviewGlow) PreviewGlow->SetVisibility(false);
        if (PreviewImpactMarker) PreviewImpactMarker->SetVisibility(false);
    }
    else
    {
        RebuildBaseRibbon();
        UpdateImpactMarker();
    }
    UpdatePreviewAnimation(0.f);
}

void UJMThrowableInteractorComponent::BuildPreviewPath()
{
    PreviewPathPoints.Reset();
    NiagaraPathPoints.Reset();
    if (!PreviewSpline || !IsValid(ActiveContext.Definition))
    {
        return;
    }
    PreviewSpline->ClearSplinePoints(false);
    PreviewSpline->SetVisibility(false);
    if (PreviewResult.Points.Num() < 2)
    {
        PreviewSpline->UpdateSpline();
        return;
    }

    NiagaraPathPoints = FJMThrowSolver::ResamplePathByDistance(
        PreviewResult.Points,
        ActiveContext.Definition->NiagaraPathSampleCount);

    const float PointSpacing = FMath::Max(1.f, ActiveContext.Definition->PreviewPointSpacing);
    PreviewPathPoints.Add(PreviewResult.Points[0]);
    for (int32 Index = 1; Index + 1 < PreviewResult.Points.Num(); ++Index)
    {
        if (FVector::Distance(PreviewPathPoints.Last(), PreviewResult.Points[Index]) >= PointSpacing)
        {
            PreviewPathPoints.Add(PreviewResult.Points[Index]);
        }
    }
    if (!PreviewPathPoints.Last().Equals(PreviewResult.Points.Last(), KINDA_SMALL_NUMBER))
    {
        // The final point is the exact first impact when one exists.
        PreviewPathPoints.Add(PreviewResult.Points.Last());
    }

    for (const FVector& Point : PreviewPathPoints)
    {
        PreviewSpline->AddSplinePoint(Point, ESplineCoordinateSpace::World, false);
    }
    PreviewSpline->UpdateSpline();
}

void UJMThrowableInteractorComponent::RebuildBaseRibbon()
{
    if (!PreviewRibbon || !IsValid(ActiveContext.Definition))
    {
        return;
    }
    FVector ViewLocation;
    FVector ViewForward;
    if (!GetView(ViewLocation, ViewForward))
    {
        PreviewRibbon->SetVisibility(false);
        return;
    }
    JMThrowablePreview::BuildRibbon(
        PreviewRibbon,
        PreviewPathPoints,
        ViewLocation,
        ActiveContext.Definition->PreviewLineWidth,
        ActiveContext.Definition->PreviewOpacity,
        true,
        false);
}

void UJMThrowableInteractorComponent::RebuildFlowRibbon(float StartDistance, float EndDistance)
{
    if (!PreviewFlowRibbon || !PreviewSpline || !IsValid(ActiveContext.Definition)
        || EndDistance <= StartDistance)
    {
        if (PreviewFlowRibbon) PreviewFlowRibbon->SetVisibility(false);
        return;
    }

    FVector ViewLocation;
    FVector ViewForward;
    if (!GetView(ViewLocation, ViewForward))
    {
        PreviewFlowRibbon->SetVisibility(false);
        return;
    }

    const float SegmentLength = EndDistance - StartDistance;
    const int32 SampleCount = FMath::Clamp(
        FMath::CeilToInt(SegmentLength / FMath::Max(5.f, ActiveContext.Definition->PreviewPointSpacing * .5f)) + 1,
        2,
        32);
    TArray<FVector> FlowPoints;
    FlowPoints.Reserve(SampleCount);
    for (int32 Index = 0; Index < SampleCount; ++Index)
    {
        const float Alpha = static_cast<float>(Index) / (SampleCount - 1);
        FlowPoints.Add(PreviewSpline->GetLocationAtDistanceAlongSpline(
            FMath::Lerp(StartDistance, EndDistance, Alpha),
            ESplineCoordinateSpace::World));
    }
    JMThrowablePreview::BuildRibbon(
        PreviewFlowRibbon,
        FlowPoints,
        ViewLocation,
        FJMThrowSolver::CalculateFlowWidth(
            ActiveContext.Definition->PreviewLineWidth,
            ActiveContext.Definition->PreviewFlowWidthMultiplier),
        ActiveContext.Definition->PreviewFlowOpacity,
        false,
        true);
}

void UJMThrowableInteractorComponent::UpdatePreviewAnimation(float DeltaTime)
{
    if (!PreviewSpline || !IsValid(ActiveContext.Definition))
    {
        return;
    }
    const float Length = PreviewSpline->GetSplineLength();
    if (Length <= KINDA_SMALL_NUMBER || PreviewPathPoints.Num() < 2)
    {
        if (PreviewFlowRibbon) PreviewFlowRibbon->SetVisibility(false);
        if (PreviewFlowOrb) PreviewFlowOrb->SetVisibility(false);
        if (PreviewGlow) PreviewGlow->SetVisibility(false);
        return;
    }

    const float LoopGap = FMath::Max(0.f, ActiveContext.Definition->PreviewFlowLoopGap);
    const float CycleLength = Length + LoopGap;
    FlowDistance = FMath::Fmod(
        FlowDistance + FMath::Max(0.f, ActiveContext.Definition->GlowMoveSpeed) * DeltaTime,
        FMath::Max(CycleLength, KINDA_SMALL_NUMBER));
    if (FlowDistance >= Length)
    {
        if (bNiagaraPreviewActive && PreviewNiagara)
        {
            PreviewNiagara->SetVariableFloat(TEXT("User.FlowPhase"), 2.f);
            PreviewNiagara->SetVariablePosition(
                TEXT("User.FlowWorldPosition"),
                FVector(0.f, 0.f, -UE_BIG_NUMBER));
        }
        if (PreviewFlowRibbon) PreviewFlowRibbon->SetVisibility(false);
        if (PreviewFlowOrb) PreviewFlowOrb->SetVisibility(false);
        if (PreviewGlow) PreviewGlow->SetVisibility(false);
        return;
    }

    const float FlowEnd = FMath::Min(
        Length,
        FlowDistance + FMath::Max(10.f, ActiveContext.Definition->PreviewFlowLength));
    RebuildFlowRibbon(FlowDistance, FlowEnd);
    const float OrbDistance = FMath::Min(
        Length,
        FlowDistance + (FlowEnd - FlowDistance) * .5f);
    const FVector OrbLocation = PreviewSpline->GetLocationAtDistanceAlongSpline(
        OrbDistance, ESplineCoordinateSpace::World);
    if (bNiagaraPreviewActive && PreviewNiagara)
    {
        PreviewNiagara->SetVariableFloat(
            TEXT("User.FlowPhase"),
            Length > KINDA_SMALL_NUMBER ? OrbDistance / Length : 0.f);
        PreviewNiagara->SetVariablePosition(TEXT("User.FlowWorldPosition"), OrbLocation);
        return;
    }
    if (PreviewFlowOrb)
    {
        PreviewFlowOrb->SetWorldLocation(OrbLocation);
        PreviewFlowOrb->SetWorldScale3D(
            FVector(ActiveContext.Definition->PreviewFlowOrbSize));
        PreviewFlowOrb->SetVisibility(true);
    }
    if (PreviewGlow)
    {
        PreviewGlow->SetWorldLocation(OrbLocation);
        PreviewGlow->SetIntensity(ActiveContext.Definition->GlowIntensity);
        PreviewGlow->SetAttenuationRadius(ActiveContext.Definition->GlowRadius);
        PreviewGlow->SetLightColor(FLinearColor::White);
        PreviewGlow->SetVisibility(ActiveContext.Definition->GlowIntensity > 0.f);
    }
}

void UJMThrowableInteractorComponent::UpdateImpactMarker()
{
    if (!PreviewImpactMarker || !IsValid(ActiveContext.Definition)
        || PreviewResult.ImpactPoints.IsEmpty() || PreviewResult.ImpactNormals.IsEmpty())
    {
        if (PreviewImpactMarker) PreviewImpactMarker->SetVisibility(false);
        return;
    }

    const FVector Normal = PreviewResult.ImpactNormals[0].GetSafeNormal();
    PreviewImpactMarker->SetWorldLocation(
        PreviewResult.ImpactPoints[0] + Normal * (
            ActiveContext.Definition->PreviewEndMarkerSize * .5f
            + ActiveContext.Definition->PreviewMarkerSurfaceOffset));
    PreviewImpactMarker->SetWorldScale3D(
        FVector(ActiveContext.Definition->PreviewEndMarkerSize));
    PreviewImpactMarker->SetVisibility(true);
}

void UJMThrowableInteractorComponent::HidePreviewVisuals(bool bClearGeometry)
{
    DeactivateNiagaraPreview(bClearGeometry);
    if (PreviewSpline)
    {
        if (bClearGeometry) PreviewSpline->ClearSplinePoints();
        PreviewSpline->SetVisibility(false);
    }
    if (PreviewRibbon)
    {
        if (bClearGeometry) PreviewRibbon->ClearAllMeshSections();
        PreviewRibbon->SetVisibility(false);
    }
    if (PreviewFlowRibbon)
    {
        if (bClearGeometry) PreviewFlowRibbon->ClearAllMeshSections();
        PreviewFlowRibbon->SetVisibility(false);
    }
    if (PreviewFlowOrb) PreviewFlowOrb->SetVisibility(false);
    if (PreviewGlow) PreviewGlow->SetVisibility(false);
    if (PreviewImpactMarker) PreviewImpactMarker->SetVisibility(false);
}

FJMThrowResult UJMThrowableInteractorComponent::TryCommitThrow()
{
    if (UseState == EJMThrowableUseState::CommittingThrow) return Fail(EJMThrowResultCode::DuplicateCommit, TEXT("Duplicate commit."), EJMThrowableUseState::CommittingThrow);
    if (UseState != EJMThrowableUseState::Aiming) return Fail(EJMThrowResultCode::InvalidState, TEXT("Throw requires Aiming state."), UseState);
    const FGuid Session = ActiveContext.SessionId;
    SetState(EJMThrowableUseState::CommittingThrow);
    HidePreviewVisuals(false);
    SetComponentTickEnabled(false);
    FJMThrowParameters P;
    if (!BuildThrowParameters(P)) return Fail(EJMThrowResultCode::NoLocalView, TEXT("No valid local player view."), EJMThrowableUseState::Aiming);
    if (!ValidateSpawn(P)) return Fail(EJMThrowResultCode::BlockedSpawn, TEXT("Throw origin is blocked."), EJMThrowableUseState::Aiming);

    FActorSpawnParameters Spawn;
    Spawn.Owner = ActiveContext.User;
    Spawn.Instigator = Cast<APawn>(ActiveContext.User.Get());
    Spawn.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    AJMThrowableProjectile* Projectile = GetWorld()->SpawnActor<AJMThrowableProjectile>(
        ActiveContext.Definition->ProjectileClass, P.StartPosition, P.InitialVelocity.Rotation(), Spawn);
    if (!Projectile) return Fail(EJMThrowResultCode::ProjectileSpawnFailed, TEXT("Projectile spawn failed."), EJMThrowableUseState::Aiming);
    Projectile->ConfigureDefinition(ActiveContext.Definition);
    Projectile->Launch(P);
    if (!CommitDelegate.IsBound() || !CommitDelegate.Execute(Session))
    {
        Projectile->Destroy();
        return Fail(EJMThrowResultCode::InventoryConsumeFailed, TEXT("Commit rejected; projectile rolled back."), EJMThrowableUseState::Aiming);
    }
    FJMThrowResult Result;
    Result.bSucceeded = true;
    Result.ResultCode = EJMThrowResultCode::Success;
    Result.Projectile = Projectile;
    Result.SessionId = Session;
    Result.ConsumedQuantity = 1;
    Cleanup(true);
    OnThrowCompleted.Broadcast(Result);
    return Result;
}

FJMThrowResult UJMThrowableInteractorComponent::Fail(EJMThrowResultCode Code, const TCHAR* Reason, EJMThrowableUseState Restore)
{
    FJMThrowResult Result;
    Result.ResultCode = Code;
    Result.FailureReason = FText::FromString(Reason);
    Result.SessionId = ActiveContext.SessionId;
    if (UseState != Restore) SetState(Restore);
    if (Restore == EJMThrowableUseState::Aiming)
    {
        PrepareNiagaraPreview();
        SetComponentTickEnabled(true);
        UpdatePreview();
    }
    OnThrowCompleted.Broadcast(Result);
    return Result;
}

void UJMThrowableInteractorComponent::SetState(EJMThrowableUseState NewState)
{
    if (UseState == NewState) return;
    UseState = NewState;
    OnStateChanged.Broadcast(NewState);
}

void UJMThrowableInteractorComponent::Cleanup(bool bNotify)
{
    const FGuid EndingSession = ActiveContext.SessionId;
    SetComponentTickEnabled(false);
    PreviewAccumulator = 0.f;
    PreviewResult = FJMThrowSimulationResult();
    PreviewPathPoints.Reset();
    NiagaraPathPoints.Reset();
    HidePreviewVisuals(true);
    FlowDistance = 0.f;
    CachedPreviewMaterial = nullptr;
    CachedTrajectoryNiagaraSystem = nullptr;
    PreviewTrajectoryMID = nullptr;
    PreviewFlowMID = nullptr;
    PreviewOrbMID = nullptr;
    PreviewMarkerMID = nullptr;
    bPreviewMaterialPrepared = false;
    ActiveContext = FJMThrowableUseContext();
    CommitDelegate.Unbind();
    SetState(EJMThrowableUseState::Idle);
    if (bNotify && EndingSession.IsValid()) SessionEndedDelegate.ExecuteIfBound(EndingSession);
}
