#include "JMRoomGridBuildLibraryCommandlet.h"

#include "JMRoomGridEditorTools.h"

UJMRoomGridBuildLibraryCommandlet::UJMRoomGridBuildLibraryCommandlet()
{
    IsClient = false;
    IsEditor = true;
    IsServer = false;
    LogToConsole = true;
    ShowErrorCount = true;
}

int32 UJMRoomGridBuildLibraryCommandlet::Main(const FString& Params)
{
    return JMRoomGridEditor::CreateThirteenByThirteenRoomAssets(false) ? 0 : 1;
}
