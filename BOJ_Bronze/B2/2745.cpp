#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull alph_to_num(char c) { return c - 'A' + 10; }
int main() {
    string str; int a; ull sum = 0;
    cin >> str >> a;
    for (int i = str.length() - 1; i >= 0; i--) {
        ull pow = 1;
        for (int j = 0; j < (str.length() - i-1); j++) pow *= a;
        if (isdigit(str[i])) {
            int temp = str[i] - '0';
            sum += temp * pow;
        }
        else {
            int temp = alph_to_num(str[i]);
            sum += temp * pow;
        }
    }
    cout << sum;
}