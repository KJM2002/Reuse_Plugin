#include "Components/JMHideSpotComponent.h"

#include "Components/JMHideAnchorComponent.h"
#include "Components/JMHideMechanismComponent.h"
#include "Data/JMHideDefinition.h"
#include "GameFramework/Actor.h"
#include "Settings/JMHideSettings.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

UJMHideSpotComponent::UJMHideSpotComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

EJMHideSpotState UJMHideSpotComponent::GetSpotState() const
{
    if (!bEnabled)
    {
        return EJMHideSpotState::Disabled;
    }
    if (CurrentOccupant.IsValid())
    {
        return EJMHideSpotState::Occupied;
    }
    if (CurrentSessionId.IsValid())
    {
        return EJMHideSpotState::Reserved;
    }
    return EJMHideSpotState::Available;
}

FJMHideResult UJMHideSpotComponent::TryReserve(const FGuid& SessionId, AActor* InReservationOwner)
{
    const EJMHideSpotState OldState = GetSpotState();
    if (!bEnabled)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::SpotDisabled);
    }
    if (!SessionId.IsValid() || !IsValid(InReservationOwner))
    {
        return FJMHideResult::Failure(EJMHideFailureCode::InvalidParticipant);
    }
    if (CurrentSessionId.IsValid() && CurrentSessionId != SessionId)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::SpotUnavailable);
    }
    CurrentSessionId = SessionId;
    ReservationOwner = InReservationOwner;
    BroadcastStateIfChanged(OldState);
    return FJMHideResult::Success();
}

FJMHideResult UJMHideSpotComponent::CommitOccupied(const FGuid& SessionId, AActor* Occupant)
{
    const EJMHideSpotState OldState = GetSpotState();
    if (CurrentSessionId != SessionId || !IsValid(Occupant) || ReservationOwner.Get() != Occupant)
    {
        return FJMHideResult::Failure(EJMHideFailureCode::SpotUnavailable);
    }
    CurrentOccupant = Occupant;
    BroadcastStateIfChanged(OldState);
    return FJMHideResult::Success();
}

void UJMHideSpotComponent::Release(const FGuid& SessionId)
{
    if (CurrentSessionId != SessionId)
    {
        return;
    }
    const EJMHideSpotState OldState = GetSpotState();
    CurrentSessionId.Invalidate();
    ReservationOwner.Reset();
    CurrentOccupant.Reset();
    BroadcastStateIfChanged(OldState);
}

bool UJMHideSpotComponent::IsOwnedBy(const FGuid& SessionId) const
{
    return SessionId.IsValid() && CurrentSessionId == SessionId;
}

void UJMHideSpotComponent::BroadcastStateIfChanged(EJMHideSpotState OldState)
{
    const EJMHideSpotState NewState = GetSpotState();
    if (NewState != OldState)
    {
        OnSpotStateChanged.Broadcast(OldState, NewState);
    }
}

UJMHideAnchorComponent* UJMHideSpotComponent::FindAnchor(EJMHideAnchorRole Role) const
{
    if (!GetOwner())
    {
        return nullptr;
    }
    TInlineComponentArray<UJMHideAnchorComponent*> Anchors(GetOwner());
    for (UJMHideAnchorComponent* Anchor : Anchors)
    {
        if (IsValid(Anchor) && Anchor->Role == Role)
        {
            return Anchor;
        }
    }
    return nullptr;
}

void UJMHideSpotComponent::GetAlternativeExitAnchors(TArray<UJMHideAnchorComponent*>& OutAnchors) const
{
    OutAnchors.Reset();
    if (!GetOwner())
    {
        return;
    }
    TInlineComponentArray<UJMHideAnchorComponent*> Anchors(GetOwner());
    for (UJMHideAnchorComponent* Anchor : Anchors)
    {
        if (IsValid(Anchor) && Anchor->Role == EJMHideAnchorRole::AlternativeExit)
        {
            OutAnchors.Add(Anchor);
        }
    }
}

UJMHideMechanismComponent* UJMHideSpotComponent::FindMechanism() const
{
    return GetOwner() ? GetOwner()->FindComponentByClass<UJMHideMechanismComponent>() : nullptr;
}

EJMHideSpotArchetype UJMHideSpotComponent::GetEffectiveArchetype() const
{
    return Definition ? Definition->Archetype : Archetype;
}

