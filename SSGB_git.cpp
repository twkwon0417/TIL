#include <bits/stdc++.h>
using namespace std;

int n, k, ls[1000][8], r[1000][2], ans;
string str;

void rotate_tape(int tape, int way){
    int ttemp[8];
    for(int i = 0; i < 8; i++){
        ttemp[i] = ls[tape][i];
    }
    if(way = 1){
        int temp = ls[tape][7];
        for(int i = 0; i < 7; i++){
            ls[tape][i + 1] = ttemp[i];
        }
        ls[tape][0] = temp;
    }
    else{
        int temp = ls[tape][0];
        for(int i = 7; i >= 1; i--){
            ls[tape][i - 1] = ttemp[i]; 
        }
        ls[tape][7] = temp;
    }
}

void solve(int a, int way){
    int ori_way = way;
    vector<int> v;
    int tape = a - 1;
    int mag = ls[tape][6];
    int mag_r = ls[tape][2];
    for(int i = tape - 1; i >= 0; i--){    // left check;
        if(mag != ls[i][2]){
            v.push_back(i);
            mag = ls[i][6];
        }
        else break;
    }
    rotate_tape(tape, way);
    for(int i : v){
        way = -way;
        rotate_tape(i, way);
    }
    
    v.clear();
    for(int i = tape + 1; i < n; i++){    // right check;
        if(mag_r != ls[i][6]){
            v.push_back(i);
            mag_r = ls[i][2];
        }
        else break;
    }
    // rotate_tape(tape, way);
    for(int i : v){
        way = -ori_way;
        rotate_tape(i, way);
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            cout << ls[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < 8; j++){
            ls[i][j] = str[j] - '0';
        }
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            cout << ls[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> r[i][0] >> r[i][1];
    }
    
    for(int i = 0; i < k; i++){
        solve(r[i][0], r[i][1]);
    }
    for(int i = 0; i < n; i++){
        if(ls[i][0]) ans++;
    }
    cout << ans;
}
