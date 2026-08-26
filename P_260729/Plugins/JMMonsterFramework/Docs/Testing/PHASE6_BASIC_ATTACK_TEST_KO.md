---
title: "JMMonsterFramework Phase 6 Basic Attack Test"
status: Current
authority: Guide
scope: "Basic Attack verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE5_PATROL_TEST_KO.md"
---

# Phase 6 Basic Attack Test

## 자동 검사

Automation 창에서 다음을 실행한다.

- `JM.MonsterFramework.Phase6.BuildAndValidatePredictiveStateTree`
- `JM.MonsterFramework.Phase6.BuildAndValidateLiveGraceAssets`
- 전체 `JM.MonsterFramework` 회귀 테스트

## PIE 절차

1. `BP_SimpleEnemy`와 `BP_SimpleEnemy_LiveGrace`를 NavMesh 위에서 각각 테스트한다.
2. 150uu 밖에서 Enemy가 Chase만 하고 `BasicAttack` 로그를 남기지 않는지 확인한다.
3. 150uu 안으로 들어가면 이동이 중단되고 `BasicAttack` 로그와 10 Damage가 발생하는지 확인한다.
4. 범위 안에 머물며 공격 간격이 최소 1초인지 확인한다.
5. 공격 경계를 빠르게 드나들어도 Cooldown을 우회해 난사하지 않는지 확인한다.
6. 범위 밖으로 나가면 Chase가 재개되고, 다시 들어오면 Cooldown 이후 Attack하는지 확인한다.
7. Attack 중 시야를 끊어 Predictive는 RecentTracking, Live Grace는 LiveGraceTracking으로 이동하는지 확인한다.
8. 이후 `InvestigateLastLocation -> Search -> Patrol` 회귀를 확인한다.

## PASS 기준

- 공격 범위 밖에서는 Damage가 없다.
- Attack 중 MoveTo 요청과 경쟁하지 않는다.
- 성공 공격 사이에 1초 Cooldown이 유지된다.
- 범위 이탈과 재진입이 Attack/Chase를 고착시키지 않는다.
- Target Lost 시 선택된 4.5/4.6 정책이 유지된다.
- 반복 PIE에서 Warning/Error가 없다.
