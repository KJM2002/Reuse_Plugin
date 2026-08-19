---
title: "P_260729 게임 프로그래머 신입 포트폴리오 면접 질문 150선"
status: Current
authority: Guide
scope: Study
last_verified: 2026-08-20
verified_against: "7c765f0348e2d6a766b83ccacf936e14d3122971"
owners:
  - Project Documentation
related:
  - README.md
  - ../Architecture/Architecture_Audit_KO.md
  - ../Architecture/PLUGIN_DEPENDENCY_GRAPH.md
  - ../Architecture/GAMEPLAY_EVENT_FLOW.md
---

# P_260729 게임 프로그래머 신입 포트폴리오 면접 질문 150선

이 문서는 `P_260729`의 Host와 21개 Plugin, Runtime·Editor·Test Module의 실제 코드를 근거로 만든 면접 대비 자료다. “좋은 답변”은 일반 원칙, “현재 프로젝트 코드를 기반으로 한 답변”은 이 저장소에서 직접 확인한 구현을 말한다. “부족한 부분”은 숨겨야 할 약점이 아니라 면접에서 개선 방향까지 설명할 항목이다.

## 구성

| 난이도 | 문항 |
|---|---:|
| 초급 | 30 |
| 중급 | 50 |
| 고급 | 50 |
| 압박 질문 | 20 |
| 합계 | 150 |

## 시스템별 질문 색인

| 대상 | 주요 질문 |
|---|---|
| `JMGameplayEvent` | Q017, Q032~Q037, Q083~Q090, Q102, Q127, Q132~Q133 |
| `JMInteraction` | Q014~Q016, Q022, Q042~Q046, Q091 |
| `ItemInspector` | Q054~Q056, Q103~Q104, Q136 |
| `InventorySystem` | Q006~Q010, Q021, Q047~Q056, Q099~Q101, Q138~Q139 |
| `ReusableDialogueSystem` | Q023, Q057~Q059, Q105~Q106, Q137 |
| `JMDoor` | Q024~Q025, Q060~Q064, Q098, Q107~Q110, Q142 |
| `JMDoorGameplayIntegration` | Q031, Q065, Q082, Q093, Q141 |
| `JMJumpScare` | Q066~Q067, Q147~Q148 |
| `JMObjective` | Q038~Q041 |
| `JMRecon` | Q068~Q070, Q096~Q097, Q111~Q115 |
| `JMReconGameplayIntegration` | Q071, Q093, Q141 |
| `JMDoorReconIntegration` | Q072, Q082 |
| `JMFootstep` | Q027, Q077 |
| `JMHide` | Q073~Q076, Q111~Q116, Q144 |
| `JMHideInteractionIntegration` | Q042, Q076, Q093 |
| `JMHideDoorIntegration` | Q076, Q082 |
| `JMRoomGrid` | Q002~Q004, Q028, Q078 |
| `JMPhysicalGrabber` | Q029, Q143 |
| `JMThrowable` | Q029, Q079 |
| `JMThrowableGameplayIntegration` | Q031, Q079, Q082 |
| `JMMonsterFramework` | Q080, Q117~Q120, Q145 |
| Host `P_060715` | Q001, Q018, Q078, Q088, Q117, Q130, Q139, Q145 |

질문 수가 코드 파일 수와 같지는 않다. 각 질문은 여러 파일의 호출 관계를 묶어 평가하며, 상세 근거는 관련 챕터와 아키텍처 감사 문서에서 이어서 확인한다.

---

## 초급 질문 30개

### Q001

- **질문:** 이 프로젝트의 전체 구조를 한 문장으로 설명해 보세요.
- **질문 의도:** 큰 코드베이스의 책임과 계층을 요약할 수 있는지 본다.
- **좋은 답변:** Host는 조립을, 기능 Plugin은 독립 도메인을, Integration Plugin은 기능 간 연결을 맡는다고 계층 중심으로 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `P_060715` Host 위에 `JMInteraction`·`JMGameplayEvent` 계약층, Inventory·Door·Recon·Hide 등 기능층, Door/Hide/Throwable Integration층이 놓인 21개 Plugin 구조다.
- **추가 꼬리 질문:** Host가 직접 참조하는 Plugin이 너무 많아지면 무엇이 문제인가요?
- **부족한 부분:** `P_060715.Build.cs`의 직접 의존 범위가 넓어 Host 조립과 프로젝트 gameplay 책임이 덜 분리돼 있다.

### Q002

- **질문:** Unreal Plugin과 Module의 차이는 무엇인가요?
- **질문 의도:** 배포 단위와 컴파일·로딩 단위를 구분하는지 확인한다.
- **좋은 답변:** Plugin은 기능 묶음과 활성화 단위이며, Module은 UBT가 빌드하고 Module Manager가 로드하는 C++ 경계다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMRoomGrid.uplugin` 하나 안에 `JMRoomGridRuntime`, `JMRoomGridEditor`, `JMRoomGridTests` 세 Module이 선언돼 같은 Plugin에서도 실행 대상을 분리한다.
- **추가 꼬리 질문:** Test Module의 LoadingPhase가 `PostEngineInit`인 이유는 무엇인가요?
- **부족한 부분:** Module 수가 많아 descriptor와 `Build.cs` 그래프를 함께 보지 않으면 실제 결합을 파악하기 어렵다.

### Q003

- **질문:** `.uplugin` 파일에서 중요하게 보는 항목은 무엇인가요?
- **질문 의도:** Plugin 로딩과 의존 선언을 읽을 수 있는지 본다.
- **좋은 답변:** Module Name·Type·LoadingPhase, Plugin 의존성, CanContainContent, EnabledByDefault, target allow-list를 확인한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMGameplayEvent.uplugin`은 Runtime을 `Default`, Tests를 Editor `PostEngineInit`으로 두고 `TargetAllowList: Editor`로 제한한다.
- **추가 꼬리 질문:** `EnabledByDefault`를 모든 Plugin에 쓰면 어떤 문제가 생기나요?
- **부족한 부분:** 다수 Plugin이 기본 활성화돼 최소 기능만 쓰는 프로젝트에서도 불필요한 Plugin closure가 커질 수 있다.

### Q004

- **질문:** `Build.cs`의 Public과 Private dependency 차이는 무엇인가요?
- **질문 의도:** C++ API 전파와 빌드 결합을 이해하는지 확인한다.
- **좋은 답변:** Public header가 노출하는 타입의 Module은 Public, 구현 파일에서만 쓰는 Module은 Private에 둬 소비자에게 의존성이 전파되지 않게 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMRoomGridEditor.Build.cs`는 `JMRoomGridRuntime`과 `UnrealEd`·`AssetTools` 등을 Private에 두며 Runtime Module은 Editor 의존성을 갖지 않는다.
- **추가 꼬리 질문:** Public dependency를 과하게 두면 어떤 비용이 있나요?
- **부족한 부분:** `JMThrowable`의 `AIModule`처럼 구현 전용으로 보이는 Module이 Public에 있고 일부 미사용 의존성 후보도 있다.

### Q005

- **질문:** `UCLASS`와 `GENERATED_BODY`는 왜 필요한가요?
- **질문 의도:** Unreal Reflection의 기본을 설명할 수 있는지 본다.
- **좋은 답변:** UHT가 타입 정보를 생성해 직렬화, GC, Blueprint, Editor 노출에 참여하게 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryItemDefinition`은 `UCLASS(BlueprintType)`과 `GENERATED_BODY()`로 Primary Data Asset과 Blueprint 타입 시스템에 참여한다.
- **추가 꼬리 질문:** 일반 C++ 클래스와 UObject의 생성 방식은 어떻게 다른가요?
- **부족한 부분:** Reflection 노출 범위가 넓은 API는 Blueprint 계약 유지 비용을 증가시키므로 필요한 항목만 공개해야 한다.

### Q006

- **질문:** `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)`를 왜 사용했나요?
- **질문 의도:** Editor 저작 권한과 런타임 변경 권한을 구분하는지 본다.
- **좋은 답변:** Asset 기본값은 Designer가 편집하되 Blueprint가 실행 중 임의로 변경하지 못하게 하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `InventoryItemDefinition.h`의 `ItemId`, `DisplayName`, `ItemTags`가 이 조합을 사용해 정의 Asset을 읽기 중심 계약으로 만든다.
- **추가 꼬리 질문:** `EditAnywhere`와 `VisibleInstanceOnly`는 언제 쓰나요?
- **부족한 부분:** `ItemId` 중복이나 `None`을 막는 validation이 더 강하게 필요하다.

### Q007

- **질문:** `TObjectPtr`와 `TWeakObjectPtr`를 어떻게 구분해 사용하나요?
- **질문 의도:** UObject 소유와 비소유 참조를 이해하는지 본다.
- **좋은 답변:** 소유자가 GC에 참조를 알려야 하면 `TObjectPtr`, 대상 수명을 연장하지 않고 유효성만 관찰하면 `TWeakObjectPtr`를 사용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMGameplayEventMessage::Payload`는 `TObjectPtr<UObject>`이고, event subscription listener와 Recon/Hide session 대상은 weak pointer로 저장된다.
- **추가 꼬리 질문:** weak pointer를 사용해도 callback 전에 무엇을 해야 하나요?
- **부족한 부분:** weak pointer는 thread safety나 논리적 세션 유효성을 보장하지 않아 SessionId·state 검사도 함께 필요하다.

### Q008

- **질문:** Soft reference를 사용하는 이유는 무엇인가요?
- **질문 의도:** Asset 로딩 결합을 이해하는지 확인한다.
- **좋은 답변:** Asset을 경로로 보관해 즉시 hard-load와 강한 cook dependency를 피하고 필요 시 로드하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryItemDefinition`의 `Icon`·`InspectMesh`·`WorldItemClass`와 `UInventorySystemSettings`의 Widget/Input/Sound가 `TSoftObjectPtr` 또는 `TSoftClassPtr`다.
- **추가 꼬리 질문:** `LoadSynchronous`의 단점은 무엇인가요?
- **부족한 부분:** UI·Recon 등 첫 사용 경로의 동기 로드가 frame hitch를 만들 수 있어 preload 정책이 필요하다.

### Q009

- **질문:** 이 프로젝트에서 Data Asset은 어떤 역할을 하나요?
- **질문 의도:** 코드와 콘텐츠 데이터의 분리를 설명할 수 있는지 본다.
- **좋은 답변:** 변하지 않는 정의와 조정 값을 Asset에 두고 런타임 상태는 Component나 Subsystem에 둔다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryItemDefinition`은 아이템 정의, `UDialogueSequence`는 대사 줄, `UJMObjectiveDefinition`은 이벤트 필터, `UJMEnemyDefinition`은 enemy 조립 데이터를 소유한다.
- **추가 꼬리 질문:** Data Table 대신 Data Asset을 선택할 이유는 무엇인가요?
- **부족한 부분:** Asset 간 ID 중복과 참조 유효성을 전 Plugin 공통 validation으로 통합하지 않았다.

### Q010

- **질문:** `UDeveloperSettings`를 어디에 사용했나요?
- **질문 의도:** 프로젝트 기본값과 config 연결을 이해하는지 본다.
- **좋은 답변:** Plugin 코드를 수정하지 않고 Project Settings와 config에서 기본 Asset·수치·정책을 바꿀 때 사용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventorySystemSettings(Config=Game, DefaultConfig)`가 기본 슬롯 수, Widget, InputAction, drop trace 값을 제공한다.
- **추가 꼬리 질문:** instance override와 settings가 모두 있으면 우선순위는 어떻게 정하나요?
- **부족한 부분:** Recon/Hide 등 시스템마다 override 합성 방식이 달라 공통 우선순위 규칙이 더 필요하다.

### Q011

- **질문:** ActorComponent 기반으로 기능을 나눈 이유는 무엇인가요?
- **질문 의도:** 상속보다 조합을 선택하는 기준을 확인한다.
- **좋은 답변:** Host Actor 계층을 강제하지 않고 Inventory·Interaction·Recon 같은 기능을 필요한 조합으로 붙이기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryComponent`, `UJMInteractionComponent`, `UJMReconInteractorComponent`, `UJMHideInteractorComponent`가 각각 상태와 API를 소유한다.
- **추가 꼬리 질문:** 필요한 companion component가 없으면 어떻게 처리해야 하나요?
- **부족한 부분:** 일부 Integration은 호출 시 companion component를 동적 생성해 Blueprint에서 구성이 보이지 않는 문제가 있다.

### Q012

- **질문:** `BeginPlay`와 `EndPlay`에서 주로 무엇을 처리했나요?
- **질문 의도:** Unreal 객체 수명에 맞춘 초기화와 정리를 아는지 본다.
- **좋은 답변:** BeginPlay에서 runtime binding·timer·상태를 시작하고 EndPlay에서 delegate·timer·동적 UI·외부 handle을 대칭 해제한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMGameplayEventListenerComponent`는 BeginPlay에 구독하고 EndPlay에 모든 handle을 해제하며, `UInventoryUIComponent`는 EndPlay에서 Widget과 입력 상태를 정리한다.
- **추가 꼬리 질문:** destructor만으로 처리하면 안 되는 이유는 무엇인가요?
- **부족한 부분:** 모든 Component의 registration과 cleanup 대칭성을 자동 검사하는 공통 수단은 없다.

### Q013

- **질문:** Tick을 항상 켜 두지 않은 예를 설명해 보세요.
- **질문 의도:** 프레임 비용을 상태에 맞춰 제어하는지 확인한다.
- **좋은 답변:** 매 frame 작업이 필요한 활성 구간에만 tick을 켜고 완료·취소 시 끈다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorComponent::BeginMovement`가 이동 시 tick을 켜고 Open/Closed 도달 후 끄며, `UJMHideSimplePanelMechanismComponent`도 활성 SessionId가 없으면 tick을 비활성화한다.
- **추가 꼬리 질문:** Interaction 탐지는 Tick 외에 어떤 방식을 지원하나요?
- **부족한 부분:** 물리·Interaction·Preview 등 여러 상시 또는 조건부 tick을 대규모 Actor 환경에서 profile한 결과는 코드에 없다.

### Q014

- **질문:** Unreal Interface를 왜 사용했나요?
- **질문 의도:** 다중 구현과 Blueprint 호환 계약을 이해하는지 본다.
- **좋은 답변:** 구체 Actor 상속을 강제하지 않고 Actor나 Component가 같은 기능 계약을 구현하게 하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMInteractionComponent`는 `IJMInteractableInterface`만 호출하므로 Pickup, Dialogue, Door adapter, Hide adapter를 같은 흐름으로 처리한다.
- **추가 꼬리 질문:** interface 지원 여부는 어떻게 확인하고 호출하나요?
- **부족한 부분:** Interface 기본 구현이 조용히 실패하면 구현 누락이 런타임까지 드러나지 않을 수 있다.

### Q015

