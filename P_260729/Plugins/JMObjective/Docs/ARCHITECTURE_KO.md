# JMObjective 아키텍처

## 책임 분리

```text
기능 플러그인
  └─ JMGameplayEvent 발행
       └─ UJMObjectiveSubsystem
            ├─ 개별 Objective 상태/구독
            └─ UJMObjectiveFlowSubsystem
                 └─ 현재 Step 자동 전환

Local Player
  └─ UJMObjectiveUISubsystem
       └─ UJMObjectiveWidgetBase
```

`UJMObjectiveDefinition`은 목표 조건 하나만 가진다. `UJMObjectiveFlowDefinition`이 순서를 소유하므로 개별 Definition은 여러 Flow에서 재사용할 수 있다.

## 수명

- Objective/Flow Subsystem: `UGameInstanceSubsystem`. 같은 GameInstance의 레벨 전환에서도 상태를 유지한다.
- UI Subsystem: `ULocalPlayerSubsystem`. 로컬 플레이어마다 위젯 하나를 관리하며 PlayerController가 바뀌면 다시 생성한다.
- Data Asset: 정적 설정만 저장하며 CurrentCount 같은 런타임 값을 저장하지 않는다.
- PIE: PIE GameInstance마다 상태와 이벤트 구독이 분리된다.

## Flow 시작

`StartObjectiveFlow`는 Definition을 검증하고 모든 Objective를 자동 활성화 없이 등록한다. 이미 같은 ID가 같은 Definition으로 등록되어 있으면 재사용하고 초기화한다. 다른 Definition이 같은 Objective ID를 사용하거나 다른 Active Flow가 같은 Objective를 사용 중이면 시작을 거부한다.

첫 Step만 Active로 만든 뒤 Started Delegate와 `Event.ObjectiveFlow.Started`를 발행한다. 같은 Flow의 중복 시작은 `false`를 반환한다.

## 자동 전환

Flow Subsystem은 Objective Subsystem의 Completed/Failed Delegate를 C++에서 한 번만 구독한다. 완료 ID가 Active Flow의 `CurrentObjectiveId`와 같을 때만 다음 Step을 즉시 활성화한다. 마지막 Step이면 Flow를 Completed로 만든다.

Objective가 실패했을 때:

- `bStopOnObjectiveFailure=true`: Flow를 Failed로 종료한다.
- `false`: 실패한 Step을 건너뛰고 다음 Step을 즉시 활성화한다.

Flow 전환은 UI Delay와 무관하다. UI 완료 표시 시간은 화면 연출만 지연한다.

## 이벤트와 의존성

Flow Delegate: Started, StepChanged, Completed, Failed, Stopped.

Gameplay Event: `Event.ObjectiveFlow.Started`, `StepChanged`, `Completed`, `Failed`, `Stopped`.

Flow Payload는 Flow ID, 상태, 현재 Step, 현재 Objective ID, 전체 Step 수를 제공한다. JMObjective의 허용 의존성은 Core, CoreUObject, Engine, GameplayTags, JMGameplayEvent, UMG, DeveloperSettings뿐이다.

`JMGameplayEvent`는 Publish 전에 구독자 스냅샷을 만들고 콜백 실행 직전에 구독 존재 여부를 다시 확인한다. 따라서 Objective 완료 콜백 도중 현재 구독을 해제하고 다음 Objective를 구독해도 현재 이벤트가 새 Objective에 중복 전달되지 않는다.

