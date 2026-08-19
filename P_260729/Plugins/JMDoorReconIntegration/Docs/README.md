---
title: "JMDoorReconIntegration"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMDoorReconIntegration"
classified_on: 2026-08-19
owners:
  - "JMDoorReconIntegration Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMDoorReconIntegration

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JMDoorReconIntegration 아키텍처](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [변경 이력](CHANGELOG.md) | `ReviewRequired` |
| Guides | [설치 및 설정](Guides/INSTALLATION.md) | `ReviewRequired` |


`JMDoor`와 `JMRecon`을 서로 결합하지 않고 연결하는 Runtime Adapter 플러그인입니다. 일반 `E` 문 상호작용, 잠금 해제, 저장 상태와 자동 닫힘 Timer는 그대로 두고 Recon 세션에만 문짝을 약간 엽니다.

## 필수 플러그인

- `JMDoor`
- `JMRecon`

`JMDoorReconIntegration`만 두 기반 플러그인을 참조합니다. 다른 프로젝트로 옮길 때는 세 폴더를 함께 복사합니다.

## 자동 동작

Game/PIE World에서 한 Actor에 `JMDoorComponent`와 `JMReconTargetComponent`가 있으면 `JMDoorReconTargetAdapterComponent`가 자동 추가됩니다. Blueprint Event Graph 연결은 필요 없습니다.

- 이동 중, Locked, Blocked, Jammed, Broken 문은 시작을 거부합니다.
- 회전문과 슬라이딩 문의 실제 Mesh Transform을 세션 시작 시 저장합니다.
- Definition의 `PeekOpenFraction`을 우선하여 세션 전용 Pose로 부드럽게 보간합니다.
- 종료, 취소, Target 파괴, EndPlay 또는 외부 문 상태 변경 시 원래 Transform을 정확히 복원합니다.
- Door 상태, OpenFraction, SaveData와 Timer는 변경하지 않습니다.

## 문 Blueprint 최소 설정

1. 기존 `JMInteraction`/`JMDoor` 구성을 유지합니다.
2. `JMReconTargetComponent` 하나를 추가합니다.
3. 컴포넌트를 플레이어가 설 위치와 바라볼 방향에 배치합니다.

Definition, 문틈 비율, 카메라 제한과 손전등은 전역 기본값으로 즉시 동작합니다.
