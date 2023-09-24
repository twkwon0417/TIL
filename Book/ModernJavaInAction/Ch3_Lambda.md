Lambda
=======
- 정의 : 메서드로 전달할 수 있는 익명 함수를 단순화 한 것
- 특징
> 1. 악명 : 보통 메서드와 달리 이름이 없다.
> 2. 함수 : 메서드와 같이 특정 클래스에 종속 되지 않아 **함수**라 부른다.
> 3. 전달 : 람다 표현식을 메서드 인수로 전달하거나 변수로 저장할 수 있다.

구조
-------
~~~ java
// --람다 파라미터 -- 화살표 ---------------람다 바디----------------
(Apple a1, Apple a2) -> a1.getWeight().compareTo(a2.getWeight());
~~~

함수형 인터페이스 (@functionalInterface)
--------------------------------------
- 오직 하나의 추상 메서드를 가지는 인터페이스 (**default method** 많아도 추상메서드 1개 있을시 함수형 인터페이스)
- 람다 표현식으로 함수형 인터페이스의 추상 메서드 구현 직접 전달 가능
- -> **전체 표현식을 함수형 인터페이스의 인스턴스로 취급** (기술적으로는 인터페이스를 **구현한** 클래스의 인스턴스)
~~~ java
@functionalInterface
public interface Predicate<T>{
    boolean test(T t);
}
~~~

> Interface 몰랐던 거
> 인터페이스도 data type역할을 할수 있다.
> ~~~ java
> public interface IntPredicate{
>     boolean test(int t);
> }
>
> Int Predicate evenNumbers = (int i) -> i % 2 == 0;
> System.Out.Println(evenNumbers.test(1000));
>
> // true;
> ~~~

- **Function Descriptor** : lambda 표현식의 signature울 서술하는 메서드
- **Remind** : **함수형 인터페이스를 인수로 받는 메서드에만** 람다 표현식 사용할 수 있다.

형식 검사, 형식 추론, 제약
---------------------------
- **형식 검사** : 람다가 사용되는 context를 이용해서 **람다의 type을 추론 할수 있다.**
- 대상 형식(target type) : 어떤 context에서 기대되는 람다 표현식의 형식 
- <ins>p.109 그림 3-4 참고</ins>

> **특별한 void 호환 규칙**
> 람다의 바디에 일반 표현식이 있으면 void를 반환하는 함수 디스크립터와 호환된다.
> > 일반 표현식 : 입력값, 리턴값이 있거나 없는 (단어 그대로 "일반") 함수를 의미라는 것 같다...?
> ~~~ java
> // 아래 두 코드는 유효한 코드
> 
> // Predicate는 Boolean 반환값을 가짐
> Predicate<String> p = s -> list.add(s);
> // Consumer는 void 반환값을 갖짐
> Consumer<String> b = s -> list.add(s);
> ~~~

형식 추론
---------
- 컴파일러는 람다의 시그니쳐도 추론할 수 있다.
> - **signature** : 이름과 인자(parameter)
~~~ java
Comparator<Apple> c = (Apple a1, Apple a2) -> a1.getweight().compareTo(a2.getWeight());

//형식 추론 적용
Comparator<Apple> c = (a1, a2) -> a1.getweight().compareTo(a2.getWeight());
~~~

