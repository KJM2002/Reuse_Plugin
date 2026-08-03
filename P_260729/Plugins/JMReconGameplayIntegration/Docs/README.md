# JMReconGameplayIntegration

기존 `JMInteraction` 포커스 흐름을 `JMRecon`에 연결하는 선택적 Runtime Bridge입니다. 별도의 정찰 Trace나 플레이어 Blueprint 이벤트 그래프를 만들지 않습니다.

## 필수 플러그인

- `JMRecon`
- `JMInteraction` (`JMGameplayEvent` 포함)

이 플러그인을 사용하지 않아도 두 기반 플러그인은 각각 독립적으로 동작합니다. 다른 프로젝트로 옮길 때는 위 세 폴더와 이 폴더를 함께 복사합니다.

## 자동 동작

플레이 중 다음 두 컴포넌트를 가진 Pawn을 찾으면 `JMReconPlayerBridgeComponent`를 자동 추가합니다.

- `JMInteractionComponent`
- `JMReconInteractorComponent`

Bridge는 Interaction이 현재 포커스한 Actor에서 `JMReconTargetComponent`를 찾아 정찰을 시작합니다. Recon 가능한 대상에만 결합 안내를 표시하고 기존 Prompt를 잠시 숨깁니다. 카메라 전환, 부드러운 플레이어 정렬, 이동 잠금, 항상 활성화된 제한 시점, 임시 SpotLight와 모든 종료 경로의 상태 복원을 기본 처리합니다. WBP가 없어도 Native UMG/Slate 텍스트 UI가 동작합니다.

## 기본 입력

- `R`: 포커스한 대상에서 정찰 시작 / 정찰 종료
- 마우스 이동: 관찰 중 설정된 Yaw/Pitch 범위에서 둘러보기
- `F` 유지: 손전등 켜기, 놓으면 Fade 후 끄기
- `Esc`: 정상 종료
- `Q`: 정찰 취소

키와 자동화 옵션은 **Project Settings > Plugins > JM Recon Gameplay Integration**에서 바꿀 수 있습니다.

## 최소 에디터 설정

1. 플레이어에 `JMInteractionComponent`와 `JMReconInteractorComponent`가 있는지 확인합니다.
2. Interaction으로 포커스 가능한 문이나 사물함 Actor에 `JMReconTargetComponent`를 추가합니다.
3. Target 컴포넌트를 플레이어가 설 위치/방향에 맞춰 배치합니다.
4. 필요할 때만 카메라 상대 Transform 또는 Definition을 고급 항목에서 덮어씁니다.

Definition을 비워두면 JMRecon Project Settings의 기본값을 사용합니다. 기본 입력과 카메라를 사용한다면 Blueprint 이벤트 바인딩은 필요 없습니다.

## 공개 확장 지점

직접 제어해야 하는 호스트는 `JMReconPlayerBridgeComponent`를 명시적으로 추가하고 자동 추가를 끈 뒤 다음 API를 사용할 수 있습니다.

- `TryStartReconFromFocusedTarget`
- `TryStartReconWithTarget`
- `FindFocusedReconTarget`
- `OnFlashlightStateChanged`

싱글플레이 로컬 Pawn을 대상으로 하며 네트워크 권한 처리는 제공하지 않습니다.
