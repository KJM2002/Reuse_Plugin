# Loot Container 설정

## 구성

- Player/Pawn: `UInventoryComponent`
- Player 또는 PlayerController: `UInventoryUIComponent`
- Loot Actor: `AInventoryContainerActor` 또는 그 Blueprint 자식
- Loot 상태: `UInventoryContainerComponent`
- 상호작용: Actor에 기본 포함된 `UJMInteractableComponent`

`UInventoryContainerComponent`는 Actor가 파괴되지 않는 동안 `Slots`를 계속 보유한다. UI를 닫을 때는 `UInventoryUIComponent::CurrentContainer` 참조만 해제한다.

## UI 연결

`WBP_InventoryDuckov` 계열에 다음 이름을 사용한다.

- 플레이어 Grid: `UniformGridPanel_Items`
- 컨테이너 Panel: `Panel_ExternalContainer`
- 컨테이너 Grid: `UniformGridPanel_ContainerItems`
- 컨테이너 이름: `Text_ContainerName`

`OpenContainer(ContainerComponent)`를 호출하면 좌측 플레이어 Grid와 우측 컨테이너 Grid가 함께 열린다. ESC/Close는 기존 `CloseInventory()` 경로를 사용한다.

지원 입력:

- Loot 슬롯 좌클릭: 플레이어 인벤토리로 자동 이동. 이동할 공간이나 무게 여유가 없으면 원본을 유지한다.
- Drag: 지정 슬롯으로 전체 스택 이동, 같은 아이템이면 병합, 다른 아이템이면 교환
- Ctrl + Drag: 스택 절반 분할
- Shift + Click 또는 Double Click: 반대편 인벤토리의 빈/병합 가능한 슬롯으로 자동 이동
- Sort: 같은 `ItemId`의 미완성 스택을 최대 스택까지 먼저 합친 뒤 수량순으로 정렬
- Drop: 스택이 2개 이상이면 `-`, `+`, `전부`로 수량을 고른 뒤 확인

모든 경로는 `MoveItem`, `MoveStack`, `SplitStack`, `SwapItem`, `CanMove` API를 공유한다.

## 랜덤 Loot

간단한 고정 후보는 `InitialLoot`에 아이템, 최소/최대 수량, 확률을 설정한다.

가중치 DataTable은 Row Struct를 `FInventoryLootTableRow`로 만들고 다음 값을 작성한다.

- `ItemDefinition`
- `MinQuantity`, `MaxQuantity`
- `Weight`

컨테이너의 `LootTable`과 `LootTableRolls`를 설정하면 BeginPlay에서 한 번만 추첨한다. 이미 생성된 컨테이너에 `GenerateInitialLoot()`를 다시 호출해도 중복 생성하지 않는다.

## 확장 Actor

`AInventoryContainerActor`의 Blueprint 자식을 만들어 Mesh, 이름, 슬롯/무게 한도와 Loot 설정만 바꾸면 Wood Box, Locker, Cabinet, Corpse, Safe, Vehicle, Stash를 같은 코드로 처리할 수 있다.
