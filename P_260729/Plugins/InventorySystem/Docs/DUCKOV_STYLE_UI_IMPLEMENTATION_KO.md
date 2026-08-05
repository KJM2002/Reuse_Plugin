# Duckov 스타일 Inventory UI 1차 구현: Unreal Editor 제작 가이드

이 문서는 Unreal Editor 5.7을 처음 사용하는 사람도 기존 UI를 보존하면서 새 UI를 확인하거나 재제작할 수 있도록 작성됐다. 아래 다섯 Widget Blueprint `.uasset`은 공식 Unreal Editor API로 `/Game/UI/Inventory`에 생성되어 있다.

```text
WBP_InventoryDuckov
WBP_InventorySlotDuckov
WBP_InventoryTooltip
WBP_InventoryContextMenu
WBP_InventoryContextAction
```

기존 `/InventorySystem/Widget/WBP_Inventory`와 `/InventorySystem/Widget/WBP_InventorySlot`은 삭제하거나 덮어쓰지 않는다. 이 문서의 Visibility 명칭은 UE 5.7 기준이며, 다른 버전에서 다음처럼 표시될 수 있다.

- `Not Hit-Testable (Self Only)` = `Self Hit Test Invisible`
- `Not Hit-Testable (Self & All Children)` = `Hit Test Invisible`

## 1. 시작 전 준비

1. 프로젝트를 C++ 빌드한 뒤 Unreal Editor를 연다.
2. Content Browser 오른쪽 위 `Settings`를 누른다.
3. `Show Plugin Content`를 체크한다.
4. Content Browser 주소창에 `/InventorySystem/Widget`을 입력한다.
5. 기존 `WBP_Inventory`와 `WBP_InventorySlot`이 보이는지 확인한다.
6. 프로젝트 Content 아래의 `/Game/UI/Inventory` 폴더에서 생성된 다섯 에셋을 확인한다. 에셋을 재제작할 때도 이 폴더를 사용한다.

## 2. 기존 WBP_Inventory를 수동으로 재제작할 때의 복제 및 Parent Class 변경

### 2.1 기존 에셋을 안전하게 복제한다

1. `/InventorySystem/Widget/WBP_Inventory`를 우클릭한다.
2. `Asset Actions > Duplicate`를 누른다. 단축키는 `Ctrl+W`다.
3. 이름을 `WBP_InventoryDuckov`로 입력한다.
4. 새 복사본만 `/Game/UI/Inventory` 폴더로 드래그한다.
5. 팝업에서 `Move Here`를 선택한다. 원본 `WBP_Inventory`는 이동하지 않는다.
6. 원본과 복사본이 각각 다음 경로에 남았는지 확인한다.

```text
/InventorySystem/Widget/WBP_Inventory
/Game/UI/Inventory/WBP_InventoryDuckov
```

실수로 원본 이름을 바꾸거나 이동했다면 저장하지 말고 즉시 `Ctrl+Z`로 되돌린다.

### 2.2 Parent Class를 바꾼다

1. `WBP_InventoryDuckov`를 더블클릭한다.
2. Widget Blueprint Editor 상단의 `File > Reparent Blueprint`를 선택한다.
3. 검색창에 `InventoryDuckovWidgetBase`를 입력한다.
4. `InventoryDuckovWidgetBase`를 선택한다.
5. 상단 `Class Settings`를 누르고 Details의 `Parent Class`가 `InventoryDuckovWidgetBase`인지 확인한다.
6. 기존 Designer 트리와 Animation 트랙을 새 구조로 교체할 예정이므로, 복제본에서만 기존 Animation을 삭제한다.
7. Designer에서 기존 Root 아래 Widget을 삭제하고 5절의 계층을 다시 만든다. `UniformGridPanel_Items`와 `Button_Close`를 만들기 전까지 Compile 오류가 나는 것은 정상이다.

`File > Reparent Blueprint`가 보이지 않으면 상단 `Class Settings`를 누른 후 Details의 `Parent Class` 드롭다운에서 같은 클래스를 선택한다.

## 3. 나머지 Widget Blueprint 생성 방법

`/Game/UI/Inventory`에서 빈 공간을 우클릭하고 `User Interface > Widget Blueprint`를 선택한다. Parent 선택 창에서 `All Classes`를 펼쳐 아래 C++ Parent를 선택한다.

| 만들 에셋 | 선택할 Parent Class |
|---|---|
| `WBP_InventorySlotDuckov` | `InventoryDuckovSlotWidgetBase` |
| `WBP_InventoryTooltip` | `InventoryTooltipWidgetBase` |
| `WBP_InventoryContextAction` | `InventoryContextActionWidgetBase` |
| `WBP_InventoryContextMenu` | `InventoryContextMenuWidgetBase` |

각 에셋은 만들자마자 한 번 Compile/Save한다. C++ Parent가 검색되지 않으면 Editor를 닫고 `P_060715Editor Win64 Development`를 빌드한 뒤 다시 연다.

## 4. UMG 값 입력 규칙

