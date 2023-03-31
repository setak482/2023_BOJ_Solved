#include <iostream>
using namespace std;
int main(){
    int a; cin >> a;
    long long cnt = 0;
    for(int i = 1; i < a; i++){
        for(int j = i + 1; j <= a; j++){
            cnt++;
        }
    }
    cout << cnt << '\n' << 2; 
}