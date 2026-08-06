# 재사용형 인벤토리 시스템

`InventorySystem`은 데이터 기반 아이템, 스택형 인벤토리 저장소, 월드 아이템 획득·버리기, 교체 가능한 UMG UI, Enhanced Input 연결, 저장용 데이터, 아이템 조사 연동 지점을 제공하는 UE 5.7 Runtime Plugin이다.

## 주요 클래스

- `UInventoryComponent`: 인벤토리 상태와 모든 변경 규칙을 관리한다.
- `UInventoryItemDefinition`: 아이템 제작에 사용하는 Primary Data Asset이다.
- `UInventoryItemUseEffect`: Blueprint와 C++에서 확장할 수 있는 아이템 사용 효과다.
- `UInventoryUseOnActorComponentsEffect`: 선택한 아이템을 사용자 Actor의 범용 Use Receiver에 전달한다.
- `AInventoryWorldItemPickup`: 재사용 가능한 월드 아이템 획득·버리기 액터다.
- `UInventoryUIComponent`: 위젯 수명, 커서와 입력 상태, 토글 입력 연결을 관리한다.
- `UInventoryWidgetBase`: BindWidget으로 전체 Grid, 상세 정보와 버튼 동작을 자동 관리한다.
- `UInventorySlotWidgetBase`: BindWidget으로 Slot 아이콘, 수량과 선택 상태를 자동 관리한다.
- `UInventoryItemInspectorBridge`: 외부 아이템 조사 시스템을 연결하는 추상 연동 계층이다.
- `UReuseInventoryInspectorBridge`: 현재 프로젝트의 ItemInspector를 연결하는 Adapter다.

Runtime 코드에서는 프로젝트 전용 Player, GameMode, HUD 또는 특정 인벤토리 구현으로 Cast하지 않는다. UI 갱신을 위한 Tick도 사용하지 않는다.

0.5부터 Project Settings의 Widget Class가 비어 있거나 기본값이면 상업용 공포 게임 톤의
네이티브 Header/Content/Footer UI가 사용된다. 기존 `WBP_Inventory`를 계속 지정해도
호환되며, 새 선택/액션/전환/HUD 이벤트 동작은 그대로 적용된다.

에디터 설정 방법은 `INSTALLATION.md`, `DATA_AUTHORING.md`, `UI_SETUP.md`, `INSPECTOR_INTEGRATION.md`, `PICKUP_INTEGRATION.md`를 참고한다.
이번 UI/UX 개편의 구조와 WBP 선택 작업은 `UI_UX_UPGRADE_KO.md`를 참고한다.
Designer의 정확한 계층, 이름, 크기와 정렬값은 `WIDGET_LAYOUT_GUIDE_KO.md`에 있다.
Loot Box 생성, 고정 아이템, 가중치 Loot Table, 조작과 테스트 방법은 [`LOOT_CONTAINERS_KO.md`](LOOT_CONTAINERS_KO.md)를 참고한다.

지금까지 확인된 시행착오, 최종 Widget 구조, PlayerController/Character 설정과 전체 회귀 테스트 순서는 [`EDITOR_SETUP_AND_REGRESSION_TEST_KO.md`](EDITOR_SETUP_AND_REGRESSION_TEST_KO.md)를 기준으로 한다. 새 프로젝트 이식이나 UI 재제작 시에는 이 문서의 최종 완료 체크리스트까지 수행한다.
