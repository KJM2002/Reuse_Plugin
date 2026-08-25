# JM 재사용형 Unreal 플러그인 개발 기준서

> 문서 버전: 1.0.0  
> 기준 프로젝트: Unreal Engine 5.7 / C++  
> 적용 범위: 이 파일이 들어 있는 `Plugins` 폴더와 모든 하위 플러그인  
> 목적: 새 시스템·에셋 플러그인을 추가할 때 이 문서 하나만으로 기존 시스템과 안전하게 연동하고, 프로젝트 종속성과 순환 의존성을 방지한다.

## 0. Codex가 반드시 지킬 작업 방식

이 문서는 설명 자료이면서 구현 지침이다. `Plugins` 아래를 수정하는 Codex/개발자는 다음 순서를 지킨다.

1. 요청만 보고 바로 구현하지 말고, 먼저 이 문서와 대상 플러그인의 `.uplugin`, `Build.cs`, `Public`, `Docs`를 확인한다.
2. 기존 공개 API로 해결 가능한지 검색한다. 같은 역할의 인터페이스·컴포넌트·Subsystem·구조체를 중복 생성하지 않는다.
3. 작업 전에 변경 대상, 새 의존성, 데이터 소유자, 런타임 수명, 실패 시 동작을 짧게 정리한다.
4. 새 플러그인은 기본적으로 독립 실행 가능하게 만든다. 다른 JM 플러그인 연동은 별도 Integration/Bridge 계층으로 격리한다.
5. 코드, 설정, 콘텐츠, 문서, 테스트를 하나의 플러그인 폴더 안에서 완결한다.
6. 매 단계 컴파일 가능한 상태를 유지하고, 마지막에 전체 프로젝트 Editor 빌드와 관련 자동화 테스트를 실행한다.
7. 구현 결과에는 변경 파일, 의존성 변화, 사용법, 검증 결과, 남은 제한을 보고한다.

요청이 기존 구조와 충돌하면 조용히 우회하지 말고 충돌 지점과 호환 가능한 선택지를 먼저 제시한다. 기존 공개 API나 저장 데이터 형식을 깨는 변경은 명시적 승인 없이 하지 않는다.

---

## 1. 최종 제품 원칙

새 프로젝트에서 아래 흐름만으로 사용할 수 있어야 한다.

```text
필요한 플러그인 폴더 복사
→ 플러그인 활성화
→ Project Settings 설정
→ 필요한 Component/Subsystem/API 연결
→ Data Asset·Blueprint·에셋 지정
→ 실행
```

플러그인은 호스트 프로젝트의 특정 Character, PlayerController, GameMode, HUD, AIController, BehaviorTree, Level Blueprint, 레벨 이름 또는 `/Game/...` 콘텐츠에 의존하지 않는다.

핵심 동작은 C++ Runtime 계층에 둔다. Blueprint는 시각적 구성, 에셋 지정, 연출, 게임별 조건과 확장 이벤트를 담당한다. 게임마다 달라지는 값은 Data Asset, Developer Settings, Gameplay Tag, String Table, Data Table 또는 Soft Reference로 분리한다.

---

## 2. 현재 플러그인 레지스트리와 실제 의존성

새 작업을 시작할 때 이 표를 실제 `.uplugin`과 `Build.cs`에 맞게 갱신한다. 문서와 코드가 다르면 코드가 현재 사실이며, 차이를 작업 결과에 기록하고 문서를 함께 수정한다.

