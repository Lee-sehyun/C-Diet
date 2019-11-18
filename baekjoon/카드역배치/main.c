#include <stdio.h>

void Change_arr (int* arr, int a, int b);

int main(void) {
    // 생각 코딩
    // 배열이 하나 필요하다.
    // 이거 배열,포안터,함수로 함 만들어볼까?

    int array[20];
    int i;
    int x, y;

    for (i = 0 ; i < 20 ; i++){
        array[i] = i+1;
    }

    //입력
    for (i = 0 ; i < 10 ; i++){
        scanf("%d %d", &x, &y);
        Change_arr(array, x, y);
    }




    for (i = 0 ; i < 20 ; i++){
        printf("%d ", array[i]);
    }


    
    return 0;
}

void Change_arr (int arr[], int a, int b){
    int i;
    int temp;

    for (i = 0 ; i < (b-a)/2+1 ; i++){
        temp = arr[a+i-1];
        arr[a+i-1] = arr[b-i-1];
        arr[b-i-1] = temp;
    }

}