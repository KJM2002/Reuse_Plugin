---
title: "JM 플러그인 개발을 위한 Interaction 기반 지식 가이드"
status: ReviewRequired
authority: Guide
scope: "Plugin Ecosystem"
classified_on: 2026-08-19
owners:
  - "Plugin Architecture"
review_reason: "현재 Plugin 전체 구성과 배포 절차를 다시 실행해 검증하지 않음"
---

# JM 플러그인 개발을 위한 Interaction 기반 지식 가이드

> 기준 프로젝트: `P_060715` / Unreal Engine 5.7 / C++  
> 작성 기준일: 2026-07-18  
> 목적: 현재 코드에서 `JMInteraction`이 실제로 무엇인지 이해하고, 이후 기능 플러그인을 독립적이고 재사용 가능하게 설계하기 위한 실전 기준을 제공한다.

## 1. 먼저 바로잡아야 할 핵심 개념

현재 프로젝트에는 `JMInteraction`이라는 이름의 독립 플러그인이나 모듈이 없다.

우리가 편의상 **JMInteraction**이라고 부르는 것은 현재 `ItemInspector` 플러그인의 `ItemInspectorRuntime` 모듈 안에 있는 다음 공개 API 묶음이다.

- `FJMInteractionContext`, `FJMInteractionPrompt`, `FJMInteractionResult`
- `IJMInteractorInterface`
- `IJMInteractableInterface`
- `UJMInteractionComponent`

즉 현재의 실제 의존 관계는 다음과 같다.

```text
새 기능 플러그인
  └─ ItemInspector 플러그인
       └─ ItemInspectorRuntime 모듈
            └─ Interaction/Core 공개 타입
```

`JMInteractionComponent`만 사용하더라도 설치 단위는 `ItemInspector` 전체이고, C++ 모듈 의존 이름은 `ItemInspectorRuntime`이다. 이 사실을 모르면 `.uplugin`에는 `ItemInspector`를 적고 `Build.cs`에는 엉뚱한 이름을 넣거나, 공통 타입을 새로 복제하는 실수를 하게 된다.

## 2. 한 문장으로 이해하는 JMInteraction

JMInteraction은 **“누가, 무엇을, 어떤 문맥에서 상호작용하는지”를 표준 계약으로 연결하고, 탐색부터 시작·유지·완료·취소까지의 공통 실행 흐름을 담당하는 Actor Component 기반 중재자**다.

역할은 세 부분으로 나뉜다.

```text
Interactor                      Interaction Component                    Interactable
상호작용 주체                  탐색·상태·호출 중재                      상호작용 대상

시점/방향/태그 제공   →   Trace → Context 작성 → 수명주기 호출   →   가능 여부/실제 기능 수행
```

- **Interactor**: 플레이어, AI, Controller 등 행동을 시작하는 쪽이다.
- **Interaction Component**: 대상을 찾고 표준 Context를 만들며 Interface 함수를 호출한다.
- **Interactable**: 문, NPC, 아이템, 레버처럼 실제 도메인 기능을 수행하는 쪽이다.

이 분리 덕분에 플레이어 코드는 Door, Dialogue, Inventory의 구체 클래스를 알 필요가 없다.

## 3. JMInteraction의 기반이 되는 Unreal 지식

### 3.1 Unreal Interface: 구체 클래스 대신 능력을 묻는다

`IJMInteractableInterface`는 “이 객체가 상호작용 가능한가?”라는 능력 계약이다. 대상은 Actor일 수도 있고 Actor Component일 수도 있다.

```cpp
class UMyFeatureComponent
    : public UActorComponent
    , public IJMInteractableInterface
{
    // CanInteract, BeginInteract, CompleteInteract ... 구현
};
```

외부에서는 `Cast<AMyDoor>` 같은 구체 타입 Cast 대신 Interface 구현 여부를 확인하고 `Execute_...` 래퍼로 호출한다.

