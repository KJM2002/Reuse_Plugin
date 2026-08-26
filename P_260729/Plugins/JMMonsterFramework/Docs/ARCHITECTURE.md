---
title: "JMMonsterFramework Phase 10 Architecture"
status: Current
authority: Canonical
scope: "JMMonsterFramework Phase 0-10 runtime architecture"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "README.md"
  - "Testing/PHASE3_LAST_SEEN_TEST_KO.md"
  - "Testing/PHASE4_SEARCH_TEST_KO.md"
---

# JMMonsterFramework Architecture

## 책임

- Phase 0: 최소 Enemy Character와 자동 AI Possession
- Phase 1: 플레이어 전용 AI Sight와 `TargetActor`, `bCanSeeTarget`
- Phase 2: StateTree 기반 Chase와 NavMesh 이동
- Phase 3: `LastSeenLocation` 기억과 마지막 관측 위치 조사
- Phase 4: 마지막 위치 도착 후 제한 시간 동안 제자리 회전 Search
- Phase 4.5: 마지막 가시 위치와 속도만 사용하는 단기 예상 추적
- Phase 4.6: 별도 StateTree에서 제한 시간 동안만 숨은 Player Actor를 사용하는 Live Grace 추적
- Phase 5: 비상호작용 상태에서 도달 가능한 NavMesh 지점을 반복 방문하는 Patrol
- Phase 6: 가시 Player가 공격 범위 안에 있을 때 이동을 멈추고 Cooldown 기반 Damage 적용
- Phase 7: AI Hearing으로 단일 소리 위치를 기억하고 조사한 뒤 Patrol 복귀
- Phase 8: 실제 사용 중인 Sight, Hearing, Predictive, Live Grace 사실을 단일 `EnemyMemory` 소유 구조로 정리
- Phase 9: 실제 Hearing 경로를 주요 Trigger로 사용하는 첫 특수 Enemy `Listener` 추가
- Phase 10: 실제 Player Camera 방향과 Visibility Trace로 멈춤을 결정하는 특수 Enemy `Watcher` 추가

## 비책임

Encounter 단계, Flee/Hide/ReApproach, Enrage/Frenzy, Crawler, 소음 단계/누적/Threat Score, Suspicion, Combo, Ability/Animation Framework, Memory Manager/Subsystem/Interface, 장기·복수 대상 Memory는 제공하지 않는다.

## 모듈과 의존성

- `JMMonsterFrameworkRuntime`: Shipping에서 사용할 독립 Runtime 모듈
- `JMMonsterFrameworkTests`: StateTree 에셋 생성·컴파일과 상태 회귀 검사용 Editor 모듈

Runtime은 `Core`, `CoreUObject`, `Engine`, `AIModule`, `StateTreeModule`, `GameplayStateTreeModule`에만 의존한다. 다른 JM 플러그인이나 호스트 `/Game` 콘텐츠를 참조하지 않는다. StateTree 기본 에셋은 플러그인 Mount Point의 `/JMMonsterFramework/AI/ST_SimpleEnemy`다.

Predictive 정책은 기존 `/JMMonsterFramework/AI/ST_SimpleEnemy`, Live Grace 정책은 `/JMMonsterFramework/AI/ST_SimpleEnemy_LiveGrace`에 독립적으로 존재한다. `BP_SimpleEnemy`와 `BP_SimpleEnemy_LiveGrace` 프리셋으로 선택하며 enum, 정책 Component 또는 통합 Mode 분기는 없다.

## 데이터 흐름과 상태 전이

AI Perception 콜백은 Controller의 단일 `EnemyMemory`를 갱신하고, StateTree 조건과 Task는 그 값을 읽어 행동을 결정한다. `EnemyMemory` 자체에는 Chase, Investigate 같은 행동 분기가 없다.

AI Sight가 플레이어 Pawn을 감지하면 `EnemyMemory`의 `TargetActor`, `bCanSeeTarget`, `LastSeenLocation`, `LastSeenVelocity`, `LastSeenTime`을 갱신한다. 이 갱신은 `bCanSeeTarget`이 참인 동안에만 수행된다. Lost 자극에는 Sight가 보관한 마지막 성공 자극 위치가 들어오므로, 숨은 Actor의 현재 위치나 속도를 다시 읽지 않는다. 마지막 가시 속도에 1.5초를 곱하고 700uu로 제한한 오프셋을 마지막 관측 위치에 더해 `EstimatedTrackingLocation`을 한 번 만든 뒤 `TargetActor`를 즉시 비운다.

