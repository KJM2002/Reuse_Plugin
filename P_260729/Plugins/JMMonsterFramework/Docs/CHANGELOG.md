---
title: "JMMonsterFramework Changelog"
status: Current
authority: Historical
scope: "JMMonsterFramework release history"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
---

# Changelog

## 1.11.0 - 2026-08-27

### Added

- 실제 Sight Target과의 2D 거리로 `TooFar`, `Preferred`, `TooClose`를 구분하는 `AStalkerEnemyAIController`
- 멀면 `Approach`, 선호 거리면 `HoldDistance`, 가까우면 NavMesh 위치로 `Retreat`하는 Stalker StateTree Task
- 실제 배치용 `BP_StalkerEnemy`, `BP_StalkerEnemyAIController`, `ST_StalkerEnemy`
- 실제 `Level_TestAI` PIE와 기존 NavMesh에서 Player 이동·접근·유지·후퇴·Sight Lost를 검증하는 통합 검사

### Changed

- 75uu 거리 히스테리시스로 경계 왕복과 빠른 접근에서 상태 진동 방지
- 후퇴 중 Player Focus를 유지해 등을 돌리며 실제 Sight를 잃는 문제 방지
- Stalker Sight Lost를 기존 Predictive Tracking → Investigate → Search → Patrol 흐름에 연결

## 1.10.1 - 2026-08-26

### Changed

- 고정 중앙 12도·눈 한 점 Gaze를 실제 Camera FOV와 Viewport 비율의 85% 화면 영역 판정으로 교체
- Watcher 눈·상체·몸통·하체 네 지점 중 하나라도 실제로 보이면 Watched로 인정
- 거리 제한 없이 5000uu에서도 같은 카메라 화면 기준을 사용하도록 회귀 검사 추가
- 한 프레임 Gaze 손실에 움직이지 않도록 0.12초 Watched 해제 완충 추가
- Gaze 로그의 `Angle`을 실제 의미에 맞는 `Screen`으로 변경

## 1.10.0 - 2026-08-26

### Added

- 실제 Player Camera Location과 View Direction을 사용하는 `AWatcherEnemyAIController`
- 중앙 12도 View Angle과 `ECC_Visibility` Trace를 모두 통과해야만 Watched가 되는 Gaze 판정
- 실제 배치용 `BP_WatcherEnemy`, `BP_WatcherEnemyAIController`, `ST_WatcherEnemy`
- `WatchedStop`과 `UnwatchedMove` 두 상태만 사용하는 Watcher 행동
- 실제 BP Possession, ViewPoint, 각도, 벽 차단, StateTree 전달과 20회 빠른 시선 반복 통합 검사

### Changed

- Player 부착 Actor는 Gaze Trace에서 제외하고 Watcher 부착 Actor는 Watcher 본체로 인정

## 1.9.0 - 2026-08-26

### Added

- 기존 AIController 기능을 상속하되 Patrol 중 Sight를 비활성화하는 `AListenerEnemyAIController`
- 실제 배치용 `BP_ListenerEnemy`, `BP_ListenerEnemyAIController`, `ST_ListenerEnemy`
- 2500uu Hearing을 주요 Trigger로 사용하는 Patrol → Sound Investigate → Patrol 흐름
- 실제 Hearing 조사 진입 시에만 Sight를 활성화하고 조사 실패·Search 종료 후 Patrol에서 다시 비활성화
- Sound 조사 중 Sight 획득 시 기존 Chase/Attack 우선 전환
- 실제 BP Possession, Perception Component, Hearing Config, StateTree, Report Noise Event를 사용하는 Listener 통합 검사

### Changed

- 반복 Noise는 가장 최근 Accepted Sound Location으로 조사 목적지를 갱신
- Hearing Accepted/Rejected 로그에 Strength, Location, 현재 StateTree State 출력

## 1.8.0 - 2026-08-26

### Changed

- 실제 사용 중인 Sight, Hearing, Predictive, Live Grace 데이터를 `FJMSimpleEnemyMemory` 하나로 이동
- AI Perception은 Memory 사실만 갱신하고 기존 StateTree가 행동을 결정하도록 책임 분리
- Predictive와 Live Grace StateTree의 Lost Sight 정책 및 독립 에셋 구조 유지
- 실제 BP Enemy/Controller/Player와 AI System을 사용하는 Sight/Hearing 런타임 통합 검사 추가
- Enemy/Controller Blueprint 네 개를 재컴파일해 제거된 Controller 변수 참조와 Native 기본값 직렬화 회귀 검사

