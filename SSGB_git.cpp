#include <bits/stdc++.h>
using namespace std;

int n, ls[24][24], visited[24][24], size = 2, ans;
pair<int, int> b_shark;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> ls[i][j];
            if(ls[i][j] == 9){
                b_shark.first = i;
                b_shark.second = j;
                ls[i][j] == 0;
            } 
        }
    }
    while(1){
        bool flag = false;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({b_shark.first, b_shark.second});
        visited[q.front().first][q.front().second] = 1;
        while(q.size()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if(visited[ny][nx]) continue;
                if(ls[ny][nx] > size){
                    visited[ny][nx]++;
                    continue;
                }
                if(ls[ny][nx] && ls[ny][nx] <= size){
                    size++;
                    ls[ny][nx] = 0;
                    ls[q.front().first][q.front().second] = 0;
                    b_shark = {ny, nx};
                    ans += visited[y][x];
                    flag = true;
                    break;
                }
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
        if(!flag) break;
    }
    cout << ans;
}
