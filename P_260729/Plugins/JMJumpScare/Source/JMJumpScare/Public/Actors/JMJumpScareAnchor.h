#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "JMJumpScareAnchor.generated.h"

class UArrowComponent;
class UBillboardComponent;
class USceneComponent;

UCLASS(BlueprintType, Blueprintable, meta=(DisplayName="JM JumpScare Anchor"))
class JMJUMPSCARE_API AJMJumpScareAnchor : public AActor
{
    GENERATED_BODY()

public:
    AJMJumpScareAnchor();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="JM JumpScare | Spawn")
    TObjectPtr<USceneComponent> SceneRoot;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Identity", meta=(Categories="JumpScare.Anchor"))
    FGameplayTag AnchorId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Spawn")
    bool bOverrideRotation = false;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM JumpScare | Spawn", meta=(EditCondition="bOverrideRotation"))
    FRotator RotationOverride = FRotator::ZeroRotator;

    UFUNCTION(BlueprintPure, Category="JM JumpScare")
    FTransform GetJumpScareAnchorTransform() const;

#if WITH_EDITORONLY_DATA
    UPROPERTY(VisibleAnywhere, Category="JM JumpScare | Debug")
    TObjectPtr<UArrowComponent> DirectionArrow;

    UPROPERTY(VisibleAnywhere, Category="JM JumpScare | Debug")
    TObjectPtr<UBillboardComponent> Billboard;
#endif
};
