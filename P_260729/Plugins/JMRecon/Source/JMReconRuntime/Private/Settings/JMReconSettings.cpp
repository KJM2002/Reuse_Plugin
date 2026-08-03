#include "Settings/JMReconSettings.h"

#include "Data/JMReconDefinition.h"

UJMReconSettings::UJMReconSettings()
{
    DefaultReconDefinition = TSoftObjectPtr<UJMReconDefinition>(
        FSoftObjectPath(TEXT("/JMRecon/Data/DA_JMRecon_Default.DA_JMRecon_Default")));
}
