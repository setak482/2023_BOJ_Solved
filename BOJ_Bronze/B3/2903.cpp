#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt, j;
    cin >> cnt;
    j = 2;
    for(; cnt != 0; cnt--) j += (j-1);
    cout << j*j;
}