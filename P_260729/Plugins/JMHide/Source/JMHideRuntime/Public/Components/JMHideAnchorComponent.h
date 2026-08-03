#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Types/JMHideTypes.h"
#include "JMHideAnchorComponent.generated.h"

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDERUNTIME_API UJMHideAnchorComponent final : public USceneComponent
{
    GENERATED_BODY()

public:
    UJMHideAnchorComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Hide")
    EJMHideAnchorRole Role = EJMHideAnchorRole::Occupant;
};
