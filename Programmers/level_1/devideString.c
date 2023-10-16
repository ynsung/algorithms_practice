#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    int len = strlen(s);
    char x = s[0];
    int sepNum = 1;
    int otherNum = 0;

    for (int i = 1; i < len - 1; i++) {
        if (s[i] == x) sepNum++;
        else otherNum++;

        if (sepNum == otherNum) {
            answer++;
            sepNum = 1;
            otherNum = 0;
            i++;
            x = s[i];
        }
    }
    return answer;
}