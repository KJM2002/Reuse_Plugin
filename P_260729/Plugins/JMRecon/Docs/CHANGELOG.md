# 변경 이력

## 1.1.0

### 추가

- 기존 데이터 호환 기본값이 Listen인 `InitialObservationMode`
- Actor뿐 아니라 ActorComponent가 구현한 `IJMReconTarget` 탐색
- 세션 시작과 종료에 동일한 Target Adapter를 보장하는 계약 참조

### 변경

- 프로젝트 기본 Definition은 중간 Listen 단계 없이 Peek/Observe로 직접 진입
- Game Config 병합 여부와 무관하게 플러그인 기본 Definition을 가리키는 안전한 C++ Soft Reference 기본값

### 호환성 중단

- 없음. 기존 Definition은 계속 Listen으로 시작합니다.

## 1.0.1

### 변경

- Target의 일반 제작 항목을 간소화하고 세부 설정을 고급 항목으로 이동
- 기본 Listen/Peek 카메라 높이를 60cm로 조정

### 수정

- Recon 모드 Bitmask가 Enum 값 `1/2/4`를 그대로 저장하도록 메타데이터 수정
- 기존 잘못 저장된 전체 모드 값 `22`를 런타임에서 호환 처리

## 1.0.0

### 추가

- Tick 없이 동작하는 Target 및 Interactor 컴포넌트
- 데이터 기반 Listen, Peek 및 Peek 전용 Illuminate 동작
- 세션 GUID 예약, 중복 요청 방지, 비동기 전환 검증 및 중앙화된 정리
- 교체 가능한 카메라, 조명, 소음 및 범용 Target Adapter 계약
- 에디터 Anchor/카메라 제한 시각화 및 데이터 검증
- 런타임 자동화 테스트와 이식 가능한 설치 문서

### 호환성 중단

- 없음. 최초 릴리스입니다.
