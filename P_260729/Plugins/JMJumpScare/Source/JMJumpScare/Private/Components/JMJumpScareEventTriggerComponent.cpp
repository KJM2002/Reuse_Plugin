#include "Components/JMJumpScareEventTriggerComponent.h"

#include "Actors/JMJumpScareAnchor.h"
#include "Data/JMJumpScareDefinition.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Subsystems/JMGameplayEventSubsystem.h"
#include "Subsystems/JMJumpScareSubsystem.h"

UJMJumpScareEventTriggerComponent::UJMJumpScareEventTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UJMJumpScareEventTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
    UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    UJMGameplayEventSubsystem* Events = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr;
    if (Events && TriggerEventTag.IsValid())
    {
        SubscriptionHandle = Events->SubscribeEvent(TriggerEventTag, this, EventMatchType, FJMGameplayEventNativeDelegate::CreateUObject(this, &UJMJumpScareEventTriggerComponent::HandleGameplayEvent));
    }
}

void UJMJumpScareEventTriggerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UGameInstance* GameInstance = GetWorld() ? GetWorld()->GetGameInstance() : nullptr;
    if (UJMGameplayEventSubsystem* Events = GameInstance ? GameInstance->GetSubsystem<UJMGameplayEventSubsystem>() : nullptr)
    {
        Events->UnsubscribeEvent(SubscriptionHandle);
    }
    SubscriptionHandle.Reset();
    Super::EndPlay(EndPlayReason);
}

void UJMJumpScareEventTriggerComponent::HandleGameplayEvent(const FJMGameplayEventMessage& Message)
{
    if (!JumpScareDefinition || (TriggerPolicy == EJMJumpScareTriggerPolicy::Once && bHasTriggered))
    {
        return;
    }
    UJMJumpScareSubsystem* Subsystem = GetWorld() ? GetWorld()->GetSubsystem<UJMJumpScareSubsystem>() : nullptr;
    if (!Subsystem)
    {
        return;
    }

    FJMJumpScarePlayContext Context;
    Context.WorldContextObject = this;
    Context.Instigator = Message.Instigator;
    Context.TargetPlayer = Cast<APlayerController>(Message.Target);
    if (!Context.TargetPlayer)
    {
        if (const APawn* Pawn = Cast<APawn>(Message.Target))
        {
            Context.TargetPlayer = Cast<APlayerController>(Pawn->GetController());
        }
    }
    Context.Anchor = JumpScareAnchor;
    Context.Source = this;
    Context.ContextTags = Message.ContextTags;
    Context.bOverrideTriggerPolicy = true;
    Context.TriggerPolicyOverride = TriggerPolicy;
    if (Subsystem->PlayJumpScare(JumpScareDefinition, Context) == EJMJumpScarePlayResult::Started)
    {
        bHasTriggered = true;
    }
}
