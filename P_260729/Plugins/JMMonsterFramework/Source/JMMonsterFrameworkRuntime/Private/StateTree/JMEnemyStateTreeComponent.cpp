#include "StateTree/JMEnemyStateTreeComponent.h"

#include "AIController.h"
#include "Core/JMEnemyBase.h"
#include "Engine/World.h"
#include "StateTreeExecutionContext.h"
#include "StateTreeTypes.h"
#include "Subsystems/WorldSubsystem.h"

UJMEnemyStateTreeComponent::UJMEnemyStateTreeComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    SetStartLogicAutomatically(false);
}

bool UJMEnemyStateTreeComponent::StartFrameworkTree(UStateTree* StateTree)
{
    if (IsRunning())
    {
        StopLogic(TEXT("Replacing framework StateTree"));
    }
    SetStateTree(StateTree);
    if (!StateTree)
    {
        return false;
    }
    StartLogic();
    return IsRunning();
}

void UJMEnemyStateTreeComponent::StopFrameworkTree(const FString& Reason)
{
    if (IsRunning())
    {
        StopLogic(Reason);
    }
}

void UJMEnemyStateTreeComponent::ValidateStateTreeReference()
{
    // The definition reference is intentionally assigned after possession.
}

bool UJMEnemyStateTreeComponent::CollectExternalData(const FStateTreeExecutionContext& Context,
    const UStateTree* StateTree, const TArrayView<const FStateTreeExternalDataDesc> Descs,
    const TArrayView<FStateTreeDataView> OutDataViews) const
{
    if (Descs.Num() != OutDataViews.Num())
    {
        return false;
    }

    AAIController* Controller = Cast<AAIController>(Context.GetOwner());
    AJMEnemyBase* Enemy = Controller ? Cast<AJMEnemyBase>(Controller->GetPawn()) : nullptr;
    UWorld* World = Context.GetWorld();
    if (!Controller || !Enemy || !World)
    {
        return false;
    }

    bool bComplete = true;
    for (int32 Index = 0; Index < Descs.Num(); ++Index)
    {
        const UStruct* Struct = Descs[Index].Struct.Get();
        UObject* Value = nullptr;
        if (!Struct)
        {
            continue;
        }
        if (Struct->IsChildOf(UWorldSubsystem::StaticClass()))
        {
            Value = World->GetSubsystemBase(Cast<UClass>(const_cast<UStruct*>(Struct)));
        }
        else if (Struct->IsChildOf(UActorComponent::StaticClass()))
        {
            Value = Enemy->FindComponentByClass(Cast<UClass>(const_cast<UStruct*>(Struct)));
        }
        else if (Struct->IsChildOf(AAIController::StaticClass()))
        {
            Value = Controller;
        }
        else if (Struct->IsChildOf(APawn::StaticClass()) || Struct->IsChildOf(AActor::StaticClass()))
        {
            Value = Enemy;
        }
        OutDataViews[Index] = FStateTreeDataView(Value);
        if (!Value && Descs[Index].Requirement == EStateTreeExternalDataRequirement::Required)
        {
            bComplete = false;
        }
    }
    return bComplete;
}
