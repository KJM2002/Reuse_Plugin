#include "Prototype/JMPrototypeLevelPortal.h"

#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "NiagaraComponent.h"
#include "Prototype/JMPrototypeTravelTransitionSubsystem.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMPrototypePortal, Log, All);

FString AJMPrototypeLevelPortal::NormalizeDestinationPackageName(const FString& PackageName)
{
	return UWorld::RemovePIEPrefix(PackageName);
}

AJMPrototypeLevelPortal::AJMPrototypeLevelPortal()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	OverlapArea = CreateDefaultSubobject<USphereComponent>(TEXT("NSOverlapArea"));
	SetRootComponent(OverlapArea);
	OverlapArea->InitSphereRadius(240.0f);
	OverlapArea->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapArea->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapArea->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapArea->SetGenerateOverlapEvents(true);
	OverlapArea->OnComponentBeginOverlap.AddDynamic(this, &AJMPrototypeLevelPortal::HandleOverlapBegin);

	PortalEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NS_Portal"));
	PortalEffect->SetupAttachment(OverlapArea);
	PortalEffect->SetAutoActivate(true);

	TransitionFocus = CreateDefaultSubobject<USceneComponent>(TEXT("TransitionFocus"));
	TransitionFocus->SetupAttachment(PortalEffect);

	ArrivalMessages = {
		NSLOCTEXT("JMPrototypeTravel", "Swallowed", "포탈이 나를 삼켰다."),
		NSLOCTEXT("JMPrototypeTravel", "Folded", "공간이 접히는 소리가 들렸다."),
		NSLOCTEXT("JMPrototypeTravel", "Pulled", "몸이 빛보다 먼저 끌려갔다."),
		NSLOCTEXT("JMPrototypeTravel", "OtherSide", "빛이 사라지고, 나는 반대편으로 떨어졌다."),
		NSLOCTEXT("JMPrototypeTravel", "AnotherWorld", "눈을 뜨면 다른 세계일 것이다.")
	};
}

void AJMPrototypeLevelPortal::BeginPlay()
{
	Super::BeginPlay();
	bTravelStarted = false;
	bRequirePortalExitBeforeRetry = false;
	OverlapArea->SetGenerateOverlapEvents(true);
	GetWorldTimerManager().SetTimer(RecheckTimerHandle, this,
		&AJMPrototypeLevelPortal::RecheckPlayerInsidePortal, 0.1f, true);
}

void AJMPrototypeLevelPortal::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(RecheckTimerHandle);
	if (EndPlayReason != EEndPlayReason::LevelTransition && TransitionPlayerController.IsValid())
	{
		TransitionPlayerController->SetIgnoreMoveInput(false);
		TransitionPlayerController->SetIgnoreLookInput(false);
	}
	Super::EndPlay(EndPlayReason);
}

void AJMPrototypeLevelPortal::HandleOverlapBegin(UPrimitiveComponent*, AActor* OtherActor,
	UPrimitiveComponent*, int32, bool, const FHitResult&)
{
	if (bTravelStarted || bRequirePortalExitBeforeRetry || !Cast<APawn>(OtherActor))
	{
		return;
	}
	if (DestinationWorld.IsNull())
	{
		UE_LOG(LogJMPrototypePortal, Error, TEXT("Portal %s has no DestinationWorld."), *GetName());
		return;
	}

	StartTransition(CastChecked<APawn>(OtherActor));
}

