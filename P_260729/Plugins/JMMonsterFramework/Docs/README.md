---
title: "JMMonsterFramework Phase 0"
status: Current
authority: Guide
scope: "JMMonsterFramework Phase 0 setup and usage"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "ARCHITECTURE.md"
  - "CHANGELOG.md"
  - "Testing/PHASE0_SMOKE_TEST_KO.md"
---

# JMMonsterFramework Phase 0

이 플러그인의 현재 범위는 Enemy 몸체와 AIController의 자동 Possession 검증뿐이다.

## 포함 기능

- `ASimpleEnemyCharacter`: `ACharacter`의 Capsule, Mesh, CharacterMovement를 그대로 사용하는 최소 Enemy
- `ASimpleEnemyAIController`: 행동 로직이 없는 최소 AIController
- 배치 및 런타임 Spawn 모두에 대한 자동 AI Possession 기본값

## 포함 Blueprint

`/JMMonsterFramework/Blueprints/BP_SimpleEnemy`가 포함되어 있다. 부모 클래스는 `ASimpleEnemyCharacter`다.

1. 필요하면 `BP_SimpleEnemy`에 Skeletal Mesh와 Animation Blueprint만 지정한다.
2. `AI Controller Class`가 `ASimpleEnemyAIController`인지 확인한다.
3. `Auto Possess AI`가 `Placed in World or Spawned`인지 확인한다.
4. 사용자가 만든 `Level_TestAI`의 NavMesh 위에 배치한다.

StateTree, Perception, Patrol, Attack, Memory, Hearing은 Phase 0에 포함되지 않는다.
