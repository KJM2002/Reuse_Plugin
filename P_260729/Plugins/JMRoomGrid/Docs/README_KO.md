---
title: "JM Room Grid 1.5.0"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMRoomGrid"
classified_on: 2026-08-19
owners:
  - "JMRoomGrid Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JM Room Grid 1.5.0

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Docs Root | [JM Room Grid architecture](ARCHITECTURE.md) | `ReviewRequired` |
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |


Unreal Engine 5.7용 모듈형 방 Blueprint 및 5×5 맵 생성 플러그인입니다. 현재 기본 라이브러리는 편집 가능한 13×13 타일 방 12종으로 구성됩니다.

1.5.0부터 기존 고정 5×5 생성기와 별도로, 사용자가 활성 셀과 통로 방향을 직접 설계하는 `AJMCustomGridMapGenerator`를 제공합니다. 기존 `Level_Mapgenerate`, 표준 Generator Blueprint, Room Blueprint 및 Room Definition은 변경하지 않습니다.

## 커스텀 그리드 생성기

### Visual Grid Designer 사용법

1. Place Actors에서 C++ 클래스 `JMCustomGridMapGenerator`를 레벨에 배치합니다.
2. `Grid Width`, `Grid Height`를 설정합니다. 크기가 바뀌면 셀 배열이 자동 동기화되며, 필요하면 `Synchronize Cells To Grid Size`를 누릅니다.
3. `Room Definitions`에 기존 `/JMRoomGrid/Data/Rooms13x13/DA_Room13x13_*` 12개를 지정합니다.
4. Details의 `Grid Designer > 1. Shape Edit`를 선택하고 2D 격자의 Sector를 클릭해 원하는 형태를 만듭니다.
5. `Auto Connect Adjacent Cells`를 누르면 맞닿은 활성 Sector가 양방향으로 자동 연결됩니다.
6. `2. Way / Direction Edit`를 선택하고 편집할 Sector를 클릭합니다.
7. `1-Way`~`4-Way` 프리셋을 고른 다음 North/East/South/West를 조정합니다. 인접 활성 Sector의 반대 방향은 자동으로 함께 변경됩니다.
8. `Set Entrance`, `Set Exit`, `Normal`로 역할을 지정합니다. Entrance와 Exit는 각각 하나만 유지됩니다.
9. 고정 방이 필요한 Sector는 `Special Room`에서 Room Definition을 선택합니다. 비어 있으면 기존 가중치와 Seed 기반 랜덤 선택이 적용됩니다.
10. `Validate Grid`, `Refresh Viewport Preview`, `Generate Rooms`를 순서대로 실행합니다.

Grid Designer의 색상은 비활성=검정, 일반 활성=파랑, 현재 선택=노랑, Entrance=초록, Exit=진한 파랑, Special Room=주황입니다. 각 칸에는 좌표와 `N/E/S/W`, Entrance `[IN]`, Exit `[OUT]`이 함께 표시됩니다. 내부 `Cells` 배열은 저장 데이터로 유지되지만 Details에서는 숨겨져 있으므로 직접 좌표 배열을 편집할 필요가 없습니다.

`Draw Grid Design`의 Debug Box는 Unreal의 선택 가능한 오브젝트가 아니므로 직접 클릭할 수 없습니다. 대신 같은 배치를 나타내는 Details의 2D Grid Designer에서 형태와 Sector를 선택하고, `Refresh Viewport Preview`로 월드의 크기와 배치를 확인합니다.

커스텀 좌표는 Cartesian 방식입니다. East는 `X+1`, West는 `X-1`, North는 `Y+1`, South는 `Y-1`입니다. 활성 셀 사이에서는 양쪽 방향이 반드시 일치해야 합니다. 예를 들어 `(0,0).East`가 열리면 `(1,0).West`도 열려야 합니다. 일반 셀이 빈 셀 또는 Grid 밖으로 열리는 것도 오류이며, Entrance/Exit의 외부 통로만 예외입니다.

방향 수로 Way를 계산합니다.

- 1방향: 1-Way
- 2방향: 2-Way
- 3방향: 3-Way
- 4방향: 4-Way

기본 13×13 라이브러리는 기존과 동일하게 2/3/4-Way만 포함합니다. 1-Way 셀을 생성하려면 `AJMRoomModule` 기반 1-Way Blueprint와 `Junction Type = OneWay`, canonical North인 Room Definition을 별도로 만들어 `Room Definitions` 또는 해당 셀의 `Special Room Definition`에 지정해야 합니다. 기본 자동 구조는 중앙에서 North까지의 막다른 통로를 만들고 Generator가 이를 회전합니다. 해당 자산이 없으면 생성기는 셀 좌표와 함께 후보 없음 오류를 출력하며 기존 방을 임의로 변형하지 않습니다.

