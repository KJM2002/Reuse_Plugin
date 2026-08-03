#include "Actors/JMJumpScareTrigger.h"

#include "Actors/JMJumpScareAnchor.h"
#include "Components/BoxComponent.h"
#include "Data/JMJumpScareDefinition.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagAssetInterface.h"
#include "Settings/JMJumpScareSettings.h"
#include "Subsystems/JMJumpScareSubsystem.h"

AJMJumpScareTrigger::AJMJumpScareTrigger()
{
    PrimaryActorTick.bCanEverTick = false;
    TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
    SetRootComponent(TriggerVolume);
    TriggerVolume->SetBoxExtent(FVector(100.0f));
    TriggerVolume->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerVolume->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerVolume->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    TriggerVolume->SetGenerateOverlapEvents(true);
    TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AJMJumpScareTrigger::HandleBeginOverlap);

    if (const UJMJumpScareSettings* Settings = GetDefault<UJMJumpScareSettings>())
    {
        TriggerPolicy = Settings->DefaultTriggerPolicy;
        TargetActorFilter = Settings->DefaultOverlapActorFilter;
    }
}

void AJMJumpScareTrigger::ResetTrigger()
{
    bHasTriggered = false;
    if (UJMJumpScareSubsystem* Subsystem = GetWorld() ? GetWorld()->GetSubsystem<UJMJumpScareSubsystem>() : nullptr)
    {
        Subsystem->ResetOncePolicy(this);
    }
}

FJMJumpScareTriggerSaveState AJMJumpScareTrigger::CaptureSaveState() const
{
    FJMJumpScareTriggerSaveState SaveState;
    SaveState.TriggerId = TriggerId;
    SaveState.bHasTriggered = bHasTriggered;
    return SaveState;
}

void AJMJumpScareTrigger::RestoreSaveState(const FJMJumpScareTriggerSaveState& SaveState)
{
    if (!TriggerId.IsValid() || TriggerId == SaveState.TriggerId)
    {
        bHasTriggered = SaveState.bHasTriggered;
    }
}

void AJMJumpScareTrigger::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bEnabled || !JumpScareDefinition || (TriggerPolicy == EJMJumpScareTriggerPolicy::Once && bHasTriggered))
    {
        return;
    }

    APlayerController* TargetPlayer = nullptr;
    if (!PassesActorFilter(OtherActor, TargetPlayer))
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
    Context.Instigator = OtherActor;
    Context.TargetPlayer = TargetPlayer;
    Context.Anchor = JumpScareAnchor;
    Context.Source = this;
    Context.bOverrideTriggerPolicy = true;
    Context.TriggerPolicyOverride = TriggerPolicy;
    if (Subsystem->PlayJumpScare(JumpScareDefinition, Context) == EJMJumpScarePlayResult::Started)
    {
        bHasTriggered = true;
    }
}

bool AJMJumpScareTrigger::PassesActorFilter(AActor* OtherActor, APlayerController*& OutPlayerController) const
{
    OutPlayerController = nullptr;
    if (!IsValid(OtherActor))
    {
        return false;
    }

    APawn* Pawn = Cast<APawn>(OtherActor);
    OutPlayerController = Pawn ? Cast<APlayerController>(Pawn->GetController()) : nullptr;
    switch (TargetActorFilter)
    {
    case EJMJumpScareOverlapFilter::PlayerControlledPawn:
        return Pawn && OutPlayerController;
    case EJMJumpScareOverlapFilter::AnyPawn:
        return Pawn != nullptr;
    case EJMJumpScareOverlapFilter::GameplayTags:
        if (const IGameplayTagAssetInterface* TagInterface = Cast<IGameplayTagAssetInterface>(OtherActor))
        {
            FGameplayTagContainer OwnedTags;
            TagInterface->GetOwnedGameplayTags(OwnedTags);
            return OwnedTags.HasAll(RequiredActorTags);
        }
        return false;
    default:
        return false;
    }
}
