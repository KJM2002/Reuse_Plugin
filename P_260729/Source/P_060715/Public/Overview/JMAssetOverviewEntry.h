#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/SoftObjectPtr.h"
#include "JMAssetOverviewEntry.generated.h"

class UAudioComponent;
class UBillboardComponent;
class UChildActorComponent;
class UNiagaraComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UTextRenderComponent;

/** Editor-only catalog entry used by Level_AssetOverview. */
UCLASS(NotBlueprintable)
class P_060715_API AJMAssetOverviewEntry : public AActor
{
	GENERATED_BODY()

public:
	AJMAssetOverviewEntry();

	virtual bool IsEditorOnly() const override { return true; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<USceneComponent> OverviewRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UStaticMeshComponent> Pedestal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UStaticMeshComponent> StaticPreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<USkeletalMeshComponent> SkeletalPreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UBillboardComponent> TexturePreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UAudioComponent> AudioPreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UNiagaraComponent> NiagaraPreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UChildActorComponent> ActorPreview;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UTextRenderComponent> AssetNameText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	TObjectPtr<UTextRenderComponent> AssetDetailText;

	/** Select this actor and use the magnifying glass in Details to browse to the source asset. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Overview")
	TSoftObjectPtr<UObject> RepresentedAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	FName AssetClassName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	FName MountPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Overview")
	FString PackagePath;

	void ConfigureOverviewEntry(const FSoftObjectPath& AssetPath, FName AssetName,
		FName ClassName, FName InMountPoint, const FString& InPackagePath, FColor DisplayColor);

private:
	void ResetPreviews();
	void BuildPreview();
	void NormalizeActorPreview();
};
