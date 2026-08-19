---
title: "Loot Box 사용 설명서"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Loot Box 사용 설명서

이 문서는 `InventorySystem` 플러그인의 Loot Box를 생성하고, 아이템을 넣고, 랜덤 Loot Table을 연결하고, 플레이어가 실제로 여는 과정까지 설명한다. Box, Locker, Cabinet, Corpse, Safe, Vehicle, Stash는 모두 같은 구조를 사용할 수 있다.

## 1. 전체 구조

```text
Player 또는 PlayerController
├─ InventoryComponent          플레이어 아이템 저장
└─ InventoryUIComponent        인벤토리 UI 열기/닫기

Loot Box
├─ Mesh                        외형과 충돌
├─ InventoryContainerComponent 아이템과 용량 저장
└─ JMInteractableComponent     상호작용 입력
```

Loot Box의 기본 C++ Actor는 `AInventoryContainerActor`이다. 이 Actor는 필요한 세 컴포넌트를 이미 가지고 있으며, 상호작용하면 플레이어 또는 PlayerController에서 `InventoryUIComponent`를 찾아 `OpenContainer()`를 호출한다.

## 2. 가장 빠른 테스트

프로젝트에는 다음 예제 에셋이 있다.

- `/Game/Loot/BP_LootBox_Test`
- `/InventorySystem/Example/Loot/DT_LootBox_Items`
- `/Game/UI/Inventory/WBP_InventoryDuckov`

테스트 순서:

1. `BP_LootBox_Test`를 레벨에 배치한다.
2. 플레이어 Pawn에 `InventoryComponent`가 있는지 확인한다.
3. 플레이어 Pawn 또는 PlayerController에 `InventoryUIComponent`가 있는지 확인한다.
4. `InventoryUIComponent > Inventory Widget Class`를 `WBP_InventoryDuckov`로 지정한다.
5. PIE를 실행하고 기존 JM Interaction 입력으로 Box를 연다.
6. 왼쪽에는 Player Inventory, 오른쪽에는 Loot Container가 표시되는지 확인한다.

오른쪽 슬롯의 아이템을 짧게 좌클릭하면 Player Inventory로 자동 이동한다. Player Inventory가 가득 찼거나 무게 제한을 초과하면 이동하지 않고 Loot Box에 그대로 남는다.

## 3. 새 Loot Box Blueprint 만들기

1. Content Browser에서 `Blueprint Class`를 선택한다.
2. `All Classes`에서 `InventoryContainerActor`를 검색한다.
3. 부모 클래스로 선택하고 `BP_LootBox` 같은 이름으로 저장한다.
4. Blueprint를 열고 Components의 `Mesh`를 선택해 Static Mesh를 지정한다.
5. `InventoryContainer`를 선택해 이름, 용량, 무게와 Loot를 설정한다.
6. `Interaction`을 선택해 화면에 표시할 상호작용 문구를 설정한다.
7. Compile/Save 후 레벨에 배치한다.

`Mesh`의 Collision은 플레이어의 상호작용 Trace가 감지할 수 있어야 한다. 기본 Actor는 `BlockAllDynamic`을 사용하지만, 프로젝트에서 별도 Trace Channel을 쓴다면 해당 채널을 Block하도록 바꾼다.

## 4. InventoryContainer 설정

Blueprint의 `InventoryContainer` 컴포넌트를 선택한다.

| 속성 | 설명 | 권장 테스트 값 |
|---|---|---:|
| `Container Name` | 오른쪽 Loot UI 제목 | `Test Loot Box` |
| `Max Inventory Slots` | 컨테이너 슬롯 수 | `20` |
| `Max Inventory Weight` | 최대 무게. `0`은 무제한 | `0` |
| `Container ID` | 저장 시스템에서 식별할 GUID | 기본값 유지 |
| `Initial Loot` | 직접 입력하는 고정/확률 아이템 | 아래 참고 |
| `Loot Table` | 가중치 기반 랜덤 DataTable | 선택 사항 |
| `Loot Table Rolls` | Loot Table 추첨 횟수 | `0` 이상 |
| `Generate Loot on Begin Play` | BeginPlay에서 자동 생성 | 체크 |

`Initial Loot`와 `Loot Table`을 동시에 설정하면 두 결과가 모두 추가된다. 슬롯이나 무게가 부족하면 컨테이너가 수용할 수 있는 수량까지만 들어간다.

`Container ID`가 비어 있으면 BeginPlay에서 새 GUID를 만든다. 이는 실행 중 식별에는 충분하지만 실행할 때마다 같은 ID가 필요한 영구 저장 시스템에서는 배치 인스턴스별 ID를 저장·복원하는 별도 연동이 필요하다.

## 5. 고정 아이템 넣기: Initial Loot

아이템이 들어 있는지 가장 간단히 확인하는 방법이다.

