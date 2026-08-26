---
title: "JMMonsterFramework Phase 10"
status: Current
authority: Guide
scope: "JMMonsterFramework Phase 0-10 setup and usage"
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
  - "Testing/PHASE8_MEMORY_REFACTOR_TEST_KO.md"
  - "Testing/PHASE9_LISTENER_ENEMY_TEST_KO.md"
  - "Testing/PHASE10_WATCHER_ENEMY_TEST_KO.md"
---

# JMMonsterFramework Phase 10

현재 범위는 Enemy 자동 Possession, NavMesh Patrol, Sight/Hearing, Chase, Basic Attack, 선택 가능한 Lost Sight Tracking, 위치 조사와 유한 Search다.

## 포함 기능

- `ASimpleEnemyCharacter`: Capsule, Mesh, CharacterMovement를 사용하는 최소 Enemy
- `ASimpleEnemyAIController`: Perception, 단일 `EnemyMemory`, StateTree 실행 소유
- `FJMSimpleEnemyMemory`: 현재 실제 사용하는 Sight, Hearing, Predictive, Live Grace 사실만 보관하며 행동을 결정하지 않음
- `AListenerEnemyAIController`: Patrol 중 Sight를 끄고 Hearing 조사 중에만 확인용 Sight를 켜는 2500uu 청각 중심 파생형
- `BP_ListenerEnemy`: 기존 Enemy 몸체·이동·공격을 재사용하는 실제 Listener 배치 프리셋
- `ST_ListenerEnemy`: `Patrol`, `InvestigateSound`, `Chase`, `Attack`, `Search`만 사용하는 Listener 전용 StateTree
- `AWatcherEnemyAIController`: 실제 Player Camera FOV의 85% 화면 영역, 다중 몸체 지점, Visibility Trace로 Gaze를 판정하는 Watcher
- `BP_WatcherEnemy`: 기존 Enemy 몸체와 Navigation을 재사용하는 실제 Watcher 배치 프리셋
- `ST_WatcherEnemy`: `WatchedStop`, `UnwatchedMove` 두 상태만 사용하는 Watcher 전용 StateTree
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

Listener는 `BP_ListenerEnemy`를 NavMesh 위에 배치한다. Patrol 중에는 Sight 자체가 비활성화되어 눈앞의 Player도 먼저 발견하지 않는다. Accepted Noise가 들어와 `InvestigateSound`가 시작된 동안에만 Sight를 켜 Player를 확인하며, 미발견 조사는 Sight를 다시 끄고 Patrol로 복귀한다.

Watcher는 `BP_WatcherEnemy`를 NavMesh 위에 배치한다. Watcher의 눈·상체·몸통·하체 중 하나가 실제 Player Camera FOV의 85% 화면 영역 안에 있고 Visibility Trace가 막히지 않으면 즉시 정지한다. 한 프레임 판정 흔들림은 0.12초 해제 완충으로 무시하며, 충분히 시선을 돌리거나 벽이 가리면 Player를 향해 이동할 수 있다. 별도 거리 제한은 없고 AI Sight나 Hearing도 Trigger로 사용하지 않는다.

Encounter 단계, Flee/Hide/ReApproach, Enrage/Frenzy, 복잡한 소음 단계/점수, Suspicion, Combo, Ability/Animation Framework와 장기·복수 대상 Memory Framework는 포함되지 않는다.
