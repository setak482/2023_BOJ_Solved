#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int t, c; cin >> t >> c;
    for(int i = 1; i <= t; i++) v.push_back(i);
    for(int i = 0; i < c; i++){
        int s, m, e;
        vector<int> tmp = v;
        cin >> s >> e >> m;
        s--; m--; e--;  //0, 5, 3
        for(int j = m; j <= e; j++) tmp[s+(j-m)] = v[j];
        for(int j = s; j < m; j++) tmp[s+(e-m)+(j-s)+1] = v[j];
        for(int j = s; j <= e; j++) v[j] = tmp[j];
    }
    for(auto &i : v) cout << i << ' ';
}