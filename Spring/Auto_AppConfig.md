# 설정코드 없이 Spring Setting 하기
## Component Scan
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

## Setting
- AnnotationConfigApplicationContext를 똑같이 사용 (AutoAppConfig.class 넘겨주자)
- AutoAppConfig와 같이 설정 파일에 @Configuration, @ComponentScan Annotation 붙이기

/// 생성자 주입 : 새로운 객체를 만들때 생성자가 호출되어야 하니 빈 등록할때 주입이 자동으로 일어나게 된다.