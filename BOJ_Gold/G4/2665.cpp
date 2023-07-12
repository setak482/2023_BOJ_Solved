#include <bits/stdc++.h>
#define MAX_SIZE 51
using namespace std;
int _map[MAX_SIZE][MAX_SIZE], border,
_step[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}},
visited[MAX_SIZE][MAX_SIZE];
struct INFO{int x, y, cnt;};
int bfs(){
    deque<INFO> dq;
    visited[1][1]++;
    dq.push_front({1, 1, 0});
    while(!dq.empty()){
        INFO cur = dq.front();
        dq.pop_front();
        if(cur.x == border && cur.y == border) return cur.cnt;
        for(int i = 0; i < 4; i++){
            int dx = cur.x + _step[0][i];
            int dy = cur.y + _step[1][i];
            if(dx < 1 || dy < 1 || dx > border || dy > border || visited[dy][dx]) continue;
            if(_map[dy][dx]){
                dq.push_front({dx, dy, cur.cnt});
                visited[dy][dx]++;
            } 
            else{
                dq.push_back({dx, dy, cur.cnt+1});
                visited[dy][dx]++;
            }
        }
    }
}
int main(){
    cin >> border;
    for(int i = 1; i <= border; i++){
        for(int j = 1; j <= border; j++){
            scanf("%1d", &_map[i][j]);
        }
    }
    cout << bfs();
}