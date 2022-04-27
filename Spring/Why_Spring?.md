# Spring은 객체 지향적 설계를 쉽게 하기 위해서 만들어진 Framework
- 모든 설계에 역활과 구현을 분리하 -> 유연하게 개발(변경) 가능
- OCP, DIP 등등을 DI, IoC 등등으로 쉽게 해결 가능
- 설계 할 때 AppConfig와 같은 Configuration파일을 따로 만들지 않으면 DIP, OCP와 같은 객체 지향이지 못하게 된다
- AppConfig 파일을 만들어서 관리 하면 되는데 이러면 repository와 같은 객체가 여러개 생성 된다. Singleton같은 거 안쓰면
- 위와 같은 문제를 해결하기 위해서 Spring Container, DI, IoC와 같은 기술이 등장
- 우리가 직접 Config(기획하는 느낌) 파일로 관리 할 수도 있고 Component Scan등을 활용해서 Spring이 자동으로 관리하게 할 수도 있음