- 기준 Designer 해상도는 `1920 × 1080`이다.
- Anchor와 Offset은 **Canvas Panel의 직접 자식**에만 존재한다. 표의 `해당 없음`은 입력을 빼먹은 것이 아니다.
- `Offset = X,Y,W,H`는 비 Stretch Canvas Slot의 Position X/Y와 Size X/Y다.
- `Offset = L,T,R,B`는 Full Stretch Canvas Slot의 Left/Top/Right/Bottom이다.
- Overlay, Horizontal Box, Vertical Box 자식의 ZOrder는 별도 숫자 속성이 없다. 표의 숫자는 **Hierarchy에서 아래에 있을수록 앞에 그려지는 자식 순서**다.
- `Is Variable = On`인 Widget은 Designer 왼쪽 Hierarchy에서 선택하고 Details 상단 `Is Variable`을 체크한다.
- C++ `BindWidget` 또는 `BindWidgetOptional` 이름은 대소문자와 밑줄까지 정확히 일치해야 한다.

## 5. WBP_InventoryDuckov

### 5.1 전체 Widget Hierarchy

아래 이름과 타입 그대로 만든다. 괄호 안은 타입이다.

```text
WBP_InventoryDuckov
└─ Overlay_Root (Overlay)
   ├─ Border_BackgroundDim (Border)
   └─ SafeZone_Main (Safe Zone)
      └─ CanvasPanel_Main (Canvas Panel)
         ├─ Panel_PlayerInventory (Size Box)
         │  └─ Border_PlayerPanel (Border)
         │     └─ VerticalBox_Player (Vertical Box)
         │        ├─ HorizontalBox_Header (Horizontal Box)
         │        │  ├─ Text_PlayerContainerName (Text Block)
         │        │  ├─ Text_Capacity (Text Block)
         │        │  ├─ Button_Sort (Button, 런타임 C++ 생성)
         │        │  └─ SizeBox_Close (Size Box)
         │        │     └─ Button_Close (Button)
         │        └─ ScrollBox_PlayerItems (Scroll Box)
         │           └─ UniformGridPanel_Items (Uniform Grid Panel)
         ├─ Panel_ExternalContainer (Size Box)
         ├─ CanvasPanel_TooltipLayer (Canvas Panel)
         └─ CanvasPanel_ContextMenuLayer (Canvas Panel)
```

Tooltip/Context Menu Canvas 안에는 Designer에서 자식을 미리 넣지 않는다. C++가 런타임에 생성한다.

### 5.2 Root 및 Canvas 직접 자식 설정

| 이름 | 타입 | Anchor | Alignment | Offset/크기 | Padding | ZOrder/순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---|---:|---|---|---|
| `Overlay_Root` | Overlay | 해당 없음 | Fill/Fill | 화면 Fill | 0 | Root | Visible | On | Self Only |
| `Border_BackgroundDim` | Border | 해당 없음 | Fill/Fill | 화면 Fill | 0 | 0 | Visible | On | Self & All Children |
| `SafeZone_Main` | Safe Zone | 해당 없음 | Fill/Fill | 화면 Fill | 0 | 1 | Visible | Off | Self Only |
| `CanvasPanel_Main` | Canvas Panel | 해당 없음 | Fill/Fill | Safe Zone Fill | 0 | 0 | Visible | Off | Self Only |
| `Panel_PlayerInventory` | Size Box | Min/Max `(0,1)` | `(0,1)` | `X=48,Y=-48,W=480,H=560` | 0 | 20 | Visible | On | Visible |
| `Panel_ExternalContainer` | Size Box | Min/Max `(1,0.5)` | `(1,0.5)` | `X=-64,Y=0,W=500,H=820` | 0 | 20 | Collapsed | On | Self Only |
| `CanvasPanel_TooltipLayer` | Canvas Panel | Min `(0,0)`, Max `(1,1)` | `(0,0)` | `L=0,T=0,R=0,B=0` | 0 | 100 | Self Only | On | Self Only |
| `CanvasPanel_ContextMenuLayer` | Canvas Panel | Min `(0,0)`, Max `(1,1)` | `(0,0)` | `L=0,T=0,R=0,B=0` | 0 | 110 | Self Only | On | Self Only |

`Border_BackgroundDim`의 Brush Color는 `(0,0,0,0.32)`로 둔다. 두 Popup Layer를 `Visible`로 두면 전체 화면 빈 Canvas가 슬롯 클릭을 막을 수 있으므로 반드시 `Not Hit-Testable (Self Only)`를 선택한다. C++도 Construct 시 이 값을 재적용한다.

### 5.3 Player Panel 내부 설정

| 이름 | 타입 | Parent Slot 정렬 | Offset/크기 | Padding | 순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---:|---|---|---|
| `Border_PlayerPanel` | Border | Fill/Fill | Fill | Content `20,20,20,20` | 0 | Visible | Off | Self Only |
| `VerticalBox_Player` | Vertical Box | Fill/Fill | Fill | 0 | 0 | Visible | Off | Self Only |
| `HorizontalBox_Header` | Horizontal Box | Fill/Top, Auto | 높이 42 | Bottom 14 | 0 | Visible | Off | Self Only |
| `Text_PlayerContainerName` | Text Block | Fill/Center | Auto, Font 24 | 0 | 0 | Visible | On | Self & All Children |
| `Text_Capacity` | Text Block | Auto/Center | Auto, Font 16 | Right 12 | 1 | Visible | On | Self & All Children |
| `Button_Sort` | Button | Auto/Center | Auto | Right 8 | 2 | Visible | On | Visible |
| `SizeBox_Close` | Size Box | Auto/Center | `38 × 38` | 0 | 3 | Visible | Off | Self Only |
| `Button_Close` | Button | Fill/Fill | Fill | Content 0 | 0 | Visible | On | Visible |
| `ScrollBox_PlayerItems` | Scroll Box | Fill/Fill | 남은 높이 Fill | 0 | 1 | Visible | Off | Visible |
| `UniformGridPanel_Items` | Uniform Grid Panel | Left/Top, Auto | Min Cell `88 × 88` | Slot Padding 4 | 0 | Visible | On | Self Only |

