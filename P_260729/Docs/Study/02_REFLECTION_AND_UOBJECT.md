---
title: "02. Reflection과 UObject"
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

# 02. Reflection과 UObject

[교재 목차](README.md)

## 1. 개념

Unreal Reflection은 `UCLASS`, `USTRUCT`, `UENUM`, `UFUNCTION`, `UPROPERTY`로 C++ 타입과 멤버를 엔진의 직렬화, Garbage Collection, Editor, Blueprint 시스템에 노출하는 구조다. `GENERATED_BODY()`가 Unreal Header Tool이 생성한 코드를 타입에 삽입한다.

## 2. Unreal Engine에서 필요한 이유

순수 C++ RTTI만으로는 Blueprint 호출, Details Panel 편집, Asset 직렬화, GC 참조 추적을 제공할 수 없다. 이 프로젝트처럼 C++에서 규칙을 구현하고 Designer가 Data Asset과 Blueprint에서 값을 저작하려면 Reflection 계약이 필요하다.

## 3. 이 프로젝트에서 사용된 위치

| 파일 | 클래스/타입 | 확인할 표식 |
|---|---|---|
| `Plugins/InventorySystem/Source/InventorySystem/Public/Items/InventoryItemDefinition.h` | `UInventoryItemDefinition` | `UCLASS(BlueprintType)`, `UPROPERTY` |
| `Plugins/InventorySystem/Source/InventorySystem/Public/Components/InventoryComponent.h` | `UInventoryComponent` | `BlueprintSpawnableComponent`, `UFUNCTION` |
| `Plugins/JMInteraction/Source/JMInteraction/Public/Interfaces/JMInteractableInterface.h` | `UJMInteractableInterface` | `UINTERFACE(BlueprintType)` |

## 4. 실제 코드 분석

`UInventoryItemDefinition`은 Asset으로 생성되는 반사 타입이다.

```cpp
UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UInventoryItemDefinition : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
    FName ItemId;

    // 표시 텍스트와 프레젠테이션 속성은 여기서 생략한다.

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rules")
    FGameplayTagContainer ItemTags;
};
```

`EditDefaultsOnly`는 Definition Asset의 기본값을 편집 대상으로 삼고, `BlueprintReadOnly`는 Blueprint가 읽되 임의로 쓰지 못하게 한다. `INVENTORYSYSTEM_API`는 다른 Module에서 이 클래스를 링크할 수 있게 export/import 경계를 만든다. `FText`인 `DisplayName`과 `Description`은 사용자 표시 텍스트이고, `FName ItemId`는 안정적인 논리 식별자로 사용된다.

## 5. 실행 흐름

1. Unreal Header Tool이 header의 Reflection 매크로를 읽고 생성 코드를 만든다.
2. Unreal Build Tool이 생성 코드와 Module 코드를 함께 컴파일한다.
3. Editor가 `UInventoryItemDefinition`의 `UPROPERTY` 메타데이터로 Details Panel을 구성한다.
4. Asset 로드 시 Reflection 정보로 속성을 역직렬화한다.
5. Blueprint와 C++는 노출 정책에 따라 같은 객체를 읽거나 함수를 호출한다.

## 6. 왜 이런 구조를 선택했는지

**코드상 확인 가능한 사실:** 항목의 정적 정보는 `UPrimaryDataAsset` 파생 객체에, 실행 중 슬롯 상태는 별도 `FInventorySlot`에 있다. Designer-facing 값에는 `EditDefaultsOnly`와 `BlueprintReadOnly`가 반복된다.

**설계 의도 추론:** 정적 정의의 무분별한 런타임 변경을 막고, C++ 규칙과 Blueprint 저작을 함께 사용하려는 경계로 해석된다. 원 저자가 이 이유를 명시한 주석은 없다.

## 7. 다른 구현 방법

- 순수 `USTRUCT` 데이터 테이블 행으로 아이템 정의
- `AActor` Blueprint 자체를 아이템 정의로 사용
- 일반 C++ 구조체와 JSON으로 전부 관리

Data Table은 대량 편집에 유리하지만 항목별 subobject와 상속 활용이 제한된다. Actor 정의는 월드 표현과 데이터가 강결합된다. JSON은 외부 파이프라인에는 좋지만 Editor/Asset Manager 통합을 직접 구현해야 한다.

## 8. 현재 구현의 장단점

장점은 Blueprint/Editor 친화성, GC 안전 참조, Category와 EditCondition을 통한 저작 가이드다. 단점은 Reflection 매크로와 생성 코드 규칙을 지켜야 하고, UObject 생성·수명 모델을 모르면 일반 C++ 객체처럼 다루다 오류를 만들 수 있다는 점이다.

## 9. 개선 가능한 부분

- `ItemId` 중복과 `None`을 Asset Validation에서 강제 검사한다.
- 저장 식별자와 표시 문자열의 역할을 API 주석에 더 명시한다.
- Blueprint에 쓸 필요가 없는 함수/속성의 노출 범위를 축소한다.
- UObject pointer는 Reflection 대상 소유 관계에 맞춰 `TObjectPtr`, 약한 참조, soft reference를 의도적으로 구분한다.

## 10. 면접에서 설명한다면 어떻게 설명할지

“`UInventoryItemDefinition`을 예로 들면 `UCLASS(BlueprintType)`과 `UPROPERTY`로 Editor, Blueprint, 직렬화에 참여시켰습니다. `EditDefaultsOnly`로 Asset 저작은 허용하지만 `BlueprintReadOnly`로 런타임 임의 변경을 제한했습니다. 슬롯의 가변 상태는 별도 구조체에 두어 UObject 기반 정적 정의와 런타임 상태를 분리했습니다.”
