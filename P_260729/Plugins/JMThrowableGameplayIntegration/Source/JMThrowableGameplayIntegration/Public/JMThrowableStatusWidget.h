#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JMThrowableTypes.h"
#include "JMThrowableStatusWidget.generated.h"

class UTextBlock;

/** Asset-free local-player status hint for the active throwable session. */
UCLASS()
class JMTHROWABLEGAMEPLAYINTEGRATION_API UJMThrowableStatusWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeOnInitialized() override;
    void SetThrowableState(EJMThrowableUseState State);

private:
    UPROPERTY(Transient) TObjectPtr<UTextBlock> StatusText;
};
