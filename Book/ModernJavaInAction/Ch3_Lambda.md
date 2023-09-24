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

// 여기서 부터 시작 입니다~


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
