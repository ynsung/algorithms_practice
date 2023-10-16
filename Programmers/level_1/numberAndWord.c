#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int i = -1;
    
    while(s[++i] != '\0'){
        answer *= 10;
        if(s[i] >= '0' && s[i] <='9'){
            answer += s[i]-'0';
        }
        else if(s[i] == 'o'){  // one
            answer++;
            i += 2;
        }
        else if(s[i] == 't'){
            if(s[i+1] == 'w'){
                answer += 2;   // two
                i += 2;
            }
            else {
                answer += 3;   // three
                i += 4;
            }
        }
        else if(s[i] == 'f'){
            if(s[i+1] == 'o'){
                answer += 4;   // four
                i += 3;
            }
            else {
                answer += 5;   // five
                i += 3;
            }
        }
        else if(s[i] == 's'){
            if(s[i+1] == 'i'){
                answer += 6;   // six
                i += 2;
            }
            else {
                answer += 7;   // seven
                i += 4;
            }
        }
        else if(s[i] == 'e'){
            answer += 8;       // eight
            i += 4;
        }
        else if(s[i] == 'n'){
            answer += 9;       // nine
            i += 3;
        }
        else if(s[i] == 'z'){
            i += 3;
        }
    }
    return answer;
}