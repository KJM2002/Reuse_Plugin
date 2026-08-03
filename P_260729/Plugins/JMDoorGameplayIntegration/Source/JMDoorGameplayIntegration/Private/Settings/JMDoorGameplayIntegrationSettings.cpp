#include "Settings/JMDoorGameplayIntegrationSettings.h"

UJMDoorGameplayIntegrationSettings::UJMDoorGameplayIntegrationSettings()
{
    CategoryName = TEXT("JM Plugins");
    SectionName = TEXT("Door Gameplay Integration");
    OpenDoorPrompt = NSLOCTEXT("JMDoorIntegration", "OpenDoorPrompt", "E키를 눌러 열기");
    CloseDoorPrompt = NSLOCTEXT("JMDoorIntegration", "CloseDoorPrompt", "E키를 눌러 닫기");
    LockedDoorPrompt = NSLOCTEXT("JMDoorIntegration", "LockedDoorPrompt", "E키를 눌러 잠긴 문 사용");
}
