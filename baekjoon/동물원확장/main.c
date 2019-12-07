#include <stdio.h>
#include <stdlib.h>

int main(void){
    // 생각 코딩
    // 배열을 만들어보자
    // 시간을 2개로 나눠서 앞부분에서의 코코넛 갯수와 뒷부분에서의 코코넛 갯수가 같으면
    // 그 시간을 바뀌는 시간이라고 해도 좋을 것이다.


    // 입력
    long long T;
    int N;
    int M;
    long long *A, *B, *C, *D;
    int i, j;
    scanf("%lld", &T);
    scanf("%d", &N);
    A = (long long *)malloc(sizeof(long long)*(N+1));
    B = (long long *)malloc(sizeof(long long)*(N+1));
    for (i = 1 ; i < N+1 ; i++){
        scanf("%lld %lld", &A[i], &B[i]);
    }
    scanf("%d", &M);
    C = (long long *)malloc(sizeof(long long)*(M+1));
    D = (long long *)malloc(sizeof(long long)*(M+1));
    for (i = 1 ; i < M+1 ; i++){
        scanf("%lld %lld", &C[i], &D[i]);
    }
    
    
    // 실행
    long long max, min, mid, sum_A, sum_C, sum_AA, sum_CC;
    max = T;
    min = 0;
    while(1){
        sum_A = 0;
        sum_C = 0;
        sum_AA = 0;
        sum_CC = 0;
        mid = (max+min) / 2;
        for (i = 1 ; i < N+1 ; i++){
            sum_A += ((mid-A[i]) / B[i])+1;
            if(sum_AA < ((max-A[i]) / B[i])*B[i]+A[i]){
                sum_AA = ((max-A[i]) / B[i])*B[i]+A[i];
            }
            a += ((max-A[i]) / B[i])+1;
        }
        for (i = 1 ; i < M+1 ; i++){
            sum_C += (((T-mid)-C[i]) / D[i])+1;
            if(sum_CC < (((T-max)-C[i]) / D[i])*D[i]+C[i]){
                sum_CC = (((T-max)-C[i]) / D[i])*D[i]+C[i];
            }
            c += (((T-mid)-C[i]) / D[i])+1;
        }
        if (sum_A >= sum_C){
            max = mid;
        }
        else {
            min = mid+1;
        }
        if(min >= max){
            sum_A = 0;
            sum_C = 0;
            for (i = 1 ; i < N+1 ; i++){
                sum_A += ((max-A[i]) / B[i])+1;
                if(sum_AA < ((max-A[i]) / B[i])*B[i]+A[i]){
                    sum_AA = ((max-A[i]) / B[i])*B[i]+A[i];
                }
            }
            for (i = 1 ; i < M+1 ; i++){
                sum_C += (((T-max)-C[i]) / D[i])+1;
                if(sum_CC < (((T-max)-C[i]) / D[i])*D[i]+C[i]){
                    sum_CC = (((T-max)-C[i]) / D[i])*D[i]+C[i];
                }
            }
            if (sum_AA+sum_CC != T){
                max -= T-(sum_AA+sum_CC);
            }
            if(sum_A > sum_C){
                // 뭐해야하지....
                
            }
            break;
        }
    }
    printf("%lld", max);


    return 0;
}