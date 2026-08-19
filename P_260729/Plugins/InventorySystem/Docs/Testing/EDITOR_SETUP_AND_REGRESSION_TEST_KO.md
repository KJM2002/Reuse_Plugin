---
title: "인벤토리 플러그인 에디터 최종 세팅 및 회귀 테스트 가이드"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor에서 테스트 절차를 다시 실행하지 않음"
---

# 인벤토리 플러그인 에디터 최종 세팅 및 회귀 테스트 가이드

이 문서는 `BaseUpgrade` 프로젝트에서 `InventorySystem` 플러그인을 다시 설정하거나 다른 프로젝트에 이식할 때 같은 문제를 반복하지 않기 위한 최종 작업 지침이다.

다음 내용을 한 문서에서 확인할 수 있다.

- C++와 Widget Blueprint의 책임 구분
- Player Character와 PlayerController의 필수 Component 설정
- `WBP_Inventory`, `WBP_InventorySlot`, `WBP_PickupNotification`의 정확한 부모 클래스와 계층
- `Is Variable`을 켜야 하는 Widget
- 아이템 획득, 조사, 버리기, 재획득 설정
- 에디터에서 반드시 수행해야 하는 테스트 순서
- 지금까지 발생한 시행착오, 원인과 최종 해결 방식

---

## 1. 현재 최종 구조

```text
BP_FirstPersonCharacter
└─ InventoryComponent

BP_FirstPersonPlayerController
└─ InventoryUIComponent
   ├─ Inventory Widget Class: WBP_Inventory
   ├─ Pickup Notification Widget Class: WBP_PickupNotification
   ├─ Toggle Inventory Action: IA_Inventory
   └─ Toggle Input Mapping Context: IMC_Default

InventoryItemDefinition
├─ 이름, 설명, 아이콘, 조사 Mesh
├─ 사용/버리기/조사 가능 여부
└─ 월드에 버릴 때 생성할 World Item Class

InventoryComponent
├─ 실제 Slot 데이터와 수량 관리
├─ 획득·사용·버리기 처리
└─ OnItemsReceived 알림 발생

InventoryUIComponent
├─ 현재 PlayerController의 Pawn에서 InventoryComponent 탐색
├─ 인벤토리 열기/닫기 및 입력 차단
├─ 획득 알림 Widget 생성
└─ Widget Blueprint에는 데이터만 전달
```

핵심 원칙은 다음과 같다.

```text
C++
→ 데이터, 규칙, 이벤트 연결, Widget 생성과 갱신

Widget Blueprint
→ 위치, 크기, 색상, 폰트, 이미지 배치, 애니메이션
```

기본 동작을 위해 Blueprint에서 `RefreshSlot`, Grid 생성 Loop 또는 Button 클릭 함수를 만들지 않는다.

---

## 2. C++ 수정 후 에디터에 확실히 적용하는 방법

플러그인 DLL이 실행 중인 Unreal Editor에 의해 잠기면 C++ 컴파일이 성공해도 새 DLL이 적용되지 않는다. `LNK1104`가 발생한 상태에서 PIE만 다시 실행해서는 새 코드가 반영되지 않는다.

### 권장 Cold Build 절차

1. Unreal Editor를 완전히 종료한다.
2. 작업 관리자에 `UnrealEditor.exe`가 남아 있지 않은지 확인한다.
3. 다음 Editor Target을 빌드한다.

```powershell
& 'C:\Program Files\Epic Games\UE_5.7\Engine\Build\BatchFiles\Build.bat' BaseUpgradeEditor Win64 Development -Project='C:\Users\User\Documents\Unreal Projects\BaseUpgrade\BaseUpgrade.uproject' -WaitMutex -NoHotReloadFromIDE -architecture=x64
```

4. 결과가 `Result: Succeeded`인지 확인한다.
5. Unreal Editor를 다시 실행한다.
6. 변경된 Widget Blueprint를 열어 Compile하고 Save한다.
7. PIE를 새로 시작한다.

### 빌드 결과 판정

