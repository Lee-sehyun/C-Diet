#include <stdio.h>

int main(void) {
    // 생각 코딩
    // 올라가고 V랑 계산하고 내려가고 이거 반복하면 될 듯
    // 헐 시간 초과라니...

    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);
    int day;

    day = (V-A)/(A-B);
    if ((V-A)%(A-B) != 0){
        day++;
    }
    day++;


    printf("%d", day);


    return 0;
}

