# 확장 가이드

## 사용자 정의 이동

Blueprint에서 `JM Custom Door Movement Component` 자식을 만들고 `Calculate Relative Transform`을 Override합니다.

입력:

- Open Fraction: 0은 닫힘, 1은 목표 개방
- Direction Sign: 위치 기반 방향 정책 결과인 +1 또는 -1

출력은 문짝의 닫힌 상대 Transform을 기준으로 계산한 최종 상대 Transform입니다. 상태 변경, Timer 또는 접근 검사는 이동 Blueprint에 넣지 않습니다.

C++에서는 `UJMDoorMovementComponent`를 상속하고 `CalculateRelativeTransform_Implementation`을 구현합니다.

## 인벤토리·카드키 연결

Character, Pawn 또는 별도 Provider Component가 `IJMDoorAccessProviderInterface`를 구현합니다.

- `GetDoorAccessTags`: 현재 보유 권한
- `CanProvideDoorAccess`: 커스텀 조건 검사
- `ConsumeDoorAccess`: 일회성 열쇠/카드 차감

Provider가 Actor Component라면 Actor가 인터페이스를 전달하거나, 게임 쪽 Adapter Actor/Component를 사용하십시오. JMDoor Runtime에 Inventory 헤더를 include하지 않습니다.

## AI 연결

Behavior Tree Task, StateTree Task 또는 AI 코드에서 `IJMDoorUsableInterface`를 호출합니다. AI 전용 Door API는 없습니다. 경로 계획, 대기, 문 파괴 선택은 AI 쪽 책임이며 Door Result Code와 상태 이벤트로 판단합니다.

## 소음 연결

`OnNoiseEmitted`에 외부 Noise Subsystem Adapter를 Bind합니다. 이벤트에는 위치, Loudness, Range, Gameplay Tag, Source와 Instigator가 있습니다. JMDoor에서 AI Perception을 직접 호출하지 않습니다.

## 커스텀 장애물

기본 검사는 Moving Component Bounds 기반 Box Overlap입니다. 매우 얇거나 다중 문짝인 경우:

- 충돌용 Primitive를 Moving Component로 사용하거나
- `UJMDoorComponent`를 상속해 `IsObstructed`를 확장할 수 있도록 C++ 계층을 포크/확장하거나
- 문짝마다 독립 Door/Movement Component를 구성합니다.

## 멀티플레이

서버 RPC에서 `ExecuteCommand`를 호출하고, State/OpenFraction/Lock/Durability를 복제하는 파생 Component를 권장합니다. Client는 UI와 예측만 수행하고 접근 아이템 소비를 확정하지 않습니다.
