---
title: "JMThrowable"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMThrowable"
classified_on: 2026-08-19
owners:
  - "JMThrowable Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMThrowable

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JMThrowable Architecture](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |
| Guides | [JMThrowable Niagara 궤적 전환 가이드](Guides/NIAGARA_PREVIEW_GUIDE_KO.md) | `ReviewRequired` |
| Guides | [에디터 설정](Guides/SETUP_KO.md) | `ReviewRequired` |
| Reference | [JMThrowable Niagara 런타임 구현](Reference/NIAGARA_RUNTIME_IMPLEMENTATION_KO.md) | `ReviewRequired` |


Portable UE 5.7 first-person throwable runtime plus an optional InventorySystem bridge.

Install both plugin folders when inventory integration is needed. For a player:

1. Add `JMThrowableInteractorComponent`.
2. Add `JMThrowableGameplayIntegrationComponent`.
3. Create a `JMThrowableDefinition` and select a projectile subclass.
4. On the Inventory Item Definition set `bCanUse=true`, `bConsumeOnUse=false`, and
   add an instanced `JMThrowableInventoryUseEffect` pointing at the throw definition.
5. Play: Use enters Ready, RMB aims, RMB release returns Ready, LMB throws, Q cancels.

While aiming, the thin white trajectory ends at the first blocking hit. A brighter
segment and visible orb travel along it, and a fixed marker shows the first impact.
This preview-only policy does not change the projectile's authored bounce/floor motion.

The integration installs a session-scoped Enhanced Input mapping dynamically, so
RMB/LMB/Q remain untouched while Idle. Call `NotifyInventoryOpening()` before opening
inventory during a session. Override `RequestCancelSprint` in Blueprint when the host
has a sprint API.
