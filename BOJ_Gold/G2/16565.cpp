#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
int dp[53][53];
int comb(int n, int r){
    if(n == r || r == 0) return 1;
    if(dp[n][r] != 0) return dp[n][r];
    return dp[n][r] = (comb(n-1, r-1) + comb(n-1, r)) % MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, sum = 0; cin >> n;
    for(int i = 4; i <= n; i += 4){
        int sign = ((i/4)%2==0) ? -1 : 1;
        sum += sign * (comb(13, i/4) * comb(52-i, n-i));
        sum %= MOD;
    }
    if(sum < 0) sum += MOD;
    cout << sum;
}