런타임에는 `Text_PlayerContainerName`이 `Backpack (점유 슬롯/최대 슬롯)`으로 갱신되고 기존 `Text_Capacity`는 중복 표시를 피하기 위해 숨겨진다. 현재 생성된 WBP에는 `Button_Sort`가 저장돼 있지 않아도 C++가 `HorizontalBox_Header`에 안전하게 생성한다. Designer에서 직접 `Button_Sort`를 추가해도 같은 Optional BindWidget을 사용하며 Blueprint `OnClicked`를 연결하지 않는다.

### 5.4 Class Defaults

상단 `Class Defaults`를 누르고 Details 검색창에서 다음 값을 지정한다.

| Property | 값 |
|---|---|
| `Is Focusable` | 체크 |
| `Slot Widget Class` | `WBP_InventorySlotDuckov` |
| `Tooltip Widget Class` | `WBP_InventoryTooltip` |
| `Context Menu Widget Class` | `WBP_InventoryContextMenu` |
| `Context Action Widget Class` | `WBP_InventoryContextAction` |
| `Grid Column Count` | `5` |
| `Show Empty Slots` | 체크 |
| `Open Transition Duration` | `0.22` |
| `Close Transition Duration` | `0.15` |

Class 드롭다운에 새 WBP가 없으면 해당 WBP를 먼저 Compile/Save하고 이 WBP를 다시 연다.

## 6. WBP_InventorySlotDuckov

### 6.1 Hierarchy

```text
WBP_InventorySlotDuckov
└─ SizeBox_Slot (Size Box)
   └─ Overlay_Slot (Overlay)
      ├─ Border_Background (Border)
      ├─ SizeBox_Icon (Size Box)
      │  └─ ScaleBox_Icon (Scale Box)
      │     └─ Image_ItemIcon (Image)
      ├─ Border_Unavailable (Border)
      ├─ Border_NameGradient (Border)
      │  └─ Text_ItemName (Text Block)
      ├─ Border_QuantityBadge (Border)
      │  └─ Text_Quantity (Text Block)
      ├─ Image_Selection (Image)
      ├─ Border_Hover (Border)
      └─ Button_Select (Button)
```

### 6.2 정확한 설정

이 WBP에는 Canvas Panel이 없으므로 Anchor와 Canvas Offset은 전부 해당 없음이다.

| 이름 | 타입 | Alignment | 크기 | Overlay Padding | 순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---:|---|---|---|
| `SizeBox_Slot` | Size Box | Fill/Fill | Override `80 × 80` | 해당 없음 | Root | Visible | On | Self Only |
| `Overlay_Slot` | Overlay | Fill/Fill | Fill | 0 | 0 | Visible | On | Self Only |
| `Border_Background` | Border | Fill/Fill | Fill | 1 | 0 | Self Only | On | Self Only |
| `SizeBox_Icon` | Size Box | Center/Center | Override `62 × 62` | 0 | 1 | Visible | On | Self Only |
| `ScaleBox_Icon` | Scale Box | Fill/Fill | Fill, Stretch=`Scale To Fit` | 0 | 0 | Visible | On | Self Only |
| `Image_ItemIcon` | Image | Fill/Fill | Fill | 0 | 0 | Collapsed | On | Self & All Children |
| `Border_Unavailable` | Border | Fill/Fill | Fill | 0 | 2 | Collapsed | On | Self & All Children |
| `Border_NameGradient` | Border | Fill/Bottom | Auto | Content `L=6,T=2,R=6,B=4` | 3 | Visible | On | Self & All Children |
| `Text_ItemName` | Text Block | Fill/Fill | Auto, Font 11, 한 줄 | 0 | 0 | Collapsed | On | Self & All Children |
| `Border_QuantityBadge` | Border | Right/Top | Auto | Content `L=6,T=2,R=6,B=2`, Overlay `T=6,R=6` | 4 | Visible | On | Self & All Children |
| `Text_Quantity` | Text Block | Fill/Fill | Auto, Font 13 | 0 | 0 | Collapsed | On | Self & All Children |
| `Image_Selection` | Image | Fill/Fill | Fill | 0 | 5 | Collapsed | On | Self & All Children |
| `Border_Hover` | Border | Fill/Fill | Fill | 0 | 6 | Collapsed | On | Self & All Children |
| `Button_Select` | Button | Fill/Fill | Fill | 0 | 7 | Visible | On | Visible |

`Button_Select`의 Normal/Hovered/Pressed Brush는 투명으로 하고 Content는 비운다. `OnClicked`는 C++가 연결하므로 Blueprint에서 추가하지 않는다. Duckov C++가 런타임에 `Slot Display Size=80`, `Icon Display Size=62`를 적용한다.

