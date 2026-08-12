# 던전 아이템·AI 배치 구조

## 목적

아이템과 AI의 위치는 월드 좌표나 생성 순서로 정하지 않는다. 각 방 Blueprint가 로컬 빌보드 위치를 소유하고, 생성이 끝나 정상 맵으로 검증된 뒤 `JMPrototypeGeneratedDungeonDirector`가 그 슬롯만 해석한다.

플러그인 `/JMRoomGrid` 원본은 수정하지 않았다. 프로젝트 전용 방은 아래에 있다.

- 방 Blueprint: `/Game/Dungeon/Rooms13x13`
- 방 정의 DataAsset: `/Game/Dungeon/Data/Rooms13x13`
- 연결된 레벨: `/Game/Level/Level_Mapgenerate`, `/Game/Level/Level_Mapgenerate_Custom`

## 방 안의 빌보드

모든 프로젝트용 방에는 다음 8개 빌보드 컴포넌트가 배치되어 있다.

| 부모 | 컴포넌트 | 역할 |
|---|---|---|
| `ItemSpawnRoot` | `Item_Common_A` | 20% 확률의 일반 아이템 슬롯 |
| `ItemSpawnRoot` | `Item_Common_B` | 20% 확률의 일반 아이템 슬롯 |
| `ItemSpawnRoot` | `Item_EmergencyBattery` | 던전 전체 후보 중 정확히 한 곳을 고르는 배터리 슬롯 |
| `AISpawnRoot` | `AI_Entry_Default` | 맵 생성 후 AI가 처음 나타나는 위치 |
| `AISpawnRoot` | `AI_Route_Home` | 수색 종료 후 돌아올 방 중심 위치 |
| `AISpawnRoot` | `AI_Route_Patrol_01~03` | 같은 방 안의 순서 있는 순찰 위치 |

빌보드는 에디터에서만 보이고 플레이 중에는 숨겨진다. 방이 회전되어 생성되면 빌보드와 AI 경로도 방과 함께 회전한다.

## 특정 위치에 아이템 고정하기

1. 원하는 `/Game/Dungeon/Rooms13x13/BP_DungeonRoom...`을 연다.
2. `ItemSpawnRoot` 아래에 `Dungeon Item Spawn Point` 컴포넌트를 추가한다.
3. 빌보드를 실제 보행 가능한 바닥 위로 옮긴다. 현재 기본 높이는 바닥에서 `Z=80`이다.
4. `Selection Policy`를 `Always Spawn`으로 바꾼다.
5. `Item Options`에 원하는 Item Definition과 메시를 하나만 넣는다.

여러 아이템 중 하나를 확률로 고르려면 옵션의 `Weight`를 사용한다. 여러 방 후보 중 던전 전체에서 하나만 등장시킬 아이템은 `Pick One Marker From Group`을 선택하고 모든 후보에 같은 `Selection Group`을 지정한다.

## AI 위치와 경로 수정하기

`AI_Entry_Default`를 옮기면 AI의 최초 스폰 위치가 바뀐다. `AI_Route_Home`과 `AI_Route_Patrol_01~03`을 옮기면 그 방에 배정된 AI의 생활 구역이 바뀐다.

Entry와 Route의 `Route Group`이 같아야 연결된다. 한 방에 서로 다른 경로 세트를 만들려면 `Primary`, `Basement`처럼 그룹 이름을 나누면 된다. `Allowed Monster Classes`를 비워 두면 모든 몬스터가 진입점을 사용할 수 있고, 클래스를 넣으면 해당 계열만 사용할 수 있다.

던전에 넣을 AI 종류와 수는 레벨의 `JMPrototypeGeneratedDungeonDirector`에서 `Monster Roster`로 수정한다. 기본값은 Listener 1, Hoarder 1, Blackout 1이며 가능한 경우 서로 다른 방에 배정된다.

## 실행 순서와 안전 규칙

1. 생성기가 방을 모두 만든다.
2. 디렉터가 생성 결과를 검증한다. 실패한 맵에는 아이템과 AI를 만들지 않는다.
3. 아이템 슬롯의 보장·확률·유일 그룹 규칙을 Seed 기반으로 해석한다.
4. AI를 Entry에 비활성 상태로 만든 뒤 같은 방의 Home/Patrol 컴포넌트를 연결한다.
5. 각 AI의 활성 지연 시간이 지나고 Entry가 NavMesh에 투영될 때만 보이게 하고 충돌을 켠다.
6. 제한 시간까지 NavMesh가 준비되지 않으면 AI는 죽이러 순간이동하지 않고 안전하게 Dormant 상태로 남는다.

## 현재 확인 사항

표준 `Level_Mapgenerate`는 프로젝트용 방 25개로 재생성 및 검증을 통과했다. `Level_Mapgenerate_Custom`은 새 방과 디렉터 참조까지 연결했지만, 기존 셀 `(2,0)`, `(2,1)`, `(3,2)`, `(4,2)`의 방향 마스크/Yaw 불일치 때문에 원본 방 정의를 사용해도 생성 검증이 실패한다. 이 레벨에서는 해당 기존 그리드 설계를 고치기 전까지 디렉터가 콘텐츠를 활성화하지 않는 것이 의도된 안전 동작이다.
