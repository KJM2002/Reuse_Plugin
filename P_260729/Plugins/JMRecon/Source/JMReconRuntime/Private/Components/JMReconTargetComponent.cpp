#include "Components/JMReconTargetComponent.h"

#include "Data/JMReconDefinition.h"
#include "Interfaces/JMReconTarget.h"
#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif
#include "Settings/JMReconSettings.h"

UJMReconTargetComponent::UJMReconTargetComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

UJMReconDefinition* UJMReconTargetComponent::GetEffectiveDefinition() const
{
    if (ReconDefinition)
    {
        return ReconDefinition;
    }

    const UJMReconSettings* Settings = GetDefault<UJMReconSettings>();
    if (Settings && !Settings->DefaultReconDefinition.IsNull())
    {
        if (UJMReconDefinition* Loaded = Settings->DefaultReconDefinition.LoadSynchronous())
        {
            return Loaded;
        }
    }

    return GetMutableDefault<UJMReconDefinition>();
}

FTransform UJMReconTargetComponent::ResolveTransform(const USceneComponent* Override, const FTransform& Relative) const
{
    return Override ? Override->GetComponentTransform() : Relative * GetComponentTransform();
}

FTransform UJMReconTargetComponent::GetPlayerWorldTransform() const
{
    return ResolveTransform(PlayerAnchorOverride, PlayerRelativeTransform);
}

FTransform UJMReconTargetComponent::GetListenCameraWorldTransform() const
{
    return ResolveTransform(ListenCameraAnchorOverride, ListenCameraRelativeTransform);
}

FTransform UJMReconTargetComponent::GetPeekCameraWorldTransform() const
{
    return ResolveTransform(PeekCameraAnchorOverride, PeekCameraRelativeTransform);
}

bool UJMReconTargetComponent::SupportsMode(EJMReconMode Mode) const
{
    // Early 1.0 editor builds stored the default three checked entries as
    // bit positions (2 | 4 | 16 == 22) instead of enum mask values (1 | 2 | 4).
    const int32 EffectiveModes = AllowedReconModes == 22
        ? static_cast<int32>(EJMReconMode::Listen) |
          static_cast<int32>(EJMReconMode::Peek) |
          static_cast<int32>(EJMReconMode::Illuminate)
        : AllowedReconModes;
    return (EffectiveModes & static_cast<int32>(Mode)) != 0;
}

FJMReconRequestResult UJMReconTargetComponent::TryReserve(const FGuid& SessionId)
{
    if (!bEnabled)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::Disabled);
    }
    if (!SessionId.IsValid())
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::InvalidTarget);
    }
    if (ReservedSessionId.IsValid() && ReservedSessionId != SessionId)
    {
        return FJMReconRequestResult::Failure(EJMReconFailureReason::AlreadyInUse);
    }
    ReservedSessionId = SessionId;
    return FJMReconRequestResult::Success();
}

void UJMReconTargetComponent::ReleaseReservation(const FGuid& SessionId)
{
    if (ReservedSessionId == SessionId)
    {
        ReservedSessionId.Invalidate();
    }
}

bool UJMReconTargetComponent::IsReservedBy(const FGuid& SessionId) const
{
    return ReservedSessionId.IsValid() && ReservedSessionId == SessionId;
}

#if WITH_EDITOR
EDataValidationResult UJMReconTargetComponent::IsDataValid(FDataValidationContext& Context) const
{
    EDataValidationResult Result = Super::IsDataValid(Context);
    UJMReconDefinition* Definition = GetEffectiveDefinition();
    if (!Definition)
    {
        Context.AddError(NSLOCTEXT("JMRecon", "MissingDefinition", "No Recon Definition or safe default is available."));
        return EDataValidationResult::Invalid;
    }
    if (MaximumStartDistance < 0.0f)
    {
        Context.AddError(NSLOCTEXT("JMRecon", "Distance", "Maximum Start Distance cannot be negative."));
        Result = EDataValidationResult::Invalid;
    }
    if (SupportsMode(EJMReconMode::Peek) && !Definition->bAllowPeek)
    {
        Context.AddWarning(NSLOCTEXT("JMRecon", "PeekMismatch", "Target allows Peek but its Definition disables Peek."));
        if (Result == EDataValidationResult::NotValidated)
        {
            Result = EDataValidationResult::Valid;
        }
    }
    return Result;
}
#endif
