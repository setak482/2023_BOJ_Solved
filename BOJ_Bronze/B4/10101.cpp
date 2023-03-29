#include <bits/stdc++.h>
using namespace std;
set<int> check;
int main(){
    string ans; int sum = 0;
    for(int i = 0; i < 3; i++){
        int a; cin >> a;
        if(check.count(a) == 0)
            check.insert(a);
        sum += a;
    }
    if(sum != 180) cout << "Error";
    else if(check.size() == 1) cout << "Equilateral";
    else if(check.size() == 2) cout << "Isosceles";
    else cout << "Scalene";
}