| 플러그인 | 모듈 | 현재 책임 | 직접 JM 의존성 | 상태 |
|---|---|---|---|---|
| `JMGameplayEvent` | `JMGameplayEvent`, `JMGameplayEventTests` | Gameplay Tag 기반 로컬 이벤트 버스, Blueprint 발행/수신, Payload 기반 계약 | 없음 | 독립 Runtime + Editor Tests |
| `JMInteraction` | `JMInteraction` | 공통 탐색, Focus, Prompt UI, 상호작용 계약/실행 | `JMGameplayEvent` | 독립 Runtime, Content 가능 |
| `ItemInspector` | `ItemInspectorRuntime`, `ItemInspectorTests` | 아이템 조사, 회전 가능한 표면 UMG 콘텐츠, 관련 UI/설정 | `JMInteraction` | Runtime + Editor Tests, Content 포함 |
| `InventorySystem` | `InventorySystem` | 인벤토리, 월드 Pickup, UI, 조사 연동 | `JMInteraction`, `ItemInspector`, `JMGameplayEvent` | Runtime, Content 포함 |
| `ReusableDialogueSystem` | `ReusableDialogueSystem` | 대사 재생, 타이핑/음성/UI, 상호작용 연동 | `JMInteraction`, `JMGameplayEvent` | Runtime, Content 포함 |
| `JMDoor` | `JMDoorRuntime`, `JMDoorTests` | 문 상태, 이동, 접근, 내구도, 장애물, 저장 계약과 샘플 | `JMGameplayEvent` | Runtime + Editor Tests, Content 포함 |
| `JMDoorGameplayIntegration` | `JMDoorGameplayIntegration` | Door-Interaction-Inventory 선택 연동과 잠긴 문 아이템 사용 흐름 | `JMDoor`, `JMInteraction`, `InventorySystem` | Runtime Bridge |
| `JMJumpScare` | `JMJumpScare`, `JMJumpScareTests` | Data Asset·Trigger·Anchor 기반 점프스케어 실행, 카메라/입력 복원, 상태 이벤트 발행 | `JMGameplayEvent` | 독립 Runtime + Editor Tests |
| `JMRecon` | `JMReconRuntime`, `JMReconEditor`, `JMReconTests` | Listen·Peek·Illuminate 정찰 세션, Target 예약, 카메라/포즈 요청, 검증과 시각화 | 없음 | 독립 Runtime + Editor Tools/Tests |
| `JMReconGameplayIntegration` | `JMReconGameplayIntegration`, `JMReconGameplayIntegrationTests` | JMInteraction Focus를 Recon Target에 연결하고 로컬 입력·카메라·플레이어 상태 자동 관리 | `JMRecon`, `JMInteraction` | Runtime Bridge + Editor Tests |
| `JMDoorReconIntegration` | `JMDoorReconIntegration`, `JMDoorReconIntegrationTests` | Door와 Recon을 직접 결합하지 않고 세션 전용 문틈 Pose·상태 검증·복원을 제공 | `JMDoor`, `JMRecon` | Runtime Adapter + Editor Tests |
| `JMFootstep` | `JMFootstepRuntime`, `JMFootstepTests` | 실제 이동 거리, Physical Surface, Walk/Run/CrouchWalk Variant 기반 로컬 3D 발걸음 Audio | 없음 | 독립 Runtime + Editor Tests |
| `JMHide` | `JMHideRuntime`, `JMHideTests` | Session 기반 은신 Domain, Spot 예약/점유, Participant Driver, Simple Panel Mechanism | 없음 | 독립 Runtime + Editor Tests |
| `JMHideInteractionIntegration` | `JMHideInteractionIntegration` | JMInteraction 명령을 JMHide 진입으로 연결하고 호스트 입력 라우팅 지원 | `JMHide`, `JMInteraction` | Runtime Bridge |
| `JMHideDoorIntegration` | `JMHideDoorIntegration`, `JMHideDoorIntegrationTests` | JMDoor 공개 Command/상태를 JMHide Mechanism 계약으로 번역 | `JMHide`, `JMDoor` | Runtime Adapter + Editor Tests |
| `JMRoomGrid` | `JMRoomGridRuntime`, `JMRoomGridEditor`, `JMRoomGridTests` | 편집 가능한 모듈 방, 데이터 기반 결정적 5x5 배치, 에셋 생성·검증 도구 | 없음 | 독립 Runtime + Editor Tools/Tests, Content 가능 |
| `JMPhysicalGrabber` | `JMPhysicalGrabber`, `JMPhysicalGrabberTests` | 고정 힘 물리 그랩, 회수 가능 작살, 대상 소유형 장력/파손/추출/활성화/소음 반응 계약 | 없음(CableComponent 엔진 플러그인만 사용) | 독립 Runtime + Editor Tests |
| `JMMonsterFramework` | `JMMonsterFrameworkRuntime`, `JMMonsterFrameworkTests` | 자동 Possession, 플레이어 Sight, StateTree Chase, 마지막 관측 위치 조사 | 없음 | 독립 Runtime + Editor Tests, Content 포함 |

