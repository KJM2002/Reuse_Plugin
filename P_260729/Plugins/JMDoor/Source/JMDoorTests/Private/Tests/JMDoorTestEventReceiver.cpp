#include "Tests/JMDoorTestEventReceiver.h"

void UJMDoorTestEventReceiver::HandleNoise(FJMDoorNoiseEvent NoiseEvent)
{
    ++NoiseCount;
    LastNoiseTag = NoiseEvent.NoiseTag;
}
