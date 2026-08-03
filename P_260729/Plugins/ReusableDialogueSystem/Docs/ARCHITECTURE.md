# 아키텍처

## 시스템 구성

`UDialogueSequence`는 선형 대사 묶음을 저장합니다. 각 `FDialogueLine`은 선택적으로 다음 데이터를 참조합니다.

- `UDialogueSpeakerProfile`
- `UDialogueTextSoundSet`
- Voice Sound
- Gameplay Tags
- 출력 방식과 진행 설정

`UDialogueSubsystem`은 `UGameInstanceSubsystem`을 상속합니다. Dialogue 재생 상태와 History가 특정 Level Actor에 종속되지 않고 하나의 GameInstance 범위에서 유지되어야 하기 때문입니다.

## 클래스 책임

### UDialogueSubsystem

- Dialogue 시작, 진행, 일시정지, 재개, 완료와 취소
- 현재 Sequence와 Line Index 관리
- Widget 생성과 제거
- Reveal Token 생성 및 Timer 예약
- Text Sound와 Voice Sound 재생 및 정리
- Runtime Dialogue History 기록
- 상태 및 Line 관련 Delegate 발생
- Modal 입력 적용 및 기본 복구

### UDialogueSequence

- 선형 `FDialogueLine` 배열 보관
- Sequence ID와 선택적 Gameplay Tag 보관
- 빈 배열에서도 안전하게 시작을 거부할 수 있는 데이터 단위

### UDialogueSpeakerProfile

- 화자 ID, 표시 이름과 이름 색상
- 선택적 Portrait와 Voice Sound
- 화자별 Text Sound Set

### UDialogueTextSoundSet

- 여러 개의 출력음 후보
- Volume/Pitch 무작위 범위
- 최소 재생 간격
- 공백과 문장부호 제외 정책
- 이전 출력음 중지 및 Sound Concurrency 설정

### UDialogueWidgetBase

- C++ Dialogue 시스템과 게임별 UMG 디자인 사이의 연결 계층
- 화자 이름, 본문, Portrait와 진행 표시 갱신
- 기본 키보드, 마우스와 게임패드 진행 입력 전달
- 게임별 Blueprint 애니메이션 이벤트 제공

### FDialogueTokenizer

- 원문을 보존하는 Word Token 생성
- UTF-16 surrogate pair를 보존하는 Character Token 생성
- 출력음 재생 가능 텍스트 판정
- 문장부호별 추가 지연 계산

## 데이터 흐름

```text
게임 또는 Blueprint
→ UDialogueSubsystem::StartDialogue
→ UDialogueSequence의 현재 Line 조회
→ Speaker 및 Widget 즉시 갱신
→ FDialogueTokenizer로 Reveal Token 생성
→ FTimerManager로 RevealNextToken 예약
→ Visible Text에 Token 추가
→ Widget Text 갱신
→ 같은 함수에서 Text Sound 재생
→ 문장부호 지연 계산
→ 다음 Token 예약
```

모든 Runtime Actor와 Component가 상시 Tick하도록 만들지 않았습니다. Dialogue가 재생 중일 때만 `FTimerManager`를 사용합니다.

## 상태 흐름

기본 상태 전이:

```text
Inactive
→ Opening
→ Revealing
→ WaitingForAdvance
→ Transitioning
→ Revealing 또는 Closing
→ Inactive
```

상태 변경은 `SetState`를 통해 처리하며 `OnDialogueStateChanged`를 한 곳에서 발생시킵니다.

진행 입력 규칙:

- `Revealing`: Timer를 해제하고 현재 Line 전체만 표시
- `WaitingForAdvance`: 다음 Line으로 이동하거나 Dialogue 완료
- `Paused` 및 기타 상태: 입력 무시

한 입력에서 문장 완성과 다음 문장 이동을 동시에 실행하지 않습니다. `InputDebounceTime`으로 빠른 연속 입력도 제한합니다.

## 출력음 동기화

`RevealNextToken`은 다음 작업을 같은 호출 흐름에서 실행합니다.

```text
Token 선택
→ Visible Text에 추가
→ Widget 본문 갱신
→ PlayTextSound 호출
→ 다음 Reveal 지연 계산 및 예약
```

독립적인 반복 Audio Timer를 사용하지 않으므로 시간이 지나도 텍스트와 출력음이 서로 어긋나지 않습니다. 문장을 즉시 완성할 때에는 남은 Token을 반복 처리하지 않고 원본 `FText` 전체를 한 번 설정하므로 남은 글자의 출력음도 재생하지 않습니다.

## 기존 Dialogue 처리 정책

- `Reject`: 실행 중인 Dialogue가 있으면 새 요청 거부
- `ReplaceCurrent`: 기존 Dialogue 정리 및 취소 이벤트 발생 후 새 Dialogue 시작

안전한 기본값은 `Reject`입니다.

## 프로젝트 독립성

플러그인은 다음 항목을 참조하지 않습니다.

- 프로젝트 전용 Character
- 프로젝트 전용 PlayerController
- GameMode 또는 HUD
- Level Blueprint
- 특정 Input Action이나 Mapping Context
- `/Game/...` 하드코딩 경로

다른 프로젝트에서는 Plugin 복사, Widget 지정, Data Asset 작성과 `StartDialogue` 호출만으로 연결할 수 있습니다.

