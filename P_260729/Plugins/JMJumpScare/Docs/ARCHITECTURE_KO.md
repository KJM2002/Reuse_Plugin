---
title: "JMJumpScare 아키텍처"
status: ReviewRequired
authority: Canonical
scope: "Plugin: JMJumpScare"
classified_on: 2026-08-19
owners:
  - "JMJumpScare Maintainers"
review_reason: "2026-08-19 전체 감사 이후 문서 구조만 정비했으며 모든 세부를 현재 코드와 재대조하지 않음"
---

# JMJumpScare 아키텍처

## 구성

- `UJMJumpScareDefinition`: 이미지, 표시 시간, 사운드, 반복 정책
- `AJMJumpScareTrigger`: Overlap 시 실행 요청
- `UJMJumpScareSubsystem`: 한 번에 하나의 실행, Timer, Once 정책, 이벤트
- `UJMJumpScareOverlayWidget`: 화면 전체를 덮는 Hit-Test 불가 `UImage`

## 흐름

```text
PlayJumpScare
→ Definition/Image/Player 검증
→ StartDelay
→ Overlay를 Target Player Screen에 추가
→ Duration
→ Overlay와 Audio 제거
→ Idle
```

Overlay는 `AddToPlayerScreen(ZOrder)`로 대상 플레이어 화면에만 추가된다.
별도 Widget Blueprint를 만들 필요가 없고 게임 입력도 가로채지 않는다.

## 호환 경계

기존 Trigger, Gameplay Event Tag, 상태 조회, Cancel API는 유지한다.
`FJMJumpScarePlayContext`의 과거 3D 필드는 기존 C++ 연결을 위해 남아 있지만 2D 표시에는 사용하지 않는다.
`FJMJumpScareActiveInfo.SpawnedActor`와 이벤트 Payload의 `SpawnedActor`는 항상 null이다.

플러그인은 Local Cosmetic 시스템이며 자동 RPC/Replication은 수행하지 않는다.
