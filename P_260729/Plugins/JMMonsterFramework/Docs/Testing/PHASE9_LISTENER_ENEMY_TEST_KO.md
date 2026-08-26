---
title: "JMMonsterFramework Phase 9 Listener Enemy Test"
status: Current
authority: Guide
scope: "Listener actual Hearing runtime path and PIE gameplay verification"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE8_MEMORY_REFACTOR_TEST_KO.md"
---

# Phase 9 Listener Enemy Test

## 자동 검사

`Tools → Test Automation`에서 다음을 실행한다.

- `JM.MonsterFramework.Phase9.BuildAndValidateListenerAssets`
- `JM.MonsterFramework.Phase9.ListenerRuntimePath`
- 전체 `JM.MonsterFramework`

`ListenerRuntimePath`는 `ApplyHearingState`를 직접 호출하지 않는다. 실제
`BP_ListenerEnemy`, 실제 BP Controller, 실제 Player Blueprint와 AI System을 생성하고
다음 경로를 사용한다.

```text
Report Noise Event
→ UAISense_Hearing
→ UAIPerceptionSystem
→ Listener UAIPerceptionComponent
→ OnTargetPerceptionUpdated
→ EnemyMemory
→ Listener StateTree
```

자동 검사는 실제 Possession, Hearing 활성화와 2500uu 직렬화 값, Listener StateTree 실행,
Patrol 중 Sight 비활성화, 시야 정면의 Player도 Noise 전에는 Target으로 저장하지 않는 상태, Noise A/B 중 최신 위치 보관,
경로 없는 조사 실패 후 Patrol 복귀를 확인한다. 전체 검사는 기존 Predictive, Live Grace,
Attack, Patrol 회귀도 함께 확인한다.

## PIE 준비

1. `Level_TestAI`의 NavMesh 위에 `/JMMonsterFramework/Blueprints/BP_ListenerEnemy`를 배치한다.
2. 먼저 Listener와 Player 사이에 Visibility를 차단하는 벽을 둔다.
3. Player의 Q 입력이 실제 `Report Noise Event`를 호출하는지 확인한다.
4. PIE 중 AI Debugger 또는 StateTree Debugger로 Listener Controller와 활성 State를 선택한다.

## 시나리오 A — 벽 뒤 Noise

1. Player를 벽 뒤 2500uu 안에 둔다.
2. Q를 누른다.
3. 다음 로그를 확인한다.

```text
[RAW PERCEPTION] ... Sense=Hearing Success=1 Strength=...
[JM HEARING ACCEPTED] ... Location=... State=Patrol
```

4. `EnemyMemory.LastHeardLocation`이 실제 Player Noise 위치인지 확인한다.
5. StateTree가 `Patrol → InvestigateSound`로 전환하고 해당 위치로 이동하는지 확인한다.

## 시나리오 B — Noise 없음

1. Q를 누르지 않은 채 Player를 벽 뒤에서 Listener 정면의 탁 트인 시야로 이동시킨다.
2. Listener가 Patrol은 계속해도 Player를 발견하거나 Player 쪽으로 직접 이동하지 않는지 확인한다.
3. `TargetActor=None`, `bCanSeeTarget=false`, `bHasHeardSound=false`인지 확인한다.

## 시나리오 C — 조사 중 Sight 획득

1. 벽 뒤에서 Noise를 내어 `InvestigateSound`를 시작한다.
2. 이때 Sight가 활성화되는지 확인한 뒤 Player가 벽 밖으로 나와 실제 시야에 들어간다.
3. 공격 범위 밖이면 `Chase`, 안이면 `Attack`이 즉시 우선하는지 확인한다.

## 시나리오 D — 조사 실패

1. Noise를 발생시킨 뒤 Player는 다른 곳으로 이동한다.
2. Listener가 기억한 Sound Location까지 조사한다.
3. 아무것도 발견하지 못하면 `Patrol`로 복귀하고 Sight가 다시 비활성화되는지 확인한다.

## 시나리오 E — 반복 Noise

1. Noise A로 `InvestigateSound`를 시작한다.
2. 이동 중 다른 위치에서 Noise B를 발생시킨다.
3. 로그에서 두 Noise가 Accepted됐는지 확인한다.
4. Listener가 최신 Noise B 위치로 목적지를 바꾸는지 확인한다.
5. `[JM HEARING REDIRECT] ... State=InvestigateSound` 로그를 확인한다.

## PASS 기준

- 실제 Listener BP가 실제 Listener BP Controller에 Possess된다.
- Hearing이 2500uu로 활성화되고 Listener StateTree가 실행된다.
- Patrol 중 Sight가 비활성화되어 Noise가 없으면 눈앞의 Player도 먼저 발견하지 않는다.
- Sound Location으로 NavMesh 이동하고 미발견 시 Patrol로 복귀한다.
- 실제 Hearing 조사 중에만 Sight가 활성화되고 실제 Sight 획득이 Chase/Attack을 우선시킨다.
- 조사 실패 또는 Search 종료로 Patrol에 복귀하면 Sight가 다시 비활성화된다.
- 반복 Noise는 최신 Accepted 위치로 이동 목적지를 갱신한다.
- 전체 자동화 10개가 PASS하고 테스트 Event에 Warning/Error가 없다.
- PIE 반복에서 StateTree 고착과 Warning/Error가 없다.
