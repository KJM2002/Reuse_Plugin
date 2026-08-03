# Unreal Editor 테스트 가이드

## 1. 업데이트 후 준비

1. Unreal Editor를 완전히 종료합니다.
2. 프로젝트의 Editor Development 타깃을 빌드합니다.
3. Editor를 다시 열고 **Edit → Plugins**에서 `JM Door System`과 `JM Door Gameplay Integration`이 활성화됐는지 확인합니다.
4. **Show Plugin Content**를 켭니다.

## 2. 기존 First Person Character 설정

`BP_FirstPersonCharacter`에 다음 두 컴포넌트를 둡니다.

- `JMInteractionComponent`
- `InventoryComponent`

`JMDoorInventoryAgentComponent`는 잠긴 문을 처음 사용할 때 자동으로 생성되므로 선택 사항입니다.

`InventoryUIComponent`는 `BP_FirstPersonPlayerController`에 하나만 둡니다. Character에 중복으로 붙어 있으면 제거합니다.

상호작용 입력에서 `Try Begin Interaction`을 호출합니다. `InventoryUIComponent.InventoryWidgetClass`는 `WBP_Inventory`로 설정합니다.

## 3. 수동 시나리오

테스트 레벨에 `BP_Item_OldKey`, `BP_JMRotatingDoorLockedExample`, `BP_JMRotatingDoorExample`, `BP_JMSlidingDoorExample`을 배치합니다.

1. Old Key를 상호작용해 Inventory에 넣습니다.
2. 잠긴 문을 상호작용합니다.
3. 자동으로 열린 Inventory에서 Old Key를 선택하고 **Use**를 누릅니다.
4. Inventory가 닫히고 문이 플레이어 반대 방향으로 열리는지 확인합니다.
5. 문의 양쪽에서 각각 닫고 다시 열어, 항상 상호작용자에게서 멀어지는 쪽으로 회전하는지 확인합니다.
6. 일반 회전문과 미닫이문도 같은 상호작용 입력으로 열고 닫습니다.

## 4. 자동화 테스트

**Tools → Test Automation**에서 `JM.Door`를 검색해 전부 실행합니다. 특히 다음을 확인합니다.

- `JM.Door.Access.RequirementMatching`
- `JM.Door.Editor.ComponentReferenceSafety`
- `JM.Door.Editor.DetailsPanelSmoke`
- `JM.Door.Integration.InventoryOldKeyFlow`
- `JM.Door.Movement.Transforms`
- `JM.Door.Save.DataContract`

Functional Test는 `/JMDoor/Tests/Maps/L_JMDoorFunctionalTests`를 열고 `Project.Functional Tests.JMDoor`를 실행합니다.

## 5. 추가 검증

- 장애물: 문 이동 경로에 Collision Actor를 놓고 Stop, Reverse, Retry를 확인합니다.
- 내구도: `Apply Lock Damage`, `Apply Door Damage`, `Force Open Door`를 호출합니다.
- 이벤트: `On Door State Changed`, `On Access Denied`, `On Noise Emitted`, `On Door Obstructed`에 Print String을 연결합니다.
- 일회용 키: Old Key 복제본의 `Consume On Use`를 켜고 성공 후 수량이 1 감소하는지 확인합니다.

상세 구성은 `QUICK_START_KO.md`, 저장 연동은 `SAVE_INTEGRATION.md`를 참고합니다.
