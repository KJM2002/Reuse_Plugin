#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Types/JMGameplayEventTypes.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveUISubsystem.generated.h"

class APlayerController;
class UJMObjectiveSubsystem;
class UJMObjectiveWidgetBase;

UCLASS()
class JMOBJECTIVE_API UJMObjectiveUISubsystem : public ULocalPlayerSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
    virtual void PlayerControllerChanged(APlayerController* NewPlayerController) override;

    UFUNCTION(BlueprintPure, Category = "JM Objective|UI")
    UJMObjectiveWidgetBase* GetObjectiveWidget() const { return ObjectiveWidget; }

private:
    UPROPERTY(Transient)
    TObjectPtr<UJMObjectiveWidgetBase> ObjectiveWidget = nullptr;

    UPROPERTY(Transient)
    TObjectPtr<UJMObjectiveSubsystem> ObjectiveSubsystem = nullptr;

    FTimerHandle CompletedDisplayTimer;
    FJMObjectiveRuntimeState LatestActiveState;
    bool bHasLatestActiveState = false;
    bool bModalSuppressed = false;
    int32 ModalSuppressionDepth = 0;
    FJMGameplayEventSubscriptionHandle ModalOpenedHandle;
    FJMGameplayEventSubscriptionHandle ModalClosedHandle;

    bool EnsureWidget();
    void BindObjectiveDelegates();
    void UnbindObjectiveDelegates();
    void ShowState(const FJMObjectiveRuntimeState& RuntimeState);
    void RefreshMostRecentActiveObjective();
    void FinishCompletedDisplay();
    bool IsShowingCompletedState() const;
    void HandleModalOpened(const FJMGameplayEventMessage& Message);
    void HandleModalClosed(const FJMGameplayEventMessage& Message);

    UFUNCTION()
    void HandleRegistered(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);

    UFUNCTION()
    void HandleActivated(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);

    UFUNCTION()
    void HandleProgressed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState, int32 ProgressDelta);

    UFUNCTION()
    void HandleCompleted(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);

    UFUNCTION()
    void HandleFailed(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);

    UFUNCTION()
    void HandleRemoved(FGameplayTag ObjectiveId, const FJMObjectiveRuntimeState& RuntimeState);
};
