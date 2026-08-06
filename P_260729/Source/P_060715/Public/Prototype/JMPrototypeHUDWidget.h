#pragma once

#include "Blueprint/UserWidget.h"
#include "Prototype/JMPrototypeTypes.h"
#include "JMPrototypeHUDWidget.generated.h"

class UJMPrototypeProgressionSubsystem;
class UTextBlock;

/** Small code-built HUD so the blockout remains readable without a bespoke Widget Blueprint. */
UCLASS()
class P_060715_API UJMPrototypeHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Prototype|HUD")
	void ShowNotification(const FText& Message, bool bSucceeded);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

private:
	UFUNCTION()
	void HandleStateChanged(EJMPrototypeRunState PreviousState, EJMPrototypeRunState NewState);

	UFUNCTION()
	void HandleCurrencyChanged(int32 NewCurrency);

	UFUNCTION()
	void HandleUpgradeChanged(bool bPurchased);

	void Refresh();
	FText GetObjectiveText(EJMPrototypeRunState State) const;

	UPROPERTY(Transient)
	TObjectPtr<UTextBlock> StateText;

	UPROPERTY(Transient)
	TObjectPtr<UTextBlock> CurrencyText;

	UPROPERTY(Transient)
	TObjectPtr<UTextBlock> NotificationText;

	TWeakObjectPtr<UJMPrototypeProgressionSubsystem> Progression;
	FTimerHandle NotificationTimer;
};