void AJMPrototypeLevelPortal::StartTransition(APawn* PlayerPawn)
{
	bTravelStarted = true;
	bSuctionComplete = false;
	bPreloadComplete = false;
	bPreloadSucceeded = false;
	bFadeStarted = false;
	PreloadedDestinationPackage = nullptr;
	TravelDestinationPackageName = NormalizeDestinationPackageName(
		DestinationWorld.ToSoftObjectPath().GetLongPackageName());
	TransitionElapsed = 0.0f;
	OverlapArea->SetGenerateOverlapEvents(false);
	GetWorldTimerManager().ClearTimer(RecheckTimerHandle);

	APlayerController* PC = Cast<APlayerController>(PlayerPawn ? PlayerPawn->GetController() : nullptr);
	if (!PC)
	{
		PC = UGameplayStatics::GetPlayerController(this, 0);
	}
	TransitionPlayerController = PC;
	if (PC)
	{
		PC->SetIgnoreMoveInput(true);
		PC->SetIgnoreLookInput(true);
		OriginalViewTarget = PC->GetViewTarget();

		const FVector ViewLocation = PC->PlayerCameraManager
			? PC->PlayerCameraManager->GetCameraLocation() : PlayerPawn->GetActorLocation();
		const FRotator ViewRotation = PC->PlayerCameraManager
			? PC->PlayerCameraManager->GetCameraRotation() : PlayerPawn->GetActorRotation();
		InitialFOV = PC->PlayerCameraManager ? PC->PlayerCameraManager->GetFOVAngle() : 80.0f;
		InitialCameraLocation = ViewLocation;
		InitialCameraRotation = ViewRotation.Quaternion();
		TransitionFocusLocation = TransitionFocus
			? TransitionFocus->GetComponentLocation() : GetActorLocation();
		const FVector ToFocus = TransitionFocusLocation - ViewLocation;
		const float AvailableTravelDistance = FMath::Max(0.0f, ToFocus.Size() - StopDistance);
		const float CameraTravelDistance = FMath::Min(MaximumCameraTravelDistance, AvailableTravelDistance);
		TargetCameraLocation = ViewLocation
			+ ToFocus.GetSafeNormal(SMALL_NUMBER, ViewRotation.Vector()) * CameraTravelDistance;

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ACameraActor* Camera = GetWorld()->SpawnActor<ACameraActor>(ViewLocation, ViewRotation, SpawnParameters);
		TransitionCamera = Camera;
		if (Camera)
		{
			UCameraComponent* CameraComponent = Camera->GetCameraComponent();
			CameraComponent->SetFieldOfView(InitialFOV);
			CameraComponent->PostProcessBlendWeight = 1.0f;
			CameraComponent->PostProcessSettings.bOverride_MotionBlurAmount = true;
			CameraComponent->PostProcessSettings.MotionBlurAmount = 0.65f;
			CameraComponent->PostProcessSettings.bOverride_MotionBlurMax = true;
			CameraComponent->PostProcessSettings.MotionBlurMax = 8.0f;
			CameraComponent->PostProcessSettings.bOverride_VignetteIntensity = true;
			CameraComponent->PostProcessSettings.VignetteIntensity = 0.35f;
			CameraComponent->PostProcessSettings.bOverride_SceneFringeIntensity = true;
			CameraComponent->PostProcessSettings.SceneFringeIntensity = 1.5f;
			if (WarpMaterial)
			{
				WarpMaterialInstance = UMaterialInstanceDynamic::Create(WarpMaterial, this);
				CameraComponent->PostProcessSettings.AddBlendable(WarpMaterialInstance, 1.0f);
			}
			PC->SetViewTarget(Camera);
		}
	}

	UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s asynchronously preloading %s."),
		*GetName(), *TravelDestinationPackageName);
	LoadPackageAsync(TravelDestinationPackageName,
		FLoadPackageAsyncDelegate::CreateUObject(this, &ThisClass::HandleDestinationPreloaded));
	SetActorTickEnabled(true);
}

void AJMPrototypeLevelPortal::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!bTravelStarted || bSuctionComplete)
	{
		return;
	}
	TransitionElapsed += DeltaSeconds;
	const float NormalizedTime = FMath::Clamp(TransitionElapsed / FMath::Max(SuctionDuration, 0.1f), 0.0f, 1.0f);
	UpdateTransition(NormalizedTime);
	if (NormalizedTime >= 1.0f)
	{
		bSuctionComplete = true;
		TryExecuteTravel();
	}
}

