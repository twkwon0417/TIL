#JAVA 코드를 사용한 Spring 설정
##설정 방법
- Configuration 파일에 @Configuration Annotation 추가 
- 모든 Method에 @Bean Annotation을 달아줘서 Spring Container에 등록
- Spring Container에서 Bean을 꺼내야 할 피요가 있는 Class : Spring은 ApplicationContext부터 시작 이게 Spring Container이다.
- ApplicationContext ac = new AnnotationConfigApplicationContext({AppConfig}.class)
- AppConfig.class 라는 구성정보를 Spring Container에 지정 Container안에 Bean들이 등록된다.
- MemberService memberservice = ac.getBean("memberService", MemberService.class)
- ac 생성하고 ac의 getBean사용해서 우리가 등록 한 Bean 불러오기 
- Parameter은 (Bean이름, 객체 Type)

##특징
- AppConfig 객체를 직접 만드는게 아니라 Spring이 관리를 해줌
- Spring Container안에는 빈 이름과 빈 객체(Method의 Return값)들을  표(?)로 저장하고 있다.
- Bean 이름들은 모두 달라야 한다. 아니면 오류 뜬다.
- 이러한 방식(자바 코드로 스프링 빈을 등록하는)으로 빈을 등록하면 생성자를 호출하면서 의존관계 주입도 한번에 처리된다.
- 원래 Spring은 Bean을 생성하고, 의존관계를 주입하는 단계가 나누어져 있다.

##BeanFactory vs ApplicationContext