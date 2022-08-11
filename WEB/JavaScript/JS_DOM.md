# 문서 객체 모델 (DOM)
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

#### DOM 접근 방법
~~~
// 반환값은 HTML Collection 객체 : DOM 트리의 텍스트 노드, 속성 노드까지 자유롭게 제어 불가
document(요소명).getElementById("id명")
document.getElementsByClassName("class명")
document.getElementsByTagNmae("태그명")


// 반환값이 노드이거나 노트 리스트 : DOM 트리의 텍스트 노드, 속성 노드까지 자유롭게 제어 가능
노드.querySelector(선택자)
노드.querySelectorAll(선택자 또는 태그)
~~~

#### innerText, innerHTML 프로퍼티
- innerText : **텍스트 내용**을 표시
- innerHTML : **HTML 태그**까지 반영하여 표시
~~~
요소명.innerText = 내용
요소명.innerHTML = 내용
~~~

#### 속성(attribute)를 접근, 수정
~~~
getAttribute("속성명")
setAttribute("속성명", "값")
~~~
- eg) href attribute수정, src attribute 수정

#### event 객체
- event 객체 : 웹 문서에서 이벤트가 발생한 요소가 무엇인지, 어떤 이벤트가 발생했는지 등의 정보를 포함
- https://developer.mozilla.org/ko/docs/Web/API/Event
- **event 객체에서는 이벤트 정보만 들어 있다 -> 이벤트가 발생한 대상에 접근하려면 이벤트 처리기에서 예약에 this를 사용**

#### addEventListener() Method
- JAVA Swing과 같은 개념 : 특정 요소에 이벤트를 감지할수 있게 해주는 것
~~~
요소.addEventListener(이벤트, 함수, 캡쳐 여부);	//캡처 여부는 필수 인자가 아니다.
~~~
- 이벤트 : 이벤트 유형을 지정 (단, click, press처럼 on을 붙이지 않는다)
- 함수 : 이벤트가 발생하면 실행할 명령이나 함수를 지정 (단, 여기에서 함수를 정의할 떄는 event객체를 인수로 받음)
- 캡쳐 여부 : 기본값은 false, true와 false중에 선택. true : 캡쳐링, false : 버블링 https://ko.javascript.info/bubbling-and-capturing 참고

#### CSS 속성 접근하기
~~~
document.요소명.style.속성명
document.getElementById("desc").style.color = "blue";
~~~
- background-color과 같이 -으로 연결되있는 것은 backgroundColor처럼 합쳐서 사용

#### node list 접근, 추가, 삭제
- nodelist 값에 접근 할 때 배열처럼 접근 하면 된다.
~~~
document.querySelectorAll("li")[1]
~~~

##### 새로운 노드 추가, 삭제
- DOM Tree를 구성하는 기본 원칙 참고 : 추가, 제거에 단순 Tag노드 뿐 만 아니라 텍스트 노드와 속성노드도 고려 해야 함
- **DOM Tree 내에서 생각**
~~~
document.createElement("노드명")	  //요소 노드 만들기
document.createTextNode("텍스트")	  //텍스트 노드 만들기
부모노드.appendChild(자식노드)		   //자식 드 연결
document.createAttribute("속성명")	  //속성 드 만들기
속성노드명.value = "내용"				//속성값 지정하기
요소명.setAttributeNode(속성노드)		//요소 노드의 자식으로 속성노드 연결하기
~~~
- eg)
~~~
var srcNode = document.createAttribute("src")
srcNode.value = "images/dom.jpg"
~~~
- **노드 삭제 시에는 부모노드에서 자식노드를 삭제해야 한다. -> 삭제해야 할 노드가 있다면 반드시 부모노드를 찾아야 함**
~~~
노드.parentNode			   //노드(참조값)의 부모노드를 반환
부모노드.removeChild(자식노드)	//자식노드를 삭제
~~~