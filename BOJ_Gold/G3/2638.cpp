#include <bits/stdc++.h>
using namespace std;
struct NODE { int x, y; };
int xMax, yMax, _map[101][101], _step[2][4] = { {1, 0, -1, 0}, {0, -1, 0, 1} },
cheese_cnt, melt[101][101];
void bfs() {
    bool visited[101][101] = { false, };
    memset(melt, 0, sizeof(melt));
    queue<NODE> q;
    q.push({ 0,0 });
    visited[0][0] = true;
    while (!q.empty()) {
        int cx = q.front().x, cy = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = cx + _step[0][i], dy = cy + _step[1][i];
            if (!_map[dy][dx]) {
                if (dx >= 0 && dy >= 0 && dx < xMax && dy < yMax && !visited[dy][dx]) {
                    q.push({ dx,dy });
                    visited[dy][dx] = true;
                }
            }
            else {
                melt[dy][dx]++;
            }
        }
    }
}
void input() {
    cin >> yMax >> xMax;
    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) cheese_cnt++;
            _map[i][j] = tmp;
        }
    }
    // cout << '\n';
}
void solution() {
    int cnt = 0;
    while (true) {
        cnt++;
        bfs();

        // for (int i = 0; i < yMax; i++) {
        //     for (int j = 0; j < xMax; j++) {
        //         cout << melt[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        for (int i = 0; i < yMax; i++) {
            for (int j = 0; j < xMax; j++) {
                if (melt[i][j] >= 2) {
                    _map[i][j] = 0;
                    cheese_cnt--;
                }
            }
        }
        if (cheese_cnt == 0) break;
    }
    cout << cnt;
}
int main() {
    input();
    solution();
}