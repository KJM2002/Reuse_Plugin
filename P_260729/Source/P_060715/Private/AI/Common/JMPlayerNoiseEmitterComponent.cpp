#include "AI/Common/JMPlayerNoiseEmitterComponent.h"

#include "Components/JMHideInteractorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AISense_Hearing.h"

UJMPlayerNoiseEmitterComponent::UJMPlayerNoiseEmitterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.1f;
}

void UJMPlayerNoiseEmitterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character || !Character->IsPlayerControlled() || !Character->GetCharacterMovement()->IsMovingOnGround())
	{
		return;
	}
	if (const UJMHideInteractorComponent* Hide = Character->FindComponentByClass<UJMHideInteractorComponent>();
		Hide && Hide->IsHidden())
	{
		return;
	}
	const float Speed = Character->GetVelocity().Size2D();
	if (Speed < 90.0f)
	{
		return;
	}
	const double Now = GetWorld()->GetTimeSeconds();
	if (LastFootstepTime >= 0.0 && Now - LastFootstepTime < FootstepInterval)
	{
		return;
	}
	LastFootstepTime = Now;
	ReportDungeonNoise(Speed >= RunSpeedThreshold ? RunLoudness : WalkLoudness, TEXT("JM.Noise.Footstep"));
}

void UJMPlayerNoiseEmitterComponent::ReportDungeonNoise(float Loudness, FName NoiseTag, float MaxRange)
{
	if (GetWorld() && GetOwner() && Loudness > 0.0f)
	{
		UAISense_Hearing::ReportNoiseEvent(GetWorld(), GetOwner()->GetActorLocation(), Loudness,
			GetOwner(), MaxRange, NoiseTag);
	}
}
