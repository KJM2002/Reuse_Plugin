---
title: "05. ActorComponent 조합"
status: Current
authority: Guide
scope: Study
last_verified: 2026-08-20
verified_against: "7c765f0348e2d6a766b83ccacf936e14d3122971"
owners:
  - Project Documentation
related:
  - README.md
---

# 05. ActorComponent 조합

[교재 목차](README.md)

## 1. 개념

`UActorComponent`는 Actor에 기능과 상태를 조합하는 UObject다. Actor 상속 계층을 늘리지 않고 Inventory, Interaction, Recon 같은 기능을 독립적으로 붙일 수 있다. `BeginPlay`, `EndPlay`, tick, owner/world 접근이라는 Unreal 수명에 참여한다.

## 2. Unreal Engine에서 필요한 이유

플레이어가 Inventory와 Interaction을 동시에 가져도 “InventoryPlayer → InteractingInventoryPlayer” 같은 상속 조합을 만들 필요가 없다. 재사용 Plugin은 Host Actor 클래스에 대한 지식 없이 component contract만 제공할 수 있다.

## 3. 이 프로젝트에서 사용된 위치

| 파일 | Component | 책임 |
|---|---|---|
| `Plugins/InventorySystem/Source/InventorySystem/Public/Components/InventoryComponent.h` | `UInventoryComponent` | 슬롯, 무게, 사용, 이동 |
| `Plugins/JMInteraction/Source/JMInteraction/Public/Components/JMInteractionComponent.h` | `UJMInteractionComponent` | 탐색, focus, hold 상호작용 |
| `Plugins/JMDoor/Source/JMDoorRuntime/Public/Door/JMDoorComponent.h` | `UJMDoorComponent` | 문 상태와 명령 |
| `Plugins/JMRecon/Source/JMReconRuntime/Public/Components/JMReconInteractorComponent.h` | `UJMReconInteractorComponent` | Recon 세션 소유 |

## 4. 실제 코드 분석

`UInventoryComponent`는 다음과 같이 Designer/Blueprint가 붙일 수 있는 component다.

```cpp
UCLASS(ClassGroup = (Inventory), BlueprintType, Blueprintable,
    meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();
    virtual void BeginPlay() override;

    UPROPERTY(BlueprintAssignable, Category = "Inventory|Events")
    FInventoryChangedSignature OnInventoryChanged;
};
```

생성자에서는 tick이 필요 없는 component로 설정하고 설정 기본값을 읽는다. `BeginPlay`는 `EnsureSlotCapacity()`로 슬롯 배열 불변식을 맞춘다. 상태 변경 함수는 `OnInventoryChanged` 등의 multicast delegate를 발행한다. `Slots`는 `VisibleInstanceOnly`라서 현재 상태는 볼 수 있지만 외부에서 직접 편집하는 API는 제공하지 않는다.

## 5. 실행 흐름

1. Actor의 CDO 또는 Blueprint가 component를 소유한다.
2. Actor 등록 과정에서 component가 register된다.
3. `BeginPlay`에서 settings 기반 용량과 내부 상태를 정규화한다.
4. gameplay 호출이 `AddItemDetailed`, `MoveItem` 같은 component API로 들어온다.
5. component가 상태를 변경하고 delegate와 gameplay event를 알린다.
6. Actor/World가 종료되면 `EndPlay`가 바인딩과 timer를 정리한다.

## 6. 왜 이런 구조를 선택했는지

**코드상 확인 가능한 사실:** Inventory, Interaction, Recon, Hide, Door는 각각 ActorComponent에 핵심 상태를 둔다. 여러 component는 `BlueprintSpawnableComponent`이고 owner를 통해 실행 context를 구한다.

**설계 의도 추론:** Host Actor 상속을 요구하지 않고 기능 단위로 재사용·조합하려는 설계로 해석된다. 어느 Actor에 어떤 조합을 강제할지는 코드만으로 확정할 수 없다.

## 7. 다른 구현 방법

- 기능별 Actor subclass 상속
- 모든 플레이어 기능을 하나의 거대한 Character 클래스에 구현
- Gameplay Ability System의 Ability/Attribute로 모델링
- World/GameInstance Subsystem이 모든 Actor별 상태를 map으로 소유

상속과 단일 클래스는 초기 탐색은 쉽지만 기능 조합이 늘면 강결합된다. GAS는 네트워크 예측과 능력 체계에 강하지만 단순 inventory storage에는 큰 도입 비용일 수 있다.

## 8. 현재 구현의 장단점

장점은 조합 가능성, Actor 수명과의 자연스러운 결합, Blueprint 부착 편의성이다. 단점은 필요한 companion component나 interface가 런타임에만 발견될 수 있고, 한 Actor에 중복 component가 붙을 때 정책이 필요하다는 점이다. 자동 부착 Integration은 편하지만 authored component와 충돌할 가능성도 있다.

## 9. 개선 가능한 부분

- `BeginPlay` 또는 `IsDataValid`에서 필수 owner/interface/component 계약을 검사한다.
- 반복되는 component lookup은 명시적 주입 또는 캐시와 invalidation 정책을 사용한다.
- tick은 Door처럼 실제 상태 변화 중에만 활성화한다.
- component 간 직접 concrete 참조가 늘어나면 Integration component나 event contract로 옮긴다.

## 10. 면접에서 설명한다면 어떻게 설명할지

“기능 상속 대신 ActorComponent 조합을 사용했습니다. `UInventoryComponent`는 슬롯 불변식과 도메인 API를 소유하고, `BeginPlay`에서 용량을 정규화하며, 변경은 delegate로 외부에 알립니다. 플레이어 Actor는 Inventory, Interaction, Recon component를 필요한 조합으로 가질 수 있고 각 Plugin은 Host Character 클래스를 몰라도 됩니다.”
