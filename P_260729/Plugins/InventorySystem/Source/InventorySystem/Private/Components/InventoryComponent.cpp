#include "Components/InventoryComponent.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "InventoryEventTags.h"
#include "InventoryLog.h"
#include "Items/InventoryItemDefinition.h"
#include "Items/InventoryItemUseEffect.h"
#include "Items/InventoryUseOnActorComponentsEffect.h"
#include "Payloads/InventoryItemEventPayload.h"
#include "Settings/InventorySystemSettings.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "World/InventoryWorldItemPickup.h"

namespace
{
	void PublishInventoryEvent(UInventoryComponent* Inventory, FGameplayTag EventTag, UInventoryItemDefinition* ItemDefinition, int32 Quantity, int32 SlotIndex, AActor* Instigator = nullptr)
	{
		UGameInstance* GameInstance = Inventory && Inventory->GetWorld() ? Inventory->GetWorld()->GetGameInstance() : nullptr;
		UJMGameplayEventSubsystem* EventSubsystem = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
		if (!EventSubsystem || !IsValid(ItemDefinition)) return;
		UInventoryItemEventPayload* Payload = NewObject<UInventoryItemEventPayload>(Inventory);
		Payload->ItemDefinition = ItemDefinition;
		Payload->Quantity = Quantity;
		Payload->ObjectiveTargetIdentifier = ItemDefinition->ItemId;
		Payload->ObjectiveProgressAmount = FMath::Max(0, Quantity);
		Payload->ObjectiveContextTags = ItemDefinition->ItemTags;
		Payload->TotalQuantityAfter = Inventory->GetItemQuantity(ItemDefinition);
		Payload->InventoryOwner = Inventory->GetOwner();
		Payload->SlotIndex = SlotIndex;
		FJMGameplayEventMessage Message;
		Message.EventTag = EventTag;
		Message.Source = Inventory;
		Message.Instigator = IsValid(Instigator) ? Instigator : Inventory->GetOwner();
		Message.Target = Inventory->GetOwner();
		Message.Payload = Payload;
		EventSubsystem->PublishEvent(Message);
	}
}

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>())
	{
		MaxInventorySlots = FMath::Max(1, Settings->DefaultMaxInventorySlots);
	}
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	EnsureSlotCapacity();
}

void UInventoryComponent::EnsureSlotCapacity()
{
	MaxInventorySlots = FMath::Max(1, MaxInventorySlots);
	if (Slots.Num() < MaxInventorySlots)
	{
		Slots.SetNum(MaxInventorySlots);
	}
}

bool UInventoryComponent::IsValidSlotIndex(int32 SlotIndex) const
{
	return Slots.IsValidIndex(SlotIndex) && Slots[SlotIndex].IsValid();
}

