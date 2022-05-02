# Bean Scope

## Bean Scope의 종류
- Singleton : 기본 스코프, 컨테이너의 시작과 종료까지 유지된다.
- Prototype : Bean의 생성과 의존관계 주입까지만 관여하고 더는 관리하지 않는 짧은 범의의 스코프
- Web 관련 스코프
  - Request : Web 요청이 들어오고 나갈때 까지 유지되는 스코프
  - Session : Web 세션이 생성되고 종료될 때 까지 유지되는 스코프
  - Application : Web의 서블릿 컨텍스트와 같은 범위로 유지되는 스코프
#### Bean Scope 지정하기
- Component Scan 자동 등록 : @Component Annotation위에 @Scope("prototype") 과 같이 붙인다.
- 수동 등록 : @Bean 위에 @Scope("prototype") 과 같이 붙인다.

### Prototype Scope
- Singleton과 달리 Prototype Scope인 Bean을 조회 할 때마다 새로운 인스턴스를 생성해서 준다.
- 의존관계 주입, 초기화까지만 처리한다. -> @PreDestroy와 같은 destroy Method가 실행되지 않는다.
#### Singleton안에서 Prototype Scope 이용하기
- Singleton과 함께 사용 할 때 **Prototype Scope인 Bean을 조회 할 때 마다** 새로운 인스턴스가 반환된다는 것을 주의 하자.
- 해결 방법
- DL (Dependency Lookup) : 직접 필요한 의존관계를 찾는 짓
  - ApplicationContext를 Singleton Bean의 Field로 넣어서 특정 Method를 실행하면 ac에서 새로운 Prototype Bean을 공급하게 할수도 있다.
    - ac 전체를 주입받으면 Spring Container에 종속적이게 되고 단위 테스트로 어려워 지고 절대 선호 하지 않는다.
    - 지정한 Prototype Bean을 Container에서 대신 찾아주는 기능이면 충분해!
  - 