생성된 2차 스타일의 기준 색은 Player Panel `RGBA(0.025, 0.075, 0.125, 0.74)`, 빈 슬롯 Outline `RGBA(0.48, 0.62, 0.68, 0.78)`, Hover/Selection 청록 `RGBA(0.08, 0.82, 0.76, 1.0)`이다. C++가 모든 `Border_Background`와 `Button_Select` Overlay Slot을 80×80 전체 Fill로 정규화하므로 빈 슬롯이 작은 선으로 축소되거나 클릭 영역이 사라지지 않는다. 패널 뒤에는 Strength 6의 `BackgroundBlur_PlayerPanel`을 런타임에 배치하며 중앙 월드 영역에는 Blur를 적용하지 않는다.

## 7. WBP_InventoryTooltip

### 7.1 Hierarchy

```text
WBP_InventoryTooltip
└─ SizeBox_Tooltip (Size Box)
   └─ Border_Tooltip (Border)
      └─ VerticalBox_Tooltip (Vertical Box)
         ├─ SizeBox_TooltipIcon (Size Box)
         │  └─ Image_TooltipIcon (Image)
         ├─ Text_TooltipName (Text Block)
         ├─ Text_TooltipCategory (Text Block)
         ├─ Text_TooltipQuantity (Text Block)
         ├─ Text_TooltipDescription (Text Block)
         ├─ Text_TooltipFlavor (Text Block)
         └─ Text_TooltipDisabledReason (Text Block)
```

### 7.2 정확한 설정

이 WBP에는 Canvas Panel이 없으므로 모든 Widget의 Canvas Anchor, Alignment, Offset과 Canvas ZOrder는 해당 없음이다. 아래 Alignment와 순서는 각 Parent Panel Slot 기준이다.

| 이름 | 타입 | Alignment | 크기 | Padding | 순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---:|---|---|---|
| `SizeBox_Tooltip` | Size Box | Fill/Fill | Width Override 320, Height Auto | 0 | Root | Visible | Off | Self & All Children |
| `Border_Tooltip` | Border | Fill/Fill | Fill | Content 16 | 0 | Visible | Off | Self & All Children |
| `VerticalBox_Tooltip` | Vertical Box | Fill/Fill | Fill | 0 | 0 | Visible | Off | Self & All Children |
| `SizeBox_TooltipIcon` | Size Box | Center/Top | `64 × 64` | Bottom 10 | 0 | Visible | Off | Self & All Children |
| `Image_TooltipIcon` | Image | Fill/Fill | Fill | 0 | 0 | Collapsed | On | Self & All Children |
| `Text_TooltipName` | Text Block | Fill/Top | Font 18 | Bottom 4 | 1 | Collapsed | On | Self & All Children |
| `Text_TooltipCategory` | Text Block | Fill/Top | Font 12 | Bottom 8 | 2 | Collapsed | On | Self & All Children |
| `Text_TooltipQuantity` | Text Block | Fill/Top | Font 13 | Bottom 8 | 3 | Collapsed | On | Self & All Children |
| `Text_TooltipDescription` | Text Block | Fill/Top | Font 14, Auto Wrap On | Bottom 10 | 4 | Collapsed | On | Self & All Children |
| `Text_TooltipFlavor` | Text Block | Fill/Top | Font 12, Auto Wrap On | Bottom 10 | 5 | Collapsed | On | Self & All Children |
| `Text_TooltipDisabledReason` | Text Block | Fill/Top | Font 12, Auto Wrap On | 0 | 6 | Collapsed | On | Self & All Children |

내부 Root인 `SizeBox_Tooltip`은 Visible로 둔다. C++가 바깥 `WBP_InventoryTooltip` 인스턴스를 생성 직후 Collapsed로 만들고 데이터가 있을 때 `Hit Test Invisible`로 표시한다. 내부 SizeBox까지 Collapsed로 설정하면 바깥 인스턴스를 표시해도 내용이 보이지 않는다. Tooltip은 마우스 입력을 절대 가로채지 않아야 한다. 런타임 Canvas ZOrder는 C++가 `100`으로 지정한다.

## 8. WBP_InventoryContextAction

### 8.1 Hierarchy

```text
WBP_InventoryContextAction
└─ SizeBox_Action (Size Box)
   └─ Button_Action (Button)
      └─ HorizontalBox_Action (Horizontal Box)
         ├─ Text_ActionLabel (Text Block)
         └─ Text_DisabledReason (Text Block)
```

### 8.2 정확한 설정

이 WBP에는 Canvas Panel이 없으므로 모든 Widget의 Canvas Anchor, Alignment, Offset과 Canvas ZOrder는 해당 없음이다. 아래 Alignment와 순서는 각 Parent Panel Slot 기준이다.

| 이름 | 타입 | Alignment | 크기 | Padding | 순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---:|---|---|---|
| `SizeBox_Action` | Size Box | Fill/Fill | Width Override 214, Min Desired Height 40 | 0 | Root | Visible | Off | Self Only |
| `Button_Action` | Button | Fill/Fill | Fill | Content `L=12,T=8,R=12,B=8` | 0 | Visible | On | Visible |
| `HorizontalBox_Action` | Horizontal Box | Fill/Fill | Fill | 0 | 0 | Visible | Off | Self Only |
| `Text_ActionLabel` | Text Block | Fill/Center | Font 14 | 0 | 0 | Visible | On | Self & All Children |
| `Text_DisabledReason` | Text Block | Auto/Center | Font 11 | Left 8 | 1 | Collapsed | On | Self & All Children |

