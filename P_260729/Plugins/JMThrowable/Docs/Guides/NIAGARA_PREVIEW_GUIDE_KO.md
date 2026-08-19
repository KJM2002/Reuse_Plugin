---
title: "JMThrowable Niagara 궤적 전환 가이드"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMThrowable"
classified_on: 2026-08-19
owners:
  - "JMThrowable Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# JMThrowable Niagara 궤적 전환 가이드

## 권장 책임 분리

탄도와 충돌은 현재 `FJMThrowSolver`가 계속 담당한다. Niagara는
`SimulatePreview`가 만든 first-hit 경로를 그리는 Cosmetic Renderer만 담당한다.

```text
Camera Center
    -> FJMThrowSolver::SimulatePreview
    -> TArray<FVector> PathPoints
    -> Niagara Vector Array Data Interface
       -> Base/Flow Ribbon
       -> Moving Dot
       -> Impact Dot
```

`PredictProjectilePath`나 Chaos로 교체할 필요가 없으며, Preview와 Runtime이
공유하는 fixed-step 결과도 유지된다.

## 권장 User Parameter

```text
User.PathPoints             Vector Array
User.ImpactPoint            Vector
User.ImpactNormal           Vector
User.HasImpact              Bool
User.FlowPhase              Float
User.BaseWidth              Float (기본 10cm)
User.BaseOpacity            Float (기본 0.20)
User.FlowWidthMultiplier    Float (기본 0.35)
User.FlowOpacity            Float (기본 0.75)
User.DotSize                Float (기본 3cm)
User.ImpactDotSize          Float (기본 5cm)
```

C++에서는 `UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayVector`로
`User.PathPoints`를 갱신한다. 배열 순서를 그대로 Ribbon Link Order로 사용한다.
Spline Data Interface는 필요하지 않다.

## Renderer 구성

가장 관리하기 쉬운 구성은 Ribbon Renderer 하나와 Sprite Renderer 두 개다.

- Ribbon: Base와 이동 Flow를 하나의 Material에서 합성한다.
- Moving Dot: Flow Phase와 같은 정규화 거리를 사용하는 Camera-Facing Sprite.
- Impact Dot: `HasImpact`일 때만 `ImpactPoint + ImpactNormal * Offset`에 표시한다.

Ribbon Material의 횡방향 Alpha는 `Ribbon UV Y` 기준으로
`0 -> 1 -> 0`이 되게 한다. Base는 이 Edge Falloff에 0.20을 곱한다.
Flow는 경로 방향의 Moving Mask와 같은 Edge Falloff를 곱해 Base 내부에서만
밝아지게 한다.

```text
BaseOpacity = EdgeFalloff * User.BaseOpacity
FlowMask = SmoothStep(FlowHead/Tail, NormalizedDistance - User.FlowPhase)
FlowOpacity = EdgeFalloff * FlowMask * User.FlowOpacity
Opacity = Saturate(BaseOpacity + FlowOpacity)
```

Flow를 별도의 굵은 Ribbon으로 만들면 다시 흰 막대처럼 보이기 쉬우므로,
우선순위는 단일 Ribbon Material 내부 Highlight다.

## 전환 순서

1. `NS_JMThrowableTrajectory`와 전용 Translucent/Unlit Ribbon Material을 만든다.
2. 현재 Procedural Preview와 동일한 PathPoints를 Niagara에 동시에 전달한다.
3. 정면/근거리 벽/원거리 벽/바닥/낮은 장애물에서 두 Renderer를 비교한다.
4. Niagara 품질과 Cleanup이 확인되면 Niagara를 기본으로 전환한다.
5. Niagara Asset 누락이나 로드 실패 시 현재 ProceduralMesh를 fallback으로 남긴다.

이 구조에서는 물리 수정을 VFX에 섞지 않고 Width, Edge Fade, Flow, Dot을
Niagara와 Material Editor에서 실시간으로 조절할 수 있다.
