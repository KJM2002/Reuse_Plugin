#include "Components/JMHarpoonWireRouteComponent.h"

#include "Components/PrimitiveComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

UJMHarpoonWireRouteComponent::UJMHarpoonWireRouteComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderFinder(
        TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    SegmentMesh = CylinderFinder.Object;
}

void UJMHarpoonWireRouteComponent::InitializeWire(
    USceneComponent* InStartComponent,
    UStaticMesh* InSegmentMesh,
    UMaterialInterface* InMaterial,
    float InWireWidth,
    const FJMHarpoonWireRouteSettings& InSettings)
{
    StartComponent = InStartComponent;
    if (InSegmentMesh)
    {
        SegmentMesh = InSegmentMesh;
    }
    WireMaterial = InMaterial;
    WireWidth = FMath::Max(0.1f, InWireWidth);
    Settings = InSettings;
    Settings.MaxContactPoints = FMath::Clamp(Settings.MaxContactPoints, 0, 3);
    Settings.MaxRenderSegments = FMath::Clamp(Settings.MaxRenderSegments, 4, 24);
    EnsureRenderComponents();
    ResetWireRoute();
}

void UJMHarpoonWireRouteComponent::SetEndComponent(USceneComponent* InEndComponent)
{
    if (EndComponent != InEndComponent)
    {
        EndComponent = InEndComponent;
        ResetWireRoute();
    }
}

void UJMHarpoonWireRouteComponent::SetWireVisible(bool bVisible)
{
    bWireVisible = bVisible;
    if (!bWireVisible)
    {
        HideUnusedSegments(0);
    }
}

void UJMHarpoonWireRouteComponent::UpdateWire(
    float DeltaTime,
    EJMHarpoonWireVisualState State,
    float AvailableLength)
{
    if (!bWireVisible || State == EJMHarpoonWireVisualState::Hidden
        || !IsValid(StartComponent) || !IsValid(EndComponent))
    {
        HideUnusedSegments(0);
        return;
    }

    EnsureRenderComponents();
    const FVector RouteStart = StartComponent->GetComponentLocation();
    const FVector RouteEnd = EndComponent->GetComponentLocation();
    const float UpdateInterval = 1.0f / FMath::Max(Settings.CollisionUpdateRate, 1.0f);
    RouteUpdateAccumulator += FMath::Max(0.0f, DeltaTime);
    const bool bEndpointsMoved = FVector::DistSquared(RouteStart, LastRouteStart) > FMath::Square(5.0f)
        || FVector::DistSquared(RouteEnd, LastRouteEnd) > FMath::Square(5.0f);
    const bool bEndpointTeleported = FVector::DistSquared(RouteStart, LastRouteStart) > FMath::Square(100.0f)
        || FVector::DistSquared(RouteEnd, LastRouteEnd) > FMath::Square(100.0f);

    if (State == EJMHarpoonWireVisualState::Flying)
    {
        Contacts.Reset();
        RouteUpdateAccumulator = 0.0f;
        bNeedsRouteUpdate = true;
    }
    else if (bEndpointTeleported
        || (RouteUpdateAccumulator >= UpdateInterval
            && (bNeedsRouteUpdate || bEndpointsMoved || !Contacts.IsEmpty())))
    {
        const float RouteDeltaTime = FMath::Min(
            FMath::Max(RouteUpdateAccumulator, UpdateInterval),
            0.1f);
        RouteUpdateAccumulator = 0.0f;
        UpdateContactRoute(RouteDeltaTime);
        LastRouteStart = RouteStart;
        LastRouteEnd = RouteEnd;
        bNeedsRouteUpdate = false;
    }

    ApplyRenderPoints(BuildRenderPoints(State, AvailableLength), DeltaTime);
}

void UJMHarpoonWireRouteComponent::ResetWireRoute()
{
    Contacts.Reset();
    SmoothedRenderPoints.Reset();
    RouteUpdateAccumulator = 0.0f;
    bNeedsRouteUpdate = true;
    LastRouteStart = IsValid(StartComponent)
        ? StartComponent->GetComponentLocation()
        : FVector::ZeroVector;
    LastRouteEnd = IsValid(EndComponent)
        ? EndComponent->GetComponentLocation()
        : FVector::ZeroVector;
    HideUnusedSegments(0);
}

void UJMHarpoonWireRouteComponent::DestroyWire()
{
    HideUnusedSegments(0);
    for (USplineMeshComponent* Segment : RenderSegments)
    {
        if (Segment)
        {
            Segment->DestroyComponent();
        }
    }
    RenderSegments.Reset();
    if (RouteSpline)
    {
        RouteSpline->DestroyComponent();
        RouteSpline = nullptr;
    }
    Contacts.Reset();
    SmoothedRenderPoints.Reset();
    StartComponent = nullptr;
    EndComponent = nullptr;
}

