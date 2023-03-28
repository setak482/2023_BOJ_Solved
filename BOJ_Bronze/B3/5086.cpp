#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int a, b; cin >> a >> b;
        if(a == 0 && b == 0) exit(0);
        if(a % b == 0 || b % a == 0){
            if(a < b) cout << "factor\n";
            else cout << "multiple\n";
        }
        else cout << "neither\n";
    }
}