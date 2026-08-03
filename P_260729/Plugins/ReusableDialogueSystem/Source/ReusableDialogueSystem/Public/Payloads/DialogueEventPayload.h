#pragma once

#include "CoreMinimal.h"
#include "Payloads/JMGameplayEventPayloadBase.h"
#include "ReusableDialogueTypes.h"
#include "DialogueEventPayload.generated.h"

class UDialogueSequence;
class UDialogueSpeakerProfile;

UCLASS(BlueprintType)
class REUSABLEDIALOGUESYSTEM_API UDialogueEventPayload : public UJMGameplayEventPayloadBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    TObjectPtr<UDialogueSequence> Sequence = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    FName DialogueId;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    FName ConversationId;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    TObjectPtr<UDialogueSpeakerProfile> Speaker = nullptr;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    FName ChoiceId;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    int32 ChoiceIndex = INDEX_NONE;

    UPROPERTY(BlueprintReadOnly, Category = "Dialogue|Events")
    EDialogueEndReason EndReason = EDialogueEndReason::Completed;
};