- **질문:** `BlueprintNativeEvent` 함수는 C++에서 어떻게 구현하고 호출하나요?
- **질문 의도:** `_Implementation`과 `Execute_*` 규칙을 아는지 본다.
- **좋은 답변:** C++ 구현자는 `함수_Implementation`을 override하고 호출자는 Blueprint override까지 통과하는 `IInterface::Execute_함수`를 사용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorInteractableAdapterComponent::CompleteInteract_Implementation`이 Door toggle을 구현하고 `UJMInteractionComponent`가 `Execute_CompleteInteract`로 호출한다.
- **추가 꼬리 질문:** C++ virtual 함수를 직접 호출하면 어떤 구현을 놓칠 수 있나요?
- **부족한 부분:** Interface 함수 수가 늘어 focus·prompt·execution 책임이 한 계약에 집중될 가능성이 있다.

### Q016

- **질문:** Delegate는 이 프로젝트에서 어떻게 사용되나요?
- **질문 의도:** event 기반 결합과 callback 수명을 이해하는지 본다.
- **좋은 답변:** 상태 소유자가 변경을 broadcast하고 소비자가 수명에 맞춰 bind/unbind해 polling과 직접 참조를 줄인다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryComponent::OnInventoryChanged`는 dynamic multicast이며 UI는 `AddUniqueDynamic`으로 연결하고 종료 시 `RemoveDynamic`한다.
- **추가 꼬리 질문:** native delegate와 dynamic multicast의 차이는 무엇인가요?
- **부족한 부분:** 중복 구독 정책이 시스템마다 다르고 모든 bind/unbind 쌍이 RAII로 강제되지는 않는다.

### Q017

- **질문:** GameplayTag를 enum 대신 사용한 이유는 무엇인가요?
- **질문 의도:** 계층형 식별과 데이터 기반 확장을 이해하는지 본다.
- **좋은 답변:** Plugin별로 tag를 확장하고 부모·자식 matching과 Editor 저작을 활용하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMGameplayEventMessage::EventTag`와 `Exact/IncludeChildren` 구독으로 `Event.Inventory.Item.Acquired` 같은 계층 event를 routing한다.
- **추가 꼬리 질문:** 문자열 기반 계약의 오타는 어떻게 막나요?
- **부족한 부분:** 일부 Plugin tags에 예제·테스트·다른 도메인 소유권이 섞여 tag governance가 더 필요하다.

### Q018

- **질문:** GameInstance, World, LocalPlayer Subsystem 차이를 설명해 보세요.
- **질문 의도:** 서비스 상태의 적절한 수명 선택 능력을 본다.
- **좋은 답변:** 레벨을 넘는 상태는 GameInstance, 현재 map 상태는 World, 플레이어별 UI는 LocalPlayer 범위에 둔다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMGameplayEventSubsystem`·Objective·Host `UJMPrototypeTravelTransitionSubsystem`은 GameInstance, `UJMJumpScareSubsystem`은 World, ItemInspection·ObjectiveUI는 LocalPlayer다.
- **추가 꼬리 질문:** split-screen에서 GameInstance UI 상태를 쓰면 어떤 문제가 생기나요?
- **부족한 부분:** Dialogue가 GameInstance 수명이므로 level travel 중 active dialogue 정책을 더 명시해야 한다.

### Q019

- **질문:** `FName`, `FText`, `FGuid`를 각각 어디에 사용했나요?
- **질문 의도:** Unreal 기본 데이터 타입의 목적을 구분하는지 본다.
- **좋은 답변:** `FName`은 비교 중심 식별자, `FText`는 현지화 표시문, `FGuid`는 세션·instance의 고유 identity에 사용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory의 `ItemId`는 FName, `DisplayName`은 FText, 슬롯 `InstanceId`와 Recon/Hide `SessionId`는 FGuid다.
- **추가 꼬리 질문:** 저장 데이터에 UObject pointer 대신 무엇을 써야 하나요?
- **부족한 부분:** 안정 ID의 중복·변경·migration 정책이 모든 도메인에 동일하게 적용되지는 않았다.

### Q020

- **질문:** bool 대신 Result enum과 struct를 사용한 이유는 무엇인가요?
- **질문 의도:** 실패 원인을 API 계약으로 표현하는 습관을 본다.
- **좋은 답변:** 호출자가 실패 이유, 부분 성공량, 메시지를 구분해 UI와 복구 정책을 결정하도록 하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FInventoryAddOutcome`은 Added/Remaining을, `FJMInteractionResult`과 `FJMDoorResult`는 성공 여부·code·message를 제공한다.
- **추가 꼬리 질문:** exception 대신 Result를 쓰는 Unreal gameplay상의 이점은 무엇인가요?
- **부족한 부분:** 일부 legacy bool API가 detailed API와 함께 남아 호출자가 정보를 버릴 수 있다.

### Q021

- **질문:** `UInventoryComponent::AddItemDetailed`의 기본 흐름을 설명해 보세요.
- **질문 의도:** 실제 도메인 코드를 읽고 순서를 설명할 수 있는지 본다.
- **좋은 답변:** 입력 검증, 수용 가능량 계산, 기존 stack 채우기, 빈 slot 생성, 결과·event 발행 순으로 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 이 함수는 무게와 stack limit을 반영해 기존 stack부터 채우고 새 stack에 GUID를 부여한 뒤 requested/added/remaining outcome을 반환한다.
- **추가 꼬리 질문:** 부분 추가는 성공인가 실패인가요?
- **부족한 부분:** pointer 동일성과 `ItemId` 동일성을 사용하는 stack 규칙을 API별로 더 명확히 통일할 필요가 있다.

### Q022

- **질문:** `UJMInteractionComponent`는 상호작용 대상을 어떻게 찾나요?
- **질문 의도:** trace와 Interface 탐색 흐름을 이해하는지 본다.
- **좋은 답변:** view/cursor에서 line 또는 sweep trace를 하고 hit actor·owner·attach parent에서 Interface 구현체를 해석한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `RefreshCurrentInteractable`이 MouseCursorTrace 또는 view 방향을 선택하고 `FindInteractable`과 `ResolveInteractableFromHit`로 대상과 Actor를 저장한다.
- **추가 꼬리 질문:** Tick, Timer, OnInput 탐지 모드의 차이는 무엇인가요?
- **부족한 부분:** 탐지·prompt·modal·execution이 한 Component에 모여 책임이 넓다.

### Q023

- **질문:** 대화 타이핑 효과는 어떻게 구현했나요?
- **질문 의도:** 문자열 처리와 timer 상태를 설명하는지 본다.
- **좋은 답변:** text를 token화하고 token별 delay를 계산해 timer로 공개하며 취소 시 timer를 정리한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FDialogueTokenizer`가 Word/Character token을 만들고 `UDialogueSubsystem::RevealNextToken`이 문장부호 delay를 더해 다음 timer를 예약한다.
- **추가 꼬리 질문:** 한글과 emoji에서 주의할 점은 무엇인가요?
- **부족한 부분:** surrogate pair는 보존하지만 완전한 Unicode grapheme cluster 분리는 아니다.

### Q024

- **질문:** Door의 상태와 움직임을 어떻게 분리했나요?
- **질문 의도:** 상태 머신과 전략 패턴의 기초를 확인한다.
- **좋은 답변:** 도메인 상태는 Door Component, transform 계산은 movement strategy에 둔다고 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorComponent`가 Open/Closed/Opening/Closing/Blocked를 관리하고 `UJMRotatingDoorMovementComponent`와 `UJMSlidingDoorMovementComponent`가 fraction→transform을 계산한다.
- **추가 꼬리 질문:** custom door movement를 추가하려면 어디를 확장하나요?
- **부족한 부분:** dual panel 세부 상태가 core Door Component에 들어와 전략 분리가 완전하지는 않다.

### Q025

- **질문:** Door 저장 데이터가 version을 갖는 이유는 무엇인가요?
- **질문 의도:** save schema migration의 기본을 이해하는지 본다.
- **좋은 답변:** 구조 변경 후에도 이전 save를 해석하고 지원하지 않는 version을 안전하게 거부하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMDoorSaveData::Version`은 2이며 `RestoreSaveData`가 v1 single-panel fraction을 panel A에 적용하고 panel B는 0으로 migration한다.
- **추가 꼬리 질문:** `PersistentId` 불일치 시 왜 거부하나요?
- **부족한 부분:** 향후 version chain과 자동 migration framework는 없고 지원 version을 조건문으로 직접 관리한다.

### Q026

- **질문:** 인벤토리 UI를 닫을 때 입력 상태는 어떻게 복원하나요?
- **질문 의도:** UMG가 gameplay 입력 상태를 빌리고 돌려주는 수명을 이해하는지 본다.
- **좋은 답변:** 열기 전 cursor·move/look block·focus 상태를 저장하고 자신이 바꾼 것만 종료 시 되돌린다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryUIComponent::ApplyInputMode`가 이전 상태와 적용 flag를 저장하고 `FinalizeCloseInventory`에서 delegate 제거 후 `RestoreInputMode`를 호출한다.
- **추가 꼬리 질문:** 기존 `FInputMode` 자체도 완전히 복원되나요?
- **부족한 부분:** 임의의 기존 input mode를 capture하지 않고 cursor 상태를 바탕으로 GameOnly/GameAndUI를 재구성한다.

### Q027

- **질문:** 발소리 시스템은 어떤 정보를 사용해 소리를 고르나요?
- **질문 의도:** 독립 Component의 입력과 출력 흐름을 읽었는지 본다.
- **좋은 답변:** 이동 거리, 바닥 trace의 physical surface, 보행 variant를 이용해 3D sound를 선택한다고 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMFootstepComponent`가 이동 누적과 surface trace를 처리하고 `UJMFootstepSettings`·정의 데이터에 따라 발소리를 재생한다.
- **추가 꼬리 질문:** Animation Notify 방식과 비교하면 어떤 차이가 있나요?
- **부족한 부분:** 거리 기반 방식은 발 animation의 실제 접지 순간과 어긋날 수 있어 캐릭터별 검증이 필요하다.

### Q028

- **질문:** RoomGrid 생성 결과를 같은 seed로 재현할 수 있는 이유는 무엇인가요?
- **질문 의도:** 결정적 난수 사용을 이해하는지 본다.
- **좋은 답변:** 전역 난수가 아니라 고정 seed의 `FRandomStream`을 생성 과정 전체에 사용하기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `AJMGridMapGenerator::GenerateInternal`과 custom generator가 `FRandomStream Stream(EffectiveSeed)`을 만들고 `RegenerateSameSeed`가 저장된 `RandomSeed`를 재사용한다.
- **추가 꼬리 질문:** 결정성이 깨지는 흔한 원인은 무엇인가요?
- **부족한 부분:** Actor iteration 순서나 외부 전역 난수가 추가되면 seed만 같아도 결과가 달라질 수 있어 결정성 테스트를 유지해야 한다.

### Q029

- **질문:** PhysicalGrabber와 Throwable 시스템의 차이를 설명해 보세요.
- **질문 의도:** 비슷해 보이는 물리 기능의 도메인 경계를 구분하는지 본다.
- **좋은 답변:** Grabber는 지속적인 constraint/끌기와 harpoon 반응, Throwable은 ready·aim·commit 후 projectile 이동을 책임진다고 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHarpoonGunComponent`는 발사·박힘·회수·wire·grapple을, `UJMThrowableInteractorComponent`는 투척 세션과 preview를, movement component는 발사체 이동을 맡는다.
- **추가 꼬리 질문:** 두 시스템이 공통으로 가질 수 있는 계약은 무엇인가요?
- **부족한 부분:** `UJMHarpoonGunComponent`는 orchestration과 물리 책임이 매우 커 SRP 개선 여지가 있다.

### Q030

- **질문:** 이 프로젝트에서 자동화 테스트는 어떤 식으로 작성했나요?
- **질문 의도:** Unreal Automation Framework의 기본 사용 경험을 확인한다.
- **좋은 답변:** 작은 규칙은 UObject test, World 동작은 Functional, 입력·camera는 latent PIE로 층화했다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMGameplayEventAutomationTests.cpp`는 `IMPLEMENT_SIMPLE_AUTOMATION_TEST`와 `NewObject`를 쓰고, Door는 `AJMDoorFunctionalTest`, Recon은 `FStartPIECommand` 기반 테스트를 가진다.
- **추가 꼬리 질문:** PIE latent test에 timeout이 왜 필요한가요?
- **부족한 부분:** 전체 CI 실행 주기와 packaged build 수준의 Gauntlet 검증은 저장소에서 확인되지 않는다.

---

## 중급 질문 50개

### Q031

- **질문:** Integration Plugin이 base Plugin 사이의 의존 방향을 어떻게 보호하나요?
- **질문 의도:** 의존성 역전과 adapter layer를 실제 구조로 설명하는지 본다.
- **좋은 답변:** 양쪽 concrete 타입을 아는 코드를 별도 Integration에 두고 base Plugin은 Integration을 역참조하지 않게 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMDoorGameplayIntegration`만 `JMDoorRuntime`·`JMInteraction`·`InventorySystem`에 의존하며 Door와 Interaction core는 이 Plugin을 모른다.
- **추가 꼬리 질문:** Integration 없이 Door가 Interface를 직접 구현하면 무엇을 잃나요?
- **부족한 부분:** Integration 수가 늘면 조합별 Plugin 폭증과 자동 부착 정책 관리 비용이 생긴다.

### Q032

- **질문:** `UJMGameplayEventSubsystem::PublishEvent`의 실행 순서를 설명해 보세요.
- **질문 의도:** 중앙 event dispatch의 검증과 실행 경로를 이해하는지 본다.
- **좋은 답변:** game thread·tag·중첩 깊이 확인, invalid 구독 정리, 대상 snapshot, callback 실행, 후처리 순으로 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `PublishEvent`는 `IsInGameThread`와 `MaximumNestedDispatchDepth`를 검사하고 bucket tag와 GUID snapshot을 만든 뒤 listener 유효성을 재확인해 local delegate copy를 실행한다.
- **추가 꼬리 질문:** 왜 dispatch 전후로 invalid subscription을 정리하나요?
- **부족한 부분:** 동기 호출이므로 느린 listener 하나가 발행자 frame을 직접 지연시킨다.

### Q033

- **질문:** Exact와 IncludeChildren event 구독은 어떻게 동작하나요?
- **질문 의도:** GameplayTag 계층 matching을 코드 수준에서 설명하는지 본다.
- **좋은 답변:** Exact는 tag 동등성, IncludeChildren은 발행 tag가 구독 부모 tag와 계층 match하는지 확인한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `PublishEvent`는 `Pair.Key == Message.EventTag`와 `Message.EventTag.MatchesTag(Pair.Key)`를 계산하고 후자는 subscription match type이 IncludeChildren일 때만 snapshot에 넣는다.
- **추가 꼬리 질문:** 부모 event를 발행했을 때 자식 구독자가 받나요?
- **부족한 부분:** 양방향 wildcard가 아니므로 팀이 match 방향을 잘못 이해하면 event 누락이 생길 수 있다.

### Q034

- **질문:** Event bus가 listener를 weak pointer로 저장하는 이유는 무엇인가요?
- **질문 의도:** 구독이 UObject 수명을 잘못 연장하는 문제를 아는지 본다.
- **좋은 답변:** 구독 때문에 파괴돼야 할 listener가 GC에서 살아남지 않게 하고 파괴된 대상은 자동으로 건너뛰기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FSubscription::Listener`는 weak reference이며 `RemoveInvalidSubscriptions`가 invalid listener나 unbound callback을 제거한다.
- **추가 꼬리 질문:** 명시적 unsubscribe가 그래도 필요한 이유는 무엇인가요?
- **부족한 부분:** invalid cleanup만 믿으면 죽은 entry가 다음 publish까지 남고 논리적 구독 종료 시점도 불명확하다.

