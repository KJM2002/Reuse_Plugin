# JMRecon 아키텍처

## 책임 범위

`JMReconRuntime`은 Interactor별로 하나의 로컬 플레이어 정찰 세션을 소유합니다. 진입, Listen, Peek, 선택적 Illuminate, 종료, 취소, 예약, Timer 보호 및 중앙화된 정리를 담당합니다.

입력 Mapping, 플레이어 클래스, 카메라 구현, UI, 손전등, AI Hearing 또는 문 이동은 소유하지 않습니다. 호스트는 카메라, 조명 및 소음 Delegate를 소비합니다. Target Actor 또는 그 ActorComponent는 `IJMReconTarget`을 구현하여 접근을 검증하고 자체 임시 Peek Pose를 소유할 수 있습니다.

## 모듈 및 의존성

- `JMReconRuntime`: `Core`, `CoreUObject`, `Engine`, `DeveloperSettings`에 의존하며 다른 JM 플러그인에는 의존하지 않습니다.
- `JMReconEditor`: 선택한 컴포넌트의 시각화와 검증을 지원하며 에디터 전용입니다.
- `JMReconTests`: 에디터 자동화 테스트 모듈이며 에디터 전용입니다.

JMDoor, JMInteraction 및 JMGameplayEvent가 없어도 핵심 기능을 사용할 수 있습니다. 상호작용 Trace는 `UJMReconTargetComponent`를 `TryStartRecon`에 전달합니다. 선택적 프로젝트 Bridge는 Delegate를 구독하거나 Target Interface를 구현합니다.

`JMReconGameplayIntegration`은 JMInteraction과 함께 사용하는 소비자 측 Bridge입니다. Interaction의 기존 Focus를 재사용하고 입력·카메라·플레이어 상태를 관리하지만, 이 모듈은 해당 Integration을 참조하지 않습니다.

## 상태 및 수명

```text
Idle -> Entering -> InitialObservationMode(Listen 또는 Peek) -> Exiting -> Idle
                                └ Illuminate 플래그 (Peek에서만 사용)
```

Interactor 컴포넌트는 하나의 `FJMReconSession`을 소유합니다. Target 컴포넌트는 세션 GUID 예약만 소유합니다. Target 계약 검색은 Actor를 먼저 확인한 뒤 ActorComponent를 확인하며, Begin/End에는 세션 시작 때 선택한 같은 Adapter를 사용합니다. 세션 내부 참조는 Weak Reference입니다. 모든 지연 전환은 GUID를 캡처하고, 상태를 변경하기 전에 GUID와 예상 상태를 함께 검증합니다.

모든 종료 경로는 `EndActiveReconSession`을 호출합니다. 이 함수는 Timer를 해제하고, 현재 세션의 Sound Mix만 제거하며, Illuminate를 끄고, Target이 소유한 Peek Pose를 종료하고, 예약을 해제하고, 카메라 복원을 요청하고, Weak Reference를 정리한 뒤 Idle 상태로 돌아갑니다. 이 경로는 멱등성을 보장합니다.

## 데이터 및 에셋

Gameplay 값은 `UJMReconDefinition`에 저장됩니다. Project Settings에는 선택적 Soft Default Definition, 기본 Camera Blend 값 및 Debug 활성화 설정만 있습니다. 에셋이 지정되지 않으면 안전한 CDO 프리셋을 사용합니다. `/Game` 경로나 호스트 에셋/클래스에 대한 Hard Reference는 없습니다.

## 네트워크 및 저장

버전 1은 명시적으로 로컬 싱글플레이어 전용이며 Replication과 영속 저장을 지원하지 않습니다. 세션 GUID와 컴포넌트 소유권을 사용하여 전역 플레이어 또는 Singleton을 가정하지 않으므로, 향후 Authority 계층이 동일한 요청을 감쌀 수 있습니다.

## 실패 시 동작

Public 요청은 일관된 사유를 담은 `FJMReconRequestResult`를 반환합니다. 유효하지 않거나 중복되거나 지원되지 않거나 경합이 발생한 요청은 Timer를 할당하거나 Delegate를 바인딩하지 않습니다. 선택적 에셋이 누락되어도 안전하게 기능이 축소됩니다. Target 파괴와 컴포넌트 `EndPlay`는 동일한 정리 경로를 사용합니다.
