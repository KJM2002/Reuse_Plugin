#pragma once

#include "Action/JMEnemyActionTypes.h"
#include "Audio/JMEnemyAudioSet.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "JMEnemyAudioComponent.generated.h"

class UJMEnemyAction;
class UJMEnemyActionComponent;
class UJMEnemyStateComponent;

/** Optional presentation adapter. It observes state/action events and never drives AI behavior. */
UCLASS(ClassGroup=(JMEnemy), meta=(BlueprintSpawnableComponent))
class JMMONSTERFRAMEWORKRUNTIME_API UJMEnemyAudioComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMEnemyAudioComponent();

    void InitializeAudio(UJMEnemyAudioSet* InAudioSet,
        UJMEnemyStateComponent* State, UJMEnemyActionComponent* Actions);

    UFUNCTION(BlueprintCallable, Category="JM Monster|Audio")
    bool PlayAudioEvent(EJMEnemyAudioEvent Event);

    UFUNCTION(BlueprintPure, Category="JM Monster|Audio")
    const UJMEnemyAudioSet* GetAudioSet() const { return AudioSet; }

    UFUNCTION(BlueprintPure, Category="JM Monster|Audio")
    EJMEnemyAudioEvent GetLastRequestedEvent() const { return LastRequestedEvent; }

protected:
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    UFUNCTION()
    void HandleStateChanged(FGameplayTag PreviousState, FGameplayTag NewState);

    UFUNCTION()
    void HandleActionStarted(FGameplayTag ActionId, UJMEnemyAction* Action);

    UFUNCTION()
    void HandleActionPhaseChanged(FGameplayTag ActionId, UJMEnemyAction* Action,
        EJMEnemyActionPhase PreviousPhase, EJMEnemyActionPhase NewPhase);

    void UnbindSources();

    UPROPERTY(Transient)
    TObjectPtr<UJMEnemyAudioSet> AudioSet;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyStateComponent> BoundState;

    UPROPERTY(Transient)
    TWeakObjectPtr<UJMEnemyActionComponent> BoundActions;

    FDelegateHandle ActionStartedHandle;
    FDelegateHandle ActionPhaseChangedHandle;

    EJMEnemyAudioEvent LastRequestedEvent = EJMEnemyAudioEvent::Idle;
};
