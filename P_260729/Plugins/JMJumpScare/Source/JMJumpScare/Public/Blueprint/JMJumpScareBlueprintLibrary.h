#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/JMJumpScareTypes.h"
#include "JMJumpScareBlueprintLibrary.generated.h"

class APlayerController;
class UJMJumpScareDefinition;

UCLASS()
class JMJUMPSCARE_API UJMJumpScareBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /** Shows Definition.Image over the target player's camera. Target Player may be left empty for player 0. */
    UFUNCTION(BlueprintCallable, Category="JM JumpScare", meta=(WorldContext="WorldContextObject", DisplayName="Play 2D JumpScare", AdvancedDisplay="TargetPlayer"))
    static EJMJumpScarePlayResult PlayJumpScare(
        UObject* WorldContextObject,
        UJMJumpScareDefinition* Definition,
        APlayerController* TargetPlayer = nullptr);

    UFUNCTION(BlueprintCallable, Category="JM JumpScare", meta=(WorldContext="WorldContextObject", DisplayName="Cancel JumpScare"))
    static bool CancelJumpScare(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category="JM JumpScare", meta=(WorldContext="WorldContextObject", DisplayName="Is JumpScare Playing"))
    static bool IsJumpScarePlaying(UObject* WorldContextObject);
};
