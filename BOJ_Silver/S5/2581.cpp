#include <bits/stdc++.h>
using namespace std;
bool prime[10001];
void era(){
    memset(prime, true, sizeof(prime));
    for(int i = 2; i <= 100; i++){
        if(!prime[i]) continue;
        for(int j = i*i; j <= 10000; j += i)
            prime[j] = false;
    }
    prime[1] = false;
}
int main(){
    era();
    int a, b, c = 0, sum = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(prime[i]){
            if(c == 0) c = i;
            sum += i;
        }
    }
    if(c == 0) cout << -1;
    else printf("%d\n%d",sum,c);
}