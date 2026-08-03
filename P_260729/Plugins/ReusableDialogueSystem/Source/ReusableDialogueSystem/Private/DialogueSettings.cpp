#include "DialogueSettings.h"

UDialogueSettings::UDialogueSettings()
{
    CategoryName = TEXT("JM Plugins");
    SectionName = TEXT("Dialogue");
    DefaultDialogueWidgetClass = TSoftClassPtr<UDialogueWidgetBase>(FSoftObjectPath(TEXT("/ReusableDialogueSystem/UI/WBP_Dialogue.WBP_Dialogue_C")));
}
