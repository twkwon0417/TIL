# Singleton Container

## Why Singleton
- 처음 Swing으로 단어장을 만들었을때 단어들을 저장하는 VocManger객체를 계속 생성해야하는게 불-편 했는데 이 문제를 쉽게 해결하게 해준다.
- 특정 Service를 계속해서 요청 할 떄마다 새로운 객체를 만드는게 아니라, 한 객체를 만들고 공유하게 만드는 것 -> 메모리 낭비 없음

## Singleton Design Pattern
- 테스트 하기 어려워, DIP 위반해, 유연성이 많이 떨어져 등등
- 결론 : 안티패턴이라 불릴 만큼 선호되지 않음
- 더 많은 정보는 찾아보자 : https://gmlwjd9405.github.io/2018/07/06/singleton-pattern.html

## Spring Singleton Container
- Bean으로 등록 시킨게 default로 Singleton으로 관리 된다.(Singleton말고 다른 방식으로도 관리 가능)
- Spring Container은 Singleton Container이 역활, 이렇게 Singleton 객체를 생성 관리 : Singleton registry라고 한다.

## Singleton을 쓸 때 주의할 점
- 한 객체를 공유한다, 따라서 Stateful하게 설계하면 안된다.
- Stateless!
    - 특정 클라이언트에 의존적인 필드가 있으면 안된다.
    - 값이 변할수 있게 설계하면 안됨, 가급적 읽기만 가능하게 설계
    - Bean의 필드에 공유값을 설정하지 말자 (공유필드 X!)

