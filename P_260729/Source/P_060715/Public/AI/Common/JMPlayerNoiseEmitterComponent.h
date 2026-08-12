#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMPlayerNoiseEmitterComponent.generated.h"

/** Converts player movement into AI hearing events. Devices can call ReportDungeonNoise for authored noises. */
UCLASS(ClassGroup=(AI), meta=(BlueprintSpawnableComponent))
class P_060715_API UJMPlayerNoiseEmitterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UJMPlayerNoiseEmitterComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Noise", meta=(ClampMin="0.1"))
	float FootstepInterval = 0.48f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Noise", meta=(ClampMin="0.0"))
	float WalkLoudness = 0.32f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Noise", meta=(ClampMin="0.0"))
	float RunLoudness = 0.9f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Noise", meta=(ClampMin="0.0"))
	float RunSpeedThreshold = 430.0f;

	UFUNCTION(BlueprintCallable, Category="AI|Noise")
	void ReportDungeonNoise(float Loudness, FName NoiseTag = TEXT("JM.Noise.Action"), float MaxRange = 0.0f);

private:
	double LastFootstepTime = -1.0;
};
