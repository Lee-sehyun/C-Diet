#include <stdio.h>
#include <stdlib.h>

void Swap(long arr[], long a, long b); // a,b 스왑 함수 
int Partition(long arr[], long left, long right);
void QuickSort(long arr[], long left, long right);

int main(void){
    // 생각 코딩
    // 배열을 만들어보자!


    // 입력
    long N, M;
    long *T;
    long *T_sum;
    long i, j;
    scanf("%ld %ld", &N, &M);

    // T = (long*)malloc(sizeof(long)*N);
    // T_sum = (long*)malloc(sizeof(long)*N);
    for (i = 0 ; i < N ; i++){
        scanf("%ld", &T[i]);
        T_sum[i] = 0;
    }
    QuickSort(T, 0, N-1);

    for (i = 0 ; i < N ; i++){
        printf("%ld", T[i]);
    }
    
    // 실행
    // M번 실행을 한다!
    // sum에 T_sum+T 값을 넣어준 뒤 가장 작은 값을 찾아준다.(함수에서 index값을 찾아주자)
    long sum;
    long index;
    long max;
    max = T_sum[0];
    for (i = 0 ; i < M ; i++){
        sum = T_sum[0] + T[0];
        index = 0;
        for (j = 1 ; j < N ; j++){
            if (sum > T_sum[j] + T[j]){
                sum = T_sum[j] + T[j];
                index = j;
            }
        }
        T_sum[index] += T[index];
        if (max < T_sum[index]){
            max = T_sum[index];
        }
    }
    printf("\n");
    for (i = 0 ; i < N ; i++){
        printf("%ld\n", T_sum[i]);
    }
    printf("\n");
    printf("\n");
    printf("%ld", max);





    return 0;
}

void Swap(long arr[], long a, long b) // a,b 스왑 함수 
{
    long temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(long arr[], long left, long right)
{
    long pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    long low = left + 1;
    long high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
        {
            low++; // low를 오른쪽으로 이동 
        }
        while (pivot <= arr[high] && high >= (left+1) ) // 피벗보다 작은 값을 찾는 과정 
        {
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
        {
            Swap(arr, low, high); //low와 high를 스왑 
        }
    }
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
 
}
 
 
void QuickSort(long arr[], long left, long right)
{
    if (left <= right)
    {
        long pivot = Partition(arr, left, right); // 둘로 나누어서
        QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}