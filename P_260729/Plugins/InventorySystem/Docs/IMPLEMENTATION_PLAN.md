# 인벤토리 시스템 구현 계획

## 프로젝트 분석 결과

- Unreal Engine: 5.7 (`EngineAssociation`과 Target Include Order 기준)
- 프로젝트 형식: C++ Runtime 프로젝트와 Blueprint 기반 First Person 콘텐츠
- 입력: 프로젝트 모듈에서 Enhanced Input 사용 중
- 기존 재사용 시스템: `ItemInspector` Runtime Module에 상호작용 및 아이템 조사 기능 존재
- 기존 조사 API: `UJMItemInspectionSubsystem::OpenInspection(UJMItemInspectionData*)`
- 확인한 Old Key 에셋:
  - `/InventorySystem/Example/Icons/oldKey`
  - `/ItemInspector/Item/SM_OldKey`
  - `/ItemInspector/Item/DA_OldKey_Inspection`

## 첫 번째 마일스톤

다음 기능을 포함하며 컴파일 가능한 Runtime Plugin을 구현한다.

1. 아이템 정의와 인스턴스형 사용 효과
2. 이벤트 기반 스택형 인벤토리 저장소
3. 월드 아이템 획득과 안전한 버리기
4. UMG 기반 위젯과 입력·UI 조정 컴포넌트
5. ItemInspector에 강하게 의존하지 않는 Inspector Bridge
6. ItemId와 InstanceId 기반 저장용 데이터
7. Developer Settings, 로그, 문서, 최소 자동화 테스트

## 생성 대상 파일

- `InventorySystem.uplugin`
- `Source/InventorySystem/InventorySystem.Build.cs`
- Runtime Module 및 로그 파일
- `Public/InventoryTypes.h`
- `Public/Items/InventoryItemDefinition.h`
- `Public/Items/InventoryItemUseEffect.h`
- `Public/Components/InventoryComponent.h`
- `Public/Components/InventoryUIComponent.h`
- `Public/Interfaces/InventoryProviderInterface.h`
- `Public/Interfaces/InventoryItemInspectorBridge.h`
- `Public/UI/InventoryWidgetBase.h`
- `Public/World/InventoryWorldItemPickup.h`
- `Public/Settings/InventorySystemSettings.h`
- 대응하는 `Private` 구현 파일
- `Docs` 아래 사용법 및 연동 문서

## 의존성 방향

`UI → InventoryComponent → ItemDefinition → UseEffect`

`WorldPickup → InventoryComponent`

`UI → InspectorBridge Interface` 방향만 허용하며 `UI → ItemInspectorRuntime` 직접 의존은 금지한다.

호스트 프로젝트에서 Blueprint 또는 C++ Bridge를 구현하여 ItemInspector를 호출한다. 이를 통해 인벤토리 플러그인의 이식성을 유지하고 기존 Inspector 구현이 인벤토리 핵심 코드로 퍼지는 것을 방지한다.

## 검증 순서

1. UnrealBuildTool이 신규 Plugin Module을 인식하도록 프로젝트 파일 상태를 갱신한다.
2. UE 5.7에서 `BaseUpgradeEditor Win64 Development`를 빌드한다.
3. UnrealHeaderTool 오류를 먼저 해결한 뒤 컴파일·링크 오류를 수정한다.
4. 경고와 Blueprint 노출 상태를 확인한다.
5. 설치법과 알려진 제한사항 문서를 갱신한다.

## 위험 요소

- 텍스트 기반 작업만으로 `.uasset` Widget Blueprint나 Data Asset을 안전하게 작성할 수 없으므로 Old Key 정의, Input Action, Mapping Context, Widget Blueprint와 프로젝트 전용 Inspector Bridge 설정은 에디터에서 수행해야 한다.
- 임의 프로젝트가 사용하던 모든 Input Mode를 Runtime에서 완전히 조회할 수는 없다. UI 조정 컴포넌트는 커서 및 이동·시점 입력 차단 상태를 보존하고 프로젝트별 복원을 위한 Blueprint 이벤트 지점을 제공한다.
- 멀티플레이 권한 및 RPC 정책은 호스트 프로젝트가 결정할 확장 지점으로 남긴다.
