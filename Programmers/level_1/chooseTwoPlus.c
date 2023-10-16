#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int num = numbers_len*(numbers_len-1)/2;
    int* answer = (int*)malloc(num*sizeof(int));
    
    int matrix[201] = {0, };
    
    for(int i=0; i<numbers_len-1; i++){
        for(int j=i+1; j<numbers_len; j++){
            matrix[numbers[i]+numbers[j]] = 1;
        }
    }
    int s = 0, i = 0;
    while(s < 201){
        if(matrix[s] == 1) answer[i++] = s;
        s++;
    }
    return answer;
}