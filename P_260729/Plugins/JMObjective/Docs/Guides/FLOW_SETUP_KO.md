---
title: "Objective Flow 처음 설정하기"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMObjective"
classified_on: 2026-08-19
owners:
  - "JMObjective Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# Objective Flow 처음 설정하기

이 방식에서는 Level Blueprint에 Objective별 Register, ID Branch, 다음 Objective Activate, Widget Bind 노드를 만들지 않는다.

## 1. Gameplay Tag 준비

다음 태그를 Project Settings > Gameplay Tags에서 추가한다.

```text
ObjectiveFlow.Main.EnterOffice
Objective.Main.GetOfficeKey
Objective.Main.OpenOfficeDoor
Objective.Main.TalkToTeacher
```

## 2. Objective Definition 세 개 만들기

Content Browser > Miscellaneous > Data Asset에서 `JMObjectiveDefinition`을 선택한다.

| Asset | Objective ID | Listening Event | Target ID |
|---|---|---|---|
| DA_Objective_GetOfficeKey | Objective.Main.GetOfficeKey | Event.Item.Acquired | Item.Key.Office |
| DA_Objective_OpenOfficeDoor | Objective.Main.OpenOfficeDoor | Event.Door.Opened | Door.Office.Main |
| DA_Objective_TalkToTeacher | Objective.Main.TalkToTeacher | Event.Dialogue.Finished | Dialogue.Teacher.Intro |

각 Asset의 Required Count는 1, Auto Activate는 끔으로 둔다. Flow는 Auto Activate 설정과 관계없이 등록 시 전부 Inactive로 준비하고 첫 Step만 활성화한다.

연동 대상도 같은 Target ID를 발행해야 한다.

- 열쇠 Item Definition: `Item Id = Item.Key.Office`
- 사무실 문의 JMDoorComponent: `Objective Target Identifier = Door.Office.Main`
- 대화 Sequence: `Sequence Id = Dialogue.Teacher.Intro`

## 3. Flow Data Asset 만들기

Content Browser > Miscellaneous > Data Asset > `JMObjectiveFlowDefinition`을 선택해 `DA_Flow_EnterOffice`를 만든다.

```text
Flow ID = ObjectiveFlow.Main.EnterOffice
Objective Definitions
  [0] DA_Objective_GetOfficeKey
  [1] DA_Objective_OpenOfficeDoor
  [2] DA_Objective_TalkToTeacher
bStopOnObjectiveFailure = true
bAllowRestart = false
```

배열 순서가 실행 순서다. 빈 배열, None, 중복 Objective ID, 잘못된 Required Count는 시작 전에 거부된다.

## 4A. 레벨 시작과 동시에 실행

Place Actors 검색창에서 `JM Objective Flow Starter`를 찾아 레벨에 배치한다.

```text
Flow Definition = DA_Flow_EnterOffice
Start On Begin Play = true
Reset Flow On End Play = false
```

이제 Play하면 첫 Objective와 UI가 자동으로 나타난다. Starter에는 Tick이 없다. 같은 Flow의 Starter를 여러 개 배치해도 중복 시작은 거부된다.

## 4B. 원하는 순간에 실행

Trigger, NPC, 게임 로직의 실행 핀에서 노드 하나만 호출한다.

```text
Start Objective Flow
  Flow Definition = DA_Flow_EnterOffice
```

반환값이 true면 시작 성공이다.

## 5. 자동 UI 설정

Project Settings > Plugins > JM Objective에서 `Automatically Create Objective UI`를 켠다. Default Objective Widget Class가 비어 있으면 이름, 설명, 진행도, 상태가 표시되는 C++ 기본 UI가 사용된다.

커스텀 외형은 `JMObjectiveWidgetBase` 부모의 Widget Blueprint를 만든 뒤 Default Objective Widget Class에 선택한다. Level Blueprint에서 Create Widget이나 Bind Event를 작성하지 않는다.

## 실제 진행

```text
Flow 시작
→ 열쇠 획득 이벤트: GetOfficeKey 완료
→ OpenOfficeDoor 자동 활성화
→ 문 열기 이벤트: OpenOfficeDoor 완료
→ TalkToTeacher 자동 활성화
→ 대화 종료 이벤트: TalkToTeacher 완료
→ Flow Completed
```

완료 UI 표시 시간이 1.5초여도 다음 게임 로직은 즉시 활성화된다. 화면 표시만 잠시 이전 목표의 Completed 상태를 보여준다.

## 오류 해결

- Flow가 시작되지 않음: Flow ID, 빈 배열, None, 중복 Objective ID, Required Count를 확인한다.
- 열쇠가 진행되지 않음: Item Id와 Required Target Identifier 철자 및 Event Tag를 비교한다.
- 문이 진행되지 않음: Actor의 JMDoorComponent를 선택하고 Objective Target Identifier를 확인한다.
- UI가 안 보임: Automatically Create Objective UI와 로컬 PlayerController를 확인한다. Dedicated Server에는 UI를 만들지 않는다.
- 다시 시작되지 않음: Flow의 Allow Restart를 켜고 `Restart Objective Flow`를 호출한다.
- 같은 Objective를 공유한 두 Flow가 동시에 시작되지 않음: 첫 버전은 상태 충돌 방지를 위해 같은 Objective ID의 동시 사용을 거부한다.

