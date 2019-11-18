#include <stdio.h>
#include <stdlib.h>

struct N_A {
    int T;
    char Z[1];
};

int main(void){
    // 생각 코딩
    // 일단 배열로 저장해서 질문지를 만든다.
    // 하다가 210초가 넘어가면 그 사람에서 아웃!
    // 반복문을 빠져나온다.

    struct N_A *N_A[100];

    // 사람 (8명)
    int K;
    int N; // 질문의 갯수
    int i;

    //입력
    scanf("%d", &K);
    scanf("%d", &N);
    for(i = 0 ; i < N ; i++){
        N_A[i] = malloc(sizeof(struct N_A));
        scanf("%d %s", &N_A[i]->T, N_A[i]->Z);
    }

    int sum = 0;

    for (i = 0 ; i < N ; i++){
        sum += N_A[i]->T;
        if (sum > 210){
            break;
        }
        else if (*N_A[i]->Z == 'T'){
            if (K == 8){
                K = 1;
            }
            else {
                K++;
            }
        }
    }

    printf("%d", K);






    return 0;
}