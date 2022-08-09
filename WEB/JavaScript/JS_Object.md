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

#### 문서 객체 모델 (DOM)
- DOM : JS를 이용하여 웹 문서에 접근하고 제어할 수 있도록 객체를 사용해 웹 문서를 체계적으로 정리하는 방법
- 웹 문서를 하나의 객체로 정의하고 문서를 이루는 이미지, 텍스트 따위도 객체로 정의
- **웹 문서와 그 안의 모든 요소를 '객체'로 인식**

#### DOM Tree
- https://poiemaweb.com/js-dom
- **DOM을 구성하는 기본 원칙**
- 1. 모든 HTML 태그는 요소(element) 노드 입니다.
- 2. HTML 태그에서 사용하는 텍스트 내용은 자식 노드인 텍스트(text) 노드입니다.
- 3. HTML태그에 있는 속성은 자식 노드인 속성(attribute) 노드입니다.
- 4. 주석은 주석(comment) 노드 입니다. 
- 웹 문서를 해석할때 DOM구조는 필수 -> 그래야 원하는 부분 찾고 수정 가능


