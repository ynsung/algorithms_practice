#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0, widthMax = 0, heightMax = 0;
    
    for(int i=0; i<sizes_rows; i++){
        if(sizes[i][0] < sizes[i][1])
            swap(&sizes[i][0], &sizes[i][1]);
        if(sizes[i][0] > widthMax)
            widthMax = sizes[i][0];
        if(sizes[i][1] > heightMax)
            heightMax = sizes[i][1];
    }
    answer = widthMax*heightMax;
    return answer;
}