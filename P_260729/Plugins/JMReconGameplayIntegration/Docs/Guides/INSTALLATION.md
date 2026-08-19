---
title: "설치 및 설정"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMReconGameplayIntegration"
classified_on: 2026-08-19
owners:
  - "JMReconGameplayIntegration Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 설치 및 설정

## 설치

프로젝트의 `Plugins` 폴더에 다음 폴더를 함께 복사하고 플러그인을 활성화한 뒤 C++ 프로젝트 파일을 재생성하여 빌드합니다.

- `JMGameplayEvent`
- `JMInteraction`
- `JMRecon`
- `JMReconGameplayIntegration`

## 호스트 설정

플레이어 Pawn에 `JMInteractionComponent`와 `JMReconInteractorComponent`를 추가합니다. 자동 Bridge가 기본 활성화되어 있으므로 별도의 `JMReconPlayerBridgeComponent`, 입력 이벤트 또는 카메라 Delegate 연결은 필요 없습니다.

정찰 가능한 Actor는 기존 JMInteraction 탐색 대상이어야 하며 `JMReconTargetComponent`를 하나 가져야 합니다. 컴포넌트 자체의 위치와 회전을 정찰 기준점에 맞춥니다. 기본 상대 Transform이 맞지 않는 대상만 고급 항목을 조정합니다.

## 설정 변경

**Project Settings > Plugins > JM Recon Gameplay Integration**에서 자동 Bridge, 입력, 카메라, 플레이어 정렬, 이동 잠금 및 키를 변경합니다.

기본값은 `E` 상호작용 표시, `R` 시작/종료, `F` Hold 손전등, `Esc` 정상 종료, `Q` 비상 취소입니다. UI에는 실제 설정 키 이름이 표시됩니다. 카메라 FOV·충돌 반경, 회전 보간, 손전등 밝기·색·원뿔·Fade 및 선택적 클릭음도 이 화면에서 한 번만 설정합니다. Target Details에는 이 값들을 반복 입력하지 않습니다.

`ReconPromptWidgetClass`를 비우면 Native 텍스트 UI가 사용됩니다. 프로젝트 전용 WBP로 교체하려면 `UJMReconPromptWidgetBase`를 부모로 만들고 Soft Class로 지정합니다.

호스트가 직접 입력과 카메라를 관리하려면 `bAutoBindInput`과 `bAutoManageCamera`를 끄고 JMRecon Delegate/API를 기존 흐름에 연결합니다. 자동 Bridge 자체가 필요 없으면 `bAutoAddPlayerBridge`도 끕니다. 기본 구현은 기존 Blueprint `E` 입력을 침범하지 않는 런타임 Key Binding이며, Enhanced Input Mapping Context를 강제로 추가하거나 `/Game` 에셋을 참조하지 않습니다.
