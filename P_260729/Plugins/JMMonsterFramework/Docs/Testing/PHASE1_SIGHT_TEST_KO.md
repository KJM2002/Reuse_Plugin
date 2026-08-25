---
title: "JMMonsterFramework Phase 1 Sight Test"
status: Current
authority: Guide
scope: "Repeated player sight verification in Level_TestAI"
last_verified: 2026-08-25
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
---

# Phase 1 Sight Test

## 자동 검사

Automation 창에서 `JM.MonsterFramework.Phase1.SightStateTransitions`를 실행한다. 한 번의 테스트에서 Detected/Lost 상태 전환을 20회 반복하며 중복 자극, 다른 Actor의 Lost, null 입력도 검사한다.

## Level_TestAI 수동 검사

1. `BP_SimpleEnemy`를 바닥에 배치하고 회전시켜 전방을 테스트 공간으로 향하게 한다.
2. Player와 Enemy 사이에 Visibility 채널을 막는 벽을 준비한다.
3. PIE를 실행하고 Enemy 앞에 나타난다.
4. Output Log의 `LogJMMonsterFramework: Detected`와 AIController의 `TargetActor`, `bCanSeeTarget=true`를 확인한다.
5. 벽 뒤로 이동한다.
6. `LogJMMonsterFramework: Lost`, `TargetActor=None`, `bCanSeeTarget=false`를 확인한다.
7. 3~6을 최소 20회 반복한다.

순서는 매번 `Detected → Lost → Detected → Lost`여야 한다. 한 번이라도 누락되거나 중복 전환이 보이면 StateTree 단계로 진행하지 않고 Sight 설정과 벽의 Visibility Collision부터 수정한다.
