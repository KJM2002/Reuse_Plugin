---
title: "Inventory Widget 배치 가이드"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Inventory Widget 배치 가이드

이 문서는 Unreal Editor의 UMG Designer에서 커스텀 `WBP_Inventory`와
`WBP_InventorySlot`을 만들 때 사용하는 최종 배치 기준이다.

기본 네이티브 UI를 그대로 사용할 경우에는 별도 Widget Blueprint가 필요 없다.
커스텀 디자인이 필요할 때만 아래 순서대로 만든다.

## 1. 사전 설정

### WBP_Inventory

1. `User Widget`을 생성한다.
2. Parent Class를 `InventoryWidgetBase`로 지정한다.
3. 이름을 `WBP_Inventory`로 지정한다.
4. Class Defaults에서 `Is Focusable`을 활성화한다.
5. `Slot Widget Class`에 아래에서 만든 `WBP_InventorySlot`을 지정한다.
6. `Grid Column Count`는 `5`, `Show Empty Slots`는 활성화한다.

### WBP_InventorySlot

1. `User Widget`을 생성한다.
2. Parent Class를 `InventorySlotWidgetBase`로 지정한다.
3. 이름을 `WBP_InventorySlot`로 지정한다.
4. Class Defaults에서 `Slot Display Size`를 `96`, `Icon Display Size`를 `72`로 지정한다.

Widget 이름과 타입이 C++ 바인딩의 계약이다. 아래 표에서 `필수`인 Widget은 이름,
타입, `Is Variable`을 모두 정확히 맞춘다.

## 2. WBP_Inventory 전체 계층

```text
WBP_Inventory
└─ Overlay_Root                                      [Optional]
   ├─ Border_BackgroundDim                           [Optional]
   └─ SizeBox_InventoryWindow                        [Design]
      └─ Border_InventoryWindow                      [Optional]
         └─ VerticalBox_Main                         [Design]
            ├─ HorizontalBox_Header                  [Design]
            │  ├─ Text_InventoryTitle                [Design]
            │  ├─ Spacer_Header                      [Design]
            │  ├─ Text_Capacity                      [Optional]
            │  └─ Button_Close                       [필수]
            ├─ HorizontalBox_Content                 [Design]
            │  ├─ Border_LeftInventoryPanel          [Design]
            │  │  └─ ScrollBox_Items                 [Design]
            │  │     └─ UniformGridPanel_Items       [필수]
            │  └─ Border_ItemDetailPanel             [Design]
            │     └─ VerticalBox_Detail              [Design]
            │        ├─ SizeBox_SelectedIcon          [Design]
            │        │  └─ Image_SelectedIcon         [필수]
            │        ├─ Text_SelectedName             [필수]
            │        ├─ Text_SelectedCategory         [Optional]
            │        ├─ Text_SelectedQuantity         [필수]
            │        ├─ ScrollBox_Description         [Design]
            │        │  └─ VerticalBox_Description
            │        │     ├─ Text_SelectedDescription [필수]
            │        │     └─ Text_SelectedFlavor      [Optional]
            │        ├─ Text_EmptyHint                [Optional]
            │        ├─ Text_DisabledReason           [Optional]
            │        └─ HorizontalBox_Actions         [Optional]
            │           ├─ Button_Use                 [필수]
            │           ├─ Button_Inspect             [필수]
            │           └─ Button_Drop                [필수]
            └─ HorizontalBox_Footer                   [Design]
               ├─ Text_InputHint                      [Design]
               ├─ Spacer_Footer                       [Design]
               └─ Text_CloseHint                      [Design]
```

`Design` 표시는 C++에서 찾지 않으므로 자유롭게 이름을 바꿀 수 있다.

## 3. WBP_Inventory 필수 바인딩

| 이름 | 타입 | 역할 |
|---|---|---|
| `UniformGridPanel_Items` | Uniform Grid Panel | 슬롯을 런타임에 생성·배치 |
| `Image_SelectedIcon` | Image | 선택 아이템 아이콘 |
| `Text_SelectedName` | Text Block | 아이템 이름 |
| `Text_SelectedQuantity` | Text Block | 선택 수량 |
| `Text_SelectedDescription` | Text Block | 설명 |
| `Button_Use` | Button | Use 요청 |
| `Button_Drop` | Button | Drop 요청 |
| `Button_Inspect` | Button | Inspector 요청 |
| `Button_Close` | Button | Close 전환 요청 |

