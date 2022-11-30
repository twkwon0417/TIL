## state의 의미
- React에서의 state : 컴포넌트 내부에서 비뀔 수 있는 값을 의미, 그냥 props는 부모 컴포넌트에서 수정을 하여야 하는데 state의 경우는 자기자신을 수정 할 수 있음



#### this.setState의 비동기 처리
- 비동기 처리란 : 동기적으로 위에서 아래로 처리 되는 것이 아니라 한번에 처리된다는 뜻, 요청한 결과에 대한 응답을 바로 받지 않아도 됨
~~~
this.state = { number: 0, nextNumber: 0, nextNextNumber: 0 }

this.setState({ number: number + 1 });
this.setState({ nextNumber: number + 1 });
this.setState({ nextNextNumber: nextNumber + 1 });

console.log(number);
console.log(nextNumber);
console.log(nextNextNumber);

// 1
// 1
// 1
~~~
