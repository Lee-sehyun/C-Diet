#include <stdio.h>
#include <stdlib.h>

struct Change {
    char Up[3][3];
    char Down[3][3];
    char Front[3][3];
    char Back[3][3];
    char Left[3][3];
    char Right[3][3];
};

struct Ans {
    char a[2];
};

void Ch_Up(struct Change * ch, char c[]);
void Ch_Down(struct Change * ch, char c[]);
void Ch_Front(struct Change * ch, char c[]);
void Ch_Back(struct Change * ch, char c[]);
void Ch_Left(struct Change * ch, char c[]);
void Ch_Right(struct Change * ch, char c[]);

int main(void) {
    // 생각 코딩
    // 일단 색깔을 저장한다. 
    // 돌리는 함수로 만들까 main 반복문으로 만들까...

    struct Change *change[100];
    struct Ans *ans[1000];

    //입력
    int T;
    int n;
    int i, j, k;
    scanf("%d", &T);
    for (i = 0 ; i < T ; i++){
        change[i] = (struct Change *)malloc(sizeof(struct Change));
        for (j = 0 ; j < 3 ; j++){
            for (k = 0 ; k < 3 ; k++){
                change[i]->Up[j][k] = 'w';
                change[i]->Down[j][k] = 'y';
                change[i]->Front[j][k] = 'r';
                change[i]->Back[j][k] = 'o';
                change[i]->Left[j][k] = 'g';
                change[i]->Right[j][k] = 'b';
            }
        }
        scanf("%d", &n);
        for (j = 0 ; j < n ; j++){
            ans[j] = (struct Ans *)malloc(sizeof(struct Ans));
            scanf(" %s", ans[j]->a);
        }
        for (j = 0 ; j < n ; j++){
            if (ans[j]->a[0] == 'U'){
                Ch_Up(change[i], ans[j]->a);
            }
            else if (ans[j]->a[0] == 'D'){
                Ch_Down(change[i], ans[j]->a);
            }
            else if (ans[j]->a[0] == 'F'){
                Ch_Front(change[i], ans[j]->a);
            }
            else if (ans[j]->a[0] == 'B'){
                Ch_Back(change[i], ans[j]->a);
            }
            else if (ans[j]->a[0] == 'L'){
                Ch_Left(change[i], ans[j]->a);
            }
            else if (ans[j]->a[0] == 'R'){
                Ch_Right(change[i], ans[j]->a);
            }
            else ;
            free(ans[j]);
        }
    }
    //출력
    for (i = 0 ; i < T ; i++){
        for (j = 0 ; j < 3 ; j++){
            for (k = 0 ; k < 3 ; k++){
                printf("%c", change[i]->Up[j][k]);
            }
            printf("\n");
        }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%c ", change[i]->Down[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%c ", change[i]->Front[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%c ", change[i]->Back[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%c ", change[i]->Left[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%c ", change[i]->Right[j][k]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for (j = 0 ; j < 3 ; j++){
        //     for (k = 0 ; k < 3 ; k++){
        //         printf("%d ", change[i]->Left[j][k]);
        //     }
        //     printf("\n");
        // }
        free(change[i]);
    }



    
    return 0;
}

void Ch_Up(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Front[0][i];
            ch->Front[0][i] = ch->Right[0][i];
            ch->Right[0][i] = ch->Back[0][i];
            ch->Back[0][i] = ch->Left[0][i];
            ch->Left[0][i] = temp;
            if (i != 2){
                temp = ch->Up[0][i];
                ch->Up[0][i] = ch->Up[2-i][0];
                ch->Up[2-i][0] = ch->Up[2][2-i];
                ch->Up[2][2-i] = ch->Up[i][2];
                ch->Up[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Front[0][i];
            ch->Front[0][i] = ch->Left[0][i];
            ch->Left[0][i] = ch->Back[0][i];
            ch->Back[0][i] = ch->Right[0][i];
            ch->Right[0][i] = temp;
            if (i != 2){
                temp = ch->Up[0][i];
                ch->Up[0][i] = ch->Up[i][2];
                ch->Up[i][2] = ch->Up[2][2-i];
                ch->Up[2][2-i] = ch->Up[2-i][0];
                ch->Up[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
void Ch_Down(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Front[2][i];
            ch->Front[2][i] = ch->Left[2][i];
            ch->Left[2][i] = ch->Back[2][i];
            ch->Back[2][i] = ch->Right[2][i];
            ch->Right[2][i] = temp;
            if (i != 2){
                temp = ch->Down[0][i];
                ch->Down[0][i] = ch->Down[2-i][0];
                ch->Down[2-i][0] = ch->Down[2][2-i];
                ch->Down[2][2-i] = ch->Down[i][2];
                ch->Down[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Front[2][i];
            ch->Front[2][i] = ch->Right[2][i];
            ch->Right[2][i] = ch->Back[2][i];
            ch->Back[2][i] = ch->Left[2][i];
            ch->Left[2][i] = temp;
            if (i != 2){
                temp = ch->Down[0][i];
                ch->Down[0][i] = ch->Down[i][2];
                ch->Down[i][2] = ch->Down[2][2-i];
                ch->Down[2][2-i] = ch->Down[2-i][0];
                ch->Down[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
void Ch_Front(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[2][i];
            ch->Up[2][i] = ch->Left[2-i][2];
            ch->Left[2-i][2] = ch->Down[0][2-i];
            ch->Down[0][2-i] = ch->Right[i][0];
            ch->Right[i][0] = temp;
            if (i != 2){
                temp = ch->Front[0][i];
                ch->Front[0][i] = ch->Front[2-i][0];
                ch->Front[2-i][0] = ch->Front[2][2-i];
                ch->Front[2][2-i] = ch->Front[i][2];
                ch->Front[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[2][i];
            ch->Up[2][i] = ch->Right[i][0];
            ch->Right[i][0] = ch->Down[0][2-i];
            ch->Down[0][2-i] = ch->Left[2-i][2];
            ch->Left[2-i][2] = temp;
            if (i != 2){
                temp = ch->Front[0][i];
                ch->Front[0][i] = ch->Front[i][2];
                ch->Front[i][2] = ch->Front[2][2-i];
                ch->Front[2][2-i] = ch->Front[2-i][0];
                ch->Front[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
void Ch_Back(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[0][i];
            ch->Up[0][i] = ch->Right[i][2];
            ch->Right[i][2] = ch->Down[2][2-i];
            ch->Down[2][2-i] = ch->Left[2-i][0];
            ch->Left[2-i][0] = temp;
            if (i != 2){
                temp = ch->Back[0][i];
                ch->Back[0][i] = ch->Back[2-i][0];
                ch->Back[2-i][0] = ch->Back[2][2-i];
                ch->Back[2][2-i] = ch->Back[i][2];
                ch->Back[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[0][i];
            ch->Up[0][i] = ch->Left[2-i][0];
            ch->Left[2-i][0] = ch->Down[2][2-i];
            ch->Down[2][2-i] = ch->Right[i][2];
            ch->Right[i][2] = temp;
            if (i != 2){
                temp = ch->Back[0][i];
                ch->Back[0][i] = ch->Back[i][2];
                ch->Back[i][2] = ch->Back[2][2-i];
                ch->Back[2][2-i] = ch->Back[2-i][0];
                ch->Back[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
void Ch_Left(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[i][0];
            ch->Up[i][0] = ch->Back[2-i][2];
            ch->Back[2-i][2] = ch->Down[i][0];
            ch->Down[i][0] = ch->Front[i][0];
            ch->Front[i][0] = temp;
            if (i != 2){
                temp = ch->Left[0][i];
                ch->Left[0][i] = ch->Left[2-i][0];
                ch->Left[2-i][0] = ch->Left[2][2-i];
                ch->Left[2][2-i] = ch->Left[i][2];
                ch->Left[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[i][0];
            ch->Up[i][0] = ch->Front[i][0];
            ch->Front[i][0] = ch->Down[i][0];
            ch->Down[i][0] = ch->Back[2-i][2];
            ch->Back[2-i][2] = temp;
            if (i != 2){
                temp = ch->Left[0][i];
                ch->Left[0][i] = ch->Left[i][2];
                ch->Left[i][2] = ch->Left[2][2-i];
                ch->Left[2][2-i] = ch->Left[2-i][0];
                ch->Left[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}
void Ch_Right(struct Change * ch, char c[]){
    int i;
    char temp;
    if(c[1] == '+'){
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[i][2];
            ch->Up[i][2] = ch->Front[i][2];
            ch->Front[i][2] = ch->Down[i][2];
            ch->Down[i][2] = ch->Back[2-i][0];
            ch->Back[2-i][0] = temp;
            if (i != 2){
                temp = ch->Right[0][i];
                ch->Right[0][i] = ch->Right[2-i][0];
                ch->Right[2-i][0] = ch->Right[2][2-i];
                ch->Right[2][2-i] = ch->Right[i][2];
                ch->Right[i][2] = temp;
            }
        }
    }
    else if (c[1] == '-') {
        for(i = 0 ; i < 3 ; i++){
            temp = ch->Up[i][2];
            ch->Up[i][2] = ch->Back[2-i][0];
            ch->Back[2-i][0] = ch->Down[i][2];
            ch->Down[i][2] = ch->Front[i][2];
            ch->Front[i][2] = temp;
            if (i != 2){
                temp = ch->Right[0][i];
                ch->Right[0][i] = ch->Right[i][2];
                ch->Right[i][2] = ch->Right[2][2-i];
                ch->Right[2][2-i] = ch->Right[2-i][0];
                ch->Right[2-i][0] = temp;
            }
        }
    }
    // for (int j = 0 ; j < 3 ; j++){
    //     for (int k = 0 ; k < 3 ; k++){
    //         printf("%c ", ch->Up[j][k]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}