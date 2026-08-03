#include "Components/JMHideSimplePanelMechanismComponent.h"

#include "Components/SceneComponent.h"
#include "Curves/CurveFloat.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogJMHideMechanismDebug, Log, All);

UJMHideSimplePanelMechanismComponent::UJMHideSimplePanelMechanismComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UJMHideSimplePanelMechanismComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    SetComponentTickEnabled(false);
    ActiveSessionId.Invalidate();
    Super::EndPlay(EndPlayReason);
}

bool UJMHideSimplePanelMechanismComponent::CanStartOperation(EJMHideOperation Operation,
    const FJMHideOperationContext& Context, EJMHideFailureCode& OutFailure) const
{
    TArray<FText> Errors;
    if (!ValidateConfiguration(Errors))
    {
        OutFailure = EJMHideFailureCode::InvalidMechanism;
        return false;
    }
    OutFailure = EJMHideFailureCode::None;
    return true;
}

bool UJMHideSimplePanelMechanismComponent::StartOperation(const FGuid& SessionId, EJMHideOperation Operation,
    const FJMHideOperationContext& Context)
{
    EJMHideFailureCode Failure;
    if (!CanStartOperation(Operation, Context, Failure) || !SessionId.IsValid())
    {
        return false;
    }

    if (Operation == EJMHideOperation::PrepareEnter || Operation == EJMHideOperation::PrepareExit)
    {
        bOpening = true;
    }
    else if (Operation == EJMHideOperation::CompleteEnter || Operation == EJMHideOperation::CompleteExit ||
        Operation == EJMHideOperation::Restore)
    {
        bOpening = false;
    }
    else
    {
        CompleteOperation(SessionId, Operation, true);
        return true;
    }

    ActiveSessionId = SessionId;
    ActiveOperation = Operation;
    Elapsed = 0.0f;
    if (Duration <= KINDA_SMALL_NUMBER && Delay <= KINDA_SMALL_NUMBER)
    {
        ApplyAlpha(bOpening ? 1.0f : 0.0f);
        FinishTransition();
        return true;
    }
    SetComponentTickEnabled(true);
    return true;
}

void UJMHideSimplePanelMechanismComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (!ActiveSessionId.IsValid())
    {
        SetComponentTickEnabled(false);
        return;
    }
    Elapsed += DeltaTime;
    if (Elapsed < Delay)
    {
        return;
    }
    const float LinearAlpha = Duration <= KINDA_SMALL_NUMBER ? 1.0f :
        FMath::Clamp((Elapsed - Delay) / Duration, 0.0f, 1.0f);
    const float EasedAlpha = Curve ? Curve->GetFloatValue(LinearAlpha) : LinearAlpha;
    ApplyAlpha(bOpening ? EasedAlpha : 1.0f - EasedAlpha);
    if (LinearAlpha >= 1.0f)
    {
        FinishTransition();
    }
}

