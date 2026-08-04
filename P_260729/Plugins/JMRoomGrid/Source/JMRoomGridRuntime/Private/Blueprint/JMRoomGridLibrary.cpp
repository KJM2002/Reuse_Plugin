#include "Blueprint/JMRoomGridLibrary.h"

#define LOCTEXT_NAMESPACE "JMRoomGridLibrary"

int32 UJMRoomGridLibrary::NormalizeQuarterTurn(const int32 YawDegrees)
{
    const int32 Normalized = ((YawDegrees % 360) + 360) % 360;
    return ((Normalized + 45) / 90 * 90) % 360;
}

EJMRoomDirection UJMRoomGridLibrary::RotateDirectionMask(const EJMRoomDirection Mask, const int32 YawDegrees)
{
    const int32 Turns = NormalizeQuarterTurn(YawDegrees) / 90;
    uint8 Result = 0;
    const uint8 Raw = static_cast<uint8>(Mask) & static_cast<uint8>(EJMRoomDirection::All);
    for (int32 Index = 0; Index < 4; ++Index)
    {
        if ((Raw & (1 << Index)) != 0)
        {
            // Unreal positive yaw rotates +X toward +Y, therefore N,E,S,W indices move backward.
            Result |= 1 << ((Index - Turns + 4) % 4);
        }
    }
    return static_cast<EJMRoomDirection>(Result);
}

EJMRoomDirection UJMRoomGridLibrary::OppositeDirection(const EJMRoomDirection Direction)
{
    return RotateDirectionMask(Direction, 180);
}

int32 UJMRoomGridLibrary::CountDirections(const EJMRoomDirection Mask)
{
    uint8 Value = static_cast<uint8>(Mask) & static_cast<uint8>(EJMRoomDirection::All);
    int32 Count = 0;
    while (Value != 0)
    {
        Count += Value & 1;
        Value >>= 1;
    }
    return Count;
}

FVector UJMRoomGridLibrary::DirectionVector(const EJMRoomDirection Direction)
{
    switch (Direction)
    {
    case EJMRoomDirection::North: return FVector(0.0, 1.0, 0.0);
    case EJMRoomDirection::East: return FVector(1.0, 0.0, 0.0);
    case EJMRoomDirection::South: return FVector(0.0, -1.0, 0.0);
    case EJMRoomDirection::West: return FVector(-1.0, 0.0, 0.0);
    default: return FVector::ZeroVector;
    }
}

FJMRoomValidationResult UJMRoomGridLibrary::ValidatePrototypeBounds(
    const FBox& Bounds,
    const EJMPrototypeMeshRole Role,
    const float SizeTolerance,
    const float PivotTolerance)
{
    FJMRoomValidationResult Result;
    const FVector ExpectedSize = Role == EJMPrototypeMeshRole::Wall
        ? FVector(400.0, 20.0, 500.0)
        : FVector(400.0, 400.0, 20.0);
    const FVector Size = Bounds.GetSize();
    if (!Size.Equals(ExpectedSize, SizeTolerance))
    {
        Result.AddError(FText::Format(
            LOCTEXT("BadSize", "Mesh size {0} does not match expected {1} within {2} cm."),
            FText::FromString(Size.ToString()), FText::FromString(ExpectedSize.ToString()), FText::AsNumber(SizeTolerance)));
    }

    const float ExpectedMinZ = Role == EJMPrototypeMeshRole::Floor ? -20.0f : 0.0f;
    const float ExpectedMaxZ = Role == EJMPrototypeMeshRole::Wall ? 500.0f : (Role == EJMPrototypeMeshRole::Floor ? 0.0f : 20.0f);
    if (!FMath::IsNearlyEqual(Bounds.Min.Z, ExpectedMinZ, PivotTolerance)
        || !FMath::IsNearlyEqual(Bounds.Max.Z, ExpectedMaxZ, PivotTolerance))
    {
        Result.AddError(FText::Format(
            LOCTEXT("BadPivot", "Mesh Z bounds [{0}, {1}] do not match expected [{2}, {3}] within {4} cm."),
            FText::AsNumber(Bounds.Min.Z), FText::AsNumber(Bounds.Max.Z),
            FText::AsNumber(ExpectedMinZ), FText::AsNumber(ExpectedMaxZ), FText::AsNumber(PivotTolerance)));
    }
    return Result;
}

#undef LOCTEXT_NAMESPACE
