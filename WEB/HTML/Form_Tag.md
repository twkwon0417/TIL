# Basic Form Tags

~~~
<form [속성="속성값"]>여러 폼 요소</form>
~~~

#### Form Tag의 속성
- method : 서버 쪽으로 어떻게 넘겨 줄지 결정, get, post 둘 증 하나
- name : 자바스크립트로 폼을 제어할때 사용하는 이름을 지정
- action : `<form>` tag 안의 내용을 처리해 줄 서버프로그램 지정
- target : action 속성에서 지정한 슼트립트 파일을 현재 창이 아닌 다른 위치에서 열도록 함
- autocomplete : 전에 값을 입력한 적 있으면 자동완성 기능, default setting은 on이다. off로 직접 설정해줘야 꺼짐

#### 폼 요소들을 그룹으로 묶기
- `<fieldset>` : 하나의 폼 안에서 여러 구역을 나누어 표시할 때 사용
- `<legend>` : `<fieldset>`으로 묶은 그룹에 제목(label)을 붙일 때 사용
~~~
<fieldset>
  <legend>그룹이름</legend>
</fieldset>
~~~

#### 폼 요소에 이름 붙이기
- `<label>` : `<input>` 태그와 같은 폼 요소에 레이블을 붙일때 사용
~~~
<label>레이블명<input type="text"></label>
~~~

~~~
<label for="user-id">레이블명</label>
<input type="text" id="user-id>
~~~
- label tag와 input tag가 떨어져 있어도 둘 사이를 쉽게 연결할 수 있다는 장점이 있다.

#### `<input>`
- `<input>` : 다양한 폼에서 사용자가 입력한 정보를 받을 때 사용

#### input tag type의 속성
- text, password, search, url, email, tel, month, day, datetime, datetime-local, checkbox, radio ... etc
- submit : 전송 버튼
- reset : 리셋버튼
- image : submit 버튼 대신 사용할 이미지를 넣음
- button : 그냥 일반 버튼
- file : 파일을 첨부할 수 있는 버튼
- hidden : 사용자에게는 보이지 않지만 서버로 넘겨주는 값이 있는 필드
~~~
<input type="image" src="이미지 경로" alt="대체 텍스트">
<input type="hidden" name="이름" value="서버로 넘길 값">

<label><input type="radio" name="gift" value="yes">선물 포장</label>
<label><input type="radio" name="gift" value="no">선물 포장 안함</label>
~~~

#### 기본적인 input tag에서 사용할 수 있는 속성
- size
- value : 버튼에 표시할 내용
- maxlength
- autofocus required : 처음에 홈페이지에 들어왔을 때 처음 커서의 위치
- readonly : 입력하지 못하고 읽기만 가능하게 해줌
- required : 필수 입력 필드 지정, 입력하지 않고 전송시 오류를 알려준다.
- placeholder : input 박스에 힌트를 제공한다.

#### checkbox, radio의 속성
- value : 선택한 체크 박스나 라디오 버튼을 서버에게 알려 줄 때 넘겨줄 값을 지정, <strong>필수 속성임</strong>
- checked : 여러 항목 중에서 기본으로 선택해 놓고 싶은 항목에 사용
- name : 웹 프로그래밍에서 폼 요소를 제어할 때 사용, 라디오 버튼에서 하나의 버튼만 선택할 수 있게 하려면 모든 라디오 버튼의 name 값이 같아야함

### 폼에서 사용하는 여러가지 태그
- textarea
- select
- option
- datalist
- button : type:submit||reset||button : 기존 input으로 만든 버튼과 같은 역활을 함

