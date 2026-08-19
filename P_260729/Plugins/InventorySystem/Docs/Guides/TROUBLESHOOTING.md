---
title: "문제 해결"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 문제 해결

## 인벤토리가 열리지 않음

- `UInventoryWidgetBase`를 부모로 하는 Widget Blueprint가 지정되어 있는지 확인한다.
- `IA_ToggleInventory`가 지정되었고 입력 초기화 시 `BindEnhancedInput`이 호출되었는지 확인한다.
- 동일한 소유자 또는 현재 조종 중인 Pawn에 `UInventoryComponent`가 있는지 확인한다.

## 자세히 보기 버튼이 작동하지 않음

- Can Inspect가 활성화되어 있고 Inspect Mesh가 지정되었는지 확인한다.
- UI Component에 Inspector Bridge가 지정되었는지 확인한다.
- 기본 `UReuseInventoryInspectorBridge`를 사용하고 호환되는 JM Inspection Data를 지정한다.

## 획득 후 월드 아이템이 남아 있음

인벤토리를 찾지 못했거나 용량이 가득 찬 경우 정상 동작이다. `TryPickup`은 인벤토리가 실제로 수용한 수량만 월드 아이템에서 차감한다.

## 아이템 버리기 실패

Can Drop 활성화 여부, 유효한 World, Dropper 근처 충돌 공간, World Item Class 로드 여부를 확인한다. 사용자 지정 Class가 없으면 기본 C++ Pickup Class를 사용한다.

## BuildConfiguration.xml 경고

검증 과정에서 확인된 `bAllowUBALocalExecutor` 사용 중단 예정 경고는 사용자 UnrealBuildTool 설정에서 발생하며 Inventory Plugin과 관련이 없다.