| 결과 | 의미 | 처리 |
|---|---|---|
| `Result: Succeeded` | Editor DLL까지 교체됨 | 에디터 실행 후 테스트 |
| `LNK1104 ... UnrealEditor-InventorySystem.dll` | 에디터가 DLL을 사용 중 | 에디터 완전 종료 후 재빌드 |
| UHT의 BindWidget 오류 | WBP 이름 문제가 아니라 C++ Header 문제일 수 있음 | 첫 컴파일 오류부터 확인 |
| Widget Blueprint Compile Error | 필수 Widget 이름 또는 타입 불일치 | 이 문서의 Widget 표와 대조 |

Live Coding과 Hot Reload만 반복하면 이전 DLL과 새 Blueprint Class가 섞일 수 있다. UPROPERTY 또는 BindWidget 구조를 바꾼 날에는 Cold Build를 기준으로 검증한다.

---

## 3. Project Settings 최종값

경로:

```text
Edit → Project Settings → Game → Inventory System
```

현재 프로젝트 기준 권장값:

```text
Default Inventory Widget Class = /InventorySystem/Widget/WBP_Inventory
Default Toggle Inventory Action = /InventorySystem/Input/IA_Inventory
Default Max Inventory Slots     = 20
Default World Item Class        = ReuseInspectableInventoryPickup

Default Drop Forward Distance   = 125 cm
Default Drop Trace Height       = 100 cm
Default Drop Trace Depth        = 300 cm
```

`Default Toggle Inventory Mapping Context`가 비어 있다면 `BP_FirstPersonPlayerController`의 `InventoryUIComponent`에 `IMC_Default`를 직접 지정한다.

---

## 4. Player Character 설정

대상:

```text
/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter
```

### InventoryComponent

Components에서 `Inventory Component`를 추가한다.

```text
Component Name      = Inventory
Max Inventory Slots = 20
```

현재 프로젝트는 Inventory 데이터가 Character에 있고 UI Coordinator는 PlayerController에 있다. 이 분리는 정상 구조다.

JM 상호작용을 사용할 경우 Character에 프로젝트의 `JMInteractionComponent`도 있어야 한다.

---

## 5. PlayerController 설정

대상:

```text
/Game/FirstPerson/Blueprints/BP_FirstPersonPlayerController
```

Components에서 `Inventory UI Component`를 추가하고 다음 값을 설정한다.

```text
Inventory Widget Class             = WBP_Inventory
Toggle Inventory Action            = IA_Inventory
Toggle Input Mapping Context       = IMC_Default
Inventory Component                = None
Pickup Notification Widget Class   = WBP_PickupNotification
Pickup Notification Duration       = 2.0
```

`Inventory Component`를 `None`으로 두는 이유는 PlayerController BeginPlay 이후 현재 Pawn에서 자동 탐색하기 때문이다. 특정 Runtime Actor 인스턴스를 Blueprint Class Default에 직접 연결하지 않는다.

Inspector를 사용할 경우:

```text
Inspector Bridge = ReuseInventoryInspectorBridge
```

### 입력 연결

`IMC_Default`에서 `IA_Inventory`를 Tab 또는 원하는 Key에 매핑한다.

Blueprint에서 직접 연결하는 경우:

```text
IA_Inventory Started
→ InventoryUIComponent.ToggleInventory
```

프로젝트 코드가 `BindEnhancedInput`을 호출하고 있다면 같은 Action을 Blueprint에서 중복 연결하지 않는다. 중복 연결하면 한 번 눌렀을 때 열고 바로 닫히는 현상이 생길 수 있다.

---

## 6. WBP_InventorySlot 최종 구조

부모 클래스:

```text
InventorySlotWidgetBase
```

권장 계층:

```text
WBP_InventorySlot
└─ SizeBox_Slot
   └─ Border_SlotPadding
      └─ Button_Select
         └─ Overlay_Slot
            ├─ Border_Background
            ├─ SizeBox_Icon
            │  └─ ScaleBox_Icon
            │     └─ Image_ItemIcon
            ├─ Border_Unavailable
            ├─ Image_Selection
            └─ Text_Quantity
```

### 필수 이름과 타입

| 이름 | 타입 | 필수 | Is Variable |
|---|---|---:|---:|
| `Button_Select` | Button | 예 | 체크 |
| `Image_ItemIcon` | Image | 예 | 체크 |
| `Text_Quantity` | Text Block | 예 | 체크 |
| `SizeBox_Slot` | Size Box | 권장 | 체크 |
| `Overlay_Slot` | Overlay | 권장 | 체크 |
| `Border_Background` | Border | 선택 | 사용 시 체크 |
| `SizeBox_Icon` | Size Box | 권장 | 체크 |
| `ScaleBox_Icon` | Scale Box | 권장 | 체크 |
| `Image_Selection` | Image | 선택 | 사용 시 체크 |
| `Border_Unavailable` | Border | 선택 | 사용 시 체크 |