현재 허용된 방향은 다음뿐이다.

```text
InventorySystem ────────────> ItemInspector

JMDoor / InventorySystem / ReusableDialogueSystem / JMInteraction
                       └──> JMGameplayEvent ──> Unreal Engine 모듈

JMJumpScare ───────────────> JMGameplayEvent

JMRecon ───────────────────> Unreal Engine 모듈

JMFootstep ────────────────> Unreal Engine 모듈

JMPhysicalGrabber ─────────> Unreal Engine 모듈 / CableComponent

JMMonsterFramework ────────> Unreal Engine 모듈

JMHide ────────────────────> Unreal Engine 모듈

JMHideInteractionIntegration ─> JMHide
                             └> JMInteraction

JMHideDoorIntegration ────────> JMHide
                             └> JMDoor

JMReconGameplayIntegration ─> JMRecon
                           └> JMInteraction

JMDoorReconIntegration ─────> JMDoor
                           └> JMRecon
```

`ItemInspector`가 두 상위 기능을 참조하는 역방향 의존성은 금지한다. `InventorySystem`과 `ReusableDialogueSystem`이 서로 참조하는 것도 금지한다.

공통 Interaction API는 `JMInteraction`으로 추출되었다. 새 기능 플러그인은 `ItemInspectorRuntime`의 과거 Interaction 경로를 복제하지 말고 `JMInteraction`의 공개 계약을 사용한다. `Core/JMGameplayTypes.h`와 `Interaction/...` forwarding include는 기존 코드 호환용이며 새 코드는 `Types`, `Interfaces`, `Components`의 정식 경로를 우선한다.

---

## 3. 의존성 설계 규칙

### 3.1 계층과 방향

의존성은 아래 방향으로만 흐른다.

```text
호스트 게임 / 선택적 통합 플러그인
                    ↓
독립 기능 플러그인 (Inventory, Dialogue, Door, Save 등)
                    ↓
공통 계약 플러그인 (향후 Core/Interaction 추출 시)
                    ↓
Unreal Engine 모듈
```

- 하위 계층은 상위 계층의 구체 클래스를 알지 못한다.
- 같은 계층의 기능 플러그인끼리 직접 참조하지 않는다.
- 기능 조합은 소비자 쪽 Bridge, Adapter, Interface, Delegate로 연결한다.
- `.uplugin`의 `Plugins`와 `Build.cs`의 Module Dependency는 실제 코드 참조와 일치시킨다.
- Public 헤더에 노출되는 타입의 모듈만 Public Dependency로 둔다. 구현에서만 쓰는 모듈은 Private Dependency로 둔다.
- 다른 플러그인 의존성을 새로 추가하기 전, 인터페이스·Delegate·Gameplay Tag·Soft Class로 역전할 수 있는지 검토한다.
- 순환 의존성은 어떤 이유로도 허용하지 않는다.

### 3.2 연동 코드의 소유권

두 시스템 A와 B를 연결할 때 다음 기준을 사용한다.

- A가 B를 선택적으로 소비한다면 Bridge는 A 또는 별도 Integration 플러그인이 소유한다.
- 기반 제공자 B는 A를 참조하지 않는다.
- 연동이 없을 때 A의 핵심 기능이 정상 작동하거나 안전하게 비활성화되어야 한다.
- 양쪽을 모두 알아야 하는 큰 연동은 `JM<A><B>Integration` 같은 별도 Runtime 플러그인으로 분리한다.
- 연동 타입은 `Public/Integration`과 `Private/Integration`에 두고 핵심 도메인 코드와 분리한다.

현재 예시는 다음과 같다.

