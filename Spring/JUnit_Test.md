#자동화 테스트를 사용하자
- @Test Annotation을 사용한다. Assertion. 사용
- @DisplayName("원하는 이름") : Test 할때 표시할 이름을 표시하는 기능
- 단위 테스트를 잘 써야 Test하는 시간을 줄일수 있다.
- @BeforeEach : 각 테스트가 실행 되기 전에 무조건 실행되는 코드

##TIP
- //given, //when, //then 꼴로 형식 맞추면 편할 듯
- cmd + shift + t 단축키로 Test만들기 Short Cut 가능
- Junit5부터 public을 쓸 필요가 없다. 

##여러 Method들
- assertThat().{isInstanceOf, isEqualTo, etc...} : 같은지 확인하기
- assertThrows(튀어나올 Exception, {하는 행위})
#### isSameAs VS isEqualTo
- isSameAs() : Java에서의 == 인스턴스를 비교
- isEqualTo : Java에서의 Equals랑 같음 (그 Overriding해서 쓰는거 있잖아)