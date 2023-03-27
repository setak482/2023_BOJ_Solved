#include <bits/stdc++.h>
using namespace std;
int alph[26];
int main(){
    int tc, ans = 0; cin >> tc;
    for(int t = 0; t < tc; t++){
        memset(alph, 0, sizeof(alph));
        string str; cin >> str;
        for(int i = 0; i < str.length(); i++){
            if(i == 0){
                alph[str[i]-'a']++;
            }
            else{
                if(str[i-1] != str[i]) alph[str[i]-'a']++;
            }
        }
        bool grp = true;
        for(int i = 0; i < 26; i++){
            if(alph[i] > 1){
                grp = false;
                break;
            }
        }
        if(grp) ans++;
    }
    cout << ans;
}