- `UReuseDialogueInteractableComponent`: Dialogue가 JMInteraction을 소비하므로 Dialogue 소유
- `UReuseInventoryInspectorBridge`, `AReuseInspectableInventoryPickup`: Inventory가 Inspector를 소비하므로 Inventory 소유

### 3.3 플러그인 하나만 복사할 수 있는가

각 플러그인의 README/Docs에는 반드시 아래를 명시한다.

- 필수 플러그인과 Engine 플러그인
- 선택 플러그인
- 단독 설치 시 사용할 수 있는 기능
- 연동 플러그인이 없을 때의 안전한 동작
- 함께 복사해야 하는 최소 폴더 집합

필수 의존성이 있는 플러그인은 대상 플러그인 폴더까지 함께 묶어야 한다. 누락 시 빌드가 실패하는 구조라면 “선택 의존성”이라고 표현하지 않는다.

---

## 4. 플러그인 유형 선택

### 4.1 Runtime 시스템 플러그인

게임 실행에 필요한 C++ 로직, 설정, Blueprint, Data Asset과 기본 리소스를 포함한다.

```text
Plugins/<PluginName>/
├─ <PluginName>.uplugin
├─ Source/
│  └─ <RuntimeModule>/
│     ├─ <RuntimeModule>.Build.cs
│     ├─ Public/
│     └─ Private/
├─ Content/
├─ Config/
└─ Docs/
```

에디터 전용 도구가 필요하면 Runtime 모듈에 `UnrealEd` 등을 넣지 말고 별도 Editor 모듈로 분리한다. Runtime 모듈은 Shipping 타깃에서 컴파일 가능해야 한다.

### 4.2 Content-only 에셋 플러그인

코드가 전혀 필요하지 않은 재사용 에셋 묶음은 `CanContainContent: true`인 Content-only 플러그인으로 만든다.

```text
Plugins/<AssetPackName>/
├─ <AssetPackName>.uplugin
├─ Content/
│  ├─ Art/
│  ├─ Audio/
│  ├─ UI/
│  ├─ Data/
│  └─ Demo/       # 선택
├─ Config/        # 꼭 필요할 때만
└─ Docs/
```

- 모든 내부 참조는 `/PluginMountPoint/...` 안에서 완결한다.
- `/Game/...` 에셋을 참조하지 않는다.
- 외부 Marketplace/Engine 콘텐츠가 필요하면 라이선스와 필수 의존성을 문서화한다.
- Demo 에셋은 런타임 필수 에셋과 폴더를 분리한다.
- Source 원본(PSD, WAV master 등)을 배포할지 여부와 라이선스를 명시한다.

### 4.3 시스템과 대형 에셋의 분리

코드 시스템이 특정 테마의 대형 에셋에 강제 의존하지 않게 한다. 기본 최소 UI/아이콘/테스트 에셋만 시스템 플러그인에 두고, 대형 아트·사운드 팩은 별도 Content 플러그인으로 분리해 Soft Reference 또는 Data Asset으로 연결한다.

---

## 5. 공개 API와 결합 경계

기능 연결은 우선순위에 따라 다음을 사용한다.

1. Unreal Interface: 기능 제공 여부와 명령/질의 계약
2. Actor Component: Actor에 조합 가능한 상태와 동작
3. Subsystem: 명확한 World/GameInstance/LocalPlayer 수명의 서비스
4. Delegate/Event Dispatcher: 발행자가 소비자를 몰라야 하는 이벤트
5. Gameplay Tag: 시스템 간 의미 식별자와 능력/조건
6. Data Asset/Developer Settings: 게임별 구성
7. Soft Object/Class Reference: 선택 콘텐츠와 지연 로딩

구체 클래스로의 Cast는 같은 플러그인 내부 구현에 한정한다. 외부 Character, Controller, HUD, Inventory, AI 클래스 Cast는 금지한다.

Public API 규칙:

