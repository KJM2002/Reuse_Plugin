---
title: "설치와 제작 흐름"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMDoor"
classified_on: 2026-08-19
owners:
  - "JMDoor Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 설치와 제작 흐름

> Sliding doors in 1.6 use `DoorLeafMesh` as panel A and `DoorLeafMeshB` as panel B. Configure `DoorAOpenOffset`/`DoorBOpenOffset` in actor-local space and choose A, B, or Both with `SlideDoorOpenMode`. Leave panel B's static mesh unset to retain a one-panel setup.

## 설치

1. Unreal Editor를 종료합니다.
2. `JMDoor` 폴더 전체를 `<Project>/Plugins/JMDoor`로 복사합니다.
3. `Binaries`와 `Intermediate`가 포함되어 있다면 삭제합니다.
4. `.uproject`에서 프로젝트 파일을 재생성합니다.
5. Editor Development 타깃을 빌드합니다.
6. Plugin 창에서 JM Door System을 활성화합니다.

필수 JM 플러그인은 없습니다. Engine의 GameplayTags와 DeveloperSettings 모듈만 사용합니다.

## 회전문

1. `AJMRotatingDoorActor` Blueprint 자식을 만듭니다.
2. Frame/DoorLeaf/Lock Mesh를 지정합니다.
3. `MovementRoot`를 경첩 위치에 놓고 DoorLeaf 상대 위치를 조정합니다.
4. `RotatingMovement.OpenAngle`과 축을 설정합니다.
5. `UJMDoorConfigData`를 만들고 DoorComponent.Config에 지정합니다.

## 미닫이문

1. `AJMSlidingDoorActor` Blueprint 자식을 만듭니다.
2. Mesh와 Config를 지정합니다.
3. `SlidingMovement.LocalOpenOffset`을 설정합니다.

## 기본 예제

- `/JMDoor/Demo/Blueprints/BP_JMRotatingDoorExample`
- `/JMDoor/Demo/Blueprints/BP_JMSlidingDoorExample`
- `/JMDoor/Demo/Data/DA_JMDoorDemoConfig`
- `/JMDoor/Demo/Maps/L_JMDoorDemo`

예제는 Engine 기본 Cube를 사용하므로 게임용 메쉬로 교체해야 합니다.

## 상호작용 시스템 연결

JMDoor는 특정 Trace/Prompt 시스템에 의존하지 않습니다. 기존 Interaction의 Complete 이벤트에서 `Execute Door Command On Object(Toggle)`를 호출할 수 있습니다.

기존 `JMInteractionComponent`와 Inventory의 Old Key 흐름을 그대로 쓰려면 `JMDoorGameplayIntegration`을 함께 설치합니다. 기존 Character에는 `JMDoorInventoryAgentComponent`만 추가하면 되고, 문 Actor의 상호작용 어댑터는 자동 등록됩니다.
