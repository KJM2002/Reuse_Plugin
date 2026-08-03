#pragma once

#include "CoreMinimal.h"
#include "UI/JMObjectiveWidgetBase.h"
#include "JMObjectiveDefaultWidget.generated.h"

/** Minimal no-Blueprint fallback UI. Projects can replace it in Project Settings > Plugins > JM Objective. */
UCLASS()
class JMOBJECTIVE_API UJMObjectiveDefaultWidget : public UJMObjectiveWidgetBase
{
    GENERATED_BODY()

protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;
};

