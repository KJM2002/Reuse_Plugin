---
title: "JMHide"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMHide"
classified_on: 2026-08-19
owners:
  - "JMHide Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMHide

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JMHide 아키텍처](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |
| Guides | [JMHide 설치](Guides/INSTALLATION.md) | `ReviewRequired` |
| Reference | [Cancel / ForceExit 정책](Reference/CANCEL_POLICY.md) | `ReviewRequired` |


UE 5.7용 재사용 은신 Runtime 플러그인입니다. `JMHide` 폴더만 복사해 사용할 수 있으며 다른 JM 플러그인은 필수가 아닙니다.

## 빠른 설정

1. Player Character에 `JMHideInteractorComponent`와 `JMHideCharacterParticipantComponent`를 추가합니다.
2. 은신 Actor에 `JMHideSpotComponent`를 추가합니다.
3. 같은 Actor에 Entry, Occupant, Camera, PrimaryExit 역할의 `JMHideAnchorComponent`를 배치합니다.
4. 폐쇄형 은신처는 `JMHideSimplePanelMechanismComponent` 또는 별도 JMDoor Adapter 하나를 추가합니다.
5. 호스트 입력에서 숨은 상태면 `TryExitCurrentHideSpot`, 아니면 기존 Interaction 입력을 호출합니다.

기본 Character Driver는 엔진 `ACharacter`만 지원합니다. 커스텀 Pawn/Camera 시스템은 `UJMHideParticipantDriverComponent` 파생 Driver를 제공해야 합니다.
