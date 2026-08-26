---
title: "JMMonsterFramework Phase 10 Watcher Enemy Test"
status: Current
authority: Guide
scope: "Watcher actual player-camera gaze and visibility runtime verification"
last_verified: 2026-08-26
verified_against: "working-tree"
owners:
  - "JMMonsterFramework"
related:
  - "../README.md"
  - "PHASE9_LISTENER_ENEMY_TEST_KO.md"
---

# Phase 10 Watcher Enemy Test

## 자동 검사

`Tools → Test Automation`에서 다음을 실행한다.

- `JM.MonsterFramework.Phase10.BuildAndValidateWatcherAssets`
- `JM.MonsterFramework.Phase10.WatcherRuntimeGazePath`
- 전체 `JM.MonsterFramework`

`WatcherRuntimeGazePath`는 `bPlayerIsWatchingWatcher`를 직접 설정하지 않는다. 실제 `BP_WatcherEnemy`, 실제 BP Controller, 실제 Player Blueprint와 PlayerController를 생성하고 다음 경로를 검증한다.

```text
PlayerController GetPlayerViewPoint
→ Camera Location / View Rotation
→ 실제 Camera FOV / Viewport 비율의 85% 영역
→ Watcher 눈·상체·몸통·하체 Visibility Trace
→ bPlayerIsWatchingWatcher
→ Watcher StateTree
```

자동 검사는 중앙 시선, 8도와 20도 비껴 보기, 50도 화면 이탈, 0.12초 해제 완충, 5000uu 거리, 실제 Box Collision 벽 차단, 벽 제거 후 재감지, `Look Away → Look Back` 20회 반복을 확인한다. Watcher의 Perception Sight/Hearing이 실제 Possess 후 꺼지고 `WatchedStop ↔ UnwatchedMove`가 전환되는지도 확인한다.

## PIE 준비

1. `Level_TestAI`의 NavMesh 위에 `/JMMonsterFramework/Blueprints/BP_WatcherEnemy`를 배치한다.
2. Watcher의 Mesh가 Player가 실제로 조준할 수 있는 높이와 크기인지 확인한다.
3. Player와 Watcher 사이에 Visibility를 차단하는 벽을 준비한다.
4. PIE에서 `showdebug ai` 또는 StateTree Debugger로 Watcher Controller와 활성 State를 확인한다.

## 시나리오 A — 정면으로 바라봄

1. 벽이 없는 상태에서 화면 중앙에 Watcher를 둔다.
2. `bPlayerIsWatchingWatcher=true`와 `WatchedStop`을 확인한다.
3. Watcher가 즉시 멈추고 Move 요청과 경쟁하지 않는지 확인한다.

기대 로그:

```text
[JM WATCHER GAZE] Enemy=... Watched=1 Screen=1 Visible=1 Blocker=...
```

## 시나리오 B — 시야각 밖

1. Watcher의 모든 표본점이 Camera FOV의 85% 허용 영역을 벗어나도록 충분히 시선을 돌린다.
2. `bPlayerIsWatchingWatcher=false`와 `UnwatchedMove`를 확인한다.
3. Watcher가 NavMesh 위에서 Player를 향해 이동하는지 확인한다.

## 시나리오 C — 벽 차단

1. 카메라는 Watcher 방향을 그대로 향한다.
2. Player와 Watcher 사이로 Visibility를 Blocking하는 벽 뒤에 Watcher를 숨긴다.
3. Angle은 통과해도 `Visible=0`, `Watched=0`인지 확인한다.
4. 벽 너머 Watcher가 정지하지 않고 이동 가능한지 확인한다.

## 시나리오 D — 빠른 반복

1. `정면 → 시선 돌림 → 정면`을 빠르게 최소 20회 반복한다.
2. 매번 `WatchedStop → UnwatchedMove → WatchedStop`이 따라오는지 확인한다.
3. Watcher가 영구 정지하거나 이동 상태에 고착되지 않는지 확인한다.

## PASS 기준

- 실제 Watcher BP가 실제 Watcher BP Controller에 Possess된다.
- AI Sight/Hearing이 Watcher Gaze Trigger로 사용되지 않는다.
- Watcher 일부가 Camera FOV의 85% 허용 영역 안에 있고 벽에 가려지지 않으면 Watched가 된다.
- 5000uu 거리에서도 같은 화면 기준으로 판정하며 별도 최대 거리가 없다.
- 시야각 밖 또는 벽 뒤에서는 Unwatched다.
- Watched는 즉시 이동을 중지하고 Unwatched는 Player를 향해 이동 가능하다.
- 빠른 20회 반복에서 StateTree 고착과 Move 경쟁이 없다.
- 기존 Simple Enemy와 Listener 자동화에 회귀가 없다.
- Warning/Error가 없다.
