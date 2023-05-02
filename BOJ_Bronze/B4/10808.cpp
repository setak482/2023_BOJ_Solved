#include <bits/stdc++.h>
using namespace std;
int alp[26];
int main(){
    string str;
    getline(cin, str);
    for(char& c : str) alp[c-'a']++;
    for(int i = 0; i < 26; i++) cout << alp[i] << ' ';
}