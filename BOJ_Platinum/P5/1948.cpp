#include <bits/stdc++.h>
#define pii pair<int, int>
#define _MAX 10001
using namespace std;
struct Info{int t, w;};
int init, goal, vertex, edge, indegree[_MAX], _time[_MAX];
vector<Info> graph[_MAX];
vector<int> backward[_MAX];
void topology_sort(){
    queue<int> q;
    q.push(init);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto &next : graph[cur]){
            int next_v = next.t;
            if(_time[next_v] < _time[cur] + next.w){
                _time[next_v] = _time[cur] + next.w;
                backward[next_v].clear();
                backward[next_v].push_back(cur);
            }
            else if(_time[next_v] == _time[cur] + next.w)
                backward[next_v].push_back(cur);
            if(!--indegree[next_v]) q.push(next_v);
        }
    }
}
int bfs(){
    int cnt = 0;
    bool visited[_MAX] = {false, };
    queue<int> q;
    q.push(goal);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& v : backward[cur]){
            cnt++;
            if(visited[v]) continue;
            q.push({v});
            visited[v] = true;
        }
    }
    return cnt;
}
void input(){
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        indegree[b]++;
    }
    cin >> init >> goal;
}
void answer(){
    cout << _time[goal] << '\n' << bfs();
    // cout << '\n';
    // for(auto& p : memo[{goal, _time[goal]}]) printf("{%d, %d} ",p.first, p.second);
}
int main(){
    input();
    topology_sort();
    answer();
}