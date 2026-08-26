---
title: "JMMonsterFramework Phase 4 Search Test"
status: Current
authority: Guide
scope: "Finite Search verification in Level_TestAI"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
---

# Phase 4 Search Test

## 자동 검사

Automation 창에서 `JM.MonsterFramework.Phase4.BuildAndValidateStateTree`를 실행한다. Search Task가 하나인지, 제한 시간이 양수인지, 재감지와 완료 전이가 모두 존재하는지 검사한다.

## Level_TestAI 수동 검사

1. 코너와 주변 NavMesh가 있는 `Level_TestAI`에 `BP_SimpleEnemy`를 배치한다.
2. Enemy에게 발견된 뒤 코너 뒤로 숨는다.
3. Enemy가 `LastSeenLocation`까지 이동하는지 확인한다.
4. 도착 직후 제자리 Search를 시작해 약 4초 동안 한 바퀴 회전하는지 확인한다.
5. 계속 숨은 상태라면 Search가 끝나고 Patrol로 복귀하는지 확인한다.
6. 다시 반복하고 Search 도중 Enemy 시야에 나타난다.
7. 회전을 즉시 끝내고 Chase로 전환해 Player를 추적하는지 확인한다.

Search가 4초를 넘어 계속되거나, Search 중 Player를 봐도 Chase하지 않으면 실패다.
