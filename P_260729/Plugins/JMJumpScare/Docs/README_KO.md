---
title: "JMJumpScare"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMJumpScare"
classified_on: 2026-08-19
owners:
  - "JMJumpScare Maintainers"
review_reason: "설치 closure와 사용 절차를 현재 .uplugin·Build.cs·코드와 완전히 재검증하지 않음"
---

# JMJumpScare

## 문서 지도

> 아래 상태는 문서 내용의 검증 수준이다. `ReviewRequired` 문서는 현재 코드·에셋·Editor 절차와 다시 확인하기 전까지 최종 구현 기준으로 사용하지 않는다.

| 분류 | 문서 | 상태 |
|---|---|---|
| Colocated | [Gameplay Tags](../Config/Tags/README.md) | `ReviewRequired` |
| Docs Root | [JMJumpScare 아키텍처](ARCHITECTURE_KO.md) | `ReviewRequired` |
| Docs Root | [Changelog](CHANGELOG.md) | `ReviewRequired` |
| Guides | [통합 가이드](Guides/INTEGRATION_KO.md) | `ReviewRequired` |
| Guides | [2D JumpScare 빠른 시작](Guides/QUICK_START_KO.md) | `ReviewRequired` |


`JMJumpScare`는 플레이어의 카메라 화면 위에 2D 이미지를 잠시 표시하는 Runtime 플러그인이다.
3D Actor Spawn, Anchor, 카메라 이동, FOV, 입력 잠금, Post Process 설정은 필요하지 않다.

## 사용 방법

1. `JM JumpScare Definition` Data Asset을 만든다.
2. `Image`와 `Duration`을 지정한다.
3. 레벨의 `JM JumpScare Trigger`에 Definition을 연결한다.

사운드가 필요하면 `Jump Scare Sound`를 지정한다. 이미지는 알파 채널을 지원하며
`Image Tint`로 색과 투명도를 조절할 수 있다.

Blueprint에서 직접 실행할 때는 `Play 2D JumpScare` 노드에 Definition을 연결한다.
`Target Player`를 비워 두면 첫 번째 로컬 플레이어를 사용한다.

## 실행 흐름

```text
Start Delay
→ 전체 화면 Image 표시 + Started/Impact 이벤트
→ Duration
→ Image 제거 + Exiting/Finished 이벤트
```

실행 중 `Cancel JumpScare`를 호출하면 이미지와 사운드가 즉시 제거되고 Cancelled 이벤트가 발행된다.
동시에 두 개를 실행하면 새 요청은 `AlreadyPlaying`으로 거절된다.

## Definition 항목

- `JumpScare Id`
- `Image`, `Image Tint`, `ZOrder`
- `Start Delay`, `Duration`
- `Jump Scare Sound`, `Sound Delay`, `Volume`, `Pitch`
- `Trigger Policy` (`Once` 또는 `Repeatable`)

자세한 설정 순서는 [QUICK_START_KO.md](Guides/QUICK_START_KO.md)를 참고한다.
