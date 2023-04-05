#include <bits/stdc++.h>
using namespace std;
int dp[15][15];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 14; i++)
        dp[0][i] = i;
    for(int i = 1; i <= 14; i++){
        dp[i][1] = 1;
        for(int j = 2; j <= 14; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int k, n; cin >> k >> n;
        cout << dp[k][n] << '\n';
    }
}