---
title: "JM 재사용 시스템 개발 컨텍스트"
status: ReviewRequired
authority: Plan
scope: "Plugin Ecosystem"
classified_on: 2026-08-19
owners:
  - "Plugin Architecture"
review_reason: "2026-08-19 아키텍처 감사에서 Plugin 레지스트리와 버전 드리프트가 확인됨"
---

# JM 재사용 시스템 개발 컨텍스트

> 문서 목적: 이 파일 하나를 AI에게 제공해, 앞으로 추가할 Unreal Engine 시스템의 시스템 프롬프트·설계안·구현 계획을 만들 수 있게 한다.  
> 기준 저장소: `P_060715`, Unreal Engine 5.7, C++20 계열 툴체인  
> 기준 시점: 2026-07-26  
> 범위: `Plugins` 아래의 재사용형 Runtime, Editor/Test, Integration, Content 자산  
> 주의: 이 문서는 기존 문서를 단순 병합한 것이 아니다. `.uplugin`, `Build.cs`, Public 헤더와 최신 아키텍처 문서를 대조해 일반화한 개발 컨텍스트다.

---

## 1. 이 문서를 AI가 해석하는 방법

이 문서에는 세 종류의 정보가 섞이지 않도록 구분되어 있다.

- **현재 사실**: 지금 저장소의 `.uplugin`, `Build.cs`, Public API에서 확인한 구조
- **설계 규칙**: 새 시스템에도 계속 적용할 재사용성·안전성 원칙
- **알려진 부채**: 기존 문서 또는 구현의 불일치, 제한, 후속 과제

새 시스템을 설계할 때 우선순위는 다음과 같다.

```text
실제 .uplugin / Build.cs / Public API / Config
→ 대상 플러그인의 최신 ARCHITECTURE와 CHANGELOG
→ 이 통합 컨텍스트
→ 과거 계획서, TODO, 사용 가이드와 주석
```

문서와 코드가 다르면 코드를 현재 사실로 취급한다. 다만 코드가 곧 올바른 목표 설계라는 뜻은 아니다. 불일치를 발견하면 현재 동작, 목표 구조, 호환성 비용을 분리해 보고한다.

AI는 요청을 받자마자 구현하지 말고 먼저 아래 다섯 문장을 채워야 한다.

1. 이 시스템이 **소유하는 것**
2. 이 시스템이 **소유하지 않는 것**
3. 필수 의존성과 선택 Integration
4. 상태와 데이터의 소유자 및 런타임 수명
5. 설정·에셋·대상 누락, 취소, 파괴 시 안전 동작

---

## 2. 제품 수준의 최종 목표

재사용 플러그인은 새 프로젝트에서 다음 흐름만으로 사용할 수 있어야 한다.

```text
필요한 플러그인 폴더 복사
→ 플러그인 활성화
→ Project Settings 확인
→ 필요한 Component / Subsystem / API 연결
→ Data Asset·Blueprint·에셋 지정
→ 실행
```

플러그인 폴더 하나 또는 문서화된 최소 의존 플러그인 묶음이 제품 단위다. 호스트 프로젝트의 `Source`, 특정 Character, PlayerController, GameMode, HUD, AIController, BehaviorTree, Level Blueprint, 레벨 이름, 배치 Actor 이름, `/Game/...` 콘텐츠가 없더라도 컴파일되어야 한다.

핵심 규칙:

- 핵심 상태와 규칙은 C++ Runtime 계층에 둔다.
- Blueprint는 시각 구성, 에셋 지정, 게임별 조건, 연출과 확장 이벤트를 담당한다.
- 게임마다 달라지는 값은 Data Asset, Developer Settings, Gameplay Tag, String Table/Data Table 또는 Soft Reference로 분리한다.
- 필수 에셋이 아닌 요소가 없을 때는 Crash가 아니라 기능 축소, 안전한 기본값, 명확한 실패 결과를 제공한다.
- 다른 프로젝트로 옮길 때 `Source`, `Content`, `Config`, `Docs`, `.uplugin`만으로 재구성할 수 있어야 한다.

---

## 3. 현재 플러그인 생태계

### 3.1 현재 레지스트리

| 플러그인 | 버전 | Runtime 책임 | 직접 플러그인 의존성 |
|---|---:|---|---|
| `JMGameplayEvent` | 1.1.0 | Gameplay Tag 기반 GameInstance 로컬 이벤트 버스 | 없음 |
| `JMInteraction` | 1.1.1 | 탐색, Focus, Prompt, 상호작용 요청/실행 계약 | `JMGameplayEvent` |
| `ItemInspector` | 0.5.0 | 로컬 플레이어 단위 아이템 조사, 3D Preview, 표면 UMG | `JMInteraction`, `JMGameplayEvent` |
| `InventorySystem` | 0.5.0 | 스택형 인벤토리, Pickup, UI, 사용/버리기, 조사 연동 | `JMGameplayEvent`, `JMInteraction`, `ItemInspector` |
| `ReusableDialogueSystem` | 0.2.1 | 대사 상태 머신, 타이핑, 음성, UI, 상호작용 진입점 | `JMGameplayEvent`, `JMInteraction` |
| `JMDoor` | 1.6.0 | 문 상태, 이동, 접근, 장애물, 내구도, 저장 계약 | `JMGameplayEvent` |
| `JMDoorGameplayIntegration` | 1.1.0 | Door + Interaction + Inventory 조합 | `JMDoor`, `JMInteraction`, `InventorySystem` |
| `JMJumpScare` | 2.0.0 | 로컬 2D 점프스케어 재생, Trigger, Event 연동 | `JMGameplayEvent` |
| `JMObjective` | 1.1.1 | 이벤트 기반 Objective, 선형 Flow, 로컬 UI, 저장 데이터 | `JMGameplayEvent` |
| `JMRecon` | 1.1.0 | Listen/Peek/Illuminate 정찰 세션과 Target 계약 | 없음 |
| `JMReconGameplayIntegration` | 1.1.0 | Interaction Focus를 Recon에 연결, 입력·카메라·Prompt 복구 | `JMRecon`, `JMInteraction` |
| `JMDoorReconIntegration` | 1.0.0 | Recon 세션 동안만 Door 문짝 Pose를 임시 조정 | `JMDoor`, `JMRecon` |
| `JMFootstep` | 1.1.0 | 실제 이동 거리, Physical Surface, Walk/Run/CrouchWalk Variant 기반 로컬 3D 발걸음 Audio | 없음 |

