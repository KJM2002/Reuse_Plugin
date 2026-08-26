---
title: "JMMonsterFramework Phase 5 Patrol Test"
status: Current
authority: Guide
scope: "NavMesh Patrol verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE4_5_RECENT_TRACKING_TEST_KO.md"
  - "PHASE4_6_LIVE_GRACE_TEST_KO.md"
---

# Phase 5 Patrol Test

## 자동 검사

Automation 창에서 다음을 실행한다.

- `JM.MonsterFramework.Phase6.BuildAndValidatePredictiveStateTree`
- `JM.MonsterFramework.Phase6.BuildAndValidateLiveGraceAssets`
- 기존 `JM.MonsterFramework.Phase0`, `Phase1`, `Phase4_6.LiveGraceState` 회귀 검사

## PIE 절차

1. `BP_SimpleEnemy`와 `BP_SimpleEnemy_LiveGrace`를 충분한 NavMesh 위에 각각 배치한다.
2. Player가 보이지 않을 때 Enemy가 반경 800uu 안의 여러 목적지로 이동하는지 확인한다.
3. 목적지 도착 후 약 1.5초 기다렸다가 다음 목적지로 이동하는지 확인한다.
4. Patrol 중 Player 앞에 나타나 즉시 Chase로 전환되는지 확인한다.
5. Predictive 프리셋은 `RecentTracking`, Live Grace 프리셋은 `LiveGraceTracking`으로 이어지는지 각각 확인한다.
6. `InvestigateLastLocation -> Search -> Patrol` 복귀를 확인한다.
7. 전체 사이클을 각 프리셋에서 최소 10회 반복한다.

## PASS 기준

- 모든 Patrol 목적지가 도달 가능한 NavMesh 위에 있다.
- 도착 또는 일시적 경로 선택 실패 후 다음 목적지를 계속 선택한다.
- Player 감지가 Patrol 이동과 대기보다 우선한다.
- 각 프리셋의 기존 Lost Sight 정책이 유지된다.
- Search 종료 후 Patrol로 복귀한다.
- 10회 반복 중 StateTree 고착, 영구 정지, Warning/Error가 없다.
