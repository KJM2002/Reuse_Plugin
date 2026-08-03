#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/JMObjectiveTypes.h"
#include "JMObjectiveWidgetBase.generated.h"

UCLASS(Abstract, Blueprintable)
class JMOBJECTIVE_API UJMObjectiveWidgetBase : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "JM Objective|UI")
    void SetObjectiveState(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintPure, Category = "JM Objective|UI")
    FJMObjectiveRuntimeState GetObjectiveState() const { return RuntimeState; }

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveAdded(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveActivated(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveProgressChanged(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveCompleted(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveFailed(const FJMObjectiveRuntimeState& InRuntimeState);

    UFUNCTION(BlueprintImplementableEvent, Category = "JM Objective|UI")
    void OnObjectiveRemoved(FGameplayTag ObjectiveId);

protected:
    virtual void NativePreConstruct() override;

    void UpdateNativeTextFields();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "JM Objective|UI")
    FJMObjectiveRuntimeState RuntimeState;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
    TObjectPtr<class UTextBlock> ObjectiveNameText = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
    TObjectPtr<class UTextBlock> ObjectiveDescriptionText = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
    TObjectPtr<class UTextBlock> ObjectiveProgressText = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
    TObjectPtr<class UTextBlock> ObjectiveStateText = nullptr;
};