모든 위 의존성은 실제 `.uplugin`과 Runtime `Build.cs`를 기준으로 작성했다. Engine 플러그인과 Engine 모듈 의존성은 표에서 생략했다.

### 3.2 현재 의존 방향

```text
JMGameplayEvent
├─ JMInteraction
│  ├─ ItemInspector
│  │  └─ InventorySystem
│  │     └─ JMDoorGameplayIntegration
│  ├─ ReusableDialogueSystem
│  ├─ JMReconGameplayIntegration
│  └─ JMDoorGameplayIntegration
├─ JMDoor
│  ├─ JMDoorGameplayIntegration
│  └─ JMDoorReconIntegration
├─ JMJumpScare
└─ JMObjective

JMRecon
├─ JMReconGameplayIntegration
└─ JMDoorReconIntegration

JMFootstep
└─ Unreal Engine Runtime 모듈
```

화살표를 “소비자가 제공자에게 의존한다”는 의미로 읽으면 된다. `JMDoorGameplayIntegration`은 `InventorySystem`을 통해 `ItemInspector`와 `JMGameplayEvent`에도 간접 의존한다.

### 3.3 계층 분류

```text
호스트 게임
  ↓
Integration / Adapter 플러그인
  ↓
독립 기능 플러그인
  ↓
공통 계약·메시지 플러그인
  ↓
Unreal Engine Runtime 모듈
```

- 공통 기반: `JMGameplayEvent`, `JMInteraction`
- 독립 도메인: `JMDoor`, `JMRecon`, `JMObjective`, `JMJumpScare`, `JMFootstep`, Dialogue, Inspector, Inventory
- 조합 계층: `JMDoorGameplayIntegration`, `JMReconGameplayIntegration`, `JMDoorReconIntegration`
- Editor/Test 계층: `*Editor`, `*Tests`; Shipping Runtime에 들어가면 안 된다.

---

## 4. 절대 지켜야 할 아키텍처 규칙

### 4.1 책임 경계를 먼저 만든다

기능 이름이 비슷하다는 이유로 모든 관련 동작을 한 플러그인에 넣지 않는다.

예를 들어 Door 코어는 문 상태와 명령을 소유하지만 다음은 소유하지 않는다.

- 플레이어가 E 키를 눌렀는지
- Interaction Prompt를 어떻게 그리는지
- 열쇠가 어느 Inventory Slot에 있는지
- SaveGame 슬롯 파일을 어디에 쓰는지
- AI가 어떤 Behavior Tree를 쓰는지

좋은 구조:

```text
여러 진입점(Interaction / AI / Script / Test / Network Command)
                         ↓
                  도메인 공개 API
                         ↓
                 도메인 상태와 규칙
```

실제 기능을 `CompleteInteract`, Widget 클릭 이벤트, Level Blueprint에만 넣지 않는다.

### 4.2 의존성은 아래로만 흐른다

- 하위 기반은 자신을 소비하는 상위 기능을 모른다.
- 같은 계층의 큰 기능 플러그인끼리 서로 참조하지 않는다.
- 두 시스템을 모두 알아야 하는 코드는 소비자 내부의 작은 `Integration` 폴더 또는 별도 Integration 플러그인에 둔다.
- 순환 의존성은 금지한다.
- 기반 플러그인에 편의를 위한 상위 시스템 Cast, Include, Asset 경로를 추가하지 않는다.

Integration을 별도 플러그인으로 만들 조건:

- 두 개 이상의 독립 플러그인을 동시에 알아야 한다.
- 코어를 각 시스템 없이도 사용할 가치가 있다.
- 연동 코드의 상태, 설정, 테스트 또는 배포 단위가 충분히 크다.

소비자 내부 `Integration` 폴더로 충분한 조건:

- A가 B를 명확하게 소비한다.
- 역방향 참조가 없다.
- 연결 코드가 작고 A의 제품 기능에 가깝다.

### 4.3 `.uplugin`과 `Build.cs`를 함께 관리한다

- `.uplugin`의 `Plugins`는 설치·활성화 의존성이다.
- `Build.cs`는 C++ 모듈 컴파일 의존성이다.
- 실제 참조가 있다면 두 선언이 함께 일치해야 한다.
- Public 헤더에 다른 모듈 타입이 노출되면 그 모듈은 Public Dependency다.
- `.cpp` 내부에서만 쓰고 Public 헤더에 노출되지 않을 때 Private Dependency를 검토한다.
- “선택 의존성”이라고 문서화했지만 Runtime `Build.cs`에 링크되어 있으면 실제로는 필수 의존성이다.

### 4.4 Runtime과 Editor를 분리한다

Runtime/Shipping 모듈에는 `UnrealEd`, `AssetTools`, `Kismet`, `PropertyEditor`, Editor Widget 코드를 넣지 않는다.

별도 Editor/Test 모듈에 둘 대상:

- Data Validation
- Component Visualizer
- Detail Customization
- 샘플 에셋 생성 Commandlet
- Functional/Automation Test
- Editor 전용 마이그레이션 도구

Runtime 모듈은 Shipping 타깃에서 컴파일 가능해야 한다.

### 4.5 상속보다 계약과 조합을 우선한다

외부 결합 수단의 기본 우선순위:

1. Unreal Interface: 기능 제공 여부와 명령/질의 계약
2. Actor Component: Actor에 조합할 상태와 동작
3. 수명에 맞는 Subsystem: World/GameInstance/LocalPlayer 서비스
4. Delegate: 직접 소유 관계 안의 변경 알림
5. Gameplay Event: 서로 몰라야 하는 여러 시스템에 완료 사실 전파
6. Gameplay Tag: 의미와 조건 식별
7. Data Asset / Developer Settings: 제작 데이터와 프로젝트 기본 정책
8. Soft Object/Class Reference: 선택 콘텐츠와 지연 로딩

