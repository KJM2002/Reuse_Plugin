#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"
#include "JMPrototypeLevelPortal.generated.h"

class ACameraActor;
class APlayerController;
class UCurveFloat;
class UMaterialInterface;
class UMaterialInstanceDynamic;
class UNiagaraComponent;
class UPrimitiveComponent;
class USceneComponent;
class USphereComponent;
class UWorld;
struct FHitResult;

/** Minimal player-overlap portal. It owns no quest, inventory, or progression logic. */
UCLASS(Blueprintable)
class P_060715_API AJMPrototypeLevelPortal : public AActor
{
	GENERATED_BODY()

public:
	AJMPrototypeLevelPortal();

	/** Converts transient PIE map paths back to their loadable source package path. */
	static FString NormalizeDestinationPackageName(const FString& PackageName);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<USphereComponent> OverlapArea;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<UNiagaraComponent> PortalEffect;

	/** Independent camera aim point. Move this component to the visible center of each portal. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Portal")
	TObjectPtr<USceneComponent> TransitionFocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	TSoftObjectPtr<UWorld> DestinationWorld;

	/** Total time spent accelerating into the portal before map travel. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "0.1"))
	float SuctionDuration = 1.35f;

	/** Camera distance from the portal center at the end of the suction. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "1.0"))
	float StopDistance = 70.0f;

	/** Maximum real camera translation. Zero keeps the player's standing viewpoint fixed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "0.0"))
	float MaximumCameraTravelDistance = 0.0f;

	/** Optional authored 0..1 curve. When unset, a cubic ease-in is used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition")
	TObjectPtr<UCurveFloat> SuctionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "1.0", ClampMax = "170.0"))
	float PeakFOV = 115.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "1.0", ClampMax = "170.0"))
	float FinalFOV = 55.0f;

	/** Enables the old wide-FOV kick before zooming in. Off is more stable for side approaches. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition")
	bool bUseWideFOVKick = false;

	/** Controls how gently the camera turns from the entry view toward TransitionFocus. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "1.0", ClampMax = "8.0"))
	float RotationEaseExponent = 2.0f;

	/** Optional Post Process material with a scalar parameter named WarpStrength. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition")
	TObjectPtr<UMaterialInterface> WarpMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition")
	FName WarpStrengthParameterName = TEXT("WarpStrength");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition", meta = (ClampMin = "0.0"))
	float MaximumWarpStrength = 0.18f;

	/** One message is chosen at random and held over black after the destination finishes loading. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal|Transition")
	TArray<FText> ArrivalMessages;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UFUNCTION()
	void HandleOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
	void RecheckPlayerInsidePortal();
	void StartTransition(APawn* PlayerPawn);
	void UpdateTransition(float NormalizedTime);
	void HandleDestinationPreloaded(const FName& PackageName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result);
	void TryExecuteTravel();
	void CancelTransition();

	bool bTravelStarted = false;
	bool bSuctionComplete = false;
	bool bPreloadComplete = false;
	bool bPreloadSucceeded = false;
	bool bFadeStarted = false;
	bool bRequirePortalExitBeforeRetry = false;
	float TransitionElapsed = 0.0f;
	float InitialFOV = 80.0f;
	FVector InitialCameraLocation = FVector::ZeroVector;
	FVector TargetCameraLocation = FVector::ZeroVector;
	FVector TransitionFocusLocation = FVector::ZeroVector;
	FQuat InitialCameraRotation = FQuat::Identity;
	TWeakObjectPtr<APlayerController> TransitionPlayerController;
	TWeakObjectPtr<AActor> OriginalViewTarget;
	TWeakObjectPtr<ACameraActor> TransitionCamera;
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> WarpMaterialInstance;
	/** Keeps the asynchronously loaded map package alive until OpenLevel consumes it. */
	UPROPERTY(Transient)
	TObjectPtr<UPackage> PreloadedDestinationPackage;
	FString TravelDestinationPackageName;
	FTimerHandle RecheckTimerHandle;
};
