---
title: "Plugin 문서 인덱스"
status: Current
authority: Canonical
scope: "Plugin Documentation"
last_verified: 2026-08-20
verified_against: "plugin-docs-layout-2026-08-20"
owners:
  - "Plugin Architecture"
related:
  - "../Docs/DOCUMENTATION_POLICY.md"
  - "../Docs/README.md"
---

# Plugin 문서 인덱스

이 문서는 `Plugins` 아래 문서의 중앙 탐색 지점이다. 실제 기능 구조의 최종 기준은 코드와 프로젝트 [Architecture Audit](../Docs/Architecture/Architecture_Audit_KO.md)이며, 이 인덱스의 `Current`는 문서 경로와 메타데이터 목록을 검증했다는 뜻이다.

## 상태 해석

- `ReviewRequired`: 분류와 링크는 정리했지만 문서 내용을 현재 코드·에셋·Editor 절차와 다시 검증해야 한다.
- `Draft`: 구현 여부가 확정되지 않은 계획 또는 TODO다.
- `Archived`: 현재 사용 지침이 아닌 과거 분석·Migration 기록이다.
- `Superseded`: 다른 Canonical 문서가 대체했다.

## Plugin 빠른 탐색

| Plugin | 버전 | 진입점 | 문서 수 | Guides | Reference | Testing | Plans | Archive |
|---|---:|---|---:|---:|---:|---:|---:|---:|
| InventorySystem | 0.7.0 | [문서](InventorySystem/Docs/README.md) | 17 | 11 | 0 | 1 | 2 | 0 |
| ItemInspector | 0.5.0 | [문서](ItemInspector/Docs/README.md) | 12 | 5 | 2 | 0 | 2 | 0 |
| JMDoor | 1.6.0 | [문서](JMDoor/README.md) | 11 | 5 | 1 | 2 | 0 | 0 |
| JMDoorGameplayIntegration | 1.1.0 | [문서](JMDoorGameplayIntegration/Docs/README_KO.md) | 4 | 1 | 0 | 0 | 0 | 0 |
| JMDoorReconIntegration | 1.0.0 | [문서](JMDoorReconIntegration/Docs/README.md) | 4 | 1 | 0 | 0 | 0 | 0 |
| JMFootstep | 1.1.1 | [문서](JMFootstep/Docs/README.md) | 3 | 0 | 0 | 0 | 0 | 0 |
| JMGameplayEvent | 1.1.0 | [문서](JMGameplayEvent/Docs/README_KO.md) | 4 | 1 | 0 | 0 | 0 | 0 |
| JMHide | 1.0.0 | [문서](JMHide/Docs/README_KO.md) | 5 | 1 | 1 | 0 | 0 | 0 |
| JMHideDoorIntegration | 1.0.0 | [문서](JMHideDoorIntegration/Docs/README_KO.md) | 1 | 0 | 0 | 0 | 0 | 0 |
| JMHideInteractionIntegration | 1.0.0 | [문서](JMHideInteractionIntegration/Docs/README_KO.md) | 1 | 0 | 0 | 0 | 0 | 0 |
| JMInteraction | 1.1.1 | [문서](JMInteraction/Docs/README_KO.md) | 5 | 1 | 0 | 0 | 0 | 1 |
| JMJumpScare | 2.0.0 | [문서](JMJumpScare/Docs/README_KO.md) | 6 | 2 | 0 | 0 | 0 | 0 |
| JMMonsterFramework | 1.1.0 | [문서](JMMonsterFramework/Docs/README.md) | 5 | 0 | 0 | 2 | 0 | 0 |
| JMObjective | 1.1.1 | [문서](JMObjective/Docs/README_KO.md) | 7 | 3 | 0 | 1 | 0 | 0 |
| JMPhysicalGrabber | 1.8.0 | [문서](JMPhysicalGrabber/Docs/README.md) | 5 | 2 | 0 | 0 | 0 | 0 |
| JMRecon | 1.1.0 | [문서](JMRecon/Docs/README.md) | 4 | 1 | 0 | 0 | 0 | 0 |
| JMReconGameplayIntegration | 1.1.0 | [문서](JMReconGameplayIntegration/Docs/README.md) | 4 | 1 | 0 | 0 | 0 | 0 |
| JMRoomGrid | 1.5.0 | [문서](JMRoomGrid/Docs/README_KO.md) | 3 | 0 | 0 | 0 | 0 | 0 |
| JMThrowable | 1.4.1 | [문서](JMThrowable/Docs/README.md) | 6 | 2 | 1 | 0 | 0 | 0 |
| JMThrowableGameplayIntegration | 1.0.0 | [문서](JMThrowableGameplayIntegration/Docs/README.md) | 2 | 0 | 0 | 0 | 0 | 0 |
| ReusableDialogueSystem | 0.2.1 | [문서](ReusableDialogueSystem/README.md) | 5 | 0 | 0 | 0 | 2 | 0 |

