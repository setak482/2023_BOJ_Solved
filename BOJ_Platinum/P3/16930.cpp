#include <bits/stdc++.h>
#define INF 998998998
using namespace std;
struct Node{int x, y;};
int dist[1001][1001];
char cmap[1001][1001];
queue<Node> q;
int maxx, maxy, maxmov, sx, sy, ex, ey, movset[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
int bfs(){
    q.push({sx, sy});
    dist[sy][sx] = 0;
    while(true){
        if(q.empty()) break;
        int cx = q.front().x, cy = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            for(int j = 1; j <= maxmov; j++){
                int dx = cx + (movset[0][i] * j);
                int dy = cy + (movset[1][i] * j);
                if(dx < 1 || dy < 1 || dx > maxx || dy > maxy || cmap[dy][dx] == '#' || dist[dy][dx] < dist[cy][cx] + 1){
                    break;
                }
                if(dist[dy][dx] == INF){
                    dist[dy][dx] = dist[cy][cx] + 1;
                    q.push({dx, dy});
                }
            }
        }
    }
    return dist[ey][ex] == INF ? -1 : dist[ey][ex];
}
int main(){
    cin >> maxy >> maxx >> maxmov;
    for(int i = 1; i <= maxy; i++){
        for(int j = 1; j <= maxx; j++){
            cin >> cmap[i][j];
            dist[i][j] = INF;
        }
    }
    cin >> sy >> sx >> ey >> ex;
    cout << bfs();
}