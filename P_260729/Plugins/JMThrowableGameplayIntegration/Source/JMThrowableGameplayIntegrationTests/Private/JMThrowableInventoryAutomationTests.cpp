#include "Misc/AutomationTest.h"
#include "Components/InventoryComponent.h"
#include "Items/InventoryItemDefinition.h"
#include "JMThrowableDefinition.h"
#include "JMThrowableProjectile.h"
#include "JMThrowableInteractorComponent.h"
#include "JMThrowableGameplayIntegrationComponent.h"
#include "JMThrowableInventoryUseEffect.h"

#if WITH_DEV_AUTOMATION_TESTS
namespace JMThrowableIntegrationTests
{
    struct FFixture
    {
        AActor* Actor = nullptr;
        UInventoryComponent* Inventory = nullptr;
        UJMThrowableInteractorComponent* Interactor = nullptr;
        UInventoryItemDefinition* Item = nullptr;

        FFixture()
        {
            Actor = NewObject<AActor>();
            Inventory = NewObject<UInventoryComponent>(Actor);
            Interactor = NewObject<UJMThrowableInteractorComponent>(Actor);
            UJMThrowableGameplayIntegrationComponent* Integration =
                NewObject<UJMThrowableGameplayIntegrationComponent>(Actor);
            Actor->AddInstanceComponent(Inventory);
            Actor->AddInstanceComponent(Interactor);
            Actor->AddInstanceComponent(Integration);

            UJMThrowableDefinition* ThrowDefinition = NewObject<UJMThrowableDefinition>();
            ThrowDefinition->ProjectileClass = AJMThrowableProjectile::StaticClass();
            Item = NewObject<UInventoryItemDefinition>();
            Item->bCanUse = true;
            Item->bStackable = true;
            Item->MaxStackSize = 10;
            Item->bConsumeOnUse = false;
            UJMThrowableInventoryUseEffect* Effect = NewObject<UJMThrowableInventoryUseEffect>(Item);
            Effect->ThrowableDefinition = ThrowDefinition;
            Item->UseEffect = Effect;
            Inventory->AddItem(Item, 5);
        }
    };
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableInventoryStartsReady,
    "JM.Throwable.Use.InventoryUseStartsAiming",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableInventoryStartsReady::RunTest(const FString&)
{
    JMThrowableIntegrationTests::FFixture F;
    TestEqual(TEXT("Use succeeds"), F.Inventory->UseItemAtSlot(0, F.Actor), EInventoryOperationResult::Success);
    TestEqual(TEXT("Session enters Aiming"), F.Interactor->GetUseState(), EJMThrowableUseState::Aiming);
    TestEqual(TEXT("Use start consumes zero"), F.Inventory->GetItemQuantity(F.Item), 5);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FJMThrowableCancelDoesNotConsume,
    "JM.Throwable.Use.CancelDoesNotConsume",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FJMThrowableCancelDoesNotConsume::RunTest(const FString&)
{
    JMThrowableIntegrationTests::FFixture F;
    F.Inventory->UseItemAtSlot(0, F.Actor);
    F.Interactor->CancelItemUse();
    TestEqual(TEXT("Cancel returns Idle"), F.Interactor->GetUseState(), EJMThrowableUseState::Idle);
    TestEqual(TEXT("Cancel consumes zero"), F.Inventory->GetItemQuantity(F.Item), 5);
    return true;
}
#endif
