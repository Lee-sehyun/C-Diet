#include <stdio.h>
#include <math.h>

int main(void){
    // 생각코딩
    // 자 빨간 타일이 있고 갈색타일이 있어

    int R, B;
    int L, W;

    // 입력
    scanf("%d %d", &R, &B);

    // 실행
    L = ((2+R/2)+sqrt((2+R/2.0)*(2+R/2.0)-4*(B+R)))/2;
    W = ((2+R/2)-sqrt((2+R/2.0)*(2+R/2.0)-4*(B+R)))/2;

    printf("%d %d", L, W);



    return 0;
}