#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s, const char* skip, int index) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*(strlen(s)+1));
    char alpha[26] = {0, };
    
    while(*skip){
        alpha[*skip++ - 'a'] = 1;  // 1이면 skip
    }
    
    int k = 0;
    while(*s){
        int idx = *s++ - 'a';
        for(int i=1; i<=index; i++){
            idx++;
            if(idx >= 26){
                if(alpha[idx%26] == 1) i--;
            }
            else{
                if(alpha[idx] == 1) i--;
            }
        }
        if(idx >= 26) answer[k++] = (idx%26) + 'a';
        else answer[k++] = idx + 'a';
    }
    answer[k] = '\0';
    
    return answer;
}