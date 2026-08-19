---
title: "JMHideDoorIntegration"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMHideDoorIntegration"
classified_on: 2026-08-19
owners:
  - "JMHideDoorIntegration Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMHideDoorIntegration

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|


`JMHide`, `JMDoor`가 필수입니다. `UJMHideDoorMechanismComponent`는 JMDoor 공개 Command API와 상태 Delegate를 JMHide의 비동기 Mechanism 계약으로 변환합니다.

같은 Door Mesh를 `UJMHideSimplePanelMechanismComponent`에도 등록하지 마십시오. Spot Validation은 Adapter와 Simple Panel이 같은 Scene Component를 소유하면 오류를 보고합니다.