### 크기와 비율

```text
SizeBox_Slot     = 176 × 176
Button_Select    = 실질 영역 160 × 160
SizeBox_Icon     = 96 × 96
ScaleBox_Icon    = Scale To Fit / Both
Image_ItemIcon   = Draw As Image
```

`Image_ItemIcon`을 Overlay에 직접 Fill로 배치하지 않는다. 512×512 Texture라도 Slot의 가로·세로 비율이 다르면 찌그러지거나 프레임 밖으로 튀어나온다. `SizeBox_Icon + ScaleBox_Icon`이 아이콘 안전 영역이다.

### 그리기 순서

Overlay에서 아래에 있는 Widget이 화면 앞쪽에 그려진다.

```text
배경 Grid
→ 아이콘
→ 사용 불가 음영
→ 선택 테두리
→ 수량 Text
```

선택 표시 Texture는 Border보다 `Image_Selection`을 사용한다. Texture를 Border Brush에 넣는 과정에서 Draw As나 Margin 설정 때문에 표시되지 않는 문제를 피할 수 있다.

---

## 7. WBP_Inventory 최종 구조

부모 클래스:

```text
InventoryWidgetBase
```

Class Defaults:

```text
Slot Widget Class = WBP_InventorySlot
Grid Column Count = 5
Show Empty Slots  = true
Is Focusable      = true
```

권장 계층:

```text
WBP_Inventory
└─ CanvasPanel_Root
   ├─ Border_DimBackground
   └─ SizeBox_InventoryWindow
      └─ Border_InventoryWindow
         └─ VerticalBox_Main
            ├─ Overlay_Header
            │  ├─ Text_InventoryTitle
            │  └─ Button_Close
            └─ HorizontalBox_Content
               ├─ SizeBox_ItemArea
               │  └─ ScrollBox_Items
               │     └─ UniformGridPanel_Items
               ├─ Spacer_Content
               └─ SizeBox_DetailArea
                  └─ VerticalBox_Detail
                     ├─ Image_SelectedIcon
                     ├─ Text_SelectedName
                     ├─ Text_SelectedQuantity
                     ├─ ScrollBox_Description
                     │  └─ Text_SelectedDescription
                     ├─ Text_DisabledReason
                     ├─ Spacer_Detail
                     └─ HorizontalBox_Actions
                        ├─ Button_Use
                        ├─ Button_Drop
                        └─ Button_Inspect
```

### C++ 필수 Widget

| 이름 | 타입 | 필수 | Is Variable |
|---|---|---:|---:|
| `UniformGridPanel_Items` | Uniform Grid Panel | 예 | 체크 |
| `Image_SelectedIcon` | Image | 예 | 체크 |
| `Text_SelectedName` | Text Block | 예 | 체크 |
| `Text_SelectedQuantity` | Text Block | 예 | 체크 |
| `Text_SelectedDescription` | Text Block | 예 | 체크 |
| `Text_DisabledReason` | Text Block | 아니요 | 사용 시 체크 |
| `Button_Use` | Button | 예 | 체크 |
| `Button_Drop` | Button | 예 | 체크 |
| `Button_Inspect` | Button | 예 | 체크 |
| `Button_Close` | Button | 예 | 체크 |

### Grid 간격이 과도하게 벌어지지 않게 하는 값

```text
UniformGridPanel_Items의 ScrollBox Slot
Horizontal Alignment = Left
Vertical Alignment   = Top

WBP_InventorySlot
SizeBox_Slot          = 176 × 176
Border_SlotPadding    = 8
Grid Column Count     = 5
Show Empty Slots      = true
```

Grid를 `Fill`로 설정하면 남는 폭이 Cell 사이로 퍼져 간격이 커질 수 있다. 빈 Grid를 고정된 형태로 보여 주려면 `Show Empty Slots`를 켠다.

---

## 8. WBP_PickupNotification 최종 구조

부모 클래스:

```text
InventoryPickupNotificationWidget
```

최종 계층:

