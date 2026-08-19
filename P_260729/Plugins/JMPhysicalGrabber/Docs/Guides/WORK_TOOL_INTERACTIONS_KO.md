---
title: "JM 작살 작업 도구 상호작용 사용법"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMPhysicalGrabber"
classified_on: 2026-08-19
owners:
  - "JMPhysicalGrabber Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# JM 작살 작업 도구 상호작용 사용법

이 문서는 `JMPhysicalGrabber 1.5.0`의 대상 소유형 작살 반응을 Blueprint에서 설정하고 테스트하는 방법을 설명한다. 작살총의 발사체, 외형, 플레이어 그래플 설정은 [HARPOON_GUN_KO.md](HARPOON_GUN_KO.md)를 참고한다.

## 1. 구조와 책임

`UJMHarpoonGunComponent`는 발사, 박힘, 장력 계산, 물리 회수, 안전 복귀만 담당한다. 대상은 `IHarpoonInteractable`을 통해 자신이 어떻게 반응할지 제공한다.

```text
작살 명중
→ 명중 컴포넌트 / 액터 / 액터 컴포넌트에서 IHarpoonInteractable 탐색
→ 대상 Profile 확인
→ 박힘 허용 여부 결정
→ 회수 중 장력 전달
→ 대상이 파손·추출·활성화 등의 결과 결정
```

일반적인 Blueprint 대상은 `JM Harpoon Interactable Component`만 추가하면 된다. 몬스터나 포탈처럼 자체 상태 머신이 필요한 대상은 `IHarpoonInteractable`을 직접 구현할 수 있다.

인터페이스가 없는 물리 대상은 기존 방식대로 질량에 따라 회수된다. 따라서 기존 레벨 액터를 한꺼번에 수정할 필요는 없다.

## 2. 가장 빠른 설치 방법

1. 대상 Actor Blueprint를 연다.
2. 작살이 맞을 Mesh 또는 Collision이 `Block` 충돌을 사용하는지 확인한다.
3. `Components` 패널에서 `JM Harpoon Interactable Component`를 추가한다.
4. 컴포넌트의 `Profile`을 펼쳐 반응과 허용 항목을 설정한다.
5. 필요한 경우 Event Graph에서 컴포넌트 이벤트를 연결한다.

물리적으로 끌 대상은 Mesh를 다음처럼 설정한다.

| 설정 | 권장값 |
|---|---|
| Mobility | `Movable` |
| Simulate Physics | 활성화 |
| Collision Preset | `PhysicsActor` 또는 작살을 Block하는 커스텀 프리셋 |
| Mass | 대상의 실제 무게감에 맞게 설정 |

판자처럼 제자리에서 뜯기기만 하는 대상은 `Simulate Physics`를 켜지 않아도 된다. 대신 `Can Pull`, 해당 반응의 `Can ...`, `Reaction Force`를 올바르게 설정해야 한다.

## 3. Profile 속성

### 허용 항목

| 속성 | 의미 |
|---|---|
| Can Embed | false이면 작살이 박히지 않고 즉시 회수된다. |
| Can Pull | 회수 중 물리 힘 또는 고정 대상 장력 계산을 허용한다. Break/Extract 등 장력 반응에도 필요하다. |
| Can Break | `Break` 완료를 허용한다. |
| Can Extract | `Extract` 완료를 허용한다. |
| Can Activate | `Activate` 완료를 허용한다. |
| Can Affect Creature | `CreaturePart` 완료를 허용한다. |

`Reaction`만 선택하고 대응하는 `Can ...`을 켜지 않으면 완료되지 않는다. 예를 들어 `Reaction=Extract`에는 `Can Pull=true`, `Can Extract=true`가 모두 필요하다.

### 장력과 손상

