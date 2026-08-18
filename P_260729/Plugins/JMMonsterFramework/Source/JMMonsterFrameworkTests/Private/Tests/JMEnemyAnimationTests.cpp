#include "Misc/AutomationTest.h"

#include "Action/JMEnemyActionComponent.h"
#include "Action/JMEnemyActionDefinition.h"
#include "Animation/JMEnemyAnimInstance.h"
#include "Core/JMEnemyBase.h"
#include "Engine/Blueprint.h"
#include "State/JMEnemyStateComponent.h"
#include "Tests/JMEnemyCoreTestTypes.h"
#include "Types/JMEnemyTags.h"
#include "UObject/StrongObjectPtr.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAnimationInitializationTest,
    "JM.MonsterFramework.Animation.Initialization",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAnimationInitializationTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyAnimInstance> Anim(NewObject<UJMEnemyAnimInstance>(Enemy->GetMesh()));
    Anim->InitializeFromEnemy(Enemy.Get());

    TestTrue(TEXT("Presentation caches the enemy once"), Anim->GetEnemyOwner() == Enemy.Get());
    TestEqual(TEXT("Initial state is available without an AnimBP or Animation asset"),
        Anim->CurrentState, JMEnemyTags::State_Idle.GetTag());
    TestEqual(TEXT("No action is represented as an empty tag"),
        Anim->CurrentAction, FGameplayTag::EmptyTag);
    TestFalse(TEXT("Placeholder enemy begins stationary"), Anim->bIsMoving);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAnimationStateDataTest,
    "JM.MonsterFramework.Animation.StateData",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAnimationStateDataTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyAnimInstance> Anim(NewObject<UJMEnemyAnimInstance>(Enemy->GetMesh()));
    Anim->InitializeFromEnemy(Enemy.Get());
    Enemy->GetEnemyStateComponent()->SetState(JMEnemyTags::State_Watcher_Frozen);
    Anim->RefreshPresentationData(0.1f);

    TestEqual(TEXT("Frozen GameplayTag reaches presentation"),
        Anim->CurrentState, JMEnemyTags::State_Watcher_Frozen.GetTag());
    TestTrue(TEXT("AnimBP can query the Frozen parent/leaf contract"),
        Anim->IsInState(JMEnemyTags::State_Watcher_Frozen));
    TestTrue(TEXT("Frozen placeholder speed is zero"), FMath::IsNearlyZero(Anim->Speed));
    TestFalse(TEXT("Frozen placeholder is not moving"), Anim->bIsMoving);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAnimationActionDataTest,
    "JM.MonsterFramework.Animation.ActionData",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAnimationActionDataTest::RunTest(const FString& Parameters)
{
    TStrongObjectPtr<AJMEnemyCoreTestEnemy> Enemy(NewObject<AJMEnemyCoreTestEnemy>());
    TStrongObjectPtr<UJMEnemyActionDefinition_Scream> Scream(
        NewObject<UJMEnemyActionDefinition_Scream>());
    Scream->WindupDuration = 1.0f;
    TArray<TObjectPtr<UJMEnemyActionDefinition>> Definitions = {Scream.Get()};
    Enemy->GetEnemyActionComponent()->InitializeActions(Definitions);

    TStrongObjectPtr<UJMEnemyAnimInstance> Anim(NewObject<UJMEnemyAnimInstance>(Enemy->GetMesh()));
    Anim->InitializeFromEnemy(Enemy.Get());
    TestEqual(TEXT("Scream starts through the existing Action lifecycle"),
        Enemy->GetEnemyActionComponent()->ExecuteAction(
            JMEnemyTags::Action_Scream, FJMEnemyActionContext()),
        EJMEnemyActionExecuteResult::Started);
    TestEqual(TEXT("Current Action reaches presentation"),
        Anim->CurrentAction, JMEnemyTags::Action_Scream.GetTag());
    TestEqual(TEXT("Windup phase reaches presentation"),
        Anim->CurrentActionPhase, EJMEnemyActionPhase::Windup);

    TestTrue(TEXT("Existing cancellation path remains authoritative"),
        Enemy->GetEnemyActionComponent()->CancelCurrentAction());
    TestEqual(TEXT("Cancellation clears presentation action"),
        Anim->CurrentAction, FGameplayTag::EmptyTag);
    TestEqual(TEXT("Cancellation returns presentation phase to Idle"),
        Anim->CurrentActionPhase, EJMEnemyActionPhase::Idle);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMEnemyAnimationSurfaceCrawlerDataTest,
    "JM.MonsterFramework.Animation.SurfaceCrawlerData",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FJMEnemyAnimationSurfaceCrawlerDataTest::RunTest(const FString& Parameters)
{
    UBlueprint* Blueprint = LoadObject<UBlueprint>(nullptr,
        TEXT("/JMMonsterFramework/Reference/Crawler/BP_Enemy_Crawler.BP_Enemy_Crawler"));
    if (!TestNotNull(TEXT("Crawler placeholder Blueprint loads"), Blueprint) || !Blueprint->GeneratedClass)
        return false;
    TStrongObjectPtr<AJMEnemyBase> Crawler(NewObject<AJMEnemyBase>(
        GetTransientPackage(), Blueprint->GeneratedClass));
    TStrongObjectPtr<UJMEnemyAnimInstance> Anim(NewObject<UJMEnemyAnimInstance>(Crawler->GetMesh()));

    const FVector SurfaceUp = FVector::RightVector;
    const FVector LocalForward = FVector::UpVector;
    Crawler->SetActorRotation(FRotationMatrix::MakeFromXZ(LocalForward, SurfaceUp).Rotator());
    Anim->InitializeFromEnemy(Crawler.Get());
    Crawler->SetActorLocation(Crawler->GetActorLocation() + Crawler->GetActorForwardVector() * 30.0f);
    Anim->RefreshPresentationData(0.1f);

    TestTrue(TEXT("Surface-local displacement produces locomotion speed"),
        FMath::IsNearlyEqual(Anim->Speed, 300.0f, 1.0f));
    TestTrue(TEXT("Surface-local forward movement keeps a shared forward direction"),
        FMath::IsNearlyZero(Anim->Direction, 1.0f));
    TestTrue(TEXT("Wall-oriented placeholder reports moving"), Anim->bIsMoving);
    TestFalse(TEXT("No Animation asset is required for surface data"), Anim->bIsFalling);
    return true;
}
