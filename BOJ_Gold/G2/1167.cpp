#include <bits/stdc++.h>
using namespace std;
struct Info{int dest, weight;};
vector<Info> graph[100001];
int ans, maxdest;
void input(){
    int vertex; cin >> vertex;
    for(int i = 0; i < vertex; i++){
        int n; cin >> n;
        while(true){
            int dest, weight;
            cin >> dest;
            if(dest == -1) break;
            cin >> weight;
            graph[n].push_back({dest, weight});
        }
    }
}
int visited[100001];
void dfs(int node, int weight){
    visited[node]++;
    if(ans < weight){
        ans = weight;
        maxdest = node;
    }
    for(auto& i : graph[node]){
        if(visited[i.dest]) continue;
        dfs(i.dest, weight + i.weight);
    }
}
void solve(){
    dfs(1, 0);
    ans = 0;
    memset(visited, 0, sizeof(visited));
    dfs(maxdest, 0);
}
void output(){
    cout << ans;
}
int main(){
    input();
    solve();
    output();
}