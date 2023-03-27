#include <bits/stdc++.h>
using namespace std; 
bool check[101][101];
int main(){
    int ans = 0;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int x, y; cin >> x >> y;
        for(int j = y; j < y+10; j++){
            for(int k = x; k < x+10; k++){
                if(!check[j][k]){
                    ans++;
                    check[j][k] = true;
                }
            }
        }
    }
    cout << ans;
}