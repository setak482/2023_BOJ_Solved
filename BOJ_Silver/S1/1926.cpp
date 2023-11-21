#include <bits/stdc++.h>
#define repeat(i, n) for(int i = 0; i < n; i++)
#define SIZE 502
using namespace std;
struct POINT{int x, y;};
bool visited[SIZE][SIZE];
int _map[SIZE][SIZE];
int _step[2][4] = {{1,0,-1,0},{0,1,0,-1}},
    x_max, y_max;

int bfs(POINT init){
    int _cnt = 0;
    queue<POINT> q;
    q.push(init);
    visited[init.y][init.x] = true;
    while(!q.empty()){
        POINT cur = q.front();
        q.pop();
        _cnt++;
        repeat(i, 4){
            int dx = cur.x + _step[0][i],
                dy = cur.y + _step[1][i];
            if(!visited[dy][dx] && _map[dy][dx] &&
                dx >= 0 && dy >= 0 && dx < x_max && dy < y_max){
                q.push({dx, dy});
                visited[dy][dx] = true;
            }
        }
    }
    return _cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _max = 0, _cnt=0;
    cin >> y_max >> x_max;
    repeat(i,y_max) repeat(j, x_max) cin >> _map[i][j];
    repeat(i,y_max){
        repeat(j, x_max){
            if(visited[i][j]==false && _map[i][j]==1){
                _max = max(_max, bfs({j, i}));
                _cnt++;
            }
        }
    }
    cout << _cnt << '\n' << _max;
}