```text
Patrol -- 보임 --> Chase
Chase -- 150uu 안 --> Attack
Attack -- 범위 이탈 --> Chase
Attack -- 시야 상실 --> 선택된 Lost Sight Tracking
Chase -- 시야 상실 --> RecentTracking
RecentTracking -- 다시 보임 --> Chase
RecentTracking -- 1.5초 만료 --> InvestigateLastLocation
InvestigateLastLocation -- 다시 보임 --> Chase
InvestigateLastLocation -- 위치 도착/경로 실패 --> Search
Search -- 다시 보임 --> Chase
Search -- 제한 시간 종료 --> Patrol
Patrol -- 유효한 Hearing --> InvestigateSound
InvestigateSound -- 위치 도착/경로 실패 --> Patrol
InvestigateSound -- Sight 획득 --> Attack 또는 Chase
```

Chase는 `MoveToActor`로 가시 Actor를 동적으로 추적한다. RecentTracking은 시야 상실 때 고정된 `EstimatedTrackingLocation`으로만 이동하며 숨은 Actor를 참조하지 않는다. 1.5초 안에 재감지하면 Chase가 우선하고, 만료되면 Investigate로 이어진다. Investigate는 `MoveToLocation`에 `LastSeenLocation` 값만 전달한다. Search는 4초 동안 초당 90도로 Pawn과 Controller 시선을 함께 회전시켜 한 바퀴만 확인한다. RecentTracking과 Search의 경과 시간은 StateTree 인스턴스 데이터에만 존재하며 완료 시 폐기된다.

Live Grace StateTree만 `LiveGraceTargetActor` 약한 참조를 사용한다. Sight Lost마다 새 참조와 새 Task 경과 시간이 시작되고, 1.5초 동안 `MoveToActor`와 실제 위치 표본으로 `LastSeenLocation`을 갱신한다. 만료 시 참조와 유효 플래그를 먼저 제거하고 Investigate로 전환하므로 이후 Player 이동은 기억 위치에 반영되지 않는다.

두 StateTree의 평상시 상태는 Patrol이다. Patrol Task는 Pawn 현재 위치를 중심으로 반경 800uu 안의 `GetRandomReachablePointInRadius` 결과만 `MoveToLocation`에 전달한다. 목적지 도착 또는 이동 실패 후 1.5초를 기다리고 새 지점을 요청하며, Player가 보이면 OnTick 전이가 Patrol 이동보다 우선해 Chase로 이동한다. Search 완료 전이는 각 트리의 Patrol로 돌아간다.

Attack은 두 StateTree에서 동일한 Task와 조건을 사용한다. 150uu 안의 가시 Target만 선택하고 진입 시 `StopMovement` 후 `TakeDamage(10)`을 호출한다. 마지막 성공 공격 시간은 Controller에 남아 Attack/Chase 경계를 반복해도 1초 Cooldown을 우회할 수 없다. Attack Task는 Move 요청을 생성하지 않으며, 범위 이탈은 Chase로, Sight Lost는 각 트리 고유의 RecentTracking 또는 LiveGraceTracking으로 직접 전환한다.

Perception 콜백은 Sense ID로 Sight와 Hearing을 먼저 분리한다. 성공한 Hearing 자극의 유효 위치 하나만 `EnemyMemory.LastHeardLocation`에 저장하며 Sight가 활성화된 동안에는 저장하지 않는다. `InvestigateSound`는 이 위치의 스냅샷으로만 `MoveToLocation`을 수행하고 도착·경로 실패 후 메모리를 소비해 Patrol로 돌아간다. 조사 중 Player를 실제로 보면 Hearing 메모리를 폐기하고 Attack 또는 Chase가 즉시 우선한다.

Phase 8은 새 행동을 추가하지 않는다. Controller의 이전 개별 런타임 변수는 제거됐고 Predictive와 Live Grace StateTree는 통합되지 않은 채 각각 같은 `EnemyMemory`에서 필요한 사실만 읽는다.

