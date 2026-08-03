#pragma once

#include "CoreMinimal.h"
#include "Interfaces/InventoryItemInspectorBridge.h"
#include "ItemInspection/JMItemInspectionTypes.h"
#include "ReuseInventoryInspectorBridge.generated.h"

class UJMItemInspectionSubsystem;

/**
 * Thin host-project adapter between the portable InventorySystem bridge and
 * the existing ItemInspector item inspection subsystem.
 */
UCLASS(BlueprintType, EditInlineNew)
class INVENTORYSYSTEM_API UReuseInventoryInspectorBridge : public UInventoryItemInspectorBridge
{
	GENERATED_BODY()

public:
	virtual bool OpenInspector_Implementation(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition) override;
	virtual void CloseInspector_Implementation() override;
	virtual bool IsInspectorOpen_Implementation() const override;

protected:
	UFUNCTION()
	void HandleInspectionClosed(EJMItemInspectionCloseReason Reason);

	TWeakObjectPtr<UJMItemInspectionSubsystem> ActiveSubsystem;
};
