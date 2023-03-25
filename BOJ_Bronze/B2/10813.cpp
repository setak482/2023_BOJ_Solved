#include <bits/stdc++.h>
using namespace std;
int sum[101];
int main(){
    int basket, cnt;
    cin >> basket >> cnt;  
    for(int i = 1; i <= basket; i++) sum[i] = i;
    for(int i = 0; i < cnt; i++){
        int a, b, temp;
        cin >> a >> b;
        temp = sum[a];
        sum[a] = sum[b];
        sum[b] = temp;
    }
    for(int i = 1; i <= basket; i++){
        cout << sum[i] << " ";
    }
}