필수 Widget은 모두 `Is Variable`을 활성화한다. Event Graph에 `OnClicked`를 다시
연결하지 않는다. 부모 C++ 클래스가 이미 연결하므로 중복 연결하면 한 번의 클릭이
두 번 실행될 수 있다.

## 4. 선택 바인딩

| 이름 | 타입 | 권장 초기 상태 | 역할 |
|---|---|---|---|
| `Text_Capacity` | Text Block | Visible | `현재 / 최대` 표시 |
| `Text_SelectedCategory` | Text Block | Collapsed | Category가 있을 때 표시 |
| `Text_SelectedFlavor` | Text Block | Collapsed | Flavor Text가 있을 때 표시 |
| `Text_EmptyHint` | Text Block | Self Hit Test Invisible | 빈 상태 안내 |
| `Text_DisabledReason` | Text Block | Collapsed | 사용 불가 사유 |
| `HorizontalBox_Actions` | Horizontal Box | Collapsed | 가능한 액션이 있을 때 표시 |
| `Overlay_Root` | Overlay | Visible | 전체 전환 기준 Root |
| `Border_BackgroundDim` | Border | Visible | 게임 화면 어둡게 처리 |
| `Border_InventoryWindow` | Border | Visible | Inventory 본체 |

선택 Widget을 배치했다면 `Is Variable`을 활성화하고 이름을 정확히 맞춘다.

## 5. 화면 배치값

### Root와 Window

| 항목 | 값 |
|---|---|
| `Overlay_Root` | 화면 전체 Fill |
| `Border_BackgroundDim` | Fill, 검정 Alpha `0.72~0.80` |
| `SizeBox_InventoryWindow` | `1220×760` |
| Window Alignment | Horizontal/Vertical Center |
| `Border_InventoryWindow` Padding | Left/Right `34`, Top `24`, Bottom `20` |
| Window 배경 | 거의 검정인 Dark Gray, Alpha `0.98` |

Background Blur는 기본 구조에 넣지 않는다. 필요한 프로젝트만
`Border_BackgroundDim`과 Window 사이에 약한 Blur를 추가한다.

### Header

| 항목 | 값 |
|---|---|
| Header 아래 Padding | `18` |
| Title Font Size | `29` |
| Capacity Font Size | `15` |
| Capacity 오른쪽 Padding | `22` |
| Close Text | `×` |
| Close Button Content Padding | 가로 `18`, 세로 `10` |

Header는 `Title → Fill Spacer → Capacity → Close` 순서로 배치한다.

### Content

| 항목 | 값 |
|---|---|
| Left Panel | Fill |
| Left Panel Padding | `18` |
| Left와 Detail 사이 | `28` |
| Detail Width | `390` |
| Detail Padding | 가로 `24`, 세로 `18` |

밝은 세로 Divider는 넣지 않는다. 두 패널의 배경 명도 차이와 28px 간격만 사용한다.

### Grid

| 항목 | 값 |
|---|---|
| Columns | `5` |
| Minimum Cell | `108×108` |
| Grid Slot Padding | `6` |
| Slot Widget | `96×96` |
| Icon 안전 영역 | `72×72` |
| ScrollBox Slot Alignment | Left / Top |
| ScrollBar | 필요 없으면 Collapsed |

Designer에서 Grid 안에 슬롯을 직접 넣지 않는다. C++가 Inventory Capacity만큼
`WBP_InventorySlot`을 생성한다.

### Detail

| 항목 | 값 |
|---|---|
| Icon 영역 높이 | `220` |
| Icon 아래 Padding | `18` |
| Name Font Size | `26` |
| Name 아래 Padding | `3` |
| Category Font Size | `13` |
| Category 아래 Padding | `10` |
| Quantity Font Size | `14` |
| Quantity 아래 Padding | `18` |
| Description Font Size | `16`, Auto Wrap |
| Flavor Font Size | `14`, Auto Wrap |
| Description과 Flavor 사이 | `16` |
| Action Panel 위 Padding | `18` |
| Action Button 사이 | `8` |

Detail의 남는 세로 공간은 `ScrollBox_Description`이 Fill하도록 한다. 액션 버튼은
Description 아래 고정 영역에 둔다.

