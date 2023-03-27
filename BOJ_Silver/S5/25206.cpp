#include <bits/stdc++.h>
using namespace std;
unordered_map<string, double> sc= {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0}
};
int main(){
    int cnt = 0; double sum = 0;
    for(int i = 0; i < 20; i++){
        string dump, cls; double num;
        cin >> dump >> num >> cls;
        if(cls[0] == 'P') continue;
        cnt += num;
        sum += sc[cls] * num;
    }
    printf("%.6f", sum / cnt);
}