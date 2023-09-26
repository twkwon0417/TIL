Stack
-----------
1. Operating System에 의해 사이즈가 제한되어 있다.
2. Heap 보다 빠르다.
3. 작은 data type을 저장하는데만 사용 된다. (변수, 객체 주소등)
4. Stack에 있는 변수와 레퍼런스는 local scope를 가지고 있어서 stack memory block에 한에서 접근 가능하다.

Heap
-----
1. 사이즈 제한이 없다. (하드웨어의 램 용량에 따름)
2. Stack보다 느리다.
3. 모든 클래스의 인스턴스들이 저장 되어있다.
4. 힙에 있는 데이터들은 global scope로써 어디에서든 접근 가능하다.

java에서
--------
Class의 instance를 만들때 힙에 instance의 정보 등을 저장하고 stack에 reference pointer(주소)을 stack에 반환
<br> heap의 정보에 접근 하고 싶을때는 stack에 있는 reference pointer를 참고해서 접근 함
