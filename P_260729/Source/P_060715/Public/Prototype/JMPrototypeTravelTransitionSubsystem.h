#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "JMPrototypeTravelTransitionSubsystem.generated.h"

class UWorld;

/** Keeps an animated loading cover alive while OpenLevel blocks the game thread. */
UCLASS()
class P_060715_API UJMPrototypeTravelTransitionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Must be called immediately before OpenLevel. A random message is selected for the click-to-reveal cover. */
	void PrepareLoadingScreen(const TArray<FText>& ArrivalMessages);

private:
	void HandlePostLoadMap(UWorld* LoadedWorld);
	void ShowArrivalScreen(UWorld* LoadedWorld);
	void DismissArrivalScreen();
	void RemoveArrivalScreen();

	FText PendingArrivalMessage;
	TSharedPtr<class SWidget> ArrivalOverlayWidget;
	TWeakObjectPtr<UWorld> ArrivalWorld;
	bool bArrivalPending = false;
	bool bPreviousShowMouseCursor = false;
};
