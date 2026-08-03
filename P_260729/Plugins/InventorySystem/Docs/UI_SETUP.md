# 인벤토리 UI 및 Enhanced Input 제작 가이드

> 0.5 기준: 아래 문서는 기존 `WBP_Inventory`를 직접 커스터마이징할 때의 레거시
> Designer 가이드다. 새 네이티브 기본 UI와 현재 권장값은
> `UI_UX_UPGRADE_KO.md`를 우선 참고한다.

현재 인벤토리 UI는 **C++가 동작을 담당하고 Widget Blueprint는 디자인과 이름 연결만 담당하는 구조**다.

Blueprint에서 `RefreshSlot` 함수, Grid 생성 Loop, 버튼 OnClicked Event를 만들 필요가 없다. C++ 기반 클래스가 `BindWidget`으로 정해진 이름의 Widget을 자동 연결한다.

완성에 필요한 Widget Blueprint는 다음 두 개다.

| Blueprint 이름 | 반드시 선택할 부모 클래스 | 역할 |
|---|---|---|
| `WBP_InventorySlot` | `InventorySlotWidgetBase` | 아이템 한 칸을 표시한다. |
| `WBP_Inventory` | `InventoryWidgetBase` | 전체 Grid, 상세 정보, 명령 버튼을 관리한다. |

> 이름은 대소문자까지 정확히 일치해야 한다. 예를 들어 C++가 요구하는 `Image_ItemIcon`을 `Image_Itemicon`이나 `ItemIcon`으로 만들면 연결되지 않는다.

---

## 1. 기존 WBP_InventorySlot의 부모 변경

이미 `UserWidget` 부모로 `WBP_InventorySlot`을 만든 경우 새로 만들 필요가 없다.

1. `WBP_InventorySlot`을 연다.
2. 상단 Toolbar에서 **Class Settings**를 누른다.
3. Details의 **Class Options → Parent Class**를 찾는다.
4. 검색창에 `InventorySlotWidgetBase`를 입력한다.
5. `InventorySlotWidgetBase`를 선택한다.
6. Compile한다.

필수 Widget 이름이나 타입이 다르면 Compile Error가 표시된다. 아래 표에 맞게 이름과 타입을 수정한 뒤 다시 Compile한다.

새로 만들 때는 다음 순서를 사용한다.

1. Content Browser의 `/Game/Inventory/UI` 폴더를 연다.
2. 오른쪽 클릭하고 **User Interface → Widget Blueprint**를 선택한다.
3. 부모 선택 창에서 **All Classes**를 펼친다.
4. `InventorySlotWidgetBase`를 검색하여 선택한다.
5. 이름을 `WBP_InventorySlot`로 지정한다.

---

## 2. WBP_InventorySlot 구성

### 2.1 권장 Hierarchy

```text
WBP_InventorySlot (부모: InventorySlotWidgetBase)
└─ SizeBox_Slot                           176×176, C++ 자동 고정·Clip To Bounds
   └─ Border_SlotPadding                  Padding 8, Brush 투명
      └─ Button_Select                    필수: Button, 실제 크기 160×160
         └─ Overlay_Slot
            ├─ Border_Background          Grid.png 자동 적용, 빈 슬롯에도 표시
            ├─ SizeBox_Icon               96×96, C++ 자동 고정
            │  └─ ScaleBox_Icon           Scale To Fit, 디자인 전용
            │     └─ Image_ItemIcon       필수: Image
            ├─ Border_Unavailable         선택: Border
            ├─ Image_Selection            선택: Image
            └─ Text_Quantity              필수: Text Block
```

### 2.2 C++가 요구하는 Widget

| 정확한 이름 | Palette에서 선택할 타입 | 필수 여부 | Is Variable | C++에서 처리하는 동작 |
|---|---|---|---|---|
| `Button_Select` | Button | 필수 | 활성화 | 클릭하면 현재 Slot을 선택한다. |
| `Image_ItemIcon` | Image | 필수 | 활성화 | Item Definition의 Soft Icon을 로드하여 표시한다. |
| `Text_Quantity` | Text Block | 필수 | 활성화 | 수량이 2 이상일 때 숫자를 표시한다. |
| `Border_Background` | Border | 선택 | 사용할 경우 활성화 | 기본 `Grid` Texture를 빈 슬롯과 아이템 슬롯의 공통 프레임으로 자동 적용한다. |
| `Image_Selection` | Image | 선택 | 사용할 경우 활성화 | 선택된 Slot에 `select.png`를 표시한다. |
| `Border_Unavailable` | Border | 선택 | 사용할 경우 활성화 | 사용할 수 없는 아이템을 어둡게 표시한다. |