`Button_Action.OnClicked`는 Blueprint에서 연결하지 않는다. C++가 Construct/Destruct에서 Bind/Unbind한다.

## 9. WBP_InventoryContextMenu

### 9.1 Hierarchy

```text
WBP_InventoryContextMenu
└─ SizeBox_ContextMenu (Size Box)
   └─ Border_ContextMenu (Border)
      └─ VerticalBox_Menu (Vertical Box)
         ├─ Text_ContextMenuTitle (Text Block)
         └─ VerticalBox_Actions (Vertical Box)
```

### 9.2 정확한 설정

이 WBP에는 Canvas Panel이 없으므로 모든 Widget의 Canvas Anchor, Alignment, Offset과 Canvas ZOrder는 해당 없음이다. 아래 Alignment와 순서는 각 Parent Panel Slot 기준이다.

| 이름 | 타입 | Alignment | 크기 | Padding | 순서 | 기본 Visibility | Is Variable | Hit Test |
|---|---|---|---|---|---:|---|---|---|
| `SizeBox_ContextMenu` | Size Box | Fill/Fill | Width Override 230, Height Auto | 0 | Root | Visible | Off | Self Only |
| `Border_ContextMenu` | Border | Fill/Fill | Fill | Content 8 | 0 | Visible | Off | Self Only |
| `VerticalBox_Menu` | Vertical Box | Fill/Fill | Fill | 0 | 0 | Visible | Off | Self Only |
| `Text_ContextMenuTitle` | Text Block | Fill/Top | Font 14 | `L=8,T=6,R=8,B=8` | 0 | Collapsed | On | Self & All Children |
| `VerticalBox_Actions` | Vertical Box | Fill/Top | Auto | 0 | 1 | Visible | On | Self Only |

내부 Root인 `SizeBox_ContextMenu`는 Visible로 둔다. C++가 바깥 `WBP_InventoryContextMenu` 인스턴스의 Visibility를 열고 닫는다. Class Defaults에서 `Action Widget Class = WBP_InventoryContextAction`을 지정한다. 런타임 Canvas ZOrder는 C++가 `110`으로 지정한다. 현재 Action은 실제 기존 API가 있는 Use, Drop One, Inspect만 생성한다.

## 10. C++ BindWidget 기준표

### 10.1 필수 BindWidget

필수 이름이 없거나 타입이 다르면 Widget Blueprint Compile이 실패한다.

| WBP | 정확한 이름 | 정확한 타입 | Is Variable |
|---|---|---|---|
| `WBP_InventoryDuckov` | `UniformGridPanel_Items` | Uniform Grid Panel | On |
| `WBP_InventoryDuckov` | `Button_Close` | Button | On |
| `WBP_InventorySlotDuckov` | `Button_Select` | Button | On |
| `WBP_InventorySlotDuckov` | `Image_ItemIcon` | Image | On |
| `WBP_InventorySlotDuckov` | `Text_Quantity` | Text Block | On |

### 10.2 Optional BindWidget

Optional은 없어도 Compile되지만 이 가이드의 1차 기능에 `제작 필수`로 표시한 항목은 실제 화면 기능을 위해 반드시 만든다.

| WBP | 이름 | 타입 | 1차 제작 |
|---|---|---|---|
| Duckov Root | `Text_Capacity` | Text Block | 필수 |
| Duckov Root | `Overlay_Root` | Overlay | 필수 |
| Duckov Root | `Border_BackgroundDim` | Border | 필수 |
| Duckov Root | `Panel_PlayerInventory` | Widget 계열 (`Size Box` 사용) | 필수 |
| Duckov Root | `Border_PlayerPanel` | Border | 패널 Rounded/Outline 적용 |
| Duckov Root | `Panel_ExternalContainer` | Widget 계열 (`Size Box` 사용) | 필수 |
| Duckov Root | `Text_PlayerContainerName` | Text Block | 필수 |
| Duckov Root | `HorizontalBox_Header` | Horizontal Box | Sort 런타임 생성에 필수 |
| Duckov Root | `Button_Sort` | Button | 선택; 없으면 C++가 생성 |
| Duckov Root | `CanvasPanel_TooltipLayer` | Canvas Panel | 필수 |
| Duckov Root | `CanvasPanel_ContextMenuLayer` | Canvas Panel | 필수 |
| Duckov Slot | `Overlay_Slot` | Overlay | 필수 |
| Duckov Slot | `Border_Background` | Border | 필수 |
| Duckov Slot | `SizeBox_Slot` | Size Box | 필수 |
| Duckov Slot | `SizeBox_Icon` | Size Box | 필수 |
| Duckov Slot | `ScaleBox_Icon` | Scale Box | 필수 |
| Duckov Slot | `Image_Selection` | Image | 필수 |
| Duckov Slot | `Border_Unavailable` | Border | 선택 |
| Duckov Slot | `Text_ItemName` | Text Block | 필수 |
| Duckov Slot | `Border_Hover` | Border | 필수 |
| Duckov Slot | `Border_NameGradient` | Border | 이름 하단 Band |
| Duckov Slot | `Border_QuantityBadge` | Border | 수량 Badge |
| Tooltip | `Border_Tooltip` | Border | Tooltip Rounded Panel |
| Tooltip | `Image_TooltipIcon` | Image | 필수 |
| Tooltip | `Text_TooltipName` | Text Block | 필수 |
| Tooltip | `Text_TooltipQuantity` | Text Block | 필수 |
| Tooltip | `Text_TooltipDescription` | Text Block | 필수 |
| Tooltip | `Text_TooltipCategory` | Text Block | 필수 |
| Tooltip | `Text_TooltipFlavor` | Text Block | 필수 |
| Tooltip | `Text_TooltipDisabledReason` | Text Block | 필수 |
| Context Menu | `VerticalBox_Actions` | Vertical Box | 필수 |
| Context Menu | `Text_ContextMenuTitle` | Text Block | 필수 |
| Context Menu | `Border_ContextMenu` | Border | Context Rounded Panel |
| Context Action | `Button_Action` | Button | 필수 |
| Context Action | `Text_ActionLabel` | Text Block | 필수 |
| Context Action | `Text_DisabledReason` | Text Block | 선택 |

