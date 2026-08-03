# JM Door System

Unreal Engine 5.7용 독립 Runtime 문 시스템입니다. 회전문, 미닫이문, Blueprint 사용자 정의 이동, 접근 권한, 내구도, 장애물 처리, 자동 닫힘, 부분 개방, 소음 이벤트와 저장 데이터 계약을 제공합니다. 플러그인 데모 맵에서 Level Blueprint 없이 이동, 문 상호작용, 열쇠 획득과 잠금 해제를 바로 시험할 수 있습니다.

## 빠른 시작

Blueprint만 사용하는 처음 사용자는 [한국어 초보자 가이드](Docs/QUICK_START_KO.md)를 먼저 따라 하십시오.

1. `JMDoor` 폴더를 대상 프로젝트의 `Plugins`에 복사합니다.
2. 프로젝트 파일을 재생성하고 C++ 프로젝트를 빌드합니다.
3. Content Browser에서 **Show Plugin Content**를 켭니다.
4. `/JMDoor/Demo/Maps/L_JMDoorDemo`를 열고 Play합니다.
5. `WASD`로 이동하고 마우스로 바라본 뒤 `E`로 열쇠를 줍거나 문을 사용합니다.
6. 실제 게임에서는 사용자 또는 AI가 `IJMDoorUsableInterface::ExecuteDoorCommand`를 호출하거나 `UJMDoorBlueprintLibrary::ExecuteDoorCommandOnObject`를 사용합니다.

```cpp
FJMDoorUseContext Context;
Context.InstigatorActor = UserActor;
Context.InteractionLocation = UserActor->GetActorLocation();
Context.bQuiet = false;
Context.bFast = false;
Context.RequestedOpenFraction = 1.0f;

IJMDoorUsableInterface::Execute_ExecuteDoorCommand(
    DoorActor,
    EJMDoorCommand::Toggle,
    Context);
```

필수 JM 플러그인은 없습니다. `ItemInspector`, `InventorySystem`, AI 및 SaveGame과 직접 결합하지 않습니다.

상세 문서:

- [아키텍처](Docs/ARCHITECTURE.md)
- [API](Docs/API.md)
- [설치](Docs/INSTALLATION.md)
- [확장](Docs/EXTENDING.md)
- [저장 연동](Docs/SAVE_INTEGRATION.md)
- [테스트](Docs/TESTING.md)
- [에디터 테스트 가이드](Docs/EDITOR_TEST_GUIDE_KO.md)
- [한국어 초보자 가이드](Docs/QUICK_START_KO.md)
- [휴대용 배포](Docs/PORTABLE_INSTALL.md)
