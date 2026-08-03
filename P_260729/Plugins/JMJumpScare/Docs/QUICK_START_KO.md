# 2D JumpScare 빠른 시작

1. 콘텐츠 브라우저에서 `JM JumpScare Definition` Data Asset을 만든다.
2. `Image`에 화면에 띄울 Texture2D를 지정한다.
3. `Image Resolution`에 화면에 표시할 픽셀 크기를 지정한다.
4. `Rise Duration`에 화면 아래에서 중앙까지 올라오는 시간을 지정한다.
5. `Duration`에 이미지 표시 시간을 입력한다.
6. `Jump Scare Sound`에는 이미지 연출 사운드를 지정한다.
7. `Glitch Sound`에는 이미지가 사라진 뒤 재생할 글리치 사운드를 지정한다.
8. 필요하면 `Glitch Duration`과 `Glitch Material`을 조정한다. 기본 Material은 `/Game/Jumpscare/M_Glitch`다.
9. 레벨에 `JM JumpScare Trigger`를 배치하고 `Jump Scare Definition`을 연결한다.

플레이어가 Trigger에 들어오면 이미지는 해당 플레이어의 카메라 화면 위에 전체 화면으로 표시되고,
`Duration`이 끝나면 자동으로 제거된다. 이미지가 표시되는 순간부터 글리치 종료까지
플레이어 이동 입력과 마우스 시점 입력은 잠기며, 종료·취소·실패 시 자동으로 복원된다.
이미지 알파 채널과 `Image Tint`를 사용할 수 있다.

Blueprint에서 직접 실행할 때는 `Play JumpScare` 노드에 Definition만 연결하면 된다.
Anchor와 3D Actor 설정은 더 이상 필요하지 않다.

## 현재 Definition 항목

- `Image`: 표시할 2D Texture
- `Image Tint`: 이미지 색상 및 투명도
- `Image Resolution`: 화면에 표시할 픽셀 크기
- `Rise Duration`: 아래에서 위로 올라오는 시간
- `ZOrder`: 다른 UI보다 앞에 표시할 순서
- `Start Delay`: 표시 전 대기 시간
- `Duration`: 표시 유지 시간
- `Jump Scare Sound`: 함께 재생할 사운드
- `Sound Delay`: 사운드 재생 지연
- `Volume / Pitch Multiplier`: 사운드 조절
- `Glitch Material / Duration`: 종료 후 포스트 프로세스와 유지 시간
- `Glitch Sound`: 포스트 프로세스와 별도로 재생할 사운드
- `Trigger Policy`: 한 번만 또는 반복 실행