- 외부에서 필요한 최소 타입만 `Public`에 둔다.
- 모든 외부 사용 `UCLASS`, `USTRUCT`, 함수에는 올바른 Module API 매크로를 적용한다.
- Public 헤더는 최소 include와 전방 선언을 사용한다.
- UPROPERTY UObject 참조는 GC 안전 타입을 사용하고, 수명이 불확실한 대상은 Weak Reference를 검토한다.
- Blueprint 노출은 실제 제작 흐름에 필요한 것만 허용하고 캡슐화를 유지한다.
- 결과는 단순 `bool`만 반환하지 말고 호출자가 대응해야 한다면 성공 여부, 실패 이유, 메시지/태그를 담는 Result 타입을 사용한다.
- Delegate 호출 순서, Thread/Game Thread 전제, Authority 전제를 문서화한다.
- 외부에서 저장하거나 참조하는 ID는 표시 이름이나 배열 인덱스가 아닌 안정적인 ID를 사용한다.

---

## 6. 데이터·에셋 참조 규칙

하드코딩 금지 대상:

- `/Game/...` 및 특정 프로젝트 콘텐츠 경로
- 특정 플레이어/위젯/입력 클래스
- 충돌 채널의 임의 숫자 값
- 문구, 키 이름, 에셋 경로, 밸런스 값
- 레벨 이름과 배치 Actor 이름

권장 참조:

```cpp
TSoftObjectPtr<UObjectType>
TSoftClassPtr<UClassType>
FPrimaryAssetId
FGameplayTag
FText
```

- 플러그인 기본 에셋 경로가 필요하면 해당 플러그인 Mount Point만 사용한다.
- CDO 생성자에서 무거운 에셋을 강제 동기 로드하지 않는다.
- 즉시 필요한 작은 UI 기본값은 동기 로드가 허용되지만 이유와 실패 동작을 기록한다.
- 큰 메쉬, 사운드, 시퀀스는 비동기 로드를 우선 검토한다.
- Soft Reference가 비어 있거나 로드에 실패해도 Crash하지 않고 경고 후 기본값/기능 비활성화로 처리한다.
- `FText`를 사용해 로컬라이징 가능성을 유지한다. 사용자 표시 문자열에 `FString` 하드코딩을 사용하지 않는다.
- 플러그인 콘텐츠는 Asset Registry 기준으로 `/Game` 참조가 없어야 한다.

---

## 7. 수명, UI, 입력, 네트워크

Subsystem은 편의가 아니라 수명에 맞춰 선택한다.

- `UEngineSubsystem`: 엔진 프로세스 범위가 정말 필요할 때만
- `UGameInstanceSubsystem`: 레벨 전환을 넘어 유지되는 게임 세션 서비스
- `UWorldSubsystem`: World별 서비스와 월드 이벤트
- `ULocalPlayerSubsystem`: 로컬 플레이어별 UI·입력·Cosmetic 상태

UI와 입력 규칙:

- 특정 HUD에 의존하지 않는다.
- Widget C++ Base/Presenter와 게임별 WBP 디자인을 분리한다.
- Dedicated Server 또는 Headless 환경에서 UI 코드가 안전하게 빠져야 한다.
- 입력 Mapping Context를 무조건 전역 적용하지 않는다.
- 입력 모드, 커서, Pause, 이동/시점 차단을 변경했다면 이전 상태를 저장하고 모든 종료 경로에서 복구한다.
- 상시 Tick 대신 Delegate, Timer, 명시적 갱신을 우선한다.

네트워크 규칙:

- 서버 권한 상태와 로컬 Cosmetic 상태를 구분한다.
- 싱글플레이 전용이면 문서와 API 주석에 명시한다.
- 클라이언트가 인벤토리/문/퀘스트 상태를 직접 확정하는 구조를 멀티플레이 지원이라고 표현하지 않는다.
- Replication/RPC를 나중에 추가할 수 있도록 UI가 내부 배열이나 상태를 직접 변경하지 않게 한다.

---

## 8. 설정, Gameplay Tag, 저장 계약

### Developer Settings

