#include <bits/stdc++.h>
#define CUT 0.15
using namespace std;
int main(){
    vector<int> arr;
    int n; cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int cut_index = round(n*CUT);
    double sum = 0;
    for(int i = cut_index; i < arr.size()-cut_index; i++)
        sum += arr[i];
    cout << round(sum/(arr.size()-(cut_index*2)));
}