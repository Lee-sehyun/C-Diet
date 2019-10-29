#include <stdio.h>
#include <algorithm> 
#include <vector>

using namespace std;

bool visit[100]; // 초기화를 해줘야 할 것 같아....
int count;
vector<int> a[99]; // 큰 거
vector<int> b[99]; // 작은 거 

void dfs_a(int start){ 
    if(visit[start]){ 
        // 방문한경우 바로 빠져나옴 
        return; 
    } 
    
    visit[start] = true; // 방문 
    count++;
    
    for(int i=0; i< a[start].size(); i++){ 
        // 인접한 노드를 방문 
        int x = a[start][i]; 
        dfs_a(x); 
    } 
}

void dfs_b(int start){ 
    if(visit[start]){ 
        // 방문한경우 바로 빠져나옴 
        return; 
    } 
    
    visit[start] = true; // 방문 
    count++;
    
    for(int i=0; i< a[start].size(); i++){ 
        // 인접한 노드를 방문 
        int x = a[start][i]; 
        dfs_b(x); 
    } 
}

int main(void) {
    // 생각 코딩
    // N/2개가 넘어가면 중간값이 될수가 없다
    // 깊이 우선 탐색을 이용해야할 것 같네

    //입력
    int N, M;
    scanf("%d %d", &N, &M);
    int a, b;
    for (int i = 0 ; i < M ; i++){
        scanf("%d %d", &a, &b);
        a[a].push_back(b);
        b[b].push_back(a);
    }
    int N_count = 0;

    for (int i = 1 ; i <= N ; i++){
        count = 0;
        for (int j = 1 ; j <= N ; j++){
            visit[j] = false; // 초기화
        }
        dfs_a(i);
        if (count > N/2){
            N_count++;
            continue;
        }

        count = 0;
        for (int j = 1 ; j <= N ; j++){
            visit[j] = false; // 초기화
        }
        dfs_b(i);
        if (count > N/2){
            N_count++;
            continue;
        }
    }
    printf("%d", N_count);

    
    return 0;
}