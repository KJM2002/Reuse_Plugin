---
title: "Cancel / ForceExit 정책"
status: ReviewRequired
authority: Supporting
scope: "Plugin: JMHide"
classified_on: 2026-08-19
owners:
  - "JMHide Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Public API·설정·런타임 계약과 재대조하지 않음"
---

# Cancel / ForceExit 정책

| 현재 Phase | Cancel 결과 | Player | Mechanism | Spot |
|---|---|---|---|---|
| Reserving/PreparingEnter/Opening/Entering/ClosingAfterEnter | 진입 전으로 rollback | Snapshot 조건부 복원 | Closed authored pose 복원 | 예약 해제 |
| Hidden | 명령 거부, Hidden 유지 | Hidden | Closed | 점유 유지 |
| PreparingExit/OpeningForExit/Exiting/ClosingAfterExit | Hidden으로 rollback | Occupant anchor/Hidden 재적용 | Closed authored pose 복원 | 점유 유지 |

`ForceExit`은 Cancel과 다르다. Hidden 세션을 종료하며 설정에 따라 막힌 Exit를 무시하고 Primary Exit를 사용할 수 있다. Spot 또는 Participant 파괴 시에는 안전한 Cleanup을 우선한다.
