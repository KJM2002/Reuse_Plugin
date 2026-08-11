#include "Types/JMHarpoonCableLengthModel.h"

void FJMHarpoonCableLengthModel::Reset(float RestingLength)
{
    CurrentLength = FMath::Max(1.0f, RestingLength);
    bInitialized = false;
}

void FJMHarpoonCableLengthModel::Initialize(float InitialLength)
{
    CurrentLength = FMath::Max(1.0f, InitialLength);
    bInitialized = true;
}

float FJMHarpoonCableLengthModel::Update(
    float EndpointDistance,
    float DeltaTime,
    bool bRetracting,
    float MinimumCableLength,
    float SlackMultiplier,
    float MinimumSlack,
    float MaximumSlack,
    float LengthDeadZone,
    float ReelInterpSpeed)
{
    const float SafeDistance = FMath::Max(0.0f, EndpointDistance);
    const float SafeMinimumSlack = FMath::Max(0.0f, MinimumSlack);
    const float SafeMaximumSlack = FMath::Max(MaximumSlack, SafeMinimumSlack);
    const float PercentageSlack = SafeDistance * FMath::Max(0.0f, SlackMultiplier - 1.0f);
    const float Slack = FMath::Clamp(PercentageSlack, SafeMinimumSlack, SafeMaximumSlack);
    const float GeometricMinimum = FMath::Max(
        FMath::Max(1.0f, MinimumCableLength),
        SafeDistance + Slack);
    const float SafeDeadZone = FMath::Max(0.0f, LengthDeadZone);

    if (!bInitialized)
    {
        Initialize(GeometricMinimum);
    }
    else if (GeometricMinimum > CurrentLength + SafeDeadZone)
    {
        CurrentLength = GeometricMinimum;
    }
    else if (bRetracting && GeometricMinimum < CurrentLength - SafeDeadZone)
    {
        CurrentLength = FMath::Max(
            GeometricMinimum,
            FMath::FInterpTo(
                CurrentLength,
                GeometricMinimum,
                FMath::Max(0.0f, DeltaTime),
                FMath::Max(0.1f, ReelInterpSpeed)));
    }

    return CurrentLength;
}
