#if WITH_DEV_AUTOMATION_TESTS

#include "DialogueTokenizer.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDialogueTokenizerRestorationTest,
    "ReusableDialogue.Tokenizer.PreservesOriginalText",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FDialogueTokenizerRestorationTest::RunTest(const FString& Parameters)
{
    (void)Parameters;
    const FString Source = TEXT("잠깐……  저기 누가 있어?\n다음 줄로 내려간다.");
    FString Restored;
    for (const FDialogueRevealToken& Token : FDialogueTokenizer::TokenizeWords(Source)) Restored += Token.Text;
    TestEqual(TEXT("Word tokens reconstruct the exact input"), Restored, Source);

    const FString CharacterSource = TEXT("ABC 123");
    const TArray<FDialogueRevealToken> CharacterTokens = FDialogueTokenizer::TokenizeCharacters(CharacterSource);
    FString RestoredCharacters;
    for (const FDialogueRevealToken& Token : CharacterTokens) RestoredCharacters += Token.Text;
    TestEqual(TEXT("Character tokens reconstruct the exact input"), RestoredCharacters, CharacterSource);
    TestEqual(TEXT("Character tokenizer reveals one ASCII character per token"), CharacterTokens.Num(), CharacterSource.Len());
    TestTrue(TEXT("A word ending in punctuation can make sound"), FDialogueTokenizer::ContainsSpeakableText(TEXT("있어?")));
    TestFalse(TEXT("Ellipsis alone cannot make sound"), FDialogueTokenizer::ContainsSpeakableText(TEXT("……")));
    TestFalse(TEXT("Whitespace cannot make sound"), FDialogueTokenizer::ContainsSpeakableText(TEXT("   \n")));
    TestTrue(TEXT("Korean word can make sound"), FDialogueTokenizer::ContainsSpeakableText(TEXT("학교에")));
    return true;
}

#endif