```cpp
if (Object->GetClass()->ImplementsInterface(UJMInteractableInterface::StaticClass()))
{
    const bool bAllowed = IJMInteractableInterface::Execute_CanInteract(Object, Context);
}
```

`BlueprintNativeEvent`이므로 C++ 기본 구현과 Blueprint 재정의를 함께 지원한다. C++에서 다른 구현의 Interface 이벤트를 호출할 때는 `_Implementation()`을 직접 호출하는 습관보다 `Execute_Function(Object, ...)`를 기본으로 삼아야 Blueprint override가 보존된다.

### 3.2 Actor Component 조합: 상속 대신 기능을 붙인다

`UJMInteractionComponent`는 플레이어 Character의 부모 클래스를 강제하지 않는다. 필요한 Actor에 Component를 붙이는 조합 방식이다.

대상 쪽도 동일하다. Dialogue는 `UReuseDialogueInteractableComponent`, Door 연동은 `UJMDoorInteractableAdapterComponent`를 Actor에 붙여 기능을 제공한다. 하나의 Actor가 거대한 다중 상속 계층을 갖지 않고 역할별 Component를 조합할 수 있다.

새 플러그인에서도 다음 질문을 먼저 한다.

- 이 기능은 Actor 자체 정체성인가, 붙였다 뗄 수 있는 능력인가?
- 여러 Actor 종류에서 재사용할 상태와 동작인가?
- 그렇다면 Actor 파생 클래스보다 Actor Component가 더 적합한가?

### 3.3 Context Object: 함수 인자가 늘어나는 것을 막는 공통 봉투

`FJMInteractionContext`에는 현재 다음 정보가 들어간다.

- 실행 Actor와 Controller
- 대상 Actor
- 상호작용 위치와 방향
- 상호작용 Gameplay Tag
- 실행자 Gameplay Tag 집합

Context를 쓰면 인터페이스 함수마다 Player, Controller, 위치, 방향, 열쇠 태그를 따로 추가하지 않아도 된다. 새 문맥 정보가 생겨도 구조체를 확장할 수 있다.

다만 Context를 만능 전역 가방으로 만들면 안 된다. 특정 기능에서만 쓰는 대형 데이터나 구체 클래스 포인터는 해당 도메인의 별도 Context로 변환한다. Door Integration의 `MakeDoorContext()`가 좋은 예다. 공통 `FJMInteractionContext`를 `FJMDoorUseContext`로 번역해 Door 코어에 전달한다.

### 3.4 Result Object: `bool`보다 실패 이유가 중요하다

`FJMInteractionResult`는 성공 여부뿐 아니라 `EJMInteractionResultCode`와 사용자 표시 가능한 `FText Message`를 반환한다.

이 패턴은 호출자가 다음을 구분하게 한다.

- 시스템 비활성화
- 대상 없음 또는 대상 파괴
- 현재 조건에서 불허
- 이미 다른 상호작용 진행 중
- 일반 실행 실패

새 플러그인의 공개 명령도 실패에 대한 대응이 필요하면 `bool` 하나보다 `Result Code + Message + 필요 데이터` 구조를 권장한다.

### 3.5 Gameplay Tag: 구현을 모르고 의미를 전달한다

Gameplay Tag는 클래스 이름이나 문자열 비교 없이 능력·의도·조건을 표현한다. 예를 들어 실행자 태그를 Door의 Access Tag로 변환하면 Door 코어는 인벤토리 클래스나 카드키 클래스가 무엇인지 몰라도 접근을 판단할 수 있다.

태그는 단순 문자열 편의 기능이 아니라 플러그인 간 공개 데이터 계약이다. 이름 변경은 저장 데이터와 Data Asset까지 영향을 주는 Breaking Change로 본다.

### 3.6 Delegate: 호출자가 소비자를 몰라도 이벤트를 알린다

`UJMInteractionComponent`는 현재 대상 변경, Prompt 변경, 상호작용 종료를 Dynamic Multicast Delegate로 발행한다.

```text
Interaction Component ── OnPromptChanged ──> HUD/WBP
                      └─ OnInteractionFinished ──> 사운드/퀘스트/로그
```

