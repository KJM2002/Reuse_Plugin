#pragma once

#include "CoreMinimal.h"
#include "JMRoomGridTypes.generated.h"

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EJMRoomDirection : uint8
{
    None  = 0 UMETA(Hidden),
    North = 1 << 0,
    East  = 1 << 1,
    South = 1 << 2,
    West  = 1 << 3,
    All   = North | East | South | West UMETA(Hidden)
};
ENUM_CLASS_FLAGS(EJMRoomDirection);

UENUM(BlueprintType)
enum class EJMRoomJunctionType : uint8
{
    TwoWay,
    ThreeWay,
    FourWay
};

UENUM(BlueprintType)
enum class EJMRoomLayoutVariant : uint8
{
    A,
    B,
    C,
    D
};

UENUM(BlueprintType)
enum class EJMPrototypeMeshRole : uint8
{
    Floor,
    Wall,
    Ceiling
};

USTRUCT(BlueprintType)
struct JMROOMGRIDRUNTIME_API FJMGridCoordinate
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid")
    int32 X = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid")
    int32 Y = 0;

    FJMGridCoordinate() = default;
    FJMGridCoordinate(int32 InX, int32 InY) : X(InX), Y(InY) {}

    bool operator==(const FJMGridCoordinate& Other) const { return X == Other.X && Y == Other.Y; }
};

FORCEINLINE uint32 GetTypeHash(const FJMGridCoordinate& Coordinate)
{
    return HashCombine(GetTypeHash(Coordinate.X), GetTypeHash(Coordinate.Y));
}

USTRUCT(BlueprintType)
struct JMROOMGRIDRUNTIME_API FJMRoomValidationResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Validation")
    bool bIsValid = true;

    UPROPERTY(BlueprintReadOnly, Category="Validation")
    TArray<FText> Errors;

    UPROPERTY(BlueprintReadOnly, Category="Validation")
    TArray<FText> Warnings;

    void AddError(const FText& Message) { bIsValid = false; Errors.Add(Message); }
    void AddWarning(const FText& Message) { Warnings.Add(Message); }
};
