#include <bits/stdc++.h>
using namespace std;
map<string, string> m= {
    {"NLCS", "North London Collegiate School"},
    {"BHA", "Branksome Hall Asia"},
    {"KIS", "Korea International School"},
    {"SJA", "St. Johnsbury Academy"}
};
int main(){
    string str; cin >> str;
    cout << m[str];
}