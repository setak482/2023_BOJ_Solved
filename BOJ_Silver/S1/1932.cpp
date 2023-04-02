#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
int dp[501][501];
int main(){
    int cnt; cin >> cnt;
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 2; i <= cnt; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j]+arr[i][j], dp[i-1][j-1]+arr[i][j]);
    int m = -1;
    for(int i = 1; i <= cnt; i++)
        if(dp[cnt][i] > m) m = dp[cnt][i];
    cout << m;
}