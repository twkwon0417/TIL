# JavaScript에서의 객체

### JS에서 모든 것은 객체

#### 객체의 종류
- 문서 객체 모델(DOM) : 웹 문서 자체, 삽입되어 있는 이미지와 링크, 텍스트 필드 등등
- 브라우저 관련 객체 (BOM) : 웹 브라우저에서 사용하는 정보 eg) navigator, history, location, screen
- 내장 객체 : Date, Array 등등

#### JS의 객체 (Java와의 비교)
- Java와 같이 객체는 참조 형태로 사용되어야 함
- 프로퍼티와 메서드 존재
- 마침표 표기법으로 프로퍼티와 메서드를 사용
- 배열에서의 concat, join method 등등

#### 브라우저 관련 객체
- https://wickies.tistory.com/26	대충 훝고 필요한 거는 검색하며 알아가자
- JavaScript Object Model 참고

#### JS의 객체는 어떻게 구성되어 있는가?
- key값과 value를 여러개 가지고 있는 꼴로 
~~~
  const obj = {
  a: 'Dip2K',
  b: 30,
  c: true,
  d: {}
};

  console.log(Object.keys(obj)); 
  // Array ["a", "b", "c", "d"]

  console.log(Object.values(obj)); 
  // Array ["Dip2K", 30, true, Object {  }]
~~~
