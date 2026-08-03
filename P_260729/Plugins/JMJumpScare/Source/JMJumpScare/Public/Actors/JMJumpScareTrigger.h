#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareTrigger.generated.h"

class AJMJumpScareAnchor;
class UBoxComponent;
class UJMJumpScareDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName="JM JumpScare Trigger"))
class JMJUMPSCARE_API AJMJumpScareTrigger : public AActor
{
    GENERATED_BODY()

public:
    AJMJumpScareTrigger();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    TObjectPtr<UBoxComponent> TriggerVolume;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    TObjectPtr<UJMJumpScareDefinition> JumpScareDefinition = nullptr;

    UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    TObjectPtr<AJMJumpScareAnchor> JumpScareAnchor = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    EJMJumpScareTriggerPolicy TriggerPolicy = EJMJumpScareTriggerPolicy::Once;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger")
    EJMJumpScareOverlapFilter TargetActorFilter = EJMJumpScareOverlapFilter::PlayerControlledPawn;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Trigger", meta=(EditCondition="TargetActorFilter==EJMJumpScareOverlapFilter::GameplayTags"))
    FGameplayTagContainer RequiredActorTags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM JumpScare | Trigger")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Save", meta=(Categories="JumpScare.Trigger"))
    FGameplayTag TriggerId;

    UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="JM JumpScare | Trigger")
    bool bHasTriggered = false;

    UFUNCTION(BlueprintCallable, Category="JM JumpScare")
    void ResetTrigger();

    UFUNCTION(BlueprintPure, Category="JM JumpScare | Save")
    FJMJumpScareTriggerSaveState CaptureSaveState() const;

    UFUNCTION(BlueprintCallable, Category="JM JumpScare | Save")
    void RestoreSaveState(const FJMJumpScareTriggerSaveState& SaveState);

private:
    UFUNCTION()
    void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    bool PassesActorFilter(AActor* OtherActor, APlayerController*& OutPlayerController) const;
};