| 속성 | 의미 |
|---|---|
| Pull Resistance | 1보다 크면 실제 적용 힘과 최대 힘 예산이 감소한다. |
| Reaction Force | 반응 진행에 필요한 최소 장력이다. |
| Reaction Hold Time | 최소 장력을 연속으로 유지해야 하는 시간이다. |
| Fragile Safe Force | 이 힘을 초과하면 화물 Condition이 감소한다. 0이면 파손도 계산을 끈다. |
| Fragile Damage Per Second | 안전 힘을 초과한 비율에 따라 초당 감소할 Condition 계수다. |

기본 작살의 `Max Pull Force`가 `200000`이고 대상의 `Pull Resistance`가 `4`라면 대상에 사용할 수 있는 최대 힘은 약 `50000`이다. 이때 `Reaction Force=75000`으로 설정하면 반응을 완료할 수 없다.

### 소음

| 속성 | 의미 |
|---|---|
| Impact Noise Loudness | 최초 명중 시 한 번 발생하는 소음 값이다. |
| Pull Noise Loudness | 당기는 동안 약 0.25초 간격으로 발생하는 소음 값이다. |

플러그인은 특정 AI 시스템을 참조하지 않는다. `On Harpoon Noise`를 게임의 `Report Noise Event`, AI Perception 또는 별도 소음 Subsystem에 연결한다.

## 4. Reaction 선택

| Reaction | 용도 | 완료 조건 |
|---|---|---|
| None | 박힘만 허용하고 특별한 대상 반응은 사용하지 않는다. | 없음 |
| Pull | 일반 화물, 소음 물체, 포탈 코어처럼 물리적으로 끈다. | 별도 완료 이벤트 없음 |
| Break | 판자, 환풍구, 고정핀 등을 뜯는다. | Can Break + 장력 유지 |
| Extract | 몬스터 부산물이나 샘플을 추출한다. | Can Extract + 장력 유지 |
| Activate | 레버, 밸브, 위험물을 원거리에서 작동한다. | Can Activate + 장력 유지 |
| CreaturePart | 살아있는 몬스터 부위의 행동을 교란한다. | Can Affect Creature + 장력 유지 |
| Anchor | 플레이어 그래플용 앵커 의미를 표현한다. | 대상 회수용이 아니면 Can Pull을 끈다. |

`Pull`은 물체가 플레이어 가까이 왔다는 이유로 `On Reaction Completed`를 발생시키지 않는다. 화물 납품이나 포탈 코어 회수 완료는 도착 Trigger, 수납 Volume 또는 게임별 `IHarpoonInteractable` 구현으로 판정한다.

## 5. Blueprint 이벤트 연결

### On Reaction Completed

`Break`, `Extract`, `Activate`, `CreaturePart`가 완료되거나 깨지기 쉬운 화물의 Condition이 0이 될 때 호출된다.

권장 흐름:

```text
On Reaction Completed
→ Switch on EJMHarpoonReaction
  → Break: Collision 끄기, Mesh 숨기기, 파편 재생
  → Extract: 아이템 지급, 추출 부위 숨기기
  → Activate: 레버/문/함정 상태 변경
  → CreaturePart: 몬스터 행동 교란 요청
```

`Release On Reaction Complete`가 true이면 완료 직후 작살이 대상에서 분리되어 돌아온다. false이면 완료 이벤트 이후에도 현재 작살의 당김 수명주기가 계속된다.

### On Condition Changed

깨지기 쉬운 화물의 현재 Condition을 `1.0 → 0.0` 범위로 전달한다.

활용 예:

- Material 파손 정도 변경
- 의뢰품 가치 감소
- UI 경고 표시
- 0에서 파손 Mesh 또는 파티클 표시

현재 Condition 감소는 작살의 회수 장력만 계산한다. 벽 충돌이나 낙하 충격으로 인한 손상은 대상 Blueprint의 Hit 이벤트에서 별도로 처리한다.

### On Harpoon Noise

다음 값을 전달한다.

- `Location`: 명중 또는 현재 당김 지점
- `Loudness`: Profile에서 지정한 값
- `From Pull`: 지속 당김 소음이면 true, 최초 충돌이면 false