`BindWidget`으로 선언된 필수 Widget이 없거나 타입이 다르면 Widget Blueprint Compile이 실패한다. `BindWidgetOptional`인 선택 Widget은 없어도 정상 작동한다.

`Border_Background`는 C++가 `Grid` Texture를 자동 적용하므로 이름을 정확히 유지하고 Is Variable을 활성화한다. `Overlay_Slot`은 디자인 전용이라 이름을 바꿔도 되고 Is Variable을 활성화할 필요가 없다. `SizeBox_Slot`은 C++가 크기와 Clipping을 자동 설정하므로 이름을 정확히 유지한다.

Designer에서 Widget을 선택하면 Details 상단에 **Is Variable** 체크박스가 있다. 위 표에서 활성화로 표시한 Widget은 반드시 체크한다. 부모 클래스를 변경한 직후 Compile Error가 발생한다면 이름, 타입과 함께 Is Variable 설정도 확인한다.

### 2.3 Widget 배치 순서

1. Palette에서 `Size Box`를 Designer로 끌어 놓고 `SizeBox_Slot`로 이름을 바꾼다.
2. Width Override와 Height Override를 각각 `176`으로 설정한다. C++도 두 값을 강제하고 `Clip To Bounds`를 적용하므로 선택 이미지가 표시되어도 슬롯 크기가 변하지 않는다.
3. `SizeBox_Slot` 아래에 `Border`를 추가하고 `Border_SlotPadding`으로 이름을 바꾼다. Brush Color의 Alpha는 `0`, Padding은 상하좌우 `8`로 설정한다.
4. Palette에서 `Button`을 `Border_SlotPadding`의 자식으로 추가한다.
5. Button의 이름을 정확히 `Button_Select`로 바꾼다.
6. Palette에서 `Overlay`를 Button의 자식으로 추가한다.
7. Overlay 안에 배경 Border를 추가한 뒤, 아이콘용 `Size Box`와 그 자식 `Scale Box`, 다시 그 자식으로 아이콘 Image를 추가한다.
8. 같은 Overlay에 사용 불가 Border, 선택 Image, 수량 Text Block을 순서대로 추가한다.
9. 필수·선택 Widget의 이름을 위 표와 정확히 맞춘다.
10. Compile한다.

Overlay에서는 Hierarchy 아래에 있는 Widget이 화면 앞쪽에 그려진다. 따라서 `Image_Selection`을 아이콘보다 아래에 두고 `Text_Quantity`를 가장 아래에 두면 선택 이미지 위로 수량이 표시된다.

### 2.4 Image_ItemIcon 설정

- 부모 `SizeBox_Icon` Width Override: `96` (C++가 자동 적용)
- 부모 `SizeBox_Icon` Height Override: `96` (C++가 자동 적용)
- `SizeBox_Icon` Horizontal Alignment: Center
- `SizeBox_Icon` Vertical Alignment: Center
- `ScaleBox_Icon` Stretch: Scale To Fit
- `ScaleBox_Icon` Stretch Direction: Both
- 이름: `Image_ItemIcon`
- 타입: Image
- Brush → Draw As: Image
- 초기 Brush Image: 비워도 됨

`Image` 자체에는 이미지 비율을 보존하는 `Stretch` 설정이 없다. C++가 `SizeBox_Icon`을 `96×96` 정사각형으로 고정하고 `ScaleBox_Icon`을 `Scale To Fit`으로 설정한다. `Image_ItemIcon`이 Overlay에 직접 들어 있는 이전 구조라면 C++가 두 안전 영역 Widget을 런타임에 생성해 아이콘을 안으로 옮긴다. 아이콘 안전 영역은 Overlay의 마지막 자식으로 추가되므로 `Grid` 프레임보다 항상 앞에 그려진다.

C++가 Slot 초기화 시 다음을 자동 처리한다.

1. Item Definition의 Icon Soft Reference를 확인한다.
2. Texture2D를 동기 로드한다.
3. `SetBrushFromTexture`로 Image에 지정한다.
4. 아이콘이 없거나 로드에 실패하면 Image를 `Collapsed`로 변경한다.

Blueprint에서 아이콘 로드 함수나 `Event Construct`를 만들 필요가 없다.

### 2.5 Text_Quantity 설정

