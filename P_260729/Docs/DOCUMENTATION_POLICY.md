---
title: P_260729 문서 관리 정책
status: Current
authority: Canonical
scope: Documentation
last_verified: 2026-08-20
verified_against: docs-layout-and-plugin-docs-2026-08-20
owners:
  - Project Documentation
related:
  - README.md
---

# P_260729 문서 관리 정책

## 1. 목적

문서의 위치, 현재성, 권위를 파일명이나 수정 시각만으로 추측하지 않게 한다. 모든 문서는 “어디에 있는가”, “현재 구현과 일치하는가”, “충돌 시 기준인가”, “누가 다시 검증해야 하는가”를 명시한다.

## 2. 상태

| `status` | 의미 | 사용 규칙 |
|---|---|---|
| `Current` | 명시된 기준과 검증 또는 검토된 현재 문서 | `last_verified` 또는 `last_reviewed` 필수 |
| `Draft` | 작성 중인 초안 | 구현의 현재 기준으로 인용 금지 |
| `ReviewRequired` | 내용은 유용하지만 현재 코드/에셋과 재검증 필요 | `review_reason` 필수 |
| `Superseded` | 다른 문서가 대체함 | `superseded_by` 필수, Archive 이동 대상 |
| `Archived` | 역사 기록 | 현재 설계/절차로 사용 금지 |

Git 수정 시각은 상태 판정 근거가 아니다. 오탈자 수정은 `last_verified`를 갱신하지 않는다.

## 3. 권위

| `authority` | 의미 |
|---|---|
| `Canonical` | 충돌 시 우선하는 현재 기준 |
| `Supporting` | Canonical 문서를 보충하는 설명 |
| `Guide` | 설치, 저작, 테스트 같은 실행 절차 |
| `Plan` | 미래 설계·백로그이며 현재 구현이 아님 |
| `Historical` | 과거 결정과 결과를 보존하는 기록 |

`Current/Plan`은 “계획 문서 자체가 현재 관리되고 있다”는 뜻이지 계획이 구현됐다는 뜻이 아니다.

## 4. 필수 메타데이터

모든 프로젝트 `Docs` 문서와 Plugin Markdown은 파일 첫 줄부터 YAML front matter를 가진다. 단, 도구가 직접 읽는 `Plugins/AGENTS.md`는 실행 지침 형식을 보존하기 위해 검사에서 제외한다.

```yaml
---
title: 문서 제목
status: Current
authority: Canonical
scope: Project
last_verified: 2026-08-19
verified_against: "<Git commit SHA 또는 명시적 working-tree 기준>"
owners:
  - Project Architecture
related:
  - RELATED_DOCUMENT.md
---
```

추가 필드:

- `last_reviewed`: 코드 검증이 아니라 내용/계획을 검토한 날짜
- `classified_on`: 기존 문서를 새 분류 체계에 편입한 날짜. 내용 검증 날짜가 아니다.
- `review_reason`: `ReviewRequired`인 이유
- `based_on`: 계획이 근거로 삼는 문서
- `superseded_by`: 대체 문서 경로
- `supersedes`: 이 문서가 대체한 문서 목록

## 5. 검증 기준

### 코드·설정 설명

- `last_verified`와 `verified_against`를 기록한다.
- `.uplugin`, `Build.cs`, Public API, 실제 구현, Config 순으로 검증한다.
- 기준 코드가 바뀌면 관련 문서를 같은 변경에서 갱신하거나 `ReviewRequired`로 내린다.

### 디자인·백로그·개선 계획

- `last_reviewed`를 기록한다.
- 구현 여부와 계획 상태를 혼합하지 않는다.
- 완료된 작업은 현재 구조 문서에 반영한 뒤 계획 항목을 완료/Archive 처리한다.

### 가이드·플레이테스트

- 실제 Editor에서 절차를 수행한 경우에만 `Current`로 올린다.
- 맵, 입력, Asset path, UI가 바뀌면 `ReviewRequired`로 내린다.

## 6. 문서 배치

