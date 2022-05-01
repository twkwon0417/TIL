# 설정코드 없이 Spring Setting 하기
## Component Scan
- Spring(ApplicationContext)가 있어야 Component Scan이 작동한다. ApplicationContext가 본인의 스프링 컨테이너에 등록할 빈을 찾으려고 ComponentScan을 실행하는 느낌~
- @Component가 붙은 클래스를 찾아 다 Spring Bean을 등록 시킨다.
- @Component, @Controlloer, @Service, @Repository, @Configuration Annotation도 CompoentScan 된다. 각 Annotation 열어보면 @Component를 포함하고 있다.
- Spring Bean의 기본 이름은 앞글자만 소문자인 클래스명
- @Conponent({"원하는이름"})으로 수동으로 이름 설정 가능
- 탐색위치 설정
  - Default : @ComponentScan이 붙은 설정 정보 클래스의 패키지가 시작 위치
  - Aruguments로 디테일한 설정 가능
    - basePackages : 해당 패키지 포함 하위 패키지 스캔
    - basePackageClasses : 해당 클래스의 패키지가 basePackages
  - 이왕이면 설정 정보 클래스의 위치를 프로젝트 최상단에 두고 Default로 설정해 쓰자 (이게 SpringBoot의 기본 설정)
- includeFilters, excludeFilters로 스캔 할지 말지 정할수 있는데 잘 안 쓰이니까 쓸 때 있을때 찾아보자~
- Component Scan중 충돌이 일어난다면(이름이 같음)?
  - 둘 다 @Component로 된거면 ConflictBeanDefinitionException 뜸
  - @Bean으로 된거랑 @Component로 된거랑 이름 같으면 수동이 Overring해버리거나 오류가 뜸 (설정차이)
## Autowire
- 생성자에 @Autowired를 지정하면, 스프링 컨테이너가 자동으로 의존관계를 주입 해준다.
- Default는 타입이 같은 빈을 주입한다. (getBean(MemberRepository.class)와 비슷)
- @Autowired Annotation은 주입할 대상이 없으면 오류가 발생, Argument를 required = false로 해서 동작하게 할 수도 있다. 
- Type으로 찾고 주입한다. 
#### 옵션 처리
- @Autowired(required = false) : 주입할 대상이 없으면 수정자 메서드 자체가 호출 되지 않는다. 
- Parameter 앞에 @Nullable : 주입할 대상이 없으면 null
- Parameter Optional<Object> 사용 : 주입할 대상이 없으면 Optional.empty

#### 같은 Type이 여러개인 경우
- 하위 타입(구체 타입)으로 지정하면 해결되나 DIP를 위반하고 유연성이 떨어진다.

##### @Autowired Field명 으로 매칭
- 같은 Type의 Bean이 여러개 있는게 확인되면 Field, Parameter 이름을 Bean이름과 매칭시킨다. 
##### @Qualifier 사용
- 추가 구분자로 Bean을 등록할때 @Qualifier("{원하는 이름}") Annotation을 추가로 붙여 준다.
- 주입시에도 @Quailifier("{원하는 이름}") Annotation을 붙여준다.
- 못 찾으면 NoSuchBeanDefinitionException 예외 발생
- 주입시 추가적인 옵션을 제공하는 것이지 Bean 이름을 변경하는 것은 아니다.

##### @Primary 사용
- Bean이 등록되는 곳에 @Primary Annotation을 붙인다.
- @Autowired 시에 여러 빈이 매칭되면 @Primary가 우선권을 가진다.

## @Primary vs @Qualifier
- 자주 쓰이는 Bean같은 경우에는 @Primary를 붙여 사용하고 
- 덜 쓰이거나 테스트 용도로 사용되는 건 @Qualifer을 적용시켜 명시적으로 획득하는 방식을 사용하면 좋다.
- Spring은 자동보다는 수동이, 넓은 범위의 선택권 보다는 좁은 범위의 선택권이 우선 순위가 높다. 따라서 @Qualifier이 우선순위를 가진다.

## Setting
- AnnotationConfigApplicationContext를 똑같이 사용 (AutoAppConfig.class 넘겨주자)
- AutoAppConfig와 같이 설정 파일에 @Configuration, @ComponentScan Annotation 붙이기

https://www.inflearn.com/questions/124234
