#pragma once

#include "AI/Common/JMDungeonMonster.h"
#include "JMBlackoutMonster.generated.h"

class UStaticMeshComponent;

/** Late-run hunter. It telegraphs activation and cannot pursue or catch players inside authored light-safe zones. */
UCLASS(Blueprintable)
class P_060715_API AJMBlackoutMonster : public AJMDungeonMonster
{
	GENERATED_BODY()

public:
	AJMBlackoutMonster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> Core;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> UpperBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> LeftArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> RightArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Blackout")
	bool bStartsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Blackout", meta=(ClampMin="0.0"))
	float AutomaticActivationDelay = 45.0f;

	UFUNCTION(BlueprintCallable, Category="AI|Blackout")
	void SetBlackoutActive(bool bActive);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void UpdateSpecialRules() override;
	virtual bool CanPursueTarget(const APawn* Target) const override;
	virtual bool CanCatchTarget(const APawn* Target) const override;

private:
	void ActivateAfterDelay();
	FTimerHandle ActivationTimer;
};
