---
title: "설치 및 이식성"
status: ReviewRequired
authority: Guide
scope: "Plugin: JMRecon"
classified_on: 2026-08-19
owners:
  - "JMRecon Maintainers"
review_reason: "문서 구조만 정비했으며 현재 Editor 절차·에셋 경로·설정과 재검증하지 않음"
---

# 설치 및 이식성

다음 폴더와 파일을 복사합니다.

```text
JMRecon/
  JMRecon.uplugin
  Source/
  Config/
  Content/   (기본 Data Asset을 포함하는 경우)
  Docs/
```

`Binaries`, `Intermediate` 또는 IDE 파일은 배포하지 않습니다. 이 플러그인은 `/Game` 참조가 없으며 필수로 요구되는 다른 플러그인도 없습니다. 대상 프로젝트의 Unreal Engine 버전에 맞춰 빌드합니다.

설치 후 `JM.Recon.*` 필터로 에디터 자동화 테스트를 실행합니다. 릴리스 번들은 깨끗한 C++ 프로젝트에서 Development Editor 빌드와 Shipping 타깃도 검증해야 합니다.
