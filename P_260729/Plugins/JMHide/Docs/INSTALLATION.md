# JMHide 설치

## Core만 사용

`Plugins/JMHide` 폴더를 복사하고 플러그인을 활성화합니다. 필수 JM 플러그인은 없습니다.

## 선택 연동

- JMInteraction 사용: `JMHide`, `JMInteraction`, `JMGameplayEvent`, `JMHideInteractionIntegration` 폴더가 필요합니다.
- JMDoor 사용: `JMHide`, `JMDoor`, `JMGameplayEvent`, `JMHideDoorIntegration` 폴더가 필요합니다.

두 Integration이 없어도 Core의 직접 API와 Delegate는 정상 동작합니다. 플러그인은 호스트 `/Game` 콘텐츠, Character 클래스, 입력 Mapping 또는 HUD를 참조하지 않습니다.
