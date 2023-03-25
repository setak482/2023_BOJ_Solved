#include <bits/stdc++.h>
using namespace std;
struct Node{int x, y, d;};
struct Area{int x1, y1, x2, y2;};
Area death[51], danger[51];
int ans, dtmax, dgmax, move_set[2][4] = {{1, 0, -1, 0},{0, 1, 0, -1}};
int visited[502][502] = {0, };
deque<Node> q;
int bfs(){
    q.push_front({0, 0, 0});
    visited[0][0] = 1;
    while(true){
        if(q.empty()) return -1;
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop_front();
        if(x == 500 && y == 500){return d;}
        for(int i = 0; i < 4; i++){
            int dx = x + move_set[0][i], dy = y + move_set[1][i], flag1 = 0, flag2 = 0;
            if(dx < 0 || dx > 500 || dy < 0 || dy > 500 || visited[dy][dx]) continue;
            for(int j = 0; j < dtmax; j++){
                Area cdt = death[j];
                if(dx >= min(cdt.x1, cdt.x2) && dy >= min(cdt.y1, cdt.y2) && dx <= max(cdt.x1, cdt.x2) && dy <= max(cdt.y1, cdt.y2)){flag1 = 1; break;}
            }
            if(flag1 == 1) continue;
            for(int j = 0; j < dgmax; j++){
                Area cdg = danger[j];
                if(dx >= min(cdg.x1, cdg.x2) && dy >= min(cdg.y1, cdg.y2) && dx <= max(cdg.x1, cdg.x2) && dy <= max(cdg.y1, cdg.y2)){
                    visited[dy][dx] = 1;
                    q.push_back({dx, dy, d+1});
                    flag2 = 1; break;
                }
            }
            if(flag2 == 1) continue;
            visited[dy][dx] = 1;
            q.push_front({dx, dy, d});
        }
    }
}
int main(){
    cin >> dgmax;
    for(int i = 0; i < dgmax; i++)
        cin >> danger[i].x1 >> danger[i].y1 >> danger[i].x2 >> danger[i].y2;
    cin >> dtmax;
    for(int i = 0; i < dtmax; i++)
        cin >> death[i].x1 >> death[i].y1 >> death[i].x2 >> death[i].y2;
    cout << bfs();
}