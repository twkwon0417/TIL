#include <bits/stdc++.h>
using namespace std;

int n, ls[20][20], temp[20][20];

void r_check(int x){
    memset(temp, 0, sizeof(temp));
    for(int i = 0; i < n; i++){
        stack<pair<int, int>> stk;
        for(int j = 0; j < n; j++){
            int temp_j = j;
            // if(j == 0){
            //     if(x == 0) stk.push(ls[i][n - 1]);
            //     else stk.push(ls[i][j]);
            //     continue;
            // }
            if(x == 0) j = n - 1 - j;
            if(stk.size() && !stk.top().second && stk.top().first == ls[i][j]){
                stk.pop();
                stk.push({ls[i][j] * 2, 1});
            }
            else stk.push({ls[i][j], 0});
            j = temp_j;
        }
        int cnt = stk.size();
        for(int j = 0; j < cnt; j++){
            int temp_j = j;
            if(x == 0) j = 2 * cnt - n - j - 1;
            // cout << cnt - 1 - j << " ";
            temp[i][cnt - 1 - j] = stk.top().first;
            stk.pop();
            j = temp_j;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ls[i][j];
        }
    }
    r_check(0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << temp[i][j] << " ";
        cout << "\n";
    }
    
}