### Q035

- **질문:** Callback 중 unsubscribe가 발생해도 안전한 이유는 무엇인가요?
- **질문 의도:** container mutation과 재진입 문제를 이해하는지 본다.
- **좋은 답변:** 실제 배열을 순회하지 않고 stable ID snapshot을 순회하며 실행 전 재조회하고 delegate를 복사해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `PublishEvent`는 `BucketTag + Id`만 snapshot하고 `FindSubscription`으로 재조회한 뒤 `FJMGameplayEventNativeDelegate Callback = Subscription->Callback`을 실행한다.
- **추가 꼬리 질문:** Callback이 다른 listener를 제거하면 어떻게 되나요?
- **부족한 부분:** 같은 dispatch에서 제거된 listener는 재조회 실패로 호출되지 않으므로 이 semantics를 계약으로 명시해야 한다.

### Q036

- **질문:** Nested event dispatch를 왜 제한하나요?
- **질문 의도:** 동기 event chain의 재귀와 stack 위험을 설명하는지 본다.
- **좋은 답변:** listener가 다시 publish하는 순환으로 stack overflow와 무한 gameplay loop가 생기는 것을 막기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMDispatchScope`가 `DispatchDepth`를 RAII로 증감하고 settings의 `MaximumNestedDispatchDepth` 이상이면 발행을 차단한다.
- **추가 꼬리 질문:** 차단된 event를 queue로 돌리는 대안은 어떤 장단점이 있나요?
- **부족한 부분:** 깊이 차단 후 gameplay 상태를 어떻게 복구할지 도메인별 정책은 없다.

### Q037

- **질문:** Blueprint가 Gameplay Event를 받게 하는 adapter는 무엇인가요?
- **질문 의도:** native core와 Blueprint 사용성의 경계를 이해하는지 본다.
- **좋은 답변:** Component가 native callback을 구독하고 dynamic multicast로 Blueprint에 중계하도록 만든다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMGameplayEventListenerComponent`가 BeginPlay에 `BindUObject`로 구독하고 `OnGameplayEventReceived.Broadcast`로 변환하며 EndPlay에 handles를 해제한다.
- **추가 꼬리 질문:** Publisher Component는 어떤 역할을 하나요?
- **부족한 부분:** Blueprint adapter를 많이 배치하면 동일 tag 중복 구독과 추적 난도가 증가할 수 있다.

### Q038

- **질문:** Objective는 Gameplay Event를 어떻게 구독하나요?
- **질문 의도:** 데이터 정의와 runtime subscription 연결을 읽었는지 본다.
- **좋은 답변:** 활성 objective의 정의가 가진 event tag와 match type으로 구독하고 objective ID를 callback context로 묶는다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMObjectiveSubsystem::SubscribeObjective`가 `Definition->ListeningEventTag`를 구독하고 `CreateUObject(this, &HandleGameplayEvent, ObjectiveId)`로 ID를 추가 인자로 저장한다.
- **추가 꼬리 질문:** Objective 완료 시 구독을 왜 해제하나요?
- **부족한 부분:** 활성 objective 수가 매우 많을 때 tag별 구독 수와 callback filtering 비용을 측정한 자료는 없다.

### Q039

- **질문:** Objective event filter는 어떤 값을 확인하나요?
- **질문 의도:** tag와 payload를 결합한 데이터 기반 조건을 설명하는지 본다.
- **좋은 답변:** event tag, required/blocked context tags, target identifier, progress amount를 검사한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `DoesEventPassFilters`가 Message와 `UJMGameplayEventPayloadBase`의 context를 합치고 `RequiredTargetIdentifier`를 비교하며 `PayloadAmount` 모드면 `ObjectiveProgressAmount`를 사용한다.
- **추가 꼬리 질문:** Concrete Inventory payload를 cast하지 않아도 되는 이유는 무엇인가요?
- **부족한 부분:** Payload가 base contract를 따르지 않으면 진행량이 0이 되며 schema mismatch가 compile time에 잡히지 않는다.

### Q040

- **질문:** `UJMObjectiveFlowSubsystem`은 ObjectiveSubsystem과 역할이 어떻게 다른가요?
- **질문 의도:** 개별 목표 상태와 순서 orchestration을 구분하는지 본다.
- **좋은 답변:** ObjectiveSubsystem은 단일 목표 lifecycle, FlowSubsystem은 step 순서와 다음 목표 활성화를 맡는다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Flow test는 첫 objective만 active로 시작하고 완료 event에 따라 다음 step을 활성화하며 개별 progress는 `UJMObjectiveSubsystem`이 처리한다.
- **추가 꼬리 질문:** 분기형 quest를 추가하려면 무엇이 바뀌어야 하나요?
- **부족한 부분:** 현재 Flow는 선형 모델 중심이라 조건 분기·병렬 step·rollback을 일반화하지 않았다.

### Q041

- **질문:** Local delegate와 global Gameplay Event를 함께 쓰는 이유는 무엇인가요?
- **질문 의도:** 같은 Actor 내부 통지와 Plugin 간 통지를 구분하는지 본다.
- **좋은 답변:** 직접 소유 관계의 빠르고 typed한 알림은 delegate, 발행자가 수신자를 모르는 전역 통합은 event bus에 둔다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory는 `OnInventoryChanged`로 UI를 갱신하면서 `PublishInventoryEvent`로 Objective 등 간접 소비자에게 획득 event를 보낸다.
- **추가 꼬리 질문:** 두 채널의 발행 순서가 왜 중요하나요?
- **부족한 부분:** 일부 작업에서 local/global event 순서와 exactly-once 보장이 명시적 transaction contract로 고정되지 않았다.

### Q042

- **질문:** Interaction input interceptor는 어떤 문제를 해결하나요?
- **질문 의도:** 기존 입력 파이프라인을 수정하지 않는 확장 지점을 이해하는지 본다.
- **좋은 답변:** owner component가 기본 interaction 입력을 먼저 소비해 modal이나 특수 상태 동작을 우선 처리하게 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `TryBeginInteraction`은 owner components의 `UJMInteractionInputInterceptorInterface`를 순회하며 `UJMHideInputRouterComponent`가 hide 상태의 enter/exit 입력을 선점한다.
- **추가 꼬리 질문:** interceptor가 여러 개면 우선순위는 어떻게 정하나요?
- **부족한 부분:** 현재 component iteration 순서에 기대면 명시적 priority가 없어 충돌 semantics가 불투명하다.

### Q043

- **질문:** Interaction focus가 바뀔 때 어떤 처리가 일어나나요?
- **질문 의도:** 대상 전환에서 이전·새 대상의 대칭 callback을 확인하는지 본다.
- **좋은 답변:** 이전 대상에 focus end, 새 대상에 focus begin을 보내고 prompt와 event를 갱신한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMInteractionComponent::SetCurrentInteractable`이 `Execute_OnFocusEnd/Begin`을 호출하고 focused/unfocused tag event와 `OnCurrentInteractableChanged`를 발행한다.
- **추가 꼬리 질문:** 같은 대상을 다시 감지하면 왜 전체 갱신을 생략하나요?
- **부족한 부분:** 대상 내부 prompt 데이터가 바뀌어도 object identity가 같으면 강제 refresh 조건을 별도로 관리해야 한다.

### Q044

- **질문:** Hold interaction의 begin과 complete를 왜 분리했나요?
- **질문 의도:** 장시간 작업의 취소 가능 상태를 설계할 수 있는지 본다.
- **좋은 답변:** 대상이 시작을 승인한 뒤 duration 동안 상태를 유지하고 완료 또는 취소를 명확히 호출하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `TryBeginInteraction`은 Begin 성공 후 duration이 0이면 즉시 complete, 아니면 `Holding`으로 전환하며 `CancelInteraction`은 `Execute_CancelInteract`를 호출한다.
- **추가 꼬리 질문:** Hold 중 target이 파괴되면 어떻게 되나요?
- **부족한 부분:** network authoritative hold와 progress replication은 구현돼 있지 않다.

### Q045

- **질문:** Modal prompt suppression에 depth가 필요한 이유는 무엇인가요?
- **질문 의도:** 중첩 자원 획득 문제를 이해하는지 본다.
- **좋은 답변:** 두 modal이 열린 상태에서 하나만 닫혔다고 prompt를 복구하면 안 되므로 reference count가 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMInteractionComponent`는 `ModalSuppressionDepth`를 증가·감소시키고 0이 됐을 때만 이전 `bPromptSuppressed`를 복원한다.
- **추가 꼬리 질문:** Close event가 누락되면 어떤 문제가 생기나요?
- **부족한 부분:** owner token 없이 정수 depth만 쓰면 중복 close나 누락을 어느 modal이 만들었는지 추적하기 어렵다.

### Q046

- **질문:** Interaction의 Tick, Timer, OnInput trace 모드를 비교해 보세요.
- **질문 의도:** 반응성과 비용의 trade-off를 설명하는지 본다.
- **좋은 답변:** Tick은 즉각적이지만 비싸고, Timer는 간격만큼 지연되며, OnInput은 저렴하지만 사전 focus UI 갱신이 제한된다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `StartAutoRefresh`가 Tick mode에서는 component tick, Timer mode에서는 `TraceTimerHandle`, OnInput에서는 `TryBeginInteraction` 시 refresh를 사용한다.
- **추가 꼬리 질문:** VR이나 gamepad에서는 어떤 모드가 적합할까요?
- **부족한 부분:** detection strategy와 cadence가 한 Component 설정에 함께 있어 새 탐지 방식 추가 시 클래스가 더 커진다.

### Q047

- **질문:** Inventory 추가에서 기존 stack을 먼저 채우는 이유는 무엇인가요?
- **질문 의도:** 슬롯 효율과 불변식 관리 방식을 이해하는지 본다.
- **좋은 답변:** 빈 슬롯 소비를 최소화하고 같은 아이템 stack limit까지 공간을 활용하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `AddItemDetailed`은 stackable Definition의 기존 slots를 순회해 여유량을 채운 뒤 빈 slot에 새 `InstanceId`를 만든다.
- **추가 꼬리 질문:** 서로 다른 Definition 객체지만 같은 ItemId면 합쳐야 하나요?
- **부족한 부분:** 연산에 따라 pointer 또는 ItemId identity가 쓰여 동일성 규칙을 더 통일해야 한다.

### Q048

- **질문:** `MoveItem`은 어떻게 원자적 이동을 시도하나요?
- **질문 의도:** 두 container 상태 변경과 보상 로직을 설명하는지 본다.
- **좋은 답변:** 전체 수용 가능성을 먼저 검증하고 destination 적용이 완료된 뒤 source를 차감하며 부분 적용은 rollback한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 자동 배치에서 `CanAccept` 후 `AddItemDetailed`을 호출하고 일부만 추가되면 그 수량을 `RemoveItem`으로 보상한 뒤 source를 유지한다.
- **추가 꼬리 질문:** 왜 이것이 데이터베이스 수준의 완전한 transaction은 아닌가요?
- **부족한 부분:** rollback이 slot delta가 아니라 Definition·수량 제거라 원래 추가 위치까지 정확히 복원하지 않는다.

### Q049

- **질문:** SplitStack과 SwapItem의 사전 조건은 무엇인가요?
- **질문 의도:** Inventory operation별 불변식을 구분하는지 본다.
- **좋은 답변:** split은 원본보다 작은 양수 수량, swap은 양쪽 유효 slot과 교환 후 무게 제한을 만족해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `SplitStack`은 `Quantity >= source.Quantity`를 거부하고 `MoveItem`에 위임하며, `SwapItem`은 교환 후 두 inventory weight를 먼저 계산한다.
- **추가 꼬리 질문:** 같은 Inventory 안에서 swap할 때 event는 어떻게 발생하나요?
- **부족한 부분:** operation별 세부 delta event보다 `OnInventoryChanged`만 발행되는 경로가 있어 UI 외 소비자가 변경 이유를 알기 어렵다.

### Q050

- **질문:** 슬롯 용량을 줄일 때 아이템 손실을 어떻게 막나요?
- **질문 의도:** runtime 설정 변경의 보존 규칙을 이해하는지 본다.
- **좋은 답변:** occupied slot 수보다 작으면 거부하고, 가능하면 occupied slots를 앞쪽으로 compact한 뒤 resize한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `SetMaxInventorySlots`는 occupied count를 검사하고 occupied-first stable sort 후 requested capacity로 줄이며 결과 enum을 반환한다.
- **추가 꼬리 질문:** stable sort를 쓰는 이유는 무엇인가요?
- **부족한 부분:** slot index를 외부가 장기 참조했다면 compact 후 identity tracking이 필요하다.

### Q051

- **질문:** Inventory 무게 제한은 이동 전에 어떻게 검사하나요?
- **질문 의도:** 사후 rollback보다 사전 계산을 사용할 수 있는지 본다.
- **좋은 답변:** 현재 무게와 요청 item weight로 수용량 또는 교환 후 양쪽 무게를 계산해 mutation 전에 거부한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `GetAcceptableQuantity`와 `CanAccept`가 추가 수량을 제한하고 `SwapItem`은 `ThisWeightAfter`와 `OtherWeightAfter`를 계산한다.
- **추가 꼬리 질문:** Weight가 음수인 잘못된 Definition은 어떻게 막나요?
- **부족한 부분:** metadata clamp는 Editor 입력을 돕지만 런타임 생성·손상 Asset까지 보장하는 validation이 별도로 필요하다.

### Q052

- **질문:** 아이템 사용 효과를 instanced object로 둔 이유는 무엇인가요?
- **질문 의도:** 데이터 기반 전략 객체와 UObject 소유를 설명하는지 본다.
- **좋은 답변:** Definition마다 다른 사용 행동을 subclass로 제공하되 Actor 상속이나 switch를 늘리지 않기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryItemDefinition::UseEffect`는 `Instanced TObjectPtr<UInventoryItemUseEffect>`이고 Use 시 효과 객체에 실행을 위임한다.
- **추가 꼬리 질문:** 상태를 가진 UseEffect를 여러 slot이 공유하면 어떤 문제가 있나요?
- **부족한 부분:** Definition subobject는 공유 Asset 상태이므로 per-instance mutable state를 두지 않는 계약을 더 명시해야 한다.

### Q053

- **질문:** Pickup이 특정 Character 클래스를 몰라도 Inventory를 찾는 방법은 무엇인가요?
- **질문 의도:** provider interface로 concrete Pawn 결합을 줄이는지 본다.
- **좋은 답변:** 대상 Actor나 관련 객체가 Inventory provider contract를 구현하게 하고 그 contract로 Component를 얻는다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory 영역의 `IInventoryProviderInterface`가 소유자 탐색을 역전하고 `AInventoryWorldItemPickup`은 `IJMInteractableInterface`로 interaction에도 참여한다.
- **추가 꼬리 질문:** provider가 여러 Inventory를 제공하면 어떻게 선택하나요?
- **부족한 부분:** 다중 container 우선순위와 authoritative owner 정책은 더 명시적이어야 한다.

### Q054

