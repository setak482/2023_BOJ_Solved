#include <bits/stdc++.h>
using namespace std;
int prev_cheese, cur_cheese;
int _map[101][101], max_x, max_y;
int _mov[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}};
queue<pair<int, int>> del_q;
void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    int visited[101][101];
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int dx = cx + _mov[0][i];
            int dy = cy + _mov[1][i];
            if(dx >= 0 && dy >= 0 && dx < max_x && dy < max_y && !visited[dy][dx]){
                if(_map[dy][dx] == 1){
                    del_q.push({dx, dy});
                    visited[dy][dx]++;
                }
                else{
                    q.push({dx, dy});
                    visited[dy][dx]++;
                }
            }
        }
    }
}
void solution(){
    int step = 0;
    while(true){
        step++;
        bfs();
        prev_cheese = cur_cheese;
        while(!del_q.empty()){
            pair<int, int> cur = del_q.front();
            del_q.pop();
            _map[cur.second][cur.first] = 0;
            cur_cheese--;
        }
        if(cur_cheese == 0){
            cout << step << '\n' << prev_cheese;
            break;
        }
    }
}
void input(){
    cin >> max_y >> max_x;
    for(int i = 0; i < max_y; i++){
        for(int j = 0; j < max_x; j++){
            int n; cin >> n;
            _map[i][j] = n;
            if(n == 1) cur_cheese++;
        }
    }
}
int main(){
    input();
    solution();
}