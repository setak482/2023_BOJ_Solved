#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt;
    long long num = 0, i = 665;
    cin >> cnt;
    while(cnt){
        i++;
        string str = to_string(i);
        int temp=0;
        for(auto j = 0; j < str.length()-2; j++){
            if(str.substr(j, 3)=="666")
                temp++;
        }
        if(temp >= 1){
            num = i;
            cnt--;
        }
    }
    cout << num;
}   