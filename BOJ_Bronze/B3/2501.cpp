#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) if(n % i == 0) v.push_back(i);
    if(v.empty() || v.size() < k) cout << 0;
    else cout << v[k-1];
}