`Clear All Custom Generated Rooms In Level`은 새 생성기가 만든 `JMRoomGrid.CustomGenerated` 방만 제거합니다. 기존 고정 생성기의 방과 `Level_Mapgenerate` 콘텐츠는 건드리지 않습니다.

## 현재 확정 규격

| 항목 | 값 |
|---|---:|
| 바닥 타일 메시 1개 | 400×400cm (`SM_Floor`) |
| 방 내부 타일 | 13×13, 최대 169칸 |
| 방 1개의 배치 간격 | 5,200×5,200cm |
| 전체 방 그리드 | 5×5, 총 25개 방 |
| 전체 실제 크기 | 26,000×26,000cm |
| 전체 내부 타일 범위 | 65×65 타일 |

기획 단위에서 바닥 타일 한 칸을 5×5 단위로 계산하면 방 하나는 65×65, 전체 맵은 325×325 단위입니다. 플러그인에서 사용하는 실제 Unreal 단위는 위 표의 cm 값을 기준으로 합니다.

## 13×13 방 라이브러리

에셋 경로는 다음과 같습니다.

- 기본 클래스: `/JMRoomGrid/Blueprints/Rooms13x13/BP_Room13x13_Base`
- 2갈래 방: `BP_Room13x13_2Way_A` ~ `BP_Room13x13_2Way_D`
- 3갈래 방: `BP_Room13x13_3Way_A` ~ `BP_Room13x13_3Way_D`
- 4갈래 방: `BP_Room13x13_4Way_A` ~ `BP_Room13x13_4Way_D`
- 방 Definition 12개: `/JMRoomGrid/Data/Rooms13x13/DA_Room13x13_*`
- 맵 Generator: `/JMRoomGrid/Blueprints/BP_GridMapGenerator13x13`

각 갈래 유형에 A~D 네 가지 디자인이 있습니다. 방은 미러링하지 않고 0°, 90°, 180°, 270° 회전만 사용하여 이웃 방의 출입 방향에 맞춥니다.

각 디자인은 13×13 전체를 무조건 채우지 않습니다. `Custom Walkable Tiles`에 등록된 이동 가능 칸에만 바닥과 천장이 존재하며, 이동 가능 영역과 빈 영역의 경계에만 벽이 배치됩니다. 따라서 굽은 통로, 비대칭 방, 작은 방, 루프 및 막다른 탐색 공간을 만들 수 있습니다.

## Project Settings

`Project Settings > Plugins > JM Room Grid`에서 다음 메시를 지정합니다.

- `Floor Mesh`: `SM_Floor`
- `Wall Mesh`: `SM_Wall`
- `Ceiling Mesh`: `SM_Ceiling`

라이브러리를 다시 생성하면 `JMGen_Floor_*`, `JMGen_WallH_*`, `JMGen_WallV_*`, `JMGen_Ceiling_*` 컴포넌트가 이 설정의 메시를 직접 사용합니다.

## 에디터에서 맵 생성

1. `/JMRoomGrid/Blueprints/BP_GridMapGenerator13x13`을 레벨에 하나 배치합니다.
2. Generator의 `Room Cell Size`가 **5200**인지 확인합니다.
3. Details에서 `Clear All Generated Rooms In Level`을 눌러 이전 생성물을 제거합니다.
4. `Generate Preview`를 누릅니다.
5. `Validate Generated Map`으로 결과를 검사합니다.
6. 필요하면 `Print Generation Report`에서 셀 위치, 방향, 클래스와 회전값을 확인합니다.

표준 토폴로지는 모서리의 2갈래 방 4개, 외곽의 3갈래 방 10개, 중앙과 입·출구 축의 4갈래 방 11개로 총 25개입니다. 입구는 남쪽 중앙, 출구는 북쪽 중앙에 연결됩니다.

### 재생성 버튼의 차이

- `Clear Preview`: 현재 Generator가 소유한 미리보기 방을 제거합니다.
- `Clear All Generated Rooms In Level`: 레벨에 남은 `JMRoomGrid.Generated` 방을 모두 제거합니다. 삭제된 Generator가 남긴 방이나 중복 생성물을 정리할 때 사용합니다.
- `Regenerate Same Seed`: 현재 Seed로 같은 구조를 다시 생성합니다.
- `Generate New Seed`: 새 Seed로 방 Variant 선택을 변경합니다.

## 게임 실행 시 생성

