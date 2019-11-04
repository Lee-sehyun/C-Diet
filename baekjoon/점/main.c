#include <stdio.h>

int array[100000][2];
int final = 1;
bool visit1[100000]; // 룰1 방문
bool visit2[100000]; // 룰2 방문
int yorn[5][3];
int i = 0;

void rule1 (void);
void rule2 (void);
void rule3 (void);

int main(void) {
    // 생각 코딩
    // 배열을 크게 설정을 했고, 2차원 배열을 이용해서
    // 규칙 1, 2, 3은 함수로 만들어주고
    // 3개 전부가 더이상 무언가를 추가 할 수 없을 때까지 한다. 
    // 새롭게 추가하면 그것이 가능한지 판별하는 좌표인지 확인한다.
    // 무한 반복문을 사용해보자.

    //입력
    scanf("%d %d", &array[0][0], &array[0][1]);
    for (int j = 0 ; j < 5 ; j++){
        scanf("%d %d ", &yorn[j][0], &yorn[j][1]);
    }

    //실행
    int k = 0
    while(1){
        rule1();
        rule2();
        rule3();
        if (i == 0) break;
        i = 0;
    }

    for (int j = 0 ; j < 5 ; j++){
        if (yorn[j][2] == 1) printf("Y\n");
        else printf("N\n");
    }

    
    
    return 0;
}

void rule1 (void){
    int a, b;
    
    for (int j = 0 ; j < final ; j++){
        if (visit1[j] == false){
            visit1[j] = true;
            a = array[j][0]+1;
            b = array[j][1]+1;
            if (a < 1 || a > 100000 || b < 1 || b > 100000){
                return;
            }
            for (int t = 0 ; t < final+1 ; t++){
                if (array[t][0] == a && array[t][1] == b){
                    return;
                }
                else if (t == final){
                    array[t][0] = a;
                    array[t][1] = b;
                    final++;
                    i = 1;
                    for (int k = 0 ; k < 5 ; k++){
                        if (a == yorn[k][0] && b == yorn[k][1]){
                            yorn[k][2] == 1;
                        }
                    }
                    return;
                }
            }
        }
    }
    
}

void rule2 (void){
    int a, b;

    for (int j = 0 ; j < final ; j++){

        if (visit2[j] == false){
            visit2[j] = true;
            if (array[j][0]%2 == 1 || array[j][1]%2 == 1){
                continue;
            }
            a = array[j][0]/2;
            b = array[j][1]/2;
            for (int t = 0 ; t < final+1 ; t++){
                if (array[t][0] == a && array[t][1] == b){
                    return;
                }
                else if (t == final){
                    array[t][0] = a;
                    array[t][1] = b;
                    final++;
                    i = 1;
                    for (int k = 0 ; k < 5 ; k++){
                        if (a == yorn[k][0] && b == yorn[k][1]){
                            yorn[k][2] == 1;
                        }
                    }
                    return;
                }
            }
        }
    }
    
}

void rule3 (void) {
    int a, b;

    for (int j = 0 ; j < final-1 ; j++){
        for (int l = 0 ; l < final ; l++){
            if (array[j][1] == array[l][0]){

            }
        }

        if (visit2[j] == false){
            visit2[j] = true;
            if (array[j][0]%2 == 1 || array[j][1]%2 == 1){
                continue;
            }
            a = array[j][0]/2;
            b = array[j][1]/2;
            for (int t = 0 ; t < 100000 ; t++){
                if (array[t][0] == a && array[t][1] == b){
                    return;
                }
                else if (array[t][0] == 0){
                    array[t][0] = a;
                    array[t][1] = b;
                    i = 1;
                    for (int k = 0 ; k < 5 ; k++){
                        if (a == yorn[k][0] && b == yorn[k][1]){
                            yorn[k][2] == 1;
                        }
                    }
                    return;
                }
            }
        }
    }

}