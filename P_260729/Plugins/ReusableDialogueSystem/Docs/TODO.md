# 후속 구현 목록

## Dialogue 기능

- Queue 정책과 요청 우선순위
- 선택지
- 조건 분기
- Dialogue Graph
- Auto Mode
- 이미 읽은 대사 Skip
- Voice 길이 기반 자동 진행
- Sequencer 연동

## 텍스트와 현지화

- 결합 문자를 포함하는 완전한 Unicode grapheme cluster 분할
- String Table 기반 제작 예시
- 현지화 Pipeline 문서와 테스트
- 언어별 문장부호 지연 정책

## UI와 저장

- Dialogue Backlog Widget
- History 저장과 불러오기
- 대화 재생 완료 상태 저장
- 프로젝트 저장 시스템과 연결할 Save Interface

## 입력 확장

- 기본 입력 Key 목록을 Project Settings에서 변경하는 기능
- 프로젝트 전용 입력 Stack을 연결하는 선택적 Interface
- CommonUI 선택 연동 모듈

## 검증과 Editor 기능

- Runtime Module과 분리된 Editor Module
- Sequence와 Speaker Profile의 `IsDataValid` 검증
- Line ID 중복 검사
- 잘못된 Auto Advance 조합 검사
- Widget 필수 BindWidget 이름 안내 도구
- Fab 플러그인 Headless 시작 문제를 피할 수 있는 환경에서 Automation Test 재실행

