#pragma once

#include "Components/ActorComponent.h"
#include "InputCoreTypes.h"
#include "JMPhysicalGrabberComponent.generated.h"

class UPrimitiveComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJMPhysicalGrabEvent, UPrimitiveComponent*, Component);

/**
 * Pulls a simulated body toward the player's view using a force-limited damped spring.
 * The same force budget is used for every body, so heavier bodies accelerate and lift less.
 */
UCLASS(ClassGroup=(JM), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class JMPHYSICALGRABBER_API UJMPhysicalGrabberComponent final : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMPhysicalGrabberComponent();

    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category="JM|Physical Grabber")
    bool TryGrab();

    UFUNCTION(BlueprintCallable, Category="JM|Physical Grabber")
    void Release();

    UFUNCTION(BlueprintPure, Category="JM|Physical Grabber")
    bool IsHoldingObject() const;

    UFUNCTION(BlueprintPure, Category="JM|Physical Grabber")
    UPrimitiveComponent* GetGrabbedComponent() const;

    UPROPERTY(BlueprintAssignable, Category="JM|Physical Grabber")
    FJMPhysicalGrabEvent OnGrabbed;

    UPROPERTY(BlueprintAssignable, Category="JM|Physical Grabber")
    FJMPhysicalGrabEvent OnReleased;

    /** Poll this key locally. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Input")
    FKey GrabKey = EKeys::LeftMouseButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Input")
    bool bToggleGrab = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Trace", meta=(ClampMin="1.0", Units="cm"))
    float GrabDistance = 350.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Trace")
    TEnumAsByte<ECollisionChannel> TraceChannel = ECC_PhysicsBody;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Hold", meta=(ClampMin="1.0", Units="cm"))
    float HoldDistance = 180.0f;

    /** Maximum player force in kg*cm/s^2. About 60000 can statically support roughly 61 kg. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Force", meta=(ClampMin="0.0"))
    float MaxGrabForce = 60000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Force", meta=(ClampMin="0.0"))
    float SpringStrength = 1500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Force", meta=(ClampMin="0.0"))
    float Damping = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Safety", meta=(ClampMin="1.0", Units="cm"))
    float BreakDistance = 275.0f;

    /** Zero means there is no hard mass rejection; force alone determines whether it can lift. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Safety", meta=(ClampMin="0.0", Units="kg"))
    float MaxGrabbableMass = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Collision")
    bool bIgnorePawnCollisionWhileHeld = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM|Physical Grabber|Debug")
    bool bDrawDebug = false;

private:
    bool GetPlayerView(FVector& OutLocation, FVector& OutDirection) const;
    void ApplyGrabForce(float DeltaTime);

    UPROPERTY(Transient)
    TObjectPtr<UPrimitiveComponent> GrabbedComponent;

    FName GrabbedBone = NAME_None;
    FVector LocalGrabPoint = FVector::ZeroVector;
    TEnumAsByte<ECollisionResponse> PreviousPawnResponse = ECR_Block;
};
