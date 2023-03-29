#include <bits/stdc++.h>
using namespace std;
int xmax = -10001, ymax = -10001,
    xmin = 10001, ymin = 10001;
void xcpr(int n){if(xmin > n) xmin = n; if(xmax < n) xmax = n;}
void ycpr(int n){if(ymin > n) ymin = n; if(ymax < n) ymax = n;}
int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int x, y; cin >> x >> y;
        xcpr(x); ycpr(y);
    }
    if(t == 1) cout << 0;
    else cout << (xmax-xmin)*(ymax-ymin);
}