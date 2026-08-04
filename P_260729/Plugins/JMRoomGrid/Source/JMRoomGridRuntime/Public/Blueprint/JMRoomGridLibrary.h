#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/JMRoomGridTypes.h"
#include "JMRoomGridLibrary.generated.h"

UCLASS()
class JMROOMGRIDRUNTIME_API UJMRoomGridLibrary final : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="JM Room Grid|Direction")
    static EJMRoomDirection RotateDirectionMask(EJMRoomDirection Mask, int32 YawDegrees);

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Direction")
    static EJMRoomDirection OppositeDirection(EJMRoomDirection Direction);

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Direction")
    static int32 CountDirections(EJMRoomDirection Mask);

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Direction")
    static FVector DirectionVector(EJMRoomDirection Direction);

    UFUNCTION(BlueprintPure, Category="JM Room Grid|Direction")
    static int32 NormalizeQuarterTurn(int32 YawDegrees);

    static FJMRoomValidationResult ValidatePrototypeBounds(
        const FBox& Bounds,
        EJMPrototypeMeshRole Role,
        float SizeTolerance = 2.0f,
        float PivotTolerance = 1.0f);
};
