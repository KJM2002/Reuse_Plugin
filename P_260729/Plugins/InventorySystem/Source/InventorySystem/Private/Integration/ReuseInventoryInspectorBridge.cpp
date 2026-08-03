#include "Integration/ReuseInventoryInspectorBridge.h"

#include "Core/ItemInspectorSettings.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "ItemInspection/JMItemInspectionData.h"
#include "ItemInspection/JMItemInspectionSubsystem.h"
#include "Items/InventoryItemDefinition.h"

bool UReuseInventoryInspectorBridge::OpenInspector_Implementation(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition)
{
	if (!IsValid(PlayerController) || !IsValid(ItemDefinition) || ItemDefinition->InspectorData.IsNull())
	{
		return false;
	}

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	UJMItemInspectionSubsystem* Subsystem = LocalPlayer ? LocalPlayer->GetSubsystem<UJMItemInspectionSubsystem>() : nullptr;
	UJMItemInspectionData* InspectionData = Cast<UJMItemInspectionData>(ItemDefinition->InspectorData.LoadSynchronous());
	if (!Subsystem || !InspectionData)
	{
		return false;
	}

	FJMItemInspectionRequest Request;
	Request.InspectionData = InspectionData;
	Request.RequestSource = this;
	Request.bUseSimpleUITransition = true;
	if (const UItemInspectorSettings* Settings = UItemInspectorSettings::Get())
	{
		Request.bPauseGame = Settings->bDefaultPauseGame;
		Request.bBlockPlayerInput = Settings->bDefaultBlockPlayerInput;
	}

	Subsystem->OnInspectionClosed.AddUniqueDynamic(this, &UReuseInventoryInspectorBridge::HandleInspectionClosed);
	if (!Subsystem->OpenInspectionFromRequest(Request))
	{
		Subsystem->OnInspectionClosed.RemoveDynamic(this, &UReuseInventoryInspectorBridge::HandleInspectionClosed);
		return false;
	}

	ActiveSubsystem = Subsystem;
	return true;
}

void UReuseInventoryInspectorBridge::CloseInspector_Implementation()
{
	if (UJMItemInspectionSubsystem* Subsystem = ActiveSubsystem.Get())
	{
		Subsystem->CloseInspection(EJMItemInspectionCloseReason::ExternalRequest);
	}
}

bool UReuseInventoryInspectorBridge::IsInspectorOpen_Implementation() const
{
	const UJMItemInspectionSubsystem* Subsystem = ActiveSubsystem.Get();
	return Subsystem && Subsystem->IsInspectionOpen();
}

void UReuseInventoryInspectorBridge::HandleInspectionClosed(EJMItemInspectionCloseReason Reason)
{
	if (UJMItemInspectionSubsystem* Subsystem = ActiveSubsystem.Get())
	{
		Subsystem->OnInspectionClosed.RemoveDynamic(this, &UReuseInventoryInspectorBridge::HandleInspectionClosed);
	}
	ActiveSubsystem.Reset();
	NotifyInspectorClosed();
}
