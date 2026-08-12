#pragma once

#include "AI/Common/JMDungeonMonster.h"
#include "JMHoarderMonster.generated.h"

class UStaticMeshComponent;

/** Territorial guardian. Entry raises suspicion; touching its protected object starts a committed but leashed chase. */
UCLASS(Blueprintable)
class P_060715_API AJMHoarderMonster : public AJMDungeonMonster
{
	GENERATED_BODY()

public:
	AJMHoarderMonster();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> Shell;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Blockout")
	TObjectPtr<UStaticMeshComponent> GuardBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Territory", meta=(ClampMin="100.0"))
	float WarningRadius = 850.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Territory", meta=(ClampMin="50.0"))
	float AggressionRadius = 430.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Territory", meta=(ClampMin="0.0"))
	float LeashExtraDistance = 350.0f;

	UFUNCTION(BlueprintCallable, Category="AI|Territory")
	void SetTerritoryCenter(FVector NewCenter);

	UFUNCTION(BlueprintCallable, Category="AI|Territory")
	void NotifyProtectedObjectDisturbed(AActor* InstigatorActor);

protected:
	virtual void BeginPlay() override;
	virtual void UpdateSpecialRules() override;
	virtual bool CanPursueTarget(const APawn* Target) const override;
	virtual FVector GetReturnLocation() const override;

private:
	FVector TerritoryCenter = FVector::ZeroVector;
	bool bTerritoryInitialized = false;
};
