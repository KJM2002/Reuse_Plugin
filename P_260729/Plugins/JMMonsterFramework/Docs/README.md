---
title: "JMMonsterFramework Phase 7"
status: Current
authority: Guide
scope: "JMMonsterFramework Phase 0-7 setup and usage"
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
  - "Testing/PHASE4_6_LIVE_GRACE_TEST_KO.md"
  - "Testing/PHASE5_PATROL_TEST_KO.md"
  - "Testing/PHASE6_BASIC_ATTACK_TEST_KO.md"
  - "Testing/PHASE7_BASIC_HEARING_TEST_KO.md"
---

# JMMonsterFramework Phase 7

현재 범위는 Enemy 자동 Possession, NavMesh Patrol, Sight/Hearing, Chase, Basic Attack, 선택 가능한 Lost Sight Tracking, 위치 조사와 유한 Search다.

## 포함 기능

- `ASimpleEnemyCharacter`: Capsule, Mesh, CharacterMovement를 사용하는 최소 Enemy
- `ASimpleEnemyAIController`: Sight 상태, 마지막 가시 위치·속도, 제한된 예상 위치와 StateTree 실행 소유
- `ST_SimpleEnemy`: `Patrol`, `Chase`, `Attack`, `RecentTracking`, `InvestigateLastLocation`, `Search`, `InvestigateSound`
- `ST_SimpleEnemy_LiveGrace`: `Patrol`, `Chase`, `Attack`, `LiveGraceTracking`, `InvestigateLastLocation`, `Search`, `InvestigateSound`
- `Patrol`: 반경 800uu 안의 도달 가능한 NavMesh 목적지를 반복 방문하고 1.5초 대기
- `Chase`: 보이는 `TargetActor`를 NavMesh로 추적
- `Attack`: 150uu 안의 가시 Player에게 1초마다 10 Damage를 적용하고 이동 중지
- `InvestigateSound`: 1500uu 안에서 감지한 단일 Sound Location으로 이동한 뒤 Patrol 복귀
- `RecentTracking`: Sight Lost 순간 만든 예상 위치를 최대 1.5초 동안 추적
- `LiveGraceTracking`: 별도 프리셋에서 Sight Lost 후 실제 Player Actor를 최대 1.5초 동안 추적
- `InvestigateLastLocation`: 시야를 잃은 순간의 실제 마지막 관측 위치까지만 이동
- `Search`: 도착 후 4초 동안 제자리에서 한 바퀴 탐색하고 미발견 시 Patrol

## 사용

1. `/JMMonsterFramework/Blueprints/BP_SimpleEnemy`에 필요한 Mesh와 Animation Blueprint를 지정한다.
2. `AI Controller Class`가 `ASimpleEnemyAIController`인지 확인한다.
3. `Auto Possess AI`가 `Placed in World or Spawned`인지 확인한다.
4. 사용자가 만든 `Level_TestAI`의 녹색 NavMesh 위에 배치한다.
5. 플레이어와 Enemy 사이의 벽이 Visibility 채널을 차단하는지 확인한다.

Predictive 방식은 기존 `BP_SimpleEnemy`, Live Grace 방식은 `BP_SimpleEnemy_LiveGrace`를 배치해 독립적으로 비교한다.

Listener, 복잡한 소음 단계/점수, Suspicion, Combo, Ability/Animation Framework와 장기 Memory는 포함되지 않는다.
