---
title: "JMMonsterFramework Architecture"
status: Current
authority: Canonical
scope: "JMMonsterFramework Phase 0 runtime architecture"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "README.md"
  - "Testing/PHASE0_SMOKE_TEST_KO.md"
---

# JMMonsterFramework Architecture

## 책임

Phase 0는 재사용 가능한 최소 Enemy `ACharacter`와 이를 Possess하는 `AAIController`만 제공한다. Enemy의 CDO가 Controller 클래스와 자동 Possession 정책을 소유한다.

## 비책임

StateTree, AI Perception, Patrol, Attack, Memory, Hearing, Gameplay Tag, 저장, 네트워크 동기화, 특정 레벨 또는 호스트 프로젝트 연동은 제공하지 않는다.

## 모듈

- `JMMonsterFrameworkRuntime`: Shipping에서 사용할 수 있는 독립 Runtime 모듈
- `JMMonsterFrameworkTests`: CDO 구성만 검사하는 Editor 자동화 테스트 모듈

Runtime 의존성은 `Core`, `CoreUObject`, `Engine`, `AIModule`뿐이며 다른 JM 플러그인에는 의존하지 않는다.

## 데이터 흐름과 수명

`ASimpleEnemyCharacter`가 월드에 배치되거나 Spawn되면 Unreal의 Pawn 초기화 흐름이 `ASimpleEnemyAIController`를 생성하고 Possess한다. Controller와 Pawn 수명, UnPossess, 파괴 처리는 엔진 기본 정책을 사용한다. 별도 Subsystem, Component, Tick, Soft Reference는 없다.

## 공개 API와 실패 동작

두 클래스는 Blueprint 부모 클래스로만 공개된다. 외부 시스템 Cast, `/Game` 경로, 레벨 이름을 참조하지 않는다. NavMesh가 없거나 Pawn이 AI를 Spawn할 수 없는 월드에서는 엔진 기본 동작을 따르며 플러그인이 임의로 재시도하거나 Warning을 발생시키지 않는다.

## 네트워크와 저장

Phase 0는 별도의 Replication, RPC, Save 계약을 정의하지 않는다.
