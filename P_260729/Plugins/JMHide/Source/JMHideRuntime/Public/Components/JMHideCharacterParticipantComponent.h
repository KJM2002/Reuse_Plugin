#pragma once

#include "CoreMinimal.h"
#include "Components/JMHideParticipantDriverComponent.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "JMHideCharacterParticipantComponent.generated.h"

class ACameraActor;
class ACharacter;
class APlayerController;

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDERUNTIME_API UJMHideCharacterParticipantComponent final : public UJMHideParticipantDriverComponent
{
    GENERATED_BODY()

public:
    UJMHideCharacterParticipantComponent();

    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual bool SupportsParticipant(AActor* Participant) const override;
    virtual FJMHideResult CaptureState(FJMHideParticipantSnapshot& OutSnapshot) override;
    virtual FJMHideResult PrepareForHide(const FGuid& SessionId, const FJMHideOperationContext& Context,
        FJMHideParticipantSnapshot& InOutSnapshot) override;
    virtual bool StartOperation(const FGuid& SessionId, EJMHideOperation Operation, const FJMHideOperationContext& Context) override;
    virtual void CancelOperation(const FGuid& SessionId) override;
    virtual void ApplyHiddenState(const FGuid& SessionId, const FJMHideOperationContext& Context) override;
    virtual void RestoreState(const FGuid& SessionId, const FJMHideParticipantSnapshot& Snapshot) override;
    virtual bool CanOccupyTransform(const FTransform& Transform) const override;
    virtual FTransform GetViewTransform() const override;

private:
    void FinishTimedOperation();
    void HandleFadeMidpoint();
    void StartFadeTransition(float Duration);
    void StopFadeTransition();
    ACharacter* GetCharacter() const;
    APlayerController* GetPlayerController() const;
    void EnsureCameraActor(const FTransform& Transform);
    void BeginHideView(const FJMHideOperationContext& Context);
    void EndHideView();
    void UpdateLimitedLook();

    FGuid ActiveSessionId;
    EJMHideOperation ActiveOperation = EJMHideOperation::None;
    FTimerHandle OperationTimer;
    FTimerHandle FadeMidpointTimer;
    FJMHideOperationContext ActiveContext;
    bool bFadeTransitionActive = false;

    TEnumAsByte<EMovementMode> OriginalMovementMode = MOVE_Walking;
    uint8 OriginalCustomMovementMode = 0;
    TEnumAsByte<ECollisionEnabled::Type> OriginalCollision = ECollisionEnabled::QueryAndPhysics;
    FName OriginalCollisionProfile;
    bool bOriginalHidden = false;
    bool bVisibilityChangedOwned = false;
    FTransform OriginalActorTransform = FTransform::Identity;
    bool bRestoreActorTransform = true;
    TWeakObjectPtr<AActor> OriginalViewTarget;
    FRotator OriginalControlRotation = FRotator::ZeroRotator;
    TWeakObjectPtr<ACameraActor> HideCameraActor;
    FRotator HideViewBaseRotation = FRotator::ZeroRotator;
    float HideViewYawLimit = 55.0f;
    float HideViewPitchLimit = 30.0f;
    bool bLimitedLookEnabled = true;
    bool bHideViewActive = false;
    FTransform LastHiddenTransform = FTransform::Identity;
};
