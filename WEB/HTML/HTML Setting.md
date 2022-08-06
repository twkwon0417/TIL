# HTML 기본 구조

#### <!DOCTYPE html>
- 현재문서가 HTML5언어도 되있다는 의미

#### `<html> ~ </html>`
- 웹 문서의 시작과 끝을 알림
- </html>은 문서가 끝났다는 뜻으로 이 태그 뒤에는 아무 내용도 없어야 한다.

#### `<head> ~ </head>`
- 웹 브자우저가 웹 문서를 해석하는 데 필요한 정보를 입력하는 부분
##### `<meta>`
- 웹 브라우저에는 보이지 않지만 웹 문서에 관련된 정보를 저장
- eg) 인코딩 정보, 언어 설정, 제목etc...

#### `<body> ~ </body>`
- 실제로 웹 브라우저 화면에 나타나는 내용

~~~
<!DOCTYPE html>
<html lang="ko">
	<head>
    	<meta charset="UTF-8">
        <title>HTML Default Setting</title>
    </head>
    <body>
    	<h1>
        내용들
        </h1>
        <p>
        단락
        </p>
    </body>
    </html>