---
title: "JMMonsterFramework Phase 8 Memory Refactor Test"
status: Current
authority: Guide
scope: "EnemyMemory ownership and runtime perception regression verification"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE7_BASIC_HEARING_TEST_KO.md"
---

# Phase 8 Memory Refactor Test

## 자동 검사

Automation 창에서 다음을 실행한다.

- `JM.MonsterFramework.Phase8.RuntimeMemoryPath`
- 전체 `JM.MonsterFramework` 회귀 테스트

`RuntimeMemoryPath`는 Setter나 Perception 처리 함수를 직접 호출하지 않는다. 실제
`BP_SimpleEnemy`, 설정된 `BP_SimpleEnemyAIController`, `BP_FirstPersonCharacter`,
GameInstance, GameMode, AI System을 생성한 뒤 다음 엔진 경로를 검증한다.

```text
Report Noise Event
→ UAISense_Hearing
→ UAIPerceptionSystem
→ UAIPerceptionComponent
→ OnTargetPerceptionUpdated
→ EnemyMemory Hearing 갱신

Player Sight Source
→ UAISense_Sight
→ UAIPerceptionComponent
→ OnTargetPerceptionUpdated
→ EnemyMemory Sight 갱신
```

또한 Predictive/Live Grace Enemy와 Controller Blueprint 네 개를 다시 컴파일하고,
Controller Blueprint에 이전 `TargetActor`, `bCanSeeTarget`, `LastHeardLocation` 속성이
남지 않았으며 단일 `EnemyMemory` 속성이 존재하는지 검사한다. Phase 7 StateTree 에셋
검사를 함께 실행하면 두 StateTree가 각각 재컴파일되어 기존 정책 분리가 유지된다.

## PIE 절차

1. Predictive 또는 Live Grace Enemy를 NavMesh 위에 배치한다.
2. Player를 시야 안에 두고 `EnemyMemory.TargetActor`, `bCanSeeTarget` 갱신과 Chase를 확인한다.
3. 벽 뒤로 이동해 선택한 프리셋의 Tracking, Investigate, Search 흐름을 확인한다.
4. Sight가 차단된 상태에서 실제 Q 입력의 `Report Noise Event`를 발생시킨다.
5. `EnemyMemory.LastHeardLocation`, `bHasHeardSound` 갱신과 `InvestigateSound` 이동을 확인한다.
6. 조사 완료 후 Patrol 복귀를 확인한다.
7. 같은 사이클을 반복하고 StateTree 고착과 Warning/Error가 없는지 확인한다.

## PASS 기준

- Perception 처리 함수를 직접 호출하지 않은 런타임 통합 검사가 통과한다.
- Sight와 Hearing 사실이 단일 `EnemyMemory`에 기록된다.
- Memory는 행동을 결정하지 않고 StateTree가 읽어서 기존 행동을 수행한다.
- Predictive와 Live Grace 정책이 각각 기존 StateTree에 유지된다.
- Enemy/Controller Blueprint에 제거된 Controller 속성 참조가 없다.
- 새 Gameplay 행동이나 미래용 Memory 필드가 추가되지 않는다.
- 전체 자동화 검사와 PIE에서 Warning/Error가 없다.
