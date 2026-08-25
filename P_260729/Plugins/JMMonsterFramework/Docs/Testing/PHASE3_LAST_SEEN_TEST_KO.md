---
title: "JMMonsterFramework Phase 3 Last Seen Location Test"
status: Current
authority: Guide
scope: "Last observed location investigation verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
---

# Phase 3 Last Seen Location Test

## 자동 검사

- `JM.MonsterFramework.Phase1.SightStateTransitions`: 20회 감지·상실 동안 마지막 관측 위치 보존 검사
- `JM.MonsterFramework.Phase3.BuildAndValidateStateTree`: 3상태 구조, 조사 Task, 재감지·완료 전이 컴파일 검사

## Level_TestAI 수동 검사

1. 코너를 포함한 벽과 그 주변을 덮는 NavMesh를 준비한다.
2. Enemy가 Player를 감지하고 추적하게 한다.
3. Player가 코너 뒤로 완전히 숨는다.
4. AIController의 `TargetActor=None`, `bCanSeeTarget=false`를 확인한다.
5. Enemy가 숨은 Player의 현재 위치를 향해 벽을 뚫지 않고, `LastSeenLocation`까지만 NavMesh 경로로 이동하는지 확인한다.
6. 해당 위치에 도착한 뒤 정지하는지 확인한다.
7. 조사 중 다시 모습을 보이면 즉시 Chase로 복귀하는지 확인한다.

통과 조건은 `Chase → InvestigateLastLocation → Idle`이며, 숨은 Player를 계속 추적하면 실패다.
