#include <bits/stdc++.h>
#define _MAX 50001
using namespace std;
int parent[_MAX], depth[_MAX];
vector<int> graph[_MAX];
queue<pair<int, int>> solve_q;
int LCA(int u, int v){
    while(u != 0 && v != 0){
        if(depth[u] < depth[v])
            v = parent[v];
        else if(depth[u] > depth[v])
            u = parent[u];
        else{
            if(u==v) return u;
            v = parent[v];
            u = parent[u];
        }
    }
    return -1;
}
void input(){
    int edge; cin >> edge;
    for(int i = 0; i < edge-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        solve_q.push({a, b});
    }
}
void make_info(){
    depth[1] = 1;
    bool visited[_MAX] = {0, };
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : graph[cur]){
            if(visited[i]) continue;
            depth[i] = depth[cur]+1;
            parent[i] = cur;
            visited[i] = true;
            q.push(i);
        }
    }
}
void solve(){
    while(!solve_q.empty()){
        int u = solve_q.front().first, v = solve_q.front().second; solve_q.pop();
        cout << LCA(u, v) << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    make_info();
    solve();
}