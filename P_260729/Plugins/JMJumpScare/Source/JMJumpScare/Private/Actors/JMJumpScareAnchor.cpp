#include "Actors/JMJumpScareAnchor.h"

#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/SceneComponent.h"

AJMJumpScareAnchor::AJMJumpScareAnchor()
{
    PrimaryActorTick.bCanEverTick = false;
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

#if WITH_EDITORONLY_DATA
    DirectionArrow = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("DirectionArrow"));
    if (DirectionArrow)
    {
        DirectionArrow->SetupAttachment(SceneRoot);
        DirectionArrow->ArrowColor = FColor(220, 30, 30);
        DirectionArrow->ArrowSize = 1.5f;
        DirectionArrow->bIsScreenSizeScaled = true;
    }
    Billboard = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
    if (Billboard)
    {
        Billboard->SetupAttachment(SceneRoot);
        Billboard->bIsScreenSizeScaled = true;
    }
#endif
}

FTransform AJMJumpScareAnchor::GetJumpScareAnchorTransform() const
{
    FTransform Result = GetActorTransform();
    if (bOverrideRotation)
    {
        Result.SetRotation(RotationOverride.Quaternion());
    }
    return Result;
}
