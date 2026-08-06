# 인벤토리 시스템 아키텍처

## 설계 목표

Plugin은 인벤토리 상태와 규칙을 소유하지만 특정 Player, Controller, HUD, 상호작용 시스템, Item Inspector 또는 SaveGame에는 종속되지 않는다. 공개 Blueprint API와 작은 Interface를 통해 외부 시스템을 연결한다.

## Runtime 데이터 흐름

1. Pickup 또는 게임 시스템이 `IInventoryProviderInterface`나 Actor Component 검색을 통해 `UInventoryComponent`를 찾는다.
2. `AddItemDetailed`이 기존 스택을 먼저 채운 다음 빈 슬롯을 사용하고, 수용한 수량과 남은 수량을 반환한다.
3. 인벤토리 Delegate가 Tick 없이 UI를 갱신한다.
4. UI는 아이템 사용·버리기를 위해 Inventory Component API만 호출한다.
5. 자세히 보기 요청은 인스턴스형 `UInventoryItemInspectorBridge`로 전달되고, 호스트 구현이 기존 Inspector를 연다.
6. Inspector가 닫히면 Bridge가 UI 조정 컴포넌트에 알리고 인벤토리 화면이 복구된다.

## 클래스별 책임

- `UInventoryComponent`: 인벤토리 규칙과 슬롯 상태를 관리하는 핵심 계층
- `UInventoryItemDefinition`: 변경되지 않는 아이템 제작 데이터와 Soft Reference 보관
- `UInventoryItemUseEffect`: 다형적인 아이템 사용 동작
- `UInventoryUseOnActorComponentsEffect`: Use 요청을 사용자 Actor의 범용 수신 컴포넌트에 전달
- `IInventoryItemUseReceiverInterface`: Door 같은 선택 시스템이 Inventory 역참조 없이 아이템 사용을 받는 계약
- `AInventoryWorldItemPickup`: 월드 표현과 획득 요청 진입점
- `UInventoryUIComponent`: 위젯 수명, Enhanced Input 연결, 커서와 이동·시점 입력 차단, Inspector 전환 관리
- `UInventoryWidgetBase`: BindWidget 기반으로 Grid 생성, 선택 상세 정보와 명령 버튼을 관리하며 시각적 배치는 Blueprint에서 교체 가능
- `UInventorySlotWidgetBase`: BindWidget 기반으로 Slot 아이콘, 수량, 선택 및 사용 불가 표시를 관리
- `UInventoryItemInspectorBridge`: ItemInspector 또는 다른 Inspector를 위한 연동 경계

`UInventoryWidgetBase`와 `UInventorySlotWidgetBase`는 Widget Blueprint가 지정되지 않아도
완전한 네이티브 Widget Tree를 구성한다. 기존 WBP를 지정하면 동일한 BindWidget API를
사용하므로 데이터/행동 계층을 바꾸지 않고 시각 디자인만 교체할 수 있다.

## Modal HUD 협업

Inventory UI는 특정 HUD를 Cast하지 않는다. 열기/닫기 시 기존 `JMGameplayEvent`로
`Event.UI.Modal.Opened` / `Event.UI.Modal.Closed`를 발행하고, 원인을
`Event.UI.Inventory.Opened` / `Event.UI.Inventory.Closed` Context Tag로 함께 보낸다.
Objective UI와 Interaction Prompt는 공통 Modal 이벤트를 구독해 자동으로 숨김/복원한다.
프로젝트 전용 Crosshair도 같은 이벤트를 구독하면 된다.

## 런타임 용량 변경

외부 성장 시스템은 `SetMaxInventorySlots` 또는 `ExpandInventorySlots`만 사용한다.
축소 요청은 아이템을 버리지 않으며, 점유 슬롯 수보다 작으면 거부한다. 안전한 축소는
점유 슬롯을 앞쪽으로 압축한 뒤 배열 크기를 변경하고 `OnInventoryChanged`를 한 번 발행한다.
성장 비용, 업그레이드 소유권과 저장은 Inventory가 아니라 소비자 시스템이 담당한다.

## 에셋 참조

아이콘, 조사 메쉬, Pickup Class, Widget, Input Action은 가능한 범위에서 Soft Reference를 사용한다. 해당 기능이 실행되는 시점에만 로드하며 C++에 프로젝트 콘텐츠 경로를 넣지 않는다.

## 멀티플레이 확장

UI는 슬롯 배열을 직접 변경하지 않는다. 멀티플레이 프로젝트에서는 Component 공개 명령을 Server RPC로 감싸고 슬롯 배열을 Replication 대상으로 확장할 수 있다. UI와 Inspector 같은 Cosmetic 동작은 로컬에 유지한다. 현재 구현은 싱글플레이 기준이며 완전한 네트워크 보안을 제공한다고 가정하지 않는다.