### Footer

| 항목 | 값 |
|---|---|
| Footer 위 Padding | `18` |
| Font Size | `13` |
| 왼쪽 | `ENTER 선택` |
| 오른쪽 | `ESC 닫기` |

실제 Input Action이 없는 `E/F/R` 키는 문구에 추가하지 않는다.

## 6. WBP_InventorySlot 계층

```text
WBP_InventorySlot
└─ SizeBox_Slot                              [Optional, 권장]
   └─ Button_Select                          [필수]
      └─ Overlay_Slot                        [Optional, 권장]
         ├─ Border_Background                [Optional, 권장]
         ├─ SizeBox_Icon                     [Optional, 권장]
         │  └─ ScaleBox_Icon                 [Optional, 권장]
         │     └─ Image_ItemIcon             [필수]
         ├─ Border_Unavailable               [Optional]
         ├─ Image_Selection                  [Optional]
         └─ Text_Quantity                    [필수]
```

### 슬롯 필수 바인딩

| 이름 | 타입 | 설정 |
|---|---|---|
| `Button_Select` | Button | Focusable 활성화 |
| `Image_ItemIcon` | Image | Center, Scale To Fit |
| `Text_Quantity` | Text Block | Right / Bottom |

### 슬롯 선택 바인딩

| 이름 | 타입 | 설정 |
|---|---|---|
| `SizeBox_Slot` | Size Box | `96×96`, Clip To Bounds |
| `Overlay_Slot` | Overlay | Fill |
| `Border_Background` | Border | Fill |
| `SizeBox_Icon` | Size Box | `72×72`, Center |
| `ScaleBox_Icon` | Scale Box | Scale To Fit |
| `Image_Selection` | Image | Fill, 초기 Collapsed |
| `Border_Unavailable` | Border | Fill, 초기 Collapsed |

`Text_Quantity`의 내부 여백은 Right `8`, Bottom `6`을 사용한다. 수량이 1이면 C++가
자동으로 숨긴다.

## 6.1 스크린샷 기준: Details 패널 입력 순서

아래 값은 `WBP_InventorySlot`의 Hierarchy를 위에서 아래로 하나씩 선택하면서 입력한다.
괄호 안은 Unreal Editor Details 패널에서 찾을 항목 이름이다.

### 1단계 — WBP_InventorySlot 자체

Designer의 빈 곳을 클릭한 뒤 `Class Defaults`를 연다.

```text
Slot Display Size = 96
Icon Display Size = 72
Quantity Padding:
  Left   = 0
  Top    = 0
  Right  = 8
  Bottom = 6
```

`Slot Background Texture`는 **비워 둔다**. 이전 `Grid` Texture는 176px 슬롯 기준으로
제작되어 96px에서 9-slice 가장자리가 원형으로 깨져 보인다. 비워 두면 C++가 해상도
독립적인 Rounded Box를 사용한다.

### 2단계 — SizeBox_Slot

Hierarchy에서 `SizeBox_Slot`을 선택한다.

```text
Layout > Width Override  = 96
Layout > Height Override = 96
Clipping                 = Clip to Bounds
Visibility               = Visible
Render Opacity           = 1.0
```

Designer 화면에서 슬롯이 너무 크게 보인다면 대부분 이 값이 아직 `176`이기 때문이다.
`Min Desired Width/Height`가 있다면 `0`으로 둔다.

### 3단계 — Button_Select

```text
Slot (Size Box Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill

Interaction:
  Is Focusable = true
  Click Method = Mouse Down 또는 Precise Click

Style:
  Normal Tint   Alpha = 0
  Hovered Tint  Alpha = 0
  Pressed Tint  Alpha = 0
  Disabled Tint Alpha = 0

Content Padding = 0
```

버튼 자체에 노란색/회색 배경을 넣지 않는다. 상태 배경은
`Border_Background`가 담당한다. Event Graph에 `OnClicked`를 만들지 않는다.

### 4단계 — Overlay_Slot

```text
Slot (Button Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill
  Padding              = 0

Visibility = Self Hit Test Invisible
Clipping   = Clip to Bounds
```

Overlay 자식 순서는 반드시 다음과 같이 유지한다.

