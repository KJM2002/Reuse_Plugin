---
title: "아이템 드랍과 획득 알림"
status: ReviewRequired
authority: Guide
scope: "Plugin: InventorySystem"
classified_on: 2026-08-19
owners:
  - "InventorySystem Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 아이템 드랍과 획득 알림

## 드랍 클래스 선택 순서

아이템을 버릴 때 생성할 Actor Class는 다음 순서로 선택한다.

1. `InventoryItemDefinition.WorldItemClass`
2. Project Settings → Game → Inventory System → `Default World Item Class`
3. `InventoryWorldItemPickup` 기본 C++ 클래스

이 프로젝트의 기본 클래스는 `ReuseInspectableInventoryPickup`으로 설정되어 있다. 따라서 Item Definition에 별도 `WorldItemClass`가 없어도 JM 상호작용으로 다시 습득할 수 있다.

조사 화면이 필요한 아이템은 Item Definition의 `WorldItemClass`에 해당 아이템 전용 Blueprint를 지정한다. 예를 들어 Old Key는 `BP_Item_OldKey`를 지정하면 드랍 후에도 `JMInspectable` 설정을 유지한다.

## 바닥 스냅

드랍 Actor는 `Always Spawn`으로 생성한 뒤 `InitializePickup`에서 Mesh를 적용한다. 이어서 `SnapToGround`가 아래 순서로 위치를 보정한다.

```text
바닥 Visibility Trace
→ ItemMesh Bounds 갱신
→ Mesh Bounds 최하단 높이 계산
→ 바닥 충돌점 + Ground Clearance에 최하단 맞춤
```

기본 `Ground Clearance`는 `1cm`이다. Mesh가 너무 높거나 바닥에 파묻히면 Pickup Blueprint의 Class Defaults에서 이 값만 조절한다.

## 획득 알림

한 번의 `AddItemDetailed` 작업이 끝나면 `OnItemsReceived`가 실제 추가된 총수량을 한 번만 전달한다. 여러 Stack에 나뉘어 들어가도 알림은 중복되지 않는다.

`InventoryUIComponent`는 다음 형식의 알림을 기본 2초간 표시한다.

```text
아이템 이름 x 개수
```

예시:

```text
오래된 열쇠 x 1
```

표시 시간은 `InventoryUIComponent.PickupNotificationDuration`에서 조절한다. 현재 프로젝트는 `InventoryPickupNotificationWidget`을 부모로 하는 `WBP_PickupNotification`을 `PickupNotificationWidgetClass`에 지정한다.

알림 WBP는 전체 화면 `Canvas Panel`을 Root로 사용한다. 실제 알림 박스의 위치와 크기는 WBP의 Canvas Slot에서 직접 관리하며 PlayerController에서 Viewport Size나 Position을 따로 입력하지 않는다.

```text
WBP_PickupNotification
└─ CanvasPanel_Root
   └─ SizeBox_Root
      └─ Border_Background
         └─ HorizontalBox_Content
            ├─ SizeBox_Icon
            │  └─ Image_ItemIcon
            ├─ Spacer_IconText
            └─ Text_Message
```

`Text_Message`, `Image_ItemIcon`, `SizeBox_Icon`은 이름을 정확히 맞추고 `Is Variable`을 체크한다. C++은 Item Definition의 `Icon`을 `Image_ItemIcon`에 적용한다. Icon이 없으면 `Image_ItemIcon`과 `SizeBox_Icon`을 숨긴다.

전체 에디터 설정, 지금까지의 시행착오와 회귀 테스트 절차는 [`EDITOR_SETUP_AND_REGRESSION_TEST_KO.md`](../Testing/EDITOR_SETUP_AND_REGRESSION_TEST_KO.md)를 기준으로 한다.
