#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char str[150001];

int countZero(char* str){
    int cnt = 0;
    while(*str)
        if(*str++ == '0') cnt++;
    return cnt;
}

void ConvStr(int num){
    int i = 0;
    while(num >= 1){
        if(num%2 == 0) str[i++] = '0';
        else str[i++] = '1';
        num /= 2;
    }
    str[i] = '\0';
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0;
    answer[1] = 0;
    if(strlen(s) == 1) return answer;
    
    strcpy(str, s);
    int len = strlen(str);
    while(len > 1){
        int cntZero = countZero(str);
        int cntOne = len - cntZero;
        answer[1] += cntZero;
        ConvStr(cntOne);
        answer[0]++;
        len = strlen(str);
    }
    
    return answer;
}