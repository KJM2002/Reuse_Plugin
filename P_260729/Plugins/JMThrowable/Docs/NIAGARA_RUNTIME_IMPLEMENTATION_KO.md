# JMThrowable Niagara 런타임 구현

JMThrowable 1.4.0부터 Line Trace 방향과 첫 Blocking Hit에 따라 갱신되는
Niagara 궤적 프리뷰가 플러그인에 포함된다.

1.4.1에서는 `User.PathPoints` 전달을 Vector Array가 아닌 Position Array로
수정하고, 게임용 반투명 Ribbon Material을 Path Renderer에 명시적으로 연결했다.
또한 Niagara가 활성화된 동안에도 동일한 Solver 경로의 흐릿한 Procedural
Underlay를 유지한다. 따라서 Niagara Renderer나 Material 상태와 무관하게
전체 포물선은 항상 표시되고, Niagara는 Flow/Impact 애니메이션을 담당한다.

## 자산

- `/JMThrowable/Effects/NS_JMThrowableTrajectory`
- `/JMThrowable/Effects/NE_JMThrowablePathRibbon`
- `/JMThrowable/Effects/NE_JMThrowableMovingDot`
- `/JMThrowable/Effects/NE_JMThrowableImpactDot`
- `/JMThrowable/Materials/M_JMThrowableRibbon_Niagara`

두 자산은 `/Game` 콘텐츠에 의존하지 않는다.

## 데이터 흐름

```text
Camera Center
  -> FJMThrowSolver::SimulatePreview
  -> First Blocking Hit에서 종료
  -> FJMThrowSolver::ResamplePathByDistance(기본 64점)
  -> User.PathPoints
  -> Niagara Ribbon
```

`UJMThrowableInteractorComponent`는 Aiming 시작 시 Niagara System을 한 번
로드하고 같은 `UNiagaraComponent`를 재사용한다. 경로 갱신 시 배열만 교체하며,
Flow 위치와 Phase는 프레임마다 전달한다.

전체 경로 Ribbon은 `User.BaseColor`의 Alpha에 `PreviewOpacity`를 전달해
진행 방향을 보여 주는 흐릿한 잔상으로 표시한다. Moving Dot과 Impact Dot의
가시성은 이 Alpha와 분리되어 유지된다.

Niagara 자산이 없거나 로드되지 않으면 기존 ProceduralMesh 프리뷰가 자동으로
사용된다. `PreviewRendererMode=ProceduralOnly`로 강제 전환할 수도 있다.

## 에디터 자산 재생성

에디터 타깃을 빌드한 뒤 Unreal Editor를 다음 플래그와 함께 한 번 실행한다.

```text
-JMGenerateThrowableNiagara
```

생성 코드는 `JMThrowableEditor` 모듈에만 존재하며 패키징 런타임에 포함되지 않는다.