초기 확인 단계에서는 `Print String`에 연결하고, 이후 AI 소음 API로 교체하는 것이 좋다.

## 6. Vertical Slice 권장 설정

수치는 기본 `Max Pull Force=200000`을 기준으로 한 시작점이며 레벨 크기와 물리 Mass에 맞춰 조절한다.

### A. 일반 화물

```text
Reaction              Pull
Can Embed             true
Can Pull              true
Pull Resistance       1.0
Simulate Physics      true
Mass                  5 / 75 / 300 kg 비교
```

질량이 증가할수록 같은 힘에서 가속이 느려지는지 확인한다.

### B. 깨지기 쉬운 화물

```text
Reaction                  Pull
Can Pull                  true
Fragile Safe Force        30000
Fragile Damage Per Second 1.0
```

`On Condition Changed`에서 상태를 표시한다. 가까운 곳에서 회수할 때와 긴 케이블을 강하게 당길 때를 비교한다.

### C. 몬스터 부산물

```text
Reaction              Extract
Can Pull              true
Can Extract           true
Reaction Force        50000
Reaction Hold Time    0.3
```

`On Reaction Completed → Extract`에서 아이템 지급과 부위 제거를 처리한다.

### D. 판자 또는 환풍구

```text
Reaction              Break
Can Pull              true
Can Break             true
Reaction Force        50000
Reaction Hold Time    0.4
Simulate Physics      false 가능
```

완료 이벤트에서 Collision을 끄고 파손 연출을 실행한다.

### E. 금속 소음원

```text
Reaction               Pull
Can Pull               true
Impact Noise Loudness  1.0
Pull Noise Loudness    0.7
```

먼저 `On Harpoon Noise → Print String`으로 확인한 뒤 AI에 연결한다.

### F. 포탈 코어

```text
Reaction               Pull
Can Pull               true
Pull Resistance        2.0
Impact Noise Loudness  1.0
Pull Noise Loudness    1.0
Simulate Physics       true
Mass                   200~500 kg
```

코어 도착 여부는 포탈 주변 Trigger 또는 회수 Volume에서 판정한다. Resistance를 높이면 `Reaction Force` 기반 기능의 도달 가능 힘도 낮아진다는 점에 주의한다.

## 7. 직접 인터페이스를 구현해야 하는 경우

다음 상황은 Actor Blueprint 또는 C++ 클래스에서 `IHarpoonInteractable`을 직접 구현하는 편이 좋다.

- 몬스터 부위마다 서로 다른 Profile이 필요한 경우
- 체력, 경직, 공격 상태를 확인해야 하는 경우
- 포탈 코어가 퀘스트 상태에 따라 박힘을 거부해야 하는 경우
- 레버 각도나 밸브 회전량처럼 연속 상태가 필요한 경우
- 서버 권한 검증이나 저장 데이터가 필요한 경우

주요 콜백:

| 함수 | 호출 시점 |
|---|---|
| Get Harpoon Interaction Profile | 명중 직후 박힘 여부를 결정하기 전 |
| On Harpoon Embedded | 대상에 정상적으로 박힌 직후 |
| On Harpoon Pull Started | 플레이어가 회수를 시작할 때 |
| On Harpoon Pull Updated | 회수 중 매 프레임 장력 정보 전달 |
| On Harpoon Interaction Ended | 완료, 분리, 리셋, 타임아웃 시 |

명중 프리미티브가 인터페이스를 구현하면 가장 먼저 사용하고, 그다음 Actor, 마지막으로 Actor에 부착된 인터페이스 컴포넌트를 찾는다. 일반 Actor에는 `JM Harpoon Interactable Component`를 하나만 두는 것을 권장한다. 부위별 반응이 필요하면 Hit Context의 컴포넌트/본 정보를 사용하는 Actor 구현이나 인터페이스를 구현한 커스텀 프리미티브를 사용한다.

## 8. 테스트 절차

