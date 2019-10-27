//
//  main.c
//  지뢰찾기
//
//  Created by 이세현 on 2019/10/14.
//  Copyright © 2019 이세현. All rights reserved.
//

#include <stdio.h>

int* Up_XorY(int array[], int t){
    int array2[sizeof(array)+1];
    
    for(int i = 0 ; i < sizeof(array) ; i++){
        array2[i] = array[i];
    }
    
    array2[sizeof(array)+1] = t;
    
    return array2;
}

int main(void) {
    int array[1] = {0};
    int x = 10;
    
    int* array = Up_XorY(array, x);
    
    printf(array);
    
    return 0;
}
