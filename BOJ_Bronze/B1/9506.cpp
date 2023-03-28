#include <bits/stdc++.h>
using namespace std;
int main(){
    while(true){
        int a, sum = 0; cin >> a;
        vector<int> v;
        if(a == -1) return 0;
        for(int i = 1; i < a; i++){
            if(a % i == 0){
                v.push_back(i);
                sum += i;
            }
        }
        if(a == sum){
            cout << a << " = ";
            for(int i = 0; i < v.size(); i++){
                if(i != v.size()-1)
                    printf("%d + ", v[i]);
                else cout << v[i];
            }
        }
        else
            printf("%d is NOT perfect.", a);
        cout << '\n';
    }
}