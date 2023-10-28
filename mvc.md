### [[MVC Pattern]] 
1. Model, View, Controller로 이루어져 있음
2. 유저 인터페이스 코드를 만드는데 사용 되는 디자인 패턴
3. Controller가 중계자 역할로 model, view에 결합을 가지고 있다.

### [[Three tier]]
1. Presentation layer, business layer(Service layer), data access layer로 이루어져 있음 
2. 큰 애플리케이션을 만드는데 사용되는 아키텍쳐 패턴
3. 각 계층이 약하게 결합되어 있고 api등으로 소통
---------
> Three tier에서 presentation layer을 만드는데 MVC패턴이 사용된다는데..?
>  > MVC랑 Three tier랑 닮은거 같은데 뭐가 뭔지 모르겠다...

애초에 둘을 비교하는 거 자체가 좀 이상하다.
-----
[apple vs apple core.jpg]
Three tier architecture가 MVC Pattern을 더 크게 만들었다고 보는게 맞는거 같다. 
두 개념이 겹치는 부분은 business logic layer과 MVC의 Model이다. 
Three tier architecture와 MVC Pattern은 겹치는 부분이 있지만 대부분 별개이다. 
다만, 결합을 없애고 큰 시스템을 분리하려는 같은 목표를 가지고 있다. 

왜 Presentation Layer에 MVC Pattern이 쓰일까?
---
1. 유저 인터페이스와 유저 상호작용에 관한 문제들을 분리하고 관리 하랴구

MVC의 Model에서도 business logic 처리하는데 three tier의 business layer은 왜 필요함??
---
Model : **보여지는** 데이터를을 준비하고 유저 인터페이스의 상태를 관리함
Business layer : 핵심 비지니스 로직(데이터 검증, 데이터 처리 등등)을 책임짐

https://www.tonymarston.co.uk/php-mysql/3-tier-architecture.html 번역 ㅋㅋㅋ
=====================================
- Aplying UML and ptterns에서 Craig Larman의 3tier architecture정의
> 1. Presentation : 창, 경고창 등등
> 2. Application Logic : 프로세스를 관장하는 규칙과 업무
> 3. Storage : 데이터 영속성 메카니즘
>
> 3티어 아키텍쳐의 최고 장점은 로직티어가 중간에 위치함으로써 애플리케이션 로직이 나위어진다는 것이다. 이로써 프레젠테이션 티어는
> 미들 티어에게 무엇을 해야하는지 요청을 줌으로써, 로직처리부터 상대적으로 자유로워 졌다. 미들 티어는 back-end storage layer와 소통
> 객체지향적 정보 시스템의 계층구조로써 추천되는 것은 클래식 책이 분리되어 있는 클래식 3티어 아키텍쳐이다. 책임들을 소프트웨어 객체들에게 할당 된다.


Note here that he created a direct link between the separation of responsibilities and the 3-Tier Architecture some 6 years before Robert C. Martin published his first article on the Single Responsibility Principe (SRP) in 2003.

계층이란 무엇인가?
-----
> **계층의 특징**
> - 각 계층들은 각자 구성될수 있어야 한다. (어떤 사람이나 팀이 각자 특정 계층을 개발하는 것 처럼)
> - 각 계층들은 "무언가"를 만들기 위해 조립될수 있어야 한다.
> - 각 계층들은 "무언가"에게 기여할수 있어야 하며 그 기여들은 각각의 계층마다 달라야 한다.
> - 각 계층들 간에는 경계선이 있어야 한다. (각 계층별로 정확히 구분 할수 있어야 하기 때문)
> - 각 계층들은 협력하여야만 실행되여야 하고 독립적으로 실행 될 수 없어야 한다.
> - **각 계층들은 그 계층과 비슷한 역활을 하는 요소로 교체된다하더하도 애플리케이션은 계속 실행될수 있어야 한다.**
> - 주로 같은 서버에서 실행 되겠지만, 각 계층을 다른 서버에서 돌리면 이점이 있을 수도 있다.

bold되 있는 특징은 굉장히 많은 이점을 가지고 오지요


https://softwareengineering.stackexchange.com/questions/299836/difference-between-3-tier-architecture-and-mvc-model-view-controller-in-asp-n
https://velog.io/@chlee4858/3-tier-vs-MVC
https://tjdtls690.github.io/studycontents/java/2023-04-24-service_layer/
https://levelup.gitconnected.com/how-to-differentiate-business-and-service-layers-in-layered-architecture-912123b2ccf1