구체 클래스 Cast는 같은 플러그인 내부 구현에 제한한다. 외부 Character, Controller, HUD, Inventory, AI 클래스 Cast는 금지한다.

---

## 5. 공개 API 설계 원칙

### 5.1 Command와 Event를 구분한다

Command는 동작을 요청하며 즉시 성공/실패가 필요하다.

```text
OpenDoor
AddItem
StartDialogue
TryStartRecon
```

Command는 직접 함수 또는 Interface를 사용한다.

Event는 이미 일어난 사실을 알린다.

```text
DoorOpened
ItemAcquired
DialogueFinished
ObjectiveCompleted
```

Event는 Delegate 또는 `JMGameplayEvent`를 사용한다. 이벤트 버스를 명령 버스로 사용하지 않는다. 호출 순서가 중요한 게임 규칙도 이벤트 구독 순서에 의존하지 않는다.

### 5.2 Context와 Result를 표준 패턴으로 사용한다

함수 인자가 늘어날 가능성이 있거나 여러 호출자가 같은 도메인 명령을 사용할 때 Context 구조체를 둔다.

Context 후보:

- Instigator Actor/Controller
- Target
- 위치와 방향
- 의미 Tag
- 세션 ID
- 권한/접근 Tag
- 요청 옵션

호출자가 실패에 대응해야 한다면 단순 `bool` 대신 Result 구조체를 제공한다.

Result 후보:

- `bSucceeded`
- 안정적인 Result Code 또는 Failure Tag
- 사용자 표시용 `FText`
- 실제 처리 수량 또는 남은 수량
- 생성된 세션/인스턴스 ID

실패를 로그에만 숨기지 않는다. 잘못된 요청은 상태를 반쯤 바꾸지 않은 채 Result로 거부한다.

### 5.3 Public API를 작고 안정적으로 유지한다

- 외부에 필요한 최소 타입만 `Public`에 둔다.
- 외부 사용 `UCLASS`, `USTRUCT`, 함수에는 Module API 매크로를 적용한다.
- Public 헤더는 최소 Include와 전방 선언을 사용한다.
- 외부가 내부 배열이나 상태 변수를 직접 수정하지 않게 한다.
- Blueprint 노출은 실제 제작 흐름에 필요한 것만 제공한다.
- Delegate 호출 순서, Game Thread 전제, Authority 전제를 문서화한다.
- 표시 이름이나 배열 인덱스를 외부 식별자로 사용하지 않는다.

### 5.4 호환성 표면을 넓게 본다

다음은 모두 공개 API다.

- C++ 클래스, 함수, Property, Enum, Struct
- Blueprint 노드와 `/Script/Module.Class` 경로
- 플러그인·모듈 이름
- Gameplay Tag
- Config 클래스와 섹션 키
- 콘텐츠 Mount Point와 에셋 경로
- Save 구조와 Persistent ID 의미

이름이나 경로 변경에는 Core Redirect, Deprecated API, 데이터 마이그레이션, Blueprint 리세이브 계획이 필요하다. 파일 탐색기로 `.uasset`을 임의 이동하지 않는다.

---

## 6. 상태, 수명, 정리 설계

### 6.1 Subsystem은 편의가 아니라 수명 선택이다

| 종류 | 적합한 책임 | 현재 사례 |
|---|---|---|
| `UGameInstanceSubsystem` | 레벨 전환을 넘어 같은 게임 세션 동안 유지 | Dialogue, Gameplay Event, Objective/Flow |
| `UWorldSubsystem` | World별 Actor 관찰, 자동 Adapter 부착 | Door/Recon Integration |
| `ULocalPlayerSubsystem` | 플레이어별 UI, 입력, Cosmetic 상태 | Item Inspector, Objective UI |
| Actor Component | Actor/Pawn별 상태와 명령 | Interaction, Inventory, Door, Recon Interactor/Target |

전역 Singleton 또는 `GetActorOfClass` 반복 검색을 수명 설계 대신 사용하지 않는다.

### 6.2 상태 머신을 문서로 먼저 쓴다

서로 모순될 수 있는 여러 bool 대신 명시적 Enum 상태와 전이를 둔다.

반드시 정의할 것:

- 초기 상태
- 정상 전이
- 중복/재진입 요청
- 취소
- 대상 파괴
- Component `EndPlay`
- World/Level 전환
- 설정/에셋 로드 실패
- 외부 상태가 세션 도중 바뀌는 경우

### 6.3 하나의 중앙 정리 경로를 만든다

모든 종료 경로는 가능한 한 하나의 멱등적 Cleanup 함수로 모은다.

정리 항목:

- Timer 해제
- 필요할 때만 켠 Tick 비활성화
- Delegate/Subsystem 구독 해제
- Weak Reference와 Session ID 초기화
- 임시 Actor/Widget/Audio/Light 제거
- 입력 모드, 커서, 이동·시점 차단 복구
- Camera/ViewTarget/FOV 복구
- 임시 Transform/Pose 복구
- 예약 해제

지연 콜백은 캡처한 Session GUID와 예상 상태를 모두 검증한 뒤 동작해야 한다. 오래된 비동기/Timer 콜백이 새 세션을 건드리면 안 된다.

### 6.4 Weak Reference와 GC 안전성을 기본값으로 본다

- 장기 비소유 Actor/UObject 참조는 `TWeakObjectPtr`를 우선 검토한다.
- 소유 UObject Property는 `UPROPERTY`/`TObjectPtr`로 GC에 안전하게 둔다.
- 대상은 콜백 사이, UI가 열린 동안, Hold 중 언제든 파괴될 수 있다.
- Delegate 실행 직전에도 Listener와 대상 유효성을 다시 확인한다.

---

## 7. 데이터, 설정, 에셋 정책

### 7.1 코드와 제작 데이터를 분리한다