FInventoryAddOutcome UInventoryComponent::AddItemDetailed(UInventoryItemDefinition* ItemDefinition, int32 Quantity)
{
	FInventoryAddOutcome Outcome;
	Outcome.RequestedQuantity = Quantity;
	Outcome.RemainingQuantity = FMath::Max(0, Quantity);

	if (!IsValid(ItemDefinition))
	{
		Outcome.Result = EInventoryAddResult::InvalidItem;
		UE_LOG(LogInventorySystem, Warning, TEXT("AddItem rejected a null item definition on %s."), *GetNameSafe(GetOwner()));
		return Outcome;
	}

	if (Quantity <= 0)
	{
		Outcome.Result = EInventoryAddResult::InvalidQuantity;
		return Outcome;
	}

	EnsureSlotCapacity();
	int32 Remaining = Quantity;
	const int32 StackLimit = ItemDefinition->GetEffectiveMaxStackSize();

	if (ItemDefinition->bStackable)
	{
		for (int32 SlotIndex = 0; SlotIndex < Slots.Num() && Remaining > 0; ++SlotIndex)
		{
			FInventorySlot& Slot = Slots[SlotIndex];
			if (Slot.ItemDefinition != ItemDefinition || Slot.Quantity >= StackLimit)
			{
				continue;
			}

			const int32 Added = FMath::Min(Remaining, StackLimit - Slot.Quantity);
			Slot.Quantity += Added;
			Remaining -= Added;
			OnItemAdded.Broadcast(ItemDefinition, Added, SlotIndex);
		}
	}

	for (int32 SlotIndex = 0; SlotIndex < Slots.Num() && Remaining > 0; ++SlotIndex)
	{
		FInventorySlot& Slot = Slots[SlotIndex];
		if (Slot.IsValid())
		{
			continue;
		}

		const int32 Added = FMath::Min(Remaining, StackLimit);
		Slot.ItemDefinition = ItemDefinition;
		Slot.Quantity = Added;
		Slot.InstanceId = FGuid::NewGuid();
		Remaining -= Added;
		OnItemAdded.Broadcast(ItemDefinition, Added, SlotIndex);
	}

	Outcome.AddedQuantity = Quantity - Remaining;
	Outcome.RemainingQuantity = Remaining;
	if (Outcome.AddedQuantity == Quantity)
	{
		Outcome.Result = EInventoryAddResult::Success;
	}
	else if (Outcome.AddedQuantity > 0)
	{
		Outcome.Result = EInventoryAddResult::PartialSuccess;
	}
	else
	{
		Outcome.Result = EInventoryAddResult::InventoryFull;
	}

	if (Outcome.AddedQuantity > 0)
	{
		UE_LOG(
			LogInventorySystem,
			Log,
			TEXT("Inventory received item: owner=%s, item=%s, quantity=%d"),
			*GetNameSafe(GetOwner()),
			*GetNameSafe(ItemDefinition),
			Outcome.AddedQuantity);
		OnInventoryChanged.Broadcast();
		OnItemsReceived.Broadcast(ItemDefinition, Outcome.AddedQuantity);
		PublishInventoryEvent(this, JMInventoryEventTags::Acquired, ItemDefinition, Outcome.AddedQuantity, INDEX_NONE);
	}
	if (Remaining > 0)
	{
		OnInventoryFull.Broadcast(ItemDefinition, Remaining);
	}

	return Outcome;
}

bool UInventoryComponent::AddItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity)
{
	return AddItemDetailed(ItemDefinition, Quantity).AddedQuantity == Quantity;
}

bool UInventoryComponent::RemoveItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity)
{
	if (!IsValid(ItemDefinition) || Quantity <= 0 || GetItemQuantity(ItemDefinition) < Quantity)
	{
		return false;
	}

	int32 Remaining = Quantity;
	for (int32 SlotIndex = Slots.Num() - 1; SlotIndex >= 0 && Remaining > 0; --SlotIndex)
	{
		if (Slots[SlotIndex].ItemDefinition != ItemDefinition)
		{
			continue;
		}

		const int32 Removed = FMath::Min(Remaining, Slots[SlotIndex].Quantity);
		RemoveItemAtSlot(SlotIndex, Removed);
		Remaining -= Removed;
	}
	return Remaining == 0;
}

EInventoryOperationResult UInventoryComponent::RemoveItemAtSlot(int32 SlotIndex, int32 Quantity)
{
	if (!IsValidSlotIndex(SlotIndex))
	{
		return EInventoryOperationResult::InvalidSlot;
	}
	if (Quantity <= 0 || Quantity > Slots[SlotIndex].Quantity)
	{
		return EInventoryOperationResult::InvalidQuantity;
	}

	FInventorySlot& Slot = Slots[SlotIndex];
	UInventoryItemDefinition* ItemDefinition = Slot.ItemDefinition;
	Slot.Quantity -= Quantity;
	if (Slot.Quantity <= 0)
	{
		Slot = FInventorySlot();
	}

	OnItemRemoved.Broadcast(ItemDefinition, Quantity, SlotIndex);
	OnInventoryChanged.Broadcast();
	PublishInventoryEvent(this, JMInventoryEventTags::Removed, ItemDefinition, Quantity, SlotIndex);
	return EInventoryOperationResult::Success;
}

