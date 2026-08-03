# JMReconGameplayIntegration 아키텍처

## 책임과 비책임

이 플러그인은 `JMInteraction`이 선택한 Actor를 `JMRecon` 세션으로 전달하고, 로컬 플레이어 입력·카메라·이동 상태, Recon 전용 텍스트 Prompt와 임시 SpotLight를 연결합니다. Interaction 탐색 규칙과 Recon 상태 머신 및 Target Pose는 각 기반 플러그인이 계속 소유합니다. 문 상태나 인벤토리 규칙은 다루지 않습니다.

## 모듈과 의존성

- `JMReconGameplayIntegration`: `JMInteraction`, `JMReconRuntime`, Engine/InputCore를 소비하는 Runtime Bridge
- `JMReconGameplayIntegrationTests`: 에디터 자동화 테스트

의존성은 Integration에서 두 기반 플러그인으로만 흐릅니다. `JMRecon`과 `JMInteraction`은 Integration을 참조하지 않습니다.

## 런타임 흐름

`UJMReconGameplayIntegrationWorldSubsystem`은 Game/PIE World의 Pawn을 관찰합니다. 두 필수 컴포넌트가 있고 설정에서 자동 연결을 허용한 Pawn에 Bridge를 하나만 추가합니다.

```text
JMInteraction 현재 Focus Actor
        -> JMReconTargetComponent 검색
        -> TryStartRecon
        -> 입력/Prompt 상태 보관 및 잠금
        -> 플레이어 정렬 및 검증된 임시 CameraComponent로 Ease Blend
        -> 제한 Look + F Hold SpotLight
        -> Finish 또는 Cancel
        -> 이전 ViewTarget/회전/입력/Prompt 복원
```

Bridge Tick은 진입 정렬, Peek 상태의 프레임 독립 회전 보간 또는 손전등 Fade가 필요할 때만 활성화됩니다. 입력 컴포넌트가 늦게 생성되는 경우 짧은 Timer로 바인딩을 재시도합니다. Raw Key 경로는 기존 호스트 입력을 보존하기 위한 기본 폴백이며, 플러그인은 프로젝트 Mapping Context를 하드 참조하지 않습니다.

## 실패 시 동작

필수 컴포넌트, PlayerController, 포커스 Actor 또는 Recon Target이 없으면 요청은 실패 결과를 반환하고 상태를 변경하지 않습니다. 세션이 실제로 시작된 경우에만 복원용 상태를 사용하므로 EndPlay만 호출된 Pawn의 입력과 시점을 덮어쓰지 않습니다. 자동 카메라를 끄면 JMRecon의 원래 Delegate 계약을 호스트가 직접 사용할 수 있습니다.

## 설정과 이식성

모든 기본값은 `UJMReconGameplayIntegrationSettings`와 플러그인 Config에 있으며 `/Game` 에셋을 참조하지 않습니다. Native UMG/Slate 폴백은 Widget 에셋 누락 시에도 동작하며, 선택 WBP와 클릭음은 Soft Reference입니다. 프로젝트 Config는 필요한 값만 덮어쓸 수 있습니다. 저장과 Replication은 범위 밖이며 로컬 싱글플레이 세션만 지원합니다.