FVector UJMHarpoonWireRouteComponent::MakeSurfaceContactPoint(
    const FVector& SurfacePoint,
    const FVector& SurfaceNormal,
    float CollisionRadius,
    float SurfaceOffset)
{
    const FVector SafeNormal = SurfaceNormal.GetSafeNormal(SMALL_NUMBER, FVector::UpVector);
    return SurfacePoint + SafeNormal * (FMath::Max(0.0f, CollisionRadius) + FMath::Max(0.0f, SurfaceOffset));
}

FVector UJMHarpoonWireRouteComponent::EvaluateSagPoint(
    const FVector& Start,
    const FVector& End,
    float Alpha,
    float SagAmount)
{
    const float SafeAlpha = FMath::Clamp(Alpha, 0.0f, 1.0f);
    const float Parabola = 4.0f * SafeAlpha * (1.0f - SafeAlpha);
    return FMath::Lerp(Start, End, SafeAlpha)
        + FVector::DownVector * FMath::Max(0.0f, SagAmount) * Parabola;
}

void UJMHarpoonWireRouteComponent::EnsureRenderComponents()
{
    AActor* Owner = GetOwner();
    if (!Owner || !Owner->GetRootComponent())
    {
        return;
    }

    if (!RouteSpline)
    {
        RouteSpline = NewObject<USplineComponent>(Owner, TEXT("JMHarpoonWireRouteSpline"));
        Owner->AddInstanceComponent(RouteSpline);
        RouteSpline->SetupAttachment(Owner->GetRootComponent());
        RouteSpline->SetMobility(EComponentMobility::Movable);
        RouteSpline->RegisterComponent();
    }

    const int32 TargetCount = FMath::Clamp(Settings.MaxRenderSegments, 4, 24);
    while (RenderSegments.Num() < TargetCount)
    {
        const FName SegmentName(*FString::Printf(TEXT("JMHarpoonWireSplineMesh_%02d"), RenderSegments.Num()));
        USplineMeshComponent* Segment = NewObject<USplineMeshComponent>(Owner, SegmentName);
        Owner->AddInstanceComponent(Segment);
        Segment->SetupAttachment(RouteSpline);
        Segment->SetMobility(EComponentMobility::Movable);
        Segment->SetForwardAxis(ESplineMeshAxis::Z, false);
        Segment->SetStaticMesh(SegmentMesh);
        if (WireMaterial)
        {
            Segment->SetMaterial(0, WireMaterial);
        }
        Segment->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        Segment->SetGenerateOverlapEvents(false);
        Segment->SetCanEverAffectNavigation(false);
        Segment->SetCastShadow(false);
        Segment->SetOnlyOwnerSee(true);
        Segment->SetVisibility(false);
        Segment->RegisterComponent();
        RenderSegments.Add(Segment);
    }
}

void UJMHarpoonWireRouteComponent::UpdateContactRoute(float RouteDeltaTime)
{
    if (!IsValid(StartComponent) || !IsValid(EndComponent))
    {
        Contacts.Reset();
        return;
    }

    for (FWireContact& Contact : Contacts)
    {
        Contact.Age += RouteDeltaTime;
    }

    for (int32 Index = Contacts.Num() - 1; Index >= 0; --Index)
    {
        const FVector PreviousPoint = Index == 0
            ? StartComponent->GetComponentLocation()
            : Contacts[Index - 1].Position;
        const FVector NextPoint = Index == Contacts.Num() - 1
            ? EndComponent->GetComponentLocation()
            : Contacts[Index + 1].Position;

        FHitResult KeepHit;
        const bool bStillBlocked = SweepSpan(
            PreviousPoint,
            NextPoint,
            Settings.CollisionRadius + Settings.ContactReleaseMargin,
            KeepHit);
        if (!bStillBlocked && Contacts[Index].Age >= Settings.MinimumContactTime)
        {
            Contacts.RemoveAt(Index);
            continue;
        }
        if (bStillBlocked)
        {
            UpdateContact(Contacts[Index], PreviousPoint, NextPoint, RouteDeltaTime);
        }
    }

    if (Contacts.Num() < Settings.MaxContactPoints)
    {
        TryInsertContact();
    }
}

