## 컴포넌트의 라이프사이클
- 크게 3가지 단계로 나눈다.
  - **Mount** : DOM이 생성되고 웹 브라우저상에 나타는 것
  - **Update** : props, state가 바뀔때, 부모 컴포넌트가 리레더링될 때, this.forceUpdate로 강제로 렌더링을 트리거 할때
  - **Unmount** : 컴포넌트를 DOM에서 제거하는 것

- 라이프 사이클 메서드 간략 분류
  - **Will이 접두사로** : 어떤 작업을 작동하기 **전** 실행되는 메서드
  - **Did가 접두사로** : 어떤 작업을 작동한 **후** 실행되는 메서드
 
![React 16.4이후의 life Cycle](https://user-images.githubusercontent.com/91003152/205493376-35022980-e83e-40ed-b148-88c025bd09fb.png)

### Mount
- **constructor** : 컴포넌트를 새로 만들 때마다 호출되는 클래스 생성자 메서드
- **getDerivedStateFromProps** : props에 있는 값을 state에 넣을 때 사용하는 메서드
- **render** : 준비힌 UI를 렌더링하는 메서드
- **componentDidMount** : 컴포넌트가 웹 브라우저상에서 나타난 후 호출하는 메서드

### Update
- **getDerivedStateFromProps** : Mount에서와 같다.
- **shouldComponentUpdate** : 컴포넌트가 리렌더링을 해야 할지 말아야 할지를 결정하는 메서드, true 혹은 false를 반환
이에 따라 다음 단계로 넘어갈지 결정, 하지만 this.forceUpdate() 호출시 이 과정을 생략하고 바로 render함수를 호출
- **getSnapshotBeforeUpdate** : 컴포넌트 변화를 DOM에 반영하기 바로 직전에 호출하는 메서드
- **componentDidUpdate** : 컴포넌트의 업데이트 작업이 끝난 후 호출하는 메서드

### Unmount
- **componentWillUnmount** : 컴포넌트가 웹 브라우저상에서 사라지기 전에 호출하는 메서드