```text
1. Border_Background
2. SizeBox_Icon
3. Border_Unavailable
4. Image_Selection
5. Text_Quantity
```

아래쪽에 있는 자식이 화면에서 더 앞에 그려진다.

### 5단계 — Border_Background

```text
Slot (Overlay Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill
  Padding              = 0

Content Padding = 1
Visibility      = Self Hit Test Invisible
```

기본값은 C++가 다음과 같은 해상도 독립 Rounded Box로 설정한다.

```text
Draw As     = Rounded Box
Tint        = R 0.035 / G 0.039 / B 0.043 / A 0.96
Corner Radius = 2
Outline Width = 1
Outline Color = R 0.16 / G 0.17 / B 0.17 / A 0.55
```

Hex 기준 기본 배경은 약 `#090A0BF5`, 외곽선은 약 `#292B2B8C`다.
C++가 Hover/Selected 상태에서 Brush Color를 자동 변경하므로 Blueprint Animation으로
같은 색을 다시 덮어쓰지 않는다.

### 6단계 — SizeBox_Icon

```text
Slot (Overlay Slot):
  Horizontal Alignment = Center
  Vertical Alignment   = Center
  Padding              = 0

Width Override  = 72
Height Override = 72
Clipping        = Clip to Bounds
Visibility      = Self Hit Test Invisible
```

스크린샷 중앙의 작은 사각형만 보이는 것은 Item Icon이 아직 지정되지 않은 Designer
Preview 상태라 정상이다.

### 7단계 — ScaleBox_Icon

```text
Slot (Size Box Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill

Stretch           = Scale to Fit
Stretch Direction = Both
User Specified Scale = 1.0
Ignore Inherited Scale = false
```

### 8단계 — Image_ItemIcon

```text
Slot (Scale Box Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill

Brush > Image      = None
Brush > Draw As    = Image
Brush > Image Size = X 72 / Y 72
Color and Opacity  = White
Visibility         = Collapsed
Clipping           = Clip to Bounds
```

런타임에 C++가 Item Definition의 Icon을 넣고 Visibility를 바꾼다. Designer 확인용
Texture를 넣었다면 최종 저장 전에 다시 `None`으로 비운다.

### 9단계 — Border_Unavailable

```text
Slot (Overlay Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill

Brush Color = R 0.00 / G 0.00 / B 0.00 / A 0.48
Padding     = 0
Visibility  = Collapsed
```

Hit Test를 막지 않도록 런타임 표시 상태는 `Self Hit Test Invisible`을 사용한다.

### 10단계 — Image_Selection

```text
Slot (Overlay Slot):
  Horizontal Alignment = Fill
  Vertical Alignment   = Fill
  Padding              = 0

Brush > Draw As   = Border
Brush > Margin    = Left 0.04 / Top 0.04 / Right 0.04 / Bottom 0.04
Color and Opacity = R 0.68 / G 0.61 / B 0.42 / A 0.72
Visibility        = Collapsed
```

Brush Image는 **None**으로 둔다. 이전 `Select` Texture는 사용하지 않는다. C++가
Texture 대신 1.5px Rounded Box 외곽선을 만들기 때문에 DPI가 달라져도 모서리가
찌그러지지 않는다.

Hex 기준 Accent는 약 `#AD9C6BB8`이다.

### 11단계 — Text_Quantity

```text
Slot (Overlay Slot):
  Horizontal Alignment = Right
  Vertical Alignment   = Bottom
  Padding:
    Left   = 0
    Top    = 0
    Right  = 8
    Bottom = 6

Text                = x5        // Designer Preview 전용
Font Size           = 14
Typeface            = Regular 또는 Medium
Color and Opacity   = R 0.87 / G 0.86 / B 0.82 / A 0.95
Justification       = Center
Auto Wrap Text      = false
Visibility          = Self Hit Test Invisible
Shadow Offset       = X 1 / Y 1
Shadow Color        = R 0 / G 0 / B 0 / A 0.75
```

런타임에는 C++가 `x수량` 형식으로 덮어쓴다. 수량이 1이면 자동으로 `Collapsed`된다.

### 12단계 — Compile 후 확인

