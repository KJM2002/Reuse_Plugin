#pragma once

#include "Components/ActorComponent.h"
#include "JMEnemyDebugComponent.generated.h"

/** Opt-in runtime inspection for one enemy. Disabled components do not tick or draw. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyDebugComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyDebugComponent();

    UFUNCTION(BlueprintCallable, Category="JM Monster|Debug")
    void SetDebugEnabled(bool bEnabled);

    UFUNCTION(BlueprintPure, Category="JM Monster|Debug")
    bool IsDebugEnabled() const { return bDebugEnabled; }

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

private:
    FString BuildStatusText() const;
    void DrawWorldData() const;

    UPROPERTY(EditInstanceOnly, Category="JM Monster|Debug",
        meta=(ToolTip="Draw this enemy's framework state while playing. The component does no work while disabled."))
    bool bEnableOnBeginPlay = false;

    UPROPERTY(EditDefaultsOnly, Category="JM Monster|Debug", meta=(ClampMin="0.05"))
    float UpdateInterval = 0.1f;

    bool bDebugEnabled = false;
};
