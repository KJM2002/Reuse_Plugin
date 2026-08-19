---
title: "통합 가이드"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMJumpScare"
classified_on: 2026-08-19
owners:
  - "JMJumpScare Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 통합 가이드

## JMGameplayEvent

Started/Impact/Exiting/Finished/Cancelled/Failed를 `UJMGameplayEventListenerComponent` 또는 `UJMGameplayEventSubsystem`으로 구독한다. Interaction Lock, HUD Hide, Objective 진행 등은 이 이벤트에 반응하는 소비자/Bridge가 구현한다. `JMJumpScare` 코어에는 해당 플러그인 의존성을 추가하지 않는다.

Impact는 피해 판정이나 강한 Audio 연동 지점으로, Exiting은 HUD Static·외부 Interaction 복원 준비 지점으로 사용할 수 있다. Payload에서 Phase, Trigger, Target Pawn, Player Controller를 확인할 수 있다.

Door가 열릴 때 실행하려면 원하는 Actor에 `JMJumpScareEventTriggerComponent`를 추가하고 Trigger Event Tag를 `Event.Door.Opened`로 지정한다. Exact 또는 IncludeChildren 매치를 선택할 수 있다. 이 Component는 `JMDoor` 타입을 전혀 참조하지 않는다.

## 특정 프로젝트 Player 연동

Trigger Overlap은 Player-controlled Pawn을 일반 API로 판별한다. 수동 실행에서는 `FJMJumpScarePlayContext.TargetPlayer` 또는 Blueprint 노드의 Target Player를 넘긴다. 게임 Character로 Cast하거나 Camera Component 이름을 하드코딩하지 않는다.

## Save 확장

`AJMJumpScareTrigger::CaptureSaveState`와 `RestoreSaveState`는 안정적인 Gameplay Tag Trigger ID와 Once 상태만 교환한다. 향후 JMSaveSystem Adapter가 이 구조를 직렬화할 수 있다. 활성 Actor, Timer, Subsystem 포인터는 저장하지 않는다.

## Objective 확장

Objective 시스템은 `Event.JumpScare.Finished`와 Payload의 `JumpScareId`를 조건으로 진행도를 갱신할 수 있다. Objective 플러그인을 JMJumpScare에 의존시키거나 별도 Integration 플러그인을 두고 역방향 참조를 만들지 않는다.

## 네트워크

플러그인은 자동 Replication/RPC가 없다. 특정 클라이언트에 보여 주려면 게임의 권한 계층이 Client RPC를 수행하고 해당 클라이언트에서 Target Player를 넘겨 `Play JumpScare`를 호출한다.
