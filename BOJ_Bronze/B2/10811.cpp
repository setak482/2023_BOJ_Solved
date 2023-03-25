#include <bits/stdc++.h>
using namespace std;
vector<int> sum(100);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int basket, cnt;
    cin >> basket >> cnt;  
    for(int i = 1; i <= basket; i++) sum[i] = i;
    for(int i = 0; i < cnt; i++){
        int a, b;
        cin >> a >> b;
        if(a != b) reverse(sum.begin()+a, sum.begin()+b+1);
    }
    for(int i = 1; i <= basket; i++) cout << sum[i] << " ";
}