- **질문:** ItemInspector를 LocalPlayerSubsystem으로 만든 이유는 무엇인가요?
- **질문 의도:** 3D preview와 UI의 플레이어별 수명을 설명하는지 본다.
- **좋은 답변:** 각 local player가 독립 Widget, preview actor, camera/input 상태를 가져야 하기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMItemInspectionSubsystem`이 LocalPlayer 범위에서 조사 session, preview actor, UMG transition과 입력 복원을 관리한다.
- **추가 꼬리 질문:** Preview Actor를 실제 World에 spawn할 때 주의할 점은 무엇인가요?
- **부족한 부분:** Subsystem 책임이 UI·preview·입력까지 넓고 Inventory Runtime의 Public API가 Inspector에 직접 결합돼 있다.

### Q055

- **질문:** Inventory와 ItemInspector 연결에 Bridge를 둔 이유는 무엇인가요?
- **질문 의도:** 선택적 기능 연결을 추상화하려는 시도를 평가한다.
- **좋은 답변:** Inventory UI는 조사 구현 세부 대신 open/close 가능한 bridge 계약만 호출해 전환을 위임해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryUIComponent`는 instanced `InspectorBridge`로 `IsInspectorOpen`, open, close, return transition을 처리한다.
- **추가 꼬리 질문:** 그런데 왜 Inventory Plugin 의존성은 여전히 선택적이지 않나요?
- **부족한 부분:** Bridge 타입이 Inventory Runtime Public API에 있고 `ItemInspectorRuntime`이 Public dependency라 Plugin 단독 closure가 분리되지 않았다.

### Q056

- **질문:** Enhanced Input binding 수명을 어떻게 관리했나요?
- **질문 의도:** InputAction soft load와 binding handle 관리 경험을 확인한다.
- **좋은 답변:** 사용할 component와 action을 검증하고 중복 binding을 피하며 owner 종료나 교체 시 해제한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryUIComponent::BindEnhancedInput`은 `ToggleInventoryAction.LoadSynchronous` 후 `UEnhancedInputComponent`에 bind하고 bound component를 weak reference로 기억한다.
- **추가 꼬리 질문:** MappingContext를 누가 LocalPlayerSubsystem에 추가하나요?
- **부족한 부분:** 여러 Plugin이 input mapping과 modal 정책을 개별 소유해 중앙 input layer 조정이 약하다.

### Q057

- **질문:** 이미 대화가 진행 중일 때 새 대화 요청은 어떻게 처리하나요?
- **질문 의도:** 재진입 API 정책을 명확히 정의하는지 본다.
- **좋은 답변:** Reject 또는 Replace처럼 호출자가 선택할 수 있는 정책을 두고 기존 session cleanup 후 새 session을 시작한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UDialogueSubsystem::StartDialogue`는 `EExistingDialoguePolicy::Reject`면 false를 반환하고 Replace면 기존 대화를 끝낸 뒤 새 sequence를 설정한다.
- **추가 꼬리 질문:** Replace된 대화를 cancelled와 finished 중 무엇으로 알리나요?
- **부족한 부분:** map travel과 subsystem deinitialize에서 대화 종료 reason을 소비자가 어떻게 해석할지 더 문서화해야 한다.

### Q058

- **질문:** Dialogue tokenizer가 UTF-16 surrogate pair를 보존하는 방법을 설명하세요.
- **질문 의도:** Unreal `FString` 인덱싱과 Unicode 기초를 확인한다.
- **좋은 답변:** high surrogate 뒤에 low surrogate가 오면 두 TCHAR code unit을 하나의 표시 token으로 묶는다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FDialogueTokenizer::TokenizeCharacters`가 0xD800~DBFF와 0xDC00~DFFF 범위를 검사해 `Source.Mid(Index, 2)`로 만든다.
- **추가 꼬리 질문:** 피부색 modifier나 ZWJ emoji도 하나로 묶이나요?
- **부족한 부분:** grapheme segmentation이 아니므로 복합 emoji와 결합 문자는 여러 token이 될 수 있다.

### Q059

- **질문:** Dialogue 종료 시 어떤 자원을 정리하나요?
- **질문 의도:** timer·audio·Widget·입력의 대칭 cleanup을 설명하는지 본다.
- **좋은 답변:** 모든 pending timer를 중지하고 audio component, Widget, focus/input ownership, runtime token을 한 경로에서 반환한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `CleanupPlayback`이 `RevealTimerHandle`을 clear하고 text/voice audio를 stop하며 `RestoreInteractionMode` 후 Widget을 제거하고 token/visible text를 reset한다.
- **추가 꼬리 질문:** Widget이 중간에 제거되면 reveal callback은 어떻게 반응하나요?
- **부족한 부분:** Modal 복원은 항상 `FInputModeGameOnly`를 적용해 기존 input mode를 정확히 되돌리지 않는다.

### Q060

- **질문:** Door 접근 권한은 어떻게 확장 가능하게 설계했나요?
- **질문 의도:** key/tag 소비를 Door concrete 코드에서 분리한 방식을 본다.
- **좋은 답변:** UseContext와 access provider interface로 보유 tag와 소비 정책을 외부에 위임한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorComponent::ResolveAccess`는 `FJMDoorUseContext`와 `IJMDoorAccessProviderInterface`를 통해 required tags를 검사하며 Inventory 연결은 Integration agent가 담당한다.
- **추가 꼬리 질문:** `AnyRequired`와 `AllRequired` 정책은 어디에서 평가하나요?
- **부족한 부분:** 접근 검증이 client에서도 가능하다면 multiplayer에서는 server authority와 item 소비 원자성을 추가해야 한다.

### Q061

- **질문:** Door가 장애물을 만났을 때 어떤 정책을 지원하나요?
- **질문 의도:** 충돌 감지와 상태 전환을 분리해 설명하는지 본다.
- **좋은 답변:** proposed transform으로 obstruction을 검사하고 Stop·Reverse·Retry 같은 설정 정책에 따라 상태와 target을 바꾼다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorComponent`는 `EJMDoorBlockBehavior`에 따라 Blocked 유지, 반대 target으로 `BeginMovement`, timer 기반 retry를 수행한다.
- **추가 꼬리 질문:** 움직이는 문이 Character를 밀 때 tunneling을 어떻게 줄이나요?
- **부족한 부분:** overlap query와 substep push는 Actor 수가 많을 때 성능 profile이 필요하다.

### Q062

- **질문:** Door movement를 local-space transform으로 계산한 이유는 무엇인가요?
- **질문 의도:** Actor 회전과 부모 transform에 독립적인 이동을 이해하는지 본다.
- **좋은 답변:** 배치된 Door Actor가 회전·이동해도 문짝의 authored closed transform 기준으로 같은 움직임을 유지하기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorMovementComponent`가 `ClosedRelativeTransform`을 저장하고 rotating strategy가 local axis quaternion을 곱하며 테스트는 90도 회전 Actor에서도 offset을 검증한다.
- **추가 꼬리 질문:** world-space offset을 사용하면 어떤 배치에서 깨지나요?
- **부족한 부분:** non-uniform scale과 복잡한 attachment 계층에 대한 계약을 더 명시할 수 있다.

### Q063

- **질문:** Door damage와 lock damage를 왜 구분했나요?
- **질문 의도:** 도메인 상태와 결과 code를 읽었는지 본다.
- **좋은 답변:** 문 파괴와 잠금장치 파손이 gameplay 의미와 후속 상태가 다르므로 durability를 분리한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorComponent`는 `DoorDurability`, `LockDurability`, `bLockBroken`을 따로 저장하고 `OnDurabilityChanged`를 발행한다.
- **추가 꼬리 질문:** Lock이 파괴되면 locked flag는 어떻게 전이돼야 하나요?
- **부족한 부분:** 접근·내구도·이동·audio·save가 같은 Component에 있어 변경 영향 범위가 크다.

### Q064

- **질문:** Door restore 전에 timer와 tick을 멈추는 이유는 무엇인가요?
- **질문 의도:** 저장 복원이 진행 중 runtime 작업과 경쟁하는 문제를 아는지 본다.
- **좋은 답변:** 이전 movement/auto-close callback이 복원한 상태를 곧바로 덮어쓰는 것을 막기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `RestoreSaveData`는 retry, auto-close, panel별 timer를 clear하고 component tick을 끈 뒤 fraction과 state를 적용한다.
- **추가 꼬리 질문:** 이동 중 상태를 save하면 restore 후 이동을 재개해야 하나요?
- **부족한 부분:** 현재 save 정책은 진행 중 command를 재생하기보다 즉시 상태를 적용하므로 기획 의도를 명시해야 한다.

### Q065

- **질문:** Door Interaction adapter가 context와 result를 어떻게 변환하나요?
- **질문 의도:** Integration code가 단순 전달 이상으로 계약을 번역하는지 본다.
- **좋은 답변:** Interaction의 instigator·target 정보를 Door use context로 바꾸고 Door result code/message를 Interaction result로 되돌린다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorInteractableAdapterComponent::CompleteInteract_Implementation`이 `MakeDoorContext` 후 `ToggleDoor`를 호출하고 성공/잠김 결과를 분기한다.
- **추가 꼬리 질문:** 잠김 결과에서 Inventory Agent는 어디에 붙나요?
- **부족한 부분:** 호출 중 participant Actor에 agent를 동적 생성하는 동작이 암묵적이고 network replication 정책이 없다.

### Q066

- **질문:** JumpScareSubsystem을 WorldSubsystem으로 둔 이유는 무엇인가요?
- **질문 의도:** 연출 상태가 현재 World에 속한다는 판단을 평가한다.
- **좋은 답변:** World Actor, camera, post-process, timer와 함께 사라져야 하며 다른 map에 재생 상태를 넘기지 않기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMJumpScareSubsystem`이 World 단위로 2D 연출·Widget·camera/input 상태와 단계 timer를 소유하고 종료 시 복원한다.
- **추가 꼬리 질문:** level travel 도중 jump scare가 active면 어떤 cleanup이 필요하나요?
- **부족한 부분:** Definition의 기본 PostProcessMaterial이 Host `/Game/Jumpscare/M_Glitch`를 가리켜 Plugin 이식성을 해친다.

### Q067

- **질문:** Gameplay Event로 점프스케어를 한 번만 실행하는 방법은 무엇인가요?
- **질문 의도:** event subscription과 one-shot 정책을 설명하는지 본다.
- **좋은 답변:** BeginPlay에 trigger tag를 구독하고 once policy면 실행 후 flag를 기록하며 EndPlay에 unsubscribe한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMJumpScareEventTriggerComponent`가 `SubscriptionHandle`과 `bHasTriggered`를 저장하고 `HandleGameplayEvent`에서 `EJMJumpScareTriggerPolicy::Once`를 검사한다.
- **추가 꼬리 질문:** 저장 후 재접속에도 once를 유지하려면 무엇이 필요한가요?
- **부족한 부분:** `bHasTriggered`는 component runtime 상태라 영구 one-shot save contract가 아니다.

### Q068

- **질문:** Recon target reservation에서 SessionId를 사용하는 이유는 무엇인가요?
- **질문 의도:** bool lock보다 owner token이 강한 이유를 설명하는지 본다.
- **좋은 답변:** 현재 소유 세션을 식별해 다른 세션이 잘못 해제하지 못하게 하고 연속 세션도 구분한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMReconTargetComponent::TryReserve`는 다른 valid `ReservedSessionId`가 있으면 AlreadyInUse를 반환하고 `ReleaseReservation`은 같은 GUID만 invalidate한다.
- **추가 꼬리 질문:** 같은 SessionId로 재예약하면 어떻게 되나요?
- **부족한 부분:** 로컬 GUID 예약이며 server authoritative replicated lock은 아니다.

### Q069

- **질문:** Recon의 Listen, Peek, Illuminate 모드는 어떻게 제한되나요?
- **질문 의도:** bitmask capability와 상태 요청의 관계를 이해하는지 본다.
- **좋은 답변:** target definition/capability에서 지원 mode를 확인하고 session state에 맞는 전이만 허용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMReconTargetComponent::SupportsMode`가 `AllowedReconModes` bitmask를 검사하고 interactor가 mode 시작 전 target/interface 결과를 확인한다.
- **추가 꼬리 질문:** 값 22에 대한 legacy 처리의 의미는 무엇인가요?
- **부족한 부분:** legacy bitmask special case가 남아 데이터 migration 완료 여부를 추적해야 한다.

### Q070

- **질문:** Recon session 종료 시 어떤 순서로 정리하나요?
- **질문 의도:** 복수 외부 자원의 cleanup 순서를 설명하는지 본다.
- **좋은 답변:** timer와 active 효과를 중지하고 대상 callback·delegate를 종료한 뒤 reservation과 camera ownership을 반환하고 session을 reset한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** interactor 종료 경로는 transition timer, SoundMix, peek, target destroyed binding, `EndRecon` interface, `ReleaseReservation`, `OnCameraRestoreRequested`를 처리한다.
- **추가 꼬리 질문:** Target이 먼저 파괴되면 reservation release는 가능한가요?
- **부족한 부분:** cleanup 책임이 긴 함수에 집중돼 새 mode 자원 추가 시 누락 위험이 있다.

### Q071

- **질문:** Recon Gameplay Integration이 담당하는 책임을 설명하세요.
- **질문 의도:** core Recon과 player presentation bridge의 경계를 이해하는지 본다.
- **좋은 답변:** Interaction focus와 입력을 Recon session 요청으로 바꾸고 camera·light·player lock·prompt를 Host 플레이어에 적용한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMReconGameplayIntegrationWorldSubsystem`이 대상 Pawn에 bridge를 자동 부착하고 player bridge가 입력·camera transition·조명·이동 제한을 총괄한다.
- **추가 꼬리 질문:** 왜 core Recon에 camera 구현을 직접 넣지 않았나요?
- **부족한 부분:** player bridge가 약 990행으로 presentation 정책이 과도하게 집중돼 있다.

### Q072

- **질문:** DoorReconIntegration은 Recon 중 Door를 어떻게 다루나요?
- **질문 의도:** 임시 pose 적용과 원상 복구 contract를 설명하는지 본다.
- **좋은 답변:** Recon target adapter가 Door 상태를 관찰하고 session 동안 peek fraction을 임시 적용한 뒤 종료 시 원래 pose를 복구한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorReconTargetAdapterComponent`가 `IJMReconTarget`을 구현하고 Door delegate와 sliding movement를 사용해 panel pose를 관리한다.
- **추가 꼬리 질문:** Recon 중 Door가 실제 gameplay command로 움직이면 어떻게 해야 하나요?
- **부족한 부분:** Sliding movement concrete cast와 tick 기반 pose가 Door abstraction을 새고 충돌 정책이 복잡하다.

### Q073

