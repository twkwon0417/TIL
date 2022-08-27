# 비구조화 할당 (객체 분해)
#### 말 그대로 객체를 분해 한다.
##### 분해되는 객체 요소의 이름과 분리되는 변수의 이름이 같아야 함을 주의

~~~
const Me = {
  name: "Tony",
  age: 21
}

const {name, age} = Me;

console.log(name);
console.log(age);
// Tony
// 21
~~~
#### 함수 parameter에서도 사용 가능
~~~
const Me = {
  name: "Tony",
  age: 21
}

function print({ name, age }) {
  console.log(name);
  console.log(age);
}

print(Me);
~~~

#### 배열에서도 사용 가능
~~~
const array = [1, 2];
const [one, two] = array;

console.log(one);
console.log(two);
~~~

#### 비구조화 할당으로 값 수정하기
~~~
const Me = {
  name: 'Tony',
  age: 21
};

const { name: '권태완' } = Me;
console.log(Me);
// {name: '권태완', age: 21}
