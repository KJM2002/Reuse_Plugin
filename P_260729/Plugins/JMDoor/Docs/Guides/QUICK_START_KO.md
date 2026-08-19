---
title: "JM Door 처음 사용하기"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMDoor"
classified_on: 2026-08-19
owners:
  - "JMDoor Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# JM Door 처음 사용하기

> 1.6 미닫이문은 상속된 `DoorLeafMesh`를 A, `DoorLeafMeshB`를 B로 사용합니다. A/B의 Open Offset은 액터 로컬 좌표이며 기본값은 각각 왼쪽/오른쪽입니다. `SlideDoorOpenMode`에서 A, B, Both를 선택하고, B 메시를 비워 두면 기존 단일 문짝 방식으로 동작합니다.

이 문서는 기존 `BP_FirstPersonCharacter`에 컴포넌트만 추가해 문, 상호작용, 인벤토리 열쇠를 시험하는 절차입니다. 전용 플레이어와 Level Blueprint는 필요하지 않습니다.

## 1. 필요한 플러그인

문만 API로 사용할 때는 `JMDoor`만 필요합니다. 아래의 플레이 테스트에는 다음 네 폴더가 모두 필요합니다.

- `JMDoor`
- `ItemInspector`
- `InventorySystem`
- `JMDoorGameplayIntegration`

Editor를 완전히 종료한 상태에서 복사하고 프로젝트를 빌드한 뒤 다시 실행합니다. Content Browser의 **Settings → Show Plugin Content**를 켭니다.

## 2. 기존 Character에 컴포넌트 추가

`BP_FirstPersonCharacter`를 열고 다음 컴포넌트가 있는지 확인합니다. 없는 것만 **Add**로 추가합니다.

1. `JMInteractionComponent`
2. `InventoryComponent`

`JMDoorInventoryAgentComponent`는 잠긴 문을 처음 상호작용할 때 자동 생성됩니다. 직접 추가해도 되지만 필수는 아닙니다.

`InventoryUIComponent`는 `BP_FirstPersonPlayerController`에 하나만 둡니다. Character와 PlayerController 양쪽에 동시에 두면 Widget과 입력이 중복됩니다. Character에 이미 있다면 제거합니다.

상호작용 입력(예: `E`)에서 `JMInteractionComponent → Try Begin Interaction`을 호출합니다. 기존 프로젝트에서 아이템 획득 상호작용이 이미 된다면 이 연결은 완료된 상태입니다.

PlayerController의 `InventoryUIComponent.Inventory Widget Class`에는 `/InventorySystem/Widget/WBP_Inventory`를 지정합니다. `Inventory Component` 참조는 비워 두면 현재 Pawn에서 자동 검색합니다.

문 Actor에는 연동 컴포넌트를 추가할 필요가 없습니다. 연동 플러그인의 World Subsystem이 모든 `AJMDoorActor`에 JM 상호작용 어댑터를 실행 중 자동으로 붙입니다.

## 3. Access Tag와 Old Key

기본 설정에는 Gameplay Tag가 필요하지 않습니다. 문 Config에 허용할 아이템 에셋을 직접 연결합니다.

```text
Door Config
→ Access
→ Accepted Access Items
→ DA_Inventory_OldKey 추가
```

포함된 에셋은 이미 설정되어 있습니다.

- 잠긴 문: `/JMDoor/Demo/Blueprints/BP_JMRotatingDoorLockedExample`
- 문 설정: `/JMDoor/Demo/Data/DA_JMDoorDemoLockedConfig`
- 열쇠 정의: `/InventorySystem/Example/DA_Inventory_OldKey`
- 열쇠 Pickup: `/InventorySystem/Example/World/BP_Item_OldKey`

`DA_Inventory_OldKey`에는 `Can Use`만 켜져 있습니다. 별도 Use Effect 없이 현재 잠긴 문으로 자동 전달됩니다.

## 4. 가장 짧은 수동 테스트

1. 테스트 레벨에 기존 `BP_FirstPersonCharacter`가 조종되도록 설정합니다.
2. `BP_Item_OldKey` Pickup과 `BP_JMRotatingDoorLockedExample`을 배치합니다.
3. Play 후 Old Key를 바라보고 상호작용하여 줍습니다.
4. 잠긴 문을 바라보고 상호작용합니다.
5. 인벤토리 창이 자동으로 열리는지 확인합니다.
6. Old Key 슬롯을 선택하고 **Use**를 누릅니다.
7. 인벤토리가 닫히고 문이 플레이어에게서 멀어지는 방향으로 열리는지 확인합니다.
8. 다시 문을 상호작용하여 닫습니다.

