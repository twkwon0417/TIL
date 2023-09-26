Static
=======
- static이라 하면 : data가 어느 클래스의 인스턴스로써 **종속 되어 있지 않다**는 의미 이다.
> non-static method를 사용 하려면 그 메서드가 있는 인스턴스를 생성해야 되지만! <br> static 메서드는 어느 곳에도 종속 되어 있지 않음으로 바로 사용 할 수 있다.

static으로 선언하면?
----------------------------------
- **Metaspace**에 **저장** 됨
> JVM 8 이전과 이후 <br>
> <img width="535" alt="image" src="https://github.com/twkwon0417/TIL/assets/91003152/e49ab6b7-8f47-4aa7-9967-90d847e062d6">
> <img width="589" alt="image" src="https://github.com/twkwon0417/TIL/assets/91003152/df45ed95-668b-4e1f-a3e5-e17d184bcfbf">
> PermGen : 사이즈가 정해져 있음
> Metaspace : Auto-growing Space, JVM memory가 아닌 Native Memory의 한 부분임
> 더 많은 정보는 여기 잠고 : https://jaemunbro.medium.com/java-metaspace%EC%97%90-%EB%8C%80%ED%95%B4-%EC%95%8C%EC%95%84%EB%B3%B4%EC%9E%90-ac363816d35e
<br>
- static은 GC의 대상이 되지 않음으로 memory leak등 조심히 사용하자
- static 변수는 **JVM이 클래스를 load 했을 때 initialized됨**, 즉 처음으로 코드에서 레퍼런스 됬을 때 <br> 인스턴스가 처음 만들어 질 때 생성되는게 아니다.
- static을 잘 사용하고 싶다면 참고 하자 : https://12bme.tistory.com/94

staic block
------------
- 클래스 초기화 블록으로써 : 클래스 변수의 초기화에 사용된다, static 답게 **class가 처음 로딩될 때 실행 됨.** <br> 따라서 자바 런타임에 의해 한번만 thread-safe-manner로 실행됨을 보장하고 여러 static block이 있어도 순차적으로 실행 됨을 보장한다.
- ~~~ java
  class StaticBlock{
      static List<Integer> list = new ArrayList<>();
      static{
          list.add(1);
          list.add(2);
          list.add(3);
      }
      static{
          list.add(4);
      }
  }

  // 항상 {1, 2, 3, 4}를 보장한다.
  ~~~

static class
------------
- Top-Level class는 static 선언을 할 수 없다. (굳이 static 아니여도 참조 가능 하잖아...)
- **Nested Class**는 가능
- > Nested Class vs Inner Class
  > Nested Class는 static, Inner class는 non static
  > Inner Class는 Inner Class를 둘러싸는 모든(private까지) 변수에 접근 할 수 있다.
  > Static인 Nested Class 같은 경우는 Outer Class의 static 변수들만 접근 가능하다.
  > > **Nested Class**
  > > Top - level로 간주 됨
  > > 생성되기 위해서 Outer Class의 instance가 필요하지 않다.
  > > 명시적 형변환(Explicit Type Casting)을 하지 않은(명시적인 참조가 아닌) 경우, Class member에 접근 불가
  > > 독립적인 lifetime을 가진다.
  > > eg. Singletone Pattern
  
-------------------------------------------
  
출저 : https://www.linkedin.com/pulse/static-variables-methods-java-where-jvm-stores-them-kotlin-malisciuc
