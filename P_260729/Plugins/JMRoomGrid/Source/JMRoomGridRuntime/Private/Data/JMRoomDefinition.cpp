#include "Data/JMRoomDefinition.h"

FPrimaryAssetId UJMRoomDefinition::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(TEXT("JMRoomDefinition"), RoomId.IsNone() ? GetFName() : RoomId);
}
