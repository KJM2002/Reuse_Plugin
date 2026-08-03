# JMDoor 아키텍처

## Dual sliding-panel model (1.6+)

Sliding doors have independent A/B runtime records in `UJMDoorComponent`. A always resolves its open transform from its closed transform plus the actor-local A offset; B does the same with its B offset. Interaction position is consulted only by the optional nearest-panel selector. Each moving panel performs its own predictive character sweep and obstruction query, then advances its own fraction. The aggregate door state is derived for compatibility with general door consumers.

Version-1 save data is restored into legacy panel A. Version-2 save data records both panel fractions and states. Assets saved before the dual-panel custom version use the original single-panel movement path; an unset static-mesh panel B also selects single-panel behavior.

## 책임과 비책임

JMDoor가 소유하는 것:

- 문 상태와 명령 검증
- 개폐 진행률과 이동 컴포넌트 구동
- 잠금/접근 요구사항
- 문짝 및 잠금장치 내구도
- 장애물 정책, 자동 닫힘, 부분 개방, 조용히/빠르게 열기
- 상태, 접근 거부, 장애물, 내구도, 소음 이벤트
- 저장 가능한 안정 데이터 구조

JMDoor가 소유하지 않는 것:

- 플레이어 입력 탐색 및 프롬프트 UI
- 인벤토리 슬롯과 카드키 구현
- AI Controller/Behavior Tree
- 전역 소음 전파 또는 AI Perception
- SaveGame 파일과 슬롯 관리
- 프로젝트 전용 Character, HUD, GameMode

## 모듈

```text
JMDoorRuntime (Runtime)
├─ Actors
├─ Blueprint
├─ Data
├─ Door
├─ Interfaces
├─ Movement
└─ Settings

JMDoorTests (Editor)
├─ Automation Tests
├─ Functional Test
└─ Sample Asset Commandlet
```

선택 설치형 `JMDoorGameplayIntegration`이 `JMDoorRuntime`, `ItemInspectorRuntime`, `InventorySystem`을 소비합니다. 따라서 JMDoor 코어의 직접 JM 의존성은 계속 0이며, Inventory나 Interaction 없이도 독립 빌드됩니다.

`JMDoorRuntime`은 `Core`, `CoreUObject`, `Engine`, `DeveloperSettings`, `GameplayTags`만 참조합니다. `JMDoorTests`의 Editor/FunctionalTesting 의존성은 Runtime 및 Shipping 타깃에 들어가지 않습니다.

## 런타임 흐름

```text
Player/AI/Host System
→ IJMDoorUsableInterface 또는 Blueprint Library
→ UJMDoorComponent::ExecuteCommand
→ 접근 계약 확인
→ 이동 목표·방향·속도 결정
→ UJMDoorMovementComponent에 OpenFraction 전달
→ 장애물 검사
→ 상태/소음/완료 이벤트
```

문이 움직일 때만 `UJMDoorComponent` Tick이 활성화됩니다. 자동 닫힘과 재시도는 Timer를 사용합니다.

## 상태 모델

```text
Closed ↔ Opening ↔ Open ↔ Closing
Closed ↔ Locked
Opening/Closing → Blocked → Reverse/Retry/Jammed
Any non-broken state → Broken
```

`bLocked`와 `bLockBroken`은 접근/내구도 축이며, 표시 상태는 닫힌 잠금 상태에서 `Locked`가 됩니다. 문이 열려 있는 동안 새로 Lock하는 요청은 거부하므로 `Open + Locked` 모순을 만들지 않습니다. `Broken`에서는 이동 명령이 거부됩니다.

## 이동 전략

- `UJMDoorMovementComponent`: 공통 진행률/대상 컴포넌트 계약
- `UJMRotatingDoorMovementComponent`: 로컬 축과 각도 기반 회전
- `UJMSlidingDoorMovementComponent`: 로컬 오프셋 기반 이동
- `UJMCustomDoorMovementComponent`: BlueprintNativeEvent로 사용자 정의 Transform 계산

상태 머신은 구체 이동 방식을 알지 못합니다. 이동 컴포넌트는 상태, 접근 또는 저장 시스템을 알지 못합니다.

## 장애물 검사

다음 프레임의 문짝 World Transform에서 문짝 Bounds 기반 Box Overlap을 수행합니다. 충돌 채널은 Project Settings의 JM Door 설정에서 정합니다.

- Stop: `Blocked` 상태에서 정지, 외부에서 Retry 가능
- Reverse: 반대 목표로 이동하며 이탈 중 동일 장애물 재감지는 억제
- Retry: 설정된 지연과 횟수만큼 재시도 후 `Jammed`
- Ignore: 검사하지 않음

회전문은 `MovementRoot`를 경첩으로 회전시키고 자식 `DoorLeafMesh`를 방향 Probe 및 장애물 Primitive로 사용합니다. 복잡한 문 형상은 전용 Collision Primitive를 지정하거나 이동 컴포넌트를 확장하는 것이 좋습니다.

## 접근 경계

`FJMDoorUseContext.AccessTags`로 직접 태그를 제공하거나, Instigator가 `IJMDoorAccessProviderInterface`를 구현할 수 있습니다. 소비형 열쇠는 `ConsumeDoorAccess` 성공 후에만 잠금이 해제됩니다. JMDoor는 열쇠가 배열, 카드 데이터, 능력 또는 인벤토리 아이템인지 알지 못합니다.

## 저장 경계

`IJMDoorSaveInterface`와 `FJMDoorSaveData`만 제공합니다. 외부 Save System이 Persistent ID를 키로 Capture/Restore를 호출합니다. 파일 I/O, 슬롯, 암호화와 레벨 Actor 검색은 호스트 시스템 책임입니다.

## 에셋 정책

Runtime 코드에는 `/Game` 참조가 없습니다. Demo Blueprint는 시각 확인을 위해 Engine 기본 Cube Mesh를 사용하며, 이 유일한 Engine Content 의존성은 예제에만 존재합니다. 게임용 메쉬와 사운드는 Data Asset/컴포넌트에 지정합니다.

## 네트워크 범위

1.0.0은 권한 중립적인 싱글플레이 Runtime 구현입니다. Replication/RPC를 제공한다고 가정하지 않습니다. 멀티플레이 프로젝트에서는 서버가 명령과 접근 소비를 권위 있게 실행하고, 상태/진행률을 복제하는 파생 Component를 구현해야 합니다.
