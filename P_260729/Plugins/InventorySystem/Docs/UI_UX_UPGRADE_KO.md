# Inventory UI/UX 0.5 적용 가이드

UMG Designer에서 직접 배치할 때는
[`WIDGET_LAYOUT_GUIDE_KO.md`](WIDGET_LAYOUT_GUIDE_KO.md)를 기준으로 한다.

## 유지한 구조

- 데이터와 슬롯 규칙: `UInventoryComponent`
- Item Data, Stack, Capacity, Save Entry
- Use / Drop / Inspect와 Inspector Bridge
- Enhanced Input Action과 Mapping Context
- Delegate 기반 갱신(인벤토리 데이터 Polling Tick 없음)

## 바뀐 Presentation

기본 `UInventoryWidgetBase`가 다음 Widget Tree를 네이티브로 만든다.

```text
Overlay_Root
├─ Border_BackgroundDim
└─ SizeBox_InventoryWindow (1220×760)
   └─ Border_InventoryWindow
      └─ VerticalBox_Main
         ├─ Header: 인벤토리 / 현재 슬롯 수 / 최대 슬롯 수 / 닫기
         ├─ Content
         │  ├─ LeftInventoryPanel / UniformGridPanel_Items
         │  └─ ItemDetailPanel
         │     ├─ Image_SelectedIcon
         │     ├─ Text_SelectedName
         │     ├─ Text_SelectedCategory
         │     ├─ Text_SelectedQuantity
         │     ├─ Text_SelectedDescription
         │     ├─ Text_SelectedFlavor
         │     ├─ Text_DisabledReason
         │     └─ HorizontalBox_Actions
         └─ Footer: ENTER 선택 / ESC 닫기
```

기본 슬롯은 96×96, Uniform Grid Cell은 108×108이므로 슬롯 사이 여백은 12px이다.
Slot 내부 아이콘 안전 영역은 72×72이다. DPI Scaling은 Unreal Viewport Scale을
그대로 따르며 절대 화면 좌표나 특정 해상도를 하드코딩하지 않는다.

## 액션 표시 규칙

- 사용: `bCanUse`
- 버리기: `bCanDrop`
- 조사: `bCanInspect && InspectMesh가 지정됨`
- 사용할 수 없는 액션은 Disabled로 남기지 않고 `Collapsed`
- 선택이 없으면 전체 Action Panel을 `Collapsed`

Item Definition의 `CategoryText`와 `FlavorText`는 선택적 Presentation Metadata다.
기존 Asset은 두 값이 비어 있어도 정상 동작하며, 비어 있는 행은 자동으로 숨긴다.

## 선택 규칙

1. 이전 `InstanceId`가 유효하면 유지한다.
2. 없으면 첫 유효 슬롯을 선택한다.
3. 선택 아이템이 제거되면 남아 있는 첫 유효 슬롯으로 이동한다.
4. 빈 Inventory는 Selection을 `INDEX_NONE`으로 만들고 Empty Detail을 표시한다.
5. 빈 슬롯 클릭은 이전 상세 내용을 즉시 비운다.

## 전환과 입력

- Open: 0.22초, Opacity 0→1, Scale 0.975→1, Y 12→0
- Close: 0.15초, 역방향
- Close가 끝나기 전에는 Widget을 제거하거나 Gameplay Input을 복구하지 않는다.
- Close 중 Toggle을 다시 누르면 같은 Widget에서 Open 방향으로 반전한다.
- 기존 Move/Look/Pawn Input 상태와 Mouse Cursor 상태를 저장·복구한다.
- UI 상태는 Inventory Delegate로 갱신하며 매 프레임 Polling하지 않는다.
  `NativeTick`은 짧은 전환 보간 중에만 시각 Transform을 계산한다.

## HUD 숨김/복원

열기/닫기 시 다음 공통 이벤트가 발행된다.

```text
Event.UI.Modal.Opened
Event.UI.Modal.Closed
```

Context Tag:

```text
Event.UI.Inventory.Opened
Event.UI.Inventory.Closed
```

`JMObjectiveUISubsystem`과 `UJMInteractionComponent`는 이를 자동 구독하므로 Objective와
Interaction Prompt는 Inventory 동안 숨겨지고 닫힌 뒤 복원된다.

프로젝트 전용 `Content/HUD/WB_Dot` Crosshair는 바이너리 Blueprint라 자동 수정하지
않았다. `BP_FirstPersonPlayerController`에서 `InventoryUIComponent`의
`On Inventory Presentation Changed`에 한 번 Bind하고:

```text
bInventoryVisible == true  -> WB_Dot Set Visibility(Collapsed)
bInventoryVisible == false -> WB_Dot Set Visibility(Self Hit Test Invisible)
```

로 연결한다. 또는 `JMGameplayEventListenerComponent`에서 두 Modal Tag를 구독해도 된다.
특정 Inventory/HUD 클래스로 Cast할 필요는 없다.

## 기존 WBP를 계속 사용할 때

Project Settings > JM Plugins > Inventory > Default Inventory Widget Class에
`WBP_Inventory`를 다시 지정할 수 있다. 기존 필수 BindWidget 이름은 유지된다.
플러그인의 기존 기본 WBP를 의도적으로 계속 사용하려면
`Upgrade Legacy Default Widget To Native`를 끈다. 프로젝트 전용 Custom WBP는 이
옵션과 관계없이 보존된다.
새 기능을 모두 표현하려면 다음 선택 Widget을 추가한다.

- `Text_Capacity`
- `Text_SelectedCategory`
- `Text_SelectedFlavor`
- `Text_EmptyHint`
- `HorizontalBox_Actions`
- `Overlay_Root`
- `Border_BackgroundDim`
- `Border_InventoryWindow`

이들은 모두 Optional이므로 추가 전에도 컴파일과 기존 UI 동작은 유지된다. 기존 WBP의
`WBP_InventorySlot` Class Default에서 `Slot Display Size=96`,
`Icon Display Size=72`로 바꾸고 Grid Cell을 108로 맞춘다.

## Sound

Project Settings에서 Open, Close, Slot Hover, Slot Select, Confirm Sound를 Soft
Reference로 지정한다. 비어 있으면 조용히 생략하며 `/Game/...` 경로는 코드에 없다.
