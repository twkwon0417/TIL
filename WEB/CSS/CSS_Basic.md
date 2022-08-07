# Cascading Style Sheet Basic

#### Cascadig 규칙
- 스타일 규칙의 중요도와 작용 범위에 따라 우선 순위가 정해지고 나중에 작성한 스타일이 먼저 작성한 스타일을 덮어쓴다.
- 스타일 상속 : 태그의 포함 관계에 따라 부모 요소의 스타일을 자식 요소로, 위에서 아래로 전달 된다.


#### Basic Format
~~~
선택자 { 속성1: 속성값1; 속성2: 속성값2; }
~~~

#### CSS 적용하는 법
1. 인라인 스타일
~~~
<p style="color: blue;">Style using inline style</p>
~~~

2. 내부 스타일 시트 : `<head> ~ </head>`에 `<style>` 추가
~~~
<style>
h1 {
	padding: 10px;
    background-color: #222;
    color: #fff;
}
</style>
~~~

3. 외부 스타일 시트 : `<head> ~ </head>`에 `<link>` 추가
~~~
<link rel="stylesheet" href="외부 CSS 경로">
~~~

#### CSS 기본 선택자
- 전체 선택자
~~~
* {속성: 값,...}
~~~

- 타입 선택자
~~~ 
태그명 { 스타일 규칙 }
~~~

- 클래스 선택자
~~~
.클래스명 { 스타일 규칙 }
~~~

- id 선택자
~~~
#아이디명 { 스타일 규칙 }
~~~

- 그룹 선택자
~~~
선택자1, 선택자2 { 스타일 규칙 }
