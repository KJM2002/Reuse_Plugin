# 변경 기록

## Unreleased

- Added `UseActionTextOverride`, `DropActionTextOverride`, and
  `InspectActionTextOverride` to the context-menu Widget Blueprint defaults.
  Empty overrides preserve the existing item/system text.
- Added click-to-loot while preserving drag-and-drop, ItemId-based stack
  consolidation during sorting, and a bounded quantity picker for stack drops.
- Added persistent external inventory containers, weighted DataTable loot generation,
  atomic cross-inventory move/split/swap operations, weight limits, reusable loot
  actors, and two-panel Duckov UI transfer gestures.
- Added an opt-in Duckov-style C++ presentation layer with compact named slots,
  hover tooltip, InstanceId-safe Use/Drop/Inspect context actions, popup cleanup,
  pure presentation helpers, tests, and an Editor authoring guide. Existing WBP
  assets and the native fallback remain unchanged.
- Added five opt-in Duckov Widget Blueprints under `/Game/UI/Inventory` with a
  translucent navy panel, blue-gray outlines, teal hover/selection feedback,
  compact 96 px slots, a lower name band, and a top-right quantity badge.
- Added Duckov Backpack occupied/max labeling, quantity-descending sorting,
  explicit left-click selection, and transactional whole-stack drag movement
  into empty player inventory slots. Hotbar data remains intentionally out of scope.
- Fixed Duckov Blueprint slot alignment so empty-cell backgrounds and pointer hit
  areas fill the entire 96 px cell, increased empty-grid contrast, and anchored
  the Backpack panel to the lower-left presentation area.
- Fixed stale hover styling after pointer exit and drag traversal. Dragging now
  shows a translucent copy of the complete slot under the pointer, dims the
  source slot, and restores all visual state when a drop is cancelled outside.
- Refined the Duckov presentation to a five-column 80 px Backpack grid with
  panel-only background blur, 14 px rounded panel framing, compact spacing,
  styled name/quantity bands, hover/selection scaling, and consistent
  Normal/Hovered/Pressed treatments for Sort, Close, and context actions.
- Empty pickup/inspect interaction text is now respected, allowing designers to hide a prompt intentionally.
- Inventory-to-Inspector transitions now keep the full-screen dim backdrop opaque while only the inventory window animates, preventing a bright world-frame flash.
- Inventory inspection now fades the Inventory out before opening Item Inspector and fades it back in after the Inspector closes.

## 0.5.0

- `WBP_Inventory`와 `WBP_InventorySlot` Designer Tree를 네이티브 0.5 UI와 동일한 편집 가능한 Widget Blueprint 구성으로 재작성
- 프로젝트 기본 Inventory Widget을 `WBP_Inventory`로 연결하고 Legacy Native 자동 교체를 비활성화
- Native slot Widget Tree를 Slate 생성 전에 조립하여 획득한 아이템과 빈 슬롯이 Grid에 정상 표시되도록 수정
- 상세 아이콘을 220×220 Scale To Fit 영역에 배치하고 저해상도 원본의 강제 확대를 방지

- WBP 없이도 동작하는 Header/Content/Footer 기반 네이티브 Inventory UI 추가
- 슬롯을 96px, 셀 간격을 12px로 정돈하고 Hover/Selected/Icon Scale 상태 피드백 추가
- 용량, Category, Flavor Text, 빈 상태와 조건부 Use/Inspect/Drop 액션 표시 추가
- 이전 선택 유지, 첫 유효 아이템 자동 선택, 선택 아이템 제거 후 안전한 Selection 복구
- 0.22초 Open / 0.15초 Close Fade·Scale·Translation 전환과 빠른 Toggle 반전 처리
- Modal Gameplay Event를 통한 Objective/Interaction HUD 자동 억제·복원
- 설정 가능한 Open/Close/Hover/Select/Confirm Sound Soft Reference 추가
- UI Selection Recovery 자동화 테스트 추가
- UMG Designer용 최종 Widget 계층·바인딩·배치값 가이드 추가
- Slot Designer의 Details 패널 항목별 입력값과 `x수량` 표시 형식 정리
- 레거시 Grid/Select Texture의 96px 9-slice 깨짐을 해상도 독립 Rounded Brush로 교체
- Generated Class 경로에서도 레거시 WBP 자동 업그레이드가 적용되도록 경로 판정 수정

## 0.4.0

- `Can Use`가 켜진 아이템은 별도 Use Effect가 없어도 사용자 Actor/Pawn/Controller의 Use Receiver로 자동 전달
- Inventory Use 버튼 활성화가 Use Effect 지정 여부에 의존하지 않도록 단순화
- 특수 효과가 필요한 아이템만 명시적 Use Effect를 사용

## 0.3.0

- `IInventoryItemUseReceiverInterface` 범용 아이템 사용 대상 계약 추가
- `UInventoryUseOnActorComponentsEffect`를 추가해 Door 같은 선택 시스템을 Inventory가 직접 참조하지 않고 Use 버튼과 연결
- 예제 Old Key를 현재 대상 Use 방식으로 설정

## 0.1.0

- 재사용 가능한 Runtime Plugin과 Developer Settings 추가
- 데이터 기반 Item Definition과 인스턴스형 Use Effect 추가
- 고정 슬롯, 스택, 부분 추가 결과, 제거, 사용, 버리기, 이벤트, 저장용 데이터 추가
- 재사용 가능한 World Pickup Actor 추가
- UMG 기반 Widget과 Enhanced Input UI 조정 컴포넌트 추가
- `UInventorySlotWidgetBase`와 BindWidget 기반 자동 Grid·상세 정보·버튼 처리 추가
- 인벤토리 오픈 중 Jump를 포함한 Pawn 입력 차단 및 Mapping Context 기반 Toggle Key 닫기 추가
- JMInspectable 조사 종료 후 안전하게 획득하는 BaseUpgrade Adapter Actor 추가
- Inspector Bridge와 BaseUpgrade용 ItemInspector Adapter 추가
- 초기 자동화 테스트와 설정 문서 추가
