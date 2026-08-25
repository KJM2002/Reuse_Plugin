---
title: "JMMonsterFramework Phase 1 Architecture"
status: Current
authority: Canonical
scope: "JMMonsterFramework Phase 0-1 runtime architecture"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "README.md"
  - "Testing/PHASE0_SMOKE_TEST_KO.md"
  - "Testing/PHASE1_SIGHT_TEST_KO.md"
---

# JMMonsterFramework Architecture

## 책임

Phase 0는 재사용 가능한 최소 Enemy `ACharacter`와 이를 Possess하는 `AAIController`를 제공한다. Phase 1은 Controller에 플레이어 전용 AI Sight를 추가한다. Controller가 현재 가시 상태인 `TargetActor`와 `bCanSeeTarget`을 소유한다.

## 비책임

StateTree, Patrol, Attack, 장기 Memory, Hearing, Gameplay Tag, 저장, 네트워크 동기화, 특정 레벨 또는 호스트 프로젝트 연동은 제공하지 않는다.

## 모듈

- `JMMonsterFrameworkRuntime`: Shipping에서 사용할 수 있는 독립 Runtime 모듈
- `JMMonsterFrameworkTests`: CDO 구성만 검사하는 Editor 자동화 테스트 모듈

Runtime 의존성은 `Core`, `CoreUObject`, `Engine`, `AIModule`뿐이며 다른 JM 플러그인에는 의존하지 않는다.

## 데이터 흐름과 수명

`ASimpleEnemyCharacter`가 월드에 배치되거나 Spawn되면 Unreal의 Pawn 초기화 흐름이 `ASimpleEnemyAIController`를 생성하고 Possess한다. Controller의 `UAIPerceptionComponent`는 Sight 자극 중 플레이어가 조종하는 Pawn만 받아들인다. 감지 성공은 `TargetActor`와 `bCanSeeTarget`을 설정하고, 동일 대상의 감지 실패는 두 값을 초기화한다. 별도 Subsystem, Tick, 이동 명령, Soft Reference는 없다.

## 공개 API와 실패 동작

두 클래스와 Controller의 읽기 전용 Sight 상태는 Blueprint에 공개된다. 외부 시스템 Cast, `/Game` 경로, 레벨 이름을 참조하지 않는다. 중복 Detected/Lost 자극과 다른 Actor의 Lost 자극은 상태를 흔들지 않으며 Warning을 발생시키지 않는다.

## 네트워크와 저장

Phase 0는 별도의 Replication, RPC, Save 계약을 정의하지 않는다.
