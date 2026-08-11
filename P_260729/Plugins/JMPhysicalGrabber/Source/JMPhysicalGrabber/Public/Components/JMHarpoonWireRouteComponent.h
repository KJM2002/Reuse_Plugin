#pragma once

#include "Components/ActorComponent.h"
#include "JMHarpoonWireRouteComponent.generated.h"

class UMaterialInterface;
class UPrimitiveComponent;
class USceneComponent;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;

UENUM()
enum class EJMHarpoonWireVisualState : uint8
{
    Hidden,
    Flying,
    Embedded,
    Retracting
};

USTRUCT(BlueprintType)
struct JMPHYSICALGRABBER_API FJMHarpoonWireRouteSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.5", Units="cm"))
    float CollisionRadius = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="cm"))
    float SurfaceOffset = 0.75f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="1.0", ClampMax="60.0", Units="Hz"))
    float CollisionUpdateRate = 25.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0", ClampMax="3"))
    int32 MaxContactPoints = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="s"))
    float MinimumContactTime = 0.15f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="cm"))
    float ContactReleaseMargin = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="cm"))
    float ContactMergeDistance = 12.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.1"))
    float ContactPositionInterpSpeed = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.1"))
    float ContactNormalInterpSpeed = 14.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="cm"))
    float MaximumContactCorrectionPerUpdate = 15.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="1.0", Units="cm"))
    float RenderSegmentLength = 120.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="4", ClampMax="24"))
    int32 MaxRenderSegments = 16;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.1"))
    float RenderPointInterpSpeed = 28.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0"))
    float SagScale = 0.6f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route", meta=(ClampMin="0.0", Units="cm"))
    float MaximumSag = 25.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Route")
    bool bCollideWithWorldDynamic = false;
};

/**
 * Stable presentation-only harpoon wire. It uses a bounded set of swept contact points and
 * spline meshes instead of CableComponent particle collision. Gameplay pulling remains external.
 */
UCLASS(ClassGroup=(JM), Transient)
class JMPHYSICALGRABBER_API UJMHarpoonWireRouteComponent final : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHarpoonWireRouteComponent();

    void InitializeWire(
        USceneComponent* InStartComponent,
        UStaticMesh* InSegmentMesh,
        UMaterialInterface* InMaterial,
        float InWireWidth,
        const FJMHarpoonWireRouteSettings& InSettings);
    void SetEndComponent(USceneComponent* InEndComponent);
    void SetWireVisible(bool bVisible);
    void UpdateWire(float DeltaTime, EJMHarpoonWireVisualState State, float AvailableLength);
    void ResetWireRoute();
    void DestroyWire();

    int32 GetContactCount() const { return Contacts.Num(); }
    int32 GetVisibleSegmentCount() const { return VisibleSegmentCount; }

    static FVector MakeSurfaceContactPoint(
        const FVector& SurfacePoint,
        const FVector& SurfaceNormal,
        float CollisionRadius,
        float SurfaceOffset);

    static FVector EvaluateSagPoint(
        const FVector& Start,
        const FVector& End,
        float Alpha,
        float SagAmount);

private:
    struct FWireContact
    {
        FVector Position = FVector::ZeroVector;
        FVector Normal = FVector::UpVector;
        TWeakObjectPtr<UPrimitiveComponent> SurfaceComponent;
        float Age = 0.0f;
    };

    void EnsureRenderComponents();
    void UpdateContactRoute(float RouteDeltaTime);
    void UpdateContact(FWireContact& Contact, const FVector& PreviousPoint, const FVector& NextPoint, float DeltaTime);
    bool TryInsertContact();
    bool SweepSpan(const FVector& Start, const FVector& End, float Radius, FHitResult& OutHit) const;
    bool IsNearExistingKnot(const FVector& Point, const TArray<FVector>& Knots) const;
    TArray<FVector> BuildRouteKnots() const;
    TArray<FVector> BuildRenderPoints(EJMHarpoonWireVisualState State, float AvailableLength) const;
    void ApplyRenderPoints(const TArray<FVector>& TargetPoints, float DeltaTime);
    void HideUnusedSegments(int32 FirstUnusedIndex);

    UPROPERTY(Transient)
    TObjectPtr<USceneComponent> StartComponent;

    UPROPERTY(Transient)
    TObjectPtr<USceneComponent> EndComponent;

    UPROPERTY(Transient)
    TObjectPtr<USplineComponent> RouteSpline;

    UPROPERTY(Transient)
    TArray<TObjectPtr<USplineMeshComponent>> RenderSegments;

    UPROPERTY(Transient)
    TObjectPtr<UStaticMesh> SegmentMesh;

    UPROPERTY(Transient)
    TObjectPtr<UMaterialInterface> WireMaterial;

    FJMHarpoonWireRouteSettings Settings;
    TArray<FWireContact> Contacts;
    TArray<FVector> SmoothedRenderPoints;
    FVector LastRouteStart = FVector::ZeroVector;
    FVector LastRouteEnd = FVector::ZeroVector;
    float WireWidth = 1.2f;
    float RouteUpdateAccumulator = 0.0f;
    int32 VisibleSegmentCount = 0;
    bool bWireVisible = false;
    bool bNeedsRouteUpdate = true;
};