```text
WBP_PickupNotification
└─ CanvasPanel_Root
   └─ SizeBox_Root
      └─ Border_Background
         └─ HorizontalBox_Content
            ├─ SizeBox_Icon
            │  └─ Image_ItemIcon
            ├─ Spacer_IconText
            └─ Text_Message
```

알림 WBP에서는 `CanvasPanel_Root`가 최상위여야 한다. C++은 알림 WBP를 전체 화면으로 AddToViewport하고, 실제 알림 박스의 위치와 크기는 Canvas Designer에서 관리한다.

### C++ 연결 Widget

| 이름 | 타입 | 필수 | Is Variable | 역할 |
|---|---|---:|---:|---|
| `Text_Message` | Text Block | 권장 | 체크 | `아이템 이름 x 수량` 표시 |
| `Image_ItemIcon` | Image | 권장 | 체크 | Item Definition의 Icon 표시 |
| `SizeBox_Icon` | Size Box | 권장 | 체크 | 아이콘이 없을 때 빈 영역까지 숨김 |

`CanvasPanel_Root`, `SizeBox_Root`, `Border_Background`, `HorizontalBox_Content`, `Spacer_IconText`는 디자인용이므로 이름을 변경해도 된다.

### 권장 외형값

```text
SizeBox_Root Width Override  = 360
SizeBox_Root Height Override = 48
SizeBox_Root Auto Size       = true

SizeBox_Icon Width Override  = 32
SizeBox_Icon Height Override = 32
Image_ItemIcon Stretch       = Scale To Fit

Text_Message Font Size       = 14~16
Text_Message Auto Wrap       = 필요 시 활성화
Text_Message Overflow Policy = Ellipsis
```

### 위치 변경 방법

PlayerController에서 Viewport Size를 입력하지 않는다. `SizeBox_Root`의 Canvas Slot만 수정한다.

상단 중앙 예시:

```text
Anchors     = Top Center
Alignment   = (0.5, 0.0)
Position    = (0, 60)
Auto Size   = true
```

오른쪽 위 예시:

```text
Anchors     = Top Right
Alignment   = (1.0, 0.0)
Position    = (-40, 40)
Auto Size   = true
```

화면 중앙 예시:

```text
Anchors     = Center
Alignment   = (0.5, 0.5)
Position    = (0, 0)
Auto Size   = true
```

알림 위치를 바꿀 때는 WBP Designer에서 `SizeBox_Root`를 이동하고 Compile/Save한다.

### 알림 아이콘 데이터

각 `InventoryItemDefinition`에서 다음 값을 지정한다.

```text
Presentation → Icon = 사용할 Texture2D
```

C++은 획득 시 Icon을 로드하여 `Image_ItemIcon`에 넣는다. Icon이 비어 있으면 `Image_ItemIcon`과 `SizeBox_Icon`을 Collapsed로 변경한다.

### 선택 애니메이션

Event Graph에서 선택적으로 다음 Event를 사용한다.

```text
Event On Notification Shown
→ Play Animation
```

기본 표시에는 Event Graph가 필요하지 않다.

---

## 9. 아이템 데이터 에셋 체크리스트

Old Key 예시:

```text
Item Id        = OldKey
Display Name   = 오래된 열쇠
Description    = 아이템 설명
Icon           = 열쇠 Texture2D
Inspect Mesh   = SM_OldKey
World Item Class = BP_Item_OldKey

Can Use        = false
Can Drop       = true
Can Inspect    = true
Stackable      = false
```

알림 문구는 다음 형식이다.

```text
오래된 열쇠 x 1
```

한 번의 `AddItemDetailed` 호출에서 실제로 추가된 총수량만 한 번 표시한다. 인벤토리가 가득 차서 아무것도 추가되지 않았다면 알림이 발생하지 않는 것이 정상이다.

---

## 10. 월드 Pickup과 JMInspectable 설정

JM 조사 후 획득하는 프로젝트용 Pickup은 다음 부모를 사용한다.

```text
ReuseInspectableInventoryPickup
```

`BP_Item_OldKey` 권장값:

```text
Item Definition              = DA_Inventory_OldKey
Quantity                     = 1
Interaction Prompt           = 조사하기
Interaction Priority         = 10
Inspect Before Pickup        = true
Pickup After Inspection      = true
Fallback To Immediate Pickup = true
Snap To Ground When Dropped  = true
Ground Clearance             = 1.0
```

