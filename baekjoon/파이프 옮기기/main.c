#include <stdio.h>

int space[18][18];

void width(int i, int j);
void height(int i, int j);
void diagonal (int i, int j);

int N;
int count = 0;

int main(void) {
    // 생각 코딩
    // 깊이 우선 탐색으로 하자.....
    // 가로, 세로, 대각선일 떄 각각의 방법을 정의해주고, 갯수를 세준다.
    // 그 전거를 저장할 것 과 새로운걸 저장할 곳이 필요할 것 같구만....

    //입력
    scanf("%d", &N);
    for (int i = 0 ; i < 18 ; i++){
        for (int j = 0 ; j < 18 ; j++){
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                scanf("%d", &space[i][j]);
            }
            else {
                space[i][j] = -1;
            }
        }
    }


    width(1, 2);

    printf("%d", count);


    
    return 0;
}

void width(int i, int j) {

    if (space[i][j] == 0){

        if (i == N && j == N) {
            count++;
            return;
        }

        width(i, j+1);

        diagonal(i+1, j+1);
    }

}

void height(int i, int j){

    if (space[i][j] == 0){

        if (i == N && j == N) {
            count++;
            return;
        }

        height(i+1, j);

        diagonal(i+1, j+1);
    }

}

void diagonal (int i, int j){

    if (space[i][j] == 0 && space[i-1][j] == 0 && space[i][j-1] == 0){

        if (i == N && j == N) {
            count++;
            return;
        }

        width(i, j+1);

        height(i+1, j);

        diagonal(i+1, j+1);
    }

}