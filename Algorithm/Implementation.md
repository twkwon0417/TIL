### <a href="https://www.acmicpc.net/source/62065989" target="_blank"> BOJ 9996</a>
- 간단하게 split을 구현해서 앞에꺼 뒤에꺼를 받아서 비교하면 된다. 
- str.substr(0)와 같이 substr할 size가 없을시 **문자열 끝까지 substr한다**.

### <a href="https://www.acmicpc.net/source/62077371" target="_blank"> BOJ 2559</a>
- 처음에는 사이즈 5 list만들어 순회하면서 앞값을 빼고 새로운 값을 추가하며 비교해나가게 짰다.
- prefix sum을 연습할 수 있는 좋은 문제이다.
- n ~ m값들의 합을 구하려면 **psum[m] - psum[n - 1]**
- psum[i] = psum[i - 1] + i **따라서 psum[]은 index 1부터 하는게 편하다.**

### <a href="https://www.acmicpc.net/source/62077967"> BOJ 1620</a>
- 시간제한이 빡빡해서 **ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);** 필수
- 메모리 충분하면 그냥 배열 여러개 선언하자. 굳이 하나로 객기 부리지 말고

### <a href="https://www.acmicpc.net/source/62080239"> BOJ 1213</a>
- cpp에서도 java처럼 string += 가능, **string += char도 가능**

### <a href="https://www.acmicpc.net/source/62114714"> BOJ 3986</a>
- 풀이가 잘 보이지 않을 때는 **입력을 추가해보기, 입력값 회전시켜 보자**
- **stack으로 폭파시키기! 짝 맞추기 폭파 --> stack일 수도?**

### <a href="https://www.acmicpc.net/source/62116467"> BOJ 1629</a>
- 숫자가 너무 커 : <a href="내가 정리한 깃허브"> **mod 연산자의 활용**</a>
- 시간 타이트 : **제곱이야 --> 2로 나눠서 log2N으로 시간 복잡도 줄이기 : 전에 구한 값 활용 가능(recursion 이용)**

### <a href="https://www.acmicpc.net/source/62117811"> BOJ 4375</a>
- 굳이 n의 배수를 구해야돼? --> 111111...을 n으로 나누자

### <a href="https://www.acmicpc.net/source/62161724"> BOJ 14719</a>
- **문제 풀기전 문제 파악 확실히 & 간략히 도식화**
- **코드 짜기 전 간략히 손코딩 하자, 코드 짜는데 시간 감소 & 오류 줄일수 있다. --> debugging에 시간 할애 down!!!**
- **코드 다 짜고 변수 초기화 언제 되는지 신경쓰기**