## 1.7.0 - 2026-08-26

### Added

- 1500uu 범위의 AI Perception Hearing 설정
- 단일 유효 소리 위치를 기억하는 `LastHeardLocation`, `bHasHeardSound`
- 소리 위치까지 NavMesh로 이동한 뒤 Patrol로 복귀하는 `InvestigateSound`
- Sound 조사 중 Sight 획득 시 거리별 Attack/Chase 우선 전환
- 실패·잘못된 위치의 Hearing 자극 무시 및 Sight/Hearing 분리 회귀 검사
- 기존 Blueprint Controller의 Sight-only 직렬화가 Hearing을 제거하지 않도록 Possess 시 Listener 설정 복구

## 1.6.0 - 2026-08-26

### Added

- 가시 Player가 150uu 안에 들어오면 선택되는 StateTree `Attack` 상태
- Attack 진입 시 이동 중지와 10 Damage의 기본 공격
- 상태 재진입으로 우회되지 않는 1초 공격 Cooldown
- 공격 범위 이탈 시 Chase, Sight Lost 시 기존 Predictive/Live Grace Tracking 전이
- 공격 성공을 확인할 수 있는 `BasicAttack` 런타임 로그

## 1.5.0 - 2026-08-26

### Added

- 현재 위치 반경 800uu 안의 도달 가능한 NavMesh 목적지를 선택하는 `Patrol`
- 목적지 도착 후 1.5초 대기하고 다음 목적지를 반복 선택하는 Patrol Task
- Patrol 중 Player 감지 시 즉시 Chase 전환
- Search 완료 후 Idle 대신 Patrol 복귀
- Predictive와 Live Grace StateTree의 기존 Lost Sight 정책을 유지한 독립 Patrol 연결

## 1.4.6 - 2026-08-26

### Added

- 독립 에셋 `ST_SimpleEnemy_LiveGrace`
- Sight Lost 후 1.5초 동안 실제 Player Actor를 추적하는 `LiveGraceTracking`
- Grace 중 `LastSeenLocation` 갱신과 만료 즉시 Live Target 참조 해제
- 기존 Predictive 에셋과 나란히 배치 가능한 Live Grace Blueprint 프리셋
- Grace 만료 후 실제 위치 갱신 차단 자동화 검사

## 1.4.5 - 2026-08-26

### Added

- 시야 중에만 갱신되는 `LastSeenVelocity`, `LastSeenTime`
- 시야 상실 시 한 번 계산되는 최대 700uu의 `EstimatedTrackingLocation`
- 1.5초 제한의 StateTree `RecentTracking` 상태
- Tracking 중 재감지 시 즉시 Chase, 만료 시 기존 Investigate/Search 전이
- 숨은 Player Transform/Velocity를 읽지 않는 반복 회귀 검사

## 1.4.0 - 2026-08-26

### Added

- StateTree `Search` 상태
- 4초 동안 한 바퀴 제자리 회전하는 유한 Search Task
- Search 중 Sight 재감지 시 Chase, 시간 종료 시 Idle 전이
- Phase 4 StateTree 컴파일 검사와 수동 테스트 절차

## 1.3.0 - 2026-08-26

### Added

- Blueprint 읽기 전용 `LastSeenLocation`
- StateTree `InvestigateLastLocation` 상태
- 마지막 관측 위치 전용 NavMesh 이동 Task
- 재감지 시 Chase 복귀, 도착 또는 경로 실패 시 Idle 복귀
- 20회 반복 Last Seen Location 회귀 검사와 Phase 3 수동 테스트 절차

## 1.2.0 - 2026-08-25

### Added

- Controller 소유 `UStateTreeAIComponent`
- `Idle`, `Chase` StateTree와 `Can See Target` 조건
- 움직이는 `TargetActor`를 추적하는 NavMesh 이동 Task
- StateTree 에셋 생성·컴파일 자동화 테스트

## 1.1.0 - 2026-08-25

### Added

- 플레이어 제어 Pawn만 감지하는 AI Sight
- Blueprint 읽기 전용 `TargetActor`, `bCanSeeTarget`
- Detected/Lost 전환 로그
- 20회 반복 상태 전환 자동화 테스트와 수동 Sight 테스트 절차

## 1.0.0 - 2026-08-25

### Added

- Phase 0 `ASimpleEnemyCharacter`
- Phase 0 `ASimpleEnemyAIController`
- 배치 및 Spawn 시 자동 AI Possession 기본값
- 기본 구성 자동화 테스트와 `Level_TestAI` 수동 Smoke Test 절차
