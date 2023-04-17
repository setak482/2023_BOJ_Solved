#include <bits/stdc++.h>
using namespace std;
int main(){
    set<string> strset;
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        string str, cmd;
        cin >> str >> cmd;
        if(cmd=="enter"){
            strset.insert(str);
        }
        else{
            if(strset.count(str) == 1) strset.erase(str);
        }
    }
    for(auto i = strset.rbegin(); i != strset.rend(); i++){
        cout << *i << '\n';
    }
}