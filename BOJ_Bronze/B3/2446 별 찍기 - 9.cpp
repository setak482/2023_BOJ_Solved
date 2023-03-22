#include <bits/stdc++.h>
using namespace std;
int main(){
    int c; cin >> c;
    if(c == 1){
        printf("*");
        return 0;
    }
    int b = 2*c-1;
    for(int i = 0; i < b; i += 2){
        for(int j = 0; j < i/2; j++){
            printf(" ");
        }
        for(int j = 0; j < b-i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = b-3; i > 0; i -= 2){
        for(int j = 0; j < i/2; j++){
            printf(" ");
        }
        for(int j = 0; j < b-i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 0; i < b; i++){
        printf("*");
    }
}