```text
1. Compile
2. Save
3. WBP_Inventory의 Slot Widget Class가 WBP_InventorySlot인지 확인
4. PIE 실행
5. 아이템 없음: 배경만 표시
6. 아이템 1개: 아이콘 표시, 수량 숨김
7. Stack 5개: 우측 아래 x5 표시
8. Hover: 배경만 살짝 밝아짐
9. Selected: 약한 Accent + 아이콘 1.04 Scale
```

스크린샷처럼 Preview 슬롯이 약 300px 이상으로 보이면 `SizeBox_Slot`의 Width/Height와
Class Defaults의 `Slot Display Size` 중 하나가 아직 이전 값인지 다시 확인한다.

## 7. 슬롯 상태 디자인

| 상태 | 배경 | Border/Selection | 아이콘 |
|---|---|---|---|
| Empty | 매우 어두운 회색, Alpha 약 `0.62` | 없음 | 숨김 |
| Normal | Dark Gray | 얇고 낮은 명도 | Scale `1.0` |
| Hovered | 배경을 약간 밝게 | 약한 강조 | Scale `1.0` |
| Selected | 어두운 Olive Gray | Accent Alpha 약 `0.72` | Scale `1.04` |
| Disabled | Normal보다 어둡게 | 필요 시 약한 Overlay | 낮은 Opacity |

강한 노란색 테두리, Glow, Bounce는 사용하지 않는다.

## 8. 액션 버튼

Button 안에는 각각 한국어 Text를 둔다.

```text
Button_Use     → 사용
Button_Inspect → 조사
Button_Drop    → 버리기
Button_Close   → ×
```

초기 Visibility는 `Collapsed`여도 된다. C++가 선택 아이템의
`bCanUse`, `bCanDrop`, `bCanInspect`에 따라 표시 상태를 갱신한다.

## 9. 애니메이션

별도의 UMG Animation Track은 필수가 아니다. 부모 C++가 전체 Widget에 다음 전환을
적용한다.

```text
Open  0.22초: Opacity 0→1, Scale 0.975→1, Translation Y 12→0
Close 0.15초: Opacity 1→0, Scale 1→0.975, Translation Y 0→12
```

Blueprint Animation을 추가한다면 부모 전환과 같은 Root Transform을 중복 조작하지
않는다. 장식 요소의 지연 등장처럼 충돌하지 않는 트랙만 추가한다.

## 10. 최종 연결

1. Project Settings → JM Plugins → Inventory를 연다.
2. 커스텀 WBP를 쓸 경우 `Default Inventory Widget Class`에 `WBP_Inventory`를 지정한다.
3. 플러그인의 레거시 `WBP_Inventory`를 계속 쓸 경우에만
   `Upgrade Legacy Default Widget To Native`를 끈다.
4. `WBP_Inventory`의 `Slot Widget Class`에 `WBP_InventorySlot`을 지정한다.
5. Compile 시 BindWidget 오류가 없는지 확인한다.
6. 빈 Inventory, 아이템 1개, Stack, 선택 아이템 제거를 PIE에서 확인한다.
7. 1280×720, 1920×1080과 프로젝트의 실제 DPI Curve에서 잘림을 확인한다.

## 11. 흔한 오류

- 슬롯 간격이 넓음: Grid가 Fill 정렬인지, Slot Size가 이전 값 `176`인지 확인한다.
- 아이콘이 찌그러짐: `SizeBox_Icon → ScaleBox_Icon → Image_ItemIcon` 순서를 확인한다.
- 버튼이 두 번 실행됨: Event Graph의 중복 `OnClicked` 연결을 제거한다.
- ESC가 동작하지 않음: `WBP_Inventory.Is Focusable`을 활성화한다.
- 새 UI가 보이지 않음: Component에 Custom WBP가 명시되어 있는지 확인한다.
- Detail이 남음: 빈 Slot의 `Button_Select`를 비활성화하지 않는다.
- Custom WBP가 네이티브 UI로 교체됨: 레거시 플러그인 WBP를 쓰는 경우
  `Upgrade Legacy Default Widget To Native`를 끈다.
- 빈 슬롯이 원형으로 깨짐: `Slot Background Texture`와 `Border_Background` Brush에서
  이전 `Grid` Texture를 제거한다.
- 선택 테두리가 노랗고 거침: `Image_Selection` Brush에서 이전 `Select` Texture를
  제거한다. C++ Rounded Outline을 사용한다.
