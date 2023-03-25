#include <bits/stdc++.h>
using namespace std;
int sum[101];
int main(){
    int basket, cnt;
    cin >> basket >> cnt;
    for(int i = 0; i < cnt; i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = a; j <= b; j++) sum[j] = c;
    }
    for(int i = 1; i <= basket; i++){
        cout << sum[i] << " ";
    }
}