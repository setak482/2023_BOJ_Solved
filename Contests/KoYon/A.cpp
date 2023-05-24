#include <bits/stdc++.h>
using namespace std;
string KOREA = "KOREA", YONSEI = "YONSEI";
int Knum, Ynum;
int main(){
    string str; cin >> str;
    int ans = 0;
    for(auto& c : str){
        if(Knum == 5){ans = 1; break;}
        else if(Ynum == 6){ans = 2; break;}
        if(c == KOREA[Knum]) Knum++;
        if(c == YONSEI[Ynum]) Ynum++;
    }
    if(ans == 1) cout << KOREA;
    else if(ans == 2) cout << YONSEI;
}