#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "JMRoomGridSettings.generated.h"

class UStaticMesh;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="JM Room Grid"))
class JMROOMGRIDRUNTIME_API UJMRoomGridSettings final : public UDeveloperSettings
{
    GENERATED_BODY()

public:
    UJMRoomGridSettings();

    virtual FName GetCategoryName() const override { return TEXT("Plugins"); }

    UPROPERTY(Config, EditAnywhere, Category="Prototype Assets", meta=(AllowedClasses="/Script/Engine.StaticMesh"))
    TSoftObjectPtr<UStaticMesh> FloorMesh;

    UPROPERTY(Config, EditAnywhere, Category="Prototype Assets", meta=(AllowedClasses="/Script/Engine.StaticMesh"))
    TSoftObjectPtr<UStaticMesh> WallMesh;

    UPROPERTY(Config, EditAnywhere, Category="Prototype Assets", meta=(AllowedClasses="/Script/Engine.StaticMesh"))
    TSoftObjectPtr<UStaticMesh> CeilingMesh;

    UPROPERTY(Config, EditAnywhere, Category="Prototype Specification", meta=(ClampMin="1.0"))
    float RoomCellSize = 5200.0f;

    UPROPERTY(Config, EditAnywhere, Category="Prototype Specification", meta=(ClampMin="1.0"))
    float RoomInteriorHeight = 500.0f;

    UPROPERTY(Config, EditAnywhere, Category="Validation", meta=(ClampMin="0.0"))
    float SizeTolerance = 2.0f;

    UPROPERTY(Config, EditAnywhere, Category="Validation", meta=(ClampMin="0.0"))
    float PivotTolerance = 1.0f;
};
