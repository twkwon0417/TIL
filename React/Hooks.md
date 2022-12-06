## Hook은 왜 필요한가?
- With Hooks, you can extract stateful logic from a component so it can be tested independently and reused.

- **useState** : 함수형 컴포넌트에서 state를 사용할수 있게 해준다. 많이 사용 해 봤으니까 생략!
- **useEffect** : React Component가 rendering 될 때마다 특정 작업을 수행하도록 설정할 수 있게 한다. componentDidMount와 componentDidUpdate를 합친 형태로 볼 수 있다. 기본적으로 렌더링이 된 직후 실행된다.
  - ~~~
    import React, { useEffect } from 'react';
    
    // 기본 형태
    useEffect(function, deps);
    // function : rendering시 수행할 함수
    // deps : 배열 형태이며, 배열 안에는 검사하고자 하는 특정 값 또는 배열 (Optional)
    // => rendering시에 함수가 실행되는 것이 아니라 배열안의 값이 변경 될때만 함수가 호출 된다. 
    // => 빈 배열의 경우에는 Mount될때 만 함수가 실행되고 re-rendering 될 때는 실행되지 않는다.
    ~~~ 
- **useReducer** : redux 공부하고 다시 봅시다. 
- **useMemo** : 렌더링하는 과정에서 특정 값이 바뀌었을 때만 함수를 실행하고, 지정한 값이 바뀌지 않았다면 이전의 함수 결괏값을 다시 사용
  - ~~~
    import React, { useMemo } from 'react';
    
    // 기본 형태
    useMemo(function, deps);
    // function : rendering시 수행할 함수
    // deps : 배열 형태이며, 배열 안에는 검사하고자 하는 특정 값 또는 배열 
    ~~~
    
 - **useCallback** : 만들어 놨던 함수를 재사용할 수 있다. 렌더링 성능을 최적화 해야 하는 상황에서 사용
   - useCallback을 쓰지 않으면 re-rendering 될때마다 새로운 함수를 생성하고 사용하게 된다. 
   - ~~~
     import React, { useCallback } from 'react';
    
     // 기본 형태
     useMemo(function, deps);
     // function : 생성하고 싶은 함수
     // deps : 배열 형태이며, 배열 안에는 검사하고자 하는 특정 값 또는 배열, 감지되면 함수를 새로 생성한다. 비여도 상관 없으
     ~~~
    
- **useRef(1)** : 함수 컴포넌트에서 ref를 쉽게 사용할수도 해줌
  - ~~~
    import { useRef } from 'react';
    
    const refName = useRef(); //  Otional Parameter은 .current 값의 기본값, 수정 할때에는 .current 값을 수정, 조회 할 때에는 .current 를 조회하면 됩니다.
    ~~~
    
- **useRef(2)** : 함수형 Component에서 굳이 값이 바뀌어도 리렌더링 하지않을 값을 관리하고 싶을 때 사용 할 수도 있다.
  - 굳이 왜 useRef를 사용할까? : <a href="https://stackoverflow.com/questions/57444154/why-need-useref-and-not-mutable-variable" target="_blank">Stackoverflow 링크</a>

  - ~~~
    const nextId = useRef(4); // parameter은 
  
    const onCreate = () => {
    console.log(nextId.current);  // 4
    nextId.current += 1;  // 5,6,7...
    }
    ~~~
    
