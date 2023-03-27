#include <bits/stdc++.h>
using namespace std;
int main(){ 
    priority_queue<pair<int, pair<int, int>>> pq;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            int a; cin >> a;
            pq.push({a, {i, j}});
        }
    }
    printf("%d\n%d %d", pq.top().first, pq.top().second.first, pq.top().second.second);
}