#include <bits/stdc++.h>
#define ll unsigned long long
#define pow(i) i*i
using namespace std;
int main(){
    ll a; cin >> a;
    ll b = a;
    for(ll i = 2; pow(i)<=a; i++){
        if(a%i==0) b=b/i*(i-1);
        while(a%i==0) a = a/i;
    }
    if(a==1) cout << b;
    else cout << b/a*(a-1);
}