`JMInspectableComponent`를 사용하는 Blueprint에서는 다음도 확인한다.

```text
Inspection Data              = DA_OldKey_Inspection
Inspection Enabled           = true
Block Player Input During Inspection = true
```

`Fallback To Immediate Pickup = true`이면 JMInspectableComponent가 없는 일반 Pickup도 즉시 획득할 수 있다. Inventory Plugin의 Integration 계층이 ItemInspector에 명시적으로 의존하며 두 플러그인을 함께 복사해야 한다.

### Drop 후 다시 상호작용하기 위한 Class 선택

Class 선택 순서:

```text
InventoryItemDefinition.WorldItemClass
→ Project Settings의 DefaultWorldItemClass
→ InventoryWorldItemPickup 기본 C++ Class
```

JM 상호작용이 필요한 아이템은 Item Definition의 `World Item Class`를 `BP_Item_OldKey`처럼 JM Adapter를 상속한 Blueprint로 설정한다.

### 바닥 부착

Drop Actor는 다음 순서로 바닥에 맞춘다.

```text
Visibility Trace로 바닥 탐색
→ Item Mesh Bounds 갱신
→ Mesh 최하단 높이 계산
→ 바닥 Impact Point + Ground Clearance에 최하단 배치
```

Actor Pivot이 Mesh 중앙에 있어도 Bounds 기준으로 바닥에 맞는다. 떠 있으면 `Ground Clearance`를 먼저 확인하고, Mesh 자체에 큰 빈 Bounds가 없는지도 확인한다.

---

## 11. 에디터 회귀 테스트 절차

다음 순서를 바꾸지 않고 한 번에 검증한다.

### 준비

1. Cold Build 후 에디터를 실행한다.
2. `WBP_InventorySlot`, `WBP_Inventory`, `WBP_PickupNotification`을 각각 Compile/Save한다.
3. `BP_FirstPersonCharacter`, `BP_FirstPersonPlayerController`, `BP_Item_OldKey`를 Compile/Save한다.
4. Output Log를 연다.
5. 테스트 Level에 Old Key Pickup을 최소 2개 배치한다.

### 테스트 A: 입력과 인벤토리

1. PIE를 시작한다.
2. Tab을 눌러 인벤토리를 연다.
3. 이동, 시점, 점프가 모두 차단되는지 확인한다.
4. Tab을 다시 눌러 닫히는지 확인한다.
5. 닫은 뒤 이동, 시점, 점프가 복원되는지 확인한다.

### 테스트 B: 아이템 획득과 알림

1. Old Key와 상호작용한다.
2. 조사 설정이 켜져 있으면 Inspector가 열리는지 확인한다.
3. Inspector를 정상 종료한다.
4. 월드 아이템이 사라지는지 확인한다.
5. WBP에서 지정한 위치에 알림이 표시되는지 확인한다.
6. 알림에 열쇠 아이콘과 `오래된 열쇠 x 1`이 표시되는지 확인한다.
7. 약 2초 후 알림이 사라지는지 확인한다.

### 테스트 C: Grid와 아이콘 비율

1. 인벤토리를 연다.
2. 5열 고정 Grid와 빈 Slot이 표시되는지 확인한다.
3. 획득한 Slot이 실제 Slot Index 위치에 채워지는지 확인한다.
4. 아이콘이 찌그러지지 않고 96×96 안전 영역 안에 들어오는지 확인한다.
5. Slot 선택 테두리가 아이콘과 수량보다 의도한 순서로 보이는지 확인한다.
6. 상세 영역의 이름, 수량, 설명과 아이콘이 갱신되는지 확인한다.

### 테스트 D: 버리기와 재획득

1. Old Key Slot을 선택한다.
2. Drop을 누른다.
3. Pickup Actor가 플레이어 앞 바닥에 생성되는지 확인한다.
4. Actor가 공중에 뜨지 않는지 확인한다.
5. 버린 Actor와 다시 상호작용할 수 있는지 확인한다.
6. 다시 획득할 때 알림이 다시 표시되는지 확인한다.

### 테스트 E: 해상도

다음 크기에서 PIE 또는 Standalone을 확인한다.

```text
1280 × 720
1920 × 1080
2560 × 1440
```

각 해상도에서 다음을 확인한다.