- 이름: `Text_Quantity`
- 타입: Text Block
- Horizontal Alignment: Right
- Vertical Alignment: Bottom
- Padding 예시: Right `12`, Bottom `10`
- 글자 크기: `18~22`
- 초기 Text: 비워도 됨

C++가 수량을 Text로 변환한다. 수량이 2 이상이면 표시하고 수량이 1이면 `Collapsed`로 숨긴다.

### 2.6 Image_Selection 설정

- 이름: `Image_Selection`
- 타입: Image
- Horizontal/Vertical Alignment: Fill
- Brush → Image: Import한 `select.png` Texture2D
- 기본 Visibility: `Collapsed`
- C++ 표시 상태: `Self Hit Test Invisible`

사용자가 Slot을 클릭하면 C++가 모든 Slot의 선택 상태를 비교한다. 선택된 Slot의 `Image_Selection`만 표시하고 이전 선택 Slot은 자동으로 숨긴다.

Blueprint에서 `bSelected`, `Set Visibility`, Button OnClicked Event를 만들 필요가 없다.

### 2.7 Border_Unavailable 설정

- 이름: `Border_Unavailable`
- 타입: Border
- Horizontal/Vertical Alignment: Fill
- Brush Color 예시: 검은색, Alpha `0.45~0.6`
- 기본 Visibility: `Collapsed`

기본 C++ 규칙은 `bCanUse == false`인 아이템에 이 Border를 표시한다.

Old Key처럼 사용할 수는 없지만 버리기와 자세히 보기가 가능한 아이템을 어둡게 표시하고 싶지 않다면 `WBP_InventorySlot`에서 선택적 Blueprint Event인 `ShouldShowUnavailable`만 Override할 수 있다. 대부분의 경우 Event Graph를 만들지 않고 기본 동작을 사용하면 된다.

---

## 3. WBP_Inventory 생성 또는 부모 변경

### 3.1 부모 클래스

새로 만들 때:

1. `/Game/Inventory/UI`에서 **User Interface → Widget Blueprint**를 선택한다.
2. **All Classes**에서 `InventoryWidgetBase`를 검색한다.
3. 해당 클래스를 부모로 선택한다.
4. 이름을 `WBP_Inventory`로 지정한다.

기존 Widget의 부모를 바꿀 때:

1. Widget Blueprint를 연다.
2. **Class Settings → Parent Class**를 찾는다.
3. `InventoryWidgetBase`로 변경한다.
4. **Is Focusable**을 활성화한다.

Is Focusable이 활성화되어야 C++가 ESC 입력을 받아 인벤토리를 닫을 수 있다.

### 3.2 권장 전체 구조

```text
WBP_Inventory (부모: InventoryWidgetBase)
└─ CanvasPanel_Root                         화면 전체
   ├─ Border_DimBackground                  화면 전체
   └─ SizeBox_InventoryWindow               1400×820, 중앙
      └─ Border_InventoryWindow
         └─ VerticalBox_Main
            ├─ Overlay_Header               높이 80
            │  ├─ Text_InventoryTitle       디자인 전용
            │  └─ Button_Close              필수: Button
            └─ HorizontalBox_Content
               ├─ SizeBox_ItemArea          너비 920
               │  └─ ScrollBox_Items
               │     └─ VerticalBox_Detail  필수: Uniform Grid Panel
               ├─ Spacer_Content            너비 24
               └─ SizeBox_DetailArea        너비 400
                  └─ VerticalBox_Detail
                     ├─ Image_SelectedIcon         필수: Image
                     ├─ Text_SelectedName          필수: Text Block
                     ├─ Text_SelectedQuantity      필수: Text Block
                     ├─ ScrollBox_Description
                     │  └─ Text_SelectedDescription 필수: Text Block
                     ├─ Text_DisabledReason        선택: Text Block
                     ├─ Spacer_Detail
                     └─ HorizontalBox_Actions
                        ├─ Button_Use               필수: Button
                        ├─ Button_Drop              필수: Button
                        └─ Button_Inspect           필수: Button
```

위 Hierarchy가 이 문서에서 사용하는 정확한 최종 구조다. Panel과 Size Box의 이름은 디자인 편의를 위한 권장 이름이며, C++가 사용하는 필수 이름은 다음 절의 표에서 구분한다.

### 3.3 C++가 요구하는 Widget