플러그인별 `UDeveloperSettings`를 제공하고 설정이 비어 있어도 안전해야 한다. 프로젝트의 `DefaultGame.ini` 복사를 강제하지 않도록 플러그인의 `Config/Default<Plugin>.ini`와 안전한 코드 기본값을 사용한다.

### Gameplay Tag

- 태그는 의미 계약이며 문자열 비교 대용으로 임의 생성하지 않는다.
- 소유 플러그인이 태그 계층과 의미를 문서화한다.
- 공통 태그는 향후 Core가 소유하고 기능 전용 태그는 해당 기능 플러그인이 소유한다.
- 태그 이름 변경은 데이터 마이그레이션이 필요한 Breaking Change다.

권장 최상위 예:

```text
JM.Interaction.*
JM.Item.*
JM.Inventory.*
JM.Dialogue.*
JM.Access.*
JM.Noise.*
JM.Door.*
JM.Save.*
```

### 저장

- 기능 플러그인은 특정 프로젝트 SaveGame 클래스에 직접 의존하지 않는다.
- 안정적인 Persistent ID와 Save Record 구조 또는 Saveable Interface를 공개한다.
- UObject 포인터, 표시 이름, 배열 인덱스를 영속 ID로 저장하지 않는다.
- 저장 구조 변경 시 버전 필드와 이전 버전 마이그레이션/거부 정책을 둔다.

---

## 9. 명명, 버전, 호환성

- 새 공개 타입은 프로젝트 전체에서 충돌하지 않는 `JM` 또는 플러그인 고유 접두사를 사용한다.
- 플러그인 폴더, `.uplugin` 이름, Module 이름, API 매크로의 대응을 명확히 유지한다.
- `Version`은 정수로 증가시키고 `VersionName`은 Semantic Versioning(`MAJOR.MINOR.PATCH`)을 사용한다.
- PATCH: 호환 버그 수정, MINOR: 호환 기능 추가, MAJOR: 공개 API/데이터/에셋 경로 Breaking Change.
- 공개 클래스/함수/프로퍼티, Gameplay Tag, Config 키, 에셋 경로 변경은 호환성 검토 대상이다.
- 에셋 이동/이름 변경 시 Redirector 정리와 Core Redirect 또는 명시적 마이그레이션을 검토한다.
- 각 플러그인의 `Docs/CHANGELOG.md`에 Added/Changed/Fixed/Breaking을 기록한다.

### Plugin 문서 구조와 현재성

Plugin 문서는 다음 구조를 사용한다. 빈 분류 폴더는 만들지 않는다.

```text
<Plugin>/
├─ README.md                    # 선택: 저장소·Marketplace 진입점
└─ Docs/
   ├─ README.md 또는 README_KO.md
   ├─ ARCHITECTURE.md 또는 ARCHITECTURE_KO.md
   ├─ CHANGELOG.md
   ├─ Guides/                   # 설치·사용·저작·Migration 절차
   ├─ Reference/                # API·Tag·Config·Save·정책 계약
   ├─ Testing/                  # 자동화·Editor·회귀 테스트
   ├─ Plans/                    # 미구현 계획과 TODO
   ├─ Decisions/                # 장기 설계 결정(ADR)
   └─ Archive/                  # 대체·종료된 역사 문서
```

- 모든 Plugin Markdown은 `title`, `status`, `authority`, `scope`, `owners` YAML 메타데이터를 가진다. 이 실행 지침인 `Plugins/AGENTS.md`만 예외다.
- 상태는 `Current`, `Draft`, `ReviewRequired`, `Superseded`, `Archived`만 사용한다.
- 코드·설정 문서를 `Current`로 올릴 때는 `last_verified`와 검증한 commit 또는 working-tree 기준을 기록한다.
- Editor 가이드는 실제 절차를 다시 수행한 경우에만 `Current`로 올린다.
- 분류만 했거나 코드·에셋과 재검증하지 않은 기존 문서는 `ReviewRequired`로 둔다.
- 계획과 TODO는 `Draft/Plan`, 과거 기록은 `Archived/Historical`로 현재 구현과 구분한다.
- 문서를 추가·이동·대체하면 대상 Plugin README의 `문서 지도`와 `Plugins/DOCUMENTATION_INDEX.md`를 같은 변경에서 갱신한다.
- 완료 전에 프로젝트 루트에서 `Docs/Tools/Validate-Docs.ps1`을 실행해 메타데이터와 상대 링크를 검사한다.
- 세부 상태 전환과 Archive 규칙은 `Docs/DOCUMENTATION_POLICY.md`를 따른다.

