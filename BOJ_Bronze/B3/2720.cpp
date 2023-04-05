#include <bits/stdc++.h>
using namespace std;
int coin[4] = {25, 10, 5, 1};
int main(){
    int d, e = 0; cin >> d;
    for(int i = 0; i < d; i++){
        int a; cin >> a;
        for(int j = 0; j < 4; j++){
            cout << a / coin[j] << ' ';
            a %= coin[j];
        }
        cout << '\n';
    }
}