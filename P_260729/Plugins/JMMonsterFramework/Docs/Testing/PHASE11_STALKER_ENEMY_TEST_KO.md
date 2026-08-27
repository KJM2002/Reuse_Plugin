---
title: "JMMonsterFramework Phase 11 Stalker Enemy Test"
status: Current
authority: Guide
scope: "Stalker actual Sight, distance band, and NavMesh movement verification"
last_verified: 2026-08-27
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE10_WATCHER_ENEMY_TEST_KO.md"
---

# Phase 11 Stalker Enemy Test

## 자동 검사

`Tools → Test Automation`에서 다음을 실행한다.

- `JM.MonsterFramework.Stalker.BuildAndValidateAssets`
- `JM.MonsterFramework.Stalker.PIERuntimeNavMeshPath`
- 전체 `JM.MonsterFramework`

`PIERuntimeNavMeshPath`는 Controller 거리나 Distance Band를 직접 설정하지 않는다. 실제 `Level_TestAI`를 PIE로 열고 실제 NavMesh에서 `BP_StalkerEnemy`, BP Controller, Player Blueprint를 Spawn/Possess한다. Player Actor를 실제 NavMesh 위치로 옮기며 다음 경로를 검증한다.

```text
실제 Player 위치 변경
→ UAISense_Sight
→ UAIPerceptionComponent
→ EnemyMemory Target
→ 실제 Actor 2D 거리
→ Stalker Distance Band
→ Stalker StateTree
→ MoveToActor / ProjectPointToNavigation / MoveToLocation
```

## PIE 준비

1. `Level_TestAI`의 녹색 NavMesh 위에 `/JMMonsterFramework/Blueprints/BP_StalkerEnemy`를 배치한다.
2. Player와 Stalker 사이의 Visibility를 막는 물체가 없는 테스트 구간을 확보한다.
3. `showdebug ai` 또는 StateTree Debugger로 Stalker Controller와 활성 State를 확인한다.
4. 기본값 `MinimumFollowDistance=450`, `MaximumFollowDistance=750`, `DistanceHysteresis=75`를 확인한다.

## 시나리오 A — 멀리서 접근

1. Player를 Stalker 시야 안 1000~1400uu에 둔다.
2. 실제 Sight 감지 후 `Approach`로 전환하는지 확인한다.
3. Stalker가 NavMesh 위에서 Player 방향으로 이동하고 거리가 감소하는지 확인한다.

## 시나리오 B — 적정 거리 유지

1. Player를 약 600uu 거리에 둔다.
2. `HoldDistance`에서 Move가 정지하는지 확인한다.
3. Player가 정지한 상태에서 Stalker가 계속 밀고 들어오지 않는지 확인한다.

## 시나리오 C — 가까우면 후퇴

1. Player가 180uu 정도까지 빠르게 접근한다.
2. Stalker가 `Retreat`로 전환하는지 확인한다.
3. Stalker가 Player를 바라본 채 뒤로 이동하고 거리가 증가하는지 확인한다.
4. 후퇴 목적지와 실제 Stalker 위치가 NavMesh 위인지 확인한다.

## 시나리오 D — 경계 진동

1. Player를 720uu와 790uu 사이로 빠르게 12회 왕복시킨다.
2. 75uu 히스테리시스 안에서는 `HoldDistance`가 유지되는지 확인한다.
3. `Approach ↔ HoldDistance`가 프레임마다 반복되지 않는지 확인한다.

## 시나리오 E — Sight Lost

1. Player를 Lose Sight 범위 밖으로 이동하거나 Visibility 벽 뒤로 숨긴다.
2. Distance Band가 `None`으로 정리되는지 확인한다.
3. `RecentTracking → InvestigateLastLocation → Search → Patrol` 흐름이 정상인지 확인한다.

## PASS 기준

- 실제 Stalker BP가 실제 Stalker BP Controller에 Possess된다.
- 실제 Sight로 발견한 Player만 거리 행동의 Target이 된다.
- 멀면 접근하고, 적정 거리에서는 정지하며, 가까우면 후퇴한다.
- 후퇴는 Player를 바라본 상태에서 수행된다.
- 후퇴 목적지와 이동 결과가 NavMesh 위에 있다.
- 실제 Player 경계 왕복과 빠른 접근에서 심한 상태 진동이 없다.
- Sight Lost 후 기존 Predictive 정책과 Patrol 복귀가 정상이다.
- Watcher Gaze, Attack, Hearing 같은 추가 Gameplay를 Stalker에 섞지 않는다.
- 기존 Phase 0~10 기능에 회귀가 없고 Warning/Error가 없다.
