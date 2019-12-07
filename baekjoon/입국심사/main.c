#include <stdio.h>
#include <stdlib.h>

int main(void){
    // 생각 코딩
    // 배열을 만들어보자!


    // 입력
    long long N, M;
    long long *T;
    long long max = 1000000000000000000;
    long long min;
    long long mid;
    long long sum;
    long long i;
    scanf("%lld %lld", &N, &M);

    T = (long long*)malloc(sizeof(long long)*N);
    for (i = 0 ; i < N ; i++){
        scanf("%lld", &T[i]);
    }
    
    // 실행
    while(min < max){
        sum = 0;
        mid = (max + min)/2;
        for (i = 0 ; i < N ; i++){
            sum += mid / T[i];
            if(sum >= M){
                max = mid;
                break;
            }
        }
        if(sum < M) {
            min = mid+1;
        }
    }
    printf("%lld", max);





    return 0;
}