---
title: "JM Plugins 구조"
status: Superseded
authority: Historical
scope: "Plugin Ecosystem"
classified_on: 2026-08-19
owners:
  - "Plugin Architecture"
superseded_by: "../Docs/Architecture/PLUGIN_DEPENDENCY_GRAPH.md"
---

# JM Plugins 구조

## 목적과 적용 원칙

이 문서는 프로젝트의 재사용 가능 시스템을 논리적으로 `JM Plugins` 아래에서 관리하기 위한 기준이다. 이번 정리에서는 기능, Blueprint API, C++ 심볼, Config 섹션 및 콘텐츠 마운트 경로를 보존하는 것을 최우선으로 했다.

Unreal 플
러그인을 `Plugins/JMPlugins/<Plugin>`처럼 중첩하거나 기존 플러그인·모듈 이름을 즉시 `JM*`로 바꾸면 플러그인 탐색, `/PluginName/...` 콘텐츠 경로, `/Script/Module.Class` 경로와 기존 Blueprint 참조가 함께 영향을 받을 수 있다. 따라서 물리 폴더는 엔진이 안정적으로 탐색하는 현재의 최상위 형식을 유지하고, Project Settings 및 Plugin Browser의 표시 카테고리를 `JM Plugins`로 통합한다.

## 전체 플러그인 목록과 역할

| 플러그인 폴더 | Runtime 모듈 | Editor 모듈 | 역할 |
|---|---|---|---|
| `InventorySystem` | `InventorySystem` | 없음 | 데이터 기반 인벤토리, Pickup, UI 및 Inspector 연동 |
| `ReusableDialogueSystem` | `ReusableDialogueSystem` | 없음 | 재사용 가능한 대화 재생, UI 및 상호작용 진입점 |
| `ItemInspector` | `ItemInspectorRuntime` | `ItemInspectorTests` | 아이템 미리보기/검사 런타임과 Editor 자동화 테스트 |
| `JMInteraction` | `JMInteraction` | `JMInteractionTests` | 탐지, 포커스, Prompt UI 및 상호작용 실행 기반 |
| `JMDoor` | `JMDoorRuntime` | `JMDoorTests` | 문 상태, 이동, 접근, 내구도, 방해 처리 및 저장 계약 |
| `JMDoorGameplayIntegration` | `JMDoorGameplayIntegration` | 없음 | Door, Interaction, Inventory를 결합하는 선택적 게임 연동 계층 |

`P_060715` 게임 모듈은 위 플러그인 모듈을 의존하지 않는다. Inventory와 Dialogue도 이미 프로젝트 `Source`가 아닌 독립 Runtime 플러그인에 있으므로 추가 소스 분리는 필요하지 않다.

## Project Settings 구조

모든 설정 클래스는 `UDeveloperSettings` 자동 등록을 사용한다. `ISettingsModule`, `RegisterSettings`, `UnregisterSettings`를 별도로 사용하지 않으므로 수동 등록 중복이나 Runtime의 `Settings`/`UnrealEd` 의존성은 없다.

```text
Project Settings
└─ JM Plugins
   ├─ Inventory
   ├─ Dialogue
   ├─ Item Inspector
   ├─ Interaction
   └─ Door
```

| 표시 섹션 | 설정 클래스 | Config 범위 | 저장 섹션 |
|---|---|---|---|
| Inventory | `UInventorySystemSettings` | `Config=Game`, `DefaultConfig` | `/Script/InventorySystem.InventorySystemSettings` |
| Dialogue | `UDialogueSettings` | `Config=Game`, `DefaultConfig` | `/Script/ReusableDialogueSystem.DialogueSettings` |
| Item Inspector | `UItemInspectorSettings` | `Config=Game`, `DefaultConfig` | `/Script/ItemInspectorRuntime.ItemInspectorSettings` |
| Interaction | `UJMInteractionSettings` | `Config=Game`, `DefaultConfig` | `/Script/JMInteraction.JMInteractionSettings` |
| Door | `UJMDoorSettings` | `Config=JMDoor`, `DefaultConfig` | `/Script/JMDoorRuntime.JMDoorSettings` |

카테고리와 표시 섹션만 바뀌었고 클래스명, 모듈명, `Config` 지정 및 저장 섹션은 바뀌지 않았다. 따라서 기존 `DefaultGame.ini` 값과 `Plugins/JMDoor/Config/DefaultJMDoor.ini` 값은 그대로 로드된다.

새 설정 페이지도 다음 패턴을 따른다.

