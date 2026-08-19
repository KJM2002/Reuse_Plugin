---
title: "Objective Definition 만들기"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMObjective"
classified_on: 2026-08-19
owners:
  - "JMObjective Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Objective Definition 만들기

여러 목표를 연결하는 기본 방법은 [FLOW_SETUP_KO.md](FLOW_SETUP_KO.md)이다. 이 문서는 개별 Objective 필드와 고급 수동 연결 방법을 설명한다.

## 세 종류의 ID

```text
Objective ID: Objective.Main.GetOfficeKey  — 목표 자체의 고유 Gameplay Tag
Event Tag:    Event.Item.Acquired          — 목표를 진행시키는 사건
Target ID:    Item.Key.Office              — 사건 대상의 안정적인 FName
```

Objective ID는 프로젝트 안에서 중복되지 않는 Gameplay Tag로 지정한다. 이름은 자유롭지만 `Objective.<분류>.<행동>` 규칙을 권장한다. `Event.Item.Acquired`를 Objective ID로 넣으면 안 된다.

Gameplay Tag 추가 창에서 `You must specify a source file for gameplay tags`가 나오면 Source를 `DefaultGameplayTags.ini` 또는 프로젝트용 Gameplay Tag ini로 선택한다.

## 열쇠 Objective 예제

Content Browser에서 Miscellaneous > Data Asset > `JMObjectiveDefinition`을 선택해 `DA_Objective_GetOfficeKey`를 만든다.

| 필드 | 값 |
|---|---|
| Objective Id | `Objective.Main.GetOfficeKey` |
| Display Name | `사무실 열쇠 획득` |
| Description | `사무실 문을 열 열쇠를 찾으세요.` |
| Listening Event Tag | `Event.Item.Acquired` |
| Required Count | `1` |
| Required Target Identifier | `Item.Key.Office` |
| Auto Activate | 끔(Flow가 활성화함) |

Inventory Item Definition의 `Item Id`도 정확히 `Item.Key.Office`여야 한다. Target ID는 현재 FName이므로 Gameplay Tag 선택창이 아니라 텍스트로 입력한다.

문은 `Listening Event Tag=Event.Door.Opened`, `Required Target Identifier=Door.Office.Main`, 대화는 `Event.Dialogue.Finished`, `Dialogue.Teacher.Intro`를 사용한다.

## 자동 UI

Project Settings > Plugins > JM Objective에서 다음을 설정한다.

- Automatically Create Objective UI: 켬
- Default Objective Widget Class: 비워두면 C++ 기본 UI 사용
- Objective Widget Z Order
- Hide Widget When No Active Objective
- Completed Display Duration

커스텀 Widget Blueprint는 `JMObjectiveWidgetBase`를 부모로 만든 뒤 Default Objective Widget Class에 지정한다. Designer에서 다음 이름을 사용하면 Blueprint Graph 없이 C++가 자동으로 Text를 채운다.

```text
ObjectiveNameText
ObjectiveDescriptionText
ObjectiveProgressText
ObjectiveStateText
```

모든 필드는 Optional이므로 일부만 만들어도 크래시하지 않는다. 기존 `On Objective Activated`, `On Objective Progress Changed`, `On Objective Completed` 이벤트를 구현한 Widget도 계속 동작한다.

## 고급 수동 연결 방식

Flow를 쓰지 않는 특수 목표만 다음 방식을 사용한다.

```text
Register Objective
→ Activate Objective
```

자동 UI를 끈 경우에만 직접 Create Widget, 변수 저장, Add to Viewport, Objective Delegate Bind를 수행한다. Create Widget의 Return Value를 변수에 저장하지 않으면 `Accessed None trying to read property ObjectiveWidget` 오류가 난다. 일반 Flow 사용에서는 이 수동 노드들이 필요 없다.