컴포넌트가 특정 HUD나 위젯 클래스를 직접 참조하지 않기 때문에 UI 교체가 쉬워진다. 새 시스템에서도 “명령은 Interface/함수, 알림은 Delegate”라는 분리를 우선한다.

### 3.7 Weak Pointer와 수명: 대상은 언제든 사라질 수 있다

현재 대상과 활성 대상은 `TWeakObjectPtr`로 보관한다. 상호작용 도중 Actor가 파괴되더라도 강제로 수명을 연장하지 않고 안전하게 무효화된다.

필수 원칙은 다음과 같다.

- 소유하는 UObject는 `UPROPERTY`와 `TObjectPtr`로 GC에 알린다.
- 소유하지 않고 관찰만 하는 장기 참조는 `TWeakObjectPtr`를 검토한다.
- Timer, Delegate, Subsystem binding은 `EndPlay`/`Deinitialize`에서 해제한다.
- 완료 시점에는 이전 포인터가 여전히 유효하다고 가정하지 않는다.

### 3.8 Subsystem: 전역 싱글턴이 아니라 수명 선택이다

Door Integration은 World마다 기존/신규 Door Actor를 찾아 Adapter를 붙여야 하므로 `UWorldSubsystem`을 사용한다. Item Inspection UI는 로컬 플레이어마다 달라질 수 있어 `ULocalPlayerSubsystem`, Dialogue 세션은 GameInstance 수명에 맞춰 `UGameInstanceSubsystem`을 사용한다.

선택 기준은 다음과 같다.

- World의 Actor와 World 이벤트: `UWorldSubsystem`
- 로컬 플레이어별 UI와 입력 상태: `ULocalPlayerSubsystem`
- 레벨 전환을 넘어가는 게임 세션 서비스: `UGameInstanceSubsystem`
- 엔진 프로세스 전체에 정말 하나여야 하는 서비스: `UEngineSubsystem`

Subsystem을 단지 어디서나 접근하기 쉽다는 이유로 선택하지 않는다.

## 4. 실제 실행 흐름

### 4.1 대상 탐색

`UJMInteractionComponent`는 설정에 따라 Manual, OnInput, Timer, Tick 방식으로 Trace를 갱신한다.

시점 결정 우선순위는 다음과 같다.

1. Owner가 `IJMInteractorInterface`를 구현하면 그 위치와 방향
2. Pawn의 Controller 시점
3. Owner가 Controller이면 그 시점
4. Owner에 붙은 Camera Component
5. Actor 위치와 Forward Vector

Trace는 `TraceRadius == 0`이면 Line Trace, 0보다 크면 Sphere Sweep이다. 충돌한 Actor만 보는 것이 아니라 Hit Component Owner, Hit Actor, Owner Actor, Attach Parent Actor 후보에서 Actor 또는 Component의 `IJMInteractableInterface` 구현을 찾는다.

따라서 새 Interactable을 만들 때는 코드만 구현해서 끝나지 않는다. 대상의 Collision이 `TraceChannel`을 Block해야 한다.

### 4.2 시작과 완료

```text
Refresh target
→ CanInteract(Context)
→ BeginInteract(Context)
→ Duration 확인
   ├─ 0 이하: 즉시 CompleteInteract(Context)
   └─ 0 초과: Holding 상태, 외부가 적절한 시점에 CompleteInteraction 호출
→ OnInteractionFinished
```

취소나 비활성화에서는 `CancelInteract`를 호출하고 Weak Pointer와 상태를 정리한다. `EndPlay`에서도 Timer 중지, 취소, 대상 초기화를 수행한다.

### 4.3 입력과 UI의 책임

JMInteraction은 입력을 자동 바인딩하지 않는다. 호스트 게임이 Enhanced Input 등의 입력을 받아 `RefreshCurrentInteractable`, `TryBeginInteraction`, `CompleteInteraction`, `CancelInteraction`을 호출한다.