1. `InventoryContainer > Initial Loot`의 `+`를 누른다.
2. `Item Definition`에 원하는 `InventoryItemDefinition` 데이터 에셋을 지정한다.
3. `Min Quantity`와 `Max Quantity`를 입력한다.
4. `Spawn Chance`를 입력한다. 범위는 `0.0~1.0`이다.

예시:

| Item Definition | Min | Max | Spawn Chance | 결과 |
|---|---:|---:|---:|---|
| Old Key | 1 | 1 | 1.0 | 항상 열쇠 1개 |
| Noise Bomb | 2 | 5 | 0.5 | 50% 확률로 2~5개 |

확정 테스트에서는 `Spawn Chance = 1.0`으로 둔다. 랜덤 여부를 제거할 수 있어 UI 문제와 Loot 생성 문제를 구분하기 쉽다.

## 6. 랜덤 Loot Table 만들기

### 6.1 DataTable 생성

1. Content Browser 빈 공간에서 우클릭한다.
2. `Miscellaneous > Data Table`을 선택한다.
3. Row Structure에서 `InventoryLootTableRow` 또는 `FInventoryLootTableRow`를 선택한다.
4. `DT_LootBox_Items` 같은 이름으로 저장한다.
5. 행을 추가하고 다음 값을 입력한다.

| 필드 | 설명 |
|---|---|
| `Item Definition` | 생성할 아이템 데이터 에셋 |
| `Min Quantity` | 선택됐을 때 최소 수량 |
| `Max Quantity` | 선택됐을 때 최대 수량 |
| `Weight` | 다른 행에 대한 상대 가중치 |

### 6.2 Weight 계산 예시

| 아이템 | Weight | 한 번 추첨될 확률 |
|---|---:|---:|
| Common Ammo | 70 | 70% |
| Medkit | 25 | 25% |
| Rare Key | 5 | 5% |

Weight의 합이 반드시 100일 필요는 없다. `7, 2.5, 0.5`도 같은 비율이다. Weight가 `0`인 행과 Item Definition이 비어 있는 행은 선택되지 않는다.

### 6.3 Box에 연결

1. `BP_LootBox`의 `InventoryContainer`를 선택한다.
2. `Loot Table`에 만든 DataTable을 지정한다.
3. `Loot Table Rolls`에 추첨 횟수를 입력한다.
4. `Generate Loot on Begin Play`를 체크한다.

각 Roll은 독립적으로 같은 테이블을 다시 추첨한다. 따라서 같은 아이템이 여러 번 선택될 수 있으며, 스택 가능한 아이템이면 기존 스택에 합쳐진다.

## 7. 생성 시점과 유지 범위

`Generate Loot on Begin Play`가 켜져 있으면 컨테이너의 BeginPlay에서 `GenerateInitialLoot()`를 한 번 호출한다. 같은 컴포넌트 인스턴스에서 이 함수를 다시 호출해도 중복 생성하지 않는다.

```text
Actor Spawn
→ Container BeginPlay
→ Initial Loot 판정
→ Loot Table N회 추첨
→ Container Slots에 저장
```

UI를 닫을 때는 현재 컨테이너 참조만 해제한다. Loot Box Actor가 살아 있는 동안 아이템 배열은 유지되므로 다시 열어도 이전 상태가 표시된다.

다음 경우에는 새 Actor/Component이므로 Loot가 다시 생성될 수 있다.

- Loot Box Actor를 Destroy한 뒤 다시 Spawn
- 레벨을 다시 시작하거나 컨테이너 Actor를 새로 생성
- 저장 데이터를 복원하지 않고 게임을 다시 실행

게임 재실행 후에도 같은 내용이 필요하면 `ContainerID`와 Inventory Save Entry를 프로젝트 SaveGame 시스템에 연결해야 한다.

## 8. UI와 조작

`WBP_InventoryDuckov`에서 사용하는 핵심 Widget 이름:

| 역할 | Widget 이름 |
|---|---|
| Player Grid | `UniformGridPanel_Items` |
| Loot Panel | `Panel_ExternalContainer` |
| Loot Grid | `UniformGridPanel_ContainerItems` |
| Loot 제목 | `Text_ContainerName` |

지원 조작:

- Loot 슬롯 짧은 좌클릭: Loot에서 Player Inventory로 전체 스택 자동 이동
- Drag: 원하는 반대편 슬롯으로 이동, 같은 아이템은 병합, 다른 아이템은 교환
- `Ctrl + Drag`: 스택 절반 분할
- `Shift + Click`: 반대편 인벤토리로 자동 이동
- Double Click: 반대편 인벤토리로 자동 이동
- Player Inventory 우클릭: Use, 수량 선택 버리기, 조사
- Sort: Player Inventory에서 같은 `ItemId`의 미완성 스택을 먼저 합친 뒤 수량 내림차순 정렬
- ESC 또는 Close: UI 닫기. Loot Box 아이템은 유지

