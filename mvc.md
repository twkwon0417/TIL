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

bold되 있는 특징은 굉장히 많은 이점을 가지고 오지요 허허허

애플리케이션이 어떻게 계층으로 나뉠수 있는가?
------
![Web Application](https://github.com/twkwon0417/TIL/assets/91003152/0849713b-404b-4352-993f-2546f9ea823e)
- 애플리케이션은 HTML document를 주고 받으며 통해 웹 브라우져와 소통한다. 이러한 코드들을 비지니스 로직으로 부터 분리 할수 있다.
- 애플리케이션이 데이터베이스와 SQL문을 주고 받으며 소통하는데, 이런 코드들을 비지니스 로직으로 부터 분리할 수 있다.

레이러라고 부르려면 각 계층의 책임영역이 확실해야 하고, 그에 맞는 코드들이 계층에 들어가야 한다.
1. Presentation Logic : 데이터을 보여주고 사용자의 입력값을 받는 유저 인터페이스 (SQL reponse, request)
2. Business(domain) Logic : 데이터 검증, 비지니스 규칙, 특정 행동들을 관리한다.
3. Data Access Logic : 데이터베이스와 소통한다. (SQL, api...etc)

3 Tier Architecture : 규칙
-----
![3-tier-architecture request   response](https://github.com/twkwon0417/TIL/assets/91003152/634a588d-d70b-4992-a886-9761e0371388)

- 각 계층의 코드들은 개별적으로 관리될 수 있게 분리된 파일에 있어야 한다.
- 각 계층은 자기 계층에 맞는 코드만 있어야 한다.
- Presentation Layer은 외부(user)로 부터 요청을 받거나 보낼수 있다.
- Presentation Layer은 business layer에게 요청을 주거나 답을 받을수 있다. (vice versa)
- Business Layer은 Data Access layer 에게 요청을 주거나 답을 받을수 있다. (vice versa)
- 각 레이어들은 다른 레이어의 내부를 알고 있으면 안된다. (그러면 의존성이 생기게 된다)

MVC랑 3-Tier architecture랑 같은 거 아닌가?
-----
![3-tier vs mvc](https://github.com/twkwon0417/TIL/assets/91003152/9edf9c72-560e-4ad1-9bf0-eda15bad95c8)
![3tier vs mvc 2](https://github.com/twkwon0417/TIL/assets/91003152/1d7bd41c-ab6c-4f92-a28d-dde4e8c7c861)
- 중요 차이 : MVC pattern은 business layer과 data access layer가 분리 되어 있지 않다.
  - 이에 따라 controller가 db의 연결을 담당하고, model에서 데이터베이스 연결 객체를 만들어 필요할때 사용된다. 

3 Tier Architecture가 주는 이점
-----
- 유연성 : 3가지 로직으로 분히 되어있어 변화에 유연하게 대처할수 있다.
- 유지보수 : 한 계층의 요소를 변경해도 다른 계층엔 영향을 미치지 않아 유지보수가 쉬워 진다.
- 재사용성 : 재사용 할수 있는 구성요소의 구현이 쉬워진다. (eg. Business Layer에 있는 한 요소가 여러 Presentation Layer 요소에서 사용 될수 있다.)
- 확장성 : 여러 서버에 애플리캐이션의 요소들을 배분할수 있도록 하여 확장성이 커진다. 

https://softwareengineering.stackexchange.com/questions/299836/difference-between-3-tier-architecture-and-mvc-model-view-controller-in-asp-n
https://velog.io/@chlee4858/3-tier-vs-MVC
https://tjdtls690.github.io/studycontents/java/2023-04-24-service_layer/
https://levelup.gitconnected.com/how-to-differentiate-business-and-service-layers-in-layered-architecture-912123b2ccf1

https://learn.microsoft.com/en-us/answers/questions/833560/is-mvc-a-design-pattern-or-an-architectural-patter
https://www.c-sharpcorner.com/UploadFile/abhikumarvatsa/what-is-model-and-viewmodel-in-mvc-pattern/
