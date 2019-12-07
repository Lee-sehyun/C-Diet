#include <stdio.h>

int main(void){
    // 생각코딩

    int K, a = 0;
    int D = 1, min = 0;

    // 입력
    scanf("%d", &K);

    // 실행
    while(K != 0){
        if (K > 1 && K%2 == 1){
            K /= 2;
            D *= 2;
            a = 1;
            min++;
            break;
        }
        else {
            K /= 2;
            D *= 2;
        }
    }

    while (K != 0){
        K /= 2;
        D *= 2;
        min++;
    }

    if (a == 0){
        D /= 2;
    }

    printf("%d %d", D, min);



    return 0;
}