| 정확한 이름 | Palette 타입 | 필수 여부 | Is Variable | 자동 동작 |
|---|---|---|---|---|
| `UniformGridPanel_Items` | Uniform Grid Panel | 필수 | 활성화 | Inventory Slot Widget을 자동 생성·배치한다. |
| `Image_SelectedIcon` | Image | 필수 | 활성화 | 선택된 아이템의 Icon을 표시한다. |
| `Text_SelectedName` | Text Block | 필수 | 활성화 | Display Name을 표시한다. |
| `Text_SelectedQuantity` | Text Block | 필수 | 활성화 | 선택 아이템 수량을 표시한다. |
| `Text_SelectedDescription` | Text Block | 필수 | 활성화 | Description을 표시한다. |
| `Text_DisabledReason` | Text Block | 선택 | 사용할 경우 활성화 | 사용할 수 없는 이유를 표시한다. |
| `Button_Use` | Button | 필수 | 활성화 | 선택 아이템을 사용한다. |
| `Button_Drop` | Button | 필수 | 활성화 | 선택 아이템 1개를 버린다. |
| `Button_Inspect` | Button | 필수 | 활성화 | Item Inspector를 연다. |
| `Button_Close` | Button | 필수 | 활성화 | 인벤토리를 닫는다. |

위 표에 없는 `CanvasPanel_Root`, 배경 Border, Inventory Window용 Size Box와 Border, Vertical/Horizontal Box, `Overlay_Header`, `Text_InventoryTitle`, `ScrollBox_Items`, `ScrollBox_Description`, Spacer는 디자인 전용이다. 자유롭게 이름을 바꿀 수 있으며 **Is Variable을 활성화할 필요가 없다**.

정리하면 다음 기준으로 판단한다.

```text
C++가 BindWidget 또는 BindWidgetOptional로 접근함
→ 이름과 타입을 정확히 맞춤
→ Is Variable 활성화

배치와 디자인에만 사용함
→ 이름 변경 가능
→ Is Variable 비활성화 가능
```

### 3.4 중앙 Inventory Window 설정

`SizeBox_InventoryWindow`를 선택하고 Canvas Slot을 다음과 같이 설정한다.

```text
Anchors:        Center
Alignment:      X 0.5, Y 0.5
Position:       X 0, Y 0
Width Override: 1400
Height Override: 820
```

`Border_DimBackground`는 Full Screen Anchor를 사용하고 Offset을 모두 0으로 설정한다. 검은색과 Alpha `0.45~0.65`를 사용하면 게임 화면이 자연스럽게 어두워진다.

### 3.5 Item Grid 설정

1. `SizeBox_ItemArea`의 Width Override를 `920`으로 설정한다.
2. 그 안에 `Scroll Box`를 넣는다.
3. Scroll Box 안에 `Uniform Grid Panel`을 넣는다.
4. Grid의 이름을 정확히 `UniformGridPanel_Items`로 변경한다.
5. `UniformGridPanel_Items`를 선택하고 부모 `ScrollBox Slot`의 Horizontal Alignment를 `Left`, Vertical Alignment를 `Top`으로 설정한다. `Fill`이면 아이템 개수에 따라 Grid 전체 폭과 열 간격이 늘어날 수 있다.
6. `UniformGridSlot`에는 공통 Padding API가 없으므로 여백은 `WBP_InventorySlot`의 `Border_SlotPadding`에서 상하좌우 `8`로 설정한다.

C++도 위 설정을 강제한다. `UniformGridPanel_Items`는 `176×176` Cell, Slot Padding `0`, 부모 ScrollBox Slot은 `Auto + Left/Top`으로 설정된다. `Border_SlotPadding`의 좌우·상하 `8` 때문에 실제 Grid 프레임 사이 간격은 `16`이 된다.

Grid에 Slot Widget을 직접 넣지 않는다. C++가 현재 인벤토리 Slot을 순회하면서 `WBP_InventorySlot`을 생성한다.

`WBP_Inventory`의 Class Defaults에서 다음 값을 권장한다.

```text
Grid Column Count: 5
Show Empty Slots:  true
```

기본 `Max Inventory Slots`가 20이면 화면에는 항상 `5열 × 4행`의 슬롯이 만들어진다. 빈 슬롯도 `WBP_InventorySlot` 배경은 표시되지만 아이콘과 수량은 숨겨지고 선택 Button은 비활성화된다. 아이템을 얻으면 Inventory의 실제 Slot Index 위치에 아이콘이 채워진다. `Show Empty Slots`를 끄면 보유 아이템만 왼쪽부터 압축해서 표시하는 목록 방식으로 돌아간다.

