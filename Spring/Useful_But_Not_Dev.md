#개발에 필요하진 않지만 쓸만할 기능

##컨테이너 등록된 빈 조회하기
- 스프링 빈을 조회할때 부모 타비으로 조회하면, 자식 타입도 함께 조회한다.
- ~~~ java
  String[] beanDefinitionNames = ac.getBeanDefinitionNames();
  for (String beanDefinitionName : beanDefinitionNames) {
    BeanDefinition beanDefinition = ac.getBeanDefinition(beanDefinitionName);
    
    if (beanDefinition.getRole() == BeanDefinition.ROLE_APPLICATION) {
        Object bean = ac.getBean(beanDefinitionName);
        System.out.println("name = " + beanDefinition + " object = " + bean);
    }
  }
    ~~~
- Bean의 Role을 가져와서 개발에 쓰는 Bean들만 가져오기 (일반적으로 사용자가 정의한 Bean)
- AppConfig나 Spring에 필요한 다른 것들은 출력 되지 않게 할 수 있다.

##조회하는 여러가지 방법
- ~~~ java
  ac.getBean("Bean 이름", 빈의 타입)
  ~~~
- Paramemter을 다 넣어서 빈 이름으로도 조회가능
- 또는 빈의 타입만 넣어서 타입으로만 또는 구체 타입으로만도 조회 할 수 있다.
- 타입으로 조회시 같은 타입이 둘 이상 있으면 NoUniqueBeanDefinitionException 터진다.
- 이러면 이름을 지정해주는 거 또는 HashMap으로 받아서 모든 Bean 받을수도 있다. 


  
  
  