void UJMHarpoonWireRouteComponent::UpdateContact(
    FWireContact& Contact,
    const FVector& PreviousPoint,
    const FVector& NextPoint,
    float DeltaTime)
{
    FHitResult Hit;
    if (!SweepSpan(PreviousPoint, NextPoint, Settings.CollisionRadius, Hit))
    {
        return;
    }

    const FVector HitNormal = Hit.ImpactNormal.GetSafeNormal(SMALL_NUMBER, Contact.Normal);
    Contact.Normal = FMath::VInterpTo(
        Contact.Normal,
        HitNormal,
        DeltaTime,
        Settings.ContactNormalInterpSpeed).GetSafeNormal(SMALL_NUMBER, HitNormal);
    const FVector SurfacePoint = Hit.bStartPenetrating ? Hit.Location : Hit.ImpactPoint;
    const FVector DesiredPosition = MakeSurfaceContactPoint(
        SurfacePoint,
        Contact.Normal,
        Settings.CollisionRadius,
        Settings.SurfaceOffset);
    FVector NewPosition = FMath::VInterpTo(
        Contact.Position,
        DesiredPosition,
        DeltaTime,
        Settings.ContactPositionInterpSpeed);
    const FVector Correction = NewPosition - Contact.Position;
    if (Settings.MaximumContactCorrectionPerUpdate > 0.0f
        && Correction.SizeSquared() > FMath::Square(Settings.MaximumContactCorrectionPerUpdate))
    {
        NewPosition = Contact.Position
            + Correction.GetSafeNormal() * Settings.MaximumContactCorrectionPerUpdate;
    }
    Contact.Position = NewPosition;
    Contact.SurfaceComponent = Hit.GetComponent();
}

bool UJMHarpoonWireRouteComponent::TryInsertContact()
{
    const TArray<FVector> Knots = BuildRouteKnots();
    for (int32 SpanIndex = 0; SpanIndex + 1 < Knots.Num(); ++SpanIndex)
    {
        FHitResult Hit;
        if (!SweepSpan(Knots[SpanIndex], Knots[SpanIndex + 1], Settings.CollisionRadius, Hit))
        {
            continue;
        }

        const FVector HitNormal = Hit.ImpactNormal.GetSafeNormal(SMALL_NUMBER, FVector::UpVector);
        const FVector SurfacePoint = Hit.bStartPenetrating ? Hit.Location : Hit.ImpactPoint;
        const FVector Candidate = MakeSurfaceContactPoint(
            SurfacePoint,
            HitNormal,
            Settings.CollisionRadius,
            Settings.SurfaceOffset);
        if (IsNearExistingKnot(Candidate, Knots))
        {
            continue;
        }

        FWireContact NewContact;
        NewContact.Position = Candidate;
        NewContact.Normal = HitNormal;
        NewContact.SurfaceComponent = Hit.GetComponent();
        Contacts.Insert(NewContact, FMath::Clamp(SpanIndex, 0, Contacts.Num()));
        return true;
    }
    return false;
}

bool UJMHarpoonWireRouteComponent::SweepSpan(
    const FVector& Start,
    const FVector& End,
    float Radius,
    FHitResult& OutHit) const
{
    UWorld* World = GetWorld();
    if (!World)
    {
        return false;
    }

    const FVector Span = End - Start;
    const float SpanLength = Span.Size();
    const float SafeRadius = FMath::Max(0.5f, Radius);
    if (SpanLength <= SafeRadius * 2.1f)
    {
        return false;
    }
    const FVector Direction = Span / SpanLength;
    const FVector SafeStart = Start + Direction * SafeRadius;
    const FVector SafeEnd = End - Direction * SafeRadius;

    FCollisionQueryParams QueryParams(SCENE_QUERY_STAT(JMHarpoonWireRouteSweep), false, GetOwner());
    if (IsValid(EndComponent) && EndComponent->GetOwner())
    {
        QueryParams.AddIgnoredActor(EndComponent->GetOwner());
    }
    FCollisionObjectQueryParams ObjectParams;
    ObjectParams.AddObjectTypesToQuery(ECC_WorldStatic);
    if (Settings.bCollideWithWorldDynamic)
    {
        ObjectParams.AddObjectTypesToQuery(ECC_WorldDynamic);
    }
    return World->SweepSingleByObjectType(
        OutHit,
        SafeStart,
        SafeEnd,
        FQuat::Identity,
        ObjectParams,
        FCollisionShape::MakeSphere(SafeRadius),
        QueryParams);
}

bool UJMHarpoonWireRouteComponent::IsNearExistingKnot(
    const FVector& Point,
    const TArray<FVector>& Knots) const
{
    const float MergeDistanceSquared = FMath::Square(FMath::Max(1.0f, Settings.ContactMergeDistance));
    for (const FVector& Knot : Knots)
    {
        if (FVector::DistSquared(Point, Knot) <= MergeDistanceSquared)
        {
            return true;
        }
    }
    return false;
}

TArray<FVector> UJMHarpoonWireRouteComponent::BuildRouteKnots() const
{
    TArray<FVector> Knots;
    if (!IsValid(StartComponent) || !IsValid(EndComponent))
    {
        return Knots;
    }
    Knots.Reserve(Contacts.Num() + 2);
    Knots.Add(StartComponent->GetComponentLocation());
    for (const FWireContact& Contact : Contacts)
    {
        Knots.Add(Contact.Position);
    }
    Knots.Add(EndComponent->GetComponentLocation());
    return Knots;
}

