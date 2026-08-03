# 변경 이력

## Unreleased

- All focus, entering, observing, flashlight, and failure prompt texts are editable in Project Settings.
- Key-bearing prompts use configurable `FText` format patterns.
- Recon now owns the illuminate key through a dedicated high-priority input layer while a session is active.
- Entering Recon forces player-attached spotlights off, and exiting while the illuminate key is held keeps the key captured until release to prevent a normal flashlight toggle from leaking through.
- Fixed normal interaction prompts remaining suppressed after leaving Recon by separating focus-owned and session-owned prompt suppression state.

## 1.1.0

### 추가

- `R` 한 번으로 직접 관찰, `Esc/R` 정상 종료와 `Q` 비상 취소
- 자동 제한 Mouse Look, 카메라 FOV·충돌 검증·Ease Blend
- `F` Hold SpotLight, 밝기 Fade, Soft 클릭음과 `OnFlashlightStateChanged`
- 실제 설정 키 이름을 쓰는 상태별 Native UMG/Slate 텍스트 Prompt
- 선택적 `UJMReconPromptWidgetBase` 파생 WBP

### 변경

- 우클릭 Listen/Peek 전환을 제거하고 직접 Peek UX로 단순화
- Recon 대상 포커스 중에만 JMInteraction Prompt를 숨기고 결합 안내 표시
- 종료·취소·EndPlay에서 카메라, 회전, 이동, Interaction, Prompt와 조명을 복원

### 수정

- ControlRotation이 ±180도를 넘을 때 제한 시점이 반대쪽 끝으로 뒤집히던 문제
- 제한 끝에서 계속 입력해도 누적 초과값 없이 고정되고 반대 입력에 즉시 반응하도록 Look 누적 방식 변경
- Recon 종료 시 정렬된 문 앞 위치가 남아 플레이어가 오른쪽으로 밀리던 문제
- `ExitingDuration` 동안 시작 Transform으로 Ease 복귀하고 종료 프레임에 정확한 위치·회전을 복원
- 종료 마지막까지 문틈 카메라가 유지되어 닫히는 문 Mesh와 카메라가 겹쳐 보이던 문제
- 문 닫힘·플레이어 복귀·이전 ViewTarget Blend를 같은 `ExitingDuration`에 동시 실행
- 마우스로 시점을 돌린 뒤 종료하면 Blend 마지막 프레임에 ControlRotation이 복원되며 화면이 끊기던 문제
- 카메라 복귀 Blend 전에 저장된 ControlRotation을 적용하고 Exiting 동안 Look 입력을 잠가 목표 시점을 안정화

### 호환성 중단

- 없음. `PeekKey` Config는 역직렬화 호환용으로 남지만 더 이상 바인딩하지 않습니다.

## 1.0.0

### 추가

- JMInteraction의 현재 Focus Actor를 재사용하는 Recon 시작 Bridge
- 필수 컴포넌트를 가진 Pawn 자동 감지 및 Bridge 추가
- 기본 키 입력, 카메라 Blend, 플레이어 정렬, 이동 잠금과 상태 복원
- Peek 카메라 회전 제한 및 Illuminate 전달
- Developer Settings와 자동화 테스트

### 호환성 중단

- 없음. 최초 릴리스입니다.
