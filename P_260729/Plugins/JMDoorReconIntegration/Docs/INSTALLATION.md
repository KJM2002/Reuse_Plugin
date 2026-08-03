# 설치 및 설정

프로젝트 `Plugins` 폴더에 `JMDoor`, `JMRecon`, `JMDoorReconIntegration`을 함께 복사하고 플러그인을 활성화한 뒤 프로젝트 파일을 재생성하여 Editor 타깃을 빌드합니다.

문 Actor/Blueprint에 `JMDoorComponent`와 `JMReconTargetComponent`가 함께 있으면 자동 Adapter가 생성됩니다. 수동 Adapter 추가는 필요하지 않습니다. 자동 부착을 끄려면 **Project Settings > Plugins > JM Door Recon Integration**에서 `bAutoAddDoorAdapter`를 비활성화합니다.

같은 설정 화면에서 전역 문 열림/복원 Blend 시간과 기존에 거의 완전히 열린 문을 거부할 임계값을 바꿀 수 있습니다. 실제 정찰 열림 비율은 `JMReconDefinition.PeekOpenFraction`을 사용합니다.

설치 확인은 `JM.DoorRecon.*` 자동화 테스트와 Editor Development 빌드로 수행합니다.
