#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JMAssetOverviewAuthoringLibrary.generated.h"

UCLASS()
class P_060715TESTS_API UJMAssetOverviewAuthoringLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Rebuilds /Game/Overview/Level_AssetOverview from the current project and plugin asset registry. */
	UFUNCTION(BlueprintCallable, Category="JM|Overview")
	static bool BuildAssetOverviewLevel();
};
