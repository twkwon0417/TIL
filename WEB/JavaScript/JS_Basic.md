# JavaScipt Basic

#### How to connect js
- ##### Inside HTML file
- - `</body>` 직전에 `<script> ~ </script>` 안에 삽입
- ##### 외부 스크립트 파일로 연결 하기
~~~
<script src="외부 스크립트 파일 경로"></script>
~~~

#### Basic Input Output
~~~
alert("Message")
confirm("Message")				 // 확인, 취소 2개의 버튼이 있는데 어떤 버튼을 눌렀는지 결과를 반환한다.
prompt("Message, "기본값")        // Client의 Input을 return한다.
document.write("출력할 메시지")    // 
console.log()
~~~

#### TIP
- JS는 문장이 끝날때 ; 필수 아니다. 다만 문장과 문장을 잘 구분하기 위해 붙이는 걸 권장

#### 변수 선언 및 변수의 종류
~~~
var 변수명
~~~

##### JS의 모든 자료형 : 이런 데이터 유형의 유연함이 장점이자 단점, 알아서 데이터 타입이 변경되니 오류를 잡기 힘들다. 데이터 타입에 주의하자 
기본 유형 : 숫자형, 문자열, 논리형
복합 유형 : 배열, 객체
특수 유형 : undefined, null

#### 기존 연산자와 JS의 연산자의 다른 점
- === : 피연산자도 같고 자료형도 같아야 true 반환
- !== : 피연산자가 같지 않거나 자료형이 같지 않으면 true 반환
<b>기존 ==와 != 연산자는 피연산자의 자료형을 변환하여 비교 함</b>