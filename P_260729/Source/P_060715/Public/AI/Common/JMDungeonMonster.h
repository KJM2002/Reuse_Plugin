#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "JMDungeonMonster.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
class UAudioComponent;
class UBehaviorTree;
class UBlackboardComponent;
class UCapsuleComponent;
class UPointLightComponent;
class UPrimitiveComponent;
class USceneComponent;
class USoundBase;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EJMDungeonMonsterState : uint8
{
	Dormant,
	Patrol,
	Suspicious,
	Investigate,
	Chase,
	AttackWarning,
	Search,
	Return
};

UENUM(BlueprintType)
enum class EJMDungeonPatrolMode : uint8
{
	/** Visit every authored patrol point in order and wrap back to the first point. */
	ContinuousLoop,
	/** Stay at the authored home/spawn position while idle. Special reactions can still move the monster. */
	Stationary
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMDungeonMonsterStateChangedSignature,
	EJMDungeonMonsterState, OldState, EJMDungeonMonsterState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMDungeonMonsterCaughtSignature, AActor*, PlayerActor);

/** Shared sight/hearing controller. Monster subclasses decide which evidence is meaningful. */
UCLASS()
class P_060715_API AJMDungeonMonsterAIController : public AAIController
{
	GENERATED_BODY()

public:
	AJMDungeonMonsterAIController();
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	bool IsTargetSeen(AActor* Target) const;

private:
	UFUNCTION()
	void HandleTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(VisibleAnywhere, Category="AI|Senses")
	TObjectPtr<UAIPerceptionComponent> MonsterPerception;

	UPROPERTY()
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	UPROPERTY()
	TObjectPtr<UAISenseConfig_Hearing> HearingConfig;
};

/**
 * Fair prototype monster foundation: every lethal chase is preceded by readable alert and attack windows,
 * lost targets are searched for at their last evidence position, and hidden players are never tracked through walls.
 */
UCLASS(Abstract, Blueprintable)
class P_060715_API AJMDungeonMonster : public ACharacter
{
	GENERATED_BODY()

public:
	AJMDungeonMonster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<USceneComponent> BlockoutRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Feedback")
	TObjectPtr<UPointLightComponent> StateLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Audio")
	TObjectPtr<UAudioComponent> VoiceAudio;

	/** Query-only capsule that turns one confirmed body contact into a catch without requiring sustained overlap. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Fairness")
	TObjectPtr<UCapsuleComponent> ContactSensor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="AI|Patrol")
	TArray<TObjectPtr<AActor>> PatrolPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Movement", meta=(ClampMin="0.0"))
	float PatrolSpeed = 165.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Patrol")
	EJMDungeonPatrolMode PatrolMode = EJMDungeonPatrolMode::ContinuousLoop;

	/** Path-following acceptance radius. Agent overlap is deliberately excluded for patrol moves. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Patrol", meta=(ClampMin="1.0"))
	float PatrolMoveAcceptanceRadius = 65.0f;

	/** 2D distance that advances to the next POI. Keep this larger than PatrolMoveAcceptanceRadius. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Patrol", meta=(ClampMin="1.0"))
	float PatrolPointAdvanceRadius = 110.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Movement", meta=(ClampMin="0.0"))
	float InvestigateSpeed = 220.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Movement", meta=(ClampMin="0.0"))
	float ChaseSpeed = 340.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Fairness", meta=(ClampMin="0.0"))
	float AlertDelay = 0.8f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Fairness", meta=(ClampMin="0.1"))
	float AttackWarningDuration = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Fairness", meta=(ClampMin="1.0"))
	float CatchDistance = 115.0f;

	/** Extra room around the two collision capsules that counts as physical contact. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Fairness", meta=(ClampMin="0.0"))
	float ContactAttackPadding = 20.0f;

	/** Small tolerance for swept character movement at the exact capsule contact boundary. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Fairness", meta=(ClampMin="0.0"))
	float PhysicalContactTolerance = 8.0f;

	/** Fallback visual acquisition used when perception registration is late after runtime room generation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Sight", meta=(ClampMin="100.0"))
	float DirectSightRange = 1350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Sight", meta=(ClampMin="1.0", ClampMax="180.0"))
	float DirectSightHalfAngle = 55.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Memory", meta=(ClampMin="0.0"))
	float LoseTargetDelay = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Memory", meta=(ClampMin="0.1"))
	float SearchDuration = 7.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Memory", meta=(ClampMin="50.0"))
	float SearchRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Hearing", meta=(ClampMin="0.0"))
	float MinimumNoiseLoudness = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Audio")
	TObjectPtr<USoundBase> AlertSound;

	/** Actual Behavior Tree used by this monster type. C++ decision rules remain the source of truth for each task. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI|Behavior Tree")
	TSoftObjectPtr<UBehaviorTree> BehaviorTreeAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Audio", meta=(ClampMin="0.1", ClampMax="3.0"))
	float AlertSoundPitch = 1.0f;

	UPROPERTY(BlueprintAssignable, Category="AI|Events")
	FJMDungeonMonsterStateChangedSignature OnStateChanged;

	UPROPERTY(BlueprintAssignable, Category="AI|Events")
	FJMDungeonMonsterCaughtSignature OnPlayerCaught;

	UFUNCTION(BlueprintPure, Category="AI")
	EJMDungeonMonsterState GetMonsterState() const { return MonsterState; }

	UFUNCTION(BlueprintPure, Category="AI")
	FVector GetLastKnownLocation() const { return LastKnownLocation; }

	UFUNCTION(BlueprintCallable, Category="AI")
	virtual void SetMonsterEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="AI")
	virtual void ResetMonster();

	/** Assigns room-authored component locations without creating transient TargetPoint actors. */
	UFUNCTION(BlueprintCallable, Category="AI|Patrol")
	void ConfigureAuthoredRoute(const TArray<USceneComponent*>& InPatrolPoints, FVector InHomeLocation);