| 데이터 종류 | 권장 위치 |
|---|---|
| 아이템/대사/문/점프스케어/정찰 정의 | Data Asset |
| 프로젝트 기본 정책과 선택 기본 에셋 | `UDeveloperSettings` |
| 의미, 조건, 이벤트 종류 | Gameplay Tag |
| 사용자 표시 문구 | `FText`, 필요 시 String Table |
| 선택 에셋과 대형 콘텐츠 | Soft Object/Class Reference |
| 런타임 진행 상태 | Component/Subsystem의 인스턴스 데이터 |

Data Asset에 CurrentCount, 현재 상태 같은 Runtime 값을 쓰지 않는다.

### 7.2 하드코딩 금지

- `/Game/...` 프로젝트 콘텐츠 경로
- 프로젝트 전용 Blueprint/Character/Controller/HUD 클래스
- 레벨 이름과 배치 Actor 이름
- 충돌 채널의 임의 숫자
- 키 이름과 Input Mapping Context
- 사용자 표시 문자열의 `FString`
- 밸런스 값과 대형 에셋 경로

플러그인 기본 에셋이 필요하면 해당 플러그인 Mount Point 안에 두고, 실패 시 안전한 폴백을 제공한다.

### 7.3 Soft Reference 로딩 원칙

- 큰 Mesh, Sound, Sequence, Widget은 Soft Reference를 우선한다.
- CDO 생성자에서 무거운 에셋을 강제 동기 로드하지 않는다.
- 실제 기능을 시작할 때 로드한다.
- 비동기 로드에서는 요청/세션 ID를 확인해 stale callback을 차단한다.
- 로드 실패는 Crash가 아니라 Result, 경고, Native UI/기본값 또는 해당 시각 기능 비활성화로 처리한다.

### 7.4 Developer Settings 원칙

- Project Settings 카테고리는 `JM Plugins`
- 새 표준 명명: `UJMFeatureSettings`
- 숫자는 `ClampMin`/`ClampMax`
- 조건부 값은 `EditCondition`
- `DisplayName`, `ToolTip`, 의미 있는 Category 제공
- 플러그인의 `Config/Default<Plugin>.ini`와 안전한 C++ 기본값 제공
- 호스트 `DefaultGame.ini` 복사를 필수 설치 단계로 만들지 않는다.

### 7.5 Gameplay Tag 소유권

- Tag는 문자열 비교를 멋있게 바꾸는 수단이 아니라 의미 계약이다.
- 기능 전용 Tag는 해당 기능 플러그인이 소유한다.
- 공통 UI/Event Tag는 공통 제공자가 소유한다.
- Tag 이름 변경은 데이터 마이그레이션이 필요한 Breaking Change다.
- Event Tag와 Payload의 Target ID/Context Tag 역할을 구분한다.

---

## 8. UI와 입력 설계

### 8.1 UI는 Presenter이며 도메인 상태의 주인이 아니다

- Widget은 Component/Subsystem API만 호출한다.
- Widget이 Inventory Slot 배열, Door 상태, Objective 진행값을 직접 확정하지 않는다.
- C++ Widget Base/Presenter와 게임별 WBP 디자인을 분리한다.
- WBP가 없어도 핵심 사용 또는 최소 Native UI 폴백이 가능하면 이식성과 디버깅이 좋아진다.
- `BindWidget` 이름은 API이므로 문서화하고 변경 시 호환성을 검토한다.

### 8.2 Local UI와 서버/Headless를 분리한다

- UI는 Local Controller/Local Player가 있을 때만 생성한다.
- Dedicated Server와 Headless 자동화 환경에서 안전하게 빠진다.
- 로컬 Preview, Prompt, JumpScare, Cosmetic Camera는 자동으로 서버 상태를 변경하지 않는다.

### 8.3 입력 상태는 대칭적으로 복구한다

플러그인이 아래를 바꾸면 이전 값을 보관하고 성공, 실패, 취소, 파괴, `EndPlay` 모든 경로에서 복구한다.

- Input Mode
- Mouse Cursor
- 이동/시점 입력 차단
- Pause
- ViewTarget/Camera/FOV
- Prompt 가시성
- 다른 HUD/Modal UI 상태

일반 Unreal API만으로 프로젝트의 커스텀 입력 스택 전체를 완벽히 복원할 수 없을 수 있다. 이 경우 “완전 복구”를 주장하지 말고 호스트 Hook, Overlay/Cinematic 모드 또는 명시적 Integration 계약을 제공한다.

### 8.4 시스템 간 HUD 협업은 이벤트로 한다

Inventory가 열릴 때 특정 HUD를 Cast하는 대신 `Event.UI.Modal.Opened/Closed` 같은 공통 완료 사실을 발행하고 Objective, Interaction Prompt, Crosshair가 선택적으로 구독하는 패턴이 현재 기준 사례다.

---

## 9. 네트워크, 저장, 이벤트 버스

### 9.1 현재 네트워크 범위

현재 대부분의 시스템은 **로컬 싱글플레이 기준**이다.

- `JMGameplayEvent`는 해당 프로세스와 GameInstance 안의 로컬 동기 이벤트다.
- Interaction Trace와 완료 요청은 서버 검증을 자동 제공하지 않는다.
- Door, Inventory, Dialogue, Objective, Recon, JumpScare와 Integration 계층은 자동 RPC/Replication을 제공한다고 가정하면 안 된다.
- UI, Preview, Prompt, JumpScare는 로컬 Cosmetic이다.

멀티플레이 확장 시:

```text
Client 입력/Trace/예측
→ Server RPC Command
→ 서버가 거리·시야·상태·권한·보유 아이템 재검증
→ 서버가 도메인 상태 변경과 아이템 소비 확정
→ 상태 Replication
→ 필요한 각 프로세스에서 로컬 Event/Cosmetic 실행
```

UI가 내부 상태를 직접 변경하지 않는 구조를 유지해야 이 확장이 가능하다.

### 9.2 저장 경계

기능 플러그인은 특정 SaveGame 클래스, 슬롯 이름, 파일 I/O, 암호화를 소유하지 않는다.

