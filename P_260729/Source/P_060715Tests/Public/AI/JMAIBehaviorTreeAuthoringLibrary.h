#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JMAIBehaviorTreeAuthoringLibrary.generated.h"

/** Editor-only deterministic authoring entry point for the three prototype monster BT asset sets. */
UCLASS()
class P_060715TESTS_API UJMAIBehaviorTreeAuthoringLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="JM AI|Authoring")
	static bool BuildMonsterBehaviorTreeAssets();
};
