#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Door/JMDoorTypes.h"
#include "Interfaces/JMReconTarget.h"
#include "JMDoorReconTargetAdapterComponent.generated.h"

class UJMDoorComponent;
class UJMReconInteractorComponent;
class UJMReconTargetComponent;
class USceneComponent;

/** Session-owned visual door pose. It never mutates JMDoor state or save data. */
UCLASS(NotBlueprintable, Transient)
class JMDOORRECONINTEGRATION_API UJMDoorReconTargetAdapterComponent final
    : public UActorComponent
    , public IJMReconTarget
{
    GENERATED_BODY()

public:
    UJMDoorReconTargetAdapterComponent();
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    virtual FJMReconRequestResult CanStartRecon_Implementation(AActor* Interactor, const FGuid& SessionId) const override;
    virtual bool CanEnterListen_Implementation(AActor* Interactor, const FGuid& SessionId) const override;
    virtual bool CanEnterPeek_Implementation(AActor* Interactor, const FGuid& SessionId) const override;
    virtual void BeginRecon_Implementation(AActor* Interactor, const FGuid& SessionId) override;
    virtual void EndRecon_Implementation(AActor* Interactor, const FGuid& SessionId, EJMReconEndReason Reason) override;
    virtual void BeginPeekPose_Implementation(const FGuid& SessionId, float OpenFraction) override;
    virtual void EndPeekPose_Implementation(const FGuid& SessionId) override;

    UFUNCTION(BlueprintPure, Category="JM Door|Recon")
    bool IsTemporaryPoseActive() const { return bPoseCaptured; }

private:
    void CacheComponents();
    void BeginTemporaryPose(float OpenFraction);
    void BeginRestore(bool bImmediate);
    void ApplyBlend(float Alpha);
    void FinishBlend();
    int32 ResolveOpenDirection() const;
    FJMReconRequestResult ValidateDoorState() const;

    UFUNCTION()
    void HandleDoorStateChanged(EJMDoorState OldState, EJMDoorState NewState);

    UPROPERTY(Transient)
    TObjectPtr<UJMDoorComponent> DoorComponent;

    UPROPERTY(Transient)
    TObjectPtr<UJMReconTargetComponent> ReconTarget;

    TWeakObjectPtr<UJMReconInteractorComponent> ReconInteractor;
    TWeakObjectPtr<AActor> SessionInteractor;
    TWeakObjectPtr<USceneComponent> MovingA;
    TWeakObjectPtr<USceneComponent> MovingB;
    FGuid ActiveSessionId;
    FTransform OriginalA = FTransform::Identity;
    FTransform OriginalB = FTransform::Identity;
    FTransform BlendStartA = FTransform::Identity;
    FTransform BlendStartB = FTransform::Identity;
    FTransform BlendTargetA = FTransform::Identity;
    FTransform BlendTargetB = FTransform::Identity;
    float BlendElapsed = 0.0f;
    float BlendDuration = 0.0f;
    bool bHasPanelB = false;
    bool bPoseCaptured = false;
    bool bRestoring = false;
};
