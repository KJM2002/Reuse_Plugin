#include "Components/JMHarpoonInteractableComponent.h"

UJMHarpoonInteractableComponent::UJMHarpoonInteractableComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

FJMHarpoonInteractionProfile UJMHarpoonInteractableComponent::GetHarpoonInteractionProfile_Implementation(
    const FJMHarpoonInteractionContext& Context) const
{
    return Profile;
}

void UJMHarpoonInteractableComponent::OnHarpoonEmbedded_Implementation(
    const FJMHarpoonInteractionContext& Context)
{
    SustainedReactionTime = 0.0f;
    PullNoiseCooldown = 0.0f;
    bReactionCompleted = false;
    if (Profile.ImpactNoiseLoudness > 0.0f)
    {
        OnHarpoonNoise.Broadcast(Context.ImpactPoint, Profile.ImpactNoiseLoudness, false);
    }
}

void UJMHarpoonInteractableComponent::OnHarpoonPullStarted_Implementation(
    const FJMHarpoonInteractionContext& Context)
{
    SustainedReactionTime = 0.0f;
    PullNoiseCooldown = 0.0f;
}

EJMHarpoonReactionDirective UJMHarpoonInteractableComponent::OnHarpoonPullUpdated_Implementation(
    const FJMHarpoonInteractionContext& Context,
    const FJMHarpoonPullUpdate& Update)
{
    PullNoiseCooldown -= Update.DeltaTime;
    if (Profile.PullNoiseLoudness > 0.0f && PullNoiseCooldown <= 0.0f)
    {
        OnHarpoonNoise.Broadcast(Context.ImpactPoint, Profile.PullNoiseLoudness, true);
        PullNoiseCooldown = 0.25f;
    }

    if (Profile.FragileSafeForce > 0.0f && Update.AppliedForce > Profile.FragileSafeForce && Condition > 0.0f)
    {
        const float OverForceRatio = Update.AppliedForce / Profile.FragileSafeForce - 1.0f;
        Condition = FMath::Clamp(
            Condition - OverForceRatio * Profile.FragileDamagePerSecond * Update.DeltaTime,
            0.0f,
            1.0f);
        OnConditionChanged.Broadcast(Condition);
        if (Condition <= 0.0f && !bReactionCompleted)
        {
            bReactionCompleted = true;
            OnReactionCompleted.Broadcast(EJMHarpoonReaction::Break, Context);
            return bReleaseOnReactionComplete
                ? EJMHarpoonReactionDirective::ReleaseHarpoon
                : EJMHarpoonReactionDirective::Continue;
        }
    }

    const bool bSupportsReaction =
        (Profile.Reaction == EJMHarpoonReaction::Break && Profile.bCanBreak)
        || (Profile.Reaction == EJMHarpoonReaction::Extract && Profile.bCanExtract)
        || (Profile.Reaction == EJMHarpoonReaction::Activate && Profile.bCanActivate)
        || (Profile.Reaction == EJMHarpoonReaction::CreaturePart && Profile.bCanAffectCreature);
    if (!bSupportsReaction || bReactionCompleted)
    {
        return EJMHarpoonReactionDirective::Continue;
    }

    if (Update.AppliedForce >= Profile.ReactionForce)
    {
        SustainedReactionTime += Update.DeltaTime;
    }
    else
    {
        SustainedReactionTime = FMath::Max(0.0f, SustainedReactionTime - Update.DeltaTime * 2.0f);
    }

    if (SustainedReactionTime >= Profile.ReactionHoldTime)
    {
        bReactionCompleted = true;
        OnReactionCompleted.Broadcast(Profile.Reaction, Context);
        return bReleaseOnReactionComplete
            ? EJMHarpoonReactionDirective::ReleaseHarpoon
            : EJMHarpoonReactionDirective::Continue;
    }
    return EJMHarpoonReactionDirective::Continue;
}

void UJMHarpoonInteractableComponent::OnHarpoonInteractionEnded_Implementation(
    const FJMHarpoonInteractionContext& Context,
    EJMHarpoonInteractionEndReason Reason)
{
    SustainedReactionTime = 0.0f;
    PullNoiseCooldown = 0.0f;
}

void UJMHarpoonInteractableComponent::ResetHarpoonCondition()
{
    Condition = 1.0f;
    SustainedReactionTime = 0.0f;
    PullNoiseCooldown = 0.0f;
    bReactionCompleted = false;
    OnConditionChanged.Broadcast(Condition);
}
