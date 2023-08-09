#include <bits/stdc++.h>
using namespace std;

int n, m, k, ls[50][50], ori[50][50], ans = 987654321;
vector<tuple<int, int, int>> v;
vector<int> sol_v;

int getAns(){
    int ret = 987654321;
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j < m; j++){
            temp += ls[i][j];
        }
        ret = min(ret, temp);
    }
    return ret;
}

void rotate(int r, int c, int s){
    int temp[50][50];
    copy(&ls[0][0], &ls[0][0] + 250, &temp[0][0]);
    for(int i = r - s - 1; i <= r + s - 1; i++){
        for(int j = c - s - 1; j <= c + s - 1; j++){
            temp[i][j] = ls[n - j - 1][i];
        }
    }
    copy(&temp[0][0], &temp[0][0] + 250, &ls[0][0]);
}

void solve(int com){
    if(sol_v.size() == k){
        for(int x : sol_v){
            int a, b, c;
            tie(a, b, c) = v[x];
            rotate(a, b, c);
        }
        int temp = getAns();
        ans = min(ans, temp);
        copy(&ori[0][0], &ori[0][0] + 250, &ls[0][0]);
        return;
    }
    for(int i = com + 1; i < k; i++){
        sol_v.push_back(i);
        solve(i);
        sol_v.pop_back();
    }
    return;
}

int main(){
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> ori[i][j];
    }
    copy(&ori[0][0], &ori[0][0] + 250, &ls[0][0]);
    for(int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    // solve(-1);
    // cout << ans;
    
    // debug
    rotate(2, 3, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ls[i][j] << " ";
        }
        cout << "\n";
    }
}
