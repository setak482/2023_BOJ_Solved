#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        sum += a;
        pq.push(a);
    }
    int i = 2;
    while(i--) pq.pop();
    cout << int(sum/5) << '\n' << pq.top();
}