#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JMThrowableTypes.h"
#include "JMThrowableMovementComponent.generated.h"

UCLASS(ClassGroup=(JM), meta=(BlueprintSpawnableComponent))
class JMTHROWABLE_API UJMThrowableMovementComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UJMThrowableMovementComponent();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    void Launch(const FJMThrowParameters& Parameters);
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) EJMThrowableProjectileState State = EJMThrowableProjectileState::Inactive;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly) FVector Velocity = FVector::ZeroVector;
private:
    FJMThrowParameters Parameters;
    FJMThrowSimulationState SimulationState;
    float Accumulator = 0.f;
    void Rest(const FHitResult& Hit);
};
