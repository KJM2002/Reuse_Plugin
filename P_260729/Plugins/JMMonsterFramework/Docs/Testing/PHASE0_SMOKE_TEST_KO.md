---
title: "JMMonsterFramework Phase 0 Smoke Test"
status: Current
authority: Guide
scope: "Manual verification in Level_TestAI"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
---

# Phase 0 Smoke Test

## 자동 검사

Automation 창에서 `JM.MonsterFramework.Phase0.SimpleEnemyDefaults`를 실행한다.

## Level_TestAI 수동 검사

1. `Level_TestAI`에 NavMesh Bounds Volume을 준비하고 `P` 키로 녹색 NavMesh를 확인한다.
2. `BP_SimpleEnemy`를 NavMesh 위에 배치한다.
3. PIE를 실행한다.
4. World Outliner에서 Enemy와 `ASimpleEnemyAIController` 인스턴스가 존재하는지 확인한다.
5. Enemy의 `Controller`가 해당 AIController인지 확인한다.
6. CharacterMovement가 활성 상태이고 Enemy가 바닥 위에 정상적으로 서 있는지 확인한다.
7. Output Log와 Message Log에 이번 기능에서 발생한 Error 또는 Warning이 없는지 확인한다.

Enemy는 의도대로 아무 행동도 하지 않는다.
