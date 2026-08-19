---
title: "JMHideInteractionIntegration"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMHideInteractionIntegration"
classified_on: 2026-08-19
owners:
  - "JMHideInteractionIntegration Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMHideInteractionIntegration

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|


`JMHide`, `JMInteraction`이 필수입니다. `UJMHideInteractableAdapterComponent`는 상호작용 완료를 은신 진입 명령 접수로 번역합니다. 실제 Hidden 완료는 `UJMHideInteractorComponent::OnHiddenEntered`에서 받습니다.

호스트 입력은 `UJMHideInputRouterComponent::RouteHostInteractInput`을 호출할 수 있습니다. 이 플러그인은 Enhanced Input Action 또는 Mapping Context를 등록하지 않습니다.
