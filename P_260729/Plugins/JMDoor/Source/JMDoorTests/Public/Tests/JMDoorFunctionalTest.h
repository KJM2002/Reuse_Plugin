#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "JMDoorFunctionalTest.generated.h"

class AJMRotatingDoorActor;

UCLASS()
class JMDOORTESTS_API AJMDoorFunctionalTest : public AFunctionalTest
{
    GENERATED_BODY()

public:
    virtual bool IsEditorOnlyLoadedInPIE() const override { return true; }
    virtual void StartTest() override;

private:
    UFUNCTION()
    void VerifyDoorOpened();

    UPROPERTY(Transient)
    TObjectPtr<AJMRotatingDoorActor> SpawnedDoor;

    FTimerHandle VerificationTimer;
};
