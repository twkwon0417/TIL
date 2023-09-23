Generic
========
- 클래스 내부에서 사용할 데이터 타입을 외부에서 지정화는 기법 -> 타입을 변수화 한 기능(객체에 타입을 지정해 줌)
- Generic type parameter 타입이 Class일 경우 다형성의 원리가 적용됨(자동으로 업캐스팅)

Genric Class, interface, method
--------------------------------
~~~ java
@FunctionalInterface
public interface Predicate<T>{  // 제너릭 인터페이스(Class도 동일)
  boolean test(T t);
}

public<T> List<T> filter(list<T> list, Predicate<T> p){  // 제네릭 메서드, 메서드 선언부에 <T>선언해줌
  List<T> results = new ArrayList<>();
  for(T t : list){
    if(p.test(t)){
      results.add(t);
    }
  }
  return results;
}

// 타입 파라미터를  String으로 정의, 제네릭 함수형 인터페이스
Predicate<String> nonEmptyStringPredicate = (String s) -> !s.isEmpty();
List<String> nonEmpty = filter(listOfStrings, nonEmptyStringPredicate);
~~~

~~~ java
class example<T> {
	
    // 클래스의 타입 파라미터를 받아와 사용하는 일반 메서드
    public T boo1(T x, T y) {
        // ...
    }
    
    // 독립적으로 타입 할당 운영되는 제네릭 메서드
    // 제네릭 메서드를 호출할때 직접 타입 파라미터를 다르게 지정시,
    // class의 <T>로 정해지지 않고 독립적으로 타입 지정
    public static <T> T boo2(T x, T y) {
        // ...
    }
}
~~~

Why Generic
------------
1. 컴파일 타임에 타입 검사를 통한 예외 처리
2. casting 안 해줘도 됨
> Genric이 안 쓰고 Object쓰면 객체를 쓸때 일일히 원하는 타입으로 casting 해줘야 함

Bounnded Type Parameter
-----------------------
**extends**
~~~ java
interface itf1{

}

interface itf2{

}

// Class상속도 가능, Interface의 경우 && 연산자 이용하여 다중 타입 한정 가능
class example<T extends itf1 && itf2>{  

}
~~~
**Recursive Type Bound**
- 타입 매개변수가 자신을 포함하는 수식에 의해 한정될 수 있다. 
~~~ java
// 자신과 비교될수 있는 모든 타입 T
static <T extends Comparable<T>> T max(List<T> list) {
    Iterator<T> iterator = list.iterator();
    T result = iterator.next();
    while (iterator.hasNext()) {
        T t = iterator.next();
        if (t.compareTo(result) > 0) result = t;
    }

    return result;
}
~~~

Generic Wild Card
------------------
나온 배경 : Generic은 Type Casting 불가능
~~~ java
// 오류 발생
List<Object> list = new ArrayList<Integer>();
~~~
- <?> : 타입 파라미터를 대치하는 구체적인 타입으로 모든 클래스나 인터페이스 타입이 올 수 있다.
- <? extends 상위타입> (Upper Bounded Wildcards) : 타입 파라미터를 대치하는 구체적인 타입으로 상위 타입이나 상위 타입의 하위 타입만 올 수 있다.
- <? super 하위타입> (Lower Bounded Wildcards) : 타입 파라미터를 대치하는 구체적인 타입으로 하위 타입이나 하위 타입의 상위 타입만 올 수 있다.
