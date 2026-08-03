#include "Settings/JMReconGameplayIntegrationSettings.h"

UJMReconGameplayIntegrationSettings::UJMReconGameplayIntegrationSettings()
{
    ReconPromptStyle.ScreenOffset = FVector2D(0.0, 260.0);
    ReconPromptStyle.FontSize = 22;
    FocusedTargetPromptFormat = NSLOCTEXT(
        "JMReconIntegration", "FocusedDoorPrompt", "[{0}] 문 열기    [{1}] 문틈 확인");
    EnteringPrompt = NSLOCTEXT(
        "JMReconIntegration", "EnteringPrompt", "문틈을 확인하는 중…");
    FlashlightActivePromptFormat = NSLOCTEXT(
        "JMReconIntegration", "FlashlightActivePrompt", "[{0}] 손전등 사용 중    [{1}] 뒤로");
    ObservingPromptFormat = NSLOCTEXT(
        "JMReconIntegration", "ObservingPrompt", "[마우스] 둘러보기    [{0} 길게] 손전등    [{1}] 뒤로");
    DoorMovingFailurePrompt = NSLOCTEXT(
        "JMReconIntegration", "DoorMovingFailure", "문이 움직이는 중입니다.");
    DoorOpenFailurePrompt = NSLOCTEXT(
        "JMReconIntegration", "DoorOpenFailure", "이미 열린 문은 문틈으로 확인할 수 없습니다.");
    BlockedFailurePrompt = NSLOCTEXT(
        "JMReconIntegration", "DoorBlockedFailure", "잠겨 있거나 사용할 수 없는 문입니다.");
    OutOfRangeFailurePrompt = NSLOCTEXT(
        "JMReconIntegration", "OutOfRangeFailure", "문에 조금 더 가까이 가세요.");
    GenericFailurePrompt = NSLOCTEXT(
        "JMReconIntegration", "GenericFailure", "지금은 문틈을 확인할 수 없습니다.");
}
