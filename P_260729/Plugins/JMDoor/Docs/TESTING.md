# 테스트

## 자동화 테스트

Editor에서 Session Frontend → Automation → `JM.Door`를 실행하거나 다음 명령을 사용합니다.

```powershell
UnrealEditor-Cmd.exe Project.uproject -unattended -nullrhi `
  '-ExecCmds=Automation RunTests JM.Door;Quit' `
  '-TestExit=Automation Test Queue Empty'
```

포함 테스트:

- `JM.Door.Access.RequirementMatching`
- `JM.Door.Editor.ComponentReferenceSafety`
- `JM.Door.Editor.DetailsPanelSmoke`
- `JM.Door.Integration.InventoryOldKeyFlow` (통합 플러그인 설치 시)
- `JM.Door.Movement.Transforms`
- `JM.Door.Movement.DualSlidingPanels`
- `JM.Door.Movement.KinematicCharacterPush`
- `JM.Door.Movement.KinematicCharacterPushPIE`
- `JM.Door.Save.DataContract`

## Functional Test

맵: `/JMDoor/Tests/Maps/L_JMDoorFunctionalTests`

테스트: `Project.Functional Tests.JMDoor.Tests.Maps.L_JMDoorFunctionalTests.JMDoorFunctionalTest0`

회전문을 Spawn하고 Runtime 상태 머신을 통해 Open 상태와 100% 개방에 도달하는지 검사합니다. 이 맵과 `JMDoorTests` 모듈은 Editor 테스트용이며 Shipping Cook 대상에 넣지 않습니다.

## 샘플 재생성

소스 변경 후 예제 에셋을 재생성할 때:

```powershell
UnrealEditor-Cmd.exe Project.uproject -run=JMDoorGenerateSamples -unattended -nullrhi
```

## 릴리스 검증

1. Editor Development 전체 빌드
2. `JM.Door` 자동화 테스트
3. Functional Test
4. Demo Map Cook/Stage/Pak
5. 빈 C++ 프로젝트로 `JMDoor` 폴더만 복사 후 빌드