- **질문:** HideSpot의 Reserved와 Occupied 상태를 왜 분리했나요?
- **질문 의도:** 준비 단계와 commit 단계가 다른 transaction을 이해하는지 본다.
- **좋은 답변:** 진입 animation 중에는 다른 사용자를 막되 모든 단계 성공 전에는 실제 점유로 확정하지 않기 위해서다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHideSpotComponent::TryReserve`가 session owner를 잡고 `CommitOccupied`가 성공 후 occupant를 설정하며 `Release`는 같은 session만 해제한다.
- **추가 꼬리 질문:** 예약 중 interactor가 파괴되면 누가 release하나요?
- **부족한 부분:** provider 파괴와 모든 비정상 종료가 cleanup으로 연결되는지 지속적인 회귀 테스트가 필요하다.

### Q074

- **질문:** Hide 진입을 transaction이라고 부를 수 있는 이유는 무엇인가요?
- **질문 의도:** 다단계 작업의 validate·commit·compensation 구조를 설명하는지 본다.
- **좋은 답변:** reserve, snapshot capture, prepare, mechanism/participant stage, occupied commit이 순서대로 진행되고 중간 실패 시 보상한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHideInteractorComponent::BeginEnter`가 spot 예약 후 `CaptureState`·`PrepareForHide`를 실행하고 마지막에 `CommitOccupied`한다.
- **추가 꼬리 질문:** Participant snapshot에는 어떤 상태가 들어가야 하나요?
- **부족한 부분:** stage orchestration이 명시적 command 목록이 아니라 큰 Component 분기로 구현돼 확장 비용이 있다.

### Q075

- **질문:** Hide enter 실패와 exit 실패의 rollback 대상이 다른 이유는 무엇인가요?
- **질문 의도:** 가장 안전한 안정 상태를 선택하는 능력을 본다.
- **좋은 답변:** enter 실패는 원래 외부 상태로, exit 실패는 충돌 없는 hidden 상태로 돌아가야 하기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `RollbackEnter`는 participant snapshot과 mechanism을 원상 복구하고 release하며, `RollbackExitToHidden`은 occupied/hidden 상태를 다시 확립한다.
- **추가 꼬리 질문:** Hidden 상태에서 cancel을 거부한 이유는 무엇인가요?
- **부족한 부분:** force exit가 collision을 무시하는 조건은 gameplay 안전 정책으로 더 명확히 문서화해야 한다.

### Q076

- **질문:** HideInteractionIntegration과 HideDoorIntegration의 역할 차이는 무엇인가요?
- **질문 의도:** 하나의 도메인에 대한 두 adapter 방향을 구분하는지 본다.
- **좋은 답변:** 전자는 플레이어 Interaction/Input을 Hide 명령으로, 후자는 Door를 Hide mechanism operation으로 변환한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHideInteractableAdapterComponent`와 `UJMHideInputRouterComponent`가 진입/이탈을 연결하고, `UJMHideDoorMechanismComponent`가 mechanism stage를 Door open/close로 번역한다.
- **추가 꼬리 질문:** 두 Integration이 동시에 필요한 hide actor의 구성 순서는 무엇인가요?
- **부족한 부분:** 호출 시 Driver/Interactor/Router를 동적 설치하는 경로가 있어 authored 구성과 자동 구성의 우선순위가 불투명하다.

### Q077

- **질문:** Footstep을 distance-based로 구현할 때 장단점은 무엇인가요?
- **질문 의도:** animation notify 대안의 trade-off를 설명하는지 본다.
- **좋은 답변:** animation asset 수정 없이 이동 거리에 비례하지만 발 접지 timing과 network correction에 민감하다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMFootstepComponent`가 이동 거리를 누적하고 threshold마다 ground trace와 physical surface로 variant sound를 선택한다.
- **추가 꼬리 질문:** 공중·teleport 이동은 어떻게 제외해야 하나요?
- **부족한 부분:** 이동 mode와 animation phase를 함께 검증하지 않으면 미끄러짐·teleport에서 잘못된 발소리가 날 수 있다.

### Q078

- **질문:** RoomGrid는 생성 결과를 어떻게 검증하나요?
- **질문 의도:** procedural generation에 post-condition validation을 두는 습관을 본다.
- **좋은 답변:** 예상 방 수, 좌표 중복, 각 방 contract, 인접 port 방향 일치를 생성 후 검사한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `AJMGridMapGenerator::ValidateGeneratedMap`과 custom variant가 coordinate map으로 방 contract와 이웃 연결을 검사하고, Host `AJMPrototypeGeneratedDungeonDirector`가 생성 결과에 Loot·Monster를 배치한다.
- **추가 꼬리 질문:** 검증 실패 시 생성 Actor는 자동 정리되나요?
- **부족한 부분:** Runtime Module에 Editor 호출 함수가 함께 존재하고 생성·검증·debug 책임이 Actor에 많이 모여 있다.

### Q079

- **질문:** Throwable과 Inventory를 어떻게 commit 단위로 연결했나요?
- **질문 의도:** 아이템 소비와 projectile 발사의 원자적 경계를 확인한다.
- **좋은 답변:** Ready/Aim은 아이템을 소비하지 않고 실제 투척 commit 성공 시 Inventory를 차감하도록 연결한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMThrowableGameplayIntegration`의 Inventory Use Effect와 bridge가 throwable session을 시작하고 native commit delegate를 받아 item 사용·UI·이동 제한을 정리한다.
- **추가 꼬리 질문:** Projectile spawn이 실패하면 아이템은 어떻게 되나요?
- **부족한 부분:** Inventory/UI/Enhanced Input/이동 정책이 Integration bridge에 집중돼 실패 transaction을 더 명시적으로 테스트해야 한다.

### Q080

- **질문:** MonsterFramework가 Enemy 기능을 Component로 나눈 방식을 설명하세요.
- **질문 의도:** AI orchestration과 세부 책임의 분리를 읽었는지 본다.
- **좋은 답변:** Enemy Actor는 Definition으로 state, memory, perception, locomotion, action, audio, StateTree component를 조립한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `AJMEnemyBase`가 `UJMEnemyStateComponent`, `UJMEnemyMemoryComponent`, `UJMEnemyPerceptionComponent`, `UJMEnemyActionComponent` 등을 소유하고 StateTree는 possession 후 시작한다.
- **추가 꼬리 질문:** Perception Component가 behavior를 직접 선택하지 않는 이유는 무엇인가요?
- **부족한 부분:** Host에는 별도 concrete BehaviorTree Monster도 있어 두 AI orchestration 체계의 장기 경계가 확정되지 않았다.

---

## 고급 질문 50개

### Q081

- **질문:** 이 프로젝트에서 SOLID가 가장 잘 적용된 부분과 약한 부분을 하나씩 고르세요.
- **질문 의도:** 원칙을 암기하지 않고 실제 코드에 적용하는지 본다.
- **좋은 답변:** 구체 클래스·함수와 변경 이유를 들어 장점과 위반을 함께 말한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door movement 계층과 Integration adapter는 OCP/DIP가 좋고, `UJMDoorComponent`와 `UJMHarpoonGunComponent`는 많은 정책을 소유해 SRP가 약하다.
- **추가 꼬리 질문:** 먼저 분리할 책임과 그 이유는 무엇인가요?
- **부족한 부분:** Component 분할만으로 SOLID가 자동 충족되는 것은 아니며 orchestration 책임이 여전히 집중된 곳이 많다.

### Q082

- **질문:** Integration Plugin이 DIP를 만족한다고 볼 근거는 무엇인가요?
- **질문 의도:** dependency graph와 runtime call contract를 함께 보는지 확인한다.
- **좋은 답변:** 상위 조립 layer가 양쪽 abstraction을 소비하고 base가 concrete integration을 모르는 방향을 증명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door/Hide/Recon base `.uplugin`과 `Build.cs`에는 Integration 역참조가 없고 Integration의 adapter가 Interface와 context 변환을 소유한다.
- **추가 꼬리 질문:** Integration이 base의 concrete Component를 cast하면 DIP가 깨진 것 아닌가요?
- **부족한 부분:** `JMDoorReconIntegration`의 sliding movement cast처럼 abstraction 누수가 일부 남아 있다.

### Q083

- **질문:** `FJMGameplayEventMessage::Payload`가 `UObject*`인 설계의 type safety를 어떻게 평가하나요?
- **질문 의도:** 확장성과 정적 타입 안전성의 교환을 분석하는지 본다.
- **좋은 답변:** 새 payload 확장은 쉽지만 tag-payload 조합 오류가 compile time에 잡히지 않으므로 schema 검증이 필요하다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory·Interaction·Door payload가 `UJMGameplayEventPayloadBase`를 상속하지만 Message는 임의 UObject를 허용하고 Objective는 runtime cast에 의존한다.
- **추가 꼬리 질문:** Template event bus나 InstancedStruct로 바꾸면 무엇이 달라지나요?
- **부족한 부분:** Event Tag별 허용 payload class registry와 validation이 없다.

### Q084

- **질문:** Event dispatch의 재진입 가능성이 어떤 상태 버그를 만들 수 있나요?
- **질문 의도:** callback이 동기적으로 원 호출 stack 안에서 실행됨을 이해하는지 본다.
- **좋은 답변:** 발행 중 listener가 같은 시스템 상태를 변경·재발행해 중간 불변식을 관찰하거나 순서를 뒤집을 수 있다고 설명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `PublishEvent`는 동기 실행이며 nested dispatch를 허용하되 depth만 제한하므로 Inventory event에서 Objective 완료 event까지 같은 stack에 이어질 수 있다.
- **추가 꼬리 질문:** queue dispatch로 바꾸면 어떤 테스트가 깨질까요?
- **부족한 부분:** 각 producer가 event 발행 전에 도메인 mutation을 완전히 commit했는지 공통 규칙으로 강제하지 않는다.

### Q085

- **질문:** Gameplay Event dispatch의 시간 복잡도와 병목을 설명하세요.
- **질문 의도:** 데이터 구조 선택을 성능 관점에서 분석하는지 본다.
- **좋은 답변:** 모든 tag bucket과 해당 subscriptions를 검사하므로 bucket 수·구독 수에 비례하고 callback 비용이 더해진다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `PublishEvent`는 `SubscriptionsByTag` 전체를 순회해 exact/child match snapshot을 만들고 dispatch 후 invalid cleanup도 다시 순회한다.
- **추가 꼬리 질문:** Tag parent index를 만들면 어떤 trade-off가 있나요?
- **부족한 부분:** 대규모 구독량 benchmark와 hot tag별 통계가 없다.

### Q086

- **질문:** Event Message의 Payload 수명은 callback 이후에도 안전한가요?
- **질문 의도:** stack message와 UObject outer/GC 수명을 구분하는지 본다.
- **좋은 답변:** 동기 callback 안에서는 message의 strong reflected pointer로 접근 가능하지만 저장해 나중에 쓰려면 별도 소유·복사 계약이 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** producer는 보통 `NewObject<Payload>(this)` 후 즉시 동기 publish하며 subscriber는 callback 안에서 cast해 읽는다.
- **추가 꼬리 질문:** 비동기 queue로 바꾸면 Payload outer를 어떻게 정해야 하나요?
- **부족한 부분:** Message나 raw reference를 callback 밖에 보존하지 말라는 명시적 계약이 Public API에 약하다.

### Q087

- **질문:** GameInstanceSubsystem이 PIE 다중 World에서 주의할 점은 무엇인가요?
- **질문 의도:** “전역” service와 World context가 동일하지 않음을 이해하는지 본다.
- **좋은 답변:** 한 GameInstance의 올바른 subsystem을 World context로 찾고 다른 PIE instance나 stale World 객체를 섞지 않아야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Event·Objective·Dialogue는 GameInstance에서 얻고 Door adapter는 WorldSubsystem으로 분리해 현재 World Actor만 순회한다.
- **추가 꼬리 질문:** Editor utility에서 World가 여러 개면 어떤 것을 선택하나요?
- **부족한 부분:** 일부 helper가 `GetWorld()` 가용성에 의존하며 multi-PIE 검증 범위가 문서화돼 있지 않다.

### Q088

- **질문:** GameInstance에 gameplay state를 두는 것이 multiplayer에서 항상 맞나요?
- **질문 의도:** 로컬 수명과 네트워크 authority를 구분하는지 본다.
- **좋은 답변:** GameInstance는 복제되지 않으므로 authoritative 공유 상태는 GameState/PlayerState나 server actor에 두고 로컬 service는 orchestration만 맡아야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Objective와 prototype progression이 GameInstanceSubsystem에 있고 현재 코드는 로컬 플레이 중심이며 복제 contract가 없다.
- **추가 꼬리 질문:** Player별 Objective라면 어디에 authoritative state를 둘 건가요?
- **부족한 부분:** single-player 가정을 코드/API에 명시하거나 multiplayer migration 계획을 세우지 않았다.

### Q089

- **질문:** Event bus가 game thread만 허용하는 이유와 한계는 무엇인가요?
- **질문 의도:** UObject 접근과 container 동기화 문제를 이해하는지 본다.
- **좋은 답변:** UObject gameplay mutation과 구독 map을 lock 없이 안전하게 다루지만 worker 결과는 game thread로 marshal해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Publish/Subscribe/Unsubscribe 모두 `ensureMsgf(IsInGameThread())`로 guard하며 별도 mutex나 task queue가 없다.
- **추가 꼬리 질문:** Async asset load callback에서 발행하려면 어떻게 하겠나요?
- **부족한 부분:** 비게임 thread producer를 위한 공식 enqueue API가 없다.

### Q090

- **질문:** 이 프로젝트를 네트워크 게임으로 바꾸면 먼저 손댈 경계는 어디인가요?
- **질문 의도:** 로컬 gameplay 구조를 authority·RPC·replication으로 재설계할 수 있는지 본다.
- **좋은 답변:** interaction/Inventory/Door/Recon/Hide의 명령은 server 검증, 상태는 replicated owner, UI는 client presentation으로 분리한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMGameplayEventSubsystem`은 주석으로 RPC/replication을 하지 않는다고 명시하고 대부분 session·reservation·inventory가 로컬 Component 상태다.
- **추가 꼬리 질문:** Client prediction이 필요한 시스템과 아닌 시스템을 구분해 보세요.
- **부족한 부분:** authority check, replicated properties, server RPC가 핵심 Plugin 계약에 거의 없다.

### Q091

- **질문:** BlueprintNativeEvent Interface의 기본 구현이 만들 수 있는 위험은 무엇인가요?
- **질문 의도:** 동적 계약이 compile-time 강제를 약화시키는 점을 보는 질문이다.
- **좋은 답변:** 필수 동작을 구현하지 않아도 컴파일되며 기본 false/빈 결과로 조용히 실패할 수 있으므로 validation과 contract test가 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `IJMInteractableInterface`의 여러 단계와 `IJMReconTarget` 구현은 adapter/Blueprint에 위임돼 누락이 runtime failure로 나타날 수 있다.
- **추가 꼬리 질문:** pure virtual과 Blueprint 지원을 동시에 얻는 방법은 무엇인가요?
- **부족한 부분:** 필수 Interface 구현 completeness를 Asset Validation에서 일괄 검사하지 않는다.

### Q092

- **질문:** 매 호출마다 `FindComponentByClass`를 사용하는 비용과 대안은 무엇인가요?
- **질문 의도:** 편리한 런타임 discovery의 성능·명시성 비용을 평가하는지 본다.
- **좋은 답변:** component 수에 비례한 검색과 구성 오류 지연이 생기므로 initialization 시 캐시하거나 명시적 reference를 주입한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door Integration agent, Hide/Recon 자동 bridge, StateTree external data resolver 등에서 component 탐색이 반복된다.
- **추가 꼬리 질문:** 캐시한 Component가 파괴·교체되면 어떻게 invalidation하나요?
- **부족한 부분:** dynamic component 설치와 캐시 invalidation의 공통 정책이 없다.

