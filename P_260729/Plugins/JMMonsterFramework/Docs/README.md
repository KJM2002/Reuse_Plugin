---
title: "JMMonsterFramework Phase 4.5"
status: Current
authority: Guide
scope: "JMMonsterFramework Phase 0-4.5 setup and usage"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "ARCHITECTURE.md"
  - "CHANGELOG.md"
  - "Testing/PHASE0_SMOKE_TEST_KO.md"
  - "Testing/PHASE1_SIGHT_TEST_KO.md"
  - "Testing/PHASE2_CHASE_TEST_KO.md"
  - "Testing/PHASE3_LAST_SEEN_TEST_KO.md"
  - "Testing/PHASE4_SEARCH_TEST_KO.md"
  - "Testing/PHASE4_5_RECENT_TRACKING_TEST_KO.md"
---

# JMMonsterFramework Phase 4.5

현재 범위는 Enemy 자동 Possession, 플레이어 Sight, StateTree Chase, 짧은 Recent Tracking, 마지막 관측 위치 조사와 유한 Search다.

## 포함 기능

- `ASimpleEnemyCharacter`: Capsule, Mesh, CharacterMovement를 사용하는 최소 Enemy
- `ASimpleEnemyAIController`: Sight 상태, 마지막 가시 위치·속도, 제한된 예상 위치와 StateTree 실행 소유
- `ST_SimpleEnemy`: `Idle`, `Chase`, `RecentTracking`, `InvestigateLastLocation`, `Search`
- `Chase`: 보이는 `TargetActor`를 NavMesh로 추적
- `RecentTracking`: Sight Lost 순간 만든 예상 위치를 최대 1.5초 동안 추적
- `InvestigateLastLocation`: 시야를 잃은 순간의 실제 마지막 관측 위치까지만 이동
- `Search`: 도착 후 4초 동안 제자리에서 한 바퀴 탐색하고 미발견 시 Idle

## 사용

1. `/JMMonsterFramework/Blueprints/BP_SimpleEnemy`에 필요한 Mesh와 Animation Blueprint를 지정한다.
2. `AI Controller Class`가 `ASimpleEnemyAIController`인지 확인한다.
3. `Auto Possess AI`가 `Placed in World or Spawned`인지 확인한다.
4. 사용자가 만든 `Level_TestAI`의 녹색 NavMesh 위에 배치한다.
5. 플레이어와 Enemy 사이의 벽이 Visibility 채널을 차단하는지 확인한다.

Patrol, Attack, Hearing, 장기 Memory와 범용 예측 시스템은 포함되지 않는다.
