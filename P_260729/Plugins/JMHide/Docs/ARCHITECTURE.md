---
title: "JMHide 아키텍처"
status: ReviewRequired
authority: Canonical
scope: "Plugin: JMHide"
classified_on: 2026-08-19
owners:
  - "JMHide Maintainers"
review_reason: "2026-08-19 전체 감사 이후 문서 구조만 정비했으며 모든 세부를 현재 코드와 재대조하지 않음"
---

# JMHide 아키텍처

## Phase 0 결정

1. `UJMHideInteractorComponent`만 `FJMHideSession`을 소유하고 Phase를 변경한다. `UJMHideSpotComponent`는 예약과 점유만 소유한다.
2. Participant 계약은 `UJMHideParticipantDriverComponent`다. 기본 `UJMHideCharacterParticipantComponent`는 `ACharacter`, `UCharacterMovementComponent`, Capsule, `APlayerController`와 엔진 `ACameraActor`만 지원한다. 프로젝트 Character/Camera 클래스는 검색하거나 Cast하지 않는다. 다른 Pawn과 커스텀 카메라는 Driver를 파생 구현해야 한다.
3. 한 Scene Component의 Transform owner는 하나다. Core의 `UJMHideSimplePanelMechanismComponent`가 등록한 Panel은 JMDoor Movement 대상일 수 없다. JMDoor 사용 시 별도 `JMHideDoorIntegration` Adapter만 JMDoor Command API를 호출한다.

## 계층과 의존성

```text
Host Input / UI
        |
JMHideInteractionIntegration ---> JMInteraction
        |
        v
JMHideRuntime (다른 JM 플러그인 의존 없음)
        ^
        |
JMHideDoorIntegration -----------> JMDoorRuntime
```

Core는 Enhanced Input, HUD/WBP, JMInteraction, JMDoor, JMGameplayEvent를 소유하지 않는다. 입력은 호스트가 `IsHidden()`에 따라 기존 Interaction 또는 `TryExitCurrentHideSpot()`으로 분기한다. Exit Prompt는 Core Delegate로 제공한다.

## 수명과 상태

Interactor당 활성 Session은 최대 하나다. Spot은 Session GUID와 Actor를 이용해 예약/점유 원자성을 보장한다. Participant와 Mechanism 완료는 Session GUID, 예상 Operation, 예상 Phase를 모두 검사한 뒤에만 상태를 변경한다. Cleanup은 멱등이며 자신이 변경한 Participant 상태만 조건부 복원한다.

```text
Reserving -> PreparingEnter -> Opening -> Entering -> ClosingAfterEnter -> Hidden
Hidden -> PreparingExit -> OpeningForExit -> Exiting -> ClosingAfterExit -> CleaningUp
```

진입 실패는 Panel 복원, Participant 복원, 예약 해제로 rollback한다. Exit 지점이 모두 막히면 Hidden/Occupied 상태를 유지한다. 진입 중 Cancel은 진입 전 상태로, Exit 중 Cancel은 Hidden 상태로 복귀한다. Hidden에서 Cancel은 상태를 유지하며 `TryExit` 또는 `ForceExit`을 요구한다.

## 비동기 계약

Driver와 Mechanism은 `StartOperation(SessionId, Operation, Context)`를 받고 완료 Delegate에 SessionId, Operation, 성공 여부, 실패 코드를 전달한다. 즉시 완료 구현도 같은 완료 경로를 사용한다. 오래된 Callback은 무시된다.

## 설정 Snapshot

세션 생성 시 C++/Project Settings → Definition → Spot Instance → Request 순으로 한 번 Resolve하여 `FJMResolvedHideConfig`에 저장한다. 진행 중 원본 설정 변경은 현재 Session에 반영되지 않는다.

## 네트워크와 저장

1.0은 로컬 싱글플레이 전용이다. Replication과 영속 Save는 제공하지 않는다. Session GUID와 명시적 계약은 향후 서버 권한 계층으로 감쌀 수 있게 유지한다.
