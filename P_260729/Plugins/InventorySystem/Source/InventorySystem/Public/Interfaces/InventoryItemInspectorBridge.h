#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryItemInspectorBridge.generated.h"

class UInventoryItemDefinition;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryInspectorClosedSignature);

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UInventoryItemInspectorBridge : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Inventory|Inspector")
	FInventoryInspectorClosedSignature OnInspectorClosed;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory|Inspector")
	bool OpenInspector(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition);
	virtual bool OpenInspector_Implementation(APlayerController* PlayerController, const UInventoryItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory|Inspector")
	void CloseInspector();
	virtual void CloseInspector_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Inventory|Inspector")
	bool IsInspectorOpen() const;
	virtual bool IsInspectorOpen_Implementation() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Inspector")
	void NotifyInspectorClosed();
};
