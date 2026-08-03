#pragma once

#include "Modules/ModuleManager.h"

class FJMDoorRuntimeModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