	UFUNCTION(BlueprintPure, Category="AI|Patrol")
	int32 GetAuthoredPatrolPointCount() const { return AuthoredPatrolPoints.Num(); }

	UFUNCTION(BlueprintPure, Category="AI|Patrol")
	FVector GetAuthoredHomeLocation() const { return bHasAuthoredHome ? AuthoredHomeLocation : SpawnLocation; }

	UFUNCTION(BlueprintPure, Category="AI|Patrol")
	int32 GetCompletedPatrolLegCount() const { return CompletedPatrolLegCount; }

	UFUNCTION(BlueprintPure, Category="AI|Patrol")
	int32 GetCurrentPatrolPointIndex() const { return PatrolIndex; }

	UFUNCTION(BlueprintPure, Category="AI")
	AActor* GetCurrentTargetActor() const { return TargetPawn.Get(); }

	/** Uses capsule contact as well as the authored catch distance, so path following cannot stop just outside attack range. */
	UFUNCTION(BlueprintPure, Category="AI|Fairness")
	float GetAttackTriggerDistance(const APawn* Target) const;

	UFUNCTION(BlueprintPure, Category="AI|Fairness")
	bool IsTargetWithinAttackRange(const APawn* Target) const;

	UFUNCTION(BlueprintPure, Category="AI|Fairness")
	bool IsTargetInPhysicalContact(const APawn* Target) const;

	/** Called by the active BT task. The expected state prevents stale tasks from executing another branch. */
	void TickBehaviorTreeDecision(EJMDungeonMonsterState ExpectedState);
	void SyncBehaviorTreeBlackboard(UBlackboardComponent& Blackboard) const;
	void SetBehaviorTreeDriven(bool bDriven);

	void HandleSightStimulus(APawn* SeenPawn, bool bSuccessfullySensed, const FVector& StimulusLocation);
	virtual void HandleHearingStimulus(AActor* SourceActor, const FVector& StimulusLocation, float Loudness);

	virtual bool UsesSightStimulus() const { return true; }
	virtual bool UsesHearingStimulus() const { return true; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void UpdateSpecialRules();
	virtual bool CanPursueTarget(const APawn* Target) const;
	virtual bool CanCatchTarget(const APawn* Target) const;
	virtual FVector GetReturnLocation() const;

	void SetMonsterState(EJMDungeonMonsterState NewState);
	void BeginSuspicion(APawn* Target, const FVector& EvidenceLocation);
	void BeginInvestigation(const FVector& EvidenceLocation, AActor* SourceActor = nullptr);
	void BeginChase(APawn* Target, const FVector& EvidenceLocation);
	void BeginSearch(const FVector& SearchOrigin);
	void ClearTargetAndReturn();
	bool IsTargetHidden(const AActor* Target) const;
	void AddBlockoutPart(UStaticMeshComponent* Part, const TCHAR* MeshPath, const FVector& RelativeLocation,
		const FRotator& RelativeRotation, const FVector& RelativeScale);

	TWeakObjectPtr<APawn> TargetPawn;
	FVector LastKnownLocation = FVector::ZeroVector;
	FVector SpawnLocation = FVector::ZeroVector;
	FRotator SpawnRotation = FRotator::ZeroRotator;
	double LastEvidenceTime = -1.0;
	double StateStartTime = 0.0;
	int32 PatrolIndex = INDEX_NONE;
	bool bMonsterEnabled = true;
	bool bBehaviorTreeDriven = false;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USceneComponent>> AuthoredPatrolPoints;

	FVector AuthoredHomeLocation = FVector::ZeroVector;
	bool bHasAuthoredHome = false;

private:
	void UpdateDecision();
	void UpdatePatrol(AJMDungeonMonsterAIController* MonsterController);
	void UpdateInvestigation(AJMDungeonMonsterAIController* MonsterController);
	void UpdateChase(AJMDungeonMonsterAIController* MonsterController);
	void UpdateAttackWarning(AJMDungeonMonsterAIController* MonsterController);
	void UpdateSearch(AJMDungeonMonsterAIController* MonsterController);
	void UpdateReturn(AJMDungeonMonsterAIController* MonsterController);
	void RefreshDirectPlayerAwareness(AJMDungeonMonsterAIController* MonsterController);
	bool HasDirectSightTo(const APawn* Target, const AJMDungeonMonsterAIController* MonsterController) const;
	void MoveToward(AJMDungeonMonsterAIController* MonsterController, const FVector& Destination,
		float AcceptanceRadius, bool bStopOnOverlap = true);
	void CatchPlayer(APawn* Player);

	UFUNCTION()
	void HandleContactSensorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void PlayAlertCue();
	void RefreshStateFeedback();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	EJMDungeonMonsterState MonsterState = EJMDungeonMonsterState::Patrol;

	FVector CurrentSearchPoint = FVector::ZeroVector;
	bool bHasSearchPoint = false;
	int32 CompletedPatrolLegCount = 0;
	FTimerHandle DecisionTimer;
};
