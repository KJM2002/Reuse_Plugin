# Changelog

## 1.6.0 - 2026-07-20

### Added

- Independent sliding panels A and B with fixed actor-local left/right opening offsets.
- Configured A, B, or Both opening modes, plus optional nearest-panel selection.
- Blueprint/C++ panel open, close, state, and progress APIs.
- Independent panel state, reversal, auto-close, obstruction, character push, and save data.
- Editor open-position preview for both sliding panels.

### Changed

- General `OpenDoor` uses `SlideDoorOpenMode`; player position no longer reverses a panel's travel direction.
- Obstruction and kinematic push queries run only for panels that are actually moving.

### Compatibility

- Pre-1.6 single-panel assets continue through the legacy panel-A path.
- A native sliding actor whose panel B has no static mesh is treated as a single-panel door.

## 1.5.0 - 2026-07-20

### Added

- 문짝의 이번 프레임 이동 영역을 실제 Primitive로 선행 Sweep하는 연속 kinematic character push
- 회전문 접촉점의 강체 선속도와 미닫이문 프레임 이동 델타 기반 push 계산
- 이동 거리·회전각 기반 predictive substep 설정
- 문 이동 델타, 요청/실제 캐릭터 이동, Sweep Hit와 Normal을 출력하는 로그·디버그 드로우 옵션
- 정지 캐릭터, 20/120 FPS, 벽 고정, 회전문·미닫이문, 이동 종료 후 추가 보정을 검증하는 Automation 및 PIE 테스트

### Changed

- 직접 Actor 위치 보정을 `CharacterMovementComponent::SafeMoveUpdatedComponent`와 `SlideAlongSurface` 기반 이동으로 교체
- `Visibility` Trace Channel 대신 문짝과 Pawn의 실제 Collision Response 쌍으로 접촉 및 장애물 판정
- 프레임당 push 거리 제한과 매 프레임 padding을 제거하고 전체 문짝 델타를 substep으로 적용

### Deprecated

- `CharacterPushPadding`, `MaxCharacterPushDistancePerTick`은 직렬화 호환성만 유지하며 더 이상 연속 push 계산에 사용하지 않음

## 1.4.1 - 2026-07-20

### Fixed

- 정지한 캐릭터를 밀 때 캡슐 Sweep이 문짝의 이전 프레임 위치에 즉시 막혀 카메라와 캐릭터가 떨리던 현상 수정
- 문이 밀어내는 순간에는 해당 문만 이동 충돌에서 제외하고, 벽과 다른 장애물에 대한 Sweep은 그대로 유지

## 1.4.0 - 2026-07-20

### Added

- 움직이는 문짝의 다음 충돌 위치에 캐릭터가 있으면 캡슐을 문 이동 방향으로 프레임별 이동시키는 부드러운 밀기 옵션 추가
- `bPushCharacters`, `CharacterPushPadding`, `MaxCharacterPushDistancePerTick` Blocking 설정 추가

### Changed

- 장애물 검사를 Bounds Box 근사 대신 실제 문짝 Primitive 형상으로 수행해 불필요한 조기 막힘 감소

## 1.3.1 - 2026-07-18

### Fixed

- 열기/닫기 사운드와 소음 이벤트가 이동 완료 후가 아니라 이동 시작 프레임에 발생하도록 타이밍 수정
- 장애물 Retry에서 같은 사운드가 중복 재생되지 않도록 방지

## 1.3.0 - 2026-07-18

### Added

- Door Config의 `Accepted Access Items`에 Item Definition을 직접 연결하는 무태그 접근 방식
- 커스텀 Inventory Blueprint용 `Use Item On Pending Door` 함수

### Changed

- 닫힌 문 평면에서 플레이어가 선 쪽을 계산하고 정확히 반대 반공간으로 회전하도록 방향 알고리즘 교체

## 1.2.1 - 2026-07-18

### Fixed

- JMInteraction의 실제 시선 방향을 Door Context에 보존하고 그 진행 방향의 먼 쪽으로만 회전문 개방
- 잠긴 문 상호작용 시 누락된 Inventory Agent를 자동 생성해 Old Key Use 대상이 사라지는 문제 방지
- 실제 Old Key 에셋과 `InventoryComponent::UseItemAtSlot` 전체 경로 회귀 테스트 추가

## 1.2.0 - 2026-07-18

### Added

- 기존 Character에 붙이는 선택형 `JMDoorGameplayIntegration` 브리지
- JMInteraction 대상 자동 등록과 잠긴 문 상호작용 시 Inventory 자동 열기
- 기존 Old Key의 Use 버튼으로 현재 잠긴 문을 해제하고 여는 흐름

### Changed

- 회전문이 문짝 중심 대신 `MovementRoot` 경첩을 회전하도록 변경
- 열림 후보 두 방향의 실제 문짝 위치를 비교해 상호작용자에게서 멀어지는 방향 선택
- 전용 데모 Pawn/Key를 제거하고 기존 Character/Inventory 기반 설정으로 교체

## 1.1.0 - 2026-07-18 (superseded)

### Added

- Level Blueprint 없이 바로 Play할 수 있는 `L_JMDoorDemo` 플레이 샘플
- WASD/마우스/E 입력과 Door Access Provider를 구현한 `BP_JMDoorDemoPlayer`
- `JM.Door.Demo.Key` 권한을 지급하는 `BP_JMDoorDemoKey`
- 열쇠를 요구하고 사용 시 소비하는 `BP_JMRotatingDoorLockedExample`과 전용 Config
- 열쇠 획득 전 거부, 획득 후 권한 제공, 소비 후 제거를 검증하는 자동화 테스트
- Blueprint와 네이티브 Interface 구현을 모두 안전하게 호출하는 내부 디스패처

### Changed

- 한국어 초보자 가이드를 플레이 가능한 데모 중심으로 개편
- Access/Usable/Save Interface를 Blueprint 구현 가능한 Unreal Interface 계약으로 명시

## 1.0.2 - 2026-07-17

### Fixed

- 게임 시작 시 컴포넌트 BeginPlay 순서에 따라 예제 문짝의 위치와 스케일이 Identity Transform으로 초기화되던 문제 수정
- 실제 예제 Blueprint가 PIE 시작 직후 제작된 위치·회전·크기를 보존하는지 Functional Test에 추가

## 1.0.1 - 2026-07-17

### Fixed

- 배치된 예제 Door의 Details 패널이 교차 컴포넌트 참조를 인라인 재귀 확장해 Stack Overflow가 발생하던 문제 수정
- MovementComponent와 MovingComponent를 편집 속성이 아닌 Transient Runtime 연결로 변경
- 실제 예제 Blueprint를 배치하고 Details 패널을 생성하는 회귀 테스트와 Editor Property Safety 테스트 추가
- UE 5.7에서 Functional Test가 게임 Tick이 없는 Editor World로 전환되던 문제를 막고 PIE World 실행을 명시

## 1.0.0 - 2026-07-17

### Added

- 독립 Runtime 문 상태 머신
- 회전, 미닫이, Blueprint 사용자 정의 이동 컴포넌트
- 위치 기반 개방 방향
- 잠금, Gameplay Tag, Provider Interface 기반 접근
- 문짝/잠금장치 내구도와 강제 개방
- Stop/Reverse/Retry/Ignore 장애물 정책
- 자동 닫힘, 부분 개방, Quiet/Fast 요청
- 저장 Capture/Restore 계약
- Player/AI 공통 Usable Interface
- 상태, 접근 거부, 장애물, 내구도, 소음 이벤트
- Automation/Functional Test
- Data Asset, 예제 Blueprint와 Demo/Test Map
