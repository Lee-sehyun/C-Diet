#include <stdio.h>


int N; // 정점의 총 갯수

int map_big[100][100], map_small[100][100], visit[100]; // 인접 행렬과 방문 여부를 나타내는 배열
int count;

void dfs_big(int v)
{
    int i;
    visit[v] = 1; // 정점 v를 방문했다고 표시
    count++;
    for (i = 1; i <= N; i++)
    {
        // 정점 v와 정점 i가 연결되었고, 정점 i를 방문하지 않았다면
        if (map_big[v][i] == 1 && !visit[i])
        {
            // 정점 i에서 다시 DFS를 시작한다
            dfs_big(i); 
        }
    }
}

void dfs_small(int v)
{
    int i;
    visit[v] = 1; // 정점 v를 방문했다고 표시
    count++;
    for (i = 1; i <= N; i++)
    {
        // 정점 v와 정점 i가 연결되었고, 정점 i를 방문하지 않았다면
        if (map_small[v][i] == 1 && !visit[i])
        {
            // 정점 i에서 다시 DFS를 시작한다
            dfs_small(i); 
        }
    }
}

int main(void) {
    // 생각 코딩
    // N/2개가 넘어가면 중간값이 될수가 없다
    // 깊이 우선 탐색을 이용해야할 것 같네

    //입력
    int M;
    scanf("%d %d", &N, &M);
    int a, b;
    for (int i = 0 ; i < M ; i++){
        scanf("%d %d", &a, &b);
        map_big[a][b] = 1; 
        map_small[b][a] = 1; // 정점 v1과 정점 v2가 연결되었다고 표시
    }
    int N_count = 0;

    for (int i = 1 ; i <= N ; i++){
        count = 0;
        for (int j = 1 ; j <= N ; j++){
            visit[j] = 0; // 초기화
        }
        dfs_big(i);
        if (count > N/2+1){
            N_count++;
            continue;
        }

        count = 0;
        for (int j = 1 ; j <= N ; j++){
            visit[j] = 0; // 초기화
        }
        dfs_small(i);
        if (count > N/2+1){
            N_count++;
            continue;
        }
    }
    printf("%d", N_count);

    
    return 0;
}