UI도 직접 만들지 않는다. UI는 `OnPromptChanged`, `GetCurrentPrompt`, `OnInteractionFinished`를 소비한다. 이 경계를 지켜야 특정 Character, Input Mapping, HUD를 강제하지 않는 휴대용 플러그인이 된다.

## 5. Door 시스템이 보여 준 올바른 플러그인 경계

### 5.1 JMDoor 코어가 JMInteraction을 의존하지 않는 이유

`JMDoorRuntime`의 책임은 문 상태, 명령, 접근, 이동, 장애물, 내구도, 저장 계약이다. “플레이어가 바라보고 E 키를 눌렀다”는 것은 Door 자체의 본질이 아니다.

그래서 Door 코어는 자체 공개 계약을 가진다.

- `FJMDoorUseContext`
- `FJMDoorResult`
- `UJMDoorComponent::ExecuteCommand`, `ToggleDoor` 등
- 접근/저장 Interface와 상태 Delegate

이 덕분에 Door는 JMInteraction 없이도 AI, 시퀀서, 레벨 스크립트, 네트워크 명령, 테스트 코드가 직접 사용할 수 있다.

### 5.2 Integration 플러그인이 번역한다

`JMDoorGameplayIntegration`만 Door, ItemInspector, InventorySystem을 함께 의존한다.

```text
UJMInteractionComponent
  → IJMInteractableInterface
  → UJMDoorInteractableAdapterComponent
  → FJMInteractionContext를 FJMDoorUseContext로 변환
  → UJMDoorComponent::ToggleDoor
```

`UJMDoorInteractionWorldSubsystem`은 Door 에셋이나 Door 코어를 수정하지 않고 World의 Door에 Transient Adapter를 하나씩 붙인다. 잠긴 문에 아이템 선택이 필요한 흐름도 Integration 쪽에서만 Inventory를 안다.

이 구조의 핵심은 **도메인 코어가 Integration을 모르고, Integration이 양쪽 공개 계약을 안다**는 것이다.

## 6. 새 플러그인을 JMInteraction과 연결하는 세 가지 방식

### 방식 A — 기능 플러그인이 직접 Interface를 구현

적합한 경우:

- 상호작용이 그 플러그인의 기본 진입 방식이다.
- `ItemInspector` 설치가 필수여도 괜찮다.
- 독립 사용 요구보다 제작 편의가 중요하다.

현재 예: `ReusableDialogueSystem`의 `UReuseDialogueInteractableComponent`.

비용: Dialogue만 필요해도 ItemInspector 전체가 필수 의존성이 된다.

### 방식 B — 별도 Integration 플러그인에 Adapter 구현

적합한 경우:

- 도메인 코어를 AI, 테스트, 다른 상호작용 시스템에서도 써야 한다.
- 여러 큰 기능 플러그인을 함께 알아야 한다.
- 휴대성과 독립 빌드가 중요하다.

현재 예: `JMDoor` + `JMDoorGameplayIntegration`.

새로운 대형 시스템에는 이 방식을 기본 후보로 삼는다.

### 방식 C — 소비자 플러그인 내부의 작은 Bridge/Integration 폴더

적합한 경우:

- A가 B를 명확하게 소비하고 역방향 참조가 없다.
- 연결 코드가 작고 A의 제품 기능에 가깝다.
- 별도 배포 단위까지 만들 필요는 없다.

현재 예: Inventory의 조사 가능한 Pickup, Inspector Bridge 계층.

### 선택 질문

```text
상호작용 없이도 코어 기능이 의미가 있는가?
  ├─ 예 → 코어는 자체 API 유지, Integration Adapter 우선
  └─ 아니오 → 직접 IJMInteractableInterface 구현 검토

두 개 이상의 독립 플러그인을 동시에 알아야 하는가?
  ├─ 예 → 별도 Integration 플러그인
  └─ 아니오 → 소비자 내부 Integration 폴더 가능
```

## 7. 의존성은 두 파일에서 함께 선언한다

### 7.1 `.uplugin`

플러그인 설치/활성화 의존성을 실제 플러그인 이름으로 선언한다.