void AJMPrototypeLevelPortal::UpdateTransition(const float NormalizedTime)
{
	const float MoveAlpha = SuctionCurve
		? FMath::Clamp(SuctionCurve->GetFloatValue(NormalizedTime), 0.0f, 1.0f)
		: NormalizedTime * NormalizedTime * NormalizedTime;
	const float WarpAlpha = FMath::InterpEaseIn(0.0f, 1.0f, NormalizedTime, 2.4f);
	if (ACameraActor* Camera = TransitionCamera.Get())
	{
		const FVector NewLocation = FMath::Lerp(InitialCameraLocation, TargetCameraLocation, MoveAlpha);
		Camera->SetActorLocation(NewLocation);
		const FQuat LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
			NewLocation, TransitionFocusLocation).Quaternion();
		const float RotationAlpha = FMath::InterpEaseInOut(
			0.0f, 1.0f, NormalizedTime, RotationEaseExponent);
		Camera->SetActorRotation(FQuat::Slerp(InitialCameraRotation, LookAtRotation, RotationAlpha));

		float NewFOV = 0.0f;
		if (bUseWideFOVKick)
		{
			NewFOV = NormalizedTime < 0.8f
				? FMath::Lerp(InitialFOV, PeakFOV, FMath::InterpEaseInOut(0.0f, 1.0f, NormalizedTime / 0.8f, 2.0f))
				: FMath::Lerp(PeakFOV, FinalFOV, FMath::InterpEaseIn(0.0f, 1.0f, (NormalizedTime - 0.8f) / 0.2f, 2.0f));
		}
		else
		{
			NewFOV = FMath::Lerp(InitialFOV, FinalFOV,
				FMath::InterpEaseIn(0.0f, 1.0f, NormalizedTime, 2.2f));
		}
		Camera->GetCameraComponent()->SetFieldOfView(NewFOV);
	}
	if (WarpMaterialInstance)
	{
		WarpMaterialInstance->SetScalarParameterValue(WarpStrengthParameterName, MaximumWarpStrength * WarpAlpha);
	}
	if (!bFadeStarted && NormalizedTime >= 0.82f && TransitionPlayerController.IsValid()
		&& TransitionPlayerController->PlayerCameraManager)
	{
		bFadeStarted = true;
		TransitionPlayerController->PlayerCameraManager->StartCameraFade(
			0.0f, 1.0f, SuctionDuration * 0.18f, FLinearColor::Black, false, true);
	}
}

void AJMPrototypeLevelPortal::HandleDestinationPreloaded(const FName&, UPackage* LoadedPackage, const EAsyncLoadingResult::Type Result)
{
	bPreloadComplete = true;
	bPreloadSucceeded = Result == EAsyncLoadingResult::Succeeded;
	PreloadedDestinationPackage = bPreloadSucceeded ? LoadedPackage : nullptr;
	if (!bPreloadSucceeded)
	{
		UE_LOG(LogJMPrototypePortal, Error, TEXT("Portal %s failed to preload %s."),
			*GetName(), *TravelDestinationPackageName);
		CancelTransition();
		return;
	}
	TryExecuteTravel();
}

void AJMPrototypeLevelPortal::TryExecuteTravel()
{
	if (!bSuctionComplete || !bPreloadComplete || !bPreloadSucceeded)
	{
		return;
	}
	SetActorTickEnabled(false);
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UJMPrototypeTravelTransitionSubsystem* Transition = GI->GetSubsystem<UJMPrototypeTravelTransitionSubsystem>())
		{
			Transition->PrepareLoadingScreen(ArrivalMessages);
		}
	}
	UE_LOG(LogJMPrototypePortal, Display, TEXT("Portal %s opening preloaded world %s."),
		*GetName(), *TravelDestinationPackageName);
	UGameplayStatics::OpenLevel(this, FName(*TravelDestinationPackageName));
}

void AJMPrototypeLevelPortal::CancelTransition()
{
	SetActorTickEnabled(false);
	bTravelStarted = false;
	bRequirePortalExitBeforeRetry = true;
	OverlapArea->SetGenerateOverlapEvents(true);
	if (APlayerController* PC = TransitionPlayerController.Get())
	{
		PC->SetIgnoreMoveInput(false);
		PC->SetIgnoreLookInput(false);
		if (OriginalViewTarget.IsValid())
		{
			PC->SetViewTargetWithBlend(OriginalViewTarget.Get(), 0.25f);
		}
		if (PC->PlayerCameraManager)
		{
			PC->PlayerCameraManager->StartCameraFade(1.0f, 0.0f, 0.25f, FLinearColor::Black, false, false);
		}
	}
	if (TransitionCamera.IsValid())
	{
		TransitionCamera->Destroy();
	}
	WarpMaterialInstance = nullptr;
	PreloadedDestinationPackage = nullptr;
	GetWorldTimerManager().SetTimer(RecheckTimerHandle, this,
		&ThisClass::RecheckPlayerInsidePortal, 0.1f, true);
}

void AJMPrototypeLevelPortal::RecheckPlayerInsidePortal()
{
	if (bTravelStarted)
	{
		return;
	}
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn)
	{
		return;
	}
	const float Radius = OverlapArea->GetScaledSphereRadius();
	const bool bPlayerInside = FVector::DistSquared(PlayerPawn->GetActorLocation(),
		OverlapArea->GetComponentLocation()) <= FMath::Square(Radius);
	if (bRequirePortalExitBeforeRetry)
	{
		if (!bPlayerInside)
		{
			bRequirePortalExitBeforeRetry = false;
		}
		return;
	}
	if (bPlayerInside)
	{
		HandleOverlapBegin(OverlapArea, PlayerPawn, nullptr, 0, false, FHitResult());
	}
}