다음 상속 Optional 이름은 Legacy WBP와 Native Fallback 호환을 위해 C++에 남아 있지만 Duckov Root에는 만들 필요가 없다.

| 이름 | C++ 타입 | Duckov에서 생략하는 이유 |
|---|---|---|
| `Image_SelectedIcon` | Image | Tooltip 아이콘 사용 |
| `Text_SelectedName` | Text Block | 슬롯/Tooltip 이름 사용 |
| `Text_SelectedQuantity` | Text Block | 슬롯/Tooltip 수량 사용 |
| `Text_SelectedDescription` | Text Block | Tooltip 설명 사용 |
| `Text_SelectedCategory` | Text Block | Tooltip 분류 사용 |
| `Text_SelectedFlavor` | Text Block | Tooltip Flavor 사용 |
| `Text_EmptyHint` | Text Block | 1차 전체화면 레이아웃에서 생략 |
| `HorizontalBox_Actions` | Horizontal Box | Context Menu 사용 |
| `Border_InventoryWindow` | Border | Player Panel 사용 |
| `Text_DisabledReason` | Text Block | Tooltip의 Disabled Reason 사용 |
| `Button_Use` | Button | Context Action 사용 |
| `Button_Drop` | Button | Context Action 사용 |
| `Button_Inspect` | Button | Context Action 사용 |

## 11. Open/Close Blueprint Animation 제작

C++가 이미 Root Render Opacity/Scale/Translation과 닫기 완료 시점을 제어한다. Blueprint Animation은 **Player Panel과 장식만 추가로 움직이는 짧은 연출**로 만든다. Animation이 없어도 기능은 완전하게 동작한다.

### 11.1 Anim_Open

1. `WBP_InventoryDuckov`를 열고 Designer 하단 `Animations` 패널의 `+ Animation`을 누른다.
2. 이름을 `Anim_Open`으로 변경한다.
3. Timeline에서 `+ Track`을 눌러 `Panel_PlayerInventory`를 추가한다.
4. `Render Transform > Translation`과 `Render Opacity` 트랙을 추가한다.
5. `0.00초`: Translation X `-28`, Opacity `0` 키를 추가한다.
6. `0.16초`: Translation X `0`, Opacity `1` 키를 추가한다.
7. Graph로 이동해 `Event Construct`를 만든다.
8. `Play Animation` 노드를 추가하고 Animation에 `Anim_Open`, Start At Time `0`, Num Loops `1`, Play Mode `Forward`를 지정한다.

Root `Overlay_Root` 자체를 Animation Track에 넣지 않는다. C++ Open Transition과 충돌한다.

### 11.2 Anim_Close

1. Animations에서 `Anim_Close`를 만든다.
2. `Panel_PlayerInventory`의 Translation과 Opacity를 추가한다.
3. `0.00초`: Translation X `0`, Opacity `1`.
4. `0.14초`: Translation X `-24`, Opacity `0`.
5. Graph의 `Event Construct` 뒤에 `Bind Event to OnCloseRequested`를 추가한다.
6. 바인딩할 Custom Event 이름을 `PlayDuckovCloseAnimation`으로 만든다.
7. Custom Event에서 `Play Animation(Anim_Close)`을 호출한다.

C++ `Close Transition Duration` 기본값이 `0.15초`이므로 Anim_Close는 반드시 `0.15초 이하`로 둔다. Animation Finished에서 `Remove From Parent`, `Request Close`, `Close Inventory`를 호출하지 않는다. 제거와 입력 복원은 `InventoryUIComponent`가 담당한다.

## 12. Project Settings에서 새 UI 선택

1. 다섯 WBP를 모두 Compile/Save한다.
2. `Edit > Project Settings`를 연다.
3. 왼쪽에서 `JM Plugins > Inventory`를 선택한다.
4. `UI > Default Inventory Widget Class`를 `WBP_InventoryDuckov`로 지정한다.
5. `Upgrade Legacy Default Widget To Native`는 새 Duckov 클래스에는 영향을 주지 않으므로 그대로 켜도 된다.
6. 게임에서 사용하는 Actor/PlayerController Blueprint를 연다.
7. Components에서 `InventoryUIComponent`를 선택한다.
8. Details의 `Inventory > UI > Inventory Widget Class`를 확인한다.
   - 값이 `None`이면 Project Settings 기본값을 사용한다.
   - 다른 클래스가 직렬화돼 있으면 `WBP_InventoryDuckov`로 직접 바꾸거나 오른쪽 Reset 화살표로 `None`으로 되돌린다.