## Listener Enemy

`AListenerEnemyAIController`는 `ASimpleEnemyAIController`의 Perception, Memory, Navigation, Attack 구현을 그대로 상속한다. 새 감각 Component나 전략 Interface를 만들지 않는다. Listener는 2500uu Hearing을 주요 Trigger로 사용하며 Patrol 진입 시 Sight를 비활성화한다. 실제 Hearing으로 `InvestigateSound`에 들어갈 때만 Sight를 켜고, 조사 실패로 Patrol에 복귀하면 다시 끈다. `BP_ListenerEnemy`는 기존 `BP_SimpleEnemy` 몸체를 상속하고 실제 `BP_ListenerEnemyAIController`를 사용한다.

```text
Patrol -- 실제 Hearing --> InvestigateSound
Patrol -- Player가 눈앞에 있음 --> Patrol 유지
InvestigateSound -- 최신 Noise --> 새 SoundLocation으로 MoveTo 갱신
InvestigateSound -- Sight 획득 --> Chase 또는 Attack
InvestigateSound -- 도착/경로 실패 --> Sight 비활성화 후 Patrol
Chase/Attack -- Sight 상실 --> Search
Search -- 완료 --> Sight 비활성화 후 Patrol
```

반복 Noise 정책은 가장 최근 Accepted 위치 우선 하나뿐이다. `InvestigateSound` Task의 현재 목적지와 `EnemyMemory.LastHeardLocation`이 달라지면 기존 Move 요청을 새 위치로 갱신한다. Strength는 RAW 및 Accepted/Rejected 로그에 남기지만 점수화·누적·분류하지 않는다. Hearing 로그에는 Sound Location과 현재 활성 StateTree State도 함께 기록한다.

## Watcher Enemy

`AWatcherEnemyAIController`는 기존 Character, Possession, Navigation, StateTree 실행만 재사용한다. Possess 후 AI Perception Sight와 Hearing을 모두 비활성화하므로 기존 `Enemy → Player` 감지는 Watcher 상태를 바꾸지 않는다. Controller Tick은 실제 첫 PlayerController의 `GetPlayerViewPoint`에서 Camera Location과 View Rotation을 읽고 다음 경로 하나만 계산한다.

```text
Player Camera Location + View Direction
→ Watcher 눈 위치 방향과 Dot Product
→ 실제 Camera FOV와 Viewport 비율의 85% 화면 영역 판정
→ 눈·상체·몸통·하체 Visibility Trace
→ bPlayerIsWatchingWatcher
→ ST_WatcherEnemy
```

Player와 Player 부착 Actor는 Trace에서 제외하며 Watcher 또는 Watcher 부착 Actor에 도달하면 보이는 것으로 인정한다. 네 표본점 중 하나라도 화면 영역과 Visibility를 통과하면 Watched다. 다른 Blocking Actor가 모든 유효 표본점을 가리면 카메라 방향이 일치해도 Watched가 아니다. 별도 최대 거리는 없으며 Watched 해제에만 0.12초 완충을 사용해 단일 프레임 흔들림을 막는다.

```text
WatchedStop -- 시선 이탈/벽 차단 --> UnwatchedMove
UnwatchedMove -- 각도와 Visibility 모두 통과 --> WatchedStop
```

`WatchedStop`은 매 Tick `StopMovement`만 수행한다. `UnwatchedMove`는 실제 Player Pawn으로 `MoveToActor`를 요청한다. Encounter 횟수, 도망, 숨기, 재접근, 분노 같은 추가 행동은 없다.

## 수명과 실패 동작

`UStateTreeAIComponent`는 AIController가 소유하며 Possess 시 플러그인 StateTree를 동기 로드해 시작한다. 작은 필수 동작 에셋이므로 Possess 시 로드하며, 누락 시 Error를 남기고 AI 행동만 시작하지 않는다. 별도 Subsystem은 없으며 Controller Tick은 Watcher의 실제 카메라 Gaze 판정에만 사용한다.

## 네트워크와 저장

현재 상태는 로컬 런타임 전용이며 Replication, RPC, Save 계약을 정의하지 않는다. `LastSeenLocation`은 영속 기억이 아닌 현재 AI 세션의 단일 임시 위치다.
