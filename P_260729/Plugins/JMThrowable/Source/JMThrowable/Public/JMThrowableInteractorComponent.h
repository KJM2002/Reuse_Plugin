#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMThrowableTypes.h"
#include "JMThrowableInteractorComponent.generated.h"

class UJMThrowableDefinition;
class USplineComponent;
class UProceduralMeshComponent;
class UPointLightComponent;
class UMaterialInterface;
class UMaterialInstanceDynamic;
class UNiagaraComponent;
class UNiagaraSystem;

DECLARE_DELEGATE_RetVal_OneParam(bool, FJMThrowableCommitDelegate, const FGuid&);
DECLARE_DELEGATE_OneParam(FJMThrowableSessionEndedNative, const FGuid&);

UCLASS(ClassGroup=(JM), BlueprintType, meta=(BlueprintSpawnableComponent))
class JMTHROWABLE_API UJMThrowableInteractorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UJMThrowableInteractorComponent();
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type Reason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* Tick) override;

    UPROPERTY(BlueprintAssignable, Category="JM Throwable") FJMThrowableStateChanged OnStateChanged;
    UPROPERTY(BlueprintAssignable, Category="JM Throwable") FJMThrowableThrowCompleted OnThrowCompleted;

    UFUNCTION(BlueprintCallable, Category="JM Throwable") bool BeginItemUse(const FJMThrowableUseContext& Context);
    UFUNCTION(BlueprintCallable, Category="JM Throwable") bool BeginAim();
    UFUNCTION(BlueprintCallable, Category="JM Throwable") bool EndAim();
    UFUNCTION(BlueprintCallable, Category="JM Throwable") FJMThrowResult TryCommitThrow();
    UFUNCTION(BlueprintCallable, Category="JM Throwable") void CancelItemUse();
    UFUNCTION(BlueprintPure, Category="JM Throwable") EJMThrowableUseState GetUseState() const { return UseState; }
    UFUNCTION(BlueprintPure, Category="JM Throwable") FGuid GetSessionId() const { return ActiveContext.SessionId; }
    UFUNCTION(BlueprintPure, Category="JM Throwable") const FJMThrowSimulationResult& GetPreviewResult() const { return PreviewResult; }

    FJMThrowableCommitDelegate CommitDelegate;
    FJMThrowableSessionEndedNative SessionEndedDelegate;

private:
    UPROPERTY(VisibleInstanceOnly) EJMThrowableUseState UseState = EJMThrowableUseState::Idle;
    UPROPERTY(Transient) FJMThrowableUseContext ActiveContext;
    UPROPERTY(Transient) FJMThrowSimulationResult PreviewResult;
    UPROPERTY(Transient) TObjectPtr<USplineComponent> PreviewSpline;
    UPROPERTY(Transient) TObjectPtr<UProceduralMeshComponent> PreviewRibbon;
    UPROPERTY(Transient) TObjectPtr<UProceduralMeshComponent> PreviewFlowRibbon;
    UPROPERTY(Transient) TObjectPtr<UProceduralMeshComponent> PreviewFlowOrb;
    UPROPERTY(Transient) TObjectPtr<UPointLightComponent> PreviewGlow;
    UPROPERTY(Transient) TObjectPtr<UProceduralMeshComponent> PreviewImpactMarker;
    UPROPERTY(Transient) TObjectPtr<UNiagaraComponent> PreviewNiagara;
    UPROPERTY(Transient) TObjectPtr<UNiagaraSystem> CachedTrajectoryNiagaraSystem;
    UPROPERTY(Transient) TObjectPtr<UMaterialInterface> CachedPreviewMaterial;
    UPROPERTY(Transient) TObjectPtr<UMaterialInstanceDynamic> PreviewTrajectoryMID;
    UPROPERTY(Transient) TObjectPtr<UMaterialInstanceDynamic> PreviewFlowMID;
    UPROPERTY(Transient) TObjectPtr<UMaterialInstanceDynamic> PreviewOrbMID;
    UPROPERTY(Transient) TObjectPtr<UMaterialInstanceDynamic> PreviewMarkerMID;
    TArray<FVector> PreviewPathPoints;
    TArray<FVector> NiagaraPathPoints;
    float PreviewAccumulator = 0.f;
    float FlowDistance = 0.f;
    bool bPreviewMaterialPrepared = false;
    bool bNiagaraPreviewActive = false;

    bool GetView(FVector& OutLocation, FVector& OutForward) const;
    bool BuildThrowParameters(FJMThrowParameters& OutParameters, FVector* OutAimPoint = nullptr) const;
    bool ValidateSpawn(const FJMThrowParameters& Parameters) const;
    void PreparePreviewMaterials();
    bool PrepareNiagaraPreview();
    bool UpdateNiagaraPreview();
    void DeactivateNiagaraPreview(bool bClearPath);
    void UpdatePreview();
    void BuildPreviewPath();
    void UpdatePreviewAnimation(float DeltaTime);
    void RebuildBaseRibbon();
    void RebuildFlowRibbon(float StartDistance, float EndDistance);
    void UpdateImpactMarker();
    void HidePreviewVisuals(bool bClearGeometry);
    void SetState(EJMThrowableUseState NewState);
    void Cleanup(bool bNotifySessionEnd);
    FJMThrowResult Fail(EJMThrowResultCode Code, const TCHAR* Reason, EJMThrowableUseState RestoreState);
};
