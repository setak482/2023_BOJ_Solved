#include <bits/stdc++.h>
#define ITEM_MAX 64
using namespace std;
int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    int entire; cin >> entire;
    int space = entire/ITEM_MAX + (entire % ITEM_MAX != 0);
    printf("현재 이 아이템이 차지하고 있는 공간은 %d칸입니다.\n",space);
    int comp = (entire / 9) / ITEM_MAX + ((entire / 9) % ITEM_MAX != 0) + (entire % 9 != 0);
    if(entire < 9){
        printf("현재 이 아이템을 압축하기에는 양이 부족합니다.");
    }
    else if(space-comp > 0){
        printf("압축할 시 총 %d칸이 되며 %d칸을 절약할 수 있습니다.",comp, abs(space-comp));
    }
    else if(space-comp == 0){
        printf("압축할 시의 칸 수가 현재 칸 수와 똑같습니다.");
    }
    else{
        printf("압축할 시 총 %d칸이 되며 %d칸을 낭비합니다",comp, abs(space-comp));
    }
}