- 알림이 화면 밖으로 잘리지 않는다.
- Canvas Anchor 기준 위치가 유지된다.
- Inventory Window가 화면 밖으로 나가지 않는다.
- Slot Grid의 간격이 늘어나지 않는다.
- Text가 Border 밖으로 넘치지 않는다.

---

## 12. Output Log 판별표

정상 획득 시 다음 로그가 순서대로 표시된다.

```text
Inventory pickup notifications bound
Inventory received item
Inventory pickup notification event received
Pickup notification displayed
```

| 마지막으로 보이는 로그 | 의미 | 확인할 항목 |
|---|---|---|
| Bind 로그 없음 | UI Component가 Inventory에 연결되지 않음 | PlayerController Component, 현재 Pawn, Cold Build |
| `Inventory received item` 없음 | AddItemDetailed까지 도달하지 않음 | 상호작용, Inventory 용량, Item Definition |
| Received는 있고 notification event 없음 | Delegate 연결 문제 | PlayerController/Pawn 소유 구조, 최신 DLL |
| `notification displayed`까지 있음 | 데이터와 생성은 정상, 순수 WBP 배치 문제 | WBP Class, Canvas Anchor, Visibility, Z Order |
| displayed의 class가 Native Class | WBP Class 미지정 | PlayerController의 Pickup Notification Widget Class |
| displayed의 class가 `WBP_PickupNotification_C` | WBP가 실제 생성됨 | WBP 내부 위치와 Widget 이름 |

---

## 13. 시행착오와 최종 결론

### 13.1 Border에 선택 Texture를 넣으려 했으나 표시되지 않음

- 원인: Border Brush의 Draw As, Margin, Tint 설정이 선택 프레임 Texture와 맞지 않았다.
- 최종 해결: `Image_Selection`을 Overlay에 배치하고 선택 상태에 따라 Visibility만 변경한다.

### 13.2 Blueprint에서 Refresh 함수 제작이 너무 복잡함

- 원인: 데이터 갱신과 디자인을 Blueprint에 동시에 맡기려 했다.
- 최종 해결: C++ 부모 클래스가 갱신과 Button Delegate를 담당하고 WBP는 정확한 이름의 Widget만 배치한다.

### 13.3 인벤토리를 열면 이동은 막히지만 점프가 됨

- 원인: Move/Look 입력만 무시하고 Pawn Action Input은 살아 있었다.
- 최종 해결: 인벤토리가 열린 동안 Pawn Input도 비활성화하고 닫을 때 원래 상태로 복원한다.

### 13.4 Tab으로 열리지만 닫히지 않음

- 원인: UI Focus 이후 Tab이 Navigation 입력으로 소비되거나 Pawn Input이 비활성화됐다.
- 최종 해결: Widget Preview Key에서 현재 Toggle Action에 매핑된 Key와 ESC를 처리한다. WBP는 `Is Focusable`을 켠다.

### 13.5 PlayerController에서 알림 Delegate가 연결되지 않음

- 원인: PlayerController BeginPlay가 Pawn Possess보다 먼저 실행돼 Character의 InventoryComponent를 찾지 못했다.
- 최종 해결: UI Component가 주기적으로 현재 Pawn을 확인하고 InventoryComponent가 바뀌면 Delegate를 다시 연결한다.

### 13.6 알림 로그는 나오지만 화면에 보이지 않음

- 원인 1: Native `RebuildWidget`이 WBP WidgetTree를 무시했다.
- 해결 1: WBP Root가 있으면 `Super::RebuildWidget()`을 사용하고, 순수 C++ Class일 때만 기본 Slate UI를 만든다.
- 원인 2: 전체 화면 Canvas WBP에 360×48 또는 420×54 Viewport Size를 강제해 내부 Widget이 잘렸다.
- 해결 2: 알림 WBP는 전체 화면으로 추가하고 위치와 크기는 WBP Canvas에서만 관리한다.

### 13.7 알림 위치 설정이 PlayerController와 WBP에 나뉘어 유지보수가 어려움

- 원인: Viewport Size, Anchor, Alignment, Position을 UI Component 속성으로 노출했다.
- 최종 해결: 해당 위치 속성을 제거했다. PlayerController는 Widget Class와 Duration만 관리하고 위치는 WBP Canvas Slot이 전담한다.

