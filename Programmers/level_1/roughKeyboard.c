#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void countKeymap(int matrix[], char* str){
    int cnt = 1;
    while(*str){
        int i = *str++ - 'A';
        if(matrix[i]!=0 && matrix[i]<=cnt) cnt++;
        else matrix[i] = cnt++;
    }
}

int findTarget(int matrix[], char* str){
    int sum = 0;
    while(*str){
        int i = *str++ - 'A';
        if(matrix[i] == 0) return -1;
        else sum += matrix[i];
    }
    return sum;
}

// keymap_len은 배열 keymap의 길이입니다.
// targets_len은 배열 targets의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(targets_len*sizeof(int));
    int matrix[26] = {0, };
    
    for(int i=0; i<keymap_len; i++)
        countKeymap(matrix, keymap[i]);
    
    for(int i=0; i<targets_len; i++)
        answer[i] = findTarget(matrix, targets[i]);
    
    return answer;
}