EInventoryOperationResult UInventoryComponent::UseItemAtSlot(int32 SlotIndex, AActor* User)
{
    if (!IsValidSlotIndex(SlotIndex))
    {
        UE_LOG(LogInventorySystem, Warning, TEXT("UseItemAtSlot failed: invalid slot %d on %s."), SlotIndex, *GetNameSafe(GetOwner()));
        return EInventoryOperationResult::InvalidSlot;
	}

	const FInventorySlot SlotSnapshot = Slots[SlotIndex];
	UInventoryItemDefinition* ItemDefinition = SlotSnapshot.ItemDefinition;
    if (!ItemDefinition->bCanUse)
    {
        UE_LOG(LogInventorySystem, Warning, TEXT("UseItemAtSlot failed: item %s is not marked Can Use."), *GetNameSafe(ItemDefinition));
        return EInventoryOperationResult::NotAllowed;
    }

    AActor* EffectiveUser = IsValid(User) ? User : GetOwner();
    UInventoryItemUseEffect* EffectiveUseEffect = ItemDefinition->UseEffect;
    if (!EffectiveUseEffect)
    {
        // Blueprint-friendly default: any Can Use item is routed to a compatible
        // component on the user. Explicit effects remain available for special items.
        EffectiveUseEffect = GetMutableDefault<UInventoryUseOnActorComponentsEffect>();
    }
    if (!EffectiveUseEffect->CanUse(EffectiveUser, SlotSnapshot))
    {
        UE_LOG(LogInventorySystem, Warning, TEXT("UseItemAtSlot failed: no receiver accepted item %s for user %s."), *GetNameSafe(ItemDefinition), *GetNameSafe(EffectiveUser));
        return EInventoryOperationResult::CannotUse;
	}
    if (!EffectiveUseEffect->ExecuteUse(EffectiveUser, this, SlotSnapshot))
    {
        UE_LOG(LogInventorySystem, Warning, TEXT("UseItemAtSlot failed: effect execution failed for item %s and user %s."), *GetNameSafe(ItemDefinition), *GetNameSafe(EffectiveUser));
        return EInventoryOperationResult::EffectFailed;
	}

    OnItemUsed.Broadcast(ItemDefinition, SlotIndex);
    UE_LOG(LogInventorySystem, Log, TEXT("UseItemAtSlot succeeded: item=%s, user=%s, slot=%d."), *GetNameSafe(ItemDefinition), *GetNameSafe(EffectiveUser), SlotIndex);
	if (ItemDefinition->bConsumeOnUse)
	{
		const int32 ConsumeQuantity = FMath::Max(1, ItemDefinition->ConsumeQuantity);
		if (!IsValidSlotIndex(SlotIndex) || Slots[SlotIndex].Quantity < ConsumeQuantity)
		{
			UE_LOG(LogInventorySystem, Warning, TEXT("Use effect succeeded but consumable quantity changed before consumption for %s."), *GetNameSafe(ItemDefinition));
			return EInventoryOperationResult::Success;
		}
		RemoveItemAtSlot(SlotIndex, ConsumeQuantity);
	}
	else
	{
		OnInventoryChanged.Broadcast();
	}
	PublishInventoryEvent(this, JMInventoryEventTags::Used, ItemDefinition, 1, SlotIndex, EffectiveUser);

	return EInventoryOperationResult::Success;
}

EInventoryOperationResult UInventoryComponent::DropItemAtSlot(int32 SlotIndex, int32 Quantity, AActor* Dropper)
{
	if (!IsValidSlotIndex(SlotIndex))
	{
		return EInventoryOperationResult::InvalidSlot;
	}
	if (Quantity <= 0 || Quantity > Slots[SlotIndex].Quantity)
	{
		return EInventoryOperationResult::InvalidQuantity;
	}

	UInventoryItemDefinition* ItemDefinition = Slots[SlotIndex].ItemDefinition;
	if (!ItemDefinition->bCanDrop)
	{
		return EInventoryOperationResult::NotAllowed;
	}

	UWorld* World = GetWorld();
	if (!World || World->bIsTearingDown)
	{
		return EInventoryOperationResult::SpawnFailed;
	}

	TSubclassOf<AInventoryWorldItemPickup> PickupClass = AInventoryWorldItemPickup::StaticClass();
	if (!ItemDefinition->WorldItemClass.IsNull())
	{
		PickupClass = ItemDefinition->WorldItemClass.LoadSynchronous();
	}
	else if (const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>(); Settings && !Settings->DefaultWorldItemClass.IsNull())
	{
		PickupClass = Settings->DefaultWorldItemClass.LoadSynchronous();
	}
	if (!PickupClass)
	{
		return EInventoryOperationResult::SpawnFailed;
	}

	AActor* EffectiveDropper = IsValid(Dropper) ? Dropper : GetOwner();
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = EffectiveDropper;
	// 충돌 회피가 Pickup을 공중으로 밀어 올리지 않게 하고, 초기화 후 Mesh Bounds로 바닥에 스냅한다.
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AInventoryWorldItemPickup* Pickup = World->SpawnActor<AInventoryWorldItemPickup>(PickupClass, FindDropLocation(EffectiveDropper), FRotator::ZeroRotator, SpawnParameters);
	if (!IsValid(Pickup))
	{
		UE_LOG(LogInventorySystem, Warning, TEXT("Failed to spawn a world pickup for %s."), *GetNameSafe(ItemDefinition));
		return EInventoryOperationResult::SpawnFailed;
	}

	Pickup->InitializePickup(ItemDefinition, Quantity);
	const EInventoryOperationResult RemoveResult = RemoveItemAtSlot(SlotIndex, Quantity);
	if (RemoveResult != EInventoryOperationResult::Success)
	{
		Pickup->Destroy();
		return RemoveResult;
	}

	OnItemDropped.Broadcast(ItemDefinition, Quantity, SlotIndex);
	PublishInventoryEvent(this, JMInventoryEventTags::Dropped, ItemDefinition, Quantity, SlotIndex, EffectiveDropper);
	return EInventoryOperationResult::Success;
}

