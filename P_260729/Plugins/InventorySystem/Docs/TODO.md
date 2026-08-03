# 인벤토리 시스템 작업 목록

## 첫 번째 마일스톤

- [x] Runtime Plugin Descriptor와 Module
- [x] Item Definition 및 Use Effect API
- [x] 스택형 Inventory Component
- [x] 아이템 획득과 버리기 흐름
- [x] UMG 기반 Widget과 UI·입력 조정 컴포넌트
- [x] Inspector Bridge
- [x] 저장용 데이터
- [x] 컴파일 검증
- [x] 스택 및 용량 자동화 테스트
- [x] 설정 문서

## 호스트 프로젝트 에셋 설정

- [ ] `IA_ToggleInventory`를 생성하고 선택한 Input Mapping Context에 추가
- [ ] `UInventoryWidgetBase` 기반 Inventory Widget Blueprint 생성
- [ ] 실제 확인한 프로젝트 에셋을 참조하는 Old Key Item Definition 생성
- [ ] `UJMItemInspectionSubsystem`을 호출하는 Inspector Bridge 지정
- [ ] 테스트 Map에 Pickup Blueprint 배치

## 추후 확장

- 무게 및 소지 용량 정책
- 버릴 수량 선택 UI
- 불러오기 시 Asset Manager를 이용한 ItemId 검색
- Server RPC 검증 및 슬롯 Replication
- 중복 ItemId Editor 검증
- 한 번의 명령으로 Demo Asset을 생성하는 선택적 Editor Module