| 디렉터리 | 허용 문서 |
|---|---|
| `Architecture` | 현재 구조, dependency, 이벤트, 개선 계획 |
| `Study` | 현재 프로젝트의 실제 코드를 근거로 한 챕터형 학습 교재 |
| `Design` | 게임 경험과 콘텐츠 설계 |
| `Systems` | 시스템 동작과 프로젝트 저작 가이드 |
| `Testing` | 테스트 절차와 검증 결과 |
| `Production` | 백로그, 일정, 제작 범위 |
| `Decisions` | ADR 형식의 장기 설계 결정 |
| `Archive` | 대체/종료된 역사 문서 |
| `Tools` | 문서 구조·링크 검사 도구 |

Plugin의 설치·API·개별 설계 문서는 Plugin 폴더 안에 둔다. 루트 Docs는 전체 프로젝트 관점만 소유한다.

`Study` 문서는 일반적인 엔진 설명을 독립적으로 복제하지 않는다. 실제 파일·클래스·함수를 근거로 설명하고, 코드상 확인 가능한 사실과 설계 의도 추론을 분리한다. 기준 코드가 바뀌면 해당 챕터를 다시 검증하거나 `ReviewRequired`로 전환한다.

## 7. Plugin Docs 표준

```text
Plugins/JMFeature/Docs/
├─ README.md
├─ ARCHITECTURE.md
├─ CHANGELOG.md
├─ Guides/
├─ Reference/
├─ Testing/
├─ Decisions/
├─ Plans/
└─ Archive/
```

- `README` 또는 `README_KO`: Plugin 문서 진입점, 버전, 최소 설치 closure
- `ARCHITECTURE`: 현재 구현만 설명하는 Canonical 문서
- `CHANGELOG`: 시간 순서 변경 기록
- `Guides`: 설치와 사용 절차
- `Reference`: API, Tag, Config, Save 계약
- `Testing`: 자동화·Editor·회귀 테스트 절차와 결과
- `Plans`: 미구현 계획
- `Archive`: 대체된 계획/가이드

Plugin 루트 `README.md`가 이미 배포·Marketplace 진입점으로 사용되면 유지할 수 있다. 이 경우 Plugin `Docs`와 양방향 링크를 제공한다. 빈 분류 디렉터리는 만들지 않는다.

Plugin 문서 재구성은 Plugin 단위로 수행하고 공개 링크를 모두 갱신한다. 분류만 완료하고 현재 코드·에셋·Editor 절차를 다시 검증하지 않았다면 `Current`로 올리지 않고 `ReviewRequired` 또는 `Draft`로 둔다.

## 8. ADR 규칙

되돌리기 어렵거나 여러 Plugin에 영향을 주는 결정은 `Decisions/ADR-NNNN-짧은-제목.md`로 기록한다.

필수 항목:

1. 상태
2. 배경
3. 결정
4. 고려한 대안
5. 결과와 제약
6. 관련 코드/문서

ADR은 구현 세부 설명을 대체하지 않는다. 결정 이유를 보존한다.

## 9. Archive 규칙

- Git 이력이 있다는 이유로 모든 낡은 문서를 삭제하지는 않는다.
- 현재 문서와 혼동될 가능성이 있으면 `Archive`로 이동한다.
- 원문 상단을 `Archived` 또는 `Superseded`로 바꾸고 대체 문서를 연결한다.
- README/분류 인덱스의 현재 문서 표에서는 제거하고 Archive 표에 등록한다.
- 외부에서 사용된 경로라면 한 릴리스 동안 이동 안내 stub을 둘 수 있다.

## 10. 갱신 트리거

다음 변경은 관련 문서 갱신 또는 `ReviewRequired` 전환을 요구한다.

- Plugin/Module 추가·삭제·이름·dependency 변경
- Public Interface/Component/Subsystem 변경
- GameplayTag, Event Payload, Delegate 흐름 변경
- Config key/default, Asset path, 입력, 맵 변경
- Save version과 migration 변경
- Integration 자동 부착/복구 정책 변경
- 테스트 절차나 완료 조건 변경

## 11. 변경 완료 조건

- 새/이동 문서가 `Docs/README.md` 또는 분류 README에 등록됨
- 메타데이터 상태와 본문 설명이 모순되지 않음
- 상대 Markdown 링크가 유효함
- 대체 문서와 Archive 관계가 연결됨
- [`Tools/Validate-Docs.ps1`](Tools/Validate-Docs.ps1) 통과

검증 도구는 기본적으로 프로젝트 `Docs`와 `Plugins` 아래 Markdown을 함께 검사한다. `Plugins/AGENTS.md`만 명시적으로 제외한다.