TArray<FVector> UJMHarpoonWireRouteComponent::BuildRenderPoints(
    EJMHarpoonWireVisualState State,
    float AvailableLength) const
{
    const TArray<FVector> Knots = BuildRouteKnots();
    TArray<FVector> Points;
    if (Knots.Num() < 2)
    {
        return Points;
    }

    float RouteLength = 0.0f;
    for (int32 Index = 0; Index + 1 < Knots.Num(); ++Index)
    {
        RouteLength += FVector::Distance(Knots[Index], Knots[Index + 1]);
    }
    const bool bAllowSag = State == EJMHarpoonWireVisualState::Embedded && Contacts.IsEmpty();
    const float SagAmount = bAllowSag
        ? FMath::Min(Settings.MaximumSag, FMath::Max(0.0f, AvailableLength - RouteLength) * Settings.SagScale)
        : 0.0f;

    Points.Add(Knots[0]);
    int32 UsedSegments = 0;
    for (int32 SpanIndex = 0; SpanIndex + 1 < Knots.Num(); ++SpanIndex)
    {
        const int32 RemainingSpans = Knots.Num() - SpanIndex - 1;
        const int32 RemainingBudget = FMath::Max(1, Settings.MaxRenderSegments - UsedSegments);
        const float SpanLength = FVector::Distance(Knots[SpanIndex], Knots[SpanIndex + 1]);
        const int32 SpanSegments = FMath::Clamp(
            FMath::CeilToInt(SpanLength / FMath::Max(1.0f, Settings.RenderSegmentLength)),
            1,
            FMath::Max(1, RemainingBudget - (RemainingSpans - 1)));
        for (int32 SegmentIndex = 1; SegmentIndex <= SpanSegments; ++SegmentIndex)
        {
            const float Alpha = static_cast<float>(SegmentIndex) / static_cast<float>(SpanSegments);
            Points.Add(EvaluateSagPoint(
                Knots[SpanIndex],
                Knots[SpanIndex + 1],
                Alpha,
                Contacts.IsEmpty() ? SagAmount : 0.0f));
        }
        UsedSegments += SpanSegments;
    }
    return Points;
}

void UJMHarpoonWireRouteComponent::ApplyRenderPoints(
    const TArray<FVector>& TargetPoints,
    float DeltaTime)
{
    if (!RouteSpline || TargetPoints.Num() < 2)
    {
        HideUnusedSegments(0);
        return;
    }

    if (SmoothedRenderPoints.Num() != TargetPoints.Num())
    {
        SmoothedRenderPoints = TargetPoints;
    }
    else
    {
        for (int32 Index = 0; Index < TargetPoints.Num(); ++Index)
        {
            SmoothedRenderPoints[Index] = FMath::VInterpTo(
                SmoothedRenderPoints[Index],
                TargetPoints[Index],
                DeltaTime,
                Settings.RenderPointInterpSpeed);
        }
        SmoothedRenderPoints[0] = TargetPoints[0];
        SmoothedRenderPoints.Last() = TargetPoints.Last();
    }

    const FTransform SplineTransform = RouteSpline->GetComponentTransform();
    const float CrossSectionScale = WireWidth / 100.0f;
    const int32 SegmentCount = FMath::Min(
        SmoothedRenderPoints.Num() - 1,
        RenderSegments.Num());
    for (int32 Index = 0; Index < SegmentCount; ++Index)
    {
        USplineMeshComponent* Segment = RenderSegments[Index];
        if (!Segment)
        {
            continue;
        }
        const FVector LocalStart = SplineTransform.InverseTransformPosition(SmoothedRenderPoints[Index]);
        const FVector LocalEnd = SplineTransform.InverseTransformPosition(SmoothedRenderPoints[Index + 1]);
        const FVector LocalTangent = LocalEnd - LocalStart;
        Segment->SetStartAndEnd(LocalStart, LocalTangent, LocalEnd, LocalTangent, false);
        Segment->SetStartScale(FVector2D(CrossSectionScale), false);
        Segment->SetEndScale(FVector2D(CrossSectionScale), false);
        Segment->SetVisibility(bWireVisible, true);
        Segment->UpdateMesh();
    }
    VisibleSegmentCount = SegmentCount;
    HideUnusedSegments(SegmentCount);
}

void UJMHarpoonWireRouteComponent::HideUnusedSegments(int32 FirstUnusedIndex)
{
    for (int32 Index = FMath::Max(0, FirstUnusedIndex); Index < RenderSegments.Num(); ++Index)
    {
        if (RenderSegments[Index])
        {
            RenderSegments[Index]->SetVisibility(false, true);
        }
    }
    if (FirstUnusedIndex <= 0)
    {
        VisibleSegmentCount = 0;
    }
}
