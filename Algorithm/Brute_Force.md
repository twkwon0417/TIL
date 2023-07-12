fire
http://boj.kr/6eca2b27e3f84a14af220a09ef488606로 품 --> 시간 초과 --> 로직이 제대로 안되있는 줄 앎 --> 
http://boj.kr/55f8a7ce531142ac844801b4e6715928 --> 메모리 초과 남 --> visited 처리 안해서(같은 곳인데 계속해ㅠㅜ --> 
처음 비효율적인 로직 : http://boj.kr/eadfc0cdd47742dbb6ea7ad889a2109c
효율적인 로직 : http://boj.kr/12b6eabf33224f709704a5698a3a770f

#include <bits/stdc++.h>
using namespace std;

pair<int, int> p_road[300];
int n, m, k, ls[31][10], p1, p2, visited[31][10];

bool check(int y, int x){
    if(y == n + 1){
        if()
    }
    if(ls[y][x])
}

int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p1 >> p2;
        ls[p2][p1] = 1 ;
        ls[p2][p1 + 1] = 1;
    }
}