### Q093

- **질문:** Runtime에 `NewObject + AddInstanceComponent + RegisterComponent`로 Component를 붙일 때 주의점은 무엇인가요?
- **질문 의도:** 동적 Component의 registration, replication, save, ownership을 아는지 본다.
- **좋은 답변:** owner/outer, 생성 시점, 중복, BeginPlay, replication flag, destruction·save 여부를 명확히 해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMDoorInteractionWorldSubsystem::EnsureDoorAdapter`와 여러 Integration이 이 패턴으로 adapter를 보장하고 중복은 `FindComponentByClass`로 막는다.
- **추가 꼬리 질문:** Client에도 같은 Component가 자동 생성된다는 보장이 있나요?
- **부족한 부분:** authority와 replication, authored component와의 우선순위, instance component 저장 정책이 명문화돼 있지 않다.

### Q094

- **질문:** Soft reference인데도 runtime hitch가 생길 수 있는 이유는 무엇인가요?
- **질문 의도:** 참조 방식과 실제 load 시점을 구분하는지 본다.
- **좋은 답변:** `LoadSynchronous`를 gameplay 첫 호출에서 실행하면 디스크/Asset load가 그 frame을 막기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory InputAction/Widget, Interaction prompt Widget, Recon default Definition 등의 fallback 경로가 동기 로드를 사용한다.
- **추가 꼬리 질문:** 로딩 실패 시 UI 흐름은 어떻게 degrade해야 하나요?
- **부족한 부분:** Plugin별 preload 목록과 async completion state가 통일돼 있지 않다.

### Q095

- **질문:** Asset Manager를 도입한다면 어떤 Asset부터 관리하겠나요?
- **질문 의도:** 현재 Data Asset과 soft reference를 확장 가능한 로딩 정책으로 연결하는지 본다.
- **좋은 답변:** stable PrimaryAssetId가 있고 gameplay 시작 전에 묶어 preload할 정의와 UI/효과 asset부터 지정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UInventoryItemDefinition::GetPrimaryAssetId`가 이미 있고 Enemy/Dialogue/Objective Definition과 soft presentation asset이 후보다.
- **추가 꼬리 질문:** Primary Asset label과 bundle을 어떻게 나누겠나요?
- **부족한 부분:** 프로젝트 전역 Asset Manager scan rule과 bundle 기반 preload가 현재 문서·config에서 분명하지 않다.

### Q096

- **질문:** Settings→Definition→Instance→Request override 구조의 위험은 무엇인가요?
- **질문 의도:** 유연한 configuration이 디버깅 가능성을 해칠 수 있음을 보는 질문이다.
- **좋은 답변:** 최종값의 출처를 알기 어렵고 새 필드가 merge 함수에서 누락될 수 있어 trace와 테스트가 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHideSpotComponent::ResolveConfig`가 여러 override 계층을 합성하고 Recon도 instance→settings→default fallback을 사용한다.
- **추가 꼬리 질문:** 최종 effective config를 Editor에서 보여주려면 어떻게 하겠나요?
- **부족한 부분:** 값별 source provenance와 공통 merge framework가 없다.

### Q097

- **질문:** Mutable default object를 fallback으로 반환할 때 어떤 문제가 생길 수 있나요?
- **질문 의도:** CDO/shared object의 전역 mutable state 위험을 이해하는지 본다.
- **좋은 답변:** 여러 instance가 같은 객체를 공유하므로 runtime mutation이 다른 대상에 누출될 수 있어 const read-only 계약이 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Recon target의 `GetEffectiveDefinition`은 instance와 settings가 없으면 mutable default Definition을 사용한다.
- **추가 꼬리 질문:** 왜 `GetDefault`와 `GetMutableDefault`를 구분해야 하나요?
- **부족한 부분:** fallback Definition을 절대 수정하지 않는다는 invariant가 타입 시스템으로 강제되지 않는다.

### Q098

- **질문:** Door save가 future version을 거부하는 방식의 장단점은 무엇인가요?
- **질문 의도:** forward/backward compatibility를 구분하는지 본다.
- **좋은 답변:** 알 수 없는 schema를 잘못 적용하지 않아 안전하지만 downgrade나 단계별 migration을 지원하지 못한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `RestoreSaveData`는 version 1과 2만 허용하며 나머지는 warning 후 false다.
- **추가 꼬리 질문:** Custom version GUID를 쓰는 방식과 비교해 보세요.
- **부족한 부분:** version별 migration 함수와 fixture archive가 분리되지 않아 조건문이 계속 커질 수 있다.

### Q099

- **질문:** Inventory 자동 이동 rollback이 완전하지 않은 이유를 코드로 설명하세요.
- **질문 의도:** “atomic”이라는 주석을 그대로 믿지 않고 구현을 검증하는지 본다.
- **좋은 답변:** 실제 변경 위치를 기록하지 않고 같은 Definition 수량만 제거하면 기존 stack과 새 추가분을 구분하지 못한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `MoveItem`은 partial `AddItemDetailed` 후 `Destination->RemoveItem(SourceSnapshot.ItemDefinition, AddedQuantity)`으로 보상한다.
- **추가 꼬리 질문:** 정확한 rollback을 어떻게 구현하겠나요?
- **부족한 부분:** slot index·old/new quantity delta journal이 없어 관찰 가능한 event까지 완전히 되돌리지 못할 수 있다.

### Q100

- **질문:** Item Definition pointer와 ItemId 중 어느 것을 identity로 써야 하나요?
- **질문 의도:** 객체 identity와 gameplay identity를 구분하는지 본다.
- **좋은 답변:** Asset instance pointer는 같은 load context의 객체 정체성, 저장·재로드·논리적 stack은 안정 ItemId를 사용한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory save와 sort consolidation은 `ItemId`를 사용하지만 일부 add/remove/stack 비교는 Definition pointer를 사용한다.
- **추가 꼬리 질문:** ItemId가 변경되면 기존 save를 어떻게 migration하나요?
- **부족한 부분:** identity 정책과 alias/migration table이 중앙화돼 있지 않다.

### Q101

- **질문:** Local delegate와 global event를 모두 발행할 때 상태 일관성을 어떻게 보장하나요?
- **질문 의도:** 두 관찰 채널의 순서와 중복 처리 문제를 본다.
- **좋은 답변:** mutation 완료 후 정해진 순서로 발행하고 event payload에 revision/operation ID를 넣어 중복과 재진입을 구분한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory·Door·Objective가 local delegate와 `JMGameplayEvent`를 함께 사용하지만 공통 revision contract는 없다.
- **추가 꼬리 질문:** Local listener가 상태를 다시 바꾸면 global payload는 무엇을 담아야 하나요?
- **부족한 부분:** 발행 순서와 callback mutation을 도메인 transaction 차원에서 고정하는 테스트가 더 필요하다.

### Q102

- **질문:** 이 Event bus는 exactly-once delivery를 보장하나요?
- **질문 의도:** “발행했다”와 전달 보장 수준을 구분하는지 본다.
- **좋은 답변:** 프로세스 내 동기 구독 handle별 한 번 호출은 가능하지만 중복 구독·재발행·crash·network를 포함한 exactly-once는 아니라고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Duplicate subscription은 warning만 하고 허용돼 같은 listener가 handle 수만큼 호출되며 테스트도 두 번 수신을 기대한다.
- **추가 꼬리 질문:** At-most-once가 필요한 listener는 어떻게 구현하나요?
- **부족한 부분:** event ID나 idempotency key가 Message에 없다.

### Q103

- **질문:** Modal suppression depth와 token stack 중 어느 쪽이 더 안전한가요?
- **질문 의도:** reference count의 출처 추적 한계를 보는 질문이다.
- **좋은 답변:** 단순 중첩에는 depth가 싸지만 token stack은 owner별 정확한 pop, 중복 close 검출, priority 복원을 제공한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Interaction은 정수 depth, Inventory·Dialogue·Inspector는 각자 input 상태를 저장해 공통 token owner가 없다.
- **추가 꼬리 질문:** Modal이 파괴돼 close event를 못 보내면 어떻게 복구하나요?
- **부족한 부분:** 프로젝트 전역 modal coordinator가 없어 여러 UI가 입력 상태를 덮어쓸 수 있다.

### Q104

- **질문:** `FInputMode`를 완전히 저장했다가 복원하기 어려운 이유는 무엇인가요?
- **질문 의도:** PlayerController API의 상태 가시성과 ownership을 이해하는지 본다.
- **좋은 답변:** 현재 input mode의 모든 내부 설정을 조회하는 대칭 getter가 부족해 각 UI가 자신이 설정한 상태를 추적해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Inventory는 cursor와 move/look flags를 저장해 mode를 재구성하고 Dialogue는 종료 시 무조건 `FInputModeGameOnly`를 적용한다.
- **추가 꼬리 질문:** CommonUI를 쓰지 않고 해결한다면 어떤 API를 만들겠나요?
- **부족한 부분:** UI 간 중첩 복원을 검증하는 통합 테스트와 중앙 ownership stack이 없다.

### Q105

- **질문:** Timer callback의 stale 실행을 어떻게 방어해야 하나요?
- **질문 의도:** timer clear만으로 충분하지 않은 비동기 수명 문제를 보는 질문이다.
- **좋은 답변:** weak owner, expected SessionId/state/generation을 callback에서 재검사하고 cleanup을 idempotent하게 만든다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Recon은 SessionId와 weak self를 사용하며 Dialogue callback은 현재 state·sequence index·Widget 유효성을 확인한다.
- **추가 꼬리 질문:** Timer를 clear한 직후 이미 실행 stack에 들어온 callback은 어떻게 되나요?
- **부족한 부분:** 모든 timer 기반 Plugin에 같은 generation guard가 일관되게 적용된 것은 아니다.

### Q106

- **질문:** 완전한 사용자 인식 문자 단위 타이핑을 구현하려면 무엇이 더 필요한가요?
- **질문 의도:** code unit, code point, grapheme cluster의 차이를 아는지 본다.
- **좋은 답변:** Unicode grapheme break 알고리즘이나 ICU 기반 segmentation으로 결합 문자와 ZWJ sequence를 묶어야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 현재 `TokenizeCharacters`는 UTF-16 surrogate pair까지만 보호해 보조 평면 code point는 지키지만 grapheme 전체는 아니다.
- **추가 꼬리 질문:** RichText markup이 들어오면 tokenization 순서를 어떻게 정하나요?
- **부족한 부분:** markup run과 localization shaping을 고려한 tokenizer contract가 없다.

### Q107

- **질문:** `UJMDoorComponent`를 분해한다면 어떤 책임부터 나누겠나요?
- **질문 의도:** 실제 God Component의 seam을 찾는지 본다.
- **좋은 답변:** access, durability, obstruction, audio/noise, save 중 변경 이유와 의존성이 독립적인 policy를 우선 분리한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door Component는 명령·state·movement orchestration·접근·손상·character push·timer·save·event를 모두 소유한다.
- **추가 꼬리 질문:** 분해 후 transaction 일관성은 누가 책임지나요?
- **부족한 부분:** 단순 Component 증식은 호출 순서만 복잡하게 만들 수 있어 Door aggregate root는 유지해야 한다.

### Q108

- **질문:** Door obstruction과 character push를 성능 최적화한다면 어디를 측정하겠나요?
- **질문 의도:** 추측이 아니라 profile 지점을 제시하는지 본다.
- **좋은 답변:** 이동 Door 수, tick 시간, overlap/sweep 횟수, substep 수, hit Actor 수를 Unreal Insights와 stat으로 측정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door는 이동 중에만 tick하지만 predictive overlap과 swept path character correction을 실행한다.
- **추가 꼬리 질문:** 먼 Door는 simulation을 생략해도 되나요?
- **부족한 부분:** 거리/가시성 기반 budget이나 대규모 stress benchmark가 없다.

### Q109

- **질문:** Dual-panel Door를 더 일반화한다면 어떤 모델이 적합한가요?
- **질문 의도:** 특수 분기를 collection abstraction으로 바꿀 수 있는지 본다.
- **좋은 답변:** panel ID별 state/fraction/movement channel collection을 두고 aggregate state를 계산한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 현재는 `SlideDoorA`와 `SlideDoorB` 전용 필드·timer·save field가 있고 `IsDualPanelSlidingDoor` 분기가 core에 있다.
- **추가 꼬리 질문:** 기존 v1/v2 save와 어떻게 호환하나요?
- **부족한 부분:** 두 panel을 넘어서는 문 구조는 field와 분기 수가 급증한다.

### Q110

- **질문:** Door key 소비를 보안 관점에서 어떻게 설계해야 하나요?
- **질문 의도:** client 제공 tag를 신뢰하지 않는 authority 설계를 보는 질문이다.
- **좋은 답변:** server가 authoritative Inventory에서 key 존재와 소비를 한 transaction으로 검증하고 client context는 요청으로만 취급한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 현재 `FJMDoorUseContext`와 access provider/inventory agent가 로컬 tag·item을 전달하는 single-player 구조다.
- **추가 꼬리 질문:** 성공 event는 검증 전후 언제 발행해야 하나요?
- **부족한 부분:** server RPC, anti-replay operation ID, replicated Door state가 없다.

### Q111

- **질문:** Recon과 Hide의 SessionId 패턴을 공통 프레임워크로 만들 수 있나요?
- **질문 의도:** 중복 abstraction과 도메인 특화의 균형을 본다.
- **좋은 답변:** token, expected phase, cancellation, idempotent cleanup은 공통화하되 mode·rollback 정책은 도메인에 남긴다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 두 시스템 모두 FGuid, weak providers, 단계 state, reservation, late callback 방어를 사용하지만 별도 구현이다.
- **추가 꼬리 질문:** 공통 base class보다 composition utility가 나은 이유는 무엇인가요?
- **부족한 부분:** 성급한 상속 공통화는 Hide의 compensation과 Recon의 camera/audio semantics를 왜곡할 수 있다.

### Q112

- **질문:** Cancel, Fail, Complete를 별도 terminal state로 둬야 하는 이유는 무엇인가요?
- **질문 의도:** 종료 원인에 따른 delegate·복구·통계를 구분하는지 본다.
- **좋은 답변:** 호출자 의도, 시스템 오류, 정상 완료는 UI·analytics·rollback과 재시도 정책이 다르기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Hide `FJMHideSession::IsActive`는 Completed/Cancelled/Failed를 구분하고 Dialogue도 `EDialogueEndReason`과 cancelled 여부로 delegate를 나눈다.
- **추가 꼬리 질문:** TargetDestroyed는 cancel인가 fail인가요?
- **부족한 부분:** Plugin마다 terminal enum과 event naming이 달라 프로젝트 전역 의미가 통일되지는 않았다.

### Q113

- **질문:** Cleanup을 idempotent하게 만드는 구체적인 방법은 무엇인가요?
- **질문 의도:** 여러 종료 경로가 같은 자원을 두 번 해제하는 문제를 이해하는지 본다.
- **좋은 답변:** 시작/완료 flag나 상태 전이 guard를 먼저 설정하고 각 resource handle 유효성을 확인해 한 번만 반환한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Hide `Cleanup`은 `bCleanupCompleted`면 반환하고 `bCleanupStarted`를 기록하며 Spot release와 participant restore를 수행한다.
- **추가 꼬리 질문:** Cleanup 도중 다른 callback이 들어오면 어떤 state를 보게 해야 하나요?
- **부족한 부분:** 모든 시스템이 동일한 idempotency 수준을 갖는 것은 아니며 긴 cleanup 함수의 부분 실패 처리도 필요하다.

### Q114

- **질문:** Active target이 파괴될 때 session을 안전하게 종료하는 방법은 무엇인가요?
- **질문 의도:** UObject destruction과 외부 delegate cleanup을 다룰 수 있는지 본다.
- **좋은 답변:** target을 weak reference로 보관하고 OnDestroyed를 bind해 expected session만 종료하며 cleanup에서 binding과 예약을 해제한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Recon interactor가 target Actor destroyed callback을 연결하고 대상 소멸 시 실패 종료 및 camera restore 경로로 간다.
- **추가 꼬리 질문:** Component만 파괴되고 Actor는 남으면 어떻게 감지하나요?
- **부족한 부분:** Actor OnDestroyed만으로 모든 provider component 수명 변화를 잡지는 못한다.

### Q115

- **질문:** Async provider가 completion을 두 번 보내면 Hide는 어떻게 방어해야 하나요?
- **질문 의도:** SessionId만으로 중복 완료를 모두 막을 수 없는 점을 본다.
- **좋은 답변:** SessionId와 operation, expected phase, stage completion flag를 함께 검사하고 첫 완료 후 phase를 먼저 전환한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMHideOperationCompletion`은 SessionId와 Operation을 갖고 interactor handler가 active session·phase를 검사한다.
- **추가 꼬리 질문:** 같은 session의 이전 stage callback은 어떻게 구분하나요?
- **부족한 부분:** provider별 monotonically increasing operation generation이 없어 phase guard 의존도가 높다.