람다 내에서의 지역 변수 사용
----------------------------
<table style="border-collapse: collapse; width: 100%; height: 1005px;" border="1" data-ke-align="alignLeft">
<tbody>
<tr style="height: 20px;">
<td style="width: 4.72864%; text-align: center; height: 20px;">No</td>
<td style="width: 18.4496%; text-align: center; height: 20px;">변수명</td>
<td style="width: 15.7363%; text-align: center; height: 20px;">선언위치</td>
<td style="width: 61.0853%; text-align: center; height: 20px;">설명</td>
</tr>
<tr style="height: 231px;">
<td style="width: 4.72864%; height: 231px; text-align: center;">1</td>
<td style="width: 18.4496%; height: 231px; text-align: center;">클래스 변수<br>(class variable)<br>(= static 변수)</td>
<td style="width: 15.7363%; text-align: center; height: 620px;" rowspan="2">클래스 영역<br><br>(클래스 외부<br>사용 가능 여부<br>- 접근 제어자에<br>따라 다름)</td>
<td style="width: 61.0853%; height: 231px; text-align: left;"><span style="background-color: #fff192;">클래스 영역에서 타입 앞에 static이 붙는 변수<br>객체를 공유하는 변수로 여러 객체에서 공통으로 사용하고 싶을 때 </span><span style="background-color: #fff192;">정의</span><br><br>※ 접근 방법 : 클래스명.클래스변수명<br>&nbsp; &nbsp; ex ) class Exem에 static 변수로 int 형태의 age가 있으면<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Exem.age = 1; 이런 식으로 접근이 가능<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 인스턴스 변수의 경우 객체(=인스턴스)를 생성하고<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 참조 변수를 통해서만 접근이 가능한데 <span style="background-color: #fff192;">클래스 변수는</span><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span style="background-color: #fff192;">객체를 생성하지 않아도 클래스명으로 바로 접근이 가능함</span></td>
</tr>
<tr style="height: 389px;">
<td style="width: 4.72864%; height: 389px; text-align: center;">2</td>
<td style="width: 18.4496%; height: 389px; text-align: center;">인스턴스 변수<br>(instance variable)</td>
<td style="width: 61.0853%; height: 389px; text-align: left;"><span style="background-color: #fff192;">클래스 영역에서 static이 아닌 변수</span><br>개별적인 저장 공간으로 객체/인스턴스마다 다른 값 저장 가능<br>→ 객체(=인스턴스)를 여러 개 생성했다면 각각의 참조 변수명으로<br>&nbsp; &nbsp; 접근이 가능하고 각각에 값을 저장할 수 있음<br>&nbsp; &nbsp; <span style="background-color: #ffc1c8;">★ 클래스 변수는 객체를 공유한다면 인스턴스 변수는 객체를</span><br>&nbsp; &nbsp; <span style="background-color: #ffc1c8;">공유하지 않음</span><br><br>※ 접근 방법 : <span style="background-color: #fff192;">객체(=인스턴스) 생성 후 참조 변수명으로 접근</span><br>&nbsp; &nbsp; ex) class Exem에 String name(=인스턴스 변수)이 있으면<br>&nbsp; &nbsp; 먼저 클래스명으로 객체/인스턴스 생성하고<br>&nbsp; &nbsp; Exem e = new Exem( );<br>&nbsp; &nbsp; e.name = "확고"; 이렇게 접근할 수 있음<br>&nbsp; &nbsp; Exem e2 = new Exem( );<br>&nbsp; &nbsp; e2.name = "확Go";&nbsp;<br><br>(부연 설명) 객체/인스턴스 생성만 하고 참조 변수가 없는 경우<br>가비지 컬렉터에 의해 자동 제거됨</td>
</tr>
<tr style="height: 106px;">
<td style="width: 4.72864%; height: 106px; text-align: center;">3</td>
<td style="width: 18.4496%; height: 106px; text-align: center;">지역 변수<br>(local variable)</td>
<td style="width: 15.7363%; text-align: center; height: 365px;" rowspan="2">메서드 영역<br><br>(접근 제어자를<br>사용하지 않음)</td>
<td style="width: 61.0853%; height: 106px; text-align: left;"><span style="background-color: #fff192;">메서드 내에서 선언되고 메서드 수행이 끝나면 소멸되는 변수<br>초깃값을 지정한 후 사용할 수 있음</span> ex) int i = 0;<br>(조건문, 반복문 블록 내에 선언한 지역변수가 있는 경우<br>수행이 끝나면 소멸되므로 계속 사용할 경우 블록 밖에서 선언 필요)</td>
</tr>
<tr style="height: 259px;">
<td style="width: 4.72864%; text-align: center; height: 259px;">4</td>
<td style="width: 18.4496%; text-align: center; height: 259px;">매개 변수<br>(= parameter)</td>
<td style="width: 61.0853%; text-align: left; height: 259px;"><span style="background-color: #fff192;">메서드 호출 시 '전달하는 값'을 가지고 있는 변수<br>(지역 변수처럼 선언된 곳부터 수행이 끝날 때까지 유효함)<br></span>ex)<br>int sum;<br>sum = add(1,2); → <span style="background-color: #fff192;">(1) add 메서드 호출하면서 1,2 값 전달</span><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span style="background-color: #fff192;">(4) 리턴 값 c의 값이 int sum에 저장</span><br>System.out.print(sum); → <span style="background-color: #fff192;">(5) sum에 저장된 값 3이 출력됨</span><br><br>static int add(int a, int b){ → <span style="background-color: #fff192;">(2) 정수(1,2) 넘어오니까 int로 받아줌</span><br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;<span style="background-color: #fff192;">★ a, b가 호출 시 '전달하는 값'을 가지고 있는 매개 변수</span><br>&nbsp;int c = a+b;<br>&nbsp;return c; → <span style="background-color: #fff192;">(3) 수행 끝나고 리턴 값 c를 가지고 호출한 곳으로 돌아감</span></td>
</tr>
</tbody>
</table>

> 출저 : https://j-growthdiary.tistory.com/entry/%EB%B3%80%EC%88%98%EC%9D%98-%EC%A2%85%EB%A5%98%ED%81%B4%EB%9E%98%EC%8A%A4-%EB%B3%80%EC%88%98Static-%EB%B3%80%EC%88%98%EC%9D%B8%EC%8A%A4%ED%84%B4%EC%8A%A4-%EB%B3%80%EC%88%98%EC%A7%80%EC%97%AD-%EB%B3%80%EC%88%98

- **자유 변수** : 파라미터로 넘겨진 변수가 아닌 **외부에서 정의된 변수**
- 자유변수를 활용하는 동작 -> **람다 캡처링(capturing lambda)**
- **제한사항** : 사용하려는 **지역 변수**가 final로 선언 되어있거나 final 취급을 받아야 함(한 번만 할당될수 있는 지역 변수) <br> 인스턴스 변수나 정적 변수는 힙 영역에 존재 하기 때문에 공유되고 있는 영역이라 괜춘
- - **why?** : 람다는 지역 변수가 존재하는 스택 영역에 직접 접근하는 것이 아니라 **지역 변수를 자신(람다식이 동작하는 쓰레드)의 스택에 복사하여 사용** -> 지역 변수가 존재하는 쓰레드가 사라져도 람다는 복사된 값을 참고해 에러가 발생하지 않음. <br> 만약, 우리가 멀티 쓰레드 환경에서 여러 개의 쓰레드가 동일한 람다식을 사용한다고 가정해 봅시다. 여러 개의 쓰레드가 람다식을 사용하면서 람다 캡쳐링을 진행하는데, 외부 변수가 변한다면 값이 계속해서 변하기때문에 **동기(sync)화 문제가 발생**하게 됨
> why 출저 : https://steady-coding.tistory.com/306

메서드 참조
------------
- 아직도 길어!, 더 간결하게! : 기존의 메서드 정의를 재활용해서 람다처럼 전달하자
~~~ java
// 예시
(Apple apple) -> apple.getWeight()
(String s) -> System.out.println(s)

// 메서드 참조 적용
Apple::getWeight
System.out:println(s)
~~~

생성자 참조
------------
- 예시로 바로 이해하자
~~~ java
Supplier<Apple> c1 = Apple::new;
Apple a1 = c1.get();

Function<Integer, Apple> c2 = Apple::new;
Apple a2 = c2.apply(110);

BiFunction<Color, Integer, Apple> c3 = Apple::new;
Apple a3 = c3.apply(GREEN, 110);

// 위 코드의 의미는
Supplier<Apple> c1 = () -> new Apple();    // 생성자 참조
Apple a1 = c1.get();

Function<Integer, Apple> c1 = (weight) -> new Apple(weight);
Apple a2 = c2.apply(110);

BiFunction<Color, Integer, Apple> c3 = new Apple(color, weight);
Apple a3 = c3.apply(GREEN, 110);
~~~

~~~ java
// 활용
static Map<String, Function<Integer, Fruit>> map = new HashMap<>();
static{
    map.put("apple, Apple::new);
    map.put("orange", Orange::new);
// ...
}

public static Fruit giveMeFruit(string fruit, Integer weight){
    return map.get(fruit.toLowerCase())
              .apply(weight);
}
~~~

> <a href="https://github.com/twkwon0417/TIL/blob/main/Book/ModernJavaInAction/Static.md" target="_blank"> static이란? 올바른 사용법 & 다양한 의미 </a>

람다 표현식을 조합할 수 있는 메서드
-------------------------------
- Functial Interface는 하나의 추상 메서드 밖에 가지지 못 하는데??? <br> **defult method**가 있잖아
1. **Comparator** 조합
    - **.reversed()** : 주어진 비교자의 순서를 뒤바꾸는 default method
    - **.thenComparing** : 앞에서의 comparator로 비교했을때 같을 경우 두번째 comparator 지정해는 default method
    - ~~~ java
      // .reversed()
      inventory.sort(comparing(Apple::getWeight).reversed());
      // .thenComparing
      inventory.sort(comparing(Apple::getWeight)
               .reversed()
               .thenComparing(Apple::getCountry));
      ~~~
2. **Predicate** 조합
    - **.negate()** : 프리티케이트를 반전 시킴
    - **.and()** : && for Predicate
    - **.or()** : || for Predicate
    - ~~~ java
      Predicate<Apple> redApple = (a1) -> a1.getColor == RED;

      // .negate() : red apple이 아닌 경우에 true 반환
      Predicate<Apple> notRedApple = redApple.negate();
      // .and()
      Predicate<Apple> redAndHeavyApple =
      redApple.and(apple -> apple.getWeight() > 150);
      // .or()
      Predicate<Apple> redAndHeavyAppleOrGreen =
      redApple.and(apple -> apple.getWeight() > 150);
              .or(apple -> GREEN.equals(a.getColor()));
      ~~~

3. **Function** 조합
    - **.andThen()** : 주어진 함수를 먼저 적용한 결과를 다른 함수의 입력으로 전달하는 함수를 반환
    - **.compose()** : 인수로 주어진 함수를 먼저 실행한 다음에 그 결과를 외부함수의 인수로 전달
    - ~~~ java
      Function<Integer, Integer> f = x -> x + 1;
      Function<Integer, Integer> g = x -> x * 2;
      Function<Integer, Integer> h1 = f.andThen(g);    // g(f(x))
      Function<Integer, Integer> h2 = f.compose(g);    // f(g(x))

      int result1 = h1.apply(1);    // return 4, g(f(x))
      int result2 = h2.apply(1);    // return 3, f(g(x))


> **try - with- resources 구문**
> ~~~ java
> // Java 7 이전, try - catch - finally 구문에서 자원 해제하기
> public static void main(String args[]) throws IOException {
>    FileInputStream is = null;
>    BufferedInputStream bis = null;
>    try {
>        is = new FileInputStream("file.txt");
>        bis = new BufferedInputStream(is);
>        int data = -1;
>        while((data = bis.read()) != -1){
>            System.out.print((char) data);
>        }
>    } finally {
>        // close resources
>        if (is != null) is.close();
>        if (bis != null) bis.close();
>    }
>}
> 
> ~~~ java
> // Java 7 이후, try - with - resources 구문
> public static void main(String args[]) {
>    try (
>        FileInputStream is = new FileInputStream("file.txt");
>        BufferedInputStream bis = new BufferedInputStream(is)
>    ) {
>        int data = -1;
>        while ((data = bis.read()) != -1) {
>            System.out.print((char) data);
>        }
>    } catch (IOException e) {
>        e.printStackTrace();
>    }
>}
> ~~~
> 
> - **AutoCloseable 인터페이스를 구현한 객체들을 finally에서 close 해준다.**
> 출저 : https://codechacha.com/ko/java-try-with-resources/

https://inpa.tistory.com/entry/JAVA-%E2%98%95-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EB%B3%B4%EB%8A%94-%EC%9E%90%EB%B0%94-%EC%BD%94%EB%93%9C%EC%9D%98-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%98%81%EC%97%AD%EC%8A%A4%ED%83%9D-%ED%9E%99
