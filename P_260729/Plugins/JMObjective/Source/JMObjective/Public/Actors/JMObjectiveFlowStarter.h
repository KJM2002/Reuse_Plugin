#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMObjectiveFlowStarter.generated.h"

class UJMObjectiveFlowDefinition;

UCLASS(Blueprintable, meta = (DisplayName = "JM Objective Flow Starter"))
class JMOBJECTIVE_API AJMObjectiveFlowStarter : public AActor
{
    GENERATED_BODY()

public:
    AJMObjectiveFlowStarter();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    TObjectPtr<UJMObjectiveFlowDefinition> FlowDefinition = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    bool bStartOnBeginPlay = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JM Objective Flow")
    bool bResetFlowOnEndPlay = false;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};

