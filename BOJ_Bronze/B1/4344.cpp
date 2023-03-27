#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++){
        int cnt; cin >> cnt;
        vector<int> v(cnt); int sum; double avg;
        for(int i = 0; i < cnt; i++){
            int tmp; cin >> tmp;
            v[i] = tmp;
        }
        sum = accumulate(v.begin(), v.end(), 0);
        avg = sum / cnt;
        int ue = 0;
        for(int i = 0; i < cnt; i++){if(v[i] > avg) ue++;}
        double pride = (double)ue / (double)cnt * 100;
        printf("%.3f\%\n", pride);
    }
}