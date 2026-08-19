---
title: Testing 문서 안내
status: Current
authority: Guide
scope: Testing
last_reviewed: 2026-08-20
verified_against: working-tree-runtime-safety-audit-2026-08-20
owners:
  - QA
related:
  - ../README.md
---

# Testing 문서 안내

- [RUNTIME_SAFETY_AUDIT_KO.md](RUNTIME_SAFETY_AUDIT_KO.md): 전체 C++의 UObject·GC·delegate·timer·world·PIE·replication 잠재 버그 정적 감사 (`Current`)
- [PROTOTYPE_PLAYTEST_KO.md](PROTOTYPE_PLAYTEST_KO.md): 최소 프로토타입 수동 플레이테스트 절차 (`ReviewRequired`)

정적 감사의 `Current`는 명시된 working tree와 코드 경로를 다시 대조했다는 뜻이며 런타임 재현 완료를 뜻하지 않는다. 플레이테스트 가이드가 `Current`가 되려면 실제 Editor에서 전체 절차를 다시 수행하고 기준 commit을 기록해야 한다.
