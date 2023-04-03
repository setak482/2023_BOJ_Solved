#include <bits/stdc++.h>
using namespace std;
char num_to_alph(int n){
    return 65 + (n-10);
}
int main(){
    int num, pow; cin >> num >> pow;
    vector<int> v;
    while(num != 0){
        v.push_back(num % pow);
        num /= pow;
    }
    for(auto i = v.end()-1; i >= v.begin(); i--){
        if(*i < 10) cout << *i;
        else cout << num_to_alph(*i);
    }
}   