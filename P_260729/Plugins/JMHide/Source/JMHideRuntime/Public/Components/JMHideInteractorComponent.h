#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types/JMHideTypes.h"
#include "JMHideInteractorComponent.generated.h"

class UJMHideMechanismComponent;
class UJMHideParticipantDriverComponent;
class UJMHideSpotComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FJMHidePhaseChangedSignature, FGuid, SessionId, EJMHidePhase, OldPhase, EJMHidePhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMHideSessionEventSignature, FGuid, SessionId, UJMHideSpotComponent*, HideSpot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMHideExitPromptChangedSignature, FText, Prompt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMHideFailedSignature, FGuid, SessionId, EJMHideFailureCode, Failure);

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDERUNTIME_API UJMHideInteractorComponent final : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHideInteractorComponent();

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    UPROPERTY(BlueprintAssignable, Category="JM Hide|Events")
    FJMHidePhaseChangedSignature OnPhaseChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Hide|Events")
    FJMHideSessionEventSignature OnHiddenEntered;

    UPROPERTY(BlueprintAssignable, Category="JM Hide|Events")
    FJMHideSessionEventSignature OnHiddenExited;

    UPROPERTY(BlueprintAssignable, Category="JM Hide|Events")
    FJMHideExitPromptChangedSignature OnExitPromptChanged;

    UPROPERTY(BlueprintAssignable, Category="JM Hide|Events")
    FJMHideFailedSignature OnHideFailed;

    UFUNCTION(BlueprintCallable, Category="JM Hide")
    FJMHideResult TryEnterHideSpot(UJMHideSpotComponent* HideSpot);

    UFUNCTION(BlueprintCallable, Category="JM Hide")
    FJMHideResult TryEnterHideSpotWithRequest(UJMHideSpotComponent* HideSpot, const FJMHideRequest& Request);

    UFUNCTION(BlueprintCallable, Category="JM Hide")
    FJMHideResult TryExitCurrentHideSpot();

    UFUNCTION(BlueprintCallable, Category="JM Hide")
    FJMHideResult CancelCurrentTransition();

    UFUNCTION(BlueprintCallable, Category="JM Hide")
    FJMHideResult ForceExit(bool bIgnoreCollisionPolicy = true);

    UFUNCTION(BlueprintPure, Category="JM Hide")
    bool IsHidden() const { return ActiveSession.CurrentPhase == EJMHidePhase::Hidden; }

    UFUNCTION(BlueprintPure, Category="JM Hide")
    bool HasActiveSession() const { return ActiveSession.IsActive(); }

    UFUNCTION(BlueprintPure, Category="JM Hide")
    EJMHidePhase GetCurrentPhase() const { return ActiveSession.CurrentPhase; }

    UFUNCTION(BlueprintPure, Category="JM Hide")
    FGuid GetCurrentSessionId() const { return ActiveSession.SessionId; }

    UFUNCTION(BlueprintPure, Category="JM Hide")
    UJMHideSpotComponent* GetCurrentHideSpot() const { return ActiveSession.HideSpot.Get(); }

    const FJMHideSession& GetActiveSession() const { return ActiveSession; }

private:
    FJMHideResult BeginEnter(UJMHideSpotComponent* HideSpot, const FJMHideRequest& Request);
    void StartMechanism(EJMHideOperation Operation, EJMHidePhase Phase);
    void StartParticipant(EJMHideOperation Operation, EJMHidePhase Phase);
    void HandleMechanismCompletion(const FJMHideOperationCompletion& Completion);
    void HandleParticipantCompletion(const FJMHideOperationCompletion& Completion);
    void FinishEnter();
    void BeginExit(bool bForce, bool bIgnoreCollisionPolicy);
    bool SelectExit(bool bIgnoreCollisionPolicy, FTransform& OutExit) const;
    FJMHideOperationContext BuildOperationContext() const;
    void RollbackEnter(EJMHideFailureCode Failure);
    void RollbackExitToHidden();
    void Cleanup(EJMHidePhase FinalPhase, bool bReleaseSpot, bool bRestoreParticipant);
    void BindProviders();
    void UnbindProviders();
    void TransitionTo(EJMHidePhase NewPhase);
    bool IsExpectedCompletion(const FJMHideOperationCompletion& Completion, EJMHidePhase ExpectedPhase,
        EJMHideOperation ExpectedOperation) const;
    UJMHideParticipantDriverComponent* ResolveDriver() const;
    void Fail(EJMHideFailureCode Failure);

    FJMHideSession ActiveSession;
    EJMHideOperation ExpectedOperation = EJMHideOperation::None;
    bool bForceExitActive = false;
};
