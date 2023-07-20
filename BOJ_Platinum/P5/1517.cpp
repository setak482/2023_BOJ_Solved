#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> arr, sorted_arr;
ll ans;
void mergeSort(int L, int R){
    if(L >= R) return;
    int mid = (L+R)/2;
    ll cnt = 0;
    mergeSort(L, mid);
    mergeSort(mid+1, R);
    int i = L, j = mid+1;
    for(int k = L; k <= R; k++){
        if(j > R){sorted_arr[k] = arr[i++]; ans += cnt;}
        else if(i > mid){sorted_arr[k] = arr[j++]; cnt++;}
        else if(arr[i] <= arr[j]){sorted_arr[k] = arr[i++]; ans+=cnt;}
        else{sorted_arr[k] = arr[j++]; cnt++;}
    }
    for(i=L; i<=R; i++)arr[i] = sorted_arr[i];
}
int main(){
    int n; cin >> n;
    arr.resize(n);
    sorted_arr.resize(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
    }
    mergeSort(0, n-1);
    // for(auto& i : sorted_arr) cout << i << ' ';
    cout << ans;
}