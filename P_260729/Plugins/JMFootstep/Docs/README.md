---
title: "JMFootstep"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMFootstep"
classified_on: 2026-08-19
owners:
  - "JMFootstep Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMFootstep

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JMFootstep Architecture](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |


JMFootstep v1.1은 애니메이션, Anim Blueprint, Anim Notify, 발 Bone/Socket 없이
작동하는 Unreal Engine 5.7 Runtime 발걸음 플러그인입니다.

`ACharacter`의 실제 XY 이동 거리를 누적해 발걸음 시점을 정하고, 발밑 Trace가
반환한 `Physical Material -> Physical Surface`를 데이터 에셋의 사운드 Profile로
변환한 뒤 충돌 지점에서 3D One-shot 사운드를 재생합니다.

## 설치와 의존성

1. `Plugins/JMFootstep` 폴더를 대상 C++ 프로젝트의 `Plugins` 폴더로 복사합니다.
2. Unreal Editor의 Plugins 창에서 **JM Footstep**을 활성화합니다.
3. C++ 프로젝트를 다시 빌드하고 Editor를 재시작합니다.

다른 JM 플러그인은 필요하지 않습니다. Runtime 모듈은 Unreal Engine의
`Core`, `CoreUObject`, `Engine`, `DeveloperSettings`, `PhysicsCore`만 사용합니다.
`JMGameplayEvent`, AI, Animation 모듈은 의존하지 않습니다.

## Blueprint 제작자 설정

### 1. Physical Surface 정의

**Project Settings -> Physics -> Physical Surface**에서 필요한 표면을 만듭니다.

예:

- Surface Type 1: Concrete
- Surface Type 2: Wood
- Surface Type 3: Metal
- Surface Type 4: Grass

### 2. Physical Material 생성

Content Browser에서 Physical Material을 만들고 각 에셋의 Surface Type을
지정합니다.

예:

- `PM_Wood`: Wood
- `PM_Metal`: Metal

바닥 Material 또는 Material Instance의 Physical Material 슬롯에 해당 에셋을
연결합니다. Trace 대상 Collision이 설정한 Trace Channel을 Block해야 합니다.

### 3. Surface Profile 생성

Content Browser에서 **Miscellaneous -> Data Asset**을 선택하고
`JMFootstepSurfaceProfile`을 만듭니다.

Details 패널의 상태별 그룹을 설정합니다. 각 상태 그룹에는 접을 수 있는 Variant
구조체가 하나씩 표시되며, 별도의 `Audio` 또는 `Variation` Category는 생성되지
않습니다.

- Footstep > Walk > Walk Variant: 걷기 Sounds와 Volume/Pitch 범위
- Footstep > Run > Run Variant: 달리기 Sounds와 Volume/Pitch 범위
- Footstep > Crouch Walk > Crouch Walk Variant: 앉아서 걷기 Sounds와 Volume/Pitch 범위
- Footstep > Spatial Audio: 세 상태가 공유하는 Attenuation Settings(선택)
- Footstep > Legacy Compatibility: v1.0 Sounds와 Volume/Pitch 범위

각 Variant의 Volume/Pitch 범위는 같은 녹음 세트 안의 자연스러운 무작위
차이를 만듭니다. Project Settings의 Walk/Run/Crouch Volume Multiplier는
상태 사이의 전체적인 상대 음량을 조절합니다. Min/Max 순서를 반대로 입력해도
런타임에서 안전하게 정렬합니다.

상태별 유효 Sound가 두 개 이상이면 해당 Profile과 실제 선택된 Variant의 직전
Sound와 다른 Sound를 우선합니다. Walk, Run, Crouch Walk 기록은 서로
독립적입니다.

#### 상태 Variant fallback

```text
Walk:       Walk -> Legacy v1.0 -> SoundMissing
Run:        Run -> Walk -> Legacy v1.0 -> SoundMissing
CrouchWalk: Crouch Walk -> Walk -> Legacy v1.0 -> SoundMissing
```

기존 v1.0 Data Asset의 `Sounds`, `VolumeMin/Max`, `PitchMin/Max` 필드는
**Legacy Compatibility** 그룹에 원래 이름과 타입 그대로 유지됩니다. 새
Variant를 비워 두면 기존 값이 계속 재생되므로 에셋을 한 번에 마이그레이션할
필요가 없습니다.

#### Walk 사운드만 있는 Surface

Wood Profile에 다음처럼 Walk 사운드만 설정해도 됩니다.

```text
Walk Variant:        Wood_Walk
Run Variant:         Empty
Crouch Walk Variant: Empty
```

런타임 결과는 다음과 같습니다.

```text
Walk        -> Wood_Walk
Run         -> Wood_Walk fallback -> Run Step Distance + Run Volume Multiplier
CrouchWalk  -> Wood_Walk fallback -> Crouch Step Distance + Crouch Volume Multiplier
```

fallback은 사운드 소스 Variant만 Walk로 바꿉니다. 현재 Locomotion State는
Run/CrouchWalk로 유지되므로 발걸음 발생 간격과 상태 Volume도 각각 Run/Crouch
설정을 사용합니다. 별도의 fallback Volume/Pitch Modifier는 없습니다.

`Grass_Wander_Cue`, `Water_Wander_Cue`처럼 Sound Cue 이름에 `Wander`가
포함되어 있어도 이는 에셋 제작자가 정한 이름일 뿐 Locomotion State가 아닙니다.
필요하면 해당 Cue를 Crouch Walk Variant에 직접 지정합니다. JMFootstep 상태는
Idle, Walk, Run, CrouchWalk 네 가지를 그대로 사용합니다.

### 4. Footstep Set 생성

`JMFootstepSet` Data Asset을 만들고 다음을 연결합니다.

- Default Profile: Physical Material 누락 또는 미등록 Surface의 fallback
- Surface Profiles: `Wood -> DA_Footstep_Wood` 같은 Surface/Profile 항목

새 Surface는 이 배열에 추가하면 되며 C++ 수정이 필요하지 않습니다.

### 5. Project Settings 연결

**Project Settings -> JM Plugins -> Footstep**에서:

- Default Footstep Set 지정
- Trigger Mode = Distance Based
- 이동/거리/Trace/Audio 값을 프로젝트에 맞게 조정

기본값:

- Minimum Movement Speed: 10 cm/s
- Run Speed Threshold: 325 cm/s
- Walk / Run / Crouch Step Distance: 110 / 140 / 80 cm
- Trace Distance / Start Offset: 70 / 10 cm
- Teleport Distance Threshold: 500 cm
- Max Steps Per Frame: 2

### 6. Character에 Component 추가

Character Blueprint를 열고 **JMFootstepComponent** 하나를 추가합니다.
별도의 Blueprint Tick이나 발걸음 Graph를 작성하지 않고 Play하면 됩니다.

특정 Character만 다른 값을 써야 하면 Component의 Override 그룹을 켭니다.
해석 우선순위는 Request 배율/Trace Origin, Component Override, Project Settings,
C++ 안전 기본값 순서입니다.

## 자동 상태 판정

- 실제 속도가 Minimum Movement Speed 미만: Idle
- Crouched: CrouchWalk
- 실제 속도가 Run Speed Threshold 이상: Run
- 그 외 Grounded 이동: Walk

입력값이 아니라 실제 Transform 변화량을 사용하므로 벽에 막힌 상태에서 키만
누르면 거리가 누적되지 않습니다. Falling/Flying/Swimming 중에는 누적값을
비우고 일반 발걸음을 발생시키지 않습니다.

Character의 `Max Walk Speed`가 300 cm/s라면 기본 Run Speed Threshold
325 cm/s에 도달하지 않아 Run Variant가 선택되지 않습니다. 예를 들어 걷기
300, 달리기 600을 사용할 경우 Threshold를 325~400 정도로 두면 두 상태를
구분할 수 있습니다. 발소리 재생 간격은 속도 자체가 아니라 상태별 Step
Distance로 결정됩니다. 소리가 너무 빠르면 Walk/Run/Crouch Step Distance를
늘리고, 너무 느리면 줄입니다.

특수 이동은 `Set Locomotion State Override`와
`Clear Locomotion State Override` Blueprint 노드로 상태를 직접 지정할 수
있습니다. 수동 상태 Override도 Grounded 검사를 우회하지 않습니다.

## 수동 호출과 확장

- `Trigger Footstep`: 현재 Owner/상태로 즉시 요청
- `Request Footstep`: Trace Origin, 상태, 논리 발, Volume/Pitch 배율을 포함한
  Context로 요청
- `On Footstep Played`: 성공 Result를 VFX, 카메라 효과, AI Adapter 등이 소비

Result에는 성공/실패, 실패 이유, 상태, Left/Right 논리 발, Surface, Physical
Material, Sound, Impact Point/Normal, 최종 Volume/Pitch가 들어 있습니다.
`Selected Variant State`, `Used Variant Fallback`, `Used Legacy Variant`로 실제
선택 경로도 확인할 수 있습니다. 수동 Request에서 Locomotion State Override를
Run으로 지정하면 동일한 공통 경로가 Run Variant를 선택합니다. 수동 Idle 요청은
Walk로 바꾸지 않고 `NotMoving`으로 실패합니다.

## Debug

Project Settings 또는 Component Override에서 Debug를 활성화하면 비-Shipping
빌드에서 Trace line, Impact point, 상태, 거리, Surface, Profile, Sound,
요청/선택 Variant, fallback, Volume/Pitch를 확인할 수 있습니다. 정상 실행에서는
Debug를 켜지 않는 한 상세 로그를 남기지 않습니다.

## 실패 정책

- 잘못된 Owner: `InvalidOwner`
- 공중: `NotGrounded`
- Idle 수동 요청: `NotMoving`
- Trace 실패: `TraceFailed`
- Physical Material 누락 + fallback 없음: `PhysicalMaterialMissing`
- Surface Profile과 fallback 누락: `SurfaceProfileMissing`
- 유효한 Sound 없음: `SoundMissing`
- Footstep Set 누락: `SettingsMissing`

누락 구성은 Sound를 생략하고 Result로 보고하며 `check()`나 Crash를 사용하지
않습니다.

## v1.1 제한

JMFootstep v1.1은 로컬 싱글플레이 Cosmetic Detection/Audio 시스템입니다.
Authority 검증, RPC, Replication, AI Hearing, Landing/Jump Sound, Anim Notify,
Foot IK, Footprint, Niagara/VFX, Camera Bob, Rumble, SaveGame은 제공하지 않습니다.
