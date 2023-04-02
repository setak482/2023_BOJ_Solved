#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> res = {
    {"Es", 21},
    {"Stair", 17}
} ;
int main(){
    int ans = 0;
    for(int i = 0; i < 4; i++){
        string str; int in;
        cin >> str >> in;
        ans += res[str] * in;
    }
    cout << ans;
}