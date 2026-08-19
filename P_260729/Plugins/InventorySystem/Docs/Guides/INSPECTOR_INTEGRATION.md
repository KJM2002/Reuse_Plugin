---
title: "Item Inspector 연동"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Item Inspector 연동

재사용 가능한 Inventory Plugin은 `UInventoryItemInspectorBridge`만 호출하며 ItemInspectorRuntime에 직접 링크하지 않는다.

Inventory Plugin은 `UReuseInventoryInspectorBridge`를 자체 제공한다. `UInventoryUIComponent.InspectorBridge`에 이 Class의 인라인 인스턴스를 지정한다.

Adapter 동작 순서:

1. Item Definition에 지정된 범용 Inspector Data Soft Reference를 로드한다.
2. 기존 `UJMItemInspectionData` 형식으로 Cast한다.
3. Local Player의 `UJMItemInspectionSubsystem::OpenInspection`을 호출한다.
4. 기존 Subsystem의 닫힘 Delegate를 전달받는다.
5. Inspector가 활성화된 동안 인벤토리 Widget을 숨기고 종료 후 다시 표시한다.

Old Key의 Inspector Data에는 `/ItemInspector/Item/DA_OldKey_Inspection`을 지정한다. 기존 Item Inspector 소스는 수정하거나 복제하지 않았다.
