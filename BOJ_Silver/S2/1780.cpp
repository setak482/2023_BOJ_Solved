#include <bits/stdc++.h>
using namespace std;
int ans[3];
int arr[3000][3000];
void sum(int _x1, int _y1, int _x2, int _y2){
    int this_n = arr[_y1][_x1];
    int dif = (_y2-_y1);
    if(dif == 1){
        ans[this_n+1]++;
        return;
    }
    bool is_equal = true;
    for(int i = _y1; i < _y2; i++){
        for(int j = _x1; j < _x2; j++){
            if(arr[i][j] != this_n){
                is_equal = false;
                break;
            }
        }
        if(is_equal == false) break;
    }
    int esum = 0;
    int div = dif/3;
    if(!is_equal){
        for(int i = _y1; i < _y2; i += div)
            for(int j = _x1; j < _x2; j += div)
                sum(j, i, j+div, i+div);
        return;
    }
    else{
        ans[this_n+1]++;
        return;
    }
}
int main(){
    int num; cin >> num;
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            cin >> arr[i][j];
    sum(0, 0, num, num);
    for(int i = 0; i < 3; i++) cout << ans[i] << '\n';
}