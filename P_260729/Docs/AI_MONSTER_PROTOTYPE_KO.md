# 던전 AI 몬스터 프로토타입

## 에셋 위치

- `/Game/AI/Listener/BP_Listener_Blockout`
- `/Game/AI/Hoarder/BP_Hoarder_Blockout`
- `/Game/AI/Blackout/BP_Blackout_Blockout`
- `/Game/AI/Blackout/BP_BlackoutSafeLight`

각 Blueprint는 네이티브 AI 클래스를 부모로 사용한다. 외형은 Engine Basic Shapes 조합이며 이후 Skeletal Mesh와 Anim Blueprint로 교체한다.

## 공통 상태

`Patrol → Suspicious → Investigate/Chase → AttackWarning → Search → Return`

- 시야나 소리를 처음 감지하면 즉시 죽이러 가지 않고 경고 상태를 거친다.
- 시야를 잃으면 플레이어 현재 위치가 아니라 마지막 증거 위치를 수색한다.
- `JMHide`로 완전히 숨은 플레이어는 추적 대상에서 제외한다.
- 접촉 즉사는 사용하지 않는다. 근접 후 별도의 `AttackWarningDuration` 동안 범위 안에 남아 있을 때만 런을 실패시킨다.
- 머리 부근 상태등은 프로토타입 판독용이다: 파랑 순찰, 노랑 경계, 주황 조사, 빨강 추격, 흰색 공격 경고, 보라 수색, 청록 복귀.

## 청음자

- 시각 정보는 사용하지 않는다.
- 첫 소음은 해당 위치 조사로 이어진다.
- `RepeatNoiseEscalationWindow` 안에 플레이어가 다시 소음을 내면 추격으로 승격한다.
- 추격 중에도 새 소음이 생길 때만 마지막 위치를 갱신한다. 조용히 방향을 바꾸면 AI가 플레이어를 벽 너머로 따라가지 않는다.
- 플레이어 이동 소음은 `UJMPlayerNoiseEmitterComponent`가 생성하며, 숨은 동안에는 발소리 이벤트를 만들지 않는다.

## 고철지기

- `TerritoryCenter`와 두 개의 반경으로 행동한다.
- `WarningRadius`는 존재를 경고하는 외곽 영역이고 `AggressionRadius`는 침입을 공격으로 승격하는 내부 영역이다.
- `NotifyProtectedObjectDisturbed`를 배터리·고가치 회수 대상의 완료 이벤트와 연결하면 즉시 추격한다.
- 플레이어가 `WarningRadius + LeashExtraDistance` 밖으로 빠지면 추격을 중단하고 영역으로 복귀한다.

## 암전 포식자

- 기본값은 비활성화이며 생성 던전에서는 45초의 예고 시간을 둔 뒤 활성화한다.
- 이후 Power Control 또는 포탈 폐쇄 이벤트에서 `SetBlackoutActive`를 직접 호출하도록 교체할 수 있다.
- `BP_BlackoutSafeLight` 범위 안의 플레이어는 추적하거나 공격할 수 없다.
- 안전 조명은 실제 화면 밝기를 추측하지 않고 명시적인 게임 규칙으로 판정하므로 레벨 조명 변경에도 결과가 안정적이다.

## 사운드

현재 상태 경고음은 `/Engine/EngineSounds/1kSineTonePing`을 낮은 볼륨과 종류별 Pitch로 사용한다. 외부 음원은 아직 사용하지 않았다. 최종 몬스터 음원은 `AlertSound`에 교체하면 되며 행동 규칙과 분리되어 있다.

## 다음 연결 작업

1. 배터리 또는 고가치 회수 완료 시 고철지기의 `NotifyProtectedObjectDisturbed` 호출.
2. Power Control/포탈 폐쇄 상태에서 암전 포식자의 `SetBlackoutActive(true)` 호출.
3. 주요 밝은 방에 `BP_BlackoutSafeLight` 배치.
4. 문 충돌, 물건 낙하, 회수 작업에서 플레이어의 `DungeonNoiseEmitter.ReportDungeonNoise` 호출.
5. 실제 플레이테스트 후 감지 거리, 경고 시간, 추격 속도만 조정하고 상태 규칙은 유지.
