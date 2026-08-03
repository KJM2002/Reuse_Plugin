#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Types/JMReconTypes.h"
#include "JMReconTarget.generated.h"

class AActor;

UINTERFACE(BlueprintType, Blueprintable)
class JMRECONRUNTIME_API UJMReconTarget : public UInterface
{
    GENERATED_BODY()
};

class JMRECONRUNTIME_API IJMReconTarget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    FJMReconRequestResult CanStartRecon(AActor* Interactor, const FGuid& SessionId) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    bool CanEnterListen(AActor* Interactor, const FGuid& SessionId) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    bool CanEnterPeek(AActor* Interactor, const FGuid& SessionId) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    void BeginRecon(AActor* Interactor, const FGuid& SessionId);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    void EndRecon(AActor* Interactor, const FGuid& SessionId, EJMReconEndReason Reason);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    void BeginPeekPose(const FGuid& SessionId, float OpenFraction);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="JM Recon")
    void EndPeekPose(const FGuid& SessionId);
};