열쇠가 없다면 인벤토리는 열리지만 사용할 수 있는 권한 아이템이 없습니다. 문에서 멀어지거나 인벤토리를 닫은 뒤 다른 문을 사용하면 새 문이 현재 대상으로 교체됩니다.

## 5. 문 메시 설정

회전문은 `MovementRoot`가 경첩이고 `DoorLeafMesh`가 그 자식입니다.

1. Blueprint에서 `MovementRoot`를 실제 경첩 위치에 둡니다.
2. `DoorLeafMesh`를 문 폭의 절반만큼 경첩에서 옆으로 이동합니다.
3. 메시의 원래 Pivot이 중앙이어도 `MovementRoot`를 기준으로 회전합니다.
4. 문짝 높이·폭은 `DoorLeafMesh`의 Transform으로만 조절합니다.

미닫이문은 `DoorLeafMesh` 자체가 이동합니다. 열림 거리와 방향은 `SlidingMovement → Local Open Offset`에서 설정합니다.

## 6. 직접 만든 열쇠와 문

1. 문 Config의 `Access → Accepted Access Items`에 열쇠 Item Definition을 추가합니다.
2. Item Definition에서 `Can Use`만 켭니다. `Use Effect`는 비워 둬도 됩니다.
3. 일회용이면 Item Definition의 `Consume On Use`를 켭니다. 실제 차감은 Inventory가 성공 뒤 처리합니다.
4. 별도 Inventory Blueprint를 사용한다면 아이템의 Use 이벤트를 Agent의 `Use Item On Pending Door` 노드에 직접 연결할 수 있습니다.

## 7. AI와 커스텀 시스템

AI와 플레이어는 모두 `IJMDoorUsableInterface` 또는 `Execute Door Command On Object`를 사용할 수 있습니다. AI는 UI가 필요 없으므로 `FJMDoorUseContext.AccessTags`에 권한 태그를 넣어 `Open`을 호출하면 됩니다.

JMDoor 코어는 Inventory, Character, HUD를 참조하지 않습니다. 다른 프로젝트로 옮길 때 상호작용·인벤토리 연동이 필요하면 위 네 플러그인 폴더를 함께 복사합니다.

## 8. 문제 해결

- 문이 플레이어 쪽으로 열린다: Config의 `Open Direction Mode`가 `Away From Interactor`인지 확인하고 `MovementRoot`가 경첩 위치인지 확인합니다.
- 문이 중앙 회전한다: `RotatingMovement`가 `MovementRoot`를 움직이는 1.2.0 이상인지 확인합니다.
- 자동으로 닫히는 문이 카메라를 밀어 화면이 떨린다: Config의 Blocking에서 `Push Characters`를 켭니다. 기본값은 켜짐입니다. 큰 프레임 델타는 `Character Push Max Substep Distance`와 `Character Push Max Substep Angle` 기준으로 나눠 predictive sweep하며, 전체 문짝 이동량은 제한하지 않습니다. 캐릭터 이동에는 Character Movement의 Sweep과 Slide가 적용되고, 벽에 막히면 기존 `Block Behavior`가 적용됩니다.

### Character Push 디버깅

Project Settings → JM Gameplay → JM Door → Debug에서 다음 옵션을 켤 수 있습니다.

- `Draw Character Push Debug`: 노랑=문짝 델타, 주황=접촉점, 청록=요청 Push, 초록=실제 이동, 빨강=막힌 표면 Normal
- `Log Character Push Debug`: 프레임, 서브스텝, 접촉 시간, 문짝 델타, 요청/실제 이동, Sweep Hit Actor와 Normal 출력
- `Character Push Debug Duration`: 디버그 선 유지 시간

문짝 Static Mesh에는 predictive component sweep이 사용할 수 있는 Simple Collision이 있어야 합니다.
- 문 상호작용 표시가 없다: Character에 `JMInteractionComponent`가 있고 문짝 Collision이 `Visibility` Trace를 막는지 확인합니다.
- 잠긴 문에서 창이 안 열린다: Character에 `InventoryUIComponent`가 있고 `Inventory Widget Class`가 지정됐는지 확인합니다. Agent는 자동 생성됩니다.
- Use가 실패한다: 문의 `Accepted Access Items`에 실제 Inventory Item Definition이 연결됐는지 확인합니다.
- PIE 시작 시 문 크기가 변한다: Editor를 종료하고 전체 C++ 빌드 후 다시 실행합니다.
