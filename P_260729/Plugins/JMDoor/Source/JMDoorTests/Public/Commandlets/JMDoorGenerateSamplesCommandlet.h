#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "JMDoorGenerateSamplesCommandlet.generated.h"

UCLASS()
class JMDOORTESTS_API UJMDoorGenerateSamplesCommandlet : public UCommandlet
{
    GENERATED_BODY()

public:
    UJMDoorGenerateSamplesCommandlet();
    virtual int32 Main(const FString& Params) override;
};
