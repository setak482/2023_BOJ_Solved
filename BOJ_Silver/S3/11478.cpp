#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<string> strset;
    string str; cin >> str;
    for(int i = 1; i <= str.length(); i++){
        for(int j = 0; j <= str.length()-i; j++){
            string sstr = str.substr(j, i);
            if(!strset.count(sstr)){
                strset.insert(sstr);
            }
        }
    }
    cout << strset.size();
}