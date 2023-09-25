https://coding-factory.tistory.com/524
https://12bme.tistory.com/94
https://qna.programmers.co.kr/questions/654/%EC%9E%90%EB%B0%94%EC%97%90%EC%84%9C-static-%EB%B8%94%EB%A1%9D%EC%9D%80-%EB%AC%B4%EC%97%87%EC%9D%84-%EC%9D%98%EB%AF%B8%ED%95%98%EB%82%98%EC%9A%94
https://www.linkedin.com/pulse/static-variables-methods-java-where-jvm-stores-them-kotlin-malisciuc
https://jaemunbro.medium.com/java-metaspace%EC%97%90-%EB%8C%80%ED%95%B4-%EC%95%8C%EC%95%84%EB%B3%B4%EC%9E%90-ac363816d35e
https://www.linkedin.com/pulse/what-where-stack-heap-maxim-malisciuc/

Static
=======
- static이라 하면 : data가 어느 클래스의 인스턴스로써 **종속 되어 있지 않다**는 의미 이다.
> non-static method를 사용 하려면 그 메서드가 있는 인스턴스를 생성해야 되지만! <br> static 메서드는 어느 곳에도 종속 되어 있지 않음으로 바로 사용 할 수 있다.

static으로 선언하면?
----------------------------------
- 힙같지만 힙이 아닌 영역 **Metaspace**에 **저장** 됨
> JVM 8 이전과 이후 <br>
> <img width="535" alt="image" src="https://github.com/twkwon0417/TIL/assets/91003152/e49ab6b7-8f47-4aa7-9967-90d847e062d6">
> <img width="589" alt="image" src="https://github.com/twkwon0417/TIL/assets/91003152/df45ed95-668b-4e1f-a3e5-e17d184bcfbf">
> PermGen : 사이즈가 정해져 있음
> Metaspace : Auto-growing Space
<br>
- static 변수는 **JVM이 클래스를 load 했을 때 initialized됨**, 즉 처음으로 코드에서 레퍼런스 됬을 때 <br> 인스턴스가 처음 만들어 질 때 생성되는게 아니다.

  # 그럼 static 변수를 선언한 클래스의 인스턴스를 여러개 만들어도 그 static 변수는 1개로만 '공유' 되는 것인가? 그런득이라 예상
