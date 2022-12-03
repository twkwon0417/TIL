## JSX에서는 Component Array를 구현 할 수 있다.
~~~
//..... name이라는 Array
const nameList = names.map(name => <li>{name}</li>);
return <ul>{nameList}</ul>;
~~~

## 리액트에서의 key
- 리액트에서 key는 컴포넌트 배열을 렌더링했을 때 어떤 원소에 변동이 있었는지 알아내려고 사용합니다.
key가 없을 때는 Virtual DOM을 비교하는 과정에서 리스트를 순차적으로 비교하면서 변화를 감지하지만 key값을 가지고 비교하는 것 보다 오래 걸린다. 
- key값은 고유해야 한다!
- **그럼 다른 Component들도 고유 key값을 지정해 줘야되지 않나? 왜 배열일때만 따로 지정해 줄까?**
  - https://stackoverflow.com/questions/68744179/are-keys-necessary-only-on-arrays-in-react
  - https://stackoverflow.com/questions/28329382/understanding-unique-keys-for-array-children-in-react-js

~~~
const IterationSample = () => {
  const names = [..........]  // Data 값들
  const namesList = names.map((name, index) => <li key={index}>{name}</li>;
  return <ul>{namesList}</ul>;
};
~~~

## 새로운 배열을 만들때 기존 배열을 해치지 말자
- **React의 불변성 유지** : 상태를 업데이트할 때는 기존 상태를 기존 상태를 그대로 두면서 새로운 값을 상태로 설정해야
나중에 리액트 컴포넌트의 성능을 최적화할 수 있다. 
