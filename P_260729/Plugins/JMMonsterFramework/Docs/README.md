---
title: "JMMonsterFramework"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMMonsterFramework"
classified_on: 2026-08-19
owners:
  - "JMMonsterFramework Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMMonsterFramework

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|


Unreal Engine 5.7용 데이터 기반 재사용형 Enemy AI 빌딩 블록 플러그인입니다. 호스트의 `P_060715` 모듈,
기존 JM AI 플러그인 및 `/Game` 콘텐츠에 의존하지 않는 독립형 플러그인입니다.

Enemy는 Definition, Perception, Memory, StateTree, Locomotion, Action과 선택적 Presentation의 조합입니다.
새로운 행동은 일반적으로 기존 노드를 새로운 StateTree에서 조합해 만듭니다. C++ 확장은 실제로 새로운
감지 능력, 이동 백엔드, 수행 능력 또는 재사용 노드가 필요할 때만 사용합니다.

## 아키텍처

```text
UJMEnemyDefinition ----------------> 변경 불가능한 시스템 설정
        |
AJMEnemyBase
|- UJMEnemyStateComponent          단일 GameplayTag 상태
|- UJMEnemyPerceptionComponent     정규화된 감지 정보
|- UJMEnemyMemoryComponent         이벤트 기반 기록과 명시적 Target
|- UJMEnemyLocomotionComponent     이동 의도와 Request 생명주기
|- UJMEnemyActionComponent         Runtime Action 인스턴스와 Cooldown
|- UJMEnemyAudioComponent          선택적 Event-to-Sound Presentation
`- UJMEnemyDebugComponent          선택형 Runtime 디버그

Skeletal Mesh
`- UJMEnemyAnimInstance            캐시 기반 읽기 전용 Animation 데이터 공급자

AJMEnemyAIController
|- UAIPerceptionComponent          Unreal 감지 어댑터
`- UJMEnemyStateTreeComponent      Possession 생명주기의 행동 실행기

