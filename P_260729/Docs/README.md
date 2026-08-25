---
title: P_260729 문서 안내
status: Current
authority: Canonical
scope: Documentation
last_verified: 2026-08-20
verified_against: working-tree-docs-and-runtime-audit-2026-08-20
owners:
  - Project Documentation
related:
  - DOCUMENTATION_POLICY.md
  - Study/README.md
  - Testing/README.md
---

# P_260729 문서 안내

이 파일은 프로젝트 문서의 유일한 시작점이다. 문서를 새로 추가하거나 이동하면 이 인덱스와 해당 분류의 `README.md`를 같은 변경에서 갱신한다.

## 먼저 읽을 문서

### Unreal Engine C++를 이 프로젝트 코드로 공부하려는 개발자

1. [실전 Unreal Engine C++ 교재 목차](Study/README.md)
2. [Plugin과 Module 경계](Study/01_PLUGIN_MODULE_BOUNDARIES.md)
3. [GameplayTag 기반 Event Bus](Study/08_GAMEPLAY_TAG_EVENT_BUS.md)
4. [Integration Plugin과 Bridge](Study/15_INTEGRATION_PLUGIN_BRIDGES.md)
5. [Automation·Functional·PIE 테스트](Study/20_AUTOMATION_FUNCTIONAL_PIE_TESTS.md)

교재는 총 20개 챕터이며, 각 챕터가 실제 파일·클래스·함수를 근거로 같은 10단계 분석 형식을 사용한다. 처음 읽는 경우 목차의 순서를 따른다.

### 프로젝트 구조를 이해하려는 개발자

1. [전체 아키텍처 감사](Architecture/Architecture_Audit_KO.md)
2. [Plugin/Module 의존성 그래프](Architecture/PLUGIN_DEPENDENCY_GRAPH.md)
3. [Gameplay Event와 Delegate 흐름](Architecture/GAMEPLAY_EVENT_FLOW.md)
4. [아키텍처 개선 계획](Architecture/ARCHITECTURE_IMPROVEMENT_PLAN.md)

### 현재 프로토타입을 실행하거나 수정하려는 개발자

1. [런타임 안전성 정적 감사](Testing/RUNTIME_SAFETY_AUDIT_KO.md)
2. [프로토타입 시스템](Systems/Prototype/PROTOTYPE_SYSTEMS_KO.md)
3. [포탈 전환 연출](Systems/Prototype/PROTOTYPE_PORTAL_TRANSITION_KO.md)
4. [프로토타입 플레이테스트](Testing/PROTOTYPE_PLAYTEST_KO.md)

런타임 안전성 감사는 현재 working tree를 기준으로 한 정적 분석이다. 나머지 세 문서는 `ReviewRequired`이며 코드·맵·입력과 다시 검증하기 전에는 구현의 최종 기준으로 사용하지 않는다.

### 첫 번째 던전을 설계·제작하려는 사용자

1. [공포 던전 콘텐츠 설계](Design/FIRST_DUNGEON_HORROR_DESIGN_KO.md)
2. [제작 백로그](Production/FIRST_DUNGEON_HORROR_PRODUCTION_BACKLOG_KO.md)
3. [던전 콘텐츠 저작 가이드](Systems/Dungeon/DUNGEON_CONTENT_AUTHORING_KO.md)
4. [AI 몬스터 프로토타입](Systems/AI/AI_MONSTER_PROTOTYPE_KO.md)

설계와 백로그는 `Draft`, 저작/AI 문서는 `ReviewRequired`다.

## 문서 상태 현황

| 문서 | 분류 | 상태 | 권위 | 마지막 확인 | 용도 |
|---|---|---|---|---|---|
| [Architecture Audit](Architecture/Architecture_Audit_KO.md) | Architecture | `Current` | `Canonical` | 2026-08-19 | 전체 구조의 현재 기준 |
| [Plugin Dependency Graph](Architecture/PLUGIN_DEPENDENCY_GRAPH.md) | Architecture | `Current` | `Canonical` | 2026-08-19 | Plugin/Module 의존성 기준 |
| [Gameplay Event Flow](Architecture/GAMEPLAY_EVENT_FLOW.md) | Architecture | `Current` | `Canonical` | 2026-08-19 | 이벤트·Delegate·Tag 기준 |
| [Architecture Improvement Plan](Architecture/ARCHITECTURE_IMPROVEMENT_PLAN.md) | Architecture | `Current` | `Plan` | 2026-08-19 | 미래 개선 순서, 현재 구현 아님 |
| [UE C++ Study](Study/README.md) | Study | `Current` | `Guide` | 2026-08-20 | 실제 코드 기반 20개 학습 챕터 |
| [Runtime Safety Audit](Testing/RUNTIME_SAFETY_AUDIT_KO.md) | Testing | `Current` | `Supporting` | 2026-08-20 | 전체 C++ 런타임 안전성 정적 감사 |
| [Prototype Systems](Systems/Prototype/PROTOTYPE_SYSTEMS_KO.md) | Systems | `ReviewRequired` | `Supporting` | 미검증 | 프로토타입 구성 설명 |
| [Portal Transition](Systems/Prototype/PROTOTYPE_PORTAL_TRANSITION_KO.md) | Systems | `ReviewRequired` | `Guide` | 미검증 | 포탈 연출·설정 |
| [Dungeon Authoring](Systems/Dungeon/DUNGEON_CONTENT_AUTHORING_KO.md) | Systems | `ReviewRequired` | `Guide` | 미검증 | 방 내부 아이템·AI 배치 |
| [AI Monster Prototype](Systems/AI/AI_MONSTER_PROTOTYPE_KO.md) | Systems | `ReviewRequired` | `Supporting` | 미검증 | Host BehaviorTree AI 설명 |
| [Prototype Playtest](Testing/PROTOTYPE_PLAYTEST_KO.md) | Testing | `ReviewRequired` | `Guide` | 미검증 | 수동 플레이테스트 절차 |
| [First Dungeon Design](Design/FIRST_DUNGEON_HORROR_DESIGN_KO.md) | Design | `Draft` | `Plan` | 2026-08-19 | 게임 디자인 초안 |
| [First Dungeon Backlog](Production/FIRST_DUNGEON_HORROR_PRODUCTION_BACKLOG_KO.md) | Production | `Draft` | `Plan` | 2026-08-19 | 제작 계획 초안 |

