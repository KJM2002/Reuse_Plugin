# JMHide

UE 5.7용 재사용 은신 Runtime 플러그인입니다. `JMHide` 폴더만 복사해 사용할 수 있으며 다른 JM 플러그인은 필수가 아닙니다.

## 빠른 설정

1. Player Character에 `JMHideInteractorComponent`와 `JMHideCharacterParticipantComponent`를 추가합니다.
2. 은신 Actor에 `JMHideSpotComponent`를 추가합니다.
3. 같은 Actor에 Entry, Occupant, Camera, PrimaryExit 역할의 `JMHideAnchorComponent`를 배치합니다.
4. 폐쇄형 은신처는 `JMHideSimplePanelMechanismComponent` 또는 별도 JMDoor Adapter 하나를 추가합니다.
5. 호스트 입력에서 숨은 상태면 `TryExitCurrentHideSpot`, 아니면 기존 Interaction 입력을 호출합니다.

기본 Character Driver는 엔진 `ACharacter`만 지원합니다. 커스텀 Pawn/Camera 시스템은 `UJMHideParticipantDriverComponent` 파생 Driver를 제공해야 합니다.
