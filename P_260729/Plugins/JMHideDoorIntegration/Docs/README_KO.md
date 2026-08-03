# JMHideDoorIntegration

`JMHide`, `JMDoor`가 필수입니다. `UJMHideDoorMechanismComponent`는 JMDoor 공개 Command API와 상태 Delegate를 JMHide의 비동기 Mechanism 계약으로 변환합니다.

같은 Door Mesh를 `UJMHideSimplePanelMechanismComponent`에도 등록하지 마십시오. Spot Validation은 Adapter와 Simple Panel이 같은 Scene Component를 소유하면 오류를 보고합니다.
