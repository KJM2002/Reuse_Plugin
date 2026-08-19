---
title: "Changelog"
status: ReviewRequired
authority: Historical
scope: "Plugin: JMFootstep"
classified_on: 2026-08-19
owners:
  - "JMFootstep Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# Changelog

## 1.1.1 - 2026-07-28

### Fixed

- Walk-only Surface가 Walk/Run/CrouchWalk 요청 모두에서 Walk Variant를
  재사용하는 기존 fallback 경로를 회귀 테스트로 고정
- Run/CrouchWalk가 Walk Variant를 fallback해도 요청 상태의 Step Distance와
  Volume Multiplier를 사용하는 경로를 공용 Runtime helper와 테스트로 검증
- `ShowOnlyInnerProperties`와 Variant 내부 `Audio`/`Variation` Category가
  결합해 Surface Profile Details에 중복 Category/Property를 만들던 문제 수정

### Changed

- Walk/Run/Crouch Walk 그룹 아래에 각각 접을 수 있는 Variant 구조체와
  Sounds/Volume/Pitch 필드가 보이도록 Details metadata 정리
- Walk-only 설정 예, `Wander` Sound Cue 이름의 의미, 상태별 거리/음량 유지
  규칙을 README와 Architecture에 명시
- Walk-only 전체 gait, Run/Crouch Legacy fallback, 요청 gait 설정 유지,
  Details metadata 자동화 테스트 추가

### Compatibility

- `WalkVariant`, `RunVariant`, `CrouchWalkVariant` 및 구조체 내부 필드의 이름,
  타입, 소유 구조를 유지하며 직렬화 데이터나 Asset migration 요구 없음
- v1.0 Legacy 필드와 Run/CrouchWalk -> Walk -> Legacy 정책 유지

## 1.1.0 - 2026-07-26

### Added

- `FJMFootstepSoundVariant`와 Walk/Run/CrouchWalk별 Sound 및 Volume/Pitch 범위
- 요청 상태와 실제 선택 Variant, Variant/Legacy fallback을 노출하는 Result 정보
- Profile + 실제 선택 Variant별 독립적인 직전 Sound 기록
- 상태 Variant 선택, fallback, null 안전성, 독립 기록, Context Override 자동화 테스트 11개

### Changed

- 공통 Request 경로가 Surface Profile 선택 후 Locomotion Variant를 해석하도록 확장
- Run은 Run -> Walk -> Legacy, CrouchWalk는 CrouchWalk -> Walk -> Legacy 순서로 fallback
- 수동 Idle 요청은 Trace/재생 없이 `NotMoving` 반환
- Debug 로그에 요청 상태, 선택 Variant, Surface/Variant fallback 및 Legacy 사용 여부 추가

### Compatibility

- v1.0의 `Sounds`, `VolumeMin/Max`, `PitchMin/Max`, `AttenuationSettings` 속성 이름과 타입 유지
- 기존 v1.0 Profile은 새 Variant가 비어 있을 때 Legacy fallback으로 계속 동작
- 기존 Component, Context, Delegate API를 유지하고 Result에는 Blueprint Read Only 필드만 추가

## 1.0.0 - 2026-07-26

### Added

- 실제 XY 이동 거리와 잔여 거리 보존 기반 자동 발걸음 Trigger
- Walk, Run, CrouchWalk 자동 판정과 수동 상태 Override
- Grounded 제한, Teleport Reset, 프레임당 Step 상한
- Capsule Bottom 기반 Physical Material 반환 Trace
- 데이터 기반 Physical Surface/Profile 매핑과 Default fallback
- 직전 Sound 반복 회피, Profile Volume/Pitch Variation, 상태별 Volume 배율
- 충돌 지점 3D One-shot Sound와 선택 Attenuation
- Blueprint Context/Result, 실패 이유, 성공 Delegate, Left/Right 논리 발
- `JM Plugins -> Footstep` Developer Settings와 Component별 Override
- 비-Shipping opt-in Debug line/point/log
- `JM.Footstep.*` Automation Test 14개
- 설치/사용 문서와 아키텍처 문서

### Notes

- v1은 로컬 싱글플레이 Cosmetic 시스템입니다.
- Network Replication, AI Hearing, Animation/AnimNotify, Landing/Jump Sound,
  VFX/Footprint는 범위 밖입니다.