```json
"Plugins": [
  { "Name": "ItemInspector", "Enabled": true }
]
```

### 7.2 `Build.cs`

C++ 컴파일 모듈 의존성을 실제 모듈 이름으로 선언한다.

```csharp
PublicDependencyModuleNames.AddRange(new[]
{
    "Core",
    "CoreUObject",
    "Engine",
    "ItemInspectorRuntime"
});
```

Public 헤더가 `FJMInteractionContext`나 `IJMInteractableInterface`를 노출하면 `ItemInspectorRuntime`은 Public Dependency다. `.cpp` 내부에서만 사용하고 Public 헤더에 새 모듈 타입이 보이지 않으면 Private Dependency를 검토한다.

`.uplugin`과 `Build.cs` 중 하나만 수정하면 다른 프로젝트로 복사했을 때 활성화 또는 링크 오류가 발생한다.

## 8. 새 Interactable 구현 체크리스트

1. `IJMInteractableInterface`를 Actor 또는 Actor Component에 구현한다.
2. `CanInteract`는 빠르고 부작용 없는 질의로 만든다.
3. `BeginInteract`는 예약/연출 시작 등 시작 단계만 담당한다.
4. 실제 성공 확정은 `CompleteInteract`에서 수행한다.
5. `CancelInteract`에서 임시 상태, Delegate, Timer, 입력/UI 상태를 원복한다.
6. `GetInteractionPrompt`는 `FText`, 표시 여부, Hold 시간, Priority를 일관되게 제공한다.
7. Context의 Actor/Controller/Target이 null이거나 파괴될 수 있음을 처리한다.
8. 대상 Collision이 Interaction Trace Channel을 Block하도록 설정한다.
9. 특정 Character/HUD/GameMode로 Cast하지 않는다.
10. 정상, 불허, 대상 파괴, 중복 실행, 취소, 설정 누락 경로를 테스트한다.

권장 뼈대:

```cpp
bool UMyInteractableComponent::CanInteract_Implementation(const FJMInteractionContext& Context) const
{
    return bEnabled && IsValid(GetOwner());
}

FJMInteractionResult UMyInteractableComponent::BeginInteract_Implementation(const FJMInteractionContext& Context)
{
    return CanInteract_Implementation(Context)
        ? FJMInteractionResult::Success()
        : FJMInteractionResult::Failure(EJMInteractionResultCode::NotAllowed, FailureText);
}

FJMInteractionResult UMyInteractableComponent::CompleteInteract_Implementation(const FJMInteractionContext& Context)
{
    // 도메인 API 호출 후 그 결과를 FJMInteractionResult로 변환
}
```

## 9. 새 기능 플러그인을 설계할 때 필요한 전체 지식

### 9.1 책임과 비책임부터 쓴다

코드보다 먼저 `Docs/ARCHITECTURE.md`에 플러그인이 소유하는 것과 소유하지 않는 것을 쓴다. Door 사례처럼 입력, UI, 인벤토리, 저장 파일 I/O, AI까지 한 플러그인이 소유하지 않게 경계를 정한다.

### 9.2 도메인 API를 Interaction API와 동일시하지 않는다

Interaction은 기능을 호출하는 하나의 입구다. Door의 본체는 `ToggleDoor`, Dialogue의 본체는 `StartDialogue`, Inventory의 본체는 `TryPickup`이다.

좋은 구조:

```text
여러 진입점(Interaction / AI / Script / Test)
                    ↓
              도메인 공개 API
                    ↓
              도메인 상태와 규칙
```

나쁜 구조는 실제 기능을 `CompleteInteract` 안에만 박아 두어 다른 시스템이 재사용할 수 없게 만드는 것이다.

### 9.3 데이터와 정책을 코드에서 분리한다

- 밸런스와 콘텐츠: Data Asset
- 프로젝트 기본값: Developer Settings
- 의미와 조건: Gameplay Tag
- 선택 에셋: Soft Object/Class Reference
- 사용자 표시 문구: `FText`