FJMResolvedHideConfig UJMHideSpotComponent::ResolveConfig(const FJMHideRequest& Request) const
{
    FJMResolvedHideConfig Result;
    static_cast<FJMHideConfigValues&>(Result) = GetDefault<UJMHideSettings>()->Defaults;
    if (Definition && Definition->ConfigOverride.bOverride)
    {
        static_cast<FJMHideConfigValues&>(Result) = Definition->ConfigOverride.Values;
    }
    if (InstanceConfigOverride.bOverride)
    {
        static_cast<FJMHideConfigValues&>(Result) = InstanceConfigOverride.Values;
    }
    if (Request.ConfigOverride.bOverride)
    {
        static_cast<FJMHideConfigValues&>(Result) = Request.ConfigOverride.Values;
    }
    return Result;
}

bool UJMHideSpotComponent::ValidateConfiguration(TArray<FText>& OutErrors) const
{
    bool bValid = true;
    const UJMHideAnchorComponent* Occupant = FindAnchor(EJMHideAnchorRole::Occupant);
    const UJMHideAnchorComponent* Camera = FindAnchor(EJMHideAnchorRole::Camera);
    const UJMHideAnchorComponent* Exit = FindAnchor(EJMHideAnchorRole::PrimaryExit);
    if (!Occupant || !Camera || !Exit)
    {
        OutErrors.Add(NSLOCTEXT("JMHide", "MissingCoreAnchors", "Occupant, Camera and Primary Exit anchors are required."));
        bValid = false;
    }
    if (ResolveConfig(FJMHideRequest()).bUseEntryAnchor && !FindAnchor(EJMHideAnchorRole::Entry))
    {
        OutErrors.Add(NSLOCTEXT("JMHide", "MissingEntryAnchor", "Entry anchor is required by the active policy."));
        bValid = false;
    }

    TInlineComponentArray<UJMHideMechanismComponent*> Mechanisms(GetOwner());
    if (GetEffectiveArchetype() == EJMHideSpotArchetype::Enclosed && Mechanisms.IsEmpty())
    {
        OutErrors.Add(NSLOCTEXT("JMHide", "MissingEnclosedMechanism", "Enclosed spots require a mechanism."));
        bValid = false;
    }
    if (Mechanisms.Num() > 1)
    {
        TSet<USceneComponent*> OwnedComponents;
        for (const UJMHideMechanismComponent* Mechanism : Mechanisms)
        {
            TArray<USceneComponent*> OwnedByMechanism;
            Mechanism->GetOwnedSceneComponents(OwnedByMechanism);
            for (USceneComponent* Component : OwnedByMechanism)
            {
                if (OwnedComponents.Contains(Component))
                {
                    OutErrors.Add(NSLOCTEXT("JMHide", "DuplicateTransformOwner", "A movable component has more than one hide mechanism owner."));
                    bValid = false;
                }
                OwnedComponents.Add(Component);
            }
        }
        OutErrors.Add(NSLOCTEXT("JMHide", "MultipleMechanisms", "A spot should expose one mechanism provider; use one composite provider for multiple parts."));
        bValid = false;
    }

    const auto GetValidationLocation = [](const UJMHideAnchorComponent* Anchor)
    {
        return Anchor->IsRegistered() ? Anchor->GetComponentLocation() : Anchor->GetRelativeLocation();
    };
    if (Occupant && Exit && GetValidationLocation(Occupant).Equals(GetValidationLocation(Exit), 1.0f))
    {
        OutErrors.Add(NSLOCTEXT("JMHide", "ExitEqualsOccupant", "Primary Exit is effectively identical to the Occupant anchor."));
        bValid = false;
    }

    TArray<UJMHideAnchorComponent*> Alternatives;
    GetAlternativeExitAnchors(Alternatives);
    TArray<FVector> SeenLocations;
    for (const UJMHideAnchorComponent* Alternative : Alternatives)
    {
        const FVector Location = GetValidationLocation(Alternative);
        if (SeenLocations.ContainsByPredicate([&Location](const FVector& Existing) { return Existing.Equals(Location, 1.0f); }))
        {
            OutErrors.Add(NSLOCTEXT("JMHide", "DuplicateAlternativeExit", "Alternative Exit anchors overlap."));
            bValid = false;
        }
        SeenLocations.Add(Location);
    }

    const FGameplayTag EffectiveTag = Definition ? Definition->HideType : HideType;
    if (!EffectiveTag.IsValid())
    {
        OutErrors.Add(NSLOCTEXT("JMHide", "InvalidHideType", "Hide Type Gameplay Tag is invalid."));
        bValid = false;
    }
    return bValid;
}

#if WITH_EDITOR
EDataValidationResult UJMHideSpotComponent::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    TArray<FText> Errors;
    if (!ValidateConfiguration(Errors))
    {
        for (const FText& Error : Errors)
        {
            Context.AddError(Error);
        }
        Result = EDataValidationResult::Invalid;
    }
    return Result;
}
#endif
