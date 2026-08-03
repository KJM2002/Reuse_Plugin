# JM Door Gameplay Integration

## 문 상호작용 문구 설정

- 전체 기본값: `Project Settings > JM Plugins > Door Gameplay Integration > Interaction Prompt`
- 문별 설정: 문 Blueprint에 `JMDoorInteractableAdapterComponent`를 직접 추가하고
  `Override Prompt Texts`를 활성화한 뒤 열기/닫기/잠김 문구를 설정합니다.
- 문구를 비워 두면 해당 상태의 프롬프트가 표시되지 않습니다.

`JMDoor`, `ItemInspector`, `InventorySystem`을 선택적으로 연결하는 브리지입니다. 기능 플러그인 코어끼리는 서로 참조하지 않습니다.

## 캐릭터 설정

`BP_FirstPersonCharacter` 같은 기존 Character에 다음 컴포넌트를 추가합니다.

1. `JMInteractionComponent`
2. `InventoryComponent`
3. `JMDoorInventoryAgentComponent` (선택: 없으면 잠긴 문 첫 상호작용 때 자동 생성)

`InventoryUIComponent`는 PlayerController에 하나만 둡니다. Character와 Controller 양쪽에 두지 않습니다.

기존 상호작용 입력에서 `JMInteractionComponent -> Try Begin Interaction`을 호출합니다. 문에는 별도 컴포넌트를 추가할 필요가 없습니다. World Subsystem이 모든 `AJMDoorActor`에 상호작용 어댑터를 런타임에 자동 등록합니다.

잠긴 문을 상호작용하면 인벤토리가 열립니다. Door Config의 `Accepted Access Items`에 직접 연결된 아이템을 선택하고 `Use`를 누르면 잠금 해제와 열기가 실행되고 인벤토리가 닫힙니다.

## Old Key 규칙

- Item Id: `OldKey`
- Can Use: true
- Use Effect: 비워 둠 (특수 동작이 있을 때만 지정)
- Consume On Use: 열쇠를 없애려는 경우에만 true

포함된 `/InventorySystem/Example/DA_Inventory_OldKey`는 잠긴 문 예제의 `Accepted Access Items`에 직접 연결되어 있습니다.

이 플러그인을 복사할 때는 `JMDoor`, `ItemInspector`, `InventorySystem`, `JMDoorGameplayIntegration` 네 폴더를 함께 복사합니다.
