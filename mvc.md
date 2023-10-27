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


https://softwareengineering.stackexchange.com/questions/299836/difference-between-3-tier-architecture-and-mvc-model-view-controller-in-asp-n
https://velog.io/@chlee4858/3-tier-vs-MVC
https://tjdtls690.github.io/studycontents/java/2023-04-24-service_layer/
https://levelup.gitconnected.com/how-to-differentiate-business-and-service-layers-in-layered-architecture-912123b2ccf1