기능 플러그인이 제공할 것:

- 안정적인 Persistent ID
- 버전이 있는 Save Record 구조체
- Capture/Restore API 또는 Saveable Interface
- 이전 버전 마이그레이션 또는 명시적 거부 정책

호스트 Save 시스템이 할 것:

- 파일/슬롯 I/O
- 레벨 Actor 등록과 ID Registry
- 중복 ID 검증
- 에셋 Soft Reference 로드
- 프로젝트 전체 Save 버전 마이그레이션

UObject 포인터, 표시 이름, 배열 인덱스를 영속 ID로 저장하지 않는다.

### 9.3 `JMGameplayEvent` 계약

- 수명: `UGameInstanceSubsystem`
- Dispatch: Game Thread 전용, 동기식, 중첩 발행 가능
- Listener: Weak UObject Reference
- 순서: 계약하지 않음
- 재진입: 최대 깊이 설정을 넘으면 차단
- 네트워크: 없음

콜백 도중 구독 추가/해제가 안전하도록 발행 대상 스냅샷과 호출 직전 유효성 검사를 사용한다. 순서가 필요한 요청은 직접 API로 구현한다.

---

## 10. 현재 시스템에서 배운 재사용 패턴

### 10.1 Door: 도메인 코어와 진입점을 분리하라

`JMDoor`의 본체는 `ExecuteCommand`, 상태 머신, 이동 전략, 접근과 저장 계약이다. Interaction, Inventory, Recon은 별도 Integration에서 Door Context로 번역한다.

재사용할 교훈:

- 플레이어 입력은 도메인의 본질이 아니다.
- 이동 전략은 상태·접근·저장을 몰라야 한다.
- Integration은 임시 Adapter를 붙일 수 있지만 원본 에셋을 수정하지 않는다.
- 임시 Recon Pose는 영구 Door State/SaveData를 변경하지 않고 Transform 스냅샷을 복원한다.

### 10.2 Interaction: 공통 입구와 도메인 API를 동일시하지 마라

`JMInteraction`은 탐색, Focus, Prompt, Begin/Complete/Cancel 계약을 제공한다. 실제 Door 열기, Item 획득, Dialogue 시작은 각 도메인 API가 수행한다.

재사용할 교훈:

- `CanInteract`는 빠르고 부작용 없는 질의다.
- `Begin`은 예약/연출 시작, `Complete`는 성공 확정, `Cancel`은 임시 상태 복구다.
- 감지 가능한 대상과 현재 실행 가능한 대상을 분리하면 Prompt에 실패 이유를 표시할 수 있다.
- Trace에 맞은 Actor뿐 아니라 계약을 구현한 Component/Owner 경계도 명확히 정의해야 한다.

### 10.3 Gameplay Event: 완료 사실만 느슨하게 공유하라

Door/Inventory/Dialogue/Interaction은 자신의 직접 Delegate와 Command API를 유지하면서 완료된 사실만 Event Bus로 발행한다.

재사용할 교훈:

- Publisher는 Objective, Save, Notification, Audio 소비자를 몰라야 한다.
- 실패하거나 중간 상태인 요청을 완료 Event처럼 발행하지 않는다.
- 기존 직접 알림을 Event로 마이그레이션할 때는 새 소비자를 먼저 배포하고 중복 통지를 검사한다.

### 10.4 Recon: 세션 ID와 중앙 정리로 비동기 상태를 보호하라

Recon은 Interactor별 세션 GUID, Target 예약, 상태 검증, 멱등적 종료를 사용한다.

재사용할 교훈:

- 지연 전환은 세션 ID와 예상 상태를 함께 검증한다.
- 세션 시작 때 선택한 Adapter를 종료 때도 사용한다.
- Target 파괴, 경합, 취소, 외부 상태 변경을 정상 실패 경로로 설계한다.
- Tick은 정렬·보간·Fade가 필요한 동안만 켠다.

### 10.5 Dialogue: 출력과 오디오를 하나의 진행 흐름에 묶어라

타이핑 텍스트와 출력음을 독립 반복 Timer로 돌리지 않고 같은 Token 처리 함수에서 갱신한다.

재사용할 교훈:

- 서로 동기화되어야 하는 출력은 같은 상태 전이/호출 흐름에 둔다.
- 한 입력이 “현재 줄 완성”과 “다음 줄 이동”을 동시에 하지 않게 한다.
- 실행 중 새 요청 정책은 `Reject`, `Replace`, `Queue`처럼 명시한다.
- 상시 Tick 대신 재생 중 Timer를 사용한다.

### 10.6 Inventory: 부분 성공을 데이터로 표현하라

`AddItemDetailed`은 기존 Stack과 빈 Slot을 처리하고 실제 수용 수량과 남은 수량을 반환한다. Pickup은 실제 수용된 만큼만 월드 수량에서 차감한다.

재사용할 교훈:

- 용량 부족은 전부 실패 또는 전부 성공만 있는 문제가 아니다.
- World 표현과 Inventory 저장소를 분리한다.
- UI는 Delegate로 갱신하고 Tick하지 않는다.
- 다형적 Use Effect와 범용 Receiver Interface로 Door 같은 소비자를 역참조하지 않는다.

### 10.7 Item Inspector: 로컬 Cosmetic을 독립 수명으로 관리하라

Inspector는 `ULocalPlayerSubsystem`이 Widget, Preview Actor, Render Target, 입력/커서 상태를 관리한다. 아이템 획득과 서버 상태 변경은 소유하지 않는다.

재사용할 교훈:

- 로컬 플레이어별 UI는 GameInstance 전역 상태로 두지 않는다.
- 선택 시각 기능 실패가 전체 기능 실패가 되지 않게 한다.
- 설정 해석 우선순위를 `Request Override → Data Asset Override → Project Default`처럼 명시한다.
- Transition 중에도 정확한 최종 authored pose를 다시 적용해 누적 오차를 막는다.

### 10.8 Objective: 정적 정의, 런타임 상태, Flow 순서를 분리하라

