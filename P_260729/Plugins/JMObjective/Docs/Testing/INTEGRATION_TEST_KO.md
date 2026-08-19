---
title: "열쇠 → 문 → Dialogue 통합"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMObjective"
classified_on: 2026-08-19
owners:
  - "JMObjective Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor에서 테스트 절차를 다시 실행하지 않음"
---

# 열쇠 → 문 → Dialogue 통합

자동화 테스트 `JM.Objective.Integration.KeyDoorDialogue`는 세 Definition을 코드로 만들고 실제 `UJMGameplayEventSubsystem` Publish/Subscribe 경로를 통과시킨다. 순차 활성화는 향후 Quest 역할을 대신하는 테스트 Controller 방식이다.

## 필요한 Definition

| 순서 | Objective ID | Listening Event | Target ID |
|---|---|---|---|
| 1 | `Objective.Test.GetOfficeKey` | `Event.Item.Acquired` | `Item.Key.Office` |
| 2 | `Objective.Test.OpenOfficeDoor` | `Event.Door.Opened` | `Door.Office.Main` |
| 3 | `Objective.Test.TalkToTeacher` | `Event.Dialogue.Finished` | `Dialogue.Teacher.Intro` |

각 RequiredCount는 1, MatchType은 Exact, FixedProgressAmount는 1로 둔다. 첫 번째만 게임 시작 시 활성화한다.

## 기능 Asset 설정

- Inventory Item Definition: `ItemId = Item.Key.Office`. 획득 Payload가 ItemId, 수량, ItemTags를 자동 전달한다.
- Office Door의 `JMDoorComponent`: `ObjectiveTargetIdentifier = Door.Office.Main`. Door의 이동 계산이나 이벤트 시점은 변경되지 않는다.
- Dialogue Sequence: `SequenceId = Dialogue.Teacher.Intro`. 정상 종료된 Finished Payload가 SequenceId를 전달한다.

## Blueprint 순차 Controller

Objective Subsystem의 `OnObjectiveCompleted`에 한 번 바인딩한다.

- GetOfficeKey 완료 → OpenOfficeDoor 활성화
- OpenOfficeDoor 완료 → TalkToTeacher 활성화
- TalkToTeacher 완료 → 테스트 흐름 종료

잘못된 Item Target, Inactive Door Objective, 이미 Completed인 Objective의 반복 이벤트는 진행되지 않는다.

## 자동화 실행

```text
UnrealEditor-Cmd.exe P_060715.uproject -NullRHI -Unattended -DisablePlugins=Fab -ExecCmds="Automation RunTests JM.Objective; Quit" -TestExit="Automation Test Queue Empty"
```

Fab 비활성화는 이 로컬 Editor 레이아웃이 headless 시작 중 Fab 탭을 열어 발생시키는 UI assertion을 피하기 위한 테스트 실행 옵션이며 게임 런타임과 무관하다.
