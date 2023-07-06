#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b; cin >> n >> a >> b;
    if((n <= b && a < b) || n > b) cout << "Bus";
    else if(n <= b && a > b) cout << "Subway";
    else cout << "Anything";
}