개별 Objective Definition은 조건 하나를 소유하고, Flow Definition이 순서를 소유한다. 따라서 Objective를 여러 Flow에서 재사용할 수 있다.

재사용할 교훈:

- Data Asset에 Runtime 진행값을 저장하지 않는다.
- 완료 콜백 중 다음 Objective 구독이 현재 Event를 중복 소비하지 않게 Event Bus 재진입 계약을 이해한다.
- Flow 전환과 UI 연출 Delay를 분리한다.
- 상위 Quest 시스템을 예상하더라도 현재 Definition에 불필요한 다음 목표 포인터를 넣지 않는다.

### 10.9 Native 폴백은 이식성과 테스트성을 높인다

Interaction Prompt, Inventory/Inspector 일부 UI, Recon Prompt, JumpScare Overlay는 WBP가 없거나 선택 에셋 로드가 실패해도 Native C++/UMG/Slate 경로를 제공한다.

재사용할 교훈:

- 시각 품질과 핵심 동작의 생존성을 분리한다.
- 최소 Native UI는 빈 프로젝트 Smoke Test와 문제 격리에 유용하다.
- 프로젝트별 WBP는 동일한 Presenter/BindWidget 계약 위에서 교체한다.

---

## 11. 새 시스템 설계 절차

### 단계 A — 저장소 조사

1. 모든 대상 `.uplugin`의 플러그인 의존성 확인
2. Runtime/Editor/Test `Build.cs`의 실제 모듈 의존성 확인
3. 기존 `Public` API에서 Context, Result, Interface, Component, Subsystem, Tag 검색
4. 같은 의미의 타입과 Tag를 새로 만들기 전에 재사용 가능성 검토
5. 대상 플러그인의 `ARCHITECTURE`, `CHANGELOG`, 설치 문서, TODO 확인
6. Engine 버전, Target, Config와 Content Mount Point 확인

### 단계 B — 설계 문서 먼저 작성

대상 플러그인의 `Docs/ARCHITECTURE.md`에 최소 다음을 기록한다.

- 책임과 비책임
- 모듈과 폴더 구조
- 직접 의존성과 선택 Integration
- 주요 Context, Result, Command, Event
- 데이터 흐름과 상태 전이
- Component/Subsystem 수명 선택 이유
- 데이터·설정·Soft Reference 로딩 정책
- UI/입력 상태 소유권과 복구
- 네트워크/Authority 범위
- 저장 계약
- 모든 실패 시 안전 동작

### 단계 C — 작은 컴파일 단위로 구현

```text
.uplugin / Module / Build.cs
→ Log / Types / Context / Result
→ Interface / Component / Subsystem 계약
→ 핵심 Runtime 상태와 규칙
→ Settings / Data Asset / Tags
→ Integration / Adapter
→ Blueprint 확장 지점과 Native 폴백
→ Content / Example
→ Tests / Docs / Changelog
```

각 단계의 컴파일 오류를 다음 단계로 넘기지 않는다.

### 단계 D — 위험 시나리오 구현

정상 경로 뒤에 붙이는 것이 아니라 상태 머신과 동시에 설계한다.

- Null Context와 미설정 에셋
- 잘못된 Data Asset
- 중복 요청과 재진입
- 취소
- Target/Listener/Owner 파괴
- Level/World 전환
- UI 생성 실패
- Soft Reference 로드 실패
- Timer/비동기 콜백 stale
- Integration 반대편 플러그인/컴포넌트 누락
- 0, 빈 배열, 최대 용량, 부분 성공

### 단계 E — 호환성 검토

변경 전후에 다음을 비교한다.

- `.uplugin`과 `Build.cs` 의존성
- Public C++/Blueprint API
- Gameplay Tag와 Config 키
- 콘텐츠와 `/Script` 경로
- Save Version/Persistent ID
- 기존 Blueprint 에셋 로드

Breaking Change가 필요하면 승인, 버전 증가, Redirect/마이그레이션, Changelog를 함께 처리한다.

---

## 12. 테스트와 완료 기준

### 12.1 최소 자동화 범위

- 정상 성공
- 유효하지 않은 요청
- Null/미설정 에셋
- 중복 요청과 재진입
- 취소와 대상 파괴
- 상태 복구의 멱등성
- 경계값과 부분 성공
- Integration 성공/실패
- Save Capture/Restore와 버전 거부
- Game Thread/Local Player 전제
- 가능하면 Dedicated Server/Headless UI 비활성

테스트 이름은 `JM.<Feature>.*` 계층을 사용한다.

### 12.2 권장 검증 순서

```text
정적 검색
→ 관련 Automation Test
→ Editor Development 전체 빌드
→ 일반 Editor Smoke Test
→ Shipping 빌드/패키징
→ 깨끗한 빈 C++ 프로젝트 복사 테스트
→ 플러그인 Content 외부 참조 검사
```

정적 검색 대상:

- `/Game/`
- 프로젝트 전용 클래스/모듈
- Runtime의 Editor-only 모듈
- 형제 플러그인 역참조
- Private 헤더 Include
- 무조건 Tick
- `GetActorOfClass` 기반 전역 검색
- 설정/에셋 누락 시 `check`

### 12.3 완료 정의

- [ ] 호스트 프로젝트 `Source` 없이 플러그인 폴더만으로 컴파일된다.
- [ ] 필수 플러그인 최소 묶음이 정확히 문서화됐다.
- [ ] `.uplugin`과 `Build.cs` 의존성이 일치하며 순환이 없다.
- [ ] 프로젝트 전용 클래스와 `/Game/...` 참조가 없다.
- [ ] 도메인 API가 Interaction/UI/Level Blueprint 밖에서도 호출 가능하다.
- [ ] 설정, 에셋, Target 누락이 Crash하지 않는다.
- [ ] 모든 종료 경로에서 Timer, Delegate, UI, 입력, 카메라, 임시 Pose가 복구된다.
- [ ] Runtime에 Editor-only 의존성이 없다.
- [ ] 네트워크와 저장 지원 범위를 과장하지 않는다.
- [ ] 관련 자동화 테스트와 전체 빌드가 통과한다.
- [ ] README, ARCHITECTURE, 설치법, CHANGELOG가 현재 코드와 일치한다.
- [ ] C++를 모르는 제작자도 Blueprint/Data Asset 사용 흐름을 따라갈 수 있다.
- [ ] 빈 프로젝트 복사와 Shipping 검증 결과가 릴리스 문서에 남아 있다.