## Plugin별 문서 지도

### InventorySystem

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [인벤토리 시스템 아키텍처](InventorySystem/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [변경 기록](InventorySystem/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [재사용형 인벤토리 시스템](InventorySystem/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [아이템 데이터 제작](InventorySystem/Docs/Guides/DATA_AUTHORING.md) | `ReviewRequired` | `Guide` |
| Guides | [아이템 드랍과 획득 알림](InventorySystem/Docs/Guides/DROP_AND_NOTIFICATION.md) | `ReviewRequired` | `Guide` |
| Guides | [Duckov 스타일 Inventory UI 1차 구현: Unreal Editor 제작 가이드](InventorySystem/Docs/Guides/DUCKOV_STYLE_UI_IMPLEMENTATION_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Item Inspector 연동](InventorySystem/Docs/Guides/INSPECTOR_INTEGRATION.md) | `ReviewRequired` | `Guide` |
| Guides | [설치 방법](InventorySystem/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |
| Guides | [Loot Box 사용 설명서](InventorySystem/Docs/Guides/LOOT_CONTAINERS_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [JMInspectable 아이템 획득 연동](InventorySystem/Docs/Guides/PICKUP_INTEGRATION.md) | `ReviewRequired` | `Guide` |
| Guides | [문제 해결](InventorySystem/Docs/Guides/TROUBLESHOOTING.md) | `ReviewRequired` | `Guide` |
| Guides | [인벤토리 UI 및 Enhanced Input 제작 가이드](InventorySystem/Docs/Guides/UI_SETUP.md) | `ReviewRequired` | `Guide` |
| Guides | [Inventory UI/UX 0.5 적용 가이드](InventorySystem/Docs/Guides/UI_UX_UPGRADE_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Inventory Widget 배치 가이드](InventorySystem/Docs/Guides/WIDGET_LAYOUT_GUIDE_KO.md) | `ReviewRequired` | `Guide` |
| Plans | [인벤토리 시스템 구현 계획](InventorySystem/Docs/Plans/IMPLEMENTATION_PLAN.md) | `Draft` | `Plan` |
| Plans | [인벤토리 시스템 작업 목록](InventorySystem/Docs/Plans/TODO.md) | `Draft` | `Plan` |
| Testing | [인벤토리 플러그인 에디터 최종 세팅 및 회귀 테스트 가이드](InventorySystem/Docs/Testing/EDITOR_SETUP_AND_REGRESSION_TEST_KO.md) | `ReviewRequired` | `Guide` |

### ItemInspector

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [아키텍처](ItemInspector/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [변경 기록](ItemInspector/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [ItemInspector 초보자 사용 안내](ItemInspector/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [Blueprint 사용법](ItemInspector/Docs/Guides/BLUEPRINT_USAGE.md) | `ReviewRequired` | `Guide` |
| Guides | [데이터 작성법](ItemInspector/Docs/Guides/DATA_AUTHORING.md) | `ReviewRequired` | `Guide` |
| Guides | [다른 프로젝트에 이식하기](ItemInspector/Docs/Guides/PORTABLE_INSTALL.md) | `ReviewRequired` | `Guide` |
| Guides | [문제 해결](ItemInspector/Docs/Guides/TROUBLESHOOTING.md) | `ReviewRequired` | `Guide` |
| Guides | [Inspector Widget 제작 및 이식 가이드](ItemInspector/Docs/Guides/WIDGET_SETUP.md) | `ReviewRequired` | `Guide` |
| Plans | [구현 계획](ItemInspector/Docs/Plans/IMPLEMENTATION_PLAN.md) | `Draft` | `Plan` |
| Plans | [TODO](ItemInspector/Docs/Plans/TODO.md) | `Draft` | `Plan` |
| Reference | [상호작용 시스템](ItemInspector/Docs/Reference/INTERACTION_SYSTEM.md) | `ReviewRequired` | `Supporting` |
| Reference | [아이템 조사 시스템](ItemInspector/Docs/Reference/ITEM_INSPECTION_SYSTEM.md) | `ReviewRequired` | `Supporting` |

### JMDoor

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMDoor 아키텍처](JMDoor/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMDoor/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Guides | [확장 가이드](JMDoor/Docs/Guides/EXTENDING.md) | `ReviewRequired` | `Guide` |
| Guides | [설치와 제작 흐름](JMDoor/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |
| Guides | [휴대용 설치와 압축](JMDoor/Docs/Guides/PORTABLE_INSTALL.md) | `ReviewRequired` | `Guide` |
| Guides | [JM Door 처음 사용하기](JMDoor/Docs/Guides/QUICK_START_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [저장 시스템 연동](JMDoor/Docs/Guides/SAVE_INTEGRATION.md) | `ReviewRequired` | `Guide` |
| Plugin Root | [JM Door System](JMDoor/README.md) | `ReviewRequired` | `Guide` |
| Reference | [JMDoor API](JMDoor/Docs/Reference/API.md) | `ReviewRequired` | `Supporting` |
| Testing | [Unreal Editor 테스트 가이드](JMDoor/Docs/Testing/EDITOR_TEST_GUIDE_KO.md) | `ReviewRequired` | `Guide` |
| Testing | [테스트](JMDoor/Docs/Testing/TESTING.md) | `ReviewRequired` | `Guide` |

### JMDoorGameplayIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [Architecture](JMDoorGameplayIntegration/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMDoorGameplayIntegration/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JM Door Gameplay Integration](JMDoorGameplayIntegration/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Portable Install](JMDoorGameplayIntegration/Docs/Guides/PORTABLE_INSTALL.md) | `ReviewRequired` | `Guide` |

### JMDoorReconIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMDoorReconIntegration 아키텍처](JMDoorReconIntegration/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [변경 이력](JMDoorReconIntegration/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMDoorReconIntegration](JMDoorReconIntegration/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [설치 및 설정](JMDoorReconIntegration/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |

### JMFootstep

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMFootstep Architecture](JMFootstep/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMFootstep/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMFootstep](JMFootstep/Docs/README.md) | `ReviewRequired` | `Guide` |

### JMGameplayEvent

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMGameplayEvent 아키텍처](JMGameplayEvent/Docs/ARCHITECTURE_KO.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMGameplayEvent/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMGameplayEvent](JMGameplayEvent/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [JMGameplayEvent Migration](JMGameplayEvent/Docs/Guides/MIGRATION_KO.md) | `ReviewRequired` | `Guide` |

### JMHide

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMHide 아키텍처](JMHide/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMHide/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMHide](JMHide/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [JMHide 설치](JMHide/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |
| Reference | [Cancel / ForceExit 정책](JMHide/Docs/Reference/CANCEL_POLICY.md) | `ReviewRequired` | `Supporting` |

### JMHideDoorIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMHideDoorIntegration](JMHideDoorIntegration/Docs/README_KO.md) | `ReviewRequired` | `Guide` |

### JMHideInteractionIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMHideInteractionIntegration](JMHideInteractionIntegration/Docs/README_KO.md) | `ReviewRequired` | `Guide` |

### JMInteraction

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Archive | [기존 프로젝트 분석 및 Migration 기록](JMInteraction/Docs/Archive/PROJECT_ANALYSIS.md) | `Archived` | `Historical` |
| Docs Root | [Architecture](JMInteraction/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMInteraction/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMInteraction 사용 가이드](JMInteraction/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Custom Interaction Prompt Widget 만들기](JMInteraction/Docs/Guides/CUSTOM_PROMPT_WIDGET_KO.md) | `ReviewRequired` | `Guide` |

### JMJumpScare

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Colocated | [Gameplay Tags](JMJumpScare/Config/Tags/README.md) | `ReviewRequired` | `Supporting` |
| Docs Root | [JMJumpScare 아키텍처](JMJumpScare/Docs/ARCHITECTURE_KO.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMJumpScare/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMJumpScare](JMJumpScare/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [통합 가이드](JMJumpScare/Docs/Guides/INTEGRATION_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [2D JumpScare 빠른 시작](JMJumpScare/Docs/Guides/QUICK_START_KO.md) | `ReviewRequired` | `Guide` |

### JMMonsterFramework

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMMonsterFramework](JMMonsterFramework/Docs/README.md) | `Current` | `Guide` |
| Docs Root | [아키텍처](JMMonsterFramework/Docs/ARCHITECTURE.md) | `Current` | `Canonical` |
| Docs Root | [변경 기록](JMMonsterFramework/Docs/CHANGELOG.md) | `Current` | `Historical` |
| Testing | [Phase 0 Smoke Test](JMMonsterFramework/Docs/Testing/PHASE0_SMOKE_TEST_KO.md) | `Current` | `Guide` |
| Testing | [Phase 1 Sight Test](JMMonsterFramework/Docs/Testing/PHASE1_SIGHT_TEST_KO.md) | `Current` | `Guide` |

### JMObjective

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMObjective 아키텍처](JMObjective/Docs/ARCHITECTURE_KO.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMObjective/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMObjective](JMObjective/Docs/README_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Objective Definition 만들기](JMObjective/Docs/Guides/EDITOR_OBJECTIVE_SETUP_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Objective Flow 처음 설정하기](JMObjective/Docs/Guides/FLOW_SETUP_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [Save 연동](JMObjective/Docs/Guides/SAVE_INTEGRATION_KO.md) | `ReviewRequired` | `Guide` |
| Testing | [열쇠 → 문 → Dialogue 통합](JMObjective/Docs/Testing/INTEGRATION_TEST_KO.md) | `ReviewRequired` | `Guide` |

### JMPhysicalGrabber

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JM Physical Grabber Architecture](JMPhysicalGrabber/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMPhysicalGrabber/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JM Physical Grabber and Harpoon Gun](JMPhysicalGrabber/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [JM 작살총 사용 및 수정 문서](JMPhysicalGrabber/Docs/Guides/HARPOON_GUN_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [JM 작살 작업 도구 상호작용 사용법](JMPhysicalGrabber/Docs/Guides/WORK_TOOL_INTERACTIONS_KO.md) | `ReviewRequired` | `Guide` |

### JMRecon

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMRecon 아키텍처](JMRecon/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [변경 이력](JMRecon/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMRecon](JMRecon/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [설치 및 이식성](JMRecon/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |

### JMReconGameplayIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMReconGameplayIntegration 아키텍처](JMReconGameplayIntegration/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [변경 이력](JMReconGameplayIntegration/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMReconGameplayIntegration](JMReconGameplayIntegration/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [설치 및 설정](JMReconGameplayIntegration/Docs/Guides/INSTALLATION.md) | `ReviewRequired` | `Guide` |

### JMRoomGrid

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JM Room Grid architecture](JMRoomGrid/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMRoomGrid/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JM Room Grid 1.5.0](JMRoomGrid/Docs/README_KO.md) | `ReviewRequired` | `Guide` |

### JMThrowable

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [JMThrowable Architecture](JMThrowable/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](JMThrowable/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMThrowable](JMThrowable/Docs/README.md) | `ReviewRequired` | `Guide` |
| Guides | [JMThrowable Niagara 궤적 전환 가이드](JMThrowable/Docs/Guides/NIAGARA_PREVIEW_GUIDE_KO.md) | `ReviewRequired` | `Guide` |
| Guides | [에디터 설정](JMThrowable/Docs/Guides/SETUP_KO.md) | `ReviewRequired` | `Guide` |
| Reference | [JMThrowable Niagara 런타임 구현](JMThrowable/Docs/Reference/NIAGARA_RUNTIME_IMPLEMENTATION_KO.md) | `ReviewRequired` | `Supporting` |

### JMThrowableGameplayIntegration

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [Changelog](JMThrowableGameplayIntegration/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Docs Root | [JMThrowableGameplayIntegration](JMThrowableGameplayIntegration/Docs/README.md) | `ReviewRequired` | `Guide` |

### ReusableDialogueSystem

| 분류 | 문서 | 상태 | 권위 |
|---|---|---|---|
| Docs Root | [아키텍처](ReusableDialogueSystem/Docs/ARCHITECTURE.md) | `ReviewRequired` | `Canonical` |
| Docs Root | [Changelog](ReusableDialogueSystem/Docs/CHANGELOG.md) | `ReviewRequired` | `Historical` |
| Plans | [구현 계획](ReusableDialogueSystem/Docs/Plans/IMPLEMENTATION_PLAN.md) | `Draft` | `Plan` |
| Plans | [후속 구현 목록](ReusableDialogueSystem/Docs/Plans/TODO.md) | `Draft` | `Plan` |
| Plugin Root | [재사용형 대화 시스템](ReusableDialogueSystem/README.md) | `ReviewRequired` | `Guide` |

## 생태계 공통 문서

| 문서 | 상태 | 역할 |
|---|---|---|
| [AGENTS.md](AGENTS.md) | 실행 규칙 | `Plugins` 전체에 적용되는 Codex·개발 지침이며 YAML 검사 예외 |
| [JM_PLUGIN_DEVELOPMENT_GUIDE_KO.md](JM_PLUGIN_DEVELOPMENT_GUIDE_KO.md) | `ReviewRequired` | Interaction 기반 개발 가이드 |
| [PORTABLE_BUNDLE.md](PORTABLE_BUNDLE.md) | `ReviewRequired` | 휴대용 번들 구성 가이드 |
| [JM_FUTURE_SYSTEM_DESIGN_CONTEXT_KO.md](JM_FUTURE_SYSTEM_DESIGN_CONTEXT_KO.md) | `ReviewRequired` | 미래 시스템 설계 컨텍스트, 레지스트리 재검토 필요 |
| [JM_PLUGINS_STRUCTURE.md](JM_PLUGINS_STRUCTURE.md) | `Superseded` | 과거 구조 설명, 현재 기준은 프로젝트 dependency graph |

## 분류 규칙

```text
<Plugin>/
├─ README.md                    # 선택: 저장소·Marketplace 진입점
└─ Docs/
   ├─ README.md 또는 README_KO.md
   ├─ ARCHITECTURE.md 또는 ARCHITECTURE_KO.md
   ├─ CHANGELOG.md
   ├─ Guides/
   ├─ Reference/
   ├─ Testing/
   ├─ Plans/
   ├─ Decisions/
   └─ Archive/
```

빈 분류 폴더는 만들지 않는다. 자세한 상태 전환과 갱신 규칙은 [문서 관리 정책](../Docs/DOCUMENTATION_POLICY.md)을 따른다.
