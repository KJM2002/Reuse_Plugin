# Save 연동

플러그인은 SaveGame 파일을 직접 만들지 않고 저장 가능한 구조체를 캡처·복원한다. 실제 슬롯 파일 입출력은 게임의 Save 시스템이 담당한다.

## 개별 Objective

`CaptureObjectiveStates()`는 `FJMObjectiveSaveData` 배열을 반환한다. ID, 상태, 진행 수량, 활성/완료/실패 시각이 포함된다.

수동 Objective를 복원할 때는 Definition들을 먼저 등록한 뒤 `RestoreObjectiveStates()`를 호출한다. Active 상태는 Gameplay Event 구독까지 복구된다.

## Objective Flow

`CaptureObjectiveFlowStates()`는 `FJMObjectiveFlowSaveData` 배열을 반환한다. 다음 값이 포함된다.

- Flow ID와 Flow Definition의 Soft Reference
- Flow 상태, 현재 Step Index, 현재 Objective ID
- 시작/완료/실패 시각
- 해당 Flow에 속한 개별 Objective 상태 배열

`RestoreObjectiveFlowStates()`는 Flow Definition을 불러오고 Objective 등록 및 상태/구독을 함께 복구한다. Active Flow는 저장 당시 Step부터 계속 진행한다.

Blueprint에서는 다음 노드를 사용한다.

```text
저장: Capture Objective Flow States → SaveGame 변수에 저장
복원: SaveGame 로드 → Restore Objective Flow States
```

복원 전에 Asset 경로가 바뀌어 Soft Reference를 불러올 수 없거나 Definition 내용과 저장된 현재 Step이 일치하지 않으면 해당 Flow 복원은 실패하고 전체 반환값은 `false`가 된다. 출시 후 Objective 배열 순서를 바꾸려면 프로젝트 Save 버전 마이그레이션을 추가하는 것이 안전하다.

