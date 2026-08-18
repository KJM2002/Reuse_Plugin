#pragma once

#include "Components/StateTreeAIComponent.h"
#include "JMEnemyStateTreeComponent.generated.h"

/** Controller-owned StateTree runner that resolves framework external data from the controlled enemy. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyStateTreeComponent : public UStateTreeAIComponent
{
    GENERATED_BODY()

public:
    UJMEnemyStateTreeComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    bool StartFrameworkTree(class UStateTree* StateTree);
    void StopFrameworkTree(const FString& Reason);

protected:
    virtual void ValidateStateTreeReference() override;
    virtual bool CollectExternalData(const FStateTreeExecutionContext& Context,
        const UStateTree* StateTree, TArrayView<const FStateTreeExternalDataDesc> Descs,
        TArrayView<FStateTreeDataView> OutDataViews) const override;
};