### 3.6 상세 정보 영역 설정

| Widget | 권장 크기와 설정 |
|---|---|
| `Image_SelectedIcon` | `220×220`, Center, Scale To Fit |
| `Text_SelectedName` | 높이 `52`, 글자 `26~32`, Auto Wrap Text |
| `Text_SelectedQuantity` | 높이 `32`, 글자 `18~22` |
| `Text_SelectedDescription` | Scroll Box 내부, Auto Wrap Text |
| `Text_DisabledReason` | 높이 `48`, 기본 Collapsed |
| `Button_Use` | `112×52`, 내부 Text `사용` |
| `Button_Drop` | `112×52`, 내부 Text `버리기` |
| `Button_Inspect` | `136×52`, 내부 Text `자세히 보기` |

C++가 선택 상태에 따라 Text와 Icon을 자동 설정하고 각 Button의 활성 상태를 변경한다.

### 3.7 Button 설정

Button 안에 표시할 Text Block은 C++가 사용하지 않으므로 이름이 자유롭다.

```text
Button_Use
└─ Text Block: "사용"

Button_Drop
└─ Text Block: "버리기"

Button_Inspect
└─ Text Block: "자세히 보기"

Button_Close
└─ Text Block: "닫기" 또는 "X"
```

OnClicked Event를 Blueprint에서 만들지 않는다. C++가 각 Button의 OnClicked Delegate를 자동으로 연결한다.

---

## 4. Slot Widget Class 지정

이 설정을 하지 않으면 Grid가 비어 있게 된다.

1. `WBP_Inventory`를 연다.
2. 상단의 **Class Defaults**를 누른다.
3. Details에서 **Inventory | UI** Category를 찾는다.
4. `Slot Widget Class`에 `WBP_InventorySlot`을 지정한다.
5. `Grid Column Count`를 `5`로 설정한다.
6. Compile하고 Save한다.

C++ 동작 순서:

```text
Inventory 변경 Delegate 수신
→ UniformGridPanel_Items.ClearChildren
→ Show Empty Slots가 켜져 있으면 빈 Slot을 포함한 전체 Inventory Slot 순회
→ SlotWidgetClass로 WBP_InventorySlot 생성
→ ItemDefinition, Quantity, SlotIndex 전달
→ GridColumnCount 기준으로 Row와 Column 계산
→ UniformGridPanel_Items에 추가
```

Blueprint에서 `OnInventoryRefreshed` Event나 For Each Loop를 만들 필요가 없다.

---

## 5. Blueprint Event Graph가 필요한 경우

기본 인벤토리는 Event Graph가 비어 있어도 작동한다.

다음 Event는 게임별 애니메이션이나 추가 연출이 필요할 때만 선택적으로 구현한다.

| 선택 Event | 호출 시점 |
|---|---|
| `OnSlotRefreshed` | C++가 Slot Icon, 수량, 상태를 갱신한 뒤 |
| `OnSelectionVisualChanged` | 선택 이미지 상태가 변경된 뒤 |
| `OnInventoryRefreshed` | C++가 전체 Grid를 다시 만든 뒤 |
| `OnSelectionChanged` | C++가 상세 정보를 갱신한 뒤 |
| `OnInventoryOperationFailed` | 사용·버리기 등에 실패했을 때 |

즉, 기본 UI 제작에는 Blueprint 함수, 변수, Button Event가 필요하지 않다.

---

## 6. Player에 Component 추가

### InventoryComponent

1. 실제 플레이어 Pawn Blueprint를 연다.
2. Components Panel에서 **Add**를 누른다.
3. `Inventory Component`를 검색하여 추가한다.
4. Max Inventory Slots를 기본 `20` 또는 원하는 값으로 설정한다.

### InventoryUIComponent

1. 동일 Pawn 또는 로컬 PlayerController에 `Inventory UI Component`를 추가한다.
2. Inventory Widget Class에 `WBP_Inventory`를 지정한다.
3. Toggle Inventory Action에 `IA_ToggleInventory`를 지정한다.
4. Toggle Input Mapping Context에 해당 Action을 등록한 `IMC_Default`를 지정한다.
5. Inventory Component에는 앞에서 추가한 Component를 지정하거나 자동 검색하도록 비워 둔다.
6. `ReuseInventoryInspectorBridge`가 Inventory Plugin에 포함되며 새 `InventoryUIComponent`에는 기본 생성된다.

