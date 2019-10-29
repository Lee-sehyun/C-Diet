#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;
 
typedef struct Queue //Queue 구조체 정의
{
    Node *front; //맨 앞(꺼낼 위치)
    Node *rear; //맨 뒤(보관할 위치)
    int count;//보관 개수
}Queue;
 
void InitQueue(Queue *queue);//큐 초기화
int IsEmpty(Queue *queue); //큐가 비었는지 확인
void Enqueue(Queue *queue, int data); //큐에 보관
int Dequeue(Queue *queue); //큐에서 꺼냄

int main(void) {
    // 생각 코딩
    // N/2개가 넘어가면 중간값이 될수가 없다
    // 넓이 우선 탐색을 이용해야할 것 같네

    //입력
    int N, M;
    scanf("%d %d", &N, &M);
    int a[M], b[M];
    for (int i = 0 ; i < M ; i++){
        scanf("%d %d", &a[i], &b[i]);
    }
    int N_count = 0;
    int k;
    int i;
    int count;
    Queue queue;

    InitQueue(&queue);//큐 초기화

    for (i = 0 ; i < N ; i++){
        Enqueue(&queue, i+1);
        count = 0;
        while(!IsEmpty(&queue)){
            k = Dequeue(&queue);
            for (int i = 0 ; i < M ; i++){
                if (k == b[i]){
                    Enqueue(&queue, a[i]);
                    count++;
                }
            }
        }
        if (count > N/2){
            N_count++;
            continue;
        }

        Enqueue(&queue, i+1);
        count = 0;
        while(!IsEmpty(&queue)){
            k = Dequeue(&queue);
            for (int i = 0 ; i < M ; i++){
                if (k == a[i]){
                    Enqueue(&queue, b[i]);
                    count++;
                }
            }
        }
        if (count > N/2){
            N_count++;
            continue;
        }
    }
    printf("%d", N_count);
    return 0;
}

void InitQueue(Queue *queue)
{
    queue->front = queue->rear = NULL; //front와 rear를 NULL로 설정
    queue->count = 0;//보관 개수를 0으로 설정
}
 
int IsEmpty(Queue *queue)
{
    return queue->count == 0;    //보관 개수가 0이면 빈 상태
}
 
void Enqueue(Queue *queue, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = NULL;
 
    if (IsEmpty(queue))//큐가 비어있을 때
    {
        queue->front = now;//맨 앞을 now로 설정       
    }
    else//비어있지 않을 때
    {
        queue->rear->next = now;//맨 뒤의 다음을 now로 설정
    }
    queue->rear = now;//맨 뒤를 now로 설정   
    queue->count++;//보관 개수를 1 증가
}
 
int Dequeue(Queue *queue)
{
    int re = 0;
    Node *now;
    if (IsEmpty(queue))//큐가 비었을 때
    {
        return re;
    }
    now = queue->front;//맨 앞의 노드를 now에 기억
    re = now->data;//반환할 값은 now의 data로 설정
    queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
    free(now);//now 소멸
    queue->count--;//보관 개수를 1 감소
    return re;
}