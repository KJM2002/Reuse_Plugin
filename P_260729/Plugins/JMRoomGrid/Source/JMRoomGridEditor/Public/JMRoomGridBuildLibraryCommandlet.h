#pragma once

#include "Commandlets/Commandlet.h"
#include "JMRoomGridBuildLibraryCommandlet.generated.h"

UCLASS()
class JMROOMGRIDEDITOR_API UJMRoomGridBuildLibraryCommandlet final : public UCommandlet
{
    GENERATED_BODY()

public:
    UJMRoomGridBuildLibraryCommandlet();
    virtual int32 Main(const FString& Params) override;
};
