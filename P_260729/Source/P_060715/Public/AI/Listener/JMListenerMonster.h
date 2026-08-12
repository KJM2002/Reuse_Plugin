#pragma once

#include "AI/Common/JMDungeonMonster.h"
#include "JMListenerMonster.generated.h"

class UStaticMeshComponent;

/** Blind sound hunter. It only receives updated player positions when a new noise is made. */
UCLASS(Blueprintable)
class P_060715_API AJMListenerMonster : public AJMDungeonMonster
{
	GENERATED_BODY()

public:
	AJMListenerMonster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> Torso;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> Head;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> LeftEar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> RightEar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Listener", meta=(ClampMin="0.1"))
	float RepeatNoiseEscalationWindow = 2.25f;

	virtual bool UsesSightStimulus() const override { return false; }
	virtual void HandleHearingStimulus(AActor* SourceActor, const FVector& StimulusLocation, float Loudness) override;
};
