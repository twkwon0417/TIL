## 배열 객체의 내장 함수 map욿 반복되는 Data 관리
~~~
arr.map(callback, [thisArg]);
~~~
- callback : 새로운 배열 요소를 생성하는 함수. 다음 세 가지 인수를 가집니다.
  - currentValue : 처리할 현재 요소.

  - index<sup>(Optional)</sup> : 처리할 현재 요소의 인덱스.

  - array<sup>(Optional)</sup> : map()을 호출한 배열.

- thisArg<sup>(Optional)</sup> : callback을 실행할 때 this로 사용되는 값.

~~~
const numbers = [1, 2];

numbers.map((a, b, c) => {

    // current index: 요소값
    // index: source에서 요소의 index
    // array: 순회하는 대상

    console.log(a);
    // 1

    console.log(b);
    // 0

    console.log(c);
    // [1]

    return a * a;
});
~~~
