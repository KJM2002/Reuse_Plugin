---
title: "휴대용 설치와 압축"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMDoor"
classified_on: 2026-08-19
owners:
  - "JMDoor Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 휴대용 설치와 압축

## 배포 포함

```text
JMDoor/
├─ JMDoor.uplugin
├─ Source/
├─ Content/
├─ Config/
├─ Docs/
└─ README.md
```

## 배포 제외

```text
Binaries/
Intermediate/
Saved/
DerivedDataCache/
```

`JMDoor`는 다른 JM 플러그인 없이 단독 복사할 수 있습니다. 대상은 Unreal Engine 5.7 C++ 프로젝트입니다.

JM 상호작용과 Inventory 열쇠까지 포함한 설치 단위는 다음 네 폴더입니다.

```text
JMDoor/
ItemInspector/
InventorySystem/
JMDoorGameplayIntegration/
```

## 설치 후 검증

1. 프로젝트 파일 재생성
2. Editor Development 빌드
3. Plugin Content 표시
4. `L_JMDoorDemo` 열기
5. 단독 설치면 게임용 Interaction 연결, 통합 설치면 Character에 `JMDoorInventoryAgentComponent` 추가

`Content/Tests`는 Editor 검증 자료입니다. 제품 Cook 목록에 Functional Test 맵을 넣지 마십시오. Demo Map만 패키지 예제로 사용합니다.
