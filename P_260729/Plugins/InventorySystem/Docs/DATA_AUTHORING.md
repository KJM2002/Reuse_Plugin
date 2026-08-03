# 아이템 데이터 제작

아이템마다 **Inventory Item Definition** 형식의 Primary Data Asset을 생성한다.

## Old Key 설정

`DA_Inventory_OldKey`를 생성한 뒤 다음과 같이 설정한다.

- Item Id: `OldKey`
- Display Name: `Old Key`
- Description: `An old and worn key. It may open something nearby.`
- Icon: `/InventorySystem/Example/Icons/oldKey`
- Inspect Mesh: `/ItemInspector/Item/SM_OldKey`
- Inspector Data: `/ItemInspector/Item/DA_OldKey_Inspection`
- Can Use: 비활성화
- Can Drop: 활성화
- Can Inspect: 활성화
- Stackable: 비활성화
- Max Stack Size: `1`
- Consume On Use: 비활성화

원본 PNG는 `C:/Users/User/Downloads/oldKey.png`에도 있지만 프로젝트에 이미 Import된 Texture2D가 있으므로 중복으로 Import할 필요가 없다.

## 새로운 아이템 추가

기존 Item Definition을 복제하고 고유한 ItemId를 지정한 뒤 Soft Reference 에셋과 규칙을 설정한다. 사용 가능한 아이템은 `UInventoryItemUseEffect`를 부모로 하는 Blueprint Class를 생성하고 Item Definition의 `UseEffect`에 인스턴스 형태로 추가한다. `CanUse`와 `ExecuteUse`를 구현한다.

소모 여부는 사용 효과와 별개로 설정한다. 이를 통해 사용해도 남는 지도와 사용 후 사라지는 열쇠가 동일한 API를 사용할 수 있다.

`MakeSaveEntries`는 ItemId, Quantity, InstanceId를 반환한다. 불러오기는 프로젝트가 ItemId 또는 Asset Manager 기반 검색 정책을 정한 뒤 연결하도록 남겨 두었다.
