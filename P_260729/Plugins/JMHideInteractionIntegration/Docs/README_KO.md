# JMHideInteractionIntegration

`JMHide`, `JMInteraction`이 필수입니다. `UJMHideInteractableAdapterComponent`는 상호작용 완료를 은신 진입 명령 접수로 번역합니다. 실제 Hidden 완료는 `UJMHideInteractorComponent::OnHiddenEntered`에서 받습니다.

호스트 입력은 `UJMHideInputRouterComponent::RouteHostInteractInput`을 호출할 수 있습니다. 이 플러그인은 Enhanced Input Action 또는 Mapping Context를 등록하지 않습니다.
