// BOJ 14940 - 쉬운 최단거리
#include <bits/stdc++.h>
using namespace std;
int _map[1001][1001], xBorder, yBorder;
struct INFO{int x, y, cnt;};
queue<INFO> q;
bool visited[1001][1001];
int _step[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
void input(){
    cin >> yBorder >> xBorder;
    for(int i = 0; i < yBorder; i++){
        for(int j = 0; j < xBorder; j++){
            int a; cin >> a;
            if(a == 2){
                q.push({j, i, 0});
                visited[i][j] = true;
            }
            if(a != 0) _map[i][j] = -1;
        }
    }
}
void bfs(){
    while(!q.empty()){
        int cx = q.front().x, cy = q.front().y, ccnt = q.front().cnt;
        q.pop();
        _map[cy][cx] = ccnt;
        for(int i = 0; i < 4; i++){
            int dx = cx + _step[0][i], dy = cy + _step[1][i];
            if(dx < 0 || dy < 0 || dx >= xBorder || dy >= yBorder || visited[dy][dx] || _map[dy][dx] == 0) continue;
            q.push({dx, dy, ccnt+1});
            visited[dy][dx] = true;
        }
    }
}
void print(){
    for(int i = 0; i < yBorder; i++){
        for(int j = 0; j < xBorder; j++){
            cout << _map[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    bfs();
    print();
}