---

## 13. 배포와 에셋 패키징

배포 포함:

```text
<Plugin>/
├─ <Plugin>.uplugin
├─ Source/
├─ Content/
├─ Config/
└─ Docs/
```

기본 제외:

```text
Binaries/
Intermediate/
Saved/
DerivedDataCache/
.vs/
IDE 사용자 파일
크래시 로그
```

Content-only 에셋 팩은 `CanContainContent: true`로 만들고 모든 내부 참조를 자신의 Mount Point 안에 닫는다. 시스템 플러그인에는 기본 UI, 아이콘, 테스트 에셋만 두고 대형 테마 Art/Audio는 별도 Content 플러그인으로 분리해 Soft Reference/Data Asset으로 연결하는 것을 우선 검토한다.

릴리스 전 확인:

- 필수 플러그인 폴더 포함
- `/Game`과 호스트 `Source` 참조 없음
- Mount Point 내부 참조 유효
- Redirector와 누락 에셋 없음
- 외부 Marketplace/Engine Content 의존성과 라이선스 문서화
- 대상 Engine/플랫폼/Configuration 명시
- 압축 해제 후 빈 C++ 프로젝트에서 재빌드·실행 성공

---

## 14. 금지 패턴

```cpp
Cast<AMyProjectCharacter>(...);
Cast<AMyProjectGameMode>(...);
LoadObject<UObject>(nullptr, TEXT("/Game/SpecificProject/..."));
UGameplayStatics::GetActorOfClass(World, ASpecificSingletonActor::StaticClass());
```

다음 구조도 금지한다.

- Level Blueprint가 있어야 핵심 기능이 시작됨
- 다른 플러그인의 Private 헤더 Include
- 형제 기능 플러그인끼리 상호 참조
- UI Blueprint가 핵심 상태·저장 규칙을 소유
- 여러 bool로 모순 가능한 상태 표현
- 모든 Actor/Component의 상시 Tick
- 설정 누락 시 `check()`로 종료
- 필수 Build 의존성을 선택 의존성으로 문서화
- 도메인 기능을 Interaction 구현 안에만 작성
- 이벤트 버스로 성공/실패 반환이 필요한 Command 실행
- Event Listener 등록 순서에 게임 규칙 의존
- Soft Reference 실패, 대상 파괴, UI 생성 실패를 예외 상황으로 무시
- 테스트 없이 Public Tag, Config, Save, Asset/Blueprint 경로 변경

---

## 15. 현재 알려진 제한과 문서 부채

이 절은 새 시스템이 잘못된 전제를 상속하지 않도록 반드시 읽어야 한다.

### 15.1 생태계 문서가 현재 레지스트리를 모두 반영하지 않는다

- `JM_PLUGINS_STRUCTURE.md`는 초기 6개 중심이라 `JMGameplayEvent`, `JMObjective`, `JMRecon`, `JMJumpScare` 및 최신 Integration을 모두 열거하지 않는다.
- `AGENTS.md` 레지스트리에도 현재 `JMObjective`가 누락되어 있다.
- 새 시스템 작업에서는 이 문서의 레지스트리와 실제 `.uplugin`을 우선한다.

### 15.2 JMDoor 의존성 문구가 현재 코드와 다르다

- `JMDoor/Docs/ARCHITECTURE.md` 일부는 JMDoor의 JM 직접 의존성이 0이라고 설명한다.
- 현재 `JMDoor.uplugin`과 `JMDoorRuntime.Build.cs`는 `JMGameplayEvent`를 직접 의존한다.
- 정확한 현재 사실은 “Interaction/Inventory에는 독립이지만 Gameplay Event에는 직접 의존”이다.

### 15.3 JMDoor Save 문서 버전이 오래됐다

- `JMDoor/Docs/Guides/SAVE_INTEGRATION.md`는 `FJMDoorSaveData.Version = 1`이라고 적혀 있다.
- 실제 `JMDoorTypes.h` 기본값은 2이며, Dual Panel A/B 상태를 저장하고 Version 1을 Legacy Panel A로 복원한다.
- Save 연동을 구현할 때 코드의 Version 2 계약과 Migration 경로를 기준으로 한다.

### 15.4 JMInteraction Hold는 외부 완료 호출이 필요하다

- Duration이 0보다 크면 현재 상태는 `Holding`이 된다.
- 현재 `UJMInteractionComponent`는 Hold 완료 Timer나 Progress Delegate를 자체 제공하지 않는다.
- 입력 계층이 시간 측정, 취소, `CompleteInteraction()` 호출을 책임진다.
- Hold UI를 추가할 때 자동 완료를 가정하지 말고 상태 변경 중 Focus 갱신과 재진입을 테스트한다.

### 15.5 JMInteraction Priority와 InteractionTag의 적용 범위

- Prompt와 Interface에 Priority가 있지만 현재 탐색은 Trace의 첫 유효 계약을 선택하는 구조다. 다중 후보 우선순위 정렬 시스템으로 간주하지 않는다.
- `BuildInteractionContext()`는 현재 Instigator, Target, Controller, View, Instigator Tags를 채우지만 `InteractionTag`를 자동 채우지 않는다.
- Tag 기반 행동을 추가하려면 누가 Tag를 선택하고 Context에 넣는지 먼저 설계한다.

### 15.6 입력 모드 전체 복구는 일반화가 어렵다

- Inspector와 Dialogue 문서 모두 프로젝트별 입력 스택 전체를 Unreal 공용 API만으로 완전히 복원하기 어렵다고 기록한다.
- 플러그인이 실제로 저장한 커서/차단/Camera 상태만 복구한다고 가정한다.
- CommonUI나 프로젝트 입력 Stack이 있으면 별도 Interface/Integration이 필요하다.

