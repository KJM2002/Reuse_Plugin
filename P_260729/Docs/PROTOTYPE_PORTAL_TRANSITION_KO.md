# 프로토타입 포탈 비동기 전환 연출

`BP_PrototypeLevelPortal`은 플레이어가 겹치면 목적지 월드 패키지를 비동기로 미리 읽으면서 포탈 흡입 연출을 시작합니다. 흡입과 프리로드가 모두 끝난 뒤 `OpenLevel`을 호출하며, 동기식 월드 교체가 진행되는 동안에는 MoviePlayer 기반 Slate 로딩 화면이 게임 스레드와 별도로 계속 그려집니다.

## 연출 순서

1. 플레이어 이동/시점 입력을 잠그고 현재 카메라 위치에 임시 카메라를 생성합니다.
2. 목적지 맵에 `LoadPackageAsync`를 시작합니다.
3. 임시 카메라는 충돌 당시 위치를 기본적으로 유지하면서 `TransitionFocus`를 향해 부드럽게 회전합니다.
4. FOV는 현재 값에서 `FinalFOV`까지 단방향으로 좁아집니다. `bUseWideFOVKick`을 켠 경우에만 `PeakFOV`까지 넓힌 뒤 좁아집니다.
5. `M_PP_PortalWarp`의 `WarpStrength`가 0에서 `MaximumWarpStrength`까지 증가합니다.
6. 마지막 18%에서 검정색으로 페이드인합니다.
7. 프리로드가 끝났으면 검정색 로딩 화면을 표시하고 `OpenLevel`을 실행합니다.
8. 새 월드 로딩이 끝나면 해당 월드의 GameViewport 최상위에 검정색 Slate 오버레이와 무작위 도착 문구를 표시합니다. 이 단계는 MoviePlayer 자동 시작 여부와 무관하므로 PIE에서도 동일하게 표시됩니다.
9. 플레이어가 클릭하면 로딩 화면을 닫고 새 월드를 0.85초 동안 페이드인합니다.

## BP_PrototypeLevelPortal 조절값

- `SuctionDuration`: 흡입 연출 시간. 기본 1.35초.
- `StopDistance`: 포탈 중심 앞에서 카메라가 멈추는 거리. 기본 70cm.
- `MaximumCameraTravelDistance`: 실제 카메라가 포탈 쪽으로 이동할 수 있는 최대 거리. 기본 0cm이므로 서 있던 시점 위치가 바뀌지 않습니다.
- `SuctionCurve`: 선택 항목. 지정하지 않으면 cubic ease-in을 사용합니다.
- `PeakFOV`: 가속 중 최대 FOV. 기본 115도.
- `FinalFOV`: 진입 직전 FOV. 기본 55도.
- `bUseWideFOVKick`: 넓어졌다가 좁아지는 기존 FOV 킥 사용 여부. 기본 비활성화.
- `RotationEaseExponent`: 좌우 진입 시 포탈을 향해 회전하는 부드러움. 기본 2.0.
- `WarpMaterial`: 기본값은 `/Game/Prototype/Materials/M_PP_PortalWarp`입니다.
- `MaximumWarpStrength`: 최대 방사형 블러 오프셋. 기본 0.18.
- `ArrivalMessages`: 로딩 완료 후 검정 화면에 무작위로 표시할 문구 배열.

`SuctionCurve`를 직접 만들 경우 시간과 값의 범위는 모두 0..1이어야 합니다. 레퍼런스와 같은 감각은 `(0,0)`, `(0.3,0.03)`, `(0.6,0.15)`, `(0.8,0.5)`, `(1,1)` 키로 시작해 조절할 수 있습니다.

`TransitionFocus`는 포탈 액터 피벗과 별개인 시선 목표 컴포넌트입니다. 각 포탈 인스턴스에서 Niagara의 실제 시각적 중심으로 옮길 수 있습니다. `Level_Mapgenerate`처럼 시각적 중심과 액터 원점이 다른 경우 이 컴포넌트만 조절합니다.

## 머티리얼

`M_PP_PortalWarp`는 `ViewportUV`에서 화면 중심 `(0.5, 0.5)` 방향을 계산하고, `WarpStrength`의 0%, 25%, 50%, 75%, 100% 위치에서 `PostProcessInput0`을 샘플링해 평균냅니다. 생성 그래프를 다시 만들어야 할 때는 에디터 Python 플러그인을 활성화한 뒤 `Content/Python/create_portal_warp_material.py`를 실행합니다.

## 실패 처리와 범위

- 목적지 패키지 프리로드가 실패하면 카메라, 입력, 페이드를 원래 상태로 복구하고 포탈을 다시 활성화합니다.
- PIE가 목적지 경로에 붙이는 `UEDPIE_<번호>_` 접두사는 프리로드 전에 제거합니다. 따라서 `Level_Mapgenerate`에서 `Level_Prototype`으로 돌아오는 포탈도 같은 전환 흐름을 사용합니다.
- 프리로드 실패 후에는 플레이어가 포탈 영역을 완전히 나갔다가 다시 진입해야 재시도하므로 실패 루프가 발생하지 않습니다.
- 이 구현은 기존 두 독립 맵 구조를 유지합니다. 목적지 패키지는 비동기로 프리로드되지만 최종 월드 교체 자체는 Unreal의 `OpenLevel` 특성상 동기식입니다. 해당 구간은 MoviePlayer 로딩 화면이 가려서 화면 애니메이션이 멈추지 않습니다.
- 월드 자체를 완전히 비동기로 교체하려면 두 맵을 하나의 Persistent World 아래 Level Instance/World Partition 스트리밍 구조로 재편해야 합니다.
