#pragma once

#include "CoreMinimal.h"
#include "Subsystems/JMJumpScareSubsystem.h"
#include "JMJumpScareSafetyTestReceiver.generated.h"

UCLASS()
class UJMJumpScareSafetyTestReceiver : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY()
    TObjectPtr<UJMJumpScareSubsystem> Subsystem;

    int32 CancelCount = 0;

    UFUNCTION()
    void CancelOnWaiting(EJMJumpScareState OldState, EJMJumpScareState NewState)
    {
        if (NewState == EJMJumpScareState::Waiting && Subsystem)
        {
            ++CancelCount;
            Subsystem->CancelJumpScare();
        }
    }
};