### 15.7 주요 후속 기능

- Dialogue: Queue/우선순위, Choice/분기, Auto/Voice 진행, 완전한 Unicode grapheme, History Save, Editor Validation
- Inventory: Weight/Capacity 정책, Drop 수량 UI, Asset Manager 기반 ID 복원, Replication/RPC, 중복 Item ID 검증
- Item Inspector: Async Load와 stale callback 보호 보강, 더 정교한 Input 복구, 패키지 검증
- Objective: 분기 Quest, 보상, Marker, Replication은 상위 시스템 범위
- Recon/JumpScare/Integration: 현재 로컬 싱글플레이, 저장/Replication 없음

이 목록은 새 시스템의 범위를 자동 확장하는 허가가 아니다. 설계 시 기존 제한과 충돌하는지 확인하기 위한 정보다.

---

## 16. AI가 새 시스템 프롬프트를 만들 때 포함할 요구사항

이 문서를 입력받아 시스템 프롬프트를 생성하는 AI는 아래 항목을 명령형으로 포함해야 한다.

### 역할과 목표

- Unreal Engine 5.7 C++ 재사용 플러그인 설계·구현 전문가로 행동
- 기존 JM 생태계의 Public API를 먼저 조사하고 중복 계약 생성 금지
- 독립 설치, 이식성, 안전한 실패, 호환성, 검증을 기능 완성도와 같은 수준으로 취급

### 작업 전 분석

- 대상 `.uplugin`, `Build.cs`, `Public`, `Config`, `Docs` 확인
- 책임/비책임, 필수/선택 의존성, 수명, 상태, 실패 동작 작성
- 현재 구조와 요청의 충돌 또는 Breaking Change를 구현 전에 보고

### 구현 규칙

- 도메인 코어와 Interaction/UI/Integration 분리
- Interface, Component, Subsystem, Delegate/Event, Tag, Data Asset, Settings, Soft Reference 우선
- Runtime/Editor/Test 모듈 분리
- Project 전용 Cast와 `/Game` 하드코딩 금지
- 중앙 Cleanup, Weak Reference, 세션 ID, stale callback 보호
- Command/Event, Context/Result, Local Cosmetic/Authority 분리

### 검증과 보고

- 정상/실패/취소/파괴/중복/레벨 전환/에셋 누락 테스트
- 관련 Automation Test, 전체 Editor 빌드, 릴리스 시 Shipping/빈 프로젝트 복사 검증
- 변경 파일, 의존성 변화, 사용법, 테스트 결과, 남은 제한 보고
- README, ARCHITECTURE, CHANGELOG와 전체 레지스트리 동기화

---

## 17. 새 시스템 요청 템플릿

```text
Plugins/JM_FUTURE_SYSTEM_DESIGN_CONTEXT_KO.md를 최우선 컨텍스트로 사용해
<시스템 이름>을 Unreal Engine 5.7 C++ 재사용 Runtime Plugin으로 설계·구현해줘.

목표 기능:
- <기능 1>
- <기능 2>

연동 대상:
- <기존 플러그인/API>

범위 밖:
- <네트워크, 저장, Editor Tool 등 명시>

요구사항:
- 도메인 코어는 Interaction/UI/호스트 프로젝트에서 독립시켜라.
- 큰 연동은 소비자 측 Integration Plugin으로 격리하라.
- Context/Result, 상태 머신, 수명, 실패 복구, 데이터/설정/에셋 정책을 먼저 문서화하라.
- .uplugin과 Build.cs 의존성을 실제 Public API에 맞춰라.
- 테스트, 전체 Editor 빌드, 설치/사용/아키텍처/CHANGELOG 문서까지 완료하라.
- 기존 공개 API, Tag, Config, Save, Asset 경로를 깨야 한다면 구현 전에 호환 계획을 제시하라.
```

Content 에셋 팩 요청:

```text
Plugins/JM_FUTURE_SYSTEM_DESIGN_CONTEXT_KO.md를 기준으로
<에셋 팩 이름>을 재사용 가능한 Content Plugin으로 구성해줘.

모든 참조를 플러그인 Mount Point 안에 닫고,
시스템 플러그인과는 Data Asset/Soft Reference로 연결하며,
런타임 필수 에셋과 Demo/Source 원본을 분리해라.
라이선스, 최소 의존성, 압축 배포, 빈 프로젝트 로드 검증까지 문서화해라.
```

---

## 18. 근거로 읽은 주요 문서와 선언

전체 기준:

- `Plugins/AGENTS.md`
- `Plugins/JM_PLUGINS_STRUCTURE.md`
- `Plugins/JM_PLUGIN_DEVELOPMENT_GUIDE_KO.md`
- `Plugins/PORTABLE_BUNDLE.md`

플러그인별:

- 각 플러그인의 `.uplugin`
- 각 Runtime/Editor/Test 모듈의 `Build.cs`
- 각 플러그인의 `Source/*/Public`
- 각 플러그인의 `Config`
- 각 플러그인의 `Docs/ARCHITECTURE*.md`
- `JMGameplayEvent/Docs/Guides/MIGRATION_KO.md`
- `JMInteraction/Docs/Archive/PROJECT_ANALYSIS.md`
- `JMDoor/Docs/Guides/SAVE_INTEGRATION.md`
- `JMObjective/Docs/Guides/SAVE_INTEGRATION_KO.md`
- Inventory, ItemInspector, Dialogue의 `TODO`, `IMPLEMENTATION_PLAN`, `TROUBLESHOOTING`

가장 중요한 결론:

> 재사용성은 기능을 많이 넣어서 생기지 않는다. 도메인 코어가 자신의 상태와 규칙만 소유하고, 공통 계약과 소비자 측 Adapter를 통해 다른 시스템과 만날 때 생긴다. 새 시스템은 독립 실행, 안전한 실패, 대칭적 복구, 명시적 의존성, 호환 가능한 공개 API, 빈 프로젝트 검증까지 포함해야 완성이다.
