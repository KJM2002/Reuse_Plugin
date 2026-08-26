---
title: "JMMonsterFramework Phase 4.5 Recent Tracking Test"
status: Current
authority: Guide
scope: "Recent Tracking Memory verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE4_SEARCH_TEST_KO.md"
---

# Phase 4.5 Recent Tracking Test

## 자동 검사

Automation 창에서 `JM.MonsterFramework.Phase4_5.BuildAndValidateStateTree`, `JM.MonsterFramework.Phase1.SightStateTransitions`, `JM.MonsterFramework.Phase0.SimpleEnemyDefaults`를 실행한다.

## Level_TestAI 수동 검사

1. Enemy의 시야 안에서 한 방향으로 달리다가 벽 모서리를 돈다.
2. Sight Lost 직후 곧바로 Investigate로 바뀌지 않고, 마지막 이동 방향으로 최대 700uu의 예상점을 향해 약 1.5초 이동하는지 확인한다.
3. RecentTracking 중 다시 나타나 즉시 Chase로 복귀하는지 확인한다.
4. 벽 뒤에서 멈춰 Enemy가 실제 정지 위치를 정확히 따라가지 않고 기존 예상점으로 가는지 확인한다.
5. 마지막 관측 방향과 반대로 이동해도 Enemy가 숨은 방향 전환을 따라가지 않는지 확인한다.
6. 끝까지 숨은 채 `RecentTracking -> InvestigateLastLocation -> Search -> Idle` 순서를 확인한다.
7. 재감지 성공/실패 흐름을 여러 번 반복해 Move 요청 누적, 상태 고착, Warning/Error가 없는지 확인한다.

## PASS 기준

- Sight Lost 뒤에는 `EstimatedTrackingLocation` 스냅샷만 추적한다.
- 재감지는 예상점 도착 여부보다 우선해 Chase로 전환한다.
- 1.5초 만료 뒤 기존 Investigate와 Search가 이어진다.
- 벽 뒤 Player의 정지나 역방향 이동을 즉시 알아내지 못한다.
- 반복 PIE에서 이동 정지, 상태 고착, Warning/Error가 없다.
