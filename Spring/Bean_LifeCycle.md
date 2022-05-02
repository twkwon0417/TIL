# Bean Life Cycle
## Spring Bean의 Life Cycle
- 스프링 컨테이너 생성 -> 스프링 빈 생성 -> 의존관계 주입 -> 초기화 콜백 -> 사용 -> 소멸 전 콜백 -> 스프링 종료
  - 초기화 콜백 : 빈이 생성되고, 빈이 의존관계 주입이 완료된 후 호출
  - 소멸전 콜백 : 빈이 소멸되기 직전에 호출
- 객체 생성 -> 의존관계 주입 으로 돌아가기 때문에 초기화 작업은 의존관계 주입이 모두 완료된 후에 호출 되어야 한다.
  - ~~~java
    @Bean
      public NetworkClient networkClient() {
          NetworkClient networkClient = new NetworkClient();
          networkClient.setUrl("http://hello-spring.dev");
          return networkClient;
      }
    ~~~
    이런거 테스트 하면 url이 초기화 되지않고 null로 나온다는 말이다.
##### 객체의 생성과 초기화를 분리하자
- 생성자는 필수 정보(파라미터)를 받고, 메모리를 할당해서 객체를 생성하는 책임을 가진다. 반면에 초기화는
  이렇게 생성된 값들을 활용해서 외부 커넥션을 연결하는등 무거운 동작을 수행한다.
  따라서 생성자 안에서 무거운 초기화 작업을 함께 하는 것 보다는 객체를 생성하는 부분과 초기화 하는 부분을 명확하게 나누는 것이 유지보수 관점에서 좋다. 물론 초기화 작업이 내부 값들만 약간 변경하는
  정도로 단순한 경우에는 생성자에서 한번에 다 처리하는게 더 나을 수 있다.

## Bean Life Cycle Call Back
스프링은 크게 3가지 방법으로 Bean 생명주기 콜백을 지원한다.<br>
마지막 방법을 애용하나 마지막 방법도 단점이 있으니 상황에 맞춰 쓰자

- ### InitializingBean, DisposableBean Interface
  - 객체에 위 두 Interface를 Implement해서 afterPropertiesSet(), destroy() override 하자
  - 단점
    - 두 Interface는 Spring전용이라 코드가 해당 인터페이스에 의존한다.
    - 초기화, 소명 Method의 이름을 변경할 수 없다.
    - 외부 라이브러리와 같이 내가 코드를 수정할수 없는 경우 사용이 불가 하다.

- ### @Bean Annotation의 Field에 initMethod, destroyMethod를 부여해주자.
  - @Bean(initMethod = "init", destroyMethod = "close") 이런식으로 초기화
  - 특징
    - 매서드 이름을 자유롭게 줄 수 있다.
    - 스프링 코드에 의존하지 않는다. Annotation까지는 OK입니다.~
    - 설정 정보에서 사용되기 때문에 외부 라이브러리에서도 사용 가능하다.
    - @Bean의 destroyMethod는 기본값이 (inferred)로 등록되어 있다.
    - (inferred)는 이름이 close, shutdown인 Method를 찾아서 호출해주는 기증이다.
    - 대부분의 라이브러리는 이름이 close, shutdown인 종료 Method를 주로 사용해 직접 Spring Bean으로 등록하면 DestroyMehtod는 따로 설정 해 주지 않아도 된다.
    - 추론 기능을 사용하기 싫으면 destroyMethod="" 와 같이 빈 공백으로 설정하자
  
- ### @PostConstruct, @PreDestroy Annotation
  - 객체의 init, destroy가 되는 Method 위에 @PostConstruct, @PreDestroy Annotation을 붙이자
  - 특징
    - 스프링이 아닌 다른 컨테이너에서도 동작한다. (javax package에 있음)
    - Component Scan과 잘 어올린다.
    - Interface를 활용한 방법과 마찬가지로 코드를 변경하지 못하는 외부 라이브러리를 사용하는 경우에는 적용 할 수 없다.
