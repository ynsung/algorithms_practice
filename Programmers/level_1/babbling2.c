#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int checkBabbling(char* str, int len){
    for(int i=0; i<len; i++){
        int j = i + 1;
        switch(str[i]){
            case 'a':
                if(str[j++]!='y' || str[j++]!='a' || (str[j]!='y' && str[j]!='w' && str[j]!='m' && str[j]!='\0')) return 0;
                else i += 2;
                break;
            case 'y':
                if(str[j++]!='e' || (str[j]!='a' && str[j]!='w' && str[j]!='m' && str[j]!='\0')) return 0;
                else i += 1;
                break;
            case 'w':
                if(str[j++]!='o' || str[j++]!='o' || (str[j]!='a' && str[j]!='y' && str[j]!='m' && str[j]!='\0')) return 0;
                else i += 2;
                break;
            case 'm':
                if(str[j++]!='a' || (str[j]!='a' && str[j]!='y' && str[j]!='w' && str[j]!='\0')) return 0;
                else i += 1;
                break;
            default :
                return 0;
        }
    }
    return 1;
}

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    
    for(int i=0; i<babbling_len; i++){
        answer += checkBabbling(babbling[i], strlen(babbling[i]));
    }
    
    return answer;
}