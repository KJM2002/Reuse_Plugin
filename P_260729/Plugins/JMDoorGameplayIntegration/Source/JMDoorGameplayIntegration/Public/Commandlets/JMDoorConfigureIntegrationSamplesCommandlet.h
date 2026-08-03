#pragma once

#include "Commandlets/Commandlet.h"
#include "JMDoorConfigureIntegrationSamplesCommandlet.generated.h"

/** Internal authoring commandlet used to keep the portable Old Key sample configured. */
UCLASS()
class JMDOORGAMEPLAYINTEGRATION_API UJMDoorConfigureIntegrationSamplesCommandlet final : public UCommandlet
{
    GENERATED_BODY()

public:
    UJMDoorConfigureIntegrationSamplesCommandlet();
    virtual int32 Main(const FString& Params) override;
};
