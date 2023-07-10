#include <bits/stdc++.h>
using namespace std;
int _step[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool visited[16][16][16][16];
char _map[16][16];
int xBorder, yBorder;
class Marble{
public:
    int x, y;
    Marble(int _x, int _y) : x(_x), y(_y){}
    Marble() : x(0), y(0){}
    pair<Marble, bool> rolling(int dir){
        int dx = this->x, dy = this->y;
        bool temp_flag = false;
        while(true){
            if(_map[dy+_step[1][dir]][dx+_step[0][dir]] == '#') break;
            if(_map[dy+_step[1][dir]][dx+_step[0][dir]] == 'O') temp_flag = true;
            dx += _step[0][dir];
            dy += _step[1][dir];
        }
        return {Marble(dx, dy), temp_flag};
    }
    pair<Marble, bool> rolling(int dir, Marble &other){
        int dx = this->x, dy = this->y;
        bool temp_flag = false;
        while(true){
            if(_map[dy+_step[1][dir]][dx+_step[0][dir]] == '#' || (other.x == dx+_step[0][dir] && other.y == dy+_step[1][dir])) break;
            if(_map[dy+_step[1][dir]][dx+_step[0][dir]] == 'O') temp_flag = true;
            dx += _step[0][dir];
            dy += _step[1][dir];
        }
        return {Marble(dx, dy), temp_flag};
    }
};
void print(int redx, int redy, int bluex, int bluey){
    cout << "-------------------------------------------\n";
    for(int i = 0; i < yBorder; i++){
        for(int j = 0; j < xBorder; j++){
            if(i == redy && j == redx) cout << 'R';
            else if(i == bluey && j == bluex) cout << 'B';
            else cout << _map[i][j];
        }
        cout << '\n';
    }
}
int bfs(int red_x, int red_y, int blue_x, int blue_y){
    // 빨강, 파랑 순
    queue<tuple<Marble, Marble, int>> q;
    q.push({Marble(red_x, red_y), Marble(blue_x, blue_y), 0});
    visited[red_x][red_y][blue_x][blue_y] = true;
    while(!q.empty()){
        Marble  red_mb =    get<0>(q.front()), 
                blue_mb =   get<1>(q.front());
        int     cur_cnt =   get<2>(q.front());
        q.pop();
        // print(red_mb.x, red_mb.y, blue_mb.x, blue_mb.y);
        if(cur_cnt == 10) continue;
        for(int i = 0; i < 4; i++){             // 방향 결정
            Marble next_rmb, next_bmb;
            bool blue_dropped, red_dropped;
            pair<Marble, bool> temp;
            if(
                (i == 0 && red_mb.y == blue_mb.y && red_mb.x > blue_mb.x) ||
                (i == 1 && red_mb.x == blue_mb.x && red_mb.y > blue_mb.y) ||
                (i == 2 && red_mb.y == blue_mb.y && red_mb.x < blue_mb.x) ||
                (i == 3 && red_mb.x == blue_mb.x && red_mb.y < blue_mb.y)
            ){
                temp = red_mb.rolling(i);
                next_rmb = temp.first;
                red_dropped = temp.second;
                if(!red_dropped)temp = blue_mb.rolling(i, next_rmb);
                else temp = blue_mb.rolling(i);
                next_bmb = temp.first;
                blue_dropped = temp.second;
                if(red_dropped){
                    if(blue_dropped) continue;
                    else return cur_cnt+1;
                }
            }
            else if(
                (i == 0 && red_mb.y == blue_mb.y) ||
                (i == 1 && red_mb.x == blue_mb.x) ||
                (i == 2 && red_mb.y == blue_mb.y) ||
                (i == 3 && red_mb.x == blue_mb.x)
            ){
                temp = blue_mb.rolling(i);
                next_bmb = temp.first;
                blue_dropped = temp.second;
                if(blue_dropped) continue;
                temp = red_mb.rolling(i, next_bmb);
                next_rmb = temp.first;
                red_dropped = temp.second;
                if(red_dropped) return cur_cnt+1;
            }
            else{
                temp = red_mb.rolling(i);
                next_rmb = temp.first;
                red_dropped = temp.second;
                if(red_dropped) return cur_cnt+1;
                temp = blue_mb.rolling(i);
                next_bmb = temp.first;
                blue_dropped = temp.second;
                if(blue_dropped) continue;
            }
            if(!visited[next_rmb.x][next_rmb.y][next_bmb.x][next_bmb.y]){
                q.push({next_rmb, next_bmb, cur_cnt+1});
                visited[next_rmb.x][next_rmb.y][next_bmb.x][next_bmb.y] = true;
            }
        }
    }
    return -1;
}
void input(){
    cin >> yBorder >> xBorder;
    int red_x, red_y, blue_x, blue_y;
    for(int i = 0; i < yBorder; i++){
        for(int j = 0; j < xBorder; j++){
            char c; cin >> c;
            if(c == 'R'){red_x = j; red_y = i;_map[i][j]='.';}
            else if(c == 'B'){blue_x = j; blue_y = i;_map[i][j]='.';}
            else _map[i][j] = c;
        }
    }
    cout << bfs(red_x, red_y, blue_x, blue_y);
}
int main(){
    input();
}