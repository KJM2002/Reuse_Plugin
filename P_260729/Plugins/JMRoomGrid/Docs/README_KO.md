# JM Room Grid

UE 5.7용 13×13 타일 방 조합형 맵 생성 플러그인입니다.

## 확정된 크기 규격

- 바닥 메시 1개: 400×400cm (`SM_Floor`)
- 방 1개: 바닥 13×13 = 169타일, 실제 5,200×5,200cm
- 전체 맵: 방 5×5 = 25방 = 바닥 65×65타일, 실제 26,000×26,000cm
- 기획 단위에서 바닥 1타일을 5×5로 셀 경우 전체 맵은 325×325입니다.

## 생성된 에셋

- `/JMRoomGrid/Blueprints/Rooms13x13/BP_Room13x13_Base`
- `BP_Room13x13_2Way_A` ~ `D` (4개)
- `BP_Room13x13_3Way_A` ~ `D` (4개)
- `BP_Room13x13_4Way_A` ~ `D` (4개)
- `/JMRoomGrid/Data/Rooms13x13/DA_Room13x13_*` (12개)
- `/JMRoomGrid/Blueprints/BP_GridMapGenerator13x13` (12개 Definition 연결 완료)

각 자식 방 Blueprint에는 통로 칸에만 `SM_Floor`와 `SM_Ceiling` 개별 컴포넌트가 있고, 그 경계에 `SM_Wall` 개별 컴포넌트가 있습니다. A~D는 서로 다른 통로 배치이며, 미러링 없이 0/90/180/270도 회전만 허용합니다.

## 사용 방법

1. 에디터를 다시 실행합니다.
2. Content Browser에서 `JMRoomGrid/Blueprints/BP_GridMapGenerator13x13`을 레벨에 배치합니다.
3. Details의 `Generate Preview`를 누릅니다.
4. 결과가 필요 없으면 `Clear Preview`, 검증하려면 `Validate Generated Map`을 누릅니다.

맵은 사진 규칙대로 모서리 2갈래 4방, 외곽 3갈래 10방, 중앙 및 입·출구 축 4갈래 11방으로 생성됩니다. 입구는 남쪽 중앙, 출구는 북쪽 중앙입니다.

새 라이브러리가 누락된 경우 `Tools > JM Room Grid > Create Editable 13x13 Room Library (12 Variants)`를 실행할 수 있습니다. 기존 에셋은 덮어쓰지 않습니다.

## 방 편집

생성된 자식 Blueprint를 열면 Components 패널에서 `JMGen_Floor_*`, `JMGen_Ceiling_*`, `JMGen_WallH_*`, `JMGen_WallV_*`를 직접 선택해 이동·삭제·복제할 수 있습니다. 모든 조각은 Project Settings에서 지정한 `SM_Floor`, `SM_Ceiling`, `SM_Wall`을 사용합니다.

`Room > 13x13`의 `Custom Walkable Tiles`에는 논리 통로 좌표가 저장되어 있습니다. 좌표 범위는 X/Y 모두 0~12이며 중앙은 (6,6)입니다. 출구 연결 논리까지 바꾸는 경우 개별 메시와 이 목록을 함께 수정하십시오. `Use Automatic 13x13 Structure`를 켜면 편집 가능한 조각 위에 자동 인스턴스 구조가 겹치므로 생성된 자식 방에서는 끈 상태를 유지하십시오.

`ContentRoot`, `ItemSpawnRoot`, `AISpawnRoot` 아래에는 가구, 추가 벽, 장식, 아이템 스폰, AI 스폰 콘텐츠를 자유롭게 추가할 수 있습니다.
