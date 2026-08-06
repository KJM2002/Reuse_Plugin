#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "JMPrototypeMonster.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPrototypePlayerCaughtSignature, AActor*, PlayerActor);

UCLASS()
class P_060715_API AJMPrototypeMonsterAIController : public AAIController
{
	GENERATED_BODY()

public:
	AJMPrototypeMonsterAIController();
	bool IsTargetCurrentlySensed(AActor* Target) const;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(VisibleAnywhere, Category = "Senses")
	TObjectPtr<UAIPerceptionComponent> MonsterPerception;

	UPROPERTY()
	TObjectPtr<UAISenseConfig_Sight> SightConfig;
};

/** Minimal patrol, sight chase and catch behavior for the first prototype. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeMonster : public ACharacter
{
	GENERATED_BODY()

public:
	AJMPrototypeMonster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Monster|Visual")
	TObjectPtr<UStaticMeshComponent> PrototypeVisual;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Monster|Patrol")
	TArray<TObjectPtr<AActor>> PatrolPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster|Movement", meta = (ClampMin = "0.0"))
	float PatrolSpeed = 180.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster|Movement", meta = (ClampMin = "0.0"))
	float ChaseSpeed = 360.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster|Senses", meta = (ClampMin = "0.1"))
	float LoseSightDelay = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Monster|Catch", meta = (ClampMin = "1.0"))
	float CatchDistance = 110.0f;

	UPROPERTY(BlueprintAssignable, Category = "Monster|Events")
	FJMPrototypePlayerCaughtSignature OnPlayerCaught;

	UFUNCTION(BlueprintCallable, Category = "Monster")
	void ResetMonster();

	void NotifyPlayerSeen(APawn* SeenPawn);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void UpdateMovement();
	void ClearChase();

	TWeakObjectPtr<APawn> ChaseTarget;
	FVector SpawnLocation = FVector::ZeroVector;
	FRotator SpawnRotation = FRotator::ZeroRotator;
	double LastSeenTime = -1.0;
	int32 PatrolIndex = INDEX_NONE;
	FTimerHandle MovementTimer;
};
