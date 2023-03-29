#include <bits/stdc++.h>
using namespace std;
int main(){
    int v[3] = {0, 0, 0};
    for(int i = 0; i < 3; i++) cin >> v[i];
    sort(v, v+3);
    while(true){
        if(v[0] + v[1] > v[2]) break;
        v[2]--;
    }
    cout << accumulate(v, v+3, 0);
}