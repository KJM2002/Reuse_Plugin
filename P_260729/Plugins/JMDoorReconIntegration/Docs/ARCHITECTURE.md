# JMDoorReconIntegration 아키텍처

## 책임과 비책임

이 플러그인은 `JMDoor` Actor의 문짝을 `JMRecon` 세션 동안만 살짝 여는 소비자 측 Adapter입니다. 문 접근 권한, 영구 상태, 저장 데이터, 자동 닫힘과 일반 `E` 상호작용은 변경하지 않습니다.

## 모듈과 의존성

- `JMDoorReconIntegration`: `JMDoorRuntime`, `JMReconRuntime`을 소비하는 Runtime Bridge
- `JMDoorReconIntegrationTests`: Editor 자동화 테스트

의존성은 Integration에서 두 독립 기능 플러그인으로만 흐릅니다. `JMDoor`와 `JMRecon`은 이 플러그인을 참조하지 않습니다.

## 수명과 데이터 흐름

World Subsystem은 Game/PIE World에서 `JMDoorComponent`와 `JMReconTargetComponent`를 함께 가진 Actor에 Adapter를 하나만 자동 추가합니다. Adapter는 Actor가 아니라 Component 형태의 `IJMReconTarget` 계약입니다.

```text
Recon 예약
→ 문 상태 검증
→ 세션 ID와 Interactor 보관
→ BeginPeekPose에서 실제 문짝 Transform 스냅샷
→ 세션 전용 작은 열림 Pose로 보간
→ 종료/취소/외부 문 상태 변경
→ 스냅샷 Transform 복원
```

회전문은 플레이어 반대 방향 후보를 선택하고, 슬라이딩 문은 존재하는 패널별 Transform을 저장·복원합니다. DoorComponent의 OpenFraction, State, SaveData와 Timer는 수정하지 않습니다.

## 실패 및 네트워크

이동 중, 잠김, 차단, 고장, 파손 상태는 안전하게 거부합니다. Target/문짝 파괴와 외부 상태 변경은 임시 Pose를 복원하고 Recon 취소를 요청합니다. 로컬 싱글플레이 전용이며 Replication과 저장을 소유하지 않습니다.
