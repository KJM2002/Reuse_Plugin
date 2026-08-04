#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Types/JMRoomGridTypes.h"
#include "JMRoomDefinition.generated.h"

class AJMRoomModule;

UCLASS(BlueprintType)
class JMROOMGRIDRUNTIME_API UJMRoomDefinition final : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    virtual FPrimaryAssetId GetPrimaryAssetId() const override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FName RoomId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Identity")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room")
    TSoftClassPtr<AJMRoomModule> RoomBlueprintClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room")
    EJMRoomJunctionType JunctionType = EJMRoomJunctionType::FourWay;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room", meta=(Bitmask, BitmaskEnum="/Script/JMRoomGridRuntime.EJMRoomDirection"))
    int32 CanonicalOpenDirections = static_cast<int32>(EJMRoomDirection::All);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room", meta=(ClampMin="0", ClampMax="270", Multiple="90"))
    TArray<int32> AllowedRotations { 0, 90, 180, 270 };

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection", meta=(ClampMin="0.0"))
    float SelectionWeight = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection", meta=(ClampMin="-1"))
    int32 MaximumSpawnCount = -1;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection", meta=(ClampMin="0"))
    int32 MinimumSpawnCount = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
    FGameplayTagContainer ThemeTags;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tags")
    FGameplayTagContainer SpecialTags;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selection", meta=(ClampMin="0.0"))
    float DangerScore = 0.0f;
};
