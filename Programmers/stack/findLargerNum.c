#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 1000001
int s[MAX_SIZE];
int top = -1;


// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*numbers_len);
    
    int i = 1;
    s[++top] = 0;
    
    while(i != numbers_len){
        if(top > -1){
            if(numbers[s[top]] < numbers[i]){
                answer[s[top--]] = numbers[i];
                continue;
            }
        }
        s[++top] = i;
        i++;
    }
    
    while(top != -1)
        answer[s[top--]] = -1;
    
    return answer;
}