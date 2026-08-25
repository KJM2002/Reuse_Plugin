---
title: "JMMonsterFramework Phase 2 Chase Test"
status: Current
authority: Guide
scope: "Player chase verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
---

# Phase 2 Chase Test

## 자동 검사

Automation 창의 `JM.MonsterFramework.Phase3.BuildAndValidateStateTree`가 Phase 2 Chase 노드까지 함께 컴파일하고 검증한다.

## Level_TestAI 수동 검사

1. `BP_SimpleEnemy`와 NavMesh Bounds Volume을 준비한다.
2. Enemy 전방에서 Player를 앞, 옆, 뒤, 원형으로 움직인다.
3. Enemy가 보이는 Player를 계속 따라가며 벽을 통과하거나 불필요하게 회전하지 않는지 확인한다.
4. Player가 잠시 멈췄다가 다시 멀어져도 Enemy가 추적을 재개하는지 확인한다.
