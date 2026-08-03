#include "Misc/AutomationTest.h"
#include "JMThrowSolver.h"
#include "JMThrowableDefinition.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "NiagaraDataInterfaceArrayFloat.h"
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
#include "NiagaraSystem.h"

#if WITH_DEV_AUTOMATION_TESTS
namespace JMThrowablePreviewTests
{
    struct FWorldFixture
    {
        UWorld* World = nullptr;

        FWorldFixture()
        {
            const UWorld::InitializationValues Initialization = UWorld::InitializationValues()
                .AllowAudioPlayback(false)
                .RequiresHitProxies(false)
                .CreatePhysicsScene(true)
                .CreateNavigation(false)
                .CreateAISystem(false)
                .ShouldSimulatePhysics(false)
                .SetTransactional(false);
            World = UWorld::CreateWorld(
                EWorldType::Game,
                false,
                NAME_None,
                nullptr,
                false,
                ERHIFeatureLevel::Num,
                &Initialization);
        }

        ~FWorldFixture()
        {
            if (World)
            {
                World->DestroyWorld(false);
            }
        }

        void AddBlockingWall(float X)
        {
            if (!World)
            {
                return;
            }

            AActor* Wall = World->SpawnActor<AActor>(FVector(X, 0.f, 0.f), FRotator::ZeroRotator);
            UBoxComponent* Collision = NewObject<UBoxComponent>(Wall, TEXT("PreviewTestWall"));
            Wall->SetRootComponent(Collision);
            Collision->SetBoxExtent(FVector(5.f, 100.f, 100.f));
            Collision->SetCollisionProfileName(TEXT("BlockAll"));
            Collision->RegisterComponent();
            World->UpdateWorldComponents(false, false);
        }

        void AddBlockingFloor(float Z)
        {
            if (!World)
            {
                return;
            }

            AActor* Floor = World->SpawnActor<AActor>(FVector(0.f, 0.f, Z - 5.f), FRotator::ZeroRotator);
            UBoxComponent* Collision = NewObject<UBoxComponent>(Floor, TEXT("PreviewTestFloor"));
            Floor->SetRootComponent(Collision);
            Collision->SetBoxExtent(FVector(1000.f, 1000.f, 5.f));
            Collision->SetCollisionProfileName(TEXT("BlockAll"));
            Collision->RegisterComponent();
            World->UpdateWorldComponents(false, false);
        }
    };