`Generate Preview`로 만든 방은 에디터 확인용 `Transient` Actor이므로 PIE 또는 게임 실행 시 제거되는 것이 정상입니다.

게임에서 방을 사용하려면 Generator의 Details에서 다음과 같이 설정합니다.

- `Generation > Generate On Begin Play`: **켜기**
- 같은 배치를 반복하려면 `Random > Use Random Seed`: **끄기**
- 고정 배치값: `Random > Random Seed`에 원하는 정수 입력

이 설정에서는 게임 시작 시 게임 월드에 25개 방을 새로 생성합니다. 현재 버전은 에디터 Preview를 영구 Actor로 변환하는 Bake 기능을 제공하지 않습니다.

## 개별 방 편집

원하는 `BP_Room13x13_*` Blueprint를 열고 Components 패널에서 다음 컴포넌트를 직접 이동, 삭제 또는 복제할 수 있습니다.

- `JMGen_Floor_*`: 개별 바닥
- `JMGen_Ceiling_*`: 개별 천장
- `JMGen_WallH_*`: 가로 방향 벽
- `JMGen_WallV_*`: 세로 방향 벽

모든 생성 컴포넌트는 이동 가능한 Generator 계층에 정상 부착되도록 `Movable`로 구성됩니다. `ContentRoot`, `ItemSpawnRoot`, `AISpawnRoot` 아래에는 가구, 장식, 추가 벽, 아이템 Spawn 및 AI Spawn 콘텐츠를 자유롭게 추가할 수 있습니다. 라이브러리 업그레이드는 `JMGen_*` 컴포넌트만 교체하고 이 사용자 콘텐츠는 보존합니다.

### 통로 좌표 편집

`Room > 13x13 > Custom Walkable Tiles`는 방의 논리 이동 가능 좌표입니다.

- X/Y 범위: 0~12
- 중앙 좌표: (6, 6)
- 출입구는 각 변의 중앙 칸을 기준으로 연결

메시 배치뿐 아니라 방의 통로 판정까지 변경하려면 개별 메시와 `Custom Walkable Tiles`를 함께 수정해야 합니다. `Use Automatic 13x13 Structure`를 켜면 편집용 `JMGen_*` 구조와 자동 인스턴스 구조가 겹칠 수 있으므로 기본 생성 방에서는 꺼진 상태를 유지합니다.

### 천장 숨기기

- 개별 방 Blueprint 편집: `Hide Ceiling In Editor`를 사용해 편집 중 천장을 숨깁니다.
- 전체 맵 Preview: Generator의 `Hide Ceilings For Preview`를 사용합니다.

두 옵션은 에디터 가시성만 제어하며 천장 메시를 삭제하지 않습니다.

## 라이브러리 생성 및 검증 메뉴

`Tools > JM Room Grid`에서 다음 기능을 사용할 수 있습니다.

- `Validate Prototype Assets`
- `Create Missing Room Blueprints`
- `Repair Room Contract Defaults`
- `Validate Room Blueprints`
- `Create 5x5 Room Library (12 Variants)`
- `Create Editable 13x13 Room Library (12 Variants)`

13×13 라이브러리 생성은 기존 사용자 컴포넌트를 보존합니다. 생성 구조 버전이 바뀐 경우 `JMGen_*` 컴포넌트만 다시 만들고 저장합니다.

## 문제 해결

### 방 Actor 위치는 맞지만 메시가 중앙에 겹침

1. Unreal Editor를 완전히 종료합니다.
2. 플러그인을 최신 버전으로 빌드합니다.
3. `Create Editable 13x13 Room Library (12 Variants)`를 실행해 구조 버전 3으로 갱신합니다.
4. `Clear All Generated Rooms In Level` 후 다시 `Generate Preview`를 실행합니다.

1.4.1부터 생성 메시가 `Movable`로 만들어지므로 이동 가능한 `StructureRoot`에 정상 부착됩니다.

### Generate를 눌러도 일부 구역만 보임

- 레벨에 Generator가 하나만 있는지 확인합니다.
- `Room Definitions`에 13×13 Definition 12개가 연결되어 있는지 확인합니다.
- `Room Cell Size`가 5200인지 확인합니다.
- `Clear All Generated Rooms In Level` 후 다시 생성합니다.
- Output Log의 `LogJMRoomGrid` 오류를 확인합니다.

## 검증 상태

현재 자동화 테스트는 방향 회전, Prototype 크기, 표준 5×5 토폴로지, 방 기본 계약, Seed 결정성, 5×5 방 레이아웃 및 13×13 방 레이아웃의 총 7개 항목을 검사합니다.
