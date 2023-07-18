#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        unordered_map<int, int> m;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            m[c] = 1;
        }
        int k; cin >> k;
        for(int i = 0; i < k; i++){
            int c; cin >> c;
            cout << (m[c]==1) ? 1 : 0;
            cout << '\n';
        }
    }
}