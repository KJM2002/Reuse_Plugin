#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Types/JMHideTypes.h"
#include "JMHideDefinition.generated.h"

UCLASS(BlueprintType)
class JMHIDERUNTIME_API UJMHideDefinition final : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Hide")
    EJMHideSpotArchetype Archetype = EJMHideSpotArchetype::OpenSpace;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Hide", meta=(Categories="Hide.Type"))
    FGameplayTag HideType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Hide")
    FJMHideConfigOverride ConfigOverride;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