9. Blueprint를 Compile/Save하고 Editor를 재실행한 뒤 테스트한다.

Project Settings보다 Component의 `Inventory Widget Class` 값이 우선한다.

## 13. 기존 UI 또는 Native Fallback으로 되돌리기

### 기존 WBP_Inventory로 복귀

1. `Project Settings > JM Plugins > Inventory`로 이동한다.
2. `Upgrade Legacy Default Widget To Native`를 **끄는 것을 권장**한다.
3. `Default Inventory Widget Class`를 `/InventorySystem/Widget/WBP_Inventory`로 지정한다.
4. `InventoryUIComponent.Inventory Widget Class`에 Duckov override가 있으면 `WBP_Inventory`로 바꾸거나 Reset해 전역값을 사용한다.

Component에 Legacy `WBP_Inventory`가 직접 저장돼 있고 `Upgrade Legacy Default Widget To Native`가 켜져 있으면 BeginPlay에서 Native Fallback으로 자동 교체될 수 있다.

### Native Fallback으로 복귀

1. `Default Inventory Widget Class`에서 C++ 클래스 `InventoryWidgetBase`를 선택한다.
2. Component override는 Reset해 `None`으로 둔다.
3. Native Fallback은 `.uasset` 없이 C++가 Widget Tree를 생성한다.

## 14. 컴파일 오류별 해결법

| 증상/메시지 | 원인 | 해결 |
|---|---|---|
| `A required widget binding ... was not found` | 필수 BindWidget 이름 누락 | 10.1 표의 이름/타입/Is Variable을 확인한다. |
| `... has an incompatible type` | 이름은 같지만 타입이 다름 | 예: `Button_Close`를 Common Button이 아닌 기본 `Button`으로 만든다. 표의 타입으로 교체한다. |
| `UniformGridPanel_Items` 오류 | Grid 이름·타입 불일치 | Uniform Grid Panel을 만들고 정확히 이름 변경, Is Variable On. |
| `Button_Close` 또는 `Button_Select` 오류 | 필수 Button 누락 | 기본 UMG Button으로 만들고 정확한 이름, Is Variable On. |
| Parent Class를 찾을 수 없음 | Editor가 최신 DLL을 로드하지 않음 | Editor 종료 → Editor Target 빌드 → 재실행. Live Coding 상태에서 해결되지 않으면 완전 종료한다. |
| Parent Class가 `InventoryWidgetBase`로 남음 | Reparent 누락 | `File > Reparent Blueprint`에서 `InventoryDuckovWidgetBase` 선택. |
| Class Defaults에서 WBP 클래스가 안 보임 | 대상 WBP 미컴파일 또는 Parent 불일치 | 대상 WBP를 먼저 Compile/Save하고 Parent Class를 확인한다. |
| Context Menu가 뜨지만 비어 있음 | `VerticalBox_Actions` 또는 Action Widget Class 누락 | 정확한 Vertical Box 이름과 `WBP_InventoryContextAction` Class Default 확인. |
| Context Action 클릭이 안 됨 | `Button_Action` 누락/Hit Test 차단 | Button 이름·타입·Is Variable과 상위 Visibility를 확인한다. Canvas Layer는 Self Only여야 한다. |
| Tooltip이 안 뜸 | Tooltip Layer/Class 또는 Tooltip Widget 누락 | Root Class Defaults와 `CanvasPanel_TooltipLayer`를 확인한다. |
| 슬롯이 보이지 않음 | Slot Widget Class 또는 Grid 누락 | `Slot Widget Class=WBP_InventorySlotDuckov`, Grid 이름, Max Slots를 확인한다. |
| 모든 슬롯 클릭이 안 됨 | 전체 화면 Canvas/Border가 Visible로 입력 차단 | Tooltip/Context Layer는 `Not Hit-Testable (Self Only)`, Dim은 `Self & All Children`로 둔다. |
| 닫기 버튼이 두 번 동작함 | Blueprint OnClicked도 연결함 | `Button_Close`, `Button_Select`, `Button_Action`의 Blueprint OnClicked를 삭제한다. |
| 삭제한 Widget을 참조하는 Animation 오류 | 복제된 기존 Animation 트랙 잔존 | 복사본의 오래된 Animation 트랙을 삭제하고 Anim_Open/Close를 다시 만든다. |
| 기존 UI 선택 후 Native UI가 열림 | Legacy 자동 Upgrade 옵션이 켜짐 | `Upgrade Legacy Default Widget To Native`를 끄고 Component override도 확인한다. |
| 설정했지만 UI가 바뀌지 않음 | Component override가 전역 설정보다 우선 | 사용 중인 `InventoryUIComponent.Inventory Widget Class`를 Reset하거나 새 WBP로 지정한다. |

Compile 오류가 계속되면 Output Log에서 첫 번째 `LogBlueprint` 또는 `LogUMG` 오류부터 해결한다. 후속 오류는 첫 오류의 연쇄 결과일 수 있다.

## 15. 게임 실행 후 테스트 순서

