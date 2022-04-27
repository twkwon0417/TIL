# XML 파일로 AppConfig 파일 설정하기
- 기존 Java 코드로 설정하는 것과 다르지 않다. (1대 1 매핑 등등)
- ~~~java
  ApplicationContext ac = new GenericXMLApplicationContext({Configuration.XML})
  ~~~
  - 이런식으로 컨테이너를 불러오음
- ~~~xml
  <?xml version="1.0" encoding="UTF-8"?>
  <beans xmlns="http://www.springframework.org/schema/beans"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://www.springframework.org/schema/beans http://
  www.springframework.org/schema/beans/spring-beans.xsd">
      <bean id="memberService" class="hello.core.member.MemberServiceImpl">
          <constructor-arg name="memberRepository" ref="memberRepository" />
      </bean>
      <bean id="memberRepository"
  class="hello.core.member.MemoryMemberRepository" />
      <bean id="orderService" class="hello.core.order.OrderServiceImpl">
          <constructor-arg name="memberRepository" ref="memberRepository" />
          <constructor-arg name="discountPolicy" ref="discountPolicy" />
      </bean>
      <bean id="discountPolicy" class="hello.core.discount.RateDiscountPolicy" />
  </beans>
  ~~~
  - "김영한 스프링 핵심원리 기본편"에서 가져옴
  - https://spring.io/projects/spring-framework 쓸 일이 생기면 공식 웹사이트를 보자
  