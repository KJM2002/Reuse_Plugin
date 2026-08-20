---
title: "Changelog"
status: ReviewRequired
authority: Historical
scope: "Plugin: JMDoorGameplayIntegration"
classified_on: 2026-08-19
owners:
  - "JMDoorGameplayIntegration Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# Changelog

## Unreleased

- Automatic runtime Door adapters are now limited to Game, PIE, and GamePreview worlds; Editor worlds are excluded.
- Door open, close, and locked interaction prompts are configurable in Project Settings.
- An explicitly-added `JMDoorInteractableAdapterComponent` can override all three prompt texts per door.
- Empty prompt text is respected and hides the prompt instead of restoring a hardcoded fallback.

## 1.1.0 - 2026-07-18

- Gameplay Tag 없이 Door Config에 열쇠 Item Definition을 직접 연결하는 방식 지원
- Blueprint에서 호출 가능한 `Use Item On Pending Door` 추가
- Pawn/PlayerController 어느 쪽에서 Use를 호출해도 동일 Agent를 찾도록 보강

## 1.0.1 - 2026-07-18

- 상호작용자의 시선 방향을 문 열림 Context에 전달
- Character에 Agent가 없으면 잠긴 문 상호작용 시 자동 생성
- 실제 InventoryComponent와 기존 Old Key 에셋을 사용하는 회귀 테스트 추가

## 1.0.0 - 2026-07-18

- 모든 JMDoor Actor의 JMInteraction 자동 어댑터 등록
- 잠긴 문 상호작용 시 Inventory UI 자동 열기
- Inventory Item Tags 기반 권한 확인과 Use 버튼 잠금 해제/열기
- 기존 Character에 추가 가능한 `JMDoorInventoryAgentComponent`
- Old Key 전체 흐름 자동화 테스트