1. PIE 실행 전 다섯 WBP와 소유 Actor Blueprint가 모두 Compile/Save 상태인지 확인한다.
2. PIE를 시작하고 Inventory Toggle 입력으로 연다.
3. 전체 화면 Dim, 좌측 하단 480×560 Player Panel, 오른쪽 External Panel 숨김을 확인한다.
4. Capacity가 `점유 슬롯 / 최대 슬롯` 형식으로 표시되는지 확인한다.
5. 빈 Inventory에서 최대 용량만큼 80×80 슬롯이 5열로 표시되는지 확인한다.
6. 아이템 한 개를 획득하고 아이콘, 이름, 수량 1일 때 수량 숨김을 확인한다.
7. 같은 아이템을 추가해 수량이 2 이상일 때 `xN` 표시를 확인한다.
8. 슬롯을 좌클릭하고 청록색 선택 표시가 해당 슬롯으로 이동하는지 확인한다.
9. 헤더가 `Backpack (점유 슬롯/최대 슬롯)` 형식인지 확인한다.
10. `Sort`를 눌러 수량이 큰 Stack부터 작은 Stack 순으로 배치되고 빈 슬롯은 뒤로 이동하는지 확인한다.
11. 아이템 슬롯을 드래그할 때 원본 슬롯은 흐려지고 아이콘·이름·수량이 포함된 슬롯 복제본이 마우스를 따라오는지 확인한다.
12. 복제본을 빈 슬롯에 드롭해 실제 위치가 이동하고, 다시 열어도 현재 Inventory 데이터 위치가 유지되는지 확인한다.
13. Grid 밖에 드롭했을 때 원본 위치와 수량이 바뀌지 않고 Hover 색이 초기화되는지 확인한다.
14. 아이템이 있는 슬롯 위로 드롭했을 때 두 슬롯이 바뀌지 않는지 확인한다.
15. 슬롯에 마우스를 올렸다가 벗어날 때 Hover 색이 즉시 원래 색으로 복구되는지 확인한다.
16. 슬롯에 마우스를 올려 Tooltip의 이름·아이콘·수량·설명이 표시되는지 확인한다.
17. 화면 네 모서리 슬롯에서 Tooltip이 화면 밖으로 나가지 않는지 확인한다.
18. 슬롯을 우클릭해 Context Menu가 열리는지 확인한다.
19. Use 가능한 아이템에서 Use를 눌러 기존 사용 결과가 발생하는지 확인한다.
20. Drop을 눌러 정확히 1개가 버려지는지 확인한다.
21. Inspect 가능한 아이템에서 Inspect가 나타나고 기존 Inspector가 열리는지 확인한다.
22. Inspector를 닫았을 때 Inventory가 다시 보이고 선택이 복구되는지 확인한다.
23. Context Menu가 열린 상태에서 ESC를 눌러 메뉴만 먼저 닫히는지 확인한다.
24. 다시 ESC를 눌러 Inventory가 닫히는지 확인한다.
25. 닫는 0.15초 동안 Tooltip/Context Menu가 즉시 제거되는지 확인한다.
26. Inventory를 다시 열어 Delegate 중복으로 한 클릭에 액션이 두 번 실행되지 않는지 확인한다.
27. Project Settings를 기존 `WBP_Inventory`로 바꿔 Legacy UI가 열리는지 확인한다.
28. `InventoryWidgetBase`를 선택해 Native Fallback이 열리는지 확인한다.
29. 테스트가 끝나면 원하는 최종 Widget Class로 되돌리고 PIE를 다시 시작한다.

## 16. 현재 1차 범위와 제한

실제 연결된 기능은 Player Inventory, 최대 용량 고정 Grid, 아이콘/이름/수량/좌클릭 선택, 수량 내림차순 정렬, 빈 슬롯 Drag 이동, Tooltip, Context Menu, Use, Drop One, Inspect, Capacity와 External Panel 숨김이다.

외부 Container 데이터 이동, Equipment, Hotbar, Stack Split, 총무게, 내구도, 가치, 등급, 즐겨찾기, 잠금은 아직 구현되지 않았다. 현재 Drag & Drop은 같은 Player Inventory 안에서 **전체 Stack을 빈 슬롯으로 이동**하는 범위만 지원하며, 아이템이 있는 슬롯과의 Swap/Merge는 하지 않는다. 현재 데이터 구조에 없는 값을 UI에서 임의로 표시하지 않는다.

## 17. C++ BindWidget 대조 기록

다음 Public Header의 `BindWidget` 및 `BindWidgetOptional` 선언을 기준으로 이 문서를 대조한다.

```text
InventoryWidgetBase.h
InventorySlotWidgetBase.h
InventoryDuckovWidgetBase.h
InventoryDuckovSlotWidgetBase.h
InventoryTooltipWidgetBase.h
InventoryContextMenuWidgetBase.h
InventoryContextActionWidgetBase.h
```

UE 5.7 현재 코드 기준 선언은 총 57개다. 필수 `BindWidget` 5개와 Optional 선언 52개이며, `Text_DisabledReason`은 Root Base와 Context Action Base에 각각 선언되어 이름은 같지만 소유 클래스가 다르다. 10절에는 필수 5개, Duckov 제작에 사용하는 Optional, Duckov에서 의도적으로 생략하는 Legacy Optional을 모두 기록했다. 문서 이름은 C++ 식별자의 대소문자와 밑줄을 그대로 사용한다.
