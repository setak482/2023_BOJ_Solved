#include <bits/stdc++.h>
using namespace std;
int visited[10001], num[10001], low[10001], vertex, edge, cnt;
vector<int> graph[10001];
vector<vector<int>> scc;
stack<int> stk;
void dfs(int cur){
    visited[cur] = 1;
    num[cur] = ++cnt;
    low[cur] = cnt;
    stk.push(cur);
    for(auto& i : graph[cur]){
        if(!num[i]){
            dfs(i);
            low[cur] = min(low[cur], low[i]);
        }
        else if(visited[i])
            low[cur] = min(low[cur], num[i]);
    }
    if(low[cur] == num[cur]){
        vector<int> temp;
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            temp.push_back(top);
            visited[top] = 0;
            if(cur == top) break;
        }
        sort(temp.begin(), temp.end());
        scc.push_back(temp);
    }
}
int main(){
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1; i <= vertex; i++){
        if(!num[i]) dfs(i);
    }
    sort(scc.begin(), scc.end());
    cout << scc.size() << '\n';
    for(auto& v : scc){
        for(auto& i : v) cout << i << ' ';
        cout << -1 << '\n';
    }
}