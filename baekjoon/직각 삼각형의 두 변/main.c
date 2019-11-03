#include <stdio.h>
#include<math.h>

double Find_ab(double num1, double num2);
double Find_c(double num1, double num2);

int main(void) {
    // 생각 코딩
    // 직각삼각형이 될 수 있는 조건이 있었는데...
    // 그걸 이용해보자

    //입력
    int i = 1;
    double a, b, c;
    while(1){
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        printf("Triangle #%d\n", i);
        if (a == -1){
            a = Find_ab(b, c);
            if (a == -1) {
                printf("Impossible.\n");
            }
            else {
                printf("a = %.3lf\n", a);
            }
        }
        else if (b == -1){
            b = Find_ab(a, c);
            if (b == -1) {
                printf("Impossible.\n");
            }
            else {
                printf("b = %.3lf\n", b);
            }
        }
        else if (c == -1){
            c = Find_c(a, b);
            printf("c = %.3lf\n", c);
        }
        i++;
        printf("\n");
    }
    
    return 0;
}

double Find_ab(double num1, double num2){
    double k;

    k = sqrt((num2*num2) - (num1*num1));
    if (k > 0) {
        return k;
    }
    else {
        return -1;
    }
}

double Find_c(double num1, double num2){
    double k;

    k = sqrt((num2*num2) + (num1*num1));
    return k;
}