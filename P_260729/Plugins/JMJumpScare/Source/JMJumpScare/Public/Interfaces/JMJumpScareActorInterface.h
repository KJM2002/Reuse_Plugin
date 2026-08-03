#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "JMJumpScareActorInterface.generated.h"

class UJMJumpScareDefinition;

UINTERFACE(BlueprintType)
class JMJUMPSCARE_API UJMJumpScareActorInterface : public UInterface
{
    GENERATED_BODY()
};

class JMJUMPSCARE_API IJMJumpScareActorInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM JumpScare")
    void OnJumpScareStarted(UJMJumpScareDefinition* Definition);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM JumpScare")
    void OnJumpScareImpact(UJMJumpScareDefinition* Definition);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM JumpScare")
    void OnJumpScareExiting(UJMJumpScareDefinition* Definition);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM JumpScare")
    void OnJumpScareFinished(UJMJumpScareDefinition* Definition);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM JumpScare")
    void OnJumpScareCancelled(UJMJumpScareDefinition* Definition);
};
