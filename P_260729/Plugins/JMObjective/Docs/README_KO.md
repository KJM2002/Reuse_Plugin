# JMObjective

`JMObjective`는 `JMGameplayEvent`를 받아 목표 진행도를 계산하는 재사용 가능한 Runtime Plugin이다. Door, Inventory, Dialogue, Interaction 플러그인을 직접 참조하지 않는다.

필수 플러그인은 `JMGameplayEvent` 하나다. `JMObjective` 폴더만 다른 프로젝트로 옮길 때는 `JMGameplayEvent`도 함께 설치해야 한다. Door/Inventory/Dialogue/Interaction이 없어도 수동 Gameplay Event와 Objective API는 정상 동작한다.

## 권장 사용 방식

여러 목표는 Blueprint에서 직접 연결하지 않고 Objective Flow Data Asset으로 관리한다.

```text
Objective Definition 생성
→ Flow Asset에 실행 순서대로 추가
→ JM Objective Flow Starter를 레벨에 배치
→ 완료
```

Flow는 목표 등록, 첫 목표 활성화, 완료된 목표 판별, 다음 목표 활성화를 C++에서 자동 처리한다. UI도 Project Settings 설정에 따라 자동 생성된다.

- 처음 설정하기: [FLOW_SETUP_KO.md](FLOW_SETUP_KO.md)
- 개별 Objective와 고급 수동 연결: [EDITOR_OBJECTIVE_SETUP_KO.md](EDITOR_OBJECTIVE_SETUP_KO.md)
- 구조 설명: [ARCHITECTURE_KO.md](ARCHITECTURE_KO.md)
- 저장 연동: [SAVE_INTEGRATION_KO.md](SAVE_INTEGRATION_KO.md)

## 주요 타입

- `UJMObjectiveDefinition`: 목표 하나의 이벤트, 수량, 필터 조건
- `UJMObjectiveFlowDefinition`: 목표들의 선형 실행 순서
- `UJMObjectiveSubsystem`: 개별 목표 상태와 이벤트 구독
- `UJMObjectiveFlowSubsystem`: Flow 상태와 자동 순차 진행
- `UJMObjectiveUISubsystem`: 로컬 플레이어별 위젯 생성과 갱신
- `AJMObjectiveFlowStarter`: 레벨 시작 시 Flow를 시작하는 선택적 Actor

## 범위

첫 버전 Flow는 선형 순서만 지원한다. 분기 Quest, 보상, Quest Marker, Replication, Save 슬롯 파일 입출력은 포함하지 않는다. 이후 상위 `JMQuest`가 Flow/Objective API를 조합할 수 있도록 Definition에는 다음 목표 포인터를 넣지 않았다.

지원 기준은 Unreal Engine 5.7이다. 플러그인 배포 시 `Binaries`, `Intermediate`, `Saved`는 제외하고 `JMObjective.uplugin`, `Source`, `Config`, `Content`, `Docs`를 포함한다.

