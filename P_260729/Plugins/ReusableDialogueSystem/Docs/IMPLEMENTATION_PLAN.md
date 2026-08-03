# 구현 계획

## 프로젝트 기준 상태

- Unreal Engine 5.7 (`EngineAssociation: 5.7`)
- `JaeminFramework` 단일 Runtime 게임 모듈
- Build Settings V6 및 Unreal 5.7 Include Order 사용
- 생성된 빌드 파일 기준 C++20 Toolchain 사용
- 게임 프로젝트에는 Enhanced Input이 활성화되어 있지만 플러그인의 필수 의존성에서는 제외
- 기존 PlayerController, HUD, UMG 또는 Dialogue 구현 없음
- 기존 콘텐츠는 빈 Map 하나
- 변경 전 `JaeminFrameworkEditor Win64 Development` 기준 빌드 성공

## 첫 번째 마일스톤

플러그인은 하나의 Runtime Module로 구성합니다. Public 데이터와 Blueprint API는 다음 모듈에만 의존합니다.

- Core
- CoreUObject
- Engine
- UMG
- Slate / SlateCore
- InputCore
- GameplayTags
- DeveloperSettings

게임 모듈인 `JaeminFramework`에는 의존하지 않습니다.

구현 순서:

1. Plugin, Runtime Module 및 전용 로그 카테고리
2. Enum, Line/History 구조체, Primary Data Asset, Developer Settings
3. Word/Character Tokenizer와 순수 로직 테스트
4. Widget 기반 클래스와 기본 입력 연결
5. GameInstance Subsystem 상태 머신, Timer, Audio 및 History
6. 컴파일, Automation Test 시도, 사용 문서 작성

## 위험 요소와 대응

- `.uasset`을 안전하게 직접 생성할 수 없으므로 Widget Blueprint와 샘플 Data Asset은 에디터에서 제작합니다.
- 프로젝트마다 입력 계층 구조가 다르므로 Enhanced Input을 필수 의존성으로 두지 않고 `AdvanceDialogue()` 공개 API를 제공합니다.
- Modal 종료 시 마우스 커서 상태는 복구하지만 프로젝트 전용 입력 스택 전체를 일반적으로 복원할 수는 없습니다. 복잡한 입력 프로젝트에는 Overlay/Cinematic 모드를 제공합니다.
- Character 모드는 UTF-16 surrogate pair를 보존합니다. 결합 문자를 포함한 완전한 Unicode grapheme 분리는 후속 확장 항목입니다.

## 컴파일 검증 순서

1. 변경 전 Editor Target 기준 빌드
2. Plugin 및 UHT 타입 생성 후 빌드
3. 엔진 헤더 이름 충돌과 UE 5.7 API 차이 수정
4. 최종 Editor Target 빌드
5. Tokenizer Automation Test 실행
6. 요구사항 체크리스트 기반 자체 검토