이동은 `CanMove`, `MoveItem`, `MoveStack`, `SplitStack`, `SwapItem`을 공통으로 사용한다. 목적지의 빈 슬롯, 스택 최대 수량과 무게 제한을 모두 검사한다.

## 9. Blueprint에서 직접 열기

기본 Interaction을 사용하지 않고 Blueprint에서 열 수도 있다.

### Loot Box Actor에서 열기

```text
Player Actor
→ BP_LootBox의 Open For 호출
```

### Player UI Component에서 열기

```text
Player의 Inventory UI Component
→ Open Container
→ Loot Box의 InventoryContainer 전달
```

`Open For`는 전달된 Actor, 그 Owner 체인, Pawn의 Controller 순서로 `InventoryUIComponent`를 찾는다. 어느 경로에도 UI 컴포넌트가 없으면 열기에 실패한다.

## 10. 다른 컨테이너 제작

`BP_LootBox`를 복제하고 Mesh와 설정만 바꾸면 된다.

- `BP_WoodBox`
- `BP_MetalBox`
- `BP_Locker`
- `BP_Cabinet`
- `BP_Corpse`
- `BP_Safe`
- `BP_VehicleStorage`
- `BP_PlayerStash`

모두 `InventoryContainerComponent`를 공유하므로 UI와 이동 코드를 새로 만들 필요가 없다.

## 11. 문제 해결

### Box는 열리지만 아이템이 없다

- `Initial Loot > Item Definition`이 지정됐는지 확인한다.
- 확정 테스트는 `Spawn Chance = 1.0`으로 설정한다.
- DataTable의 Row Structure가 `FInventoryLootTableRow`인지 확인한다.
- `Loot Table Rolls`가 `1` 이상인지 확인한다.
- 모든 Weight가 `0`인지 확인한다.
- `Max Inventory Slots`와 `Max Inventory Weight`를 확인한다.
- BeginPlay 이후 값을 바꿨다면 Actor를 새로 Spawn하거나 PIE를 다시 시작한다.

### 상호작용해도 UI가 열리지 않는다

- Player/Pawn에 `InventoryComponent`가 있는지 확인한다.
- Player 또는 PlayerController에 `InventoryUIComponent`가 있는지 확인한다.
- `Inventory Widget Class`가 `WBP_InventoryDuckov`인지 확인한다.
- Mesh가 상호작용 Trace Channel을 Block하는지 확인한다.
- JM Interaction 입력과 Scanner/Interactor 설정이 정상인지 확인한다.

### Loot Panel이 보이지 않는다

- 사용하는 위젯의 부모가 `InventoryDuckovWidgetBase`인지 확인한다.
- `Panel_ExternalContainer`와 `UniformGridPanel_ContainerItems` 이름을 확인한다.
- 일반 `OpenInventory()`가 아니라 `OpenContainer()`로 열었는지 확인한다.

### 아이템이 Player Inventory로 이동하지 않는다

- Player Inventory가 가득 찼는지 확인한다.
- 같은 아이템 스택이 이미 최대 수량인지 확인한다.
- Player의 `Max Inventory Weight`를 초과하는지 확인한다.
- Loot 슬롯의 `Item Definition`과 Quantity가 유효한지 확인한다.

### Box를 닫았다 다시 열었더니 내용이 초기화된다

- 기존 Actor를 Destroy하고 새 Actor를 Spawn하고 있지 않은지 확인한다.
- 레벨 스트리밍으로 Actor가 제거되고 다시 생성되는지 확인한다.
- UI를 닫을 때 Container의 Slots를 직접 Clear하는 Blueprint가 없는지 확인한다.

## 12. 테스트 완료 체크리스트

- [ ] Box에 `InventoryContainer`, `Mesh`, `Interaction` 컴포넌트가 있다.
- [ ] Container Name과 Max Inventory Slots가 설정됐다.
- [ ] Initial Loot 1개를 Spawn Chance 1.0으로 설정했다.
- [ ] 상호작용 시 좌측 Player/우측 Loot UI가 열린다.
- [ ] Loot 아이템 짧은 좌클릭 이동이 된다.
- [ ] Drag, Shift Click, Double Click이 동작한다.
- [ ] Player Inventory가 가득 차면 Loot가 원본에 남는다.
- [ ] UI를 닫고 다시 열어도 남은 Loot 상태가 유지된다.
- [ ] DataTable Weight와 Loot Table Rolls가 의도대로 작동한다.

## 13. 관련 코드

- `AInventoryContainerActor`: Loot Actor와 상호작용 연결
- `UInventoryContainerComponent`: Loot 상태, 초기 아이템과 랜덤 추첨
- `UInventoryUIComponent::OpenContainer`: Player/Loot UI 열기
- `UInventoryDuckovWidgetBase`: 두 Grid 표시와 이동 처리
- `FInventoryInitialItem`: 직접 입력 Loot 구조
- `FInventoryLootTableRow`: DataTable Row 구조
