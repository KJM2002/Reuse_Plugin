---
title: "변경 이력"
status: ReviewRequired
authority: Historical
scope: "Plugin: JMDoorReconIntegration"
classified_on: 2026-08-19
owners:
  - "JMDoorReconIntegration Maintainers"
review_reason: "릴리스 및 Git 이력과 변경 항목의 누락 여부를 재대조하지 않음"
---

# 변경 이력

## 1.0.0

### 추가

- `JMDoorComponent` + `JMReconTargetComponent` Actor 자동 Adapter
- ActorComponent 기반 `IJMReconTarget` 계약
- 회전문/슬라이딩 문 세션 전용 임시 Pose와 정확한 Transform 복원
- Locked, Moving, Broken, Jammed, Blocked 및 외부 상태 변경 안전 처리
- Project Settings 기본값과 Editor 자동화 테스트

### 변경

- 정상 Recon 종료 시 문 복원 시간을 Definition의 `ExitingDuration`과 동기화

### 호환성 중단

- 없음. 최초 릴리스입니다.
