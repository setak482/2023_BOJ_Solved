#include <bits/stdc++.h>
using namespace std;
vector<int> arr, tree;
int _min(int x, int y){
    if(x == -1) return y;
    if(y == -1) return x;
    if(arr[x] == arr[y]) return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
}
int init(int node, int begin, int end){
    if(begin == end) return tree[node] = begin;
    return tree[node] = _min(
        init(node*2, begin, (begin+end)/2),
        init(node*2+1, (begin+end)/2+1, end)
    );
}
int update(int node, int begin, int end, int idx){
    if(idx < begin || end < idx || begin == end) return tree[node];
    return tree[node] = _min(
        update(node*2, begin, (begin+end)/2, idx),
        update(node*2+1, (begin+end)/2+1, end, idx)
    );
}
int _find(int node, int begin, int end, int L, int R){
    if(begin > R || end < L) return -1;
    if(L <= begin && end <= R) return tree[node];
    return _min(
        _find(node*2, begin, (begin+end)/2, L, R),
        _find(node*2+1, (begin+end)/2+1, end, L, R)
    );
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; 
    arr.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    tree.resize((1 << int(ceil(log2(n)))+1)+1);
    init(1, 1, n);

    int m; cin >> m;
    while(m--){
        int cmd, p, q; cin >> cmd;
        if(cmd == 1){
            cin >> p >> q;
            arr[p] = q;
            update(1, 1, n, p);
        }
        else{
            cin >> p >> q;
            cout << _find(1, 1, n, p, q) << '\n';
        }
    }
}