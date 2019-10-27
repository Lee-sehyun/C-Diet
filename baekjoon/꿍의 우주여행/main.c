#include <stdio.h>

int main(void) {
    // 생각 코딩
    // 1. 속도 * 연료 / 연료 소비량(단 연료와 연료 소비량은 float형으로)
    // 2. 이것이 목적지의 거리를 넘으면 count++을 해주면 되겠다.
    // 3. 출력

    int T;
    scanf("%d", &T);
    int t;
    int count[50] = {0};
    for (t = 0 ; t < T ; t++) {
        int N, n;
        int D;
        int v;
        float f;
        float c;

        scanf("%d %d", &N, &D);
        for (n = 0 ; n < N ; n++) {
            scanf("%d %f %f", &v, &f, &c);
            if (v*f/c >= D) count[t]++;
        }
    }

    for (t = 0 ; t < T ; t++){
      printf("%d\n", count[t]);
    }


    return 0;
}