---

## 10. 새 플러그인 구현 절차

### 단계 A — 기존 구조 조사

- `Plugins/*/*.uplugin`로 플러그인과 필수 의존성을 확인한다.
- 모든 `Build.cs`로 실제 모듈 의존성을 확인한다.
- 기존 `Public` API에서 재사용 가능한 계약을 찾는다.
- 같은 이름/역할의 Gameplay Tag, Settings, Result, Context, Interface가 있는지 검색한다.
- 대상 Engine 버전과 빌드 타깃을 확인한다.

### 단계 B — 설계 기록

구현 전에 대상 플러그인의 `Docs/ARCHITECTURE.md`에 최소한 다음을 작성한다.

- 책임과 비책임
- 모듈과 폴더 구조
- 의존성 방향
- 주요 데이터 흐름과 상태 전이
- Subsystem/Component 수명 선택 이유
- Public API와 Integration 경계
- Soft Reference 로딩 정책
- 네트워크 및 저장 범위
- 실패 시 안전 동작

### 단계 C — 작은 단위 구현

1. `.uplugin`, Module, `Build.cs`
2. 로그, 타입, Interface와 데이터 계약
3. 핵심 Runtime 로직
4. Integration/Bridge
5. Settings와 기본값
6. Blueprint 확장 지점
7. Content와 예제
8. 자동화 테스트와 문서

각 단계 후 컴파일 오류를 다음 단계로 넘기지 않는다.

### 단계 D — 완료 조건

아래 체크리스트가 모두 충족되어야 완료다.

- [ ] 호스트 프로젝트 `Source` 없이 플러그인 폴더만으로 컴파일된다.
- [ ] `.uplugin`과 `Build.cs` 의존성이 일치하고 순환이 없다.
- [ ] 프로젝트 전용 클래스와 `/Game/...` 참조가 없다.
- [ ] 설정/에셋 누락과 잘못된 입력에서 Crash하지 않는다.
- [ ] Public 헤더와 API 매크로가 다른 모듈 소비를 지원한다.
- [ ] Runtime 모듈에 Editor-only 의존성이 없다.
- [ ] UI/입력 상태가 취소, 실패, 파괴, 레벨 전환 경로에서도 복구된다.
- [ ] 관련 자동화 테스트와 Editor Development 전체 빌드가 통과한다.
- [ ] 플러그인 Content의 외부 참조를 검사했다.
- [ ] README, ARCHITECTURE, 설치/사용법, CHANGELOG를 갱신했다.
- [ ] 새 Blueprint 사용 흐름을 C++ 지식 없이 따라 할 수 있다.

---

## 11. 필수 테스트 기준

최소 테스트 범위:

- 정상 경로
- null/미설정 에셋과 잘못된 데이터
- 중복 요청, 취소, 대상 파괴, 레벨 전환
- 경계값(0, 빈 배열, 최대 슬롯/길이 등)
- 두 시스템 Bridge의 성공/실패
- 재진입과 상태 복구
- 가능한 경우 Dedicated Server/Non-UI 안전성

권장 검증 순서:

```text
정적 검색(금지 참조·의존성)
→ 관련 Automation Test
→ Editor Development 전체 빌드
→ 에디터 수동 Smoke Test
→ 패키징/Shipping 검증(릴리스 시 필수)
→ 깨끗한 빈 프로젝트에 플러그인 복사 테스트(릴리스 시 필수)
```

자동화 테스트 이름은 플러그인별 접두사를 사용한다. 예: `JM.Inventory.*`, `JM.Dialogue.*`.

---

## 12. 휴대용 압축·배포 규칙