### 에디터 Smoke Test

1. 5kg, 75kg, 300kg 물리 화물을 나란히 배치한다.
2. Pull 반응으로 각각 회수해 질량 차이를 확인한다.
3. Fragile 화물의 Condition을 화면에 출력한다.
4. 고정 판자에 Break를 설정하고 실제로 장력이 누적되는지 확인한다.
5. Extract 대상에서 지정 시간 후 완료 이벤트가 한 번만 발생하는지 확인한다.
6. 금속통의 충돌 소음과 지속 당김 소음을 구분해 확인한다.
7. 회수 중 대상을 Destroy해도 작살이 안전하게 돌아오는지 확인한다.

### 자동화 테스트

PowerShell에서 실행한다.

```powershell
& 'C:\Program Files\Epic Games\UE_5.7\Engine\Binaries\Win64\UnrealEditor-Cmd.exe' `
  'D:\UE5_Reuse_Plugin\Reuse_Plugin\P_260729\P_060715.uproject' `
  -NoSplash -NullRHI -Unattended -NoSound `
  -DisablePlugins=Fab `
  -ExecCmds='Automation RunTests JM.PhysicalGrabber' `
  -TestExit='Automation Test Queue Empty' `
  -log
```

현재 테스트:

- `JM.PhysicalGrabber.Interaction.ExtractThreshold`
- `JM.PhysicalGrabber.Interaction.FragileCargoBreaks`
- `JM.PhysicalGrabber.Interaction.SessionReset`

결과는 프로젝트의 `Saved/Logs/P_060715.log`에서 `Result={Success}`로 확인한다.

## 9. 문제 해결

### 작살이 박히지 않는다

- 대상 Collision이 작살 발사체 채널을 `Block`하는지 확인한다.
- `Can Embed`가 true인지 확인한다.
- 작살이 플레이어 소유 Actor 자신을 맞히고 있지 않은지 확인한다.

### Break 또는 Extract가 완료되지 않는다

- `Can Pull`과 반응별 `Can Break/Extract/...`를 모두 확인한다.
- `Reaction Force`가 대상의 실제 최대 힘보다 낮은지 확인한다.
- `Pull Resistance`를 너무 높이지 않았는지 확인한다.
- `Reaction Hold Time` 동안 장력이 유지되는 거리인지 확인한다.

### 물체가 움직이지 않는다

- 물리 회수 대상이라면 `Mobility=Movable`, `Simulate Physics=true`인지 확인한다.
- Mass와 Pull Resistance가 지나치게 높지 않은지 확인한다.
- 고정 장애물은 움직이는 대신 Break/Extract 같은 장력 반응만 완료한다.

### 완료 이벤트가 오지 않는다

- `Reaction=Pull`은 완료 이벤트를 발생시키지 않는다.
- `Release On Reaction Complete`는 완료 이벤트 발생 여부가 아니라 완료 후 작살 분리 여부를 제어한다.
- Event Graph에서 올바른 컴포넌트 인스턴스의 이벤트를 연결했는지 확인한다.

### 소음이 AI에 전달되지 않는다

- 이 플러그인의 소음 값은 범용 이벤트이며 AI에 자동 등록되지 않는다.
- `On Harpoon Noise`를 프로젝트의 AI Perception 또는 소음 시스템에 연결해야 한다.

## 10. 현재 범위

- 상호작용 상태는 로컬·일시적이며 서버 권한 멀티플레이 복제는 제공하지 않는다.
- Condition과 반응 완료 여부는 SaveGame에 자동 저장되지 않는다.
- 인벤토리 지급, 몬스터 상태, 문 상태, 포탈 상태는 게임 또는 별도 Integration 계층이 소유한다.
- `Pull` 대상의 목적지 도착 판정은 Trigger/Volume 또는 게임별 구현이 담당한다.
- 플러그인은 프로젝트 전용 Actor와 `/Game` 에셋을 직접 참조하지 않는다.
