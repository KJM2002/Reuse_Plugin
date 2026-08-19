---
title: "에디터 설정"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMThrowable"
classified_on: 2026-08-19
owners:
  - "JMThrowable Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 에디터 설정

플레이어 Actor에 `JMThrowableInteractorComponent`와
`JMThrowableGameplayIntegrationComponent`를 추가한다.

`JMThrowableDefinition` Data Asset을 만들고 Projectile Class, 속도, 중력, 반경,
충돌 프로필, 바닥 법선 임계값과 벽 반사 값을 지정한다.

Inventory Item Definition은 `Can Use`를 켜고 `Consume On Use`는 반드시 끈다.
Use Effect에 `JMThrowableInventoryUseEffect`를 추가하고 위 Definition을 지정한다.
사용 시 즉시 소비하지 않으며 실제 투척 커밋 성공 후 정확히 1개만 소비한다.

Project Settings > JM Plugins > Throwable에서 기본 키와 입력 우선순위,
Preview 갱신률, Aim 이동 제한을 설정할 수 있다.

`Trajectory Material`은 기본적으로 플러그인의
`/JMThrowable/Materials/M_ThrowableTrajectory`를 사용한다. 프로젝트별 재질로
교체할 수 있지만 Unlit, Translucent, Two Sided 구성을 권장한다.

Preview는 실제 Projectile과 동일한 fixed-step/sphere sweep을 사용하지만 최초
Blocking Hit에서만 끝난다. 따라서 벽 뒤 Bounce 경로는 Preview에 나오지 않고,
실제 Projectile은 기존 Bounce/Floor 정책을 계속 수행한다.

Preview 렌더 설정:

```text
PreviewPointSpacing          경로 중간 점 필터 간격. 첫 점과 정확한 마지막 Hit는 유지
PreviewStartDistance         카메라 앞을 가리지 않도록 선 렌더 시작을 늦추는 거리
PreviewLineWidth             Base Ribbon 폭
PreviewOpacity               Base Ribbon의 Vertex Color Alpha
PreviewEndMarkerSize         최초 충돌점 고정 구의 지름
PreviewFlowLength            이동하는 밝은 Highlight의 길이
PreviewFlowWidthMultiplier   Base Ribbon 대비 Highlight 폭
PreviewFlowLoopGap           End 뒤에서 Start로 돌아가기 전 보이지 않는 짧은 구간
PreviewFlowOrbSize           실제로 보이는 이동 구의 지름
PreviewMarkerSurfaceOffset   Marker 반지름 외에 표면에서 추가로 띄우는 거리
GlowMoveSpeed                Flow Highlight, Orb, 보조 PointLight의 이동 속도
GlowIntensity/GlowRadius     Orb 주변 선택적 보조 조명. 0이면 조명만 숨김
```

권장 시작값은 `PointSpacing 20`, `StartDistance 40`,
`LineWidth 10`, `Opacity 0.20`, `EndMarkerSize 5`,
`FlowLength 100`, `FlowWidthMultiplier 0.35`, `FlowOpacity 0.75`,
`FlowLoopGap 35`, `FlowOrbSize 3`, `MarkerSurfaceOffset 1.5`이다.
`PreviewStartDistance`는 Runtime Spawn Offset이 아니라 카메라 중심 전방의
`PreviewVisualOrigin` 거리다. 따라서 `SpawnRightOffset`이나 손 위치 보정값이
Preview 시작점에 섞이지 않는다.

Flow는 Material Time 노드가 아니라 별도 `PreviewFlowRibbon` ProceduralMesh가
매 프레임 이동하는 방식이다. Orb와 Marker도 Native low-poly sphere이므로
호스트 `/Game` Mesh가 필요 없다. 커스텀 Trajectory Material은 다음 최소 계약을
따라야 Base/Flow/구의 밝기와 Fade가 정확히 보인다.

```text
Material Domain: Surface
Blend Mode: Translucent
Shading Model: Unlit
Two Sided: true
Emissive Color: VertexColor.RGB
Opacity: VertexColor.A
```

C++은 호환성을 위해 `PreviewColor`, `BaseOpacity`, `Opacity` Parameter를
전달하지만 핵심 투명도/Fade는 Vertex Color Alpha로 완성한다. 플러그인 기본
`M_ThrowableTrajectory`는 Unreal Editor API로 위 계약에 맞게 갱신했다. 커스텀 재질이
위 계약을 무시하거나 Soft Reference 로드에 실패하면 Preview 품질만 저하되며
Ready/Aiming/Commit과 실제 투척은 계속 동작한다. 재질은 Aiming 갱신마다
동기 로드하지 않고 item-use 세션에서 한 번 준비해 재사용한다.

권장 폭죽 값:

```text
ThrowSpeed 980
VerticalThrowBoost 220
GravityScale 1
ProjectileRadius 4.5
FloorNormalThreshold 0.7
MaxWallBounces 1
BounceRestitution 0.08
TangentialDamping 0.5
MaxFloorBounces 3
FloorRestitution 0.20
FloorTangentialDamping 0.60
FloorBounceDecay 0.60
FloorBounceStopSpeed 80
SurfaceOffset 1
FloorFriction 0.18
FloorStopSpeed 50
SpawnForwardOffset 60
SpawnRightOffset 0
SpawnVerticalOffset 0
ProjectileVisualSize 8.5, 5.5, 2.2
PreviewLineWidth 10
PreviewOpacity 0.20
PreviewPointSpacing 20
PreviewStartDistance 40
PreviewEndMarkerSize 5
PreviewFlowLength 100
PreviewFlowWidthMultiplier 0.35
PreviewFlowOpacity 0.75
PreviewFlowLoopGap 35
PreviewFlowOrbSize 3
PreviewMarkerSurfaceOffset 1.5
GlowMoveSpeed 650
GlowIntensity 0
FuseDelay 1.5
BurstCount 5
BurstInterval 0.22
LightIntensity 8000
LightDuration 0.08
NoiseLoudness 4
NoiseRadius 2500
```

Projectile Visual Mesh가 지정되면 해당 Soft Mesh를 `ProjectileVisualSize`로
정규화해 사용한다. 비어 있으면 플러그인의 Native Procedural Box가 자동으로
생성되므로 `/Game` Mesh 의존성이 없다. Visual Material도 선택적 Soft Reference다.
`SphereCollision`은 기존 Blueprint 호환성을 위해 유지되며 시각 Mesh와 Native Box의
Collision/Overlap은 항상 꺼진다.

Burst Particle에는 Niagara System, Burst Sound에는 3D Sound, Sound Attenuation에는
거리 감쇠 Asset을 지정한다. 비어 있어도 나머지 Burst와 AI Hearing은 안전하게
동작한다. Blueprint에서 시각 Mesh를 추가할 때도 `SphereCollision` 아래에 두고
Collision/Simulate Physics를 끈다. 이동과 충돌은 공통 Solver가 담당한다.

바닥 반동은 벽 반동과 별도다. `FloorBounceStopSpeed`는 반동 후 속도가 아니라
충돌 직전 바닥 법선 방향 입사 속도 기준이다. 기본값에서는 큰 첫 낙하가 작게
튀고, 다음 반동은 `FloorBounceDecay`로 급격히 약해진 뒤 Slide/Rest로 전환된다.
`MaxFloorBounces=0`이면 기존처럼 바닥 반동 없이 바로 Settling 단계로 간다.
