#include <bits/stdc++.h>
using namespace std;

    // 흰 : 엎고 ㄱ
    // 빨 : 엎은 상태로 오면 온 친구들만 반대로 정렬
    // 파 : 이동방향 reverse & 한칸만 이동, 만약 뒤 한칸도 파랑 -> 가만히
    // 행, 열, 이동방향 0 ~ 3 오, 왼, 위, 아래
int n, k, ls[13][13], ret;
vector<pair<int, int>> mal[13][13];    //번호, 이동 방향

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ls[i][j];
        }
    }
    int a, b, c;
    for(int i = 0; i < k; i++){
        cin >> a >> b >> c;
        mal[a - 1][b - 1].push_back(i + 1, c - 1);
    }
    
    while(ret <= 1000){ // 처음 친구만 계산하고 업힌애랑 안 업힌해 구분해서 별도의 벡터에 넣어
        for(int ffind = 1; ffind <= k; ffind++){    // 계산 값 위치에mal[ny][nx]에 push_back
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(!mal[i][j].size()) continue;
                    pair<int, int> flag = {-1, -1};   // 이동방향, 말 번호
                    bool red = false;
                    vector<pair<int, int>> no_temp;    // 안 이동한 친구들
                    for(auto pawn : mal[i][j]){
                        if(pawn == ffind){
                            if(flag.first){// 뒤에 친구들 해결
                                
                            }
                            if(pawn.second == -1){    // 오, 왼
                                if(j + pawn.first >= n){
                                    blue(); // 새로운 위치에 push_back해줄것임
                                }
                                else{
                                    if(ls[i][j + pawn.first] == 0){  // 흰 빨 파
                                        white();
                                    }
                                    else if(ls[i][j + pawn.first] == 1){
                                        red();
                                        red = true;
                                    }
                                    else blue();
                                }
                            }
                            else if(pawn.second == 1){             
                                if(j - pawn.first < 0){
                                    blue();
                                }
                                else{
                                    if(ls[i][j - pawn.first] == 0){  // 흰 빨 파
                                        white();
                                    }
                                    else if(ls[i][j - pawn.first] == 1){
                                        red();
                                        red = true;
                                    }
                                    else blue();
                                }
                            }
                            else if(pawn.second == 2){      // 위, 아래
                                if(i - pawn.first < 0){
                                    blue();
                                }
                                else{
                                    if(ls[i - pawn.first][j] == 0){  // 흰 빨 파
                                        white();
                                    }
                                    else if(ls[i - pawn.first][j] == 1){
                                        red();
                                        red = true;
                                    }
                                    else blue();
                                }
                            }
                            else{
                                if(i + pawn.first >= n){
                                    blue();
                                }
                                else{
                                    if(ls[i + pawn.first][j] == 0){  // 흰 빨 파
                                        white();
                                    }
                                    else if(ls[i + pawn.first][j] == 1){
                                        red();
                                        red = true;
                                    }
                                    else blue();
                                }
                            }
                            flag = 
                        }
                        else{
                            temp.push_back({mal[i][j].first, mal[i][j].second});
                        }
                    }
                    mal[i][j] = no_temp;
                }
            }
        }
    }
}
