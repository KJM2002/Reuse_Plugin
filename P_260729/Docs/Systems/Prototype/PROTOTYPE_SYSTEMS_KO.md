---
title: Base Upgrade 최소 프로토타입 시스템
status: ReviewRequired
authority: Supporting
scope: Prototype
last_reviewed: 2026-08-19
review_reason: 코드 및 에셋 상태와 재검증 필요
owners:
  - Prototype
related:
  - PROTOTYPE_PORTAL_TRANSITION_KO.md
  - ../../Testing/PROTOTYPE_PLAYTEST_KO.md
---

# Base Upgrade 최소 프로토타입 시스템

## 레벨 구조

- `/Game/Prototype/Maps/Level_Prototype`: 의뢰, 제출, 요리, 업그레이드를 수행하는 고정 기지입니다.
- `/Game/Level/Level_Mapgenerate`: `JM Room Grid`가 실행마다 방과 콘텐츠를 배치하는 랜덤 던전입니다.
- `/Game/Prototype/Blueprints/BP_PrototypeLevelPortal`: `NS_Portal`의 구형 오버랩 영역으로 두 레벨을 연결합니다.

포탈은 Interaction 인터페이스를 구현하지 않습니다. 플레이어 Pawn이 영역에 겹치면 의뢰, 인벤토리, 진행 상태를 검사하지 않고 지정된 `DestinationWorld`에 `OpenLevel`을 호출합니다.

## 주요 책임

- `UJMPrototypeProgressionSubsystem`: 의뢰 상태, 화폐, 인벤토리 업그레이드를 보관하고, 맵 로드 직전에 전체 인벤토리를 자동 저장해 새 Pawn에 복원합니다.
- 영구 인벤토리 체크포인트는 `Level_Mapgenerate`에서 `Level_Prototype`으로 정상 귀환할 때만 기록됩니다. 던전에서 게임을 종료하면 그 탐사의 미귀환 아이템은 저장되지 않습니다.
- `AJMPrototypeLevelPortal`: 진입·귀환 조건 검사, 아이템 임시 저장, 오버랩 잠금, 레벨 이동을 담당합니다.
- `AJMPrototypeFlowCoordinator`: 최초 실행에만 프로토타입 설정을 구성하고, 레벨 이동 뒤에는 진행 상태를 초기화하지 않습니다.
- `AJMPrototypeGeneratedDungeonDirector`: 생성된 방의 `ItemSpawnRoot`와 `AISpawnRoot`에 수집물, 순찰 지점, 몬스터를 분산 배치합니다.
- `UJMPrototypeDialogueQuestBridgeComponent`: 기존 Dialogue 완료를 의뢰 수락과 Objective Flow 시작으로 연결합니다.
- `AJMPrototypeQuestSubmitStation`: 실제 아이템 수량을 확인하고 제거한 뒤 의뢰 보상을 지급합니다.
- `AJMPrototypeCookingStation`: 부산물을 소비하고 요리 보상을 지급합니다.
- `AJMPrototypeUpgradeStation`: 화폐를 소비하고 InventorySystem의 안전한 용량 변경 API를 호출합니다.
- `AJMPrototypeMonster`: AI Perception 기반 시야, 순찰, 추격, 접촉 판정을 수행합니다.
- `UJMPrototypeRunResetComponent`: 실패 시 이번 탐사 아이템을 제거하고 기지 레벨로 복귀시킵니다.

## 포탈 배치 규칙

1. 기지 포탈은 `EnterDungeon`, 목적지는 `Level_Mapgenerate`로 설정합니다.
2. 던전 포탈은 `ReturnToBase`, 목적지는 `Level_Prototype`으로 설정합니다.
3. 이동 보존 목록에는 점액 샘플, 몬스터 부산물, 스크랩, 배터리를 지정합니다.
4. 오버랩 Sphere는 Pawn만 감지하며 기본 반경은 190cm입니다.
5. 상태 전이가 성공한 뒤 오버랩을 즉시 비활성화해 중복 레벨 이동을 차단합니다.
6. 기존 `AJMPrototypePortal` 인스턴스는 표시, 상호작용, 충돌을 모두 끕니다.

## 실패 안전성

- 의뢰를 받지 않은 상태의 던전 진입과 탐사 상태가 아닌 귀환은 거부됩니다.
- 목적지 레벨이나 인벤토리가 없으면 상태와 화폐를 바꾸지 않고 실패 결과를 반환합니다.
- 제출 보상은 필요한 아이템 제거가 성공한 뒤에만 지급됩니다.
- 업그레이드 비용은 인벤토리 용량 변경이 성공한 뒤에만 차감됩니다.
- 실패 초기화는 영구 화폐와 구매한 인벤토리 업그레이드를 유지합니다.

## 현재 제외 범위

- SaveGame 영구 저장
- 실제 조리 미니게임 UI
- 공격과 전투
- 포탈 잠금·불안정 연출
- 멀티플레이와 Replication
