#pragma once

#include "CoreMinimal.h"

/** Pure, testable visual winch model. It feeds out as needed and only reels in during recall. */
struct JMPHYSICALGRABBER_API FJMHarpoonCableLengthModel
{
    float CurrentLength = 10.0f;
    bool bInitialized = false;

    void Reset(float RestingLength = 10.0f);
    void Initialize(float InitialLength);

    float Update(
        float EndpointDistance,
        float DeltaTime,
        bool bRetracting,
        float MinimumCableLength,
        float SlackMultiplier,
        float MinimumSlack,
        float MaximumSlack,
        float LengthDeadZone,
        float ReelInterpSpeed);
};
