---
title: "JMThrowableGameplayIntegration"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMThrowableGameplayIntegration"
classified_on: 2026-08-19
owners:
  - "JMThrowableGameplayIntegration Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMThrowableGameplayIntegration

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |


Bridge from InventorySystem Use Effects to JMThrowable. It tracks the stable inventory
slot `InstanceId`, installs session-only Enhanced Input, validates commit, consumes
exactly one on success, and restores input/movement on every exit path.
