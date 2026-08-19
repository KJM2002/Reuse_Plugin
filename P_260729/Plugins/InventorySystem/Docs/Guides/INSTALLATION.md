---
title: "설치 방법"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 설치 방법

`InventorySystem` 0.2.0은 조사 상호작용 연동을 포함하므로 `ItemInspector`와 함께 설치합니다. 두 플러그인 폴더가 같은 프로젝트의 `Plugins` 아래 있어야 합니다.

1. 다른 Unreal 프로젝트의 `Plugins` 폴더에 `Plugins/InventorySystem`과 `Plugins/ItemInspector`를 복사한다.
2. **Reusable Inventory System**과 **Enhanced Input** Plugin을 활성화한다.
3. C++ 프로젝트라면 프로젝트 파일을 다시 생성한다.
4. 호스트 C++ 코드에서 Plugin Header를 Include할 때만 호스트 Module의 Build.cs에 `InventorySystem` 의존성을 추가한다.
5. 인벤토리를 소유할 Pawn 또는 PlayerState에 `UInventoryComponent`를 추가한다.
6. 로컬 인벤토리 UI를 관리할 Pawn 또는 PlayerController에 `UInventoryUIComponent`를 추가한다.
7. UI Component 또는 `Project Settings → Game → Inventory System`에서 Widget과 Input Action을 설정한다.

Inventory Plugin 0.2.0은 기본 조사 Bridge와 상호작용 Pickup을 제공하기 위해 ItemInspector를 요구한다. 다른 Inspector를 사용하려면 `UInventoryItemInspectorBridge` 파생 클래스로 `InspectorBridge`를 교체할 수 있다.