### Q116

- **질문:** Hide의 force exit가 안전성과 gameplay 진행 중 무엇을 우선해야 하나요?
- **질문 의도:** 기술적으로 가능한 fallback의 제품 정책을 설명하는지 본다.
- **좋은 답변:** 일반 exit는 collision-safe anchor를 요구하고, deadlock 방지를 위한 force exit는 명시적 opt-in과 telemetry를 가져야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** primary/alternative anchor를 검사한 뒤 설정에 따라 collision을 무시한 force fallback이 가능하다.
- **추가 꼬리 질문:** Force exit 위치가 벽 안이면 다음 frame에 어떻게 복구하나요?
- **부족한 부분:** navigation projection이나 safe spot search 같은 최종 안전 장치가 더 필요하다.

### Q117

- **질문:** Host BehaviorTree와 Plugin StateTree가 공존하는 구조를 어떻게 정리하겠나요?
- **질문 의도:** 중복 orchestration framework의 migration 전략을 본다.
- **좋은 답변:** authoritative state owner를 먼저 정하고 BT는 legacy adapter 또는 특정 계층에 한정하며 신규 AI 표준을 ADR로 고정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UBTTask_JMMonsterState`는 Host `AJMDungeonMonster` state를 실행하고 `UJMEnemyStateTreeComponent`는 Plugin `AJMEnemyBase`에서 별도 tree를 구동한다.
- **추가 꼬리 질문:** 두 체계를 한 Enemy에서 동시에 돌리면 어떤 경쟁이 생기나요?
- **부족한 부분:** 프로젝트 차원의 최종 AI 표준과 migration 완료 조건이 없다.

### Q118

- **질문:** Host BT node의 concrete Monster 결합을 어떻게 낮출 수 있나요?
- **질문 의도:** 테스트 가능성과 재사용성을 높이는 seam을 찾는지 본다.
- **좋은 답변:** state query/decision/blackboard sync를 Interface 또는 ActorComponent contract로 추출하고 task는 그것만 소비한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMMonsterBehaviorTreeNodes.cpp`의 `GetMonster`는 controller pawn을 바로 `AJMDungeonMonster`로 cast한다.
- **추가 꼬리 질문:** Blueprint Interface와 native interface 중 무엇을 선택하겠나요?
- **부족한 부분:** concrete cast 때문에 다른 Enemy가 같은 BT node를 재사용할 수 없다.

### Q119

- **질문:** `CollectExternalData`의 type switch는 OCP 관점에서 어떤가요?
- **질문 의도:** 편리한 generic resolver가 새 타입 추가 시 수정되는 구조를 평가한다.
- **좋은 답변:** 현재 지원 타입에는 간결하지만 새 category마다 resolver 수정이 필요하므로 provider registry나 explicit schema를 검토한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMEnemyStateTreeComponent`는 요청 Struct가 WorldSubsystem, ActorComponent, AIController, Pawn/Actor인지 `IsChildOf`로 분기한다.
- **추가 꼬리 질문:** Required와 Optional external data를 어떻게 처리하나요?
- **부족한 부분:** 같은 base의 여러 component 중 어느 instance를 선택할지와 custom UObject provider 확장이 제한적이다.

### Q120

- **질문:** AI 의사결정을 결정적으로 테스트하려면 무엇을 제어해야 하나요?
- **질문 의도:** 시간·난수·perception·world query를 test seam으로 보는지 확인한다.
- **좋은 답변:** seed, clock, stimulus 입력, navigation/world query 결과를 주입하고 state transition을 순수 규칙에 가깝게 격리한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** MonsterFramework는 State·Memory·Perception·Action Component로 나뉘어 seam은 있으나 실제 World perception과 StateTree asset 의존 테스트도 존재한다.
- **추가 꼬리 질문:** Blackboard mirror는 source of truth가 될 수 있나요?
- **부족한 부분:** Host BT는 concrete Monster와 World 상태에 강하게 묶여 순수 decision test가 어렵다.

### Q121

- **질문:** Editor용 Commandlet이 Runtime Module에 있으면 왜 문제인가요?
- **질문 의도:** 코드 실행 시점보다 build dependency 경계를 우선 보는지 본다.
- **좋은 답변:** 게임에서 호출하지 않아도 Runtime binary와 dependency/API surface에 Editor 저작 책임이 섞이기 때문이다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 감사에서 `JMDoorGameplayIntegration`의 샘플 구성 Commandlet이 Runtime Module 안에 있는 것이 확인됐다.
- **추가 꼬리 질문:** Commandlet Module Type은 어떻게 분리하겠나요?
- **부족한 부분:** Runtime과 asset 생성/저장 코드 경계가 Plugin마다 일관되지 않다.

### Q122

- **질문:** Module API export macro와 Public header 설계가 왜 중요하나요?
- **질문 의도:** DLL 경계와 dependency 전파를 이해하는지 본다.
- **좋은 답변:** 다른 Module이 타입의 symbol을 링크할 수 있게 export하고 Public header에는 안정 계약과 최소 include만 노출해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `INVENTORYSYSTEM_API UInventoryComponent`, `JMDOORRUNTIME_API UJMDoorComponent` 같은 macro가 Plugin 간 API를 만들며 Integration이 이를 소비한다.
- **추가 꼬리 질문:** Forward declaration로 줄일 수 없는 경우는 언제인가요?
- **부족한 부분:** Public API에 concrete bridge/Inspector 타입이 노출된 곳은 선택적 dependency를 어렵게 한다.

### Q123

- **질문:** 재사용 Plugin의 `EnabledByDefault` 정책은 어떻게 정해야 하나요?
- **질문 의도:** 사용 편의와 최소 dependency closure를 균형 있게 보는지 확인한다.
- **좋은 답변:** 독립 base는 명시적 enable을 기본으로 하고 Integration은 양쪽 base가 필요할 때만 활성화되게 하며 문서에 최소 closure를 적는다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 여러 Plugin이 기본 활성화되고 WorldSubsystem Integration은 활성화만으로 actor scan과 adapter 주입을 시작한다.
- **추가 꼬리 질문:** Optional plugin dependency를 runtime에 검사하는 방법은 무엇인가요?
- **부족한 부분:** “설치했지만 쓰지 않는 Integration”의 비용과 전역 정책을 줄이는 opt-in 체계가 약하다.

### Q124

- **질문:** 현재 순환 의존은 없는데 앞으로 생길 수 있는 경로를 설명하세요.
- **질문 의도:** 그래프의 잠재 cycle을 예측하는지 본다.
- **좋은 답변:** base가 편의를 위해 Integration이나 상위 feature를 역참조할 때 cycle이 생기므로 interface/event를 아래 공통층에 둔다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 예를 들어 Door가 Inventory 편의를 직접 참조하면 `Door → Inventory → Interaction/Event`와 Integration 방향이 섞이며 구조가 역전될 수 있다.
- **추가 꼬리 질문:** CI에서 cycle을 어떻게 검출하나요?
- **부족한 부분:** 현재 그래프 문서는 있으나 `.uplugin`·`Build.cs` cycle을 자동 차단하는 전용 검사는 언급되지 않는다.

### Q125

- **질문:** 불필요한 dependency를 어떻게 판별했나요?
- **질문 의도:** Build.cs를 감으로 줄이지 않고 심볼 사용과 header 노출로 검증하는지 본다.
- **좋은 답변:** Public/Private source의 include·symbol 사용, generated header 요구, transitive 의존을 검색하고 target별 build로 확인한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 감사에서 `JMDoorRuntime`의 `InputCore`, JumpScare의 Slate, Recon의 AudioMixer가 직접 심볼 미검출 후보로 기록됐다.
- **추가 꼬리 질문:** 검색에서 안 나와도 dependency가 필요할 수 있는 경우는 무엇인가요?
- **부족한 부분:** 후보를 실제 제거한 뒤 전체 target compile로 검증하기 전에는 확정적인 “불필요”라고 단정할 수 없다.

### Q126

- **질문:** 이 프로젝트의 테스트 피라미드를 평가해 보세요.
- **질문 의도:** 테스트 수가 아니라 실행 환경과 feedback 속도를 평가하는지 본다.
- **좋은 답변:** 순수 규칙·UObject test가 기반, World/Functional이 중간, 실제 map PIE가 상단이어야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Event bus·Door 수학은 빠른 Automation, Door Blueprint는 Functional, Recon/Hide/던전은 PIE latent로 구성돼 층화가 보인다.
- **추가 꼬리 질문:** 가장 먼저 CI에서 돌릴 suite는 무엇인가요?
- **부족한 부분:** suite label, 평균 실행 시간, flaky rate, coverage 목표가 문서화돼 있지 않다.

### Q127

- **질문:** GC 관련 테스트가 실제로 무엇을 증명하나요?
- **질문 의도:** `TStrongObjectPtr`와 weak subscription의 수명 조건을 읽는지 본다.
- **좋은 답변:** 유일한 strong reference를 제거하고 GC 후 publish해 listener가 호출되지 않고 dead entry가 제거됨을 증명한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FJMGameplayEventDestroyedListenerTest`가 Receiver를 reset하고 `CollectGarbage` 후 호출 수 0과 subscription count 0을 검사한다.
- **추가 꼬리 질문:** Delegate 자체가 UObject를 strong capture하면 결과가 달라지나요?
- **부족한 부분:** 모든 lambda/callback capture 형태를 검사하는 것은 아니며 native delegate 구현 세부에 의존한다.

### Q128

- **질문:** Door는 Functional Test, Recon은 PIE Test를 선택한 이유를 추론해 보세요.
- **질문 의도:** 검증 대상에 필요한 최소 실행 환경을 선택하는지 본다.
- **좋은 답변:** Door Actor 상태·transform은 World와 Functional Actor면 충분하지만 Recon은 실제 PlayerController input/camera/BeginPlay가 필요하다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `AJMDoorFunctionalTest`는 Door Blueprint를 spawn해 state/fraction을 확인하고 `JMReconLevelTestPIETest`는 `Level_test`에서 control rotation과 prompt 복원을 확인한다.
- **추가 꼬리 질문:** Functional Test도 PIE map에서 실행할 수 있는데 굳이 나눈 이유는 무엇인가요?
- **부족한 부분:** 일부 World automation과 PIE 경계가 일관된 분류 규칙으로 문서화되지는 않았다.

### Q129

- **질문:** Asset path를 직접 쓰는 PIE 테스트의 취약점과 보완책은 무엇인가요?
- **질문 의도:** 통합 테스트의 현실적 유지 비용을 보는 질문이다.
- **좋은 답변:** rename/move에 깨지므로 soft object path 상수, asset registry query, redirector 검사와 content validation을 병행한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Recon/Hide tests는 `/Game/Level/Level_test`, Door Functional은 Plugin demo Blueprint path를 실제로 로드한다.
- **추가 꼬리 질문:** Path 변경을 테스트 실패가 아니라 compile-time에 잡을 수 있나요?
- **부족한 부분:** 문자열 path가 여러 test에 분산되면 rename 대응과 오류 원인 진단이 느리다.

### Q130

- **질문:** 이 프로젝트용 CI를 설계한다면 어떤 단계를 두겠나요?
- **질문 의도:** 빌드·문서·테스트·Asset 검증을 실제 Module 구조에 맞춰 설계하는지 본다.
- **좋은 답변:** dependency/docs 정적 검사, Runtime/Editor target build, fast automation, content validation, PIE, 선택적 packaged smoke 순으로 나눈다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `Validate-Docs.ps1`, 다수 Editor Test Module, Runtime/Editor 분리, PIE tests가 있어 단계별 suite를 구성할 근거가 있다.
- **추가 꼬리 질문:** 어느 실패를 merge blocker로 만들겠나요?
- **부족한 부분:** 저장소에서 CI workflow, test timing, flaky quarantine, packaged Gauntlet 실행은 확인되지 않는다.

---

## 압박 질문 20개

### Q131

- **질문:** 신입 포트폴리오에 Plugin이 21개나 필요한가요? 과설계 아닌가요?
- **질문 의도:** 구조의 크기를 방어만 하지 않고 비용과 기준을 인정하는지 본다.
- **좋은 답변:** 독립 배포·테스트·선택 사용 가치가 있는 경계만 유지하고 조합 전용 Plugin 폭증과 boilerplate 비용을 인정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Event, Interaction, Footstep처럼 독립성이 높은 Plugin은 타당하지만 Door/Recon/Hide/Throwable 조합마다 Integration이 생겨 운영 복잡도가 높다.
- **추가 꼬리 질문:** 지금 당장 합칠 Plugin 세 개를 고르세요.
- **부족한 부분:** 실제 외부 프로젝트 재사용 횟수나 build-time 자료가 없어 21개 분리의 ROI를 수치로 증명하지 못한다.

### Q132

- **질문:** Event bus는 결국 누가 무엇을 호출하는지 숨기는 전역 서비스 아닌가요?
- **질문 의도:** 느슨한 결합의 대가인 추적성 저하를 인정하는지 본다.
- **좋은 답변:** 모든 통신을 bus로 보내지 않고 local typed call과 global integration을 구분하며 tag/payload publisher-subscriber 목록과 logging을 유지한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Objective·modal·progression 간 간접 연결에는 `JMGameplayEvent`를 쓰지만 Door adapter의 핵심 명령은 typed Interface/direct call로 유지한다.
- **추가 꼬리 질문:** 디버거로 한 event의 전체 원인을 어떻게 추적하나요?
- **부족한 부분:** Message에 correlation ID·timestamp·call trace가 없어 nested event 원인 추적이 어렵다.

### Q133

