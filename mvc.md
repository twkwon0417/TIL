### [[MVC Pattern]] 
1. Model, View, Controller로 이루어져 있음
2. 유저 인터페이스 코드를 만드는데 사용 되는 디자인 패턴
3. Controller가 중계자 역할로 model, view에 결합을 가지고 있다.

### Three tier
1. Presentation layer, business logic layer, data access layer로 이루어져 있음 
2. 큰 애플리케이션을 만드는데 사용되는 아키텍쳐 패턴
3. 각 계층이 약하게 결합되어 있고 api등으로 소통
---------
> Three tier에서 presentation layer을 만드는데 MVC패턴이 사용된다는데..?
>  > MVC랑 Three tier랑 닮은거 같은데 뭐가 뭔지 모르겠다...

왜 Presentation Layer에 MVC Pattern이 쓰일까?
---
1. 유저 인터페이스와 유저 상호작용에 관한 문제들을 분리하고 관리 하랴구

MVC의 Model에서도 business logic 처리하는데 three tier의 business layer은 왜 필요함??
---
Model : 보여지는 데이터를을 준비하고 유저 인터페이스의 상태를 관리함
Business layer : 핵심 비지니스 로직(데이터 검증, 데이터 처리 등등)