World -> Perception -> Memory -> StateTree -> State / Locomotion / Action -> Presentation
```

Perception과 Memory는 행동을 선택하지 않습니다. Locomotion은 목적지가 선택된 이유를 알지 못합니다.
Action은 State를 자동으로 변경하지 않습니다. Enemy별 규칙은 StateTree Asset에만 존재하며 DataAsset은
Runtime 상태를 보관하지 않습니다.

## 빠른 시작

1. 플러그인을 활성화하고 Content Browser에서 Plugin Content를 표시합니다.
2. `AJMEnemyBase` 기반 Blueprint를 만듭니다. Surface Crawler만 `AJMSurfaceCrawlerEnemyBase`를 사용합니다.
3. `UJMEnemyDefinition`을 만들고 Blueprint의 Enemy Definition 속성에 지정합니다.
4. 필요한 Vision, Hearing, Player Gaze 설정을 활성화합니다.
5. `UJMEnemyMovementSet`과 유효한 기본 Movement Profile을 선택합니다.
6. 필요한 `UJMEnemyActionDefinition` Asset을 추가합니다.
7. StateTree를 만들고 제공된 Task와 Condition을 조합합니다.
8. 필요하면 `UJMEnemyAudioSet`을 지정하고 Asset을 검증한 다음 Play합니다.

Editor 속성은 `JM Monster|Identity`, `Perception`, `Movement`, `Actions`, `Behavior`, `Audio`, `Debug`
Category로 정리되어 있습니다.

## 새로운 Enemy 만들기

가장 가까운 Reference Enemy에서 시작해 감지, 이동, Action, 상태 흐름을 분석한 뒤 새로운 Definition과
StateTree를 구성합니다. 기존 빌딩 블록으로 설계를 표현할 수 있다면 C++를 추가하지 않습니다.

```text
새로운 행동 패턴 또는 상태 흐름 -> StateTree
새로운 튜닝 수치              -> DataAsset / Profile
새로운 감지 능력              -> Perception 확장
새로운 이동 능력              -> Locomotion Subclass
새로운 수행 능력              -> Action Subclass + Definition
```

예를 들어 "플레이어가 보면 도망간다"는 StateTree, "두 번째 조우에서 광폭화한다"는 StateTree와 Memory,
"벽을 기어 다닌다"는 새로운 Locomotion 백엔드의 책임입니다.

## Perception

`UJMEnemyPerceptionComponent`는 Unreal Vision/Hearing, Player Gaze, Damage 및 외부 Observation을
`FJMStimulus`로 정규화합니다. Vision과 Hearing은 Engine Event 기반입니다. Gaze는 활성화된 경우에만 설정된
주기로 실행됩니다. `SubmitPlayerGazeObservation`은 VR, Camera, Test 또는 사용자 정의 Viewer용 어댑터 경계입니다.

새 Sense는 결과를 Perception 경계에서 `FJMStimulus`로 변환해 추가합니다. Sense 어댑터에 Target 선택이나
State 전환을 구현하지 않습니다.

## Memory

`UJMEnemyMemoryComponent`는 마지막으로 본/들은/알려진 위치와 시간, 현재 시야 여부, 명시적 Current Target,
Encounter Count를 저장합니다. Stimulus로 갱신되고 Target 변경을 알리지만, 정보의 사용 방법은 StateTree가 결정합니다.

## State

`UJMEnemyStateComponent`는 하나의 구체적인 `JM.Enemy.State.*` Tag를 소유하고 `OnStateChanged`를 발생시킵니다.
State Tag는 관찰 가능한 Runtime 상태이며 행동 그래프를 대체하지 않습니다.

## Locomotion

`UJMEnemyLocomotionComponent`는 MoveToActor, MoveToLocation, MoveAway, Stop, Facing, Random Reachable Point 및
Named Profile 기능을 제공합니다. 결과는 Started/Succeeded/Failed/Aborted로 정규화됩니다. Ground Movement는
UE AI Navigation에 위임하며 Tick하지 않습니다.

`UJMEnemyLocomotion_SurfaceCrawler`는 동일한 이동 의도 API를 유지하면서 연결된 정적 Geometry를 Trace합니다.
활성 Request가 있을 때만 Tick하고, 일반 이동 중 Forward Transition Trace와 Support Trace를 각각 한 번 수행합니다.
Actor Up을 Surface Normal에 맞추고 제한된 Surface Loss 복구 후 안전하게 Falling/Failed 상태로 전환합니다.

Flying 등 새로운 백엔드는 Locomotion Seam을 Subclass하고 Request ID와 완료 의미를 유지해야 기존 StateTree Task를
그대로 재사용할 수 있습니다.

## Action

`UJMEnemyActionComponent`는 변경 불가능한 Definition마다 Enemy별 Runtime `UJMEnemyAction`을 만들고 하나의
Primary Action 정책을 적용합니다. Windup, Active, Recovery, Cancel, Cooldown은 Timer 기반입니다. 명시적으로
Update를 요청한 Action이 실행 중일 때만 Component Tick이 활성화됩니다. Melee와 Scream은 Reference Action입니다.

새로운 수행 능력은 Enemy Class가 아니라 새로운 Action Subclass와 변경 불가능한 Action Definition에 구현합니다.

## StateTree

Controller가 Possession 기간 동안 StateTree를 소유하고 실행합니다. 공통 Task는 State, Move, Facing, Movement
Profile, Escape, Action, Encounter, Wait, Target 명령을 제공합니다. 공통 Condition은 Target, 최근 Stimulus, Sight,
Gaze, Distance, Encounter, State, Action Ready 상태를 조회합니다. `JM.Enemy.Event.Stimulus`가 이벤트 기반 전환을
깨웁니다. 재사용 가능한 Query나 Command가 실제로 없을 때만 새 노드를 추가하며 Engine Scheduling을 복제하지 않습니다.

## Audio

`UJMEnemyAudioSet`은 Presentation Event를 Volume/Pitch 범위를 가진 여러 Sound Variant에 연결합니다.
`UJMEnemyAudioComponent`는 State와 Action Delegate를 구독합니다. AI 코드와 Scream Action은 Sound Asset을 직접
소유하지 않습니다. Variant가 비어 있는 Event Entry도 유효한 Placeholder Contract입니다.

현재 Investigate, Chase, Flee, Frozen, Enrage, Frenzy, AttackWindup, Attack, Death, Scream Event를 지원합니다.
Listener는 Investigate/Chase/Attack, Watcher는 Frozen/Attack, Crawler는 Enrage/Scream/Frenzy 연결을 검증합니다.
재생하려면 각 Reference Audio Set의 Variant에 Sound를 지정합니다. Audio Set이 없으면 Delegate Binding과 Runtime
작업도 수행하지 않습니다.

## Animation / Presentation

`UJMEnemyAnimInstance`는 Framework Runtime 데이터와 Animation Blueprint 사이의 Skeleton 독립적 경계입니다.
Animation 초기화 시 Enemy, State, Locomotion, Action 참조를 캐시합니다. Animation Update에서는 World Velocity,
Actor Local Direction, Speed, Moving/Falling 여부, Current State, Movement Profile, Current Action과 Action Phase만
읽습니다. 매 Frame Component 검색, Sense, Trace, Navigation, StateTree Query 또는 Asset Lookup을 수행하지 않습니다.

```text
StateTree -> State / Locomotion / Action -> UJMEnemyAnimInstance -> AnimBP -> Skeletal Mesh
```

Animation은 읽기 전용 Presentation입니다. AnimBP가 Target을 선택하거나 AI State를 변경해서는 안 됩니다.
GameplayTag State Data만으로 Listener의 Patrol/Investigate/Chase/Search, Watcher의 Frozen Pose, Crawler의
Stalk/Flee/ReApproach/Enrage/Frenzy를 Enemy Type Boolean이나 전용 Runtime Brain 없이 표현할 수 있습니다.

Ground와 SurfaceCrawler는 동일한 Local-space Locomotion Contract를 사용합니다. SurfaceCrawler가 Actor Up을
Surface Normal에 맞추므로 동일한 In-place Crawl Animation을 Floor, Wall, Ceiling에서 사용할 수 있습니다.
Surface Attachment가 Actor Transform을 소유하므로 Crawler의 일반 이동에는 Root Motion을 사용하지 않는 것이 원칙입니다.

One-shot Animation은 기존 Action Component Delegate에 한 번 Bind하고 Action Tag로 Montage를 선택할 수 있습니다.
`OnActionStarted`, `OnActionPhaseChanged`, `OnActionFinished`, `OnActionCancelled`가 그대로 Event Contract이며
Animation 전용 생명주기를 중복 구현하지 않습니다.

현재 Timing 소유 정책은 다음과 같습니다.

```text
Action Timer Lifecycle -> Gameplay Timing과 Damage
Montage / AnimBP        -> 시각적 동기화
```

향후 Notify 기반 Gameplay Timing을 별도 확장으로 추가할 수 있지만, 현재의 안정적인 Action Timeline과 Damage
Ownership을 AnimNotify로 옮기지 않습니다. 공유 Montage Asset이 없어 중복 제거의 실익이 없으므로
`UJMEnemyAnimationSet`도 아직 추가하지 않았습니다. 실제 Content가 필요로 할 때 선택적 Definition Asset으로 확장합니다.

새 Enemy Animation 제작 절차:

1. 원하는 Skeletal Mesh/Skeleton을 준비합니다. Framework 전용 Bone 이름은 없습니다.
2. `UJMEnemyAnimInstance` 기반 AnimBP를 만듭니다.
3. Speed와 Direction으로 Locomotion을 구성합니다.
4. CurrentState GameplayTag로 특수 Pose를 선택합니다.
5. Action Lifecycle Event에 Bind하고 CurrentAction/Phase로 선택적 Montage를 실행합니다.
6. 일반 이동은 In-place로 유지하고 특수 Root-motion Action은 명시적인 후속 확장으로 취급합니다.

Animation은 완전히 선택 사항입니다. Cube/Static Placeholder와 Definition, StateTree, Locomotion, Action, Debug만으로
Skeletal Mesh, AnimBP, Sequence, Montage 또는 AnimationSet이 준비되기 전에 AI 전체를 개발하고 검증할 수 있습니다.

## Debug

모든 Enemy는 선택형 `UJMEnemyDebugComponent`를 소유합니다. 기본값은 비활성 및 Tick OFF입니다. PIE에서 Enemy를
선택해 `SetDebugEnabled(true)`를 호출하거나 **Enable On Begin Play**를 활성화할 수 있습니다. 전체 Enemy는 다음
Console Command로 제어합니다.

```text
JM.AI.Debug 1
JM.AI.Debug 0
```

Overlay는 Enemy/State/Target, Seen/Heard/Known Memory, Visibility/Gaze, Encounter Count, Movement Profile/Status/
Destination/Target/Request, Current Action/Phase/Cooldown, StateTree 상태를 표시합니다. World Primitive는 Vision,
Hearing, Gaze, Memory Point, Move Destination, Crawler Attachment/Normal/Direction을 표시합니다. Shipping Build에서는
Component가 강제로 꺼지고 Draw 경로가 Compile-out됩니다.

Mesh가 `UJMEnemyAnimInstance`를 사용하면 동일한 Overlay에 AnimInstance Class, Animation Speed/Direction,
CurrentAction, Action Phase도 표시됩니다. AnimInstance가 없는 Placeholder는 Warning이나 실패 없이 `Anim: None`으로 표시됩니다.

## Reference Enemy

- **Listener**: Hearing, 성급한 Target 지정 없는 증거 조사, Memory, Chase, Melee, Search, Patrol 복귀를 검증합니다.
- **Watcher**: Vision, Player Gaze, Frozen, Movement/Action Cancel, Gaze 해제, Chase, Attack을 검증합니다.
- **Crawler**: 연결된 정적 Floor/Wall/Ceiling 이동, 지속되는 Encounter Count, 공통 Gaze, 첫 Gaze Flee,
  두 번째 Gaze Enrage, Scream, Frenzy, Attack을 검증합니다.

Reference Content는 `Content/Reference/Listener`, `Watcher`, `Crawler`에 일관되게 배치되어 있습니다. 각 폴더에는
`BP_Enemy_*`, `DA_Enemy_*`, `ST_*`, Definition별 Movement/Action Asset과 `DA_*_Audio`가 있습니다.

## 테스트

`JM.MonsterFramework` Automation Group을 실행합니다. 테스트는 다음 범주로 나뉩니다.

- Unit: Core State/Default/Validation, Stimulus와 Memory 정책, Profile 조회, Action Lifecycle, Audio Mapping
- Animation Contract: Asset 없는 초기화, State/Frozen Data, Action Lifecycle Data, SurfaceCrawler Local-space 이동 Data
- Integration: Perception-to-Memory 조합, StateTree Ownership/Event Bridge, Locomotion 안전 실패
- Asset Composition: 각 Reference Definition, Blueprint, StateTree, Profile/Action, Audio Contract
- World Vertical Slice: Transient Game World의 Listener, Watcher, Crawler 빌딩 블록 행동 흐름
- Surface Locomotion: Collision ON 상태의 Floor -> Wall -> Ceiling -> Wall -> Floor Capsule 이동, Orientation,
  Request 교체/Abort, Transition Count, 실제 Static Cube Geometry에서의 NaN 안전성

Automation은 일부 StateTree와 Transient World Fixture를 직접 Step합니다. Component Contract와 Graph Composition은
검증하지만 전체 PIE Scheduler, Animation Rendering, Player Gameplay, Sound Mix 품질, Packaged Build, Moving Platform,
Multiplayer Authority, Production Level의 복잡한 Collision까지 재현하지는 않습니다. 해당 항목은 대상 프로젝트의
PIE와 Packaged Build에서 별도로 검증해야 합니다.

Reference/Test Asset은 Editor Commandlet 환경에서 다음 명령으로 재생성할 수 있습니다.

```text
UnrealEditor-Cmd.exe <Project>.uproject -run=JMMonsterFrameworkBuildReferenceAssets
```

Builder는 Editor 전용 Tests Module에 있으며 Shipping Runtime Dependency가 아닙니다.

## Tick 및 성능 정책

```text
EnemyBase / State / Memory / Ground Locomotion / Audio   OFF
Perception Vision / Hearing / Damage                     Event 기반
Player Gaze                                               설정된 Timer만 사용
Action                                                    기본 OFF, Update 요청 Action 실행 중에만 ON
SurfaceCrawler                                            Active Move 중에만 ON
StateTree                                                 Engine 관리
AnimInstance                                              Engine Animation Update, 캐시 참조와 값 읽기만 수행
Debug                                                     명시적으로 활성화할 때만 ON
```

Frame 단위 로그는 없습니다. 잘못된 필수 Runtime 설정은 조치 가능한 Warning을 남기고 상세 확인은 선택형 Debug
Layer가 담당합니다.

## Data Validation

다음 설정을 Error로 검증합니다.

- 0 이하 Health 또는 음수 Damage
- 잘못된 State/Action Tag
- 활성화된 Sense의 잘못된 Range
- 잘못된 Gaze Interval/Distance
- 불완전하거나 존재하지 않는 기본 Movement Profile
- 잘못되거나 중복된 Movement Profile
- Null/Invalid/Duplicate Action Definition
- 잘못되거나 중복된 Audio Event/Variant

Authoring Identity 또는 StateTree 누락은 Headless 빌딩 블록 사용을 지원하기 위해 Warning으로 처리합니다.
StateTree Graph를 Parsing해 Cross-system 의도를 추론하지는 않습니다.

## 알려진 제한 사항

- Single-player Reference 범위이며 Production Replication, Authority, Network Smoothing은 검증하지 않았습니다.
- SurfaceCrawler는 연결된 정적 Geometry를 지원하며 Arbitrary-surface Path Planning과 Moving Platform은 지원하지 않습니다.
- `ACharacter`의 Capsule/CharacterMovement 전제를 유지합니다. Collision ON Reference Geometry는 검증했지만 복잡한
  Concave Corner, 좁은 통로, Dynamic Obstacle, 임의 Capsule Orientation은 프로젝트별 PIE 검증이 필요합니다.
  완전한 Arbitrary-surface Collision이 필요하다면 Custom Pawn/Movement 구현을 권장합니다.
- Crawler는 Placeholder Presentation을 사용합니다. Production AnimBP, Root-motion 정책, Leg IK, Corner 시각 보정은
  포함하지 않습니다. 공통 Animation Data Provider는 있지만 Montage/Sequence는 제공하지 않습니다.
- 위치 변화 기반 Velocity Fallback을 사용하므로 외부 Teleport 직후 Animation Speed가 일시적으로 크게 보일 수 있습니다.
- Audio Event Contract는 연결되어 있지만 고품질 Sound와 Mixing은 프로젝트 Content의 책임입니다.
- 기존 `AJMDungeonMonster`, Listener/Hoarder/Blackout 구현은 Migration하지 않았습니다.

## 향후 확장

실제 프로젝트 요구가 생길 때 Flying Locomotion, 고급 Target Selection/EQS, Multiplayer Replication,
Gameplay Debugger 연동, 확장된 Editor Tooling을 고려합니다. Rule Layer는 초기 설계 후보였지만 Listener, Watcher,
Crawler를 StateTree만으로 표현할 수 있었습니다. 실제 전역 제약이 StateTree로 깔끔하게 표현되지 않을 때만
`UJMEnemyRule`/Rule Component를 추가합니다.

## Migration 전략

기존 AI는 한 번에 하나씩 Migration합니다. 행동을 분석하고 Sense/Movement/Action으로 분리한 뒤 Definition과
StateTree를 구성합니다. 기존 Enemy와 새 Framework Enemy를 병렬 검증한 다음 기존 구현 제거 여부를 결정합니다.
전체 Legacy AI를 한 번에 교체하지 않습니다.