`/Game/...` 경로, 특정 Blueprint 클래스, 레벨 Actor 이름을 Runtime 코드에 하드코딩하지 않는다.

### 9.4 Runtime과 Editor를 분리한다

Shipping에서 필요한 모듈에 `UnrealEd`, `AssetTools`, Editor Widget 코드를 넣지 않는다. 샘플 생성 Commandlet, 상세 패널, 자동 에셋 생성은 별도 Editor/Test 모듈로 분리한다. `JMDoorRuntime`과 `JMDoorTests` 분리가 기준 사례다.

### 9.5 상태 머신과 실패 복구를 명시한다

Idle, Targeting, Interacting, Holding, Disabled 같은 상태와 허용 전이를 문서로 먼저 정의한다. 모든 종료 경로에서 다음을 확인한다.

- Weak Pointer 초기화
- Timer/Tick 중지
- Delegate binding 해제
- 입력 모드와 커서 복구
- UI 제거
- 중간 예약 상태 취소

### 9.6 네트워크 권한을 별도로 설계한다

현재 JMInteraction과 JMDoor 흐름은 자동 Replication/RPC를 제공하지 않는다. 멀티플레이에서는 클라이언트 Trace가 선택한 대상을 서버가 거리, 시야, 상태, 접근 권한으로 다시 검증해야 한다. Inventory 소비와 Door 상태 변경은 서버 권한 명령 뒤에서 실행한다.

“Blueprint에서 실행된다”와 “멀티플레이에서 안전하다”는 전혀 다른 조건이다.

### 9.7 저장은 외부 시스템에 계약만 제공한다

기능 플러그인이 특정 SaveGame 클래스나 슬롯 이름을 알지 않게 한다. 안정적인 Persistent ID, Save Record, Capture/Restore API만 제공하고 파일 I/O는 호스트 Save 시스템이 맡는다.

## 10. 현재 JMInteraction의 한계와 주의점

현재 코드를 사용할 때 다음을 알고 있어야 한다.

### 10.1 독립 Core가 아니다

Interaction API가 `ItemInspectorRuntime` 안에 있어 Dialogue, Inventory 같은 소비자는 조사 기능까지 포함한 `ItemInspector` 플러그인을 필수 설치해야 한다. 플러그인이 더 늘면 이름과 책임이 맞지 않는 기반 의존성이 된다.

### 10.2 Hold 진행을 자동 완료하지 않는다

Duration이 0보다 크면 상태를 `Holding`으로 바꾸지만, 현재 Component 자체에는 Hold Timer나 Progress Delegate가 없다. 입력 계층이 시간 측정과 취소/완료 호출을 책임져야 한다. 새 UI가 `HoldDuration`만 읽고 자동 완료될 것이라고 가정하면 안 된다.

### 10.3 Priority는 현재 탐색 선택에 사용되지 않는다

Prompt와 Interface에 Priority가 있지만 현재 탐색은 Single Trace의 첫 유효 구현체를 반환한다. 여러 겹의 후보 중 최고 Priority를 정렬하는 시스템은 아니다.

### 10.4 InteractionTag는 Context 생성 시 자동 지정되지 않는다

구조체에 `InteractionTag`가 있지만 현재 `BuildInteractionContext()`는 이 값을 채우지 않는다. 태그별 행동 분기를 도입하려면 어떤 계층이 태그를 선택하고 Context에 넣는지 API를 먼저 설계해야 한다.

### 10.5 자동 Trace와 진행 상태의 상호작용을 검토해야 한다

`SetCurrentInteractable()`은 대상 변경 때 상태를 Targeting 또는 Idle로 설정한다. Tick/Timer 탐색이 Holding 중에도 계속된다면 진행 상태와 충돌할 여지가 있으므로 Hold 기능을 확장할 때 상태 전이 테스트가 필요하다.

### 10.6 단일 플레이 기준이다

거리 Trace, 대상 선택, 완료 호출에 서버 검증이 없고 상태가 복제되지 않는다. 네트워크 지원을 표방하려면 Authority, RPC, 검증, 예측/취소 정책을 별도로 추가해야 한다.