    FJMThrowParameters MakeParameters()
    {
        FJMThrowParameters Parameters;
        Parameters.StartPosition = FVector::ZeroVector;
        Parameters.InitialVelocity = FVector(1000.f, 0.f, 0.f);
        Parameters.Gravity = FVector::ZeroVector;
        Parameters.ProjectileRadius = 5.f;
        Parameters.SimulationStep = 0.05f;
        Parameters.MaximumSimulationTime = 0.5f;
        Parameters.CollisionProfile = TEXT("BlockAll");
        Parameters.MaxWallBounces = 1;
        return Parameters;
    }
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewCenteredOriginTest,
    "JM.Throwable.Preview.CenterAlignedOrigin",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewCenteredOriginTest::RunTest(const FString&)
{
    const FVector ViewLocation(100.f, 200.f, 300.f);
    const FVector ViewForward = FVector(1.f, 1.f, .25f).GetSafeNormal();
    const FVector ViewRight = FVector::CrossProduct(FVector::UpVector, ViewForward).GetSafeNormal();
    const FVector Origin =
        FJMThrowSolver::CalculatePreviewVisualOrigin(ViewLocation, ViewForward, 40.f);
    const FVector Offset = Origin - ViewLocation;
    TestTrue(TEXT("Preview origin lies on the camera center ray"),
        FMath::IsNearlyZero(FVector::DotProduct(Offset, ViewRight), KINDA_SMALL_NUMBER));
    TestEqual(TEXT("Preview origin is exactly the authored forward distance"),
        Offset.Size(), 40.0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewFlowWidthTest,
    "JM.Throwable.Preview.FlowNarrowerThanBase",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewFlowWidthTest::RunTest(const FString&)
{
    const UJMThrowableDefinition* Definition = GetDefault<UJMThrowableDefinition>();
    const float FlowWidth = FJMThrowSolver::CalculateFlowWidth(
        Definition->PreviewLineWidth,
        Definition->PreviewFlowWidthMultiplier);
    TestTrue(TEXT("Flow ribbon is narrower than the base ribbon"),
        FlowWidth < Definition->PreviewLineWidth);
    TestEqual(TEXT("Default flow width is 35 percent of base"),
        FlowWidth, Definition->PreviewLineWidth * .35f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableNiagaraPathResampleTest,
    "JM.Throwable.Preview.Niagara.FixedPathResampling",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableNiagaraPathResampleTest::RunTest(const FString&)
{
    const TArray<FVector> Source = {
        FVector(0.f, 0.f, 0.f),
        FVector(25.f, 0.f, 0.f),
        FVector(100.f, 0.f, 0.f)};
    const TArray<FVector> Samples =
        FJMThrowSolver::ResamplePathByDistance(Source, 64);
    TestEqual(TEXT("Niagara receives the authored fixed point count"), Samples.Num(), 64);
    if (Samples.Num() == 64)
    {
        TestTrue(TEXT("First point is preserved exactly"), Samples[0].Equals(Source[0]));
        TestTrue(TEXT("Terminal impact point is preserved exactly"), Samples.Last().Equals(Source.Last()));
        TestTrue(TEXT("Samples are uniform by traveled distance"),
            FMath::IsNearlyEqual(Samples[32].X, 100.f * 32.f / 63.f, .01f));
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableNiagaraDegeneratePathTest,
    "JM.Throwable.Preview.Niagara.DegeneratePathResampling",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableNiagaraDegeneratePathTest::RunTest(const FString&)
{
    const TArray<FVector> Source = {FVector(10.f, 20.f, 30.f)};
    const TArray<FVector> Samples =
        FJMThrowSolver::ResamplePathByDistance(Source, 8);
    TestEqual(TEXT("Single-point paths still provide a stable fixed array"), Samples.Num(), 8);
    TestTrue(TEXT("All degenerate samples remain at the only source point"),
        Samples.ContainsByPredicate(
            [&Source](const FVector& Point) { return Point.Equals(Source[0]); }));
    for (const FVector& Point : Samples)
    {
        TestTrue(TEXT("Degenerate sample matches source"), Point.Equals(Source[0]));
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableNiagaraAssetContractTest,
    "JM.Throwable.Preview.Niagara.AssetContract",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableNiagaraAssetContractTest::RunTest(const FString&)
{
    const UJMThrowableDefinition* Definition = GetDefault<UJMThrowableDefinition>();
    TestEqual(
        TEXT("Niagara is preferred by default"),
        Definition->PreviewRendererMode,
        EJMThrowablePreviewRendererMode::NiagaraPreferred);
    TestEqual(
        TEXT("The default path particle count is fixed"),
        Definition->NiagaraPathSampleCount,
        64);
    TestEqual(
        TEXT("Default system belongs to the portable plugin mount"),
        Definition->TrajectoryNiagaraSystem.ToSoftObjectPath().ToString(),
        FString(TEXT(
            "/JMThrowable/Effects/NS_JMThrowableTrajectory."
            "NS_JMThrowableTrajectory")));
    UNiagaraSystem* System =
        Definition->TrajectoryNiagaraSystem.LoadSynchronous();
    TestNotNull(
        TEXT("Plugin-owned trajectory Niagara system loads"),
        System);
    if (System)
    {
        TestEqual(
            TEXT("Trajectory system owns path, moving-dot, and impact-dot emitters"),
            System->GetEmitterHandles().Num(),
            3);
        const FNiagaraVariable PathArray(
            FNiagaraTypeDefinition(UNiagaraDataInterfaceArrayPosition::StaticClass()),
            TEXT("User.PathPoints"));
        TestTrue(
            TEXT("Trajectory system exposes the runtime path array"),
            System->GetExposedParameters().IndexOf(PathArray) != INDEX_NONE);
        UNiagaraComponent* Component =
            NewObject<UNiagaraComponent>(GetTransientPackage());
        Component->SetAsset(System);
        UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayPosition(
            Component,
            TEXT("User.PathPoints"),
            {FVector::ZeroVector, FVector(100.f, 0.f, 0.f)});
        TestTrue(
            TEXT("Runtime writes a Position Array override with the matching type"),
            Component->GetOverrideParameters().IndexOf(PathArray) != INDEX_NONE);
        const FNiagaraVariable BaseColor(
            FNiagaraTypeDefinition::GetColorDef(),
            TEXT("User.BaseColor"));
        TestTrue(
            TEXT("Trajectory system exposes the faint ribbon color and alpha"),
            System->GetExposedParameters().IndexOf(BaseColor) != INDEX_NONE);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableBounceMathTest, "JM.Throwable.Throw.BounceMath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableBounceMathTest::RunTest(const FString&)
{
    const FVector V = FJMThrowSolver::ResolveWallBounce(FVector(100, 0, -50), FVector::UpVector, .5f, .8f);
    TestEqual(TEXT("Tangential damping"), V.X, 80.0);
    TestEqual(TEXT("Normal restitution"), V.Z, 25.0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableLowRestitutionBounceTest,
    "JM.Throwable.Physics.LowRestitutionBounce",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableLowRestitutionBounceTest::RunTest(const FString&)
{
    const FVector Incoming(100.f, 40.f, -10.f);
    const FVector Bounce = FJMThrowSolver::ResolveWallBounce(
        Incoming,
        FVector::BackwardVector,
        .08f,
        .5f);
    TestEqual(TEXT("Normal speed retains only eight percent"), Bounce.X, -8.0);
    TestEqual(TEXT("Tangential speed is halved"), Bounce.Y, 20.0);
    TestEqual(TEXT("Vertical tangent is halved"), Bounce.Z, -5.0);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableGravityAfterWallTest,
    "JM.Throwable.Physics.GravityContinuesAfterWallHit",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableGravityAfterWallTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    if (!Fixture.World) return false;
    Fixture.AddBlockingWall(100.f);
    FJMThrowParameters Parameters = JMThrowablePreviewTests::MakeParameters();
    Parameters.Gravity = FVector(0.f, 0.f, -980.f);
    Parameters.SimulationStep = .1f;
    Parameters.BounceRestitution = .08f;
    Parameters.TangentialDamping = .5f;
    FJMThrowSimulationState State;
    State.Position = Parameters.StartPosition;
    State.Velocity = Parameters.InitialVelocity;
    FHitResult WallHit;
    FJMThrowSolver::Step(Fixture.World, Parameters, State, &WallHit);
    TestTrue(TEXT("First step hits the wall"), WallHit.bBlockingHit);
    const float VerticalSpeedAfterWall = State.Velocity.Z;
    FHitResult NextHit;
    FJMThrowSolver::Step(Fixture.World, Parameters, State, &NextHit);
    TestTrue(TEXT("Gravity makes vertical speed more negative after the wall"),
        State.Velocity.Z < VerticalSpeedAfterWall);
    TestFalse(TEXT("Projectile is not forced to rest by its first wall hit"), State.bResting);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableFloorSettlesTest,
    "JM.Throwable.Physics.FloorSettles",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableFloorSettlesTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    if (!Fixture.World) return false;
    Fixture.AddBlockingFloor(0.f);
    FJMThrowParameters Parameters = JMThrowablePreviewTests::MakeParameters();
    Parameters.StartPosition = FVector(0.f, 0.f, 100.f);
    Parameters.InitialVelocity = FVector(400.f, 0.f, -100.f);
    Parameters.Gravity = FVector(0.f, 0.f, -980.f);
    Parameters.SimulationStep = 1.f / 60.f;
    Parameters.MaximumSimulationTime = 3.f;
    Parameters.FloorFriction = .18f;
    Parameters.FloorStopSpeed = 50.f;
    Parameters.MaxFloorBounces = 3;
    Parameters.FloorRestitution = .2f;
    Parameters.FloorTangentialDamping = .6f;
    Parameters.FloorBounceDecay = .6f;
    Parameters.FloorBounceStopSpeed = 80.f;
    const FJMThrowSimulationResult Result =
        FJMThrowSolver::Simulate(Fixture.World, Parameters);
    TestTrue(TEXT("Floor contact reaches a stable rest"), Result.bReachedRest);
    TestTrue(TEXT("Floor performs at least one soft bounce before settling"),
        Result.FloorBounceCount > 0);
    TestTrue(TEXT("Floor bounce count respects its authored cap"),
        Result.FloorBounceCount <= Parameters.MaxFloorBounces);
    TestTrue(TEXT("Projectile advances along the floor before settling"),
        Result.FinalRestPoint.X > Parameters.StartPosition.X);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableFloorBounceDecayTest,
    "JM.Throwable.Physics.FloorBounceDecays",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableFloorBounceDecayTest::RunTest(const FString&)
{
    const FVector Incoming(300.f, 0.f, -500.f);
    const FVector First = FJMThrowSolver::ResolveFloorBounce(
        Incoming, FVector::UpVector, .2f, .6f, .6f, 0);
    const FVector Second = FJMThrowSolver::ResolveFloorBounce(
        Incoming, FVector::UpVector, .2f, .6f, .6f, 1);
    const FVector Third = FJMThrowSolver::ResolveFloorBounce(
        Incoming, FVector::UpVector, .2f, .6f, .6f, 2);
    TestEqual(TEXT("First floor rebound retains twenty percent normal speed"),
        First.Z, 100.0);
    TestTrue(TEXT("Second rebound is weaker than the first"), Second.Z < First.Z);
    TestTrue(TEXT("Third rebound is weaker than the second"), Third.Z < Second.Z);
    TestEqual(TEXT("Floor tangent retains sixty percent speed"), First.X, 180.0);
    TestTrue(TEXT("Sufficient incoming speed can bounce"),
        FJMThrowSolver::ShouldFloorBounce(500.f, 0, 3, 80.f));
    TestFalse(TEXT("Low incoming speed transitions to settling"),
        FJMThrowSolver::ShouldFloorBounce(70.f, 1, 3, 80.f));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableOneBounceLimitTest, "JM.Throwable.Throw.OneBounceConfiguration",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableOneBounceLimitTest::RunTest(const FString&)
{
    FJMThrowParameters P;
    TestEqual(TEXT("Default permits exactly one non-floor bounce"), P.MaxWallBounces, 1);
    TestTrue(TEXT("Default floor threshold distinguishes walkable normals"), P.FloorNormalThreshold > 0.f);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableSurfaceClassificationTest, "JM.Throwable.Throw.SurfaceClassification",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableSurfaceClassificationTest::RunTest(const FString&)
{
    TestEqual(TEXT("Up normal is floor"), FJMThrowSolver::ClassifySurface(FVector::UpVector, .7f), EJMThrowableSurfaceType::Floor);
    TestEqual(TEXT("Horizontal normal is wall"), FJMThrowSolver::ClassifySurface(FVector::ForwardVector, .7f), EJMThrowableSurfaceType::Wall);
    TestEqual(TEXT("Down normal is ceiling"), FJMThrowSolver::ClassifySurface(FVector::DownVector, .7f), EJMThrowableSurfaceType::Ceiling);
    TestTrue(TEXT("First wall can bounce"), FJMThrowSolver::ShouldBounce(EJMThrowableSurfaceType::Wall, 0, 1));
    TestFalse(TEXT("Second wall cannot bounce"), FJMThrowSolver::ShouldBounce(EJMThrowableSurfaceType::Wall, 1, 1));
    TestFalse(TEXT("Floor never bounces"), FJMThrowSolver::ShouldBounce(EJMThrowableSurfaceType::Floor, 0, 1));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewFirstHitTest,
    "JM.Throwable.Preview.FirstBlockingHitStopsPath",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewFirstHitTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    TestNotNull(TEXT("Test world"), Fixture.World);
    if (!Fixture.World) return false;
    Fixture.AddBlockingWall(100.f);

    const FJMThrowSimulationResult Preview =
        FJMThrowSolver::SimulatePreview(Fixture.World, JMThrowablePreviewTests::MakeParameters());
    TestEqual(TEXT("Preview records the first impact"), Preview.ImpactPoints.Num(), 1);
    TestTrue(TEXT("Preview has a path"), Preview.Points.Num() >= 2);
    if (Preview.ImpactPoints.Num() == 1 && Preview.Points.Num() >= 2)
    {
        TestTrue(TEXT("Last preview point is the exact impact"),
            Preview.Points.Last().Equals(Preview.ImpactPoints[0], KINDA_SMALL_NUMBER));
        const int32 ImpactPathIndex = Preview.Points.IndexOfByPredicate(
            [&Preview](const FVector& Point)
            {
                return Point.Equals(Preview.ImpactPoints[0], KINDA_SMALL_NUMBER);
            });
        TestEqual(TEXT("First impact is the terminal path point"),
            ImpactPathIndex, Preview.Points.Num() - 1);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewSingleImpactTest,
    "JM.Throwable.Preview.SingleImpact",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewSingleImpactTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    if (!Fixture.World) return false;
    Fixture.AddBlockingWall(100.f);
    const FJMThrowSimulationResult Preview =
        FJMThrowSolver::SimulatePreview(Fixture.World, JMThrowablePreviewTests::MakeParameters());
    TestTrue(TEXT("Preview has at most one impact"), Preview.ImpactPoints.Num() <= 1);
    TestEqual(TEXT("Impact points and normals stay paired"),
        Preview.ImpactPoints.Num(), Preview.ImpactNormals.Num());
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewNoHitTest,
    "JM.Throwable.Preview.NoHit",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewNoHitTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    if (!Fixture.World) return false;
    const FJMThrowSimulationResult Preview =
        FJMThrowSolver::SimulatePreview(Fixture.World, JMThrowablePreviewTests::MakeParameters());
    TestEqual(TEXT("No-hit preview has no impact"), Preview.ImpactPoints.Num(), 0);
    TestTrue(TEXT("No-hit preview reaches its authored time path"), Preview.Points.Num() > 2);
    TestFalse(TEXT("No-hit preview does not report rest"), Preview.bReachedRest);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowablePreviewRuntimeBounceTest,
    "JM.Throwable.Preview.DoesNotChangeRuntimeBounce",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowablePreviewRuntimeBounceTest::RunTest(const FString&)
{
    JMThrowablePreviewTests::FWorldFixture Fixture;
    if (!Fixture.World) return false;
    Fixture.AddBlockingWall(100.f);
    const FJMThrowParameters Parameters = JMThrowablePreviewTests::MakeParameters();
    const FJMThrowSimulationResult Preview = FJMThrowSolver::SimulatePreview(Fixture.World, Parameters);
    const FJMThrowSimulationResult Runtime = FJMThrowSolver::Simulate(Fixture.World, Parameters);
    TestEqual(TEXT("Runtime still resolves one authored bounce"), Runtime.WallBounceCount, 1);
    TestTrue(TEXT("Runtime simulation continues after preview stops"),
        Runtime.Points.Num() > Preview.Points.Num());
    TestTrue(TEXT("Wall response remains a bounce"),
        FJMThrowSolver::ShouldBounce(EJMThrowableSurfaceType::Wall, 0, Parameters.MaxWallBounces));
    return true;
}
#endif
