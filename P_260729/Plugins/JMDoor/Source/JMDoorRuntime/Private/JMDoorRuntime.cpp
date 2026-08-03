#include "JMDoorRuntime.h"

#include "JMDoorLog.h"

IMPLEMENT_MODULE(FJMDoorRuntimeModule, JMDoorRuntime)

void FJMDoorRuntimeModule::StartupModule()
{
    UE_LOG(LogJMDoor, Log, TEXT("JMDoorRuntime started."));
}

void FJMDoorRuntimeModule::ShutdownModule()
{
}