bool UInventoryComponent::HasItem(UInventoryItemDefinition* ItemDefinition, int32 Quantity) const
{
	return IsValid(ItemDefinition) && Quantity > 0 && GetItemQuantity(ItemDefinition) >= Quantity;
}

int32 UInventoryComponent::GetItemQuantity(UInventoryItemDefinition* ItemDefinition) const
{
	if (!IsValid(ItemDefinition))
	{
		return 0;
	}

	int32 Total = 0;
	for (const FInventorySlot& Slot : Slots)
	{
		if (Slot.ItemDefinition == ItemDefinition)
		{
			Total += Slot.Quantity;
		}
	}
	return Total;
}

bool UInventoryComponent::GetSlot(int32 SlotIndex, FInventorySlot& OutSlot) const
{
	if (!Slots.IsValidIndex(SlotIndex))
	{
		OutSlot = FInventorySlot();
		return false;
	}
	OutSlot = Slots[SlotIndex];
	return OutSlot.IsValid();
}

int32 UInventoryComponent::GetOccupiedSlotCount() const
{
	int32 Count = 0;
	for (const FInventorySlot& Slot : Slots)
	{
		Count += Slot.IsValid() ? 1 : 0;
	}
	return Count;
}

TArray<FInventorySaveEntry> UInventoryComponent::MakeSaveEntries() const
{
	TArray<FInventorySaveEntry> Entries;
	for (const FInventorySlot& Slot : Slots)
	{
		if (!Slot.IsValid() || Slot.ItemDefinition->ItemId.IsNone())
		{
			continue;
		}
		FInventorySaveEntry& Entry = Entries.AddDefaulted_GetRef();
		Entry.ItemId = Slot.ItemDefinition->ItemId;
		Entry.Quantity = Slot.Quantity;
		Entry.InstanceId = Slot.InstanceId;
	}
	return Entries;
}

FVector UInventoryComponent::FindDropLocation(AActor* Dropper) const
{
	if (!IsValid(Dropper))
	{
		return FVector::ZeroVector;
	}

	const UInventorySystemSettings* Settings = GetDefault<UInventorySystemSettings>();
	const float ForwardDistance = Settings ? Settings->DefaultDropForwardDistance : 125.0f;
	const float TraceHeight = Settings ? Settings->DefaultDropTraceHeight : 100.0f;
	const float TraceDepth = Settings ? Settings->DefaultDropTraceDepth : 300.0f;
	const FVector Candidate = Dropper->GetActorLocation() + Dropper->GetActorForwardVector() * ForwardDistance;
	const FVector TraceStart = Candidate + FVector::UpVector * TraceHeight;
	const FVector TraceEnd = Candidate - FVector::UpVector * TraceDepth;

	FHitResult Hit;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(InventoryDropFloor), false, Dropper);
	if (GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, Params))
	{
		return Hit.ImpactPoint;
	}
	return Candidate;
}
