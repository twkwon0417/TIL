# ComponentScan & Auto DI vs 수동 Bean등록 & 수동 DI
### 자동
- 자동으로 가는 추세이고 자동으로 해도 OCP, DIP를 지킨다. 따라서 특정 경우를 빼고 자동울 쓰자
- 업무 로작 Bean
  - Controller, Service, Repository 등등 비즈니스 요구사항을 개발할 때 추가되거나 변경되는 것들
  - 유사한 패턴이 있어서 문제가 발생하도 어떤 곳에서 문제가 발생 했는지 쉽게 파악 가능하다.
### 수동
- 애플리케이션에 광범위하게 영향을 미치는 기술 지원 객체는 수동 빈으로 등록해서 딱! 설정 정보에 바로 나타나게 하는 것이 유지보수 하기 좋다.
- 기술 지원 Bean
  - 기술적인 문제나 공통 관심사(AOP)를 처리할 떄 사용 됨, 업무 로직을 지원하기 위한 하부 기술이나 공통 기술들이다.
- 비즈니스 로직 중에서 다형성을 적극 활용할 때
  * [Spring_Strategy_Pattern](https://naver.com) 참고
  - 여러 코드를 찾아봐야 하는 가독성의 문제가 있다. 
  - 별도 설정 정보를 만들고 수동으로 등록하자 
  - 자동으로 하려면 파악하기 좋게 특정 패키지에 같이 묶어두는 최소한의 성의를 보이자 
##### 스프링과 스프링 부트가 자동으로 등록하는 수 많은 빈들은 예외 : 의도대로 사용하자