Toggle Input Mapping Context는 UI가 Tab을 Focus Navigation Key로 먼저 소비하더라도 C++가 현재 Toggle Action에 매핑된 Key임을 확인하고 인벤토리를 닫기 위해 사용한다. Key를 C++에 하드코딩하지 않으므로 IMC에서 Tab을 I로 바꾸면 닫기 Key도 함께 변경된다.

---

## 7. Enhanced Input 설정

### IA_ToggleInventory 생성

1. `/Game/Inventory/Input` 폴더에서 오른쪽 클릭한다.
2. **Input → Input Action**을 선택한다.
3. 이름을 `IA_ToggleInventory`로 지정한다.
4. Value Type을 `Digital (bool)`로 설정한다.

### Input Mapping Context 연결

1. 실제 플레이어가 사용하는 Input Mapping Context를 연다.
2. `IA_ToggleInventory`를 추가한다.
3. Tab 또는 I Key를 지정한다.

### 입력 Event 연결

Blueprint Player에서 가장 간단한 방식:

```text
IA_ToggleInventory (Started)
→ InventoryUIComponent.ToggleInventory
```

C++ Pawn에서는 다음처럼 연결할 수 있다.

```cpp
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    InventoryUI->BindEnhancedInput(Cast<UEnhancedInputComponent>(PlayerInputComponent));
}
```

키는 C++가 아니라 Input Mapping Context에서 변경한다.

Inventory UI Component의 최종 입력 설정 예시:

```text
Toggle Inventory Action         = IA_Inventory
Toggle Input Mapping Context    = IMC_Default
```

인벤토리가 열리면 C++가 이동·시점 무시 상태뿐 아니라 현재 조종 중인 Pawn의 Input도 임시 비활성화한다. 따라서 Jump처럼 이동 축과 무관한 Action도 실행되지 않는다. UI의 Preview Key 처리에서 Toggle Action의 Key와 ESC를 받으므로 Pawn Input이 비활성화되어 있어도 인벤토리를 닫을 수 있다.

---

## 8. 해상도별 권장 크기

### 1920×1080

| 영역 | 권장 크기 |
|---|---:|
| Inventory Window | `1400×820` |
| Header | 높이 `80` |
| Item Area | 너비 `920` |
| Detail Area | 너비 `400` |
| Inventory Slot | `160×160` |
| Grid 열 수 | `5` |
| Selected Icon | `220×220` |

### 1280×720

| 영역 | 권장 크기 |
|---|---:|
| Inventory Window | `1080×620` |
| Item Area | 약 `700` 너비 |
| Detail Area | 약 `320` 너비 |
| Inventory Slot | `128×128` |
| Grid 열 수 | `4` |
| Selected Icon | `160×160` |

Project Settings의 **User Interface → DPI Scaling**을 1280×720, 1920×1080, 2560×1440에서 확인한다.

---

## 9. Compile Error 점검

Widget Blueprint Compile Error가 발생하면 다음 순서로 확인한다.

1. Parent Class가 정확한지 확인한다.
2. 필수 Widget이 모두 존재하는지 확인한다.
3. 이름의 대소문자가 C++ 요구 이름과 같은지 확인한다.
4. Widget 타입이 맞는지 확인한다. 예를 들어 `Image_Selection`은 Border가 아니라 Image여야 한다.
5. `WBP_Inventory`의 Slot Widget Class에 `WBP_InventorySlot`이 지정되었는지 확인한다.

### WBP_InventorySlot 필수 이름

```text
Button_Select       : Button
Image_ItemIcon      : Image
Text_Quantity       : Text Block
```

위 세 Widget은 모두 Is Variable을 활성화한다. 선택 Widget인 `Image_Selection`과 `Border_Unavailable`도 배치했다면 Is Variable을 활성화한다.

### WBP_Inventory 필수 이름

```text
UniformGridPanel_Items     : Uniform Grid Panel
Image_SelectedIcon         : Image
Text_SelectedName          : Text Block
Text_SelectedQuantity      : Text Block
Text_SelectedDescription   : Text Block
Button_Use                 : Button
Button_Drop                : Button
Button_Inspect             : Button
Button_Close               : Button
```

위 `WBP_Inventory` 필수 Widget은 모두 Is Variable을 활성화한다. `WBP_Inventory`의 선택 Widget인 `Text_DisabledReason`은 없어도 Compile되지만 배치했다면 Is Variable을 활성화한다. `Image_Selection`과 `Border_Unavailable`은 `WBP_InventorySlot`에 속하는 선택 Widget이다.
