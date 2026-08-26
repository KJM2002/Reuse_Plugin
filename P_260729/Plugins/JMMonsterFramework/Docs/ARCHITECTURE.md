---
title: "JMMonsterFramework Phase 4.5 Architecture"
status: Current
authority: Canonical
scope: "JMMonsterFramework Phase 0-4.5 runtime architecture"
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

## 비책임

Patrol, Attack, Hearing, 장기·복수 대상 Memory, 복잡한 궤적 예측, Gameplay Tag, 저장, 네트워크 동기화, 특정 레벨 연동은 제공하지 않는다.

## 모듈과 의존성

- `JMMonsterFrameworkRuntime`: Shipping에서 사용할 독립 Runtime 모듈
- `JMMonsterFrameworkTests`: StateTree 에셋 생성·컴파일과 상태 회귀 검사용 Editor 모듈

Runtime은 `Core`, `CoreUObject`, `Engine`, `AIModule`, `StateTreeModule`, `GameplayStateTreeModule`에만 의존한다. 다른 JM 플러그인이나 호스트 `/Game` 콘텐츠를 참조하지 않는다. StateTree 기본 에셋은 플러그인 Mount Point의 `/JMMonsterFramework/AI/ST_SimpleEnemy`다.

## 데이터 흐름과 상태 전이

AI Sight가 플레이어 Pawn을 감지하면 Controller가 `TargetActor`, `bCanSeeTarget`, `LastSeenLocation`, `LastSeenVelocity`, `LastSeenTime`을 갱신한다. 이 갱신은 `bCanSeeTarget`이 참인 동안에만 수행된다. Lost 자극에는 Sight가 보관한 마지막 성공 자극 위치가 들어오므로, 숨은 Actor의 현재 위치나 속도를 다시 읽지 않는다. 마지막 가시 속도에 1.5초를 곱하고 700uu로 제한한 오프셋을 마지막 관측 위치에 더해 `EstimatedTrackingLocation`을 한 번 만든 뒤 `TargetActor`를 즉시 비운다.

```text
Idle -- 보임 --> Chase
Chase -- 시야 상실 --> RecentTracking
RecentTracking -- 다시 보임 --> Chase
RecentTracking -- 1.5초 만료 --> InvestigateLastLocation
InvestigateLastLocation -- 다시 보임 --> Chase
InvestigateLastLocation -- 위치 도착/경로 실패 --> Search
Search -- 다시 보임 --> Chase
Search -- 제한 시간 종료 --> Idle
```

Chase는 `MoveToActor`로 가시 Actor를 동적으로 추적한다. RecentTracking은 시야 상실 때 고정된 `EstimatedTrackingLocation`으로만 이동하며 숨은 Actor를 참조하지 않는다. 1.5초 안에 재감지하면 Chase가 우선하고, 만료되면 Investigate로 이어진다. Investigate는 `MoveToLocation`에 `LastSeenLocation` 값만 전달한다. Search는 4초 동안 초당 90도로 Pawn과 Controller 시선을 함께 회전시켜 한 바퀴만 확인한다. RecentTracking과 Search의 경과 시간은 StateTree 인스턴스 데이터에만 존재하며 완료 시 폐기된다.

## 수명과 실패 동작

`UStateTreeAIComponent`는 AIController가 소유하며 Possess 시 플러그인 StateTree를 동기 로드해 시작한다. 작은 필수 동작 에셋이므로 Possess 시 로드하며, 누락 시 Error를 남기고 AI 행동만 시작하지 않는다. 별도 Subsystem과 Controller Tick은 없다.

## 네트워크와 저장

현재 상태는 로컬 런타임 전용이며 Replication, RPC, Save 계약을 정의하지 않는다. `LastSeenLocation`은 영속 기억이 아닌 현재 AI 세션의 단일 임시 위치다.
