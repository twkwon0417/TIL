# JavaScipt Basic

#### How JS Work
- **Single Thread** : 위에서 아래로 차근차근
- **synchronous** : 동기적인 (중간에 시간 오래 걸리는게 있어도 기다리지 않고 바로 다음 라인으로)

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

#### JS의 함수 선언
~~~
function(){
	명령
}
~~~
- JS에서의 함수선언의 위치와 실행 위치는 중요하지 않다 (알아서 실행 됨)
- **단 var은 주의 할 것** : 함수안에서 var로 선언된 변수는 지역 변수로 처리된다.
- 또한 var은 hoisting 된다
##### hoisting
- Interpreter가 함수 소스를 훝어보고 var로 선언된 변수는 따로 기억 해 놓는다. (변수 값은 저장되지 않음) 따라서
~~~
function multiple() {
	console.log("x is" + x);
    var x = 20;
}
~~~
- **위의 함수를 실행하면 x is undefined 오류 발생**

#### var, let, const의 차이
- var : 함수 영역(레벨)의 스코프를 사용
- let : 변수를 선언한 블록({}로 묶인 부분)에서만 유효, 재할당은 되지만 **재선언은 안됨, Hoisting 안됨**
- const :블록 레벨의 스코프, **재할당, 재선언 불가**

#### 매개변수 기본 값 지정
~~~
function multiple(a, b = 5, c =10) {	//b = 5, c = 10으로 기본값 지정 함
	return a * b + c
}
~~~

#### 익명 함수 (함수의 이름을 지정하지 않고 사용)
1. 함수를 변수에 할당 할 때 사용 가능
2. 다른 함수의 매개변수로 사용 할 때 사용 가능
- 익명 함수 자체가 식(expression) 이므로
- **익명 함수의 경우 lambda꼴로 사용 가능**

#### 즉시 실행 함수
~~~
(function() {
	명령
}());

or 

(function(매개변수) {
	명령
}(인수));
~~~

#### HTML을 이용한 이벤트 처리
~~~
<태그 on이벤트명="JS함수명">
~~~
- 이벤트명 : https://developer.mozilla.org/ko/docs/Web/Events
- JS script와 HTML markup이 붙어 있어서 가독성 떨어짐

#### DOM을 이용한 이벤트 처리
- DOM을 사용하면 JS가 주인이 되어 HTML의 요소를 가져와 이벤트 처리기를 연결한다.
##### JS를 이용해서 웹 요소 가지고 오기
- document의 querySelector()함수 사용 : 인자로는 클래스 이름이나 id이름 또는 다양한 선택자를 넣을 수 있다.

~~~
var changeBttn = document.querySelector("#change");
changeBttn.onclick = changeColor;	// changeColor 함수 이름 뒤에 괄호가 없다는 것 주의

function changeColor() {
	document.querySelector("p").style.color = "#f00";
}
~~~
- 이 형식 외에도 웹 요소를 다른 변수에 할당 필요 없고 바로 익명함수를 이용해도 됨
- **함수 이름 뒤에 괄호가 없음을 주의!!**
