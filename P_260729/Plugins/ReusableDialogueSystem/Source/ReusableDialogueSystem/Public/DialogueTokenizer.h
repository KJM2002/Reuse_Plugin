#pragma once

#include "CoreMinimal.h"
#include "ReusableDialogueTypes.h"

class REUSABLEDIALOGUESYSTEM_API FDialogueTokenizer
{
public:
    static TArray<FDialogueRevealToken> TokenizeWords(const FString& Source);
    static TArray<FDialogueRevealToken> TokenizeCharacters(const FString& Source);
    static bool ContainsSpeakableText(const FString& Text);
    static float CalculatePunctuationDelay(const FString& Text, float CommaDelay, float SentenceDelay, float EllipsisDelay, float NewLineDelay);
};
