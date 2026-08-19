---
title: "JMInspectable 아이템 획득 연동"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# JMInspectable 아이템 획득 연동

## 목표

월드 아이템에 `JMInspectableComponent`를 부착하여 먼저 조사하고, 조사 화면을 정상적으로 닫으면 같은 아이템을 인벤토리에 추가한다.

Inventory Plugin의 Integration 폴더에 `AReuseInspectableInventoryPickup`을 두어 ItemInspector 연결을 한곳에 모았다.

```text
InventorySystem
└─ AInventoryWorldItemPickup
   └─ InventorySystem Integration Adapter
      └─ AReuseInspectableInventoryPickup
         ↔ UJMInspectableComponent
```

다른 프로젝트로 Inventory Plugin을 복사할 때 이 Adapter는 함께 복사하지 않아도 된다. 해당 프로젝트의 조사 시스템에 맞는 Adapter만 새로 구현하면 된다.

## 1. Old Key Item Definition 생성

Content Browser에서 Inventory Item Definition Data Asset을 만들고 `DA_Inventory_OldKey`로 이름을 지정한다.

```text
Item Id            = OldKey
Display Name       = Old Key
Description        = An old and worn key. It may open something nearby.
Icon               = /InventorySystem/Example/Icons/oldKey
Inspect Mesh       = /ItemInspector/Item/SM_OldKey
Inspector Data     = /ItemInspector/Item/DA_OldKey_Inspection
Can Use            = false
Can Drop           = true
Can Inspect        = true
Stackable          = false
Max Stack Size     = 1
Consume On Use     = false
```

## 2. Pickup Blueprint 생성

1. Content Browser에서 **Blueprint Class**를 선택한다.
2. **All Classes**를 펼친다.
3. `ReuseInspectableInventoryPickup`을 검색한다.
4. 해당 클래스를 부모로 선택한다.
5. 이름을 `BP_OldKey_Pickup`으로 지정한다.

일반 Actor나 `AInventoryWorldItemPickup`을 직접 부모로 선택하지 않는다. 현재 JM 조사 연동이 필요한 테스트 아이템은 `ReuseInspectableInventoryPickup`을 부모로 사용한다.

## 3. JMInspectableComponent 추가

1. `BP_OldKey_Pickup`을 연다.
2. Components Panel에서 **Add**를 누른다.
3. `JM Inspectable Component`를 검색하여 추가한다.
4. Component를 선택하고 다음 값을 설정한다.

```text
Inspection Data                  = /ItemInspector/Item/DA_OldKey_Inspection
Inspection Enabled               = true
Pause Game During Inspection     = false
Block Player Input During Inspection = true
Hide Source Actor During Inspection  = false
Prompt Text                      = 조사하기
```

Actor Adapter가 JM Interaction Interface를 직접 구현하므로 JM Interaction 시스템은 Actor를 먼저 선택한다. 부착된 `JMInspectableComponent`와 Pickup용 별도 Interactable Component가 서로 선택 경쟁을 하지 않는다.

## 4. Pickup 데이터 설정

`BP_OldKey_Pickup`의 **Class Defaults**에서 다음 값을 설정한다.

```text
Item Definition             = DA_Inventory_OldKey
Quantity                    = 1
Interaction Prompt          = 조사하기
Interaction Priority        = 10
Inspect Before Pickup       = true
Pickup After Inspection     = true
Fallback To Immediate Pickup = true
```

Item Mesh는 Item Definition의 Inspect Mesh를 BeginPlay에서 자동으로 불러온다. 별도의 Static Mesh 설정이 필요하지 않다. Blueprint에서 다른 Mesh를 사용하고 싶다면 Item Mesh Component에 직접 지정할 수 있다.

## 5. Level에 배치하고 테스트

1. `BP_OldKey_Pickup`을 Level에 배치한다.
2. 플레이어 Character에 `InventoryComponent`와 `JMInteractionComponent`가 있는지 확인한다.
3. Play를 실행한다.
4. Old Key를 바라보고 프로젝트의 상호작용 Key를 누른다.
5. JM Item Inspector가 열리는지 확인한다.
6. Inspector를 Close Button 또는 사용자 닫기 입력으로 닫는다.
7. 월드의 Old Key가 사라지는지 확인한다.
8. Tab으로 인벤토리를 열고 Old Key가 한 Slot에 표시되는지 확인한다.

## 동작 순서

```text
JM 상호작용 완료
→ Adapter Actor가 부착된 JMInspectableComponent 검색
→ 기존 JM Item Inspector 열기
→ Inspector 닫힘 Delegate 수신
→ TryPickup(상호작용한 Actor)
→ InventoryComponent.AddItemDetailed
→ 실제 추가된 수량만 월드 수량에서 차감
→ 수량이 0이면 Pickup Actor 제거
```

인벤토리가 가득 찼다면 `TryPickup`이 실패하므로 월드 아이템은 사라지지 않는다.

## 설정별 동작

| 설정 | 동작 |
|---|---|
| Inspect Before Pickup = true | 먼저 JM Inspector를 연다. |
| Pickup After Inspection = true | Inspector를 정상 종료한 뒤 획득한다. |
| Inspect Before Pickup = false | 조사 없이 즉시 획득한다. |
| Fallback To Immediate Pickup = true | JMInspectable이 없거나 Inspector를 열 수 없으면 즉시 획득을 시도한다. |
| Fallback To Immediate Pickup = false | JMInspectable 또는 Inspector가 없으면 실패하고 월드에 남는다. |

## 결합 범위

- `InventorySystem` Module은 ItemInspectorRuntime을 참조하지 않는다.
- 기존 `UJMInspectableComponent` 소스는 수정하지 않았다.
- 기존 `UJMItemInspectionSubsystem` 소스도 수정하지 않았다.
- 두 시스템을 함께 아는 코드는 `AReuseInspectableInventoryPickup`뿐이다.
- 다른 프로젝트에서는 이 Adapter만 교체할 수 있다.
