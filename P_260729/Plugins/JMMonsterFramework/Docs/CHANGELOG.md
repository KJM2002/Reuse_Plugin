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
