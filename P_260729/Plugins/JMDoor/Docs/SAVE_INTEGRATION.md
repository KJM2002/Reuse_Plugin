# 저장 시스템 연동

JMDoor는 SaveGame 클래스나 슬롯에 의존하지 않습니다.

## 저장

1. `IJMDoorSaveInterface` 구현 Actor를 등록합니다.
2. `GetDoorPersistentId`를 키로 사용합니다.
3. `CaptureDoorSaveData` 결과를 외부 Save Record에 저장합니다.

```cpp
const FGuid Id = IJMDoorSaveInterface::Execute_GetDoorPersistentId(Door);
const FJMDoorSaveData Data = IJMDoorSaveInterface::Execute_CaptureDoorSaveData(Door);
DoorRecords.Add(Id, Data);
```

## 복원

레벨 Actor 등록이 끝난 뒤 같은 Persistent ID Record를 찾아 `RestoreDoorSaveData`를 호출합니다.

복원 데이터:

- Schema Version
- Persistent ID
- 상태
- 잠금/잠금 파손
- 개방 비율
- 문짝/잠금장치 내구도

복원은 진행 중 Timer/Tick을 정리하고 Transform을 즉시 적용합니다. 버전이 1이 아니거나 유효한 ID가 다른 데이터는 거부합니다.

## ID 주의사항

`AJMDoorActor`는 생성 또는 로드 시 ID가 없으면 생성합니다. 레벨에 배치한 Actor는 생성된 ID를 레벨/Blueprint에 저장한 뒤 커밋해야 합니다. 런타임 Spawn Door는 생성된 ID를 Spawn Record와 함께 최초 저장해야 다음 세션에서 동일 ID로 재생성할 수 있습니다.

Actor 복제, Copy/Paste 후에는 ID 중복 검사를 외부 Save Registry 또는 Editor Validation에서 수행하는 것이 좋습니다. 1.0.0 Runtime은 전역 Actor 검색과 자동 중복 수정을 하지 않습니다.

## 버전 변경

`FJMDoorSaveData.Version`은 현재 1입니다. 필드 의미가 바뀌면 새 버전과 명시적 마이그레이션을 추가하고 기존 데이터를 조용히 오해하지 않습니다.
