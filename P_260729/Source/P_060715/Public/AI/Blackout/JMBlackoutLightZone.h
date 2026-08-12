#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JMBlackoutLightZone.generated.h"

class UPointLightComponent;
class USphereComponent;

/** Explicit prototype light-safe zone used instead of unreliable scene-luminance guesses. */
UCLASS(Blueprintable)
class P_060715_API AJMBlackoutLightZone : public AActor
{
	GENERATED_BODY()

public:
	AJMBlackoutLightZone();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blackout")
	TObjectPtr<USphereComponent> SafeRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blackout")
	TObjectPtr<UPointLightComponent> SafeLight;

	UFUNCTION(BlueprintPure, Category="AI|Blackout")
	bool ProtectsLocation(const FVector& Location) const;

	static bool IsLocationProtected(const UWorld* World, const FVector& Location);
};