`Current`는 단순히 최근에 편집됐다는 뜻이 아니라 실제 코드/설정과 검증됐다는 뜻이다. 정확한 판정과 갱신 규칙은 [문서 관리 정책](DOCUMENTATION_POLICY.md)을 따른다.

## 디렉터리 역할

```text
Docs/
├─ README.md                 # 유일한 시작점과 전체 상태표
├─ DOCUMENTATION_POLICY.md   # 상태·권위·최신화 규칙
├─ Architecture/             # 현재 구조, 의존성, 이벤트, 개선 계획
├─ Study/                    # 실제 프로젝트 코드 기반 UE C++ 교재
├─ Design/                   # 플레이 경험과 콘텐츠 설계
├─ Systems/                  # 실제 시스템별 설명과 저작 가이드
├─ Testing/                  # 플레이테스트와 검증 절차
├─ Production/               # 백로그, 일정, 제작 범위
├─ Decisions/                # 변경하지 말아야 할 설계 결정(ADR)
├─ Archive/                  # 대체되거나 종료된 역사 문서
└─ Tools/                    # 문서 구조 검증 도구
```

## Plugin 문서

Plugin 문서는 단독 복사·배포 가능성을 보존하기 위해 각 `Plugins/<Plugin>/Docs` 안에 유지한다. 2026-08-20 기준으로 보조 문서를 `Guides`, `Reference`, `Testing`, `Plans`, `Archive`로 분류하고 메타데이터를 적용했다. 다만 내용 자체를 코드·에셋·Editor 절차와 전부 재검증한 것은 아니므로 대부분 `ReviewRequired`다. 전체 목록은 [Plugin 문서 인덱스](../Plugins/DOCUMENTATION_INDEX.md)에서 확인한다.

| Plugin | 버전 | 문서 진입점 | 현재 문서 판정 |
|---|---:|---|---|
| InventorySystem | 0.7.0 | [README](../Plugins/InventorySystem/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| ItemInspector | 0.5.0 | [README](../Plugins/ItemInspector/Docs/README.md) | 분류 완료, 의존성 문구 재검토 필요 |
| JMDoor | 1.6.0 | [README](../Plugins/JMDoor/README.md) | 분류 완료, 의존성 문구 재검토 필요 |
| JMDoorGameplayIntegration | 1.1.0 | [README](../Plugins/JMDoorGameplayIntegration/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMDoorReconIntegration | 1.0.0 | [README](../Plugins/JMDoorReconIntegration/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMFootstep | 1.1.1 | [README](../Plugins/JMFootstep/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMGameplayEvent | 1.1.0 | [README](../Plugins/JMGameplayEvent/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMHide | 1.0.0 | [README](../Plugins/JMHide/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMHideDoorIntegration | 1.0.0 | [README](../Plugins/JMHideDoorIntegration/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMHideInteractionIntegration | 1.0.0 | [README](../Plugins/JMHideInteractionIntegration/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMInteraction | 1.1.1 | [README](../Plugins/JMInteraction/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMJumpScare | 2.0.0 | [README](../Plugins/JMJumpScare/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMMonsterFramework | 1.0.0 | [README](../Plugins/JMMonsterFramework/Docs/README.md) | Phase 0 최소 Enemy와 AIController 자동 Possession |
| JMObjective | 1.1.1 | [README](../Plugins/JMObjective/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMPhysicalGrabber | 1.8.0 | [README](../Plugins/JMPhysicalGrabber/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMRecon | 1.1.0 | [README](../Plugins/JMRecon/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMReconGameplayIntegration | 1.1.0 | [README](../Plugins/JMReconGameplayIntegration/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMRoomGrid | 1.5.0 | [README](../Plugins/JMRoomGrid/Docs/README_KO.md) | 분류 완료, 내용 재검증 필요 |
| JMThrowable | 1.4.1 | [README](../Plugins/JMThrowable/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| JMThrowableGameplayIntegration | 1.0.0 | [README](../Plugins/JMThrowableGameplayIntegration/Docs/README.md) | 분류 완료, 내용 재검증 필요 |
| ReusableDialogueSystem | 0.2.1 | [README](../Plugins/ReusableDialogueSystem/README.md) | 분류 완료, 내용 재검증 필요 |

전체 Plugin 구조의 현재 기준은 개별 README가 아니라 [Architecture Audit](Architecture/Architecture_Audit_KO.md)과 [Plugin Dependency Graph](Architecture/PLUGIN_DEPENDENCY_GRAPH.md)다.

## 문서 추가 전 확인

1. 기존 문서의 섹션으로 추가할 수 없는지 확인한다.
2. 새 문서의 `status`, `authority`, `scope`, owner를 정한다.
3. 적합한 분류 디렉터리에 둔다.
4. YAML 메타데이터와 관련 문서 링크를 추가한다.
5. 이 인덱스 또는 분류 README에 등록한다.
6. [`Tools/Validate-Docs.ps1`](Tools/Validate-Docs.ps1)을 실행한다.
