# Changelog

## Unreleased

### Changed

- Nested modal UI keeps the Objective Widget hidden until the final modal closes.

- Project Settings의 `JM Objective` 섹션을 `Plugins`에서 공통 `JM Plugins` 카테고리로 이동
- 공통 `Event.UI.Modal.*` 이벤트 동안 Objective Widget을 숨기고 종료 후 최신 상태 복원

## 1.1.0 - 2026-07-22

### Added

- Data Asset 기반 선형 `UJMObjectiveFlowDefinition`
- GameInstance 수명의 `UJMObjectiveFlowSubsystem`
- Flow Start/Stop/Reset/Restart/조회/Capture/Restore Blueprint API
- `AJMObjectiveFlowStarter` 레벨 Actor
- LocalPlayer 수명의 자동 Objective UI Presenter
- Blueprint 없는 C++ 기본 Objective Widget
- Flow Delegate와 `Event.ObjectiveFlow.*` Gameplay Event/Payload
- Flow 검증, 순차 진행, 실패, 재시작, Save, UI 계약 자동화 테스트
- 초보자용 `FLOW_SETUP_KO.md`

### Changed

- `UJMObjectiveSettings`에 자동 UI, Z Order, 빈 상태 숨김, 완료 표시 시간 설정 추가
- `UJMObjectiveWidgetBase`가 선택적 이름/설명/진행도/상태 TextBlock을 자동 갱신
- 수동 Level Blueprint 조립 방식은 고급 사용법으로 이동

### Compatibility

- 기존 Objective Definition, Subsystem, Blueprint API, Delegate, Gameplay Event, Widget 이벤트, Save API 유지
- Door, Inventory, Dialogue, Interaction Runtime 직접 의존성 없음