### 13.8 아이콘이 찌그러지거나 선택 프레임 밖으로 튀어나옴

- 원인: Image를 비정사각형 부모에 Fill로 넣거나 원본 Texture 크기를 Slot 크기로 오해했다.
- 최종 해결: 원본 해상도와 무관하게 `SizeBox_Icon + ScaleBox_Icon(Scale To Fit)`으로 표시 영역과 비율을 고정한다.

### 13.9 Grid Cell 사이 간격이 지나치게 큼

- 원인: Uniform Grid의 부모 Slot이 Fill이라 남는 공간이 Grid 폭에 반영됐다.
- 최종 해결: ScrollBox Slot을 Left/Top으로 두고 Slot 크기와 내부 Padding으로 간격을 결정한다. `Show Empty Slots`로 고정 Grid를 만든다.

### 13.10 Drop 후 상호작용할 수 없음

- 원인: Drop 시 일반 C++ Pickup Class가 생성되어 프로젝트의 JM Adapter가 없었다.
- 최종 해결: Item Definition의 `WorldItemClass` 또는 Default World Item Class에 `ReuseInspectableInventoryPickup` 계열을 지정한다.

### 13.11 Drop Actor가 공중에 뜸

- 원인: Actor Pivot 위치만 바닥 Impact Point에 맞췄다.
- 최종 해결: Mesh Bounds의 최하단을 계산하여 바닥과 `Ground Clearance`에 맞춘다.

### 13.12 에디터 빌드가 됐다고 생각했지만 변경사항이 적용되지 않음

- 원인: 컴파일은 끝났지만 실행 중인 에디터가 DLL을 잠가 Link가 실패했다.
- 최종 해결: `LNK1104`는 성공이 아니다. 에디터 완전 종료 후 Editor Target을 Cold Build한다.

### 13.13 선택 전에는 수량이 아이콘 뒤에 가리고 선택 후에만 정상 위치에 표시됨

- 원인: 이전 Slot WBP에 아이콘용 `SizeBox_Icon`과 `ScaleBox_Icon`이 없을 때 C++이 안전 영역을 런타임에 만들면서 아이콘을 Overlay의 마지막 자식으로 추가했다. 이 때문에 아이콘이 `Text_Quantity`보다 앞에서 그려졌다.
- 최종 해결: C++이 Overlay 순서를 `배경 → 아이콘 → 사용 불가 → 선택 테두리 → 수량`으로 다시 정렬한다. `Text_Quantity`는 선택 여부와 관계없이 `Right/Bottom`, Right `12`, Bottom `10` Padding을 사용한다.
- 권장 WBP: 런타임 보정에 의존하지 않도록 `SizeBox_Icon → ScaleBox_Icon → Image_ItemIcon` 계층을 WBP에 직접 만들고 `Text_Quantity`를 Overlay의 마지막 자식으로 둔다.

---

## 14. 최종 완료 체크리스트

아래 항목이 모두 체크되어야 작업 완료로 판단한다.

```text
[ ] BaseUpgradeEditor Development 빌드 성공
[ ] WBP_InventorySlot 부모가 InventorySlotWidgetBase
[ ] WBP_Inventory 부모가 InventoryWidgetBase
[ ] WBP_PickupNotification 부모가 InventoryPickupNotificationWidget
[ ] 모든 BindWidget 이름과 타입 일치
[ ] 필요한 Widget의 Is Variable 체크
[ ] Character에 InventoryComponent 존재
[ ] PlayerController에 InventoryUIComponent 존재
[ ] InventoryWidgetClass와 PickupNotificationWidgetClass 지정
[ ] IA_Inventory와 IMC_Default 지정
[ ] Tab 열기/닫기 정상
[ ] 인벤토리 중 이동/시점/점프 차단
[ ] 획득 알림 Text와 Icon 표시
[ ] 고정 Grid와 아이콘 비율 정상
[ ] 선택 여부와 관계없이 수량이 우측 하단 최상위에 표시
[ ] Drop Actor 바닥 부착
[ ] Drop Actor 재상호작용 가능
[ ] 1280×720, 1920×1080에서 UI 잘림 없음
[ ] Output Log에 Error와 Ensure 없음
```

이 체크리스트를 새 프로젝트 이식, UI 리디자인, 입력 변경, Pickup Class 변경 후마다 회귀 테스트 기준으로 사용한다.
