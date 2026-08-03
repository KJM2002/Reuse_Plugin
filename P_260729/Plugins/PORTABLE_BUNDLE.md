# Portable Gameplay Plugin Bundle

다른 Unreal Engine 5.7 C++ 프로젝트로 다음 세 폴더를 함께 복사한다.

```text
TargetProject/
└─ Plugins/
   ├─ ItemInspector/
   ├─ ReusableDialogueSystem/
   └─ InventorySystem/
```

각 폴더의 `Source`, `Content`, `Config`, `Docs`, `.uplugin`이 한 묶음이다. `Binaries`와 `Intermediate`는 생성 파일이므로 복사하지 않아도 되며, 대상 프로젝트에서 다시 빌드하는 방식을 권장한다.

## 포함된 연동 코드

- `UReuseDialogueInteractableComponent`: ReusableDialogueSystem에 포함
- `UReuseInventoryInspectorBridge`: InventorySystem에 포함
- `AReuseInspectableInventoryPickup`: InventorySystem에 포함

호스트 프로젝트의 `Source` 클래스 없이 세 플러그인만으로 컴파일된다.

## 포함된 예제 콘텐츠

- ItemInspector: 기본 조사 위젯, Preview 머티리얼, Old Key Mesh·Data Asset·재질·텍스처
- ReusableDialogueSystem: 기본 Dialogue 위젯, 사운드·화자·시퀀스 Data Asset, 상호작용 예제 Actor와 관련 Mesh·Material
- InventorySystem: 기본 Inventory 위젯, Input Action, Old Key Item Definition·아이콘·월드 Blueprint

플러그인 에셋은 Asset Registry 검사 기준으로 `/Game` 콘텐츠에 의존하지 않는다.

## 대상 프로젝트에서 할 일

1. 프로젝트를 닫고 세 폴더를 `Plugins`에 복사한다.
2. `Binaries`와 `Intermediate`를 복사했다면 삭제한다.
3. 프로젝트 파일을 재생성하고 Editor Development 빌드를 수행한다.
4. 세 플러그인을 활성화한다.
5. Content Browser의 `Settings -> Show Plugin Content`를 켠다.
6. 플레이어에 `JMInteractionComponent`, `InventoryComponent`, `InventoryUIComponent`를 필요한 만큼 추가한다.

기본 Widget Class, Inventory Input Action, Pickup Class는 플러그인 코드에 안전한 기본 경로가 설정되어 있어 호스트 프로젝트의 `DefaultGame.ini`를 복사할 필요가 없다.