### 10.7 문서와 주석보다 실제 의존 선언을 우선 확인해야 한다

현재 저장소에도 과거 설계 의도가 남은 주석과 현재 코드가 어긋난 부분이 있다.

- `UReuseDialogueInteractableComponent`의 주석은 두 플러그인이 직접 의존하지 않는다고 표현하지만, 실제 `ReusableDialogueSystem.uplugin`은 `ItemInspector`를 필수 활성화하고 `ReusableDialogueSystem.Build.cs`는 `ItemInspectorRuntime`을 Public Dependency로 사용한다.
- Inventory 문서 일부는 `InventorySystem`이 `ItemInspectorRuntime`을 참조하지 않는다고 적혀 있지만, 현재 `InventorySystem.uplugin`과 `InventorySystem.Build.cs`에는 직접 의존성이 선언되어 있다.

따라서 의존성 조사 순서는 **`.uplugin` → `Build.cs` → Public 헤더 include/노출 타입 → 구현 코드 → 문서와 주석**으로 잡는다. 차이를 발견하면 코드를 현재 사실로 기록하고 문서와 주석을 같은 변경에서 갱신해야 한다.

## 11. 언제 `JMInteractionCore`로 분리해야 하는가

지금 당장 같은 타입을 복제해 새 Core를 만드는 것은 더 나쁘다. 기존 Blueprint, C++ Public API, 에셋 참조가 깨질 수 있기 때문이다.

다음 신호가 누적되면 계획된 추출을 진행한다.

- 3개 이상의 독립 플러그인이 Interaction/Core 타입만 사용한다.
- 조사 기능이 필요 없는데 ItemInspector 전체를 설치해야 하는 경우가 반복된다.
- 공통 Context, Result, Tag, 로그 타입이 여러 곳에 복제되기 시작한다.
- 순환 의존성을 피하려고 부자연스러운 콜백이나 중복 Adapter가 생긴다.

권장 목표 구조:

```text
JMInteractionCore
  ├─ Interaction Context / Result / Prompt
  ├─ Interactor / Interactable Interface
  ├─ Interaction Component
  └─ Interaction Settings / Tags

ItemInspector ───────────────> JMInteractionCore
InventorySystem ─────────────> JMInteractionCore
ReusableDialogueSystem ──────> JMInteractionCore
JMDoorGameplayIntegration ───> JMInteractionCore + JMDoor + Inventory
```

추출할 때는 다음이 필수다.

1. 기존 클래스/구조체 이름과 Blueprint 경로의 호환 계획
2. Core Redirect 또는 단계적 Deprecated API
3. `.uplugin`과 `Build.cs` 의존성 마이그레이션
4. ItemInspector가 새 Core를 소비하도록 방향 역전
5. 빈 프로젝트 복사 테스트와 Blueprint Asset 로드 테스트

## 12. 피해야 할 시행착오

- 기능마다 `MyDoorInteractable`, `MyDialogueInteractable` 전용 Interface를 새로 만들어 공통 호출 흐름을 복제한다.
- 순환 의존성을 피한다며 동일한 Context/Result 구조체를 플러그인마다 복사한다.
- 기반 플러그인이 자신을 소비하는 상위 기능 플러그인을 참조한다.
- Door 코어가 Player Character, Inventory Component, HUD를 직접 찾는다.
- `GetActorOfClass`나 전역 검색을 입력마다 반복한다.
- 모든 Component를 Tick시키고 이벤트/Timer로 충분한 경우를 구분하지 않는다.
- Public 헤더에 다른 모듈 타입을 노출하면서 Private Dependency로만 선언한다.
- 플러그인을 “선택 의존성”이라고 문서화하면서 실제 Build.cs에는 필수 링크가 있다.
- Soft Reference 로드 실패, null 설정, 대상 파괴, UI 열기 실패를 정상 실패 경로로 다루지 않는다.
- 도메인 기능을 Interaction 구현 안에만 넣어 AI, 테스트, Script 재사용을 막는다.