```cpp
UCLASS(Config=Game, DefaultConfig,
    meta=(DisplayName="New System", ToolTip="Configure the reusable JM system."))
class JMNEWSYSTEM_API UJMNewSystemSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    virtual FName GetCategoryName() const override { return TEXT("JM Plugins"); }
    virtual FName GetSectionName() const override { return TEXT("New System"); }
};
```

설정 프로퍼티에는 의미 있는 `Category`, `DisplayName`, `ToolTip`을 사용하고 숫자 범위에는 `ClampMin`/`ClampMax`, 조건부 값에는 `EditCondition`을 지정한다. Blueprint 런타임 접근이 필요하면 설정 UObject 자체를 임의로 노출하기보다 안정적인 Blueprint 함수 또는 Subsystem API를 제공한다.

## 의존 관계

```text
JMInteraction
├─ ItemInspector
│  └─ InventorySystem
├─ ReusableDialogueSystem
└─ JMDoorGameplayIntegration
   ├─ JMDoor
   └─ InventorySystem

JMDoor (독립 Runtime 플러그인)
```

정확한 현재 관계는 다음과 같다.

- `JMInteraction`은 다른 JM 플러그인에 의존하지 않는 하위 기반이다.
- `ItemInspector`는 `JMInteraction`을 명시적으로 의존한다.
- `InventorySystem`은 현재 Inspector bridge와 Interaction 구현을 포함하므로 `ItemInspector`와 `JMInteraction`을 명시적으로 의존한다. 이 결합을 선택 사항으로 만들려면 bridge 코드를 별도 연동 플러그인으로 이동하는 API 설계가 먼저 필요하다.
- `ReusableDialogueSystem`은 대화용 interactable component 때문에 `JMInteraction`을 명시적으로 의존한다.
- `JMDoorRuntime`은 `JMInteraction`과 `InventorySystem`에 의존하지 않는다.
- `JMDoorGameplayIntegration`만 `JMDoor`, `JMInteraction`, `InventorySystem`을 결합한다. 순환 의존성은 없다.

각 `.uplugin`의 플러그인 의존성과 각 `.Build.cs`의 모듈 의존성은 위 관계를 명시한다. Editor 테스트 모듈에만 `UnrealEd`, `Kismet`, `AssetRegistry`, `PropertyEditor` 같은 Editor 전용 모듈이 있으며 Runtime 모듈에는 없다.

## 실제 물리 구조

```text
Plugins/
├─ InventorySystem/
│  ├─ InventorySystem.uplugin
│  ├─ Config/
│  ├─ Content/
│  └─ Source/InventorySystem/{Public,Private}
├─ ReusableDialogueSystem/
│  ├─ ReusableDialogueSystem.uplugin
│  ├─ Config/
│  ├─ Content/
│  └─ Source/ReusableDialogueSystem/{Public,Private}
├─ ItemInspector/
│  ├─ ItemInspector.uplugin
│  ├─ Config/
│  ├─ Content/
│  └─ Source/{ItemInspectorRuntime,ItemInspectorTests}
├─ JMInteraction/
│  ├─ JMInteraction.uplugin
│  ├─ Config/
│  ├─ Content/
│  └─ Source/{JMInteraction,JMInteractionTests}
├─ JMDoor/
│  ├─ JMDoor.uplugin
│  ├─ Config/
│  ├─ Content/
│  └─ Source/{JMDoorRuntime,JMDoorTests}
└─ JMDoorGameplayIntegration/
   ├─ JMDoorGameplayIntegration.uplugin
   ├─ Content/
   └─ Source/JMDoorGameplayIntegration/{Public,Private}
```

이 구조는 물리적으로는 병렬이지만 Project Settings와 Plugin Browser에서는 `JM Plugins`라는 하나의 제품군으로 표시된다.

## 다른 프로젝트로 옮기는 방법

1. 필요한 플러그인 폴더 전체를 대상 프로젝트의 `Plugins` 바로 아래에 복사한다. `Binaries`, `Intermediate`는 복사하지 않아도 된다.
2. 위 의존 관계에 따라 하위 플러그인도 함께 복사한다. 예를 들어 Item Inspector는 JMInteraction이 필요하고, Inventory는 현재 ItemInspector와 JMInteraction이 모두 필요하다.
3. Door 자체만 필요하면 JMDoor만 복사한다. 인벤토리/상호작용 연동도 필요할 때만 JMDoorGameplayIntegration과 그 의존 플러그인을 추가한다.
4. 대상 엔진 버전에서 프로젝트 파일을 다시 생성하고 Development Editor를 빌드한다.
5. 대상 프로젝트의 Project Settings에서 `JM Plugins` 값을 확인하고 필요한 프로젝트별 Soft Object/Class 경로를 지정한다.
6. 로그에서 Missing Module, Failed to load class, Asset path, Config import 오류를 확인한다.

