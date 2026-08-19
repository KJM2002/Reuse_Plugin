---
title: "재사용형 대화 시스템"
status: ReviewRequired
authority: Guide
scope: "Plugin: ReusableDialogueSystem"
classified_on: 2026-08-19
owners:
  - "ReusableDialogueSystem Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# 재사용형 대화 시스템

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [아키텍처](Docs/ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [Changelog](Docs/CHANGELOG.md) | `ReviewRequired` |
| Plans | [구현 계획](Docs/Plans/IMPLEMENTATION_PLAN.md) | `Draft` |
| Plans | [후속 구현 목록](Docs/Plans/TODO.md) | `Draft` |


> 0.2.0부터 `UReuseDialogueInteractableComponent`가 이 플러그인에 포함됩니다. 액터에 컴포넌트를 추가하고 Dialogue Sequence를 지정하면 ItemInspector의 상호작용으로 대화를 시작할 수 있습니다. 따라서 이 플러그인을 사용할 때는 `ItemInspector` 플러그인 폴더도 함께 복사합니다.

`ReusableDialogueSystem`은 특정 Character, GameMode, HUD 또는 PlayerController 구현에 의존하지 않는 Unreal Engine 5.7 Runtime Plugin입니다. 다른 프로젝트의 `Plugins` 폴더에 플러그인 폴더 전체를 복사하고 활성화한 뒤 컴파일하여 사용할 수 있습니다.

## 설치 방법

1. 대상 프로젝트를 닫습니다.
2. `Plugins/ReusableDialogueSystem` 폴더 전체를 대상 프로젝트의 `Plugins` 폴더로 복사합니다.
3. 프로젝트 파일 재생성이 필요하면 `.uproject`를 우클릭하고 **Generate Visual Studio project files**를 실행합니다.
4. 프로젝트를 컴파일하고 Unreal Editor를 실행합니다.
5. **Edit → Plugins**에서 **Reusable Dialogue System**이 활성화되어 있는지 확인합니다.

이 플러그인은 `JaeminFramework`, Enhanced Input, 특정 Input Action 또는 프로젝트 전용 콘텐츠에 의존하지 않습니다.

## Project Settings 설정

**Edit → Project Settings → Game → Reusable Dialogue System**을 엽니다.

다음 값을 설정할 수 있습니다.

- `Default Dialogue Widget Class`: 기본 대화 Widget Blueprint
- `Default Word Interval`: 단어 단위 출력 간격
- `Default Character Interval`: 글자 단위 출력 간격
- `Comma Delay`: 쉼표 뒤 추가 지연
- `Sentence End Delay`: 마침표, 물음표, 느낌표 뒤 추가 지연
- `Ellipsis Delay`: 말줄임표 뒤 추가 지연
- `New Line Delay`: 줄바꿈 뒤 추가 지연
- `Input Debounce Time`: 빠른 연속 입력 방지 시간
- 마우스, 키보드, 게임패드 기본 진행 입력 허용 여부
- 기본 Text Sound Set과 음향 설정

`Default Dialogue Widget Class`가 없으면 크래시하지 않고 Dialogue 시작을 거부하며 로그 경고를 출력합니다.

## Widget Blueprint 만들기

Content Browser에서 `UDialogueWidgetBase`를 부모 클래스로 하는 Widget Blueprint를 만듭니다. 권장 이름은 `WBP_Dialogue`입니다.

권장 계층 구조입니다. 괄호 안은 **UMG Palette에서 실제로 추가해야 하는 Widget 타입 이름**이고, 괄호 앞은 생성한 뒤 변경할 **Widget 변수 이름**입니다.

```text
SafeZone (Safe Zone)
└─ CanvasPanel (Canvas Panel)
   └─ DialogueContainer (Size Box)
      └─ DialogueVerticalBox (Vertical Box)
         ├─ SpeakerNamePanel (Border)
         │  └─ SpeakerNameText (Text Block)
         ├─ DialogueBackground (Border)
         │  └─ DialogueText (Text Block)
         └─ AdvanceIndicator (Image)
```

예를 들어 Palette에서 **Size Box**를 끌어다 놓은 다음, Hierarchy에서 해당 항목의 이름을 `DialogueContainer`로 변경합니다. 나머지 항목도 같은 방식으로 괄호 안의 Widget을 추가한 뒤 괄호 앞의 이름으로 변경합니다.

각 항목의 용도:

- `SafeZone` (`Safe Zone`): TV나 모바일 화면 가장자리에서 UI가 잘리는 것을 방지합니다.
- `CanvasPanel` (`Canvas Panel`): Dialogue UI를 화면 상단 중앙에 자유롭게 배치하는 최상위 배치 영역입니다.
- `DialogueContainer` (`Size Box`): Dialogue UI 전체의 너비와 최소 높이를 지정합니다.
- `DialogueVerticalBox` (`Vertical Box`): 화자 이름, 본문, 진행 표시를 위에서 아래 순서로 정렬합니다.
- `SpeakerNamePanel` (`Border`): 화자 이름 뒤의 선택적 배경입니다.
- `SpeakerNameText` (`Text Block`): 실제 화자 이름을 표시합니다.
- `DialogueBackground` (`Border`): 대사 본문의 배경과 Padding을 담당합니다.
- `DialogueText` (`Text Block`): 실제 대사 내용을 표시합니다.
- `AdvanceIndicator` (`Image`): 현재 문장이 완성되어 다음 입력을 기다리는 상태를 표시합니다.

`AdvanceIndicator`는 반드시 `Image`일 필요는 없습니다. 애니메이션이나 글자를 사용하고 싶다면 다른 Widget 타입으로 만들어도 됩니다. C++에서는 선택적인 `UWidget`으로 처리하므로 이름만 `AdvanceIndicator`와 정확히 일치하면 됩니다.

필수 Widget 이름과 타입:

- `SpeakerNameText`: `Text Block`, 필수
- `DialogueText`: `Text Block`, 필수

선택 Widget 이름과 권장 타입:

- `SpeakerNamePanel`: `Border`
- `SpeakerPortrait`: `Image` — Portrait가 필요할 때만 추가
- `AdvanceIndicator`: `Image` 권장
- `DialogueContainer`: `Size Box` 권장

이름은 C++의 `BindWidget` 변수명과 정확히 일치해야 합니다. `DialogueText`에는 자동 줄바꿈을 적용하고, 단어가 출력될 때 UI 높이가 흔들리지 않도록 본문 컨테이너에 최소 높이를 설정하는 것을 권장합니다.

## 화면 하단 중앙 배치 권장값

아래 값은 **1920×1080 화면을 기준으로 한 시작점**입니다. Anchor를 하단 중앙에 두기 때문에 다른 해상도에서도 대화창이 화면 하단 중앙을 기준으로 유지됩니다.

### 1. SafeZone (Safe Zone)

`SafeZone`을 선택하고 Canvas가 아닌 Widget Root로 사용합니다.

- Anchors: 화면 전체를 채우는 기본 Root 상태
- 크기: 화면 전체 자동 채움
- Padding: 기본값 `0`

직접 Width와 Height를 입력할 필요가 없습니다.

### 2. CanvasPanel (Canvas Panel)

`CanvasPanel`은 `SafeZone`의 자식으로 추가합니다.

- Slot → Horizontal Alignment: `Fill`
- Slot → Vertical Alignment: `Fill`
- Padding: `0`

Canvas가 Safe Zone 전체를 채워야 하므로 별도의 고정 크기를 설정하지 않습니다.

### 3. DialogueContainer (Size Box)

`DialogueContainer`를 선택하고 **Slot (Canvas Panel Slot)** 항목을 다음과 같이 설정합니다.

```text
Anchors: Bottom Center
Anchor Min: X 0.5, Y 1.0
Anchor Max: X 0.5, Y 1.0
Alignment: X 0.5, Y 1.0
Position X: 0
Position Y: -80
Size X: 1200
Size Y: 260
Auto Size: 비활성화
ZOrder: 0
```

여기서 `Position Y = -80`은 화면 아래쪽에서 위로 80px 떨어뜨린다는 뜻입니다. 더 아래에 두려면 `-40`, 더 위에 두려면 `-120`처럼 조정합니다.

`DialogueContainer` 자체의 **Size Box** 설정:

```text
Width Override: 1200
Height Override: 설정하지 않음
Min Desired Height: 220
Max Desired Height: 320
```

Canvas Slot의 `Size Y`와 Size Box의 높이 제한을 동시에 강하게 지정하면 수정하기 불편할 수 있습니다. 처음에는 Canvas Slot 크기를 `1200 × 260`으로 사용하고, UI가 안정된 뒤 `Min Desired Height`만 남기는 방법을 권장합니다.

화면이 좁은 환경까지 고려한다면 고정 Width `1200` 대신 다음 구조를 사용할 수 있습니다.

```text
CanvasPanel
└─ DialogueContainer (Size Box: Max Desired Width 1200)
   └─ DialogueVerticalBox
```

이 경우 Canvas Slot의 좌우 여백을 확보하고 Size Box가 최대 1200까지만 커지도록 설정합니다.

### 4. DialogueVerticalBox (Vertical Box)

`DialogueVerticalBox`는 `DialogueContainer` 내부를 채웁니다.

- Horizontal Alignment: `Fill`
- Vertical Alignment: `Fill`
- Padding: `0`

Vertical Box는 자식들을 위에서 아래로 정렬하므로 직접 위치나 크기를 입력하지 않습니다.

### 5. SpeakerNamePanel (Border)

화자 이름 영역의 권장 크기입니다.

```text
Vertical Box Slot → Size: Auto
Horizontal Alignment: Left
Vertical Alignment: Center
Padding: Left 28, Top 8, Right 28, Bottom 8
최소 높이 권장: 44
```

Border의 Brush Color는 본문보다 조금 밝거나 진한 색을 사용합니다. 화자 이름을 본문과 같은 너비로 표시하고 싶다면 Horizontal Alignment를 `Fill`로 바꿉니다.

### 6. SpeakerNameText (Text Block)

```text
Font Size: 26
Justification: Left
Auto Wrap Text: 비활성화
Min Desired Width: 별도 설정 없음
```

실제 이름 색상은 `DialogueSpeakerProfile`의 `Name Color`가 적용됩니다.

### 7. DialogueBackground (Border)

본문 영역의 권장값입니다.

```text
Vertical Box Slot → Size: Fill
Horizontal Alignment: Fill
Vertical Alignment: Fill
Padding: Left 32, Top 22, Right 32, Bottom 22
```

배경색 예시:

```text
검은색 계열: R 0.02, G 0.02, B 0.03
Opacity 또는 Alpha: 0.75 ~ 0.9
```

Border가 Vertical Box의 남은 공간을 채우도록 Slot Size를 `Fill`로 설정합니다.

### 8. DialogueText (Text Block)

```text
Font Size: 30
Justification: Left
Auto Wrap Text: 활성화
Wrapping Policy: Default Wrapping
Line Height Percentage: 1.15 ~ 1.25
Horizontal Alignment: Fill
Vertical Alignment: Top
```

본문은 `DialogueBackground`의 Padding을 제외한 내부 너비에서 자동으로 줄바꿈됩니다. `DialogueText`에 고정 Width나 Height를 직접 입력하지 않는 것을 권장합니다.

### 9. AdvanceIndicator (Image)

진행 표시는 Vertical Box의 마지막 자식으로 둘 수 있지만, 본문 우측 아래에 겹쳐 표시하고 싶다면 `DialogueBackground` 내부에 `Overlay`를 추가하는 편이 좋습니다.

초보자용 기본 배치:

```text
Vertical Box Slot → Size: Auto
Horizontal Alignment: Right
Vertical Alignment: Center
Padding: Left 0, Top 6, Right 16, Bottom 8
Image Size: 24 × 24
```

대체 권장 계층:

```text
DialogueBackground (Border)
└─ DialogueOverlay (Overlay)
   ├─ DialogueText (Text Block)
   └─ AdvanceIndicator (Image, 우측 하단 정렬)
```

Overlay를 사용할 경우 `AdvanceIndicator`의 Overlay Slot을 다음과 같이 설정합니다.

```text
Horizontal Alignment: Right
Vertical Alignment: Bottom
Padding: Right 4, Bottom 2
Image Size: 24 × 24
```

### 최종 권장 화면 범위

1920×1080 기준:

- 대화창 너비: `1100 ~ 1300px`
- 대화창 높이: `220 ~ 300px`
- 화면 아래 여백: `60 ~ 100px`
- 화자 이름 Font Size: `24 ~ 28`
- 본문 Font Size: `28 ~ 34`
- 좌우 내부 Padding: `28 ~ 40px`

가장 무난한 시작값은 **크기 1200×260, 하단 여백 80, 화자 이름 26, 본문 30**입니다. Safe Zone을 유지하면 다양한 화면 비율에서도 UI가 화면 가장자리와 지나치게 붙는 것을 방지할 수 있습니다.

위치, 배경, 폰트, 크기와 애니메이션은 게임 분위기에 맞게 Widget Blueprint에서 자유롭게 변경할 수 있습니다.

사용 가능한 Blueprint 이벤트:

- `On Dialogue Opened`
- `On Dialogue Closed`
- `On Line Started`
- `On Line Completed`
- `On Speaker Changed`

Widget을 만든 뒤 Project Settings의 `Default Dialogue Widget Class`에 지정합니다.

## Text Sound Set 만들기

Content Browser에서 **Miscellaneous → Data Asset**을 선택하고 `DialogueTextSoundSet` 타입을 선택합니다.

권장 설정:

- `Sounds`: 짧은 타건음이나 전자음 여러 개
- `Volume Min / Max`: `0.85 / 1.0`
- `Pitch Min / Max`: `0.96 / 1.04`
- `Minimum Playback Interval`: `0.05`
- `Sound Every N Characters`: `2`
- `Skip Whitespace`: 활성화
- `Skip Punctuation`: 활성화

여러 Sound를 등록하면 같은 샘플이 연속 선택되는 빈도를 줄이면서 무작위로 재생합니다. 배열이 비어 있거나 null Sound가 포함되어 있어도 Dialogue는 정상 진행됩니다.

`bStopPreviousSound`를 활성화하면 새 출력음을 재생할 때 이전 출력음을 중단할 수 있습니다. Sound Concurrency 에셋은 선택 사항입니다.

## Speaker Profile 만들기

`DialogueSpeakerProfile` 타입의 Data Asset을 만듭니다.

예시 1:

```text
Asset Name: DA_Speaker_Student
Speaker Id: Student
Display Name: 학생
Name Color: 연한 파란색
Text Sound Set: 학생용 타건음 세트
```

예시 2:

```text
Asset Name: DA_Speaker_Player
Speaker Id: Player
Display Name: 주인공
Name Color: 흰색
Text Sound Set: 조금 낮은 Pitch의 타건음 세트
```

화자 Profile이 없는 Line도 정상 표시됩니다. 이름은 다음 순서로 결정됩니다.

1. Line의 `Speaker Name Override`
2. Speaker Profile의 `Display Name`
3. 빈 이름

이름이 비어 있으면 `SpeakerNamePanel`이 자동으로 숨겨집니다.

## Dialogue Sequence 만들기

`DialogueSequence` 타입의 Data Asset을 만들고 `Lines` 배열에 대사를 추가합니다.

샘플:

```text
1. Speaker: DA_Speaker_Student
   Dialogue Text: "선생님이 아직 오지 않았어."
   Reveal Mode: Word

2. Speaker: DA_Speaker_Player
   Dialogue Text: "조금 더 기다려 보자."
   Reveal Mode: Word

3. Speaker: DA_Speaker_Student
   Dialogue Text: "그런데…… 복도에서 무슨 소리가 들리지 않았어?"
   Reveal Mode: Word
```

세 번째 문장에서는 말줄임표에 `Ellipsis Delay`가 적용됩니다. 연속 공백, 탭과 줄바꿈은 원문 그대로 보존됩니다.

Line의 주요 설정:

- `Reveal Mode`: Word, Character 또는 Instant
- `Word/Character Interval Override`: 음수이면 Project Settings 기본값 사용
- `Start Delay`, `End Delay`: 문장 시작과 종료 지연
- `bWaitForPlayerInput`: 다음 진행 입력을 기다릴지 여부
- `bCanSkipReveal`: 출력 중 현재 문장 즉시 완성 허용
- `bAutoAdvance`: 자동 진행
- `Voice Sound`: 문장 시작 시 재생할 선택적 Voice
- `Text Sound Set Override`: Line 전용 출력음
- `Text Sound Trigger Mode`: 출력음 발생 규칙

## Blueprint에서 Dialogue 시작하기

일반적인 호출 흐름:

```text
Get Game Instance Subsystem
→ Dialogue Subsystem 선택
→ Start Dialogue
```

`Start Dialogue` 인자:

- `Sequence`: 재생할 Dialogue Sequence
- `Interaction Mode`: Modal, Overlay 또는 Cinematic
- `Player Controller`: 선택 사항이며 null이면 첫 Local PlayerController 사용
- `Existing Policy`: Reject 또는 Replace Current

기본 정책인 `Reject`는 이미 Dialogue가 실행 중이면 새 요청을 거부합니다. `Replace Current`는 기존 Dialogue에 취소 이벤트를 발생시키고 새 Dialogue를 시작합니다.

## 게임에서 처음 테스트하기

현재 프로젝트처럼 별도 Character나 입력 Blueprint가 없는 상태에서는 **Level Blueprint의 BeginPlay에서 Dialogue를 시작하는 방법**이 가장 간단합니다.

### 1. 테스트할 Level 열기

Dialogue를 확인할 Map을 연 다음 상단 Toolbar에서 다음 메뉴를 선택합니다.

```text
Blueprints
→ Open Level Blueprint
```

### 2. BeginPlay 흐름 만들기

Level Blueprint의 Event Graph에서 다음 노드를 연결합니다.

```text
Event BeginPlay
→ Delay (Duration: 0.2)
→ Start Dialogue
```

`Delay 0.2`는 Level과 Local PlayerController가 생성될 시간을 주기 위한 테스트용 값입니다.

`Start Dialogue`의 Target에는 Dialogue Subsystem이 필요합니다. 다음 순서로 노드를 만듭니다.

1. Event Graph 빈 곳을 우클릭합니다.
2. `Get Game Instance Subsystem`을 검색합니다.
3. 노드의 `Class`에서 `DialogueSubsystem`을 선택합니다.
4. 반환값을 `Start Dialogue`의 Target에 연결합니다.

엔진 버전에 따라 `Get Dialogue Subsystem`처럼 타입이 지정된 이름으로 표시될 수도 있습니다.

전체 연결 예시:

```text
Event BeginPlay
    │
    ▼
Delay (0.2)
    │
    ▼
Start Dialogue
    ▲ Target
    │
Get Game Instance Subsystem
Class: DialogueSubsystem
```

### 3. Start Dialogue 입력값 설정

`Start Dialogue` 노드에서 다음 값을 설정합니다.

```text
Sequence: 앞에서 만든 Dialogue Sequence Data Asset
Interaction Mode: Modal
Player Controller: Get Player Controller의 Return Value
Existing Policy: Reject
```

`Get Player Controller` 노드는 `Player Index = 0`으로 둡니다.

초보자용 전체 흐름:

```text
Event BeginPlay
→ Delay (0.2)
→ Start Dialogue
   ├─ Target: Get Game Instance Subsystem (DialogueSubsystem)
   ├─ Sequence: DA_Dialogue_Test
   ├─ Interaction Mode: Modal
   ├─ Player Controller: Get Player Controller (0)
   └─ Existing Policy: Reject
```

`Start Dialogue`의 Boolean 반환값은 시작 성공 여부입니다. 반환값을 `Branch`에 연결하고 False 쪽에 `Print String`을 연결하면 설정 오류를 쉽게 확인할 수 있습니다.

```text
Start Dialogue Return Value
→ Branch
   ├─ True: Print String "Dialogue 시작 성공"
   └─ False: Print String "Dialogue 시작 실패 - Output Log 확인"
```

### 4. 컴파일하고 실행하기

1. Level Blueprint에서 **Compile**을 누릅니다.
2. **Save**를 누릅니다.
3. Editor 상단의 **Play**를 누릅니다.
4. 0.2초 뒤 Dialogue Widget이 화면 하단 중앙에 표시되는지 확인합니다.

Modal 모드에서 다음 입력으로 진행할 수 있습니다.

- Left Mouse Button
- Space Bar
- Enter
- Gamepad Face Button Bottom

문장이 출력되는 도중 입력하면 현재 문장만 즉시 완성됩니다. 완성된 뒤 다시 입력하면 다음 문장으로 이동합니다. 마지막 문장 다음 입력에서는 Widget이 닫힙니다.

### 5. 키를 눌렀을 때 시작하고 싶을 경우

BeginPlay 자동 시작 대신 테스트 Key로 시작할 수도 있습니다. Level Blueprint에 Keyboard Event를 추가합니다.

```text
Keyboard T
→ Start Dialogue
```

`Start Dialogue`의 나머지 연결은 BeginPlay 예시와 같습니다. 다만 Level Blueprint가 Keyboard 입력을 받지 못하는 프로젝트 설정도 있으므로, 첫 검증은 BeginPlay 방식을 권장합니다.

### 6. 테스트 종료 이벤트 확인하기

Dialogue가 끝났는지 확인하려면 BeginPlay에서 Subsystem 반환값을 변수로 저장하고 `OnDialogueFinished`에 이벤트를 바인딩합니다.

간단한 확인 흐름:

```text
Dialogue Subsystem
→ Bind Event to OnDialogueFinished
→ Custom Event
→ Print String "Dialogue 종료"
```

강제로 중단했을 때는 `OnDialogueCancelled`가 발생합니다.

### 7. Dialogue가 보이지 않을 때 확인할 항목

다음 순서로 확인합니다.

1. **Project Settings → Game → Reusable Dialogue System**의 `Default Dialogue Widget Class`에 만든 WBP가 지정되어 있는지 확인합니다.
2. WBP의 부모 클래스가 `DialogueWidgetBase`인지 확인합니다.
3. WBP에 `SpeakerNameText`와 `DialogueText`라는 정확한 이름의 `Text Block`이 있는지 확인합니다.
4. 해당 Widget들의 **Is Variable**이 활성화되어 있는지 확인합니다.
5. Dialogue Sequence의 `Lines` 배열에 Line이 하나 이상 있는지 확인합니다.
6. `Start Dialogue`의 `Sequence`에 실제 Data Asset을 지정했는지 확인합니다.
7. **Window → Output Log**에서 `LogReusableDialogue` 메시지를 확인합니다.

대표적인 로그 의미:

```text
null or empty sequence
→ Sequence가 없거나 Lines 배열이 비어 있음

Default Dialogue Widget Class is not configured
→ Project Settings에 기본 WBP가 지정되지 않음

widget creation failed
→ WBP 생성 실패 또는 필수 BindWidget 구성 문제

another dialogue is active
→ 기존 Dialogue가 실행 중이며 Existing Policy가 Reject임
```

### 8. 최소 테스트 체크리스트

- 화자 이름이 본문 위에 표시되는가
- 본문이 기본적으로 단어 단위로 출력되는가
- 연속 공백과 줄바꿈이 유지되는가
- 출력 중 한 번 클릭하면 현재 문장만 완성되는가
- 다시 클릭하면 다음 문장으로 이동하는가
- 마지막 문장 뒤 Widget이 닫히는가
- Text Sound Set을 지정했을 때 글자가 표시되는 순간 소리가 나는가
- Text Sound Set을 비워도 Dialogue가 정상 진행되는가

## 진행 입력 연결

기본 Widget은 다음 입력을 처리할 수 있습니다.

- Left Mouse Button
- Space Bar
- Enter
- Gamepad Face Button Bottom

출력 중 진행 입력을 누르면 현재 문장만 즉시 완성합니다. 같은 입력으로 다음 문장까지 넘어가지 않습니다. 문장이 완성된 뒤 다시 입력하면 다음 문장으로 진행합니다.

Enhanced Input 프로젝트에서는 프로젝트 측 Input Action을 직접 연결합니다.

```text
IA_DialogueAdvance Triggered
→ Get Game Instance Subsystem
→ Dialogue Subsystem
→ Advance Dialogue
```

플러그인은 특정 Input Action이나 Input Mapping Context를 요구하지 않습니다.

## Interaction Mode

### Modal

Widget에 포커스를 주고 UI Only Input Mode로 전환합니다. 종료 시 Game Only Input Mode와 기존 마우스 커서 표시 상태를 복구합니다. 프로젝트에서 복잡한 입력 계층을 사용한다면 Overlay 모드와 프로젝트 측 입력 연동을 권장합니다.

### Overlay

게임 플레이 입력을 변경하지 않고 대사만 표시합니다. 이동 가능한 독백, 무전이나 상황 대사에 적합합니다.

### Cinematic

입력 상태를 변경하지 않습니다. Sequencer 또는 외부 게임 로직에서 `AdvanceDialogue`를 호출하는 용도입니다.

## 이벤트 연결

`UDialogueSubsystem`에서 다음 Delegate를 Blueprint에 바인딩할 수 있습니다.

- `OnDialogueStarted`
- `OnDialogueStateChanged`
- `OnLineStarted`
- `OnLineRevealCompleted`
- `OnLineAdvanced`
- `OnDialogueFinished`
- `OnDialogueCancelled`

예시:

```text
Bind Event to OnDialogueFinished
→ 문 열기
→ 퀘스트 진행
→ AI 행동 재개
```

## 현재 제한 사항

- Widget Blueprint와 샘플 Data Asset은 Unreal Editor에서 직접 만들어야 합니다.
- 선택지와 분기 그래프는 아직 포함되지 않습니다.
- 복잡한 결합 문자 전체를 다루는 Unicode grapheme 분할은 추후 확장 대상입니다. 현재 UTF-16 surrogate pair는 하나의 표시 토큰으로 보존합니다.
- Unreal은 모든 프로젝트 전용 입력 스택을 일반적으로 백업하는 API를 제공하지 않으므로, 복잡한 입력 시스템에서는 Overlay 또는 Cinematic 모드 사용을 권장합니다.
- Voice 길이 기반 자동 진행과 저장·불러오기는 후속 구현 대상입니다.
