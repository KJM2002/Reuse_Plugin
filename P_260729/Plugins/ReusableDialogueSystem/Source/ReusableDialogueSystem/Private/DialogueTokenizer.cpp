#include "DialogueTokenizer.h"

namespace
{
bool IsPunctuation(TCHAR C)
{
    static const FString Marks = TEXT(".,!?…~。，！？、：；'\"()[]{}<>-—–「」『』【】（）");
    return Marks.Contains(FString::Chr(C));
}
}

bool FDialogueTokenizer::ContainsSpeakableText(const FString& Text)
{
    for (TCHAR C : Text) if (!FChar::IsWhitespace(C) && !IsPunctuation(C)) return true;
    return false;
}

float FDialogueTokenizer::CalculatePunctuationDelay(const FString& Text, float CommaDelay, float SentenceDelay, float EllipsisDelay, float NewLineDelay)
{
    if (Text.Contains(TEXT("...")) || Text.Contains(TEXT("…"))) return EllipsisDelay;
    if (Text.Contains(TEXT("\n")) || Text.Contains(TEXT("\r"))) return NewLineDelay;
    if (Text.Contains(TEXT(".")) || Text.Contains(TEXT("!")) || Text.Contains(TEXT("?")) || Text.Contains(TEXT("。")) || Text.Contains(TEXT("！")) || Text.Contains(TEXT("？"))) return SentenceDelay;
    if (Text.Contains(TEXT(",")) || Text.Contains(TEXT("，")) || Text.Contains(TEXT("、"))) return CommaDelay;
    return 0.f;
}

TArray<FDialogueRevealToken> FDialogueTokenizer::TokenizeWords(const FString& Source)
{
    TArray<FDialogueRevealToken> Result;
    int32 Start = 0;
    while (Start < Source.Len())
    {
        int32 End = Start;
        const bool bStartsWhitespace = FChar::IsWhitespace(Source[Start]);
        if (bStartsWhitespace)
        {
            while (End < Source.Len() && FChar::IsWhitespace(Source[End])) ++End;
        }
        else
        {
            while (End < Source.Len() && !FChar::IsWhitespace(Source[End])) ++End;
            while (End < Source.Len() && FChar::IsWhitespace(Source[End])) ++End;
        }
        FDialogueRevealToken& Token = Result.AddDefaulted_GetRef();
        Token.Text = Source.Mid(Start, End - Start);
        Token.bCanTriggerSound = ContainsSpeakableText(Token.Text);
        Token.Type = bStartsWhitespace ? EDialogueTokenType::Whitespace : (Token.bCanTriggerSound ? EDialogueTokenType::Word : EDialogueTokenType::Punctuation);
        Start = End;
    }
    return Result;
}

TArray<FDialogueRevealToken> FDialogueTokenizer::TokenizeCharacters(const FString& Source)
{
    TArray<FDialogueRevealToken> Result;
    for (int32 Index = 0; Index < Source.Len(); ++Index)
    {
        // FString indexes TCHAR code units. Preserve UTF-16 surrogate pairs as one visible token.
        int32 Count = 1;
        const uint32 First = static_cast<uint32>(Source[Index]);
        const uint32 Second = Index + 1 < Source.Len() ? static_cast<uint32>(Source[Index + 1]) : 0;
        if (First >= 0xD800 && First <= 0xDBFF && Second >= 0xDC00 && Second <= 0xDFFF) Count = 2;
        FDialogueRevealToken& Token = Result.AddDefaulted_GetRef();
        Token.Text = Source.Mid(Index, Count);
        Token.bCanTriggerSound = ContainsSpeakableText(Token.Text);
        Token.Type = FChar::IsWhitespace(Source[Index]) ? EDialogueTokenType::Whitespace : (Token.bCanTriggerSound ? EDialogueTokenType::Word : EDialogueTokenType::Punctuation);
        Index += Count - 1;
    }
    return Result;
}
