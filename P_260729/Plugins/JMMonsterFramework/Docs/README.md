---
title: "JMMonsterFramework Phase 1"
status: Current
authority: Guide
scope: "JMMonsterFramework Phase 0-1 setup and usage"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "ARCHITECTURE.md"
  - "CHANGELOG.md"
  - "Testing/PHASE0_SMOKE_TEST_KO.md"
  - "Testing/PHASE1_SIGHT_TEST_KO.md"
---

# JMMonsterFramework Phase 1

이 플러그인의 현재 범위는 Enemy 자동 Possession과 플레이어 Sight 감지다. Enemy는 아직 움직이지 않는다.

## 포함 기능

- `ASimpleEnemyCharacter`: `ACharacter`의 Capsule, Mesh, CharacterMovement를 그대로 사용하는 최소 Enemy
- `ASimpleEnemyAIController`: 행동 로직이 없는 최소 AIController
- 배치 및 런타임 Spawn 모두에 대한 자동 AI Possession 기본값
- 플레이어가 보일 때 `TargetActor`와 `bCanSeeTarget` 갱신
- 시야를 잃을 때 두 상태를 즉시 초기화

## 포함 Blueprint

`/JMMonsterFramework/Blueprints/BP_SimpleEnemy`가 포함되어 있다. 부모 클래스는 `ASimpleEnemyCharacter`다.

1. 필요하면 `BP_SimpleEnemy`에 Skeletal Mesh와 Animation Blueprint만 지정한다.
2. `AI Controller Class`가 `ASimpleEnemyAIController`인지 확인한다.
3. `Auto Possess AI`가 `Placed in World or Spawned`인지 확인한다.
4. 사용자가 만든 `Level_TestAI`의 NavMesh 위에 배치한다.

StateTree, Patrol, Attack, 장기 Memory, Hearing은 Phase 1에 포함되지 않는다.
