#include "AI/Blackout/JMBlackoutLightZone.h"

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "EngineUtils.h"

AJMBlackoutLightZone::AJMBlackoutLightZone()
{
	PrimaryActorTick.bCanEverTick = false;
	SafeRadius = CreateDefaultSubobject<USphereComponent>(TEXT("SafeRadius"));
	SetRootComponent(SafeRadius);
	SafeRadius->SetSphereRadius(500.0f);
	SafeRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SafeRadius->SetCollisionResponseToAllChannels(ECR_Ignore);

	SafeLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("SafeLight"));
	SafeLight->SetupAttachment(SafeRadius);
	SafeLight->SetLightColor(FLinearColor(0.65f, 0.82f, 1.0f));
	SafeLight->SetIntensity(4500.0f);
	SafeLight->SetAttenuationRadius(500.0f);
}

bool AJMBlackoutLightZone::ProtectsLocation(const FVector& Location) const
{
	return !IsHidden() && SafeRadius && FVector::DistSquared(Location, GetActorLocation()) <= FMath::Square(SafeRadius->GetScaledSphereRadius());
}

bool AJMBlackoutLightZone::IsLocationProtected(const UWorld* World, const FVector& Location)
{
	if (!World)
	{
		return false;
	}
	for (TActorIterator<AJMBlackoutLightZone> It(World); It; ++It)
	{
		if (It->ProtectsLocation(Location))
		{
			return true;
		}
	}
	return false;
}