- **질문:** Payload가 UObject면 타입 안전성이 없는데 왜 이런 설계를 했나요?
- **질문 의도:** 약점을 부정하지 않고 당시 trade-off와 개선책을 말하는지 본다.
- **좋은 답변:** Blueprint 확장과 공통 envelope를 우선한 선택이며 tag-payload registry나 typed wrapper로 보완해야 한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Objective 공통 필드를 `UJMGameplayEventPayloadBase`로 올려 concrete cast를 줄였지만 Message 자체는 임의 UObject를 허용한다.
- **추가 꼬리 질문:** 잘못된 Payload가 들어오면 현재는 어떻게 실패하나요?
- **부족한 부분:** Cast 실패가 0 progress나 필터 실패로 조용히 나타날 수 있어 즉시 validation error가 필요하다.

### Q134

- **질문:** 왜 GAS, Gameplay Message Router, CommonUI를 쓰지 않고 직접 만들었나요?
- **질문 의도:** “몰라서 안 썼다”가 아닌 문제 규모와 도입 비용 판단을 듣는다.
- **좋은 답변:** single-player reusable feature에 필요한 최소 계약을 만들었고 network prediction·ability cost·UI stack 요구가 커지면 검증된 엔진 체계로 전환한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 현재 event bus는 동기·비복제이고 Inventory/Interaction/UI는 가벼운 Component 구조라 GAS 전 기능이 필요하지 않았지만 modal/input stack은 CommonUI 대안이 유효하다.
- **추가 꼬리 질문:** 직접 구현한 코드가 엔진 기능보다 낫다는 근거는 있나요?
- **부족한 부분:** 비교 benchmark나 선택 ADR이 없어 사후 합리화로 보일 수 있다.

### Q135

- **질문:** Soft reference를 써 놓고 `LoadSynchronous`를 호출하면 의미가 있나요?
- **질문 의도:** 표면적 패턴 사용과 실제 runtime 효과를 구분하는지 본다.
- **좋은 답변:** hard dependency와 초기 memory residency는 줄지만 첫 호출 hitch는 남으므로 async preload가 필요하다고 정확히 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Widget·InputAction·Recon Definition을 설정으로 교체할 수 있다는 이점은 있지만 일부 gameplay 진입점에서 동기 로드한다.
- **추가 꼬리 질문:** 어느 화면에서 어떤 Asset을 언제 preload할 건가요?
- **부족한 부분:** 로딩 budget, Asset bundle, 실패 fallback이 체계화되지 않았다.

### Q136

- **질문:** 인벤토리를 닫으면 이전 입력 모드가 정말 정확히 돌아오나요?
- **질문 의도:** 구현의 보장 범위를 과장하는지 확인한다.
- **좋은 답변:** cursor와 자신이 적용한 move/look block은 복원하지만 임의의 기존 `FInputMode` 전체는 복원하지 못한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `RestoreInputMode`는 저장된 flag를 바탕으로 GameOnly/GameAndUI를 재구성할 뿐 기존 Widget focus·mouse lock 설정 객체를 capture하지 않는다.
- **추가 꼬리 질문:** 다른 modal 위에서 Inventory를 열었다 닫으면 어떻게 되나요?
- **부족한 부분:** 중앙 modal token stack이 없어 중첩 순서에 따라 외부 UI 상태를 덮을 수 있다.

### Q137

- **질문:** Dialogue는 종료 시 무조건 GameOnly로 바꾸는데 명백한 버그 아닌가요?
- **질문 의도:** 지적을 회피하지 않고 영향과 수정 방안을 제시하는지 본다.
- **좋은 답변:** 기존 UI mode 위에서 열렸다면 상태 손실 가능성이 있는 결함이며 공통 input ownership stack으로 고쳐야 한다고 인정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UDialogueSubsystem::RestoreInteractionMode`는 `SetInputMode(FInputModeGameOnly())` 후 cursor boolean만 복원한다.
- **추가 꼬리 질문:** 왜 테스트가 이 문제를 잡지 못했나요?
- **부족한 부분:** 중첩 modal에서 Dialogue 종료 후 기존 focus/input mode를 검증하는 PIE test가 없다.

### Q138

- **질문:** 주석에는 `MoveItem`이 atomic이라고 했는데 실제로는 아니지 않나요?
- **질문 의도:** 자신의 용어 사용을 엄밀하게 방어할 수 있는지 본다.
- **좋은 답변:** 단일 game-thread 호출에서 source 손실을 막는 보상형 원자성이지 event·slot layout까지 포함한 강한 transaction은 아니라고 범위를 한정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** partial destination add를 Definition 수량 제거로 보상하지만 정확한 slot delta journal과 event rollback은 없다.
- **추가 꼬리 질문:** “atomic” 주석을 바꿀 건가요, 구현을 바꿀 건가요?
- **부족한 부분:** 현재 표현은 보장 수준을 과장할 수 있어 API 문서와 구현 모두 정밀화해야 한다.

### Q139

- **질문:** Inventory는 `MakeSaveEntries`만 있고 복원 API가 없는데 저장 기능이라고 할 수 있나요?
- **질문 의도:** 반쪽짜리 API를 완성된 기능처럼 포장하는지 본다.
- **좋은 답변:** Plugin은 capture DTO만 제공하고 resolver/orchestrator는 Host 책임이지만 public restore contract 부재는 재사용성 결함이라고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `FInventorySaveEntry`는 ItemId·Quantity·InstanceId를 만들고 Host prototype progression이 save/restore를 조립하지만 Inventory Component 자체에는 대칭 restore API가 없다.
- **추가 꼬리 질문:** 누락된 ItemId는 복원 시 어떻게 처리해야 하나요?
- **부족한 부분:** Definition registry, partial restore 결과, schema version, migration 정책이 Plugin 계약에 없다.

### Q140

- **질문:** 네트워크 코드가 거의 없는데 게임 프로그래머 포트폴리오로 충분한가요?
- **질문 의도:** 프로젝트 범위를 솔직하게 한정하고 다음 학습 계획을 제시하는지 본다.
- **좋은 답변:** single-player architecture와 수명·테스트 역량을 증명하되 multiplayer 역량은 별도 authoritative vertical slice로 보완한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Event bus가 비복제를 명시하고 Inventory·Door·Recon·Hide에 server RPC/replicated state가 없어 multiplayer 완성 프로젝트라고 주장할 수 없다.
- **추가 꼬리 질문:** 2주 안에 어떤 시스템 하나를 복제해 보겠나요?
- **부족한 부분:** latency, prediction, reconciliation, ownership 경험을 이 저장소만으로 증명하기 어렵다.

### Q141

- **질문:** WorldSubsystem이 몰래 Component를 붙이는 구조는 디버깅하기 나쁘지 않나요?
- **질문 의도:** zero-authoring 편의와 명시적 구성의 trade-off를 평가한다.
- **좋은 답변:** 편리하지만 opt-in, 로그, generated marker, duplicate/custom priority, authority 정책이 필요하다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Door/Recon Integration이 시작 시 `TActorIterator`로 전수 순회하고 spawn handler에서 adapter를 `NewObject`로 등록한다.
- **추가 꼬리 질문:** Blueprint Details에서 보이지 않던 Component가 런타임에 생긴 것을 어떻게 찾나요?
- **부족한 부분:** 공통 diagnostic UI와 자동 부착 provenance가 없다.

### Q142

- **질문:** `UJMDoorComponent`는 사실상 God Component 아닌가요?
- **질문 의도:** 큰 핵심 클래스에 대한 방어적 태도를 본다.
- **좋은 답변:** aggregate root 역할은 필요하지만 access·durability·obstruction·audio/save 정책은 분리 가능한 책임이라고 인정한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** movement 수학은 Component 계층으로 분리했지만 Door core가 명령, 상태, timer, damage, push, save, delegate/event를 소유한다.
- **추가 꼬리 질문:** 분리 후 누가 최종 상태 전이를 결정하나요?
- **부족한 부분:** SRP 개선과 aggregate 일관성을 함께 보존하는 리팩터링 설계가 아직 구현되지 않았다.

### Q143

- **질문:** HarpoonGun 하나가 너무 많은 일을 하지 않나요?
- **질문 의도:** 기능이 동작한다는 이유로 책임 집중을 무시하는지 본다.
- **좋은 답변:** gun state orchestration과 projectile, tether, grapple, target response를 policy/component로 나눌 seam을 제시한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `UJMHarpoonGunComponent`가 발사·박힘·회수·wire route·player grapple·target callback을 총괄하고 CableComponent에도 의존한다.
- **추가 꼬리 질문:** 가장 먼저 어떤 단위 테스트 seam을 만들겠나요?
- **부족한 부분:** 물리 상태 전이와 시각 wire 표현이 강하게 엮여 deterministic test가 어렵다.

### Q144

- **질문:** Hide 시스템은 간단한 옷장 들어가기에 비해 지나치게 복잡하지 않나요?
- **질문 의도:** 복잡성이 실제 failure mode를 해결하는지 설명하게 한다.
- **좋은 답변:** 비동기 mechanism·participant·collision exit·취소를 지원하려면 transaction이 필요하지만 콘텐츠 요구가 단순하면 profile을 줄여야 한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** reserve/commit, snapshot, enter/exit rollback, SessionId completion guard는 반쪽 상태를 막지만 많은 phase와 provider가 학습 비용을 만든다.
- **추가 꼬리 질문:** MVP라면 어떤 기능을 제거하겠나요?
- **부족한 부분:** 복잡성을 정당화할 실제 콘텐츠 종류·실패 통계가 문서에 없다.

### Q145

- **질문:** BehaviorTree와 StateTree를 둘 다 쓴 건 기술 선택을 못 한 것 아닌가요?
- **질문 의도:** 실험과 미완성 표준화를 구분해 설명하는지 본다.
- **좋은 답변:** Host legacy BT와 reusable framework StateTree의 범위를 인정하고 신규 표준·migration 계획을 명확히 말한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** Host `AJMDungeonMonster`는 BT node에 concrete 결합되고 Plugin `AJMEnemyBase`는 StateTree component를 사용한다.
- **추가 꼬리 질문:** 최종적으로 하나만 남긴다면 무엇을 선택하나요?
- **부족한 부분:** 둘의 비교 기준과 제거 일정이 ADR로 확정되지 않았다.

### Q146

- **질문:** Build.cs에 안 쓰는 dependency가 있는데 아키텍처를 깊게 설계했다고 할 수 있나요?
- **질문 의도:** 빌드 위생을 세부 품질로 받아들이는지 본다.
- **좋은 답변:** 감사에서 후보를 식별했고 실제 제거→전체 target build로 검증해야 하며 설계와 운영 품질은 별개로 개선한다고 답한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMDoorRuntime/InputCore`, JumpScare/Slate, Recon/AudioMixer 등이 직접 심볼 미검출 후보이고 `JMThrowable/AIModule`은 Public 범위 재검토 대상이다.
- **추가 꼬리 질문:** 지금 확실히 지워도 된다고 보장할 dependency는 무엇인가요?
- **부족한 부분:** 검색만으로 확정할 수 없고 제거 빌드 실험을 아직 수행하지 않았다.

### Q147

- **질문:** Plugin이 Host의 `/Game` Asset을 기본 참조하면 재사용 Plugin이 맞나요?
- **질문 의도:** 선언한 재사용성과 실제 콘텐츠 참조의 모순을 보는 질문이다.
- **좋은 답변:** 맞지 않으며 Plugin content path나 비어 있는 soft default로 바꾸고 설치 validation을 제공해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `JMJumpScareDefinition.h`의 기본 `PostProcessMaterial`이 `/Game/Jumpscare/M_Glitch`를 가리키는 P0 이식성 문제로 감사됐다.
- **추가 꼬리 질문:** Asset이 없을 때 런타임은 어떻게 실패해야 하나요?
- **부족한 부분:** 코드 수정 없이 문서로만 식별된 상태라 Plugin 단독 복사 보장이 아직 깨져 있다.

### Q148

- **질문:** 선언만 있고 실제 Runtime에서 쓰지 않는 API가 왜 있나요?
- **질문 의도:** dead API와 미래 계획을 구분하고 제거 결정을 내리는지 본다.
- **좋은 답변:** 소비자·dispatch·테스트 근거가 없으면 Draft 계획으로 표시하거나 deprecate 후 제거해야 한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** `IJMJumpScareActorInterface`는 테스트 Actor 구현은 확인되지만 Runtime dispatch 소비가 미검출돼 dead API 후보로 감사됐다.
- **추가 꼬리 질문:** Public API 제거 시 호환성은 어떻게 관리하나요?
- **부족한 부분:** Plugin versioning과 deprecation 기간 정책이 일관되게 문서화돼 있지 않다.

### Q149

- **질문:** 이 많은 코드를 정말 본인이 이해하고 작성했다는 것을 어떻게 증명하겠습니까?
- **질문 의도:** 문서 양이 아니라 실제 문제 해결 소유권과 디버깅 깊이를 확인한다.
- **좋은 답변:** 특정 버그의 재현, call flow, 실패 원인, 수정 trade-off, 대응 테스트를 코드에서 즉시 설명하고 commit history로 범위를 구분한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 예로 event self-unsubscribe는 snapshot+GUID 재조회+delegate local copy와 `SafeMutationDuringDispatch` 테스트까지 연결해 설명할 수 있다.
- **추가 꼬리 질문:** 그중 가장 어려웠던 버그를 지금 코드 줄 단위로 설명하세요.
- **부족한 부분:** 저장소 코드만으로 개인 기여 범위는 증명할 수 없으므로 본인 작성·수정·분석 영역을 정직하게 구분해야 한다.

### Q150

- **질문:** 이 포트폴리오에서 딱 하나만 고칠 시간이 있다면 무엇을 고르겠습니까?
- **질문 의도:** 영향도·위험·검증 가능성으로 우선순위를 정하는지 본다.
- **좋은 답변:** 가장 화려한 기능이 아니라 다수 시스템에 파급되는 실제 결함을 고르고 완료 조건과 테스트를 제시한다.
- **현재 프로젝트 코드를 기반으로 한 답변:** 공통 modal/input ownership stack을 도입해 Inventory·Dialogue·Inspector·Objective UI의 중첩 복원 문제를 해결하고 PIE 회귀 테스트를 추가하겠다.
- **추가 꼬리 질문:** 왜 Door 분해나 multiplayer보다 먼저인가요?
- **부족한 부분:** 우선순위는 제품 목표에 따라 달라지며 현재는 crash/성능 실측과 사용자 버그 데이터가 없어 문서 감사 기반 판단이다.

---

## 면접 연습 방법

1. “현재 프로젝트 코드를 기반으로 한 답변”의 클래스와 함수를 실제 IDE에서 연다.
2. 좋은 답변을 외우기보다 호출자→상태 변경→delegate/event→cleanup 순서로 직접 설명한다.
3. 부족한 부분을 숨기지 말고 영향, 우선순위, 수정안, 검증 방법까지 한 번에 말한다.
4. 압박 질문은 90초 안에 “인정할 사실→당시 선택→현재 한계→개선 계획” 순서로 답한다.
5. 본인이 직접 작성하지 않은 영역은 기여 범위를 명확히 밝히고 코드 분석으로 확인한 사실과 개인 경험을 섞지 않는다.
