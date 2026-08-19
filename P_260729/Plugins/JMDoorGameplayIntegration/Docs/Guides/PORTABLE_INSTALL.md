---
title: "Portable Install"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMDoorGameplayIntegration"
classified_on: 2026-08-19
owners:
  - "JMDoorGameplayIntegration Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Portable Install

다음 폴더를 함께 복사합니다.

```text
Plugins/JMDoor
Plugins/ItemInspector
Plugins/InventorySystem
Plugins/JMDoorGameplayIntegration
```

`Binaries`, `Intermediate`, `Saved`는 제외하고 대상 UE 5.7 C++ 프로젝트에서 다시 빌드합니다. 설치 뒤 기존 Character에 `JMInteractionComponent`, `InventoryComponent`, `InventoryUIComponent`, `JMDoorInventoryAgentComponent`를 추가합니다.
