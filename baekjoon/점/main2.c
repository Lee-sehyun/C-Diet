#include <stdio.h>

void check(int num1, int num2);

int n;

int main(void) {
    // 생각 코딩

    //입력
    int yorn[5][2];
    int a, b;
    int i;
    scanf("%d %d", &a, &b);
    for (i = 0 ; i < 5 ; i++){
        scanf("%d %d", &yorn[i][0], &yorn[i][1]);
    }

    //실행
    if (a < b){
        n = b-a;
    }
    else {
        n = a-b;
    }
    if (n == 0);
    else {
        while (1){
            if (n % 2 == 0){
                n /= 2;
            }
            else break;
        }
    }

    for (i = 0 ; i < 5 ; i++){
        if (n == 0){
            if (yorn[i][0] == yorn[i][1]){
                printf("Y\n");
            }
            else {
                printf("N\n");
            }
        }
        else if (a < b){
            check(yorn[i][0], yorn[i][1]);
        }
        else {
            check(yorn[i][1], yorn[i][0]);
        }
    }

    return 0;
}

void check(int num1, int num2){

    if (num1 >= num2){
        printf("N\n");
    }
    else if ((num2-num1)%n == 0){
        printf("Y\n");
    }
    else {
        printf("N\n");
    }

}