void UJMHideSimplePanelMechanismComponent::ApplyAlpha(float Alpha)
{
    for (const FJMHidePanelPart& Part : Panels)
    {
        if (IsValid(Part.Panel) && IsValid(Part.Panel->GetAttachParent()))
        {
            const float ClampedAlpha = FMath::Clamp(Alpha, 0.0f, 1.0f);
            if (Part.MotionType == EJMHidePanelMotionType::RotationOnly)
            {
                const FQuat Rotation = ClampedAlpha <= 0.0f
                    ? Part.ClosedRelativeTransform.GetRotation()
                    : ClampedAlpha >= 1.0f
                        ? Part.OpenRelativeTransform.GetRotation()
                        : FQuat::Slerp(
                            Part.ClosedRelativeTransform.GetRotation(),
                            Part.OpenRelativeTransform.GetRotation(),
                            ClampedAlpha).GetNormalized();
                Part.Panel->SetRelativeRotation(Rotation);
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
                if (ClampedAlpha <= 0.0f || ClampedAlpha >= 1.0f)
                {
                    UE_LOG(LogJMHideMechanismDebug, Log,
                        TEXT("RotationOnly endpoint: Panel=%s RelativeLocation=%s RelativeRotation=%s RelativeScale=%s"),
                        *GetNameSafe(Part.Panel),
                        *Part.Panel->GetRelativeLocation().ToCompactString(),
                        *Part.Panel->GetRelativeRotation().ToCompactString(),
                        *Part.Panel->GetRelativeScale3D().ToCompactString());
                    TArray<USceneComponent*> Children;
                    Part.Panel->GetChildrenComponents(false, Children);
                    for (const USceneComponent* Child : Children)
                    {
                        UE_LOG(LogJMHideMechanismDebug, Log,
                            TEXT("RotationOnly child invariant: Child=%s RelativeLocation=%s RelativeRotation=%s RelativeScale=%s"),
                            *GetNameSafe(Child),
                            *Child->GetRelativeLocation().ToCompactString(),
                            *Child->GetRelativeRotation().ToCompactString(),
                            *Child->GetRelativeScale3D().ToCompactString());
                    }
                }
#endif
            }
            else
            {
                Part.Panel->SetRelativeTransform(UKismetMathLibrary::TLerp(
                    Part.ClosedRelativeTransform, Part.OpenRelativeTransform, ClampedAlpha));
            }
        }
    }
}

void UJMHideSimplePanelMechanismComponent::FinishTransition()
{
    const FGuid CompletedSession = ActiveSessionId;
    const EJMHideOperation CompletedOperation = ActiveOperation;
    ApplyAlpha(bOpening ? 1.0f : 0.0f);
    ActiveSessionId.Invalidate();
    ActiveOperation = EJMHideOperation::None;
    SetComponentTickEnabled(false);
    CompleteOperation(CompletedSession, CompletedOperation, true);
}

void UJMHideSimplePanelMechanismComponent::CancelOperation(const FGuid& SessionId)
{
    if (SessionId == ActiveSessionId)
    {
        ActiveSessionId.Invalidate();
        ActiveOperation = EJMHideOperation::None;
        SetComponentTickEnabled(false);
    }
}

void UJMHideSimplePanelMechanismComponent::Restore(const FGuid& SessionId)
{
    CancelOperation(SessionId);
    ApplyAlpha(0.0f);
}

void UJMHideSimplePanelMechanismComponent::GetOwnedSceneComponents(TArray<USceneComponent*>& OutComponents) const
{
    for (const FJMHidePanelPart& Part : Panels)
    {
        if (IsValid(Part.Panel))
        {
            OutComponents.AddUnique(Part.Panel);
        }
    }
}

bool UJMHideSimplePanelMechanismComponent::ValidateConfiguration(TArray<FText>& OutErrors) const
{
    bool bValid = true;
    TSet<const USceneComponent*> Seen;
    for (const FJMHidePanelPart& Part : Panels)
    {
        if (!IsValid(Part.Panel) || !IsValid(Part.Panel->GetAttachParent()))
        {
            OutErrors.Add(NSLOCTEXT("JMHide", "InvalidPanelParent", "Every panel must have a valid parent."));
            bValid = false;
            continue;
        }
        if (Seen.Contains(Part.Panel))
        {
            OutErrors.Add(NSLOCTEXT("JMHide", "DuplicatePanel", "A panel is registered more than once."));
            bValid = false;
        }
        Seen.Add(Part.Panel);
        const bool bSamePose = Part.MotionType == EJMHidePanelMotionType::RotationOnly
            ? Part.ClosedRelativeTransform.GetRotation().Equals(
                Part.OpenRelativeTransform.GetRotation())
            : Part.ClosedRelativeTransform.Equals(Part.OpenRelativeTransform);
        if (bSamePose)
        {
            OutErrors.Add(NSLOCTEXT("JMHide", "SamePanelPose", "Panel open and closed relative transforms are identical."));
            bValid = false;
        }
    }
    return bValid;
}
