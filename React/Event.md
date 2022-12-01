## Event를 다룰 때 흔히 쓰는 e객체는 React에서 무엇을 의미 하는가?
- e객체 : SyntheticEvent 웹 브라우저의 네이티브 이벤트를 감싸는 객체<br>순수 JS에서 HTML 핸들링 할때 똑같이 사용<br>이벤트가 끝나고 나면 이벤트가 초기화되어 정보를 참조 할 수 없다.(NativeEvent와 다른 점
- 비동기적으로 이벤트 객체를 참조 할 일이 있으면 e.persist()함수를 호출 해야한다.

~~~
e.target.value // => 현재 이벤트가 발생하고 있는 객체의 value를 가지고 옴
~~~
            
