#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    tc = tc*2 - 1;
    if(tc == 1){
        cout << '*';
        exit(0);
    }
    for(int i = 1; i <= tc; i += 2){
        for(int j = 0; j < (tc-i)/2; j++){
            cout << ' ';
        }
        for(int j = 0; j < i; j++){
            cout << '*';
        }
        cout << '\n';
    }
    for(int i = tc-2; i >= 1; i -= 2){
        for(int j = 0; j < (tc-i)/2; j++){
            cout << ' ';
        }
        for(int j = 0; j < i; j++){
            cout << '*';
        }
        if(i != 1) cout << '\n';
    }
}