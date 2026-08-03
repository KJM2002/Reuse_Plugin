# JMDoor API

## Sliding door panels (1.6+)

`AJMSlidingDoorActor` exposes the inherited `DoorLeafMesh` as panel A and `DoorLeafMeshB` as panel B. `DoorAOpenOffset` defaults to actor-local left `(0, -150, 0)` and `DoorBOpenOffset` defaults to actor-local right `(0, 150, 0)`.

Use `OpenSlideDoor(Panel, Context)` and `CloseSlideDoor(Panel, Context)` from Blueprint or C++, where `Panel` is `DoorA`, `DoorB`, or `Both`. `GetSlideDoorPanelState` and `GetSlideDoorPanelOpenFraction` expose independent runtime state. General `OpenDoor` follows `SlideDoorOpenMode`; `ConfiguredPanel` is the default selection mode and `NearestPanel` only selects a panel—it never changes its movement direction.

Panel A and B independently retain `Closed / Opening / Open / Closing / Blocked / Jammed / Broken` state. A command received mid-animation reverses from the current fraction. Auto-close, obstruction detection, and character pushing apply only to the panel involved.

## 주요 Actor

### `AJMRotatingDoorActor`

`SceneRoot`, `FrameMesh`, `MovementRoot`, `DoorLeafMesh`, `LockMesh`, `DoorComponent`, `RotatingMovement`를 포함하는 즉시 사용 가능한 회전문입니다. `MovementRoot`를 경첩 위치로 두고 `DoorLeafMesh`의 상대 위치로 Pivot을 보정합니다.

### `AJMSlidingDoorActor`

동일한 기본 구성에 `SlidingMovement`가 포함됩니다. `LocalOpenOffset`으로 이동 축과 거리를 지정합니다.

## `UJMDoorComponent`

주요 명령:

- `ExecuteCommand`: 범용 명령 진입점
- `OpenDoor`, `CloseDoor`, `ToggleDoor`
- `LockDoor`, `UnlockDoor`
- `ForceOpenDoor`
- `ApplyDoorDamage`, `ApplyLockDamage`
- `RetryBlockedMovement`
- `CaptureSaveData`, `RestoreSaveData`
- `ValidateConfiguration`

조회:

- `GetState`
- `IsLocked`
- `GetOpenFraction`
- `GetDoorDurability`
- `GetLockDurability`

이벤트:

- `OnDoorStateChanged`
- `OnAccessDenied`
- `OnNoiseEmitted`
- `OnDoorObstructed`
- `OnDurabilityChanged`

모든 Dynamic Multicast 이벤트는 Game Thread에서 발생합니다. 명령 호출 직후 Opening/Closing 상태 전이가 먼저 발생하고, 같은 프레임에 해당 사운드와 소음 이벤트가 발생합니다. 이동 완료 시에는 Open/Closed 상태 전이가 발생합니다.

## Context와 결과

`FJMDoorUseContext`:

- Instigator Actor/Controller
- Interaction Location
- Interaction Direction
- Access Tags
- Access Object (직접 연결된 Key/Card/Item Definition)
- AI 여부
- Quiet/Fast 요청
- `RequestedOpenFraction`(0~1)

`FJMDoorResult`는 성공 여부, `EJMDoorResultCode`, 로컬라이징 가능한 메시지를 반환합니다. 호출자는 `bool`만 보지 말고 실패 코드를 UI/AI 분기에서 사용해야 합니다.

## Data Asset

`UJMDoorConfigData`는 다음을 정의합니다.

- 개폐 시간, Curve, 방향 정책
- 자동 닫힘
- 초기 잠금, Tag 접근 요구사항, `Accepted Access Items` 직접 에셋 연결
- 문/잠금장치 내구도
- 장애물 정책과 재시도
- 소음 수치
- Soft Sound Reference

Config가 비어 있으면 클래스 기본 객체의 안전한 기본값이 사용됩니다.

## Native Gameplay Tags

- `JM.Door.Noise.Open`
- `JM.Door.Noise.Close`
- `JM.Door.Noise.Break`
- `JM.Door.Access.Master`
- `JM.Door.Demo.Key` (플레이 가능한 데모 전용 열쇠)

`JM.Door.Test.*` 태그는 자동화 테스트 전용입니다.

## Blueprint 연결

`Make Door Use Context`로 Context를 만들고 `Execute Door Command On Object`를 호출합니다. 대상은 `JM Door Usable Interface` 구현체여야 합니다. Player와 AI 모두 동일한 노드를 사용하고 `bIsAI`만 의미 정보로 전달합니다.

일반 Blueprint 프로젝트에서는 Door Config의 `Accepted Access Items`에 Inventory Item Definition을 직접 연결하는 방식을 권장합니다. Tag 기반 권한 계층이 필요한 대형 프로젝트만 `Access Tags` 또는 `JM Door Access Provider Interface`를 사용하면 됩니다. 통합 플러그인의 `Use Item On Pending Door` 노드는 커스텀 Inventory Blueprint의 Use 이벤트와 직접 연결할 수 있습니다.
