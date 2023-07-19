#include <bits/stdc++.h>
#define um unordered_map
using namespace std;
um<char, int> rometoi = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
int strtoi(string rome){
    int temp = 0;
    for(int i = 0; i < rome.size(); i++){
        if(rometoi[rome[i-1]] < rometoi[rome[i]])
            temp -= rometoi[rome[i-1]]*2;
        temp += rometoi[rome[i]];
    }
    return temp;
}
string itostr(int num){
    string str = "";
    while(num){
        if(num >= 1000){num -= 1000; str += "M";}
        else if(num >= 900){num -= 900; str += "CM";}
        else if(num >= 500){num -= 500; str += "D";}
        else if(num >= 400){num -= 400; str += "CD";}
        else if(num >= 100){num -= 100; str += "C";}
        else if(num >= 90){num -= 90; str += "XC";}
        else if(num >= 50){num -= 50; str += "L";}
        else if(num >= 40){num -= 40; str += "XL";}
        else if(num >= 10){num -= 10; str += "X";}
        else if(num >= 9){num -= 9; str += "IX";}
        else if(num >= 5){num -= 5; str += "V";}
        else if(num >= 4){num -= 4; str += "IV";}
        else{num--; str += "I";}
    }
    return str;
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int temp = strtoi(str1) + strtoi(str2);
    cout << temp << '\n' << itostr(temp);
}