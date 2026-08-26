---
title: "JMMonsterFramework Phase 7 Basic Hearing Test"
status: Current
authority: Guide
scope: "Basic Hearing verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE6_BASIC_ATTACK_TEST_KO.md"
---

# Phase 7 Basic Hearing Test

## 자동 검사

Automation 창에서 다음을 실행한다.

- `JM.MonsterFramework.Phase7.HearingState`
- `JM.MonsterFramework.Phase7.BuildAndValidatePredictiveStateTree`
- `JM.MonsterFramework.Phase7.BuildAndValidateLiveGraceAssets`
- 전체 `JM.MonsterFramework` 회귀 테스트

`HearingState`는 실제 `BP_SimpleEnemyAIController`를 Spawn/Possess하여 기존 Blueprint의
Sight-only 직렬화 이후에도 런타임 Listener에 Hearing이 복구되는지 확인한다.

## PIE 준비

Player 또는 테스트 Actor에서 `Report Noise Event`를 호출한다.

- Noise Location: 발생 Actor의 현재 위치
- Loudness: `1.0`
- Max Range: `0.0`으로 두어 Enemy의 Hearing Range 1500uu 사용
- Instigator: 소리를 발생시킨 Actor

## PIE 절차

1. Player가 Enemy Sight 밖이지만 1500uu Hearing 안에 있도록 벽 뒤에 배치한다.
2. Noise를 발생시켜 `HeardSound` 로그와 `InvestigateSound` 이동을 확인한다.
3. Enemy가 실제 Sound Location까지 이동하고 아무것도 못 찾으면 Patrol로 복귀하는지 확인한다.
4. Noise를 호출하지 않은 상태에서는 Patrol이 유지되는지 확인한다.
5. Sound 조사 중 Player가 시야에 나타나면 거리에 따라 Attack 또는 Chase로 즉시 전환되는지 확인한다.
6. 이후 Sight를 잃어 Predictive/Live Grace 프리셋별 기존 Tracking 흐름을 확인한다.
7. Sound 조사와 Sight 획득을 반복해 상태 고착이나 이동 요청 경쟁이 없는지 확인한다.

## PASS 기준

- 성공한 유효 Noise에만 반응한다.
- 기억한 Sound Location으로 이동한다.
- Sound 조사 중 Sight가 항상 우선한다.
- 조사 완료 후 Patrol로 복귀한다.
- Target Lost 시 선택된 4.5/4.6 정책이 유지된다.
- 반복 PIE에서 Warning/Error가 없다.
