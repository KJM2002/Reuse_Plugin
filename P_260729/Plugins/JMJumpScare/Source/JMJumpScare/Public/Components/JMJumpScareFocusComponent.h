#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "JMJumpScareFocusComponent.generated.h"

/** Optional face/eyes/focal transform used by ForcedLookAt without assuming an Actor root location. */
UCLASS(ClassGroup=(JM), BlueprintType, meta=(BlueprintSpawnableComponent, DisplayName="JM JumpScare Focus"))
class JMJUMPSCARE_API UJMJumpScareFocusComponent : public USceneComponent
{
    GENERATED_BODY()

public:
    UJMJumpScareFocusComponent();
};