## 이름 규칙

- 새 플러그인과 주 Runtime 모듈: `JMFeature` (예: `JMInteraction`)
- Runtime/Editor 분리: `JMFeature`, `JMFeatureEditor` 또는 테스트 전용 `JMFeatureTests`
- 설정 클래스: `UJMFeatureSettings`
- Project Settings 카테고리: 항상 `JM Plugins`
- Project Settings 섹션: 접두사 없이 사용자가 읽기 쉬운 기능명(예: `Interaction`)
- 콘텐츠 마운트 경로와 `/Script/...` 경로는 공개 API로 간주한다. 출시 후 이름을 바꿀 때는 Core Redirect와 에셋 리세이브 계획을 함께 둔다.

기존 `InventorySystem`, `ReusableDialogueSystem`, `ItemInspectorRuntime`, `JMDoorRuntime` 이름은 호환성을 위해 유지한다. 표시 이름 통일을 이유로 기존 C++ 클래스나 모듈명을 바꾸지 않는다.

## 이번 변경 사항

- 5개 설정 페이지의 카테고리를 `JM Plugins`로 통합했다.
- 표시 섹션을 `Inventory`, `Dialogue`, `Item Inspector`, `Interaction`, `Door`로 정리했다.
- 각 설정 페이지에 짧은 Tool Tip을 추가했다.
- 관련 `.uplugin`의 Plugin Browser 카테고리를 `JM Plugins`로 통일했다.
- 설정 클래스명, Config 이름, Config 섹션, Blueprint API, 모듈명, 플러그인 폴더명은 유지했다.
- 게임 모듈 의존성은 추가하지 않았다.

## Config 및 에셋 마이그레이션 주의사항

- `DefaultGame.ini`의 기존 `/Script/InventorySystem.InventorySystemSettings` 및 `/Script/JMInteraction.JMInteractionSettings` 값은 그대로 유효하다.
- Door는 계속 `Config=JMDoor`와 `Plugins/JMDoor/Config/DefaultJMDoor.ini`를 사용한다.
- 설정 클래스와 Config 섹션명이 바뀌지 않았으므로 이번 변경에는 Config migration이나 추가 Core Redirect가 필요 없다.
- 콘텐츠 폴더와 마운트 경로를 이동하지 않았으므로 `.uasset` 파일 이동, Redirector 생성 또는 Fix Up Redirectors가 필요 없다.
- 기존 Core Redirect(`InventorySystem`, `ItemInspector`, `JMInteraction`, `ReusableDialogueSystem`)는 이전 구조에서 만들어진 참조를 위해 계속 유지한다.
- 향후 플러그인/모듈/클래스명을 바꿀 경우 먼저 Package/Class/Struct/Enum Redirect를 추가하고 Unreal Editor의 Asset Tools로 에셋을 이동한 뒤 모든 참조를 리세이브해야 한다. 파일 탐색기로 `.uasset`을 이동하지 않는다.

## 검증 체크리스트

- Development Editor 및 전체 Rebuild 성공
- Project Settings에 `JM Plugins` 카테고리 하나와 5개 섹션 표시
- 설정 변경 후 Editor 재시작 시 값 유지
- Runtime 모듈에 `UnrealEd`, `Settings`, `AssetTools` 의존성 없음
- Blueprint compile 및 기존 맵 로드 성공
- Door/Interaction, Inspector/Inventory 연동 회귀 테스트 성공
- 패키징 빌드 성공
- 로그에 Missing Module, Failed to load class, Asset path, Config import 오류 없음

## 2026-07-21 검증 결과

- UE 5.7 `P_060715Editor Win64 Development` Clean 후 전체 Rebuild 성공
- `P_060715 Win64 Shipping` Runtime 빌드 성공
- Shipping BuildCookRun(Cook, Stage, Pak, Archive) 성공: `C:/tmp/P_060715_JMPlugins_20260721/Windows`
- 시작 맵 `Level_test` 로드 및 Map Check 성공: 0 errors, 0 warnings
- JM/Inventory/Dialogue 자동화 테스트 15개 중 14개 성공
- 기존 `JM.Door.Movement.Transforms` 테스트 1개는 `Sliding applies fraction and direction` 기대값 불일치로 실패했다. 설정 카테고리 변경과 무관한 기존 Door 이동 수학 회귀 항목이며 별도 수정이 필요하다.
- 설정 UI의 실제 클릭/편집/재시작 확인은 Headless 검증 범위 밖이므로 일반 Editor에서 최종 수동 확인한다.
