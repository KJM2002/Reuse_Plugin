---
title: "JMMonsterFramework Phase 4.6 Live Grace Test"
status: Current
authority: Guide
scope: "Live Grace Tracking verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE4_5_RECENT_TRACKING_TEST_KO.md"
---

# Phase 4.6 Live Grace Test

## 자동 검사

Automation 창에서 다음을 실행한다.

- `JM.MonsterFramework.Phase6.BuildAndValidateLiveGraceAssets`
- `JM.MonsterFramework.Phase4_6.LiveGraceState`
- 기존 `JM.MonsterFramework` 회귀 테스트

## 비교 배치

- Predictive: `BP_SimpleEnemy`
- Live Grace: `BP_SimpleEnemy_LiveGrace`

## PIE 절차

1. 두 프리셋을 NavMesh 위의 동일한 코너 환경에서 각각 테스트한다.
2. Live Grace Enemy에게 보인 뒤 코너를 돌고, 1.5초 안에 벽 뒤에서 방향을 꺾는다. Enemy가 실제 방향 전환을 따라가는지 확인한다.
3. 1.5초 넘게 도망간 뒤 다시 방향을 바꾼다. Enemy가 새 위치를 따라가지 않고 Grace 만료 위치를 Investigate하는지 확인한다.
4. Grace 도중 다시 나타나 즉시 Chase로 복귀하는지 확인한다.
5. 재감지 후 다시 숨고, 두 번째 Grace가 0초부터 1.5초 동안 새로 실행되는지 확인한다.
6. 끝까지 숨은 상태에서 `LiveGraceTracking -> InvestigateLastLocation -> Search -> Patrol`을 확인한다.
7. 위 성공/실패 흐름을 반복해 이동 요청 누적, 상태 고착, Warning/Error가 없는지 확인한다.

## PASS 기준

- Grace 안에서는 벽 뒤 실제 방향 전환을 추적한다.
- Grace 만료 직후부터 실제 위치 갱신이 멈춘다.
- 재감지는 즉시 Chase하며 다음 Sight Lost는 새 1.5초를 사용한다.
- 기존 Predictive 프리셋은 마지막 관측 정보만 사용한다.
- 기존 Investigate와 Search 흐름이 유지된다.
