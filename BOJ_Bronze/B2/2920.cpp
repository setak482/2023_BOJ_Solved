#include <bits/stdc++.h>
using namespace std;
vector<int> ascending = {1, 2, 3, 4, 5, 6, 7, 8};
vector<int> descending = {8, 7, 6, 5, 4, 3, 2 ,1};
int main(){
    vector<int> in;
    for(int i = 0; i < 8; i++){
        int a; 
        cin >> a; 
        in.push_back(a);
    }
    if(in == ascending) cout << "ascending";
    else if (in == descending) cout << "descending";
    else cout << "mixed";
}