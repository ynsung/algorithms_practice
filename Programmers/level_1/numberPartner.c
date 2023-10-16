#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* X, const char* Y) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int x_len = strlen(X), y_len = strlen(Y);
    int short_len;
    
    if(x_len > y_len) short_len = y_len;
    else short_len = x_len;
    if(short_len <= 2) short_len = 3;
    char* answer = (char*)malloc(short_len*sizeof(int));
    
    int xm[10] = {0, };
    int ym[10] = {0, };
    
    while(*X){
        int i = *X++ - '0';
        xm[i]++;
    }
    while(*Y){
        int i = *Y++ - '0';
        ym[i]++;
    }
    int j = 0;
    for(int i=9; i>=0; i--){
        while(xm[i] != 0 && ym[i] != 0){
            xm[i]--; ym[i]--;
            answer[j++] = i + '0';
        }
    }
    if(j == 0){
        answer[0] = '-';
        answer[1] = '1';
        answer[2] = '\0';
    }
    else if(answer[0] == '0' && answer[1] == '0'){
        answer[0] = '0';
        answer[1] = '\0';
    }
    else answer[j] = '\0';
    return answer;
}