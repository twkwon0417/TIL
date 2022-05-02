# Custom Annotation 만들기
- Java Class 생성에서 @Annotation을 선택해서 만들 수 있다.
- Annotation은 상속이라는 개념이 없고 여러 Annotation을 모아서 사용하는 것 뿐
- 기존 Annotation을 기반으로 새로운 거 만들려면 기존 Annotation 정보 긁어와서 수정하자
- @Qualifier 기반 Annotation을 만들어서 @Qualifier의 Field를 잘못 적어도 컴파일시 타입 체크가 되게 만들 수 있다.
- 특별한 이유없이 새로 만들지 말자, 더 복잡해짐