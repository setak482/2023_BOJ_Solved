#include <bits/stdc++.h>
#define _MAX 20200
using namespace std;
int visited[_MAX], num[_MAX], low[_MAX], vertex, edge, cnt;
set<int> graph[_MAX];
vector<vector<int>> scc;
stack<int> s;
int trans(int num, int mode){
    return (mode == 0) ? num + 10000 : num - 10000;
}
void dfs(int cur){
    visited[cur]++;
    num[cur] = ++cnt;
    low[cur] = cnt;
    s.push(cur);
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
        while(!s.empty()){
            int top = s.top(); s.pop();
            temp.push_back(top);
            visited[top] = 0;
            if(cur == top) break;
        }
        scc.push_back(temp);
    }
}
void input(){
    cin >> vertex >> edge;
    vertex *= 2;
    for(int i = 0; i < edge; i++){
        int a, b; cin >> a >> b;
        graph[trans(a*(-1), 0)].insert(trans(b, 0));
        graph[trans(b*(-1), 0)].insert(trans(a, 0));
    }
    for(int i = 1; i <= vertex/2; i++)
        if(!num[trans(i, 0)]) dfs(trans(i, 0));
    for(int i = -1; i >= vertex*(-1)/2; i--)
        if(!num[trans(i, 0)]) dfs(trans(i, 0));
}
void output(){
    for(auto& v : scc){
        int check[_MAX] = {0, };
        for(auto& i : v){
            int ori = trans(i, 1);
            if(check[trans(ori, 0)]){
                cout << 0;
                return;
            }
            check[trans(ori*(-1), 0)]++;
        }
    }
    cout << 1;
}
int main(){
    input();
    output();
}