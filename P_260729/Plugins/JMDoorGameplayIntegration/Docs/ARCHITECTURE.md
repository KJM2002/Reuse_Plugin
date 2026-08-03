# Architecture

## 책임

이 플러그인은 세 독립 시스템의 조합만 담당합니다.

```text
JMInteractionComponent
→ UJMDoorInteractableAdapterComponent
→ AJMDoorActor

Locked Door
→ UJMDoorInventoryAgentComponent
→ Inventory UI
→ InventoryUseOnActorComponentsEffect
→ Pending Door Open
```

`UJMDoorInteractionWorldSubsystem`은 World 수명 동안 기존/신규 `AJMDoorActor`에 Transient Adapter를 하나만 등록합니다. Door 에셋을 수정하지 않습니다.

`UJMDoorInventoryAgentComponent`는 Character/Pawn 수명이며 현재 잠긴 문을 Weak Pointer로 보관합니다. UI 열기 실패, 문 파괴, 태그 불일치에서는 안전하게 실패합니다.

## 의존성

이 플러그인만 `JMDoorRuntime`, `ItemInspectorRuntime`, `InventorySystem`을 함께 참조합니다. 세 기능 플러그인은 서로의 구체 타입을 참조하지 않으므로 순환 의존성이 없습니다.

## 네트워크

현재 흐름은 코어 JMDoor와 동일하게 싱글플레이 기준입니다. 멀티플레이에서는 Door 명령과 Inventory 소비를 서버 권한 RPC 뒤에서 실행해야 합니다.
