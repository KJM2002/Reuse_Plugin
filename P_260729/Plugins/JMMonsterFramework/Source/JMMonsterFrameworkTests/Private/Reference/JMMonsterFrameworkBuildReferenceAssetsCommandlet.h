#pragma once

#include "Commandlets/Commandlet.h"
#include "JMMonsterFrameworkBuildReferenceAssetsCommandlet.generated.h"

/** One-shot UE editor asset authoring entry point. Binary assets are always produced by UE serialization. */
UCLASS()
class UJMMonsterFrameworkBuildReferenceAssetsCommandlet : public UCommandlet
{
    GENERATED_BODY()

public:
    UJMMonsterFrameworkBuildReferenceAssetsCommandlet();
    virtual int32 Main(const FString& Params) override;
};
