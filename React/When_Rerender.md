## React는 언제 Rerendering 될까?
- https://velog.io/@surim014/react-rerender
> **상태를 변경한다는 것은 setState 함수(React hooks에서는 useState)를 실행할 때, React 트리거가 업데이트된다는 것을 의미합니다.** 
  이는 컴포넌트의 render 함수가 호출된다는 것을 의미할 뿐만 아니라, props 변경 여부와 관계없이 모든 하위 컴포넌트들이 리렌더링 된다는 것을 의미합니다.
  -> 그냥 jsx에서 쓰이는 변수들을 수정한다고 React가 rerendering 되는 것은 아님
