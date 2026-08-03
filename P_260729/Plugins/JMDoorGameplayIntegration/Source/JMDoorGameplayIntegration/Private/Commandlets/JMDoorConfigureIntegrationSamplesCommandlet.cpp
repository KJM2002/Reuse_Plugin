#include "Commandlets/JMDoorConfigureIntegrationSamplesCommandlet.h"

#include "Door/JMDoorTags.h"
#include "Data/JMDoorConfigData.h"
#include "Items/InventoryItemDefinition.h"
#include "Items/InventoryUseOnActorComponentsEffect.h"
#include "Misc/PackageName.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"

UJMDoorConfigureIntegrationSamplesCommandlet::UJMDoorConfigureIntegrationSamplesCommandlet()
{
    IsClient = false;
    IsEditor = true;
    LogToConsole = true;
    ShowErrorCount = true;
}

int32 UJMDoorConfigureIntegrationSamplesCommandlet::Main(const FString& Params)
{
    constexpr TCHAR OldKeyPath[] = TEXT("/InventorySystem/Example/DA_Inventory_OldKey.DA_Inventory_OldKey");
    UInventoryItemDefinition* OldKey = LoadObject<UInventoryItemDefinition>(nullptr, OldKeyPath);
    if (!OldKey)
    {
        UE_LOG(LogTemp, Error, TEXT("Could not load %s"), OldKeyPath);
        return 1;
    }

    OldKey->ItemId = TEXT("OldKey");
    OldKey->bCanUse = true;
    OldKey->UseButtonText = NSLOCTEXT("JMDoorIntegration", "UseOldKey", "Use key");
    OldKey->CannotUseReason = NSLOCTEXT("JMDoorIntegration", "NoPendingDoor", "Interact with a locked door first.");
    OldKey->ItemTags.AddTag(TAG_JMDoor_Demo_Key);
    // No per-item effect is needed. InventorySystem routes any Can Use item to
    // compatible receiver components by default.
    OldKey->UseEffect = nullptr;
    OldKey->bConsumeOnUse = false;
    OldKey->ConsumeQuantity = 1;

    UPackage* Package = OldKey->GetOutermost();
    Package->MarkPackageDirty();
    const FString Filename = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());
    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
    SaveArgs.SaveFlags = SAVE_NoError;
    const bool bOldKeySaved = UPackage::SavePackage(Package, OldKey, *Filename, SaveArgs);

    UJMDoorConfigData* LockedConfig = LoadObject<UJMDoorConfigData>(nullptr, TEXT("/JMDoor/Demo/Data/DA_JMDoorDemoLockedConfig.DA_JMDoorDemoLockedConfig"));
    bool bConfigSaved = false;
    if (LockedConfig)
    {
        LockedConfig->AccessRequirement.RequiredTags.Reset();
        LockedConfig->AcceptedAccessObjects.Reset();
        LockedConfig->AcceptedAccessObjects.Add(TSoftObjectPtr<UObject>(OldKey));
        UPackage* ConfigPackage = LockedConfig->GetOutermost();
        ConfigPackage->MarkPackageDirty();
        const FString ConfigFilename = FPackageName::LongPackageNameToFilename(ConfigPackage->GetName(), FPackageName::GetAssetPackageExtension());
        bConfigSaved = UPackage::SavePackage(ConfigPackage, LockedConfig, *ConfigFilename, SaveArgs);
    }

    const bool bSaved = bOldKeySaved && bConfigSaved;
    UE_LOG(LogTemp, Display, TEXT("JMDoor direct Old Key integration sample configuration %s."), bSaved ? TEXT("succeeded") : TEXT("failed"));
    return bSaved ? 0 : 1;
}