## 13. 새 플러그인 개발 순서

1. 기존 `.uplugin`, `Build.cs`, `Public`, `Docs`에서 재사용 가능한 계약을 검색한다.
2. 책임/비책임과 독립 설치 범위를 정한다.
3. 도메인 Context, Result, 상태, 명령 API를 먼저 설계한다.
4. Interaction이 필수인지 선택 Integration인지 결정한다.
5. 모듈과 플러그인 의존 방향을 그림으로 검증한다.
6. Runtime Core를 구현하고 직접 API 테스트를 만든다.
7. Adapter/Bridge로 `FJMInteractionContext`를 도메인 Context로 변환한다.
8. Settings, Data Asset, Soft Reference, Gameplay Tag를 연결한다.
9. 취소, 대상 파괴, 설정 누락, 중복 요청, 레벨 전환을 테스트한다.
10. 전체 Editor 빌드, Automation Test, 빈 프로젝트 복사 검증을 수행한다.

## 14. 완료 판단 체크리스트

- [ ] 플러그인의 핵심 기능을 JMInteraction 없이도 호출할 필요가 있는지 판단했다.
- [ ] 직접 의존과 Integration 분리 중 하나를 의식적으로 선택했다.
- [ ] 기반 계층이 소비자 구체 클래스를 참조하지 않는다.
- [ ] `.uplugin` 플러그인 이름과 `Build.cs` 모듈 이름을 모두 정확히 선언했다.
- [ ] Public Dependency와 Private Dependency를 헤더 노출 기준으로 나눴다.
- [ ] `CanInteract`가 빠르고 부작용 없는 질의다.
- [ ] Begin/Complete/Cancel의 책임과 상태 복구가 분명하다.
- [ ] 사용자 문구는 `FText`, 의미 식별은 Gameplay Tag를 사용한다.
- [ ] 장기 비소유 참조와 Delegate/Timer 수명을 안전하게 관리한다.
- [ ] 특정 Character, HUD, GameMode, `/Game/...` 경로에 묶이지 않는다.
- [ ] UI, 입력, 도메인 상태의 소유자가 분리되어 있다.
- [ ] 단독 설치, 필수 플러그인, 실패 시 동작을 문서화했다.
- [ ] 정상/실패/취소/파괴/중복/레벨 전환 테스트가 있다.
- [ ] 네트워크와 저장 지원 범위를 과장하지 않는다.

## 15. 이 프로젝트에서 우선 읽을 실제 코드

1. `ItemInspector/Source/ItemInspectorRuntime/Public/Core/JMGameplayTypes.h`
2. `ItemInspector/Source/ItemInspectorRuntime/Public/Interaction/JMInteractorInterface.h`
3. `ItemInspector/Source/ItemInspectorRuntime/Public/Interaction/JMInteractableInterface.h`
4. `ItemInspector/Source/ItemInspectorRuntime/Public/Interaction/JMInteractionComponent.h`
5. `ItemInspector/Source/ItemInspectorRuntime/Private/Interaction/JMInteractionComponent.cpp`
6. `ReusableDialogueSystem/.../ReuseDialogueInteractableComponent.*`
7. `JMDoor/Source/JMDoorRuntime/Public/Door/JMDoorComponent.h`
8. `JMDoorGameplayIntegration/.../JMDoorInteractableAdapterComponent.*`
9. `JMDoorGameplayIntegration/.../JMDoorInteractionWorldSubsystem.*`
10. 각 플러그인의 `.uplugin`, `Build.cs`, `Docs/ARCHITECTURE.md`

가장 중요한 결론은 하나다.

> **JMInteraction은 여러 기능을 한 플러그인에 섞는 도구가 아니라, 서로 다른 기능이 구체 구현을 모른 채 만나는 공통 입구다. 도메인 코어의 독립성을 먼저 지키고, 필요한 곳에서 Adapter로 이 입구에 연결해야 재사용성이 생긴다.**
