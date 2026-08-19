---
title: "JMRecon"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMRecon"
classified_on: 2026-08-19
owners:
  - "JMRecon Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMRecon

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JMRecon 아키텍처](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [변경 이력](CHANGELOG.md) | `ReviewRequired` |
| Guides | [설치 및 이식성](Guides/INSTALLATION.md) | `ReviewRequired` |


Listen, 직접 Peek 관찰 및 선택적 Illuminate 기능을 제공하는 재사용형 Unreal Engine 5.7 런타임 정찰 플러그인입니다.

## 설치

전체 `JMRecon` 폴더를 프로젝트의 `Plugins` 폴더에 복사하고 **JM Recon**을 활성화한 다음, 프로젝트 파일을 다시 생성하고 빌드합니다. 필수로 요구되는 다른 JM 플러그인은 없습니다. `JMReconEditor`와 `JMReconTests`는 에디터 타깃에서만 로드됩니다.

## 1분 설정

1. 문, 사물함, 환기구, 벽 개구부 또는 창문 Blueprint에 `JMReconTargetComponent`를 추가합니다.
2. 해당 컴포넌트를 정찰 기준 위치로 이동하고 회전합니다.
3. `DA_JMRecon_Default` 또는 다른 `JMReconDefinition`을 지정합니다. Project Settings는 기본적으로 플러그인에 포함된 프리셋을 가리키며, 에셋이 없어도 안전한 C++ 기본값으로 동작합니다.
4. 플레이어에 `JMReconInteractorComponent`를 추가합니다.
5. 호스트의 상호작용 또는 입력 흐름에서 `TryStartRecon(Target)`, `StartListen`, `StartPeek`, `SetIlluminate`, `CancelRecon`, `FinishRecon` 중 필요한 함수를 호출합니다.
6. 카메라 코드를 `OnCameraTransformRequested`와 `OnCameraRestoreRequested`에 바인딩합니다. 손전등과 유사한 기능은 `OnIlluminateRequested`에 바인딩합니다.

Target 컴포넌트는 플레이어, Listen 카메라, Peek 카메라 Transform을 직접 제공합니다. 고급 Target은 Anchor Override를 설정할 수 있습니다.

## 문 및 기타 Target Adapter

Target Actor에 검증이나 임시 Pose가 필요하면 `IJMReconTarget`을 구현합니다. Pose의 소유권은 Target에 있습니다.

- `CanStartRecon`은 파손, 이동 중, 열림, 차단 또는 미지원 상태의 Target을 사유와 함께 거부합니다.
- `BeginPeekPose(SessionId, OpenFraction)`는 정규화된 임시 Pose를 적용합니다.
- `EndPeekPose(SessionId)`는 해당 세션이 소유한 Pose만 제거합니다.
- 외부에서 영구 상태가 변경되면 Pose를 무효화하고 호스트 Bridge를 통해 `CancelRecon`을 호출해야 합니다.

JMRecon은 문의 Mesh Transform을 저장하거나 복원하지 않으며 JMDoor로 Cast하지 않습니다.

## 선택적 연동

- JMInteraction: Focus 중인 Actor의 `JMReconTargetComponent`를 `TryStartRecon`에 전달합니다. `JMReconGameplayIntegration`을 함께 활성화하면 이 전달, 기본 입력, 카메라 및 플레이어 상태 복원이 자동 처리되어 Blueprint 바인딩이 필요 없습니다.
- JMGameplayEvent: 상태/소음 Delegate를 프로젝트가 소유하는 Gameplay Message로 변환합니다.
- JMDoor: `JMDoorReconIntegration`을 활성화하면 문 Actor의 `JMDoorComponent`와 `JMReconTargetComponent` 조합을 자동 인식하는 Component Adapter가 붙습니다.

연동 플러그인이 없어도 런타임 상태, 예약, Transform, Delegate, 검증 및 테스트 기능은 정상 동작합니다.

## 최소 설정 모드

`JMInteraction`을 이미 쓰는 프로젝트에서는 플레이어에 두 Interactor 컴포넌트만 두고 Target 컴포넌트의 기준 위치를 맞추면 됩니다. `Recon Definition`은 비워 두어 전역 기본값을 사용할 수 있으며, 모드·거리·세부 카메라 Transform은 필요한 Target에서만 고급 항목으로 덮어씁니다.

## 성능 및 안전성

두 컴포넌트 모두 Tick이 비활성화되어 있습니다. 처리는 요청, 상태 변경, Delegate 및 일회성 Timer가 발생할 때만 수행됩니다. 지연 전환 시 세션 GUID와 예상 상태를 검증합니다. 정리 로직은 중앙화되어 있으며 반복 호출해도 안전합니다.
