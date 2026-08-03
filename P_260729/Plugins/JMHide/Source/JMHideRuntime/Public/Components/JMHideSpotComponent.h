#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Types/JMHideTypes.h"
#include "JMHideSpotComponent.generated.h"

class UJMHideAnchorComponent;
class UJMHideDefinition;
class UJMHideMechanismComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FJMHideSpotStateChangedSignature, EJMHideSpotState, OldState, EJMHideSpotState, NewState);

UCLASS(ClassGroup=(JMHide), meta=(BlueprintSpawnableComponent), BlueprintType)
class JMHIDERUNTIME_API UJMHideSpotComponent final : public UActorComponent
{
    GENERATED_BODY()

public:
    UJMHideSpotComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    bool bEnabled = true;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JM Hide")
    TObjectPtr<UJMHideDefinition> Definition = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    EJMHideSpotArchetype Archetype = EJMHideSpotArchetype::OpenSpace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide", meta=(Categories="Hide.Type"))
    FGameplayTag HideType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JM Hide")
    FJMHideConfigOverride InstanceConfigOverride;

    UPROPERTY(BlueprintAssignable, Category="JM Hide")
    FJMHideSpotStateChangedSignature OnSpotStateChanged;

    UFUNCTION(BlueprintPure, Category="JM Hide")
    EJMHideSpotState GetSpotState() const;

    UFUNCTION(BlueprintPure, Category="JM Hide")
    bool IsAvailable() const { return GetSpotState() == EJMHideSpotState::Available; }

    FJMHideResult TryReserve(const FGuid& SessionId, AActor* ReservationOwner);
    FJMHideResult CommitOccupied(const FGuid& SessionId, AActor* Occupant);
    void Release(const FGuid& SessionId);
    bool IsOwnedBy(const FGuid& SessionId) const;

    UJMHideAnchorComponent* FindAnchor(EJMHideAnchorRole Role) const;
    void GetAlternativeExitAnchors(TArray<UJMHideAnchorComponent*>& OutAnchors) const;
    UJMHideMechanismComponent* FindMechanism() const;
    FJMResolvedHideConfig ResolveConfig(const FJMHideRequest& Request) const;
    EJMHideSpotArchetype GetEffectiveArchetype() const;

    UFUNCTION(BlueprintCallable, Category="JM Hide|Validation")
    bool ValidateConfiguration(TArray<FText>& OutErrors) const;

#if WITH_EDITOR
    virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif

private:
    void BroadcastStateIfChanged(EJMHideSpotState OldState);

    FGuid CurrentSessionId;
    TWeakObjectPtr<AActor> ReservationOwner;
    TWeakObjectPtr<AActor> CurrentOccupant;
};
