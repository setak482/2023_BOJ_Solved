#include <bits/stdc++.h>
using namespace std;
int main(){
    int num = 1, cnt, a, b;
    bool flag = false;
    cin >> cnt;
    while(true){
        for(int i = 1; i <= num; i++){
            a = i, b = (num-i)+1;
            if(--cnt == 0) {
                flag = true;
                break;
            }
        }
        if(flag) break;
        num++;
    }
    if(num % 2 == 0) printf("%d/%d", a, b);
    else printf("%d/%d", b, a);
}