배포 단위에는 다음을 포함한다.

```text
<Plugin>/
├─ <Plugin>.uplugin
├─ Source/      # 코드 플러그인
├─ Content/     # 콘텐츠가 있을 때
├─ Config/      # 설정이 있을 때
└─ Docs/
```

기본 제외 대상:

```text
Binaries/
Intermediate/
Saved/
DerivedDataCache/
.vs/
IDE 사용자 파일
크래시 로그
```

다른 프로젝트로 옮길 때는 대상 Unreal Engine 버전에서 프로젝트 파일을 재생성하고 다시 빌드한다. 사전 빌드 바이너리를 배포한다면 Engine 버전, 플랫폼, Configuration 호환 범위를 별도로 명시한다.

번들 릴리스 전 확인:

- 필수 플러그인 폴더가 모두 포함되었는가
- 각 플러그인의 Mount Point 내부 참조가 유효한가
- `/Game` 또는 개발 프로젝트 `Source` 참조가 없는가
- Redirector와 누락 에셋이 없는가
- 라이선스/출처 파일이 필요한 에셋에 포함되었는가
- 압축 해제 후 빈 C++ 프로젝트에서 빌드·실행되는가

---

## 13. 금지 패턴

```cpp
Cast<AMyProjectCharacter>(...);
Cast<AMyProjectGameMode>(...);
LoadObject<UObject>(nullptr, TEXT("/Game/SpecificProject/..."));
UGameplayStatics::GetActorOfClass(World, ASpecificSingletonActor::StaticClass());
```

다음 설계도 금지한다.

- Level Blueprint가 있어야 핵심 기능이 시작되는 구조
- 다른 기능 플러그인의 Private 헤더 include
- 형제 플러그인끼리 상호 참조
- UI Blueprint에만 존재하는 핵심 상태·저장 규칙
- 여러 bool로 서로 모순되는 상태 표현
- 모든 Actor/Component의 무조건 Tick
- Settings 누락 시 `check()`로 에디터/게임 종료
- 플러그인 Content가 호스트 `/Game` 에셋을 강제 참조
- Integration 편의를 이유로 기반 플러그인에 상위 시스템 지식 추가
- 테스트 없이 공개 에셋 경로, Tag, Save 구조 또는 Blueprint API 변경

---

## 14. 새 시스템 요청 시 사용할 최소 프롬프트

이 문서가 프로젝트에 있으면 사용자는 긴 공통 설명을 반복하지 않고 아래 정도만 요청하면 된다.

```text
Plugins/AGENTS.md 기준으로 <시스템 이름> Runtime Plugin을 설계·구현해줘.

목표 기능:
- <기능 1>
- <기능 2>

기존 <플러그인/API>와 연동하되 직접 결합은 최소화하고,
설계 문서·테스트·전체 빌드·휴대용 설치 문서까지 완료해줘.
```

에셋 팩은 다음처럼 요청한다.

```text
Plugins/AGENTS.md 기준으로 <에셋 팩 이름> Content Plugin을 구성해줘.
모든 참조를 플러그인 내부에 닫고, 시스템 플러그인과는 Data Asset/Soft Reference로 연결하며,
압축 배포 검증과 라이선스 문서까지 정리해줘.
```

---

## 15. 이 문서의 유지 규칙

다음 변경이 생기면 같은 작업에서 이 문서를 반드시 갱신한다.

- 플러그인 추가/삭제/이름 변경
- Module 이름 또는 의존성 방향 변경
- 공통 Core/Interaction 플러그인 추출
- 지원 Unreal Engine 버전 변경
- 배포 구조 또는 버전 정책 변경
- 프로젝트 전체가 따라야 할 새로운 Gameplay Tag/Save/API 계약 추가

개별 플러그인의 세부 구현은 각 `Docs`에 기록하고, 이 문서에는 전체 생태계의 계약과 현재 의존성만 유지한다. 이 문서와 개별 문서가 충돌하면 안전을 위해 실제 코드와 빌드 설정을 재검사